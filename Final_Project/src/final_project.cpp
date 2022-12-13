/**
 * @file final_project.cpp
 * Graph Algorithms
 */

#include <algorithm>
#include "../src/final_project.h"
#include "utils.h"
#include <time.h>
 
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


void plot_graph(const std::string & filename, const std::string & output) {

    srand((unsigned)time(NULL)); 
    V2D file = file_to_V2D(filename);
    Graph graph = V2D_to_Graph(file);


    Image canvas; canvas.readFromFile("../lib/canvas.png");
    Image spot_white; spot_white.readFromFile("../lib/spot.png");
    Image spot_Red; spot_Red.readFromFile("../lib/spot_Red.png");
    Image spot_Blue; spot_Blue.readFromFile("../lib/spot_Blue.png");
    Image spot_Green; spot_Green.readFromFile("../lib/spot_Green.png");
    Image spot_Yellow; spot_Yellow.readFromFile("../lib/spot_Yellow.png");
    StickerSheet sheet(canvas, 100);

    vector<pair<unsigned,unsigned>> locations;
    vector<string> vertices = graph.sortVertices();


    for (size_t i = 0; i < vertices.size(); i++) {
        //1920 * 1080
        if (i == 100) break;
        pair<unsigned, unsigned> loc = {rand() % 1850, rand() % 1000};
        locations.push_back({loc.first + 25, loc.second + 15});
        if (i == 0) sheet.addSticker(spot_Red,loc.first,loc.second);
        else if (i < 5) sheet.addSticker(spot_Blue,loc.first,loc.second);
        else if (i < 15) sheet.addSticker(spot_Green,loc.first,loc.second);
        else if (i < 35) sheet.addSticker(spot_Yellow,loc.first,loc.second);
        else sheet.addSticker(spot_white,loc.first,loc.second);
        double lambda = graph.getCentrality(vertices[i]) / graph.size();
        sheet.getSticker(i)->scale(1.5 * lambda);
        
    }
    
    Image toreturn = sheet.render();
    // add lines:
    for (size_t i = 0; i < locations.size(); i++) {
        for (size_t j = i + 1; j < locations.size(); j++) {
            if (graph.Isconnected(vertices[i],vertices[j])) toreturn.addline(locations[i],locations[j]);
        }
    }
    toreturn.writeToFile(output);
    cout<<"The hub is Node:"<<vertices[0]<<endl;
}