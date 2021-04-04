#include <memory>

#include <catch2/catch.hpp>

#include <cgraph++/AGraph.h>
#include <gvc++/GVContext.h>
#include <gvc++/GVLayout.h>

TEST_CASE("Layout of a graph can use on-demand loaded plugins") {
  auto gvc = std::make_shared<GVC::GVContext>();

  auto dot = "graph {a}";
  auto g = std::make_shared<CGraph::AGraph>(dot);

  const auto layout = GVC::GVLayout(gvc, g, "dot");
}
