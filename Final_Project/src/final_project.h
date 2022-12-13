/**
 * @file final_project.h
 * Graph Algorithms
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

#include "graph.h"
#include "Image.h"
#include "StickerSheet.h"


using namespace std;

typedef std::vector<std::vector<std::string> > V2D; 

V2D file_to_V2D(const std::string & filename);

Graph V2D_to_Graph(const V2D & file);

void plot_graph(const std::string & filename, const std::string & output);