#include <catch2/catch_test_macros.hpp>

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "../lib/cs225/PNG.h"
#include "../lib/cs225/HSLAPixel.h"
#include "../src/final_project.h"
#include "../src/utils.h"
using namespace cs225;


//
// Non-iterator Tests:
//

TEST_CASE("requiretrue", "[weight=5]") {
    REQUIRE(true);
}

TEST_CASE("Test file_to_V2D_Smallcase", "[weight=5]") {
    V2D file = file_to_V2D("../tests/smallcase.txt");

    // std::cout << file.size() <<std::endl;
    // std::cout << file[0].size()<<std::endl;

    // for (size_t i = 0; i < file.size(); i++) {
    //     for (size_t j = 0; j < file[i].size(); j++) {
    //         std::cout << file[i][j]<< " ";
    //     }
    //     std::cout << " " << std::endl;
    // }
    REQUIRE(file[0][0] == "0");
    REQUIRE(file[0][1] == "1");
}

TEST_CASE("Test file_to_V2D_Largecase", "[weight=5]") {
    V2D file = file_to_V2D("../tests/p2p-Gnutella08.txt");
    //std::cout << file.size() <<std::endl;
    for (size_t i = 0; i < file.size(); i++) {
        // if (file[i].size() != 2) {
        //     std::cout << i << std::endl;
        // }
        REQUIRE(file[i].size() == 2);
        // for (size_t j = 0; j < file[i].size(); j++) {
        //     std::cout << file[i][j]<< " ";
        // }
        // std::cout << " " << std::endl;
    }
}

TEST_CASE("Test V2D_to_Graph_Smallcase", "[weight=5]") {
    V2D file = file_to_V2D("../tests/smallcase.txt");
    Graph graph = V2D_to_Graph(file);
    REQUIRE(graph.size() == 6);
    REQUIRE(graph.Isconnected("1","5"));
    REQUIRE(graph.Isconnected("1","2"));
    REQUIRE(graph.Isconnected("1","0"));
}

TEST_CASE("Test V2D_to_Graph_Largecase", "[weight=5]") {
    std::cout << __LINE__ << std::endl;
    V2D file = file_to_V2D("../tests/p2p-Gnutella08.txt");
    Graph graph = V2D_to_Graph(file);
    std::cout << __LINE__ << std::endl;
    std::cout << graph.size() << std::endl;
    std::vector<std::string> vertices = graph.GetVertices();
    // for (auto i : vertices) {
    //     std::cout<<i << std::endl;
    // }
    graph.print();
    REQUIRE(vertices.size() == 6301);

}
