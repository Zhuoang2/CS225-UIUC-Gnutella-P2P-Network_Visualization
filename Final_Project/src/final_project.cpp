/**
 * @file final_project.cpp
 * Graph Algorithms
 */

#include <algorithm>
#include "../src/final_project.h"
#include "utils.h"
 
V2D file_to_V2D(const std::string & filename){
    std::string file = file_to_string(filename);
    V2D toreturn;
    std::vector<std::string> lines;
    SplitString(file,'\n',lines);

    for (std::string eachline: lines) {
        //the first lines are the description starting with #
        if (eachline[0] == '#') continue;
        // std::vector<std::string> line;
        // int size = 0;
        // if (eachline.find('\t') != std::string::npos) size = SplitString(eachline, '\t', line);
        // else size = SplitString(eachline, ' ', line);
        // if (size != 2) continue;
        // for (size_t i = 0; i < line.size(); i++) {
        //     line[i] = Trim(line[i]);
        // }
        // toreturn.push_back(line);
        std::vector<std::string> topush = string_split(eachline);
        if (topush.size() != 2) continue;
        toreturn.push_back(topush);
    }
    
    return toreturn;
}

Graph V2D_to_Graph(const V2D & file) {
    Graph graph = Graph();
    for (auto pair : file) {
        if (pair.size() == 1) graph.addVertice(pair[0]);
        else graph.addedge(pair[0],pair[1]);
    }
    graph.setCentrality();
    return graph;
}
