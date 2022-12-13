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

    std::cout << file.size() <<std::endl;
    std::cout << file[0].size()<<std::endl;

    // for (size_t i = 0; i < file.size(); i++) {
    //     for (size_t j = 0; j < file[i].size(); j++) {
    //         std::cout << file[i][j]<< " ";
    //     }
    //     std::cout << " " << std::endl;
    // }
    REQUIRE(file.size()== 6);
    REQUIRE(file[0][0] == "0");
    REQUIRE(file[0][1] == "1");
    REQUIRE(file[1][0] == "1");
    REQUIRE(file[1][1] == "2");
}

TEST_CASE("Test file_to_V2D_Mediancase", "[weight=5]") {
    V2D file = file_to_V2D("../tests/email-Eu-core.txt");
    // std::cout << __LINE__ << std::endl;
    for (size_t i = 0; i < file.size(); i++) {
        REQUIRE(file[i].size() == 2);
    }
    // std::cout << file[0][0] << file[0][1] << std::endl;
    // std::cout << file[1][0] << file[1][1] << std::endl;
    REQUIRE(file[0][0] == "0");
    REQUIRE(file[0][1] == "1");
    REQUIRE(file[1][0] == "2");
    REQUIRE(file[1][1] == "3");
    REQUIRE(file[43][0] == "60");
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
    REQUIRE(file.size() == 20777);
    REQUIRE(file[0][0] == "0");
    REQUIRE(file[0][1] == "1");
    REQUIRE(file[1][0] == "0");
    REQUIRE(file[1][1] == "2");
    REQUIRE(file[60][1] == "147");

}

TEST_CASE("Test V2D_to_Graph_Smallcase", "[weight=5]") {
    V2D file = file_to_V2D("../tests/smallcase.txt");
    Graph graph = V2D_to_Graph(file);
    REQUIRE(graph.size() == 6);
    REQUIRE(graph.Isconnected("1","5"));
    REQUIRE(graph.Isconnected("1","2"));
    REQUIRE(graph.Isconnected("1","0"));
}

TEST_CASE("Test V2D_to_Graph_Mediancase", "[weight=5]") {
    V2D file = file_to_V2D("../tests/email-Eu-core.txt");
    Graph graph = V2D_to_Graph(file);
    std::vector<std::string> vertices = graph.GetVertices();
    REQUIRE(graph.Isconnected("97","101"));
    REQUIRE(graph.Isconnected("158","159"));
    REQUIRE(graph.Isconnected("72","163"));
    REQUIRE(file.size() == 25571);
    REQUIRE(vertices.size() == 1005);
}


TEST_CASE("Test V2D_to_Graph_Largecase", "[weight=5]") {
    // std::cout << __LINE__ << std::endl;
    V2D file = file_to_V2D("../tests/p2p-Gnutella08.txt");
    Graph graph = V2D_to_Graph(file);
    // std::cout << __LINE__ << std::endl;
    // std::cout << graph.size() << std::endl;
    std::vector<std::string> vertices = graph.GetVertices();
    // for (auto i : vertices) {
    //     std::cout<<i << std::endl;
    // }
    // graph.print();
    REQUIRE(file.size() == 20777);
    REQUIRE(vertices.size() == 6301);
}

TEST_CASE("Test V2D_to_Graph_empty", "[weight=5]") {
    V2D file = file_to_V2D("../tests/empty.txt");
    Graph graph = V2D_to_Graph(file);
    std::vector<std::string> vertices = graph.GetVertices();
    REQUIRE(vertices.size() == 0);
}

TEST_CASE("Test BFS_Smallcase", "[weight=5]") {
    V2D file = file_to_V2D("../tests/smallcase.txt");
    Graph graph = V2D_to_Graph(file);
    std::unordered_map<std::string, std::vector<std::string>> bfs_0 = graph.BFS("0");
    // for (auto & map: bfs_0) {
    //     std::cout << map.first << ": ";
    //     for (size_t j = 0; j < map.second.size(); j++) {
    //         std::cout << map.second[j]<< " ";
    //     }
    //     std::cout << " " << std::endl;
    // }
    REQUIRE(bfs_0["0"].size() == 1);
    REQUIRE(bfs_0["1"].size() == 2);
    REQUIRE(bfs_0["5"].size() == 3);
}

TEST_CASE("Test BFS_Smallcase2", "[weight=5]") {
    V2D file = file_to_V2D("../tests/smallcase2.txt");
    Graph graph = V2D_to_Graph(file);
    std::unordered_map<std::string, std::vector<std::string>> bfs_0 = graph.BFS("0");
    // for (auto & map: bfs_0) {
    //     std::cout << map.first << ": ";
    //     for (size_t j = 0; j < map.second.size(); j++) {
    //         std::cout << map.second[j]<< " ";
    //     }
    //     std::cout << " " << std::endl;
    // }
    REQUIRE(bfs_0["0"].size() == 1);
    REQUIRE(bfs_0["3"].size() == 2);
}

TEST_CASE("Test BFS_Mediancase", "[weight=5]") {
    V2D file = file_to_V2D("../tests/email-Eu-core.txt");
    Graph graph = V2D_to_Graph(file);
    std::unordered_map<std::string, std::vector<std::string>> bfs_0 = graph.BFS("0");
    REQUIRE(bfs_0["0"].size() == 1);
    REQUIRE(bfs_0["1"].size() == 2);
    std::unordered_map<std::string, std::vector<std::string>> bfs_103 = graph.BFS("103");
    // for (size_t j = 0; j < bfs_103["218"].size(); j++) {
    //         std::cout << bfs_103["218"][j]<< " ";
    //     }
    std::cout << endl;
    REQUIRE(bfs_103["218"].size() == 3);
}


TEST_CASE("Test BFS_Largecase", "[weight=5]") {
    V2D file = file_to_V2D("../tests/p2p-Gnutella08.txt");
    Graph graph = V2D_to_Graph(file);
    std::unordered_map<std::string, std::vector<std::string>> bfs_0 = graph.BFS("0");
    REQUIRE(bfs_0["0"].size() == 1);
    REQUIRE(bfs_0["9"].size() == 2);
    std::unordered_map<std::string, std::vector<std::string>> bfs_5531 = graph.BFS("5531");
    REQUIRE(bfs_5531["2850"].size() == 2);
}


TEST_CASE("Test Find_path_Smallcase", "[weight=5]") {
    V2D file = file_to_V2D("../tests/smallcase.txt");
    Graph graph = V2D_to_Graph(file);
    std::vector<std::string> find_02 = graph.Find_path("0", "2");
    std::vector<std::string> find_14 = graph.Find_path("1", "4");
    // for (auto & i: find_02) {
    //     std::cout << i << " ";
    // }
    // std::cout<<std::endl;
    REQUIRE(find_02.size() == 3);
    REQUIRE(find_14.size() == 3);
}

TEST_CASE("Test Find_path_Mediancase", "[weight=5]") {
    V2D file = file_to_V2D("../tests/email-Eu-core.txt");
    Graph graph = V2D_to_Graph(file);
    std::vector<std::string> find_07 = graph.Find_path("0", "7");
    std::vector<std::string> find_5_441 = graph.Find_path("5", "441");

    std::vector<std::string> find_124_234 = graph.Find_path("124", "234");

    //not exist 
    std::vector<std::string> find_124_1500 = graph.Find_path("124", "1500");
    std::vector<std::string> find_1500_124 = graph.Find_path("1500", "124");
    std::vector<std::string> find_1500_1500 = graph.Find_path("1500", "1500");

    // for (auto & i: find_124_234) {
    //     std::cout << i << " ";
    // }
    // std::cout<<std::endl;

    REQUIRE(find_07.size() == 3);
    REQUIRE(find_5_441.size() == 3);
    REQUIRE(find_124_1500.size() == 0);
    REQUIRE(find_1500_124.size() == 0);
    REQUIRE(find_1500_1500.size() == 0);
}

TEST_CASE("Test Centrality Smallcase", "[weight=5]") {
    V2D file = file_to_V2D("../tests/smallcase.txt");
    Graph graph = V2D_to_Graph(file);
    for (string i : graph.GetVertices()) {
        std::cout << i << ' ' << graph.getCentrality(i) << std::endl;
    }
}

TEST_CASE("Test Centrality Smallcase_Disconnected Graph", "[weight=5]") {
    V2D file = file_to_V2D("../tests/smallcase_disconnected.txt");
    Graph graph = V2D_to_Graph(file);
    for (string i : graph.GetVertices()) {
        std::cout << i << ' ' << graph.getCentrality(i) << std::endl;
    }
}

TEST_CASE("Test Centrality Mediancase", "[weight=5]") {
    V2D file = file_to_V2D("../tests/email-Eu-core.txt");
    Graph graph = V2D_to_Graph(file);
    std::cout << "0 " << graph.getCentrality("0") << std::endl;
    std::cout << "10 " << graph.getCentrality("10") << std::endl;
    std::cout << "20 " << graph.getCentrality("20") << std::endl;
}

TEST_CASE("Test Centrality Largecase", "[weight=5]") {
    V2D file = file_to_V2D("../tests/p2p-Gnutella08.txt");
    Graph graph = V2D_to_Graph(file);
    std::cout << "0 " << graph.getCentrality("0") << std::endl;
    std::cout << "11 " << graph.getCentrality("11") << std::endl;
    std::cout << "20 " << graph.getCentrality("20") << std::endl;
    std::cout << "30 " << graph.getCentrality("30") << std::endl;
}

TEST_CASE("Test SortCentrality Smallcase", "[weight=5]") {
    V2D file = file_to_V2D("../tests/smallcase.txt");
    Graph graph = V2D_to_Graph(file);
    for (string i : graph.GetVertices()) {
        std::cout << i << ' ' << graph.getCentrality(i) << std::endl;
    }
    for (std::string i : graph.sortVertices()) {
        std::cout << i << ' ' ;
    }
    std::cout << std::endl;
}

TEST_CASE("Test SortCentrality Mediancase", "[weight=5]") {
    V2D file = file_to_V2D("../tests/email-Eu-core.txt");
    Graph graph = V2D_to_Graph(file);
    std::vector<std::string> sorted = graph.sortVertices();
    for (size_t i = 0; i < 10; i ++) {
        std::cout << sorted[i] << ' ' << graph.getCentrality(sorted[i]) << std::endl;
    }
}


TEST_CASE("Test plot_graph Smallcase", "[weight=5]") {
    plot_graph("../tests/smallcase.txt", "../tests/smallcase.png");
}

TEST_CASE("Test plot_graph Mediancase", "[weight=5]") {
    plot_graph("../tests/email-Eu-core.txt", "../tests/email-Eu-core.png");
}

TEST_CASE("Test plot_graph Largecase", "[weight=5]") {
    plot_graph("../tests/p2p-Gnutella08.txt", "../tests/p2p-Gnutella08.png");
}