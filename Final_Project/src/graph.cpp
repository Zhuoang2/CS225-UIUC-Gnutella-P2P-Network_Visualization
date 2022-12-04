/**
 * @file graph.cpp
 * graph class & graph algorithm
 */
#include "graph.h"
#include <queue>

void Graph::addVertice(std::string src) {
    graph_[src] = std::unordered_set<std::string>();
}
    
void Graph::addedge(std::string src, std::string des) {
    graph_[src].insert(des);
    graph_[des].insert(src);
};

std::unordered_set<std::string> Graph:: GetNeighbor(std::string src) {
    return graph_[src];
}

bool Graph::Isconnected (std::string src, std::string des) {  
    return graph_[src].find(des) != graph_[src].end();
};

std::vector<std::string> Graph::GetVertices() {
    std::vector<std::string> keys;
    for (auto i: graph_) {
        keys.push_back(i.first);
    }
    return keys;
}

void Graph::print() {
    int stop = 0;
    for (auto i : graph_) {
        stop++;
        std::cout<<i.first<<": ";
        for (auto j : graph_[i.first]) {
            std::cout<<j<<" ";
        }
        std::cout<<std::endl;
        if (stop == 50) break;
    }
}

size_t Graph::size() {
    return graph_.size();
}

std::unordered_map<std::string, std::vector<std::string>> Graph::BFS (std::string vertex) {
    //unordered_map<string, int> distance;
    if (graph_.find(vertex) == graph_.end()) {
        cout<<vertex<<" is Not in the Graph!"<<endl;
        return std::unordered_map<std::string, std::vector<std::string>>();
    }


    unordered_map<string, string> laststep;

    for (string i : GetVertices()) {
        //distance[i] = -1;
        laststep[i] = "";
    }
    laststep[vertex] = "-";

    queue<string> q;
    q.push(vertex);

    while (!q.empty())
    {
        string front = q.front();
        q.pop();
        for (string i : GetNeighbor(front)) {
            if (laststep[i] != "") continue;
            
            laststep[i] = front;
            //distance[i] = 1 + distance[front];
            q.push(i);
            
        }

    }

    unordered_map<string, vector<string>> toreturn;



    for (string i : GetVertices()) {
        // if "", not in the same component
        if (laststep[i] == "") continue;
        vector<string> topush;
        string temp = i;
        while(laststep[temp] != "-") {
            topush.insert(topush.begin(), temp);
            temp = laststep[temp];
        }
        topush.insert(topush.begin(), vertex);
        toreturn[i] = topush;
    }
    
    return toreturn;
}


std::vector<std::string> Graph::Find_path(std::string src, std::string des) {
    std::unordered_map<std::string, std::vector<std::string>> path = BFS(src);
    if (path.size() == 0) return vector<string> ();

    if (path.find(des) == path.end()) {
        std::cout<<"Not connected!"<<endl;
        return vector<string> ();
    }
    return path[des];

}
