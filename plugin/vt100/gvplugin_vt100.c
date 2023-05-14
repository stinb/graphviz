/// \file
/// \brief Device that renders using ANSI terminal colors

#include <gvc/gvplugin.h>
#include <gvc/gvplugin_device.h>

#include <gvc/gvio.h>

static void process(GVJ_t *job) {

  unsigned char *data = (unsigned char *)job->imagedata;

  for (unsigned y = 0; y < job->height; y += 2) {
    for (unsigned x = 0; x < job->width; ++x) {

      // number of bytes per pixel
      const unsigned BPP = 4;

      {
        // extract the upper pixel
        unsigned offset = y * job->width * BPP + x * BPP;
        unsigned red = data[offset + 2];
        unsigned green = data[offset + 1];
        unsigned blue = data[offset];

        // use this to select a foreground color
        if (red == 0 && green == 0 && blue == 0) {
          gvprintf(job, "\033[30m"); // black
        } else if (red == 0xff && green == 0 && blue == 0) {
          gvprintf(job, "\033[31m"); // red
        } else if (red == 0 && green == 0xff && blue == 0) {
          gvprintf(job, "\033[32m"); // green
        } else if (red == 0xff && green == 0xff && blue == 0) {
          gvprintf(job, "\033[33m"); // yellow
        } else if (red == 0 && green == 0 && blue == 0xff) {
          gvprintf(job, "\033[34m"); // blue
        } else if (red == 0xff && green == 0 && blue == 0xff) {
          gvprintf(job, "\033[35m"); // magenta
        } else if (red == 0 && green == 0xff && blue == 0xff) {
          gvprintf(job, "\033[36m"); // cyan
        } else if (red == 0xff && green == 0xff && blue == 0xff) {
          gvprintf(job, "\033[37m"); // white
        }
      }

      {
        // extract the lower pixel
        unsigned red = 0;
        unsigned green = 0;
        unsigned blue = 0;
        if (y + 1 < job->height) {
          unsigned offset = (y + 1) * job->width * BPP + x * BPP;
          red = data[offset + 2];
          green = data[offset + 1];
          blue = data[offset];
        }

        // use this to select a background color
        if (red == 0 && green == 0 && blue == 0) {
          gvprintf(job, "\033[40m"); // black
        } else if (red == 0xff && green == 0 && blue == 0) {
          gvprintf(job, "\033[41m"); // red
        } else if (red == 0 && green == 0xff && blue == 0) {
          gvprintf(job, "\033[42m"); // green
        } else if (red == 0xff && green == 0xff && blue == 0) {
          gvprintf(job, "\033[43m"); // yellow
        } else if (red == 0 && green == 0 && blue == 0xff) {
          gvprintf(job, "\033[44m"); // blue
        } else if (red == 0xff && green == 0 && blue == 0xff) {
          gvprintf(job, "\033[45m"); // magenta
        } else if (red == 0 && green == 0xff && blue == 0xff) {
          gvprintf(job, "\033[46m"); // cyan
        } else if (red == 0xff && green == 0xff && blue == 0xff) {
          gvprintf(job, "\033[47m"); // white
        }
      }

      // print unicode “upper half block” to effectively do two rows of
      // pixels per one terminal row
      gvprintf(job, "▀\033[0m");
    }
    gvprintf(job, "\n");
  }
}

static gvdevice_engine_t engine = {
    .format = process,
};

static gvdevice_features_t device_features = {
    .default_dpi = {96, 96},
};

static gvplugin_installed_t device_types[] = {
    {0, "vt100:cairo", 0, &engine, &device_features},
    {0},
};

static gvplugin_api_t apis[] = {
    {API_device, device_types},
    {(api_t)0, 0},
};

gvplugin_library_t gvplugin_vt100_LTX_library = {"vt100", apis};
