/**
 * @file graph.h
 * graph class & graph algorithm
 */

#pragma once

#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <fstream>
#include <sstream>
#include <set>
#include <iostream>
#include <queue>

using namespace std;

 

class Graph {
private:
    std::unordered_map<std::string, std::unordered_set<std::string>> graph_; 

    std::unordered_map<std::string, double> centrality_; //vertex to pair<connected component number, centrality value>
    
public:
    
    Graph() = default;
    ~Graph() = default;

    void addVertice(std::string src);

    void addedge(std::string src, std::string des);

    std::unordered_set<std::string> GetNeighbor(std::string src);

    bool Isconnected (std::string src, std::string des);

    std::vector<std::string> GetVertices();

    void print();

    size_t size();

    double getCentrality(std::string vertex);
    
    // Find the shortest path from a source to all the other vertices within the same component.
    std::unordered_map<std::string, std::vector<std::string>> BFS (std::string vertex);

    //Find path.
    std::vector<std::string> Find_path(std::string src, std::string des);

    void setCentrality(); // set centrality_

    vector<string> sortVertices(); //sort all vertices by centrality value from large to small

    int partition(vector<string>& vec, int left, int right);  //helper for sortVertices
    void quickSort(vector<string>& vec, int left, int right); //helper for sortVertices
};