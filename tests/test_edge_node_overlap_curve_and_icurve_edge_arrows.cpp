#include <string>

#include <catch2/catch.hpp>

#include "test_edge_node_overlap_utilities.h"
#include "test_utilities.h"

TEST_CASE("Edge node overlap for curve and icurve arrow",
          "[!shouldfail] An edge connected to a node shall touch that node and "
          "not overlap it too much") {

  std::string filename_base = AUTO_NAME();

  const std::string_view primitive_arrow_shape = GENERATE("curve", "icurve");
  INFO("Edge arrowhead: " << primitive_arrow_shape);
  filename_base += fmt::format("_arrow_shape_{}", primitive_arrow_shape);

  const auto rankdir = GENERATE(from_range(all_rank_directions));
  INFO("Rank direction: " << rankdir);
  filename_base += fmt::format("_rankdir_{}", rankdir);

  const graph_options graph_options = {
      .rankdir = rankdir,
      .node_shape = "polygon",
      .node_penwidth = 2,
      .dir = "both",
      .edge_penwidth = 2,
      .primitive_arrowhead_shape = primitive_arrow_shape,
      .primitive_arrowtail_shape = primitive_arrow_shape,
  };

  test_edge_node_overlap(graph_options, {}, {.filename_base = filename_base});
}
