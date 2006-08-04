/* $Id$ $Revision$ */
/* vim:set shiftwidth=4 ts=8: */

/**********************************************************
*      This software is part of the graphviz package      *
*                http://www.graphviz.org/                 *
*                                                         *
*            Copyright (c) 1994-2004 AT&T Corp.           *
*                and is licensed under the                *
*            Common Public License, Version 1.0           *
*                      by AT&T Corp.                      *
*                                                         *
*        Information and Software Systems Research        *
*              AT&T Research, Florham Park NJ             *
**********************************************************/


#include "render.h"
#include "htmltable.h"
#include <limits.h>

static void storeline(graph_t *g, textlabel_t *lp, char *line, char terminator)
{
    pointf size;
    textpara_t *para;

    lp->u.txt.para =
	ALLOC(lp->u.txt.nparas + 2, lp->u.txt.para, textpara_t);
    para = &(lp->u.txt.para[lp->u.txt.nparas]);
    para->str = line;
    para->just = terminator;
    size = textsize(g, para, lp->fontname, lp->fontsize);
    lp->u.txt.nparas++;
    /* total width = max line width */
    if (lp->dimen.x < size.x)
	lp->dimen.x = size.x;
    /* recalculate total height */
    lp->dimen.y = lp->u.txt.nparas * (int) (size.y * LINESPACING);
}

/* compiles <str> into a label <lp> and returns its bounding box size.  */
static pointf label_size(graph_t * g, textlabel_t * lp)
{
    char c, *p, *line, *lineptr, *str = lp->text;
    unsigned char byte = 0x00;
    int charset = GD_charset(g);

    if (*str == '\0')
	return lp->dimen;

    line = lineptr = NULL;
    p = str;
    line = lineptr = N_GNEW(strlen(p) + 1, char);
    *line = 0;
    while ((c = *p++)) {
	byte = (unsigned int) c;
	/* wingraphviz allows a combination of ascii and big-5. The latter
         * is a two-byte encoding, with the first byte in 0xA1-0xFE, and
         * the second in 0x40-0x7e or 0xa1-0xfe. We assume that the input
         * is well-formed, but check that we don't go past the ending '\0'.
         */
	if ((charset == CHAR_BIG5) && 0xA1 <= byte && byte <= 0xFE) {
	    *lineptr++ = c;
	    c = *p++;
	    *lineptr++ = c;
	    if (!c) /* NB. Protect against unexpected string end here */
		break;
	} else {
	    if (c == '\\') {
		switch (*p) {
		case 'n':
		case 'l':
		case 'r':
		    *lineptr++ = '\0';
		    storeline(g, lp, line, *p);
		    line = lineptr;
		    break;
		default:
		    *lineptr++ = *p;
		}
		if (*p)
		    p++;
		/* tcldot can enter real linend characters */
	    } else if (c == '\n') {
		*lineptr++ = '\0';
		storeline(g, lp, line, 'n');
		line = lineptr;
	    } else {
		*lineptr++ = c;
	    }
	}
    }

    if (line != lineptr) {
	*lineptr++ = '\0';
	storeline(g, lp, line, 'n');
    }

    return lp->dimen;
}

/* size_label:
 * Process label text for size and line breaks.
 */ 
void
size_label (graph_t* g, textlabel_t* rv)
{
    char *s;

    switch (GD_charset(g->root)) {
    case CHAR_LATIN1:
	s = latin1ToUTF8(rv->text);
	break;
    default: /* UTF8 */
	s = htmlEntityUTF8(rv->text);
	break;
    }
    free(rv->text);
    rv->text = s;
    label_size(g, rv);
}

/* make_label:
 * Assume str is freshly allocated for this instance, so it
 * can be freed in free_label.
 */
textlabel_t *make_label(graph_t *g, int html, char *str, double fontsize,
			char *fontname, char *fontcolor)
{
    textlabel_t *rv = NEW(textlabel_t);

    rv->text = str;
    rv->fontname = fontname;
    rv->fontcolor = fontcolor;
    rv->fontsize = fontsize;
    if (html)
	rv->html = TRUE;
    else
	size_label(g, rv);
    return rv;
}

static void free_textpara(textpara_t * tl)
{
    if (tl) {
	if (tl->str)
	    free(tl->str);
	if (tl->xshow)
	    free(tl->xshow);
	if (tl->layout && tl->free_layout)
	    tl->free_layout (tl->layout);
	free(tl);
    }
}

void free_label(textlabel_t * p)
{
    if (p) {
	free(p->text);
	if (p->html) {
	    free_html_label(p->u.html, 1);
	} else {
	    free_textpara(p->u.txt.para);
	}
	free(p);
    }
}

void 
emit_textparas(GVJ_t* job, int nparas, textpara_t paras[], pointf p,
              double halfwidth_x, char* fname, double fsize, char* fcolor)
{
    int i, paraspacing, tmp;
    double center_x, left_x, right_x;

    center_x = p.x;
    left_x = center_x - halfwidth_x;
    right_x = center_x + halfwidth_x;

    /* set paraspacing to an exact no. of pixelrows */
    paraspacing = (int) (fsize * LINESPACING);

    /* position for first para */
    p.y += paraspacing * (nparas - 1) / 2	/* cl of top para */
			- fsize * 0.30; /* Empirically determined fudge factor */

    gvrender_begin_context(job);
    gvrender_set_pencolor(job, fcolor);
    gvrender_set_font(job, fname, fsize);

    for (i = 0; i < nparas; i++) {
	switch (paras[i].just) {
	case 'l':
	    p.x = left_x;
	    break;
	case 'r':
	    p.x = right_x;
	    break;
	default:
	case 'n':
	    p.x = center_x;
	    break;
	}

        tmp = ROUND(p.x);  /* align with integer points */
        p.x = (double)tmp;
        tmp = ROUND(p.y);  /* align with integer points */
        p.y = (double)tmp;

	gvrender_textpara(job, p, &(paras[i]));

	/* position for next para */
	p.y -= paraspacing;
    }

    gvrender_end_context(job);
}

void emit_label(GVJ_t * job, emit_state_t emit_state, textlabel_t * lp)
{
    obj_state_t *obj = job->obj;
    double halfwidth_x;
    pointf p;
    emit_state_t old_emit_state;

    old_emit_state = obj->emit_state;
    obj->emit_state = emit_state;

    if (lp->html) {
	emit_html_label(job, lp->u.html, lp);
	return;
    }

    /* make sure that there is something to do */
    if (lp->u.txt.nparas < 1)
	return;

    p.x = lp->p.x;
    p.y = lp->p.y;

    /* dimensions of box for label, no padding, adjusted for resizing */
    halfwidth_x = (lp->dimen.x + lp->d.x) / 2.0;

    emit_textparas(job, lp->u.txt.nparas, lp->u.txt.para, p,
              halfwidth_x, lp->fontname, lp->fontsize, lp->fontcolor);

    obj->emit_state = old_emit_state;
}


char *strdup_and_subst_graph(char *str, Agraph_t * g)
{
    char c, *s, *p, *t, *newstr;
    char *g_str = NULL;
    int g_len = 0, newlen = 0;

    /* two passes over str.
     *
     * first pass prepares substitution strings and computes 
     * total length for newstring required from malloc.
     */
    for (s = str; (c = *s++);) {
	if (c == '\\') {
	    switch (c = *s++) {
	    case 'G':
		if (!g_str) {
		    g_str = g->name;
		    g_len = strlen(g_str);
		}
		newlen += g_len;
		break;
	    default:
		newlen += 2;
	    }
	} else {
	    newlen++;
	}
    }
    /* allocate new string */
    newstr = gmalloc(newlen + 1);

    /* second pass over str assembles new string */
    for (s = str, p = newstr; (c = *s++);) {
	if (c == '\\') {
	    switch (c = *s++) {
	    case 'G':
		for (t = g_str; (*p = *t++); p++);
		break;

	    default:
		*p++ = '\\';
		*p++ = c;
	    }
	} else {
	    *p++ = c;
	}
    }
    *p++ = '\0';
    return newstr;
}

char *strdup_and_subst_node(char *str, Agnode_t * n)
{
    char c, *s, *p, *t, *newstr;
    char *g_str = NULL, *n_str = NULL;
    int g_len = 0, n_len = 0, newlen = 0;

    /* two passes over str.
     *
     * first pass prepares substitution strings and computes 
     * total length for newstring required from malloc.
     */
    for (s = str; (c = *s++);) {
	if (c == '\\') {
	    switch (c = *s++) {
	    case 'G':
		if (!g_str) {
		    g_str = n->graph->name;
		    g_len = strlen(g_str);
		}
		newlen += g_len;
		break;
	    case 'N':
		if (!n_str) {
		    n_str = n->name;
		    n_len = strlen(n_str);
		}
		newlen += n_len;
		break;
	    default:
		newlen += 2;
	    }
	} else {
	    newlen++;
	}
    }
    /* allocate new string */
    newstr = gmalloc(newlen + 1);

    /* second pass over str assembles new string */
    for (s = str, p = newstr; (c = *s++);) {
	if (c == '\\') {
	    switch (c = *s++) {
	    case 'G':
		for (t = g_str; (*p = *t++); p++);
		break;

	    case 'N':
		for (t = n_str; (*p = *t++); p++);
		break;
	    default:
		*p++ = '\\';
		*p++ = c;
	    }
	} else {
	    *p++ = c;
	}
    }
    *p++ = '\0';
    return newstr;
}

char *strdup_and_subst_edge(char *str, Agedge_t * e)
{
    char c, *s, *p, *t, *newstr;
    char *g_str = NULL, *e_str = NULL, *h_str = NULL, *t_str = NULL;
    int g_len = 0, e_len = 0, h_len = 0, t_len = 0, newlen = 0;

    /* two passes over str.
     *
     * first pass prepares substitution strings and computes 
     * total length for newstring required from malloc.
     */
    for (s = str; (c = *s++);) {
	if (c == '\\') {
	    switch (c = *s++) {
	    case 'G':
		if (!g_str) {
		    g_str = e->tail->graph->root->name;
		    g_len = strlen(g_str);
		}
		newlen += g_len;
		break;
	    case 'E':
		if (!e_str) {
		    t_str = e->tail->name;
		    t_len = strlen(t_str);
		    h_str = e->head->name;
		    h_len = strlen(h_str);
		    if (e->tail->graph->root->kind & AGFLAG_DIRECTED)
			e_str = "->";
		    else
			e_str = "--";
		    e_len = t_len + 2 + h_len;
		}
		newlen += e_len;
		break;
	    case 'H':
		if (!h_str) {
		    h_str = e->head->name;
		    h_len = strlen(h_str);
		}
		newlen += h_len;
		break;
	    case 'T':
		if (!t_str) {
		    t_str = e->tail->name;
		    t_len = strlen(t_str);
		}
		newlen += t_len;
		break;
	    default:
		newlen += 2;
	    }
	} else {
	    newlen++;
	}
    }
    /* allocate new string */
    newstr = gmalloc(newlen + 1);

    /* second pass over str assembles new string */
    for (s = str, p = newstr; (c = *s++);) {
	if (c == '\\') {
	    switch (c = *s++) {
	    case 'G':
		for (t = g_str; (*p = *t++); p++);
		break;
	    case 'E':
		for (t = t_str; (*p = *t++); p++);
		for (t = e_str; (*p = *t++); p++);
		for (t = h_str; (*p = *t++); p++);
		break;
	    case 'H':
		for (t = h_str; (*p = *t++); p++);
		break;
	    case 'T':
		for (t = t_str; (*p = *t++); p++);
		break;
	    default:
		*p++ = '\\';
		*p++ = c;
	    }
	} else {
	    *p++ = c;
	}
    }
    *p++ = '\0';
    return newstr;
}

/* return true if *s points to &[A-Za-z]*;      (e.g. &Ccedil; )
 *                          or &#[0-9]*;        (e.g. &#38; )
 *                          or &#x[0-9a-fA-F]*; (e.g. &#x6C34; )
 */
static int xml_isentity(char *s)
{
    s++;			/* already known to be '&' */
    if (*s == '#') {
	s++;
	if (*s == 'x' || *s == 'X') {
	    s++;
	    while ((*s >= '0' && *s <= '9')
		   || (*s >= 'a' && *s <= 'f')
		   || (*s >= 'A' && *s <= 'F'))
		s++;
	} else {
	    while (*s >= '0' && *s <= '9')
		s++;
	}
    } else {
	while ((*s >= 'a' && *s <= 'z')
	       || (*s >= 'A' && *s <= 'Z'))
	    s++;
    }
    if (*s == ';')
	return 1;
    return 0;
}


char *xml_string(char *s)
{
    static char *buf = NULL;
    static int bufsize = 0;
    char *p, *sub;
    int len, pos = 0;

    if (!buf) {
	bufsize = 64;
	buf = gmalloc(bufsize);
    }

    p = buf;
    while (*s) {
	if (pos > (bufsize - 8)) {
	    bufsize *= 2;
	    buf = grealloc(buf, bufsize);
	    p = buf + pos;
	}
	/* these are safe even if string is already UTF-8 coded
	 * since UTF-8 strings won't contain '<' or '>' */
	if (*s == '<') {
	    sub = "&lt;";
	    len = 4;
	} else if (*s == '>') {
	    sub = "&gt;";
	    len = 4;
	} else if (*s == '"') {
	    sub = "&quot;";
	    len = 6;
	} else if (*s == '-') {	/* can't be used in xml comment strings */
	    sub = "&#45;";
	    len = 5;
	} else if (*s == '\'') {
	    sub = "&#39;";
	    len = 5;
	}
	/* escape '&' only if not part of a legal entity sequence */
	else if (*s == '&' && !(xml_isentity(s))) {
	    sub = "&amp;";
	    len = 5;
	} else {
	    sub = s;
	    len = 1;
	}
	while (len--) {
	    *p++ = *sub++;
	    pos++;
	}
	s++;
    }
    *p = '\0';
    return buf;
}
