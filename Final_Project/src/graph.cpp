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
    vector<string> vertices = GetVertices();

    for (string i : vertices) {
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

    double centrality = 0.0;
    for (string i : vertices) {
        // if "", not in the same component
        if (laststep[i] == "") continue;
        vector<string> topush;
        string temp = i;
        int distance = 0;
        while(laststep[temp] != "-") {
            topush.insert(topush.begin(), temp);
            temp = laststep[temp];
            distance ++;
        }
        if (distance != 0) centrality += 1 / (distance*1.0);
        topush.insert(topush.begin(), vertex);
        toreturn[i] = topush;
    }
    centrality_[vertex] = centrality;

    return toreturn;
}


std::vector<std::string> Graph::Find_path(std::string src, std::string des) {
    std::unordered_map<std::string, std::vector<std::string>> path = BFS(src);
    if (path.size() == 0) return vector<string> ();

    if (path.find(des) == path.end()) {
        //std::cout<<"Not connected!"<<endl;
        return vector<string> ();
    }
    return path[des];

}

void Graph::setCentrality() {
    for (string i : GetVertices()) BFS(i);
    
}

double Graph::getCentrality(std::string vertex) {
    return centrality_[vertex];
}

vector<string> Graph::sortVertices() {
    vector<string> vertices = GetVertices();
    quickSort(vertices, 0, vertices.size()-1);
    return vertices;
}

int Graph::partition(vector<string>& vec, int left, int right) {
    string pivot = vec[right];
    int i = left - 1;
    for (int j = left; j < right; j++) {
        if (centrality_[vec[j]] > centrality_[pivot]) {
            i++;
            swap(vec[i], vec[j]);
        }
    }
    swap(vec[i+1], vec[right]);
    return i + 1;
}

void Graph::quickSort(vector<string>& vec, int left, int right) {
    if (left < right) {
        int p = partition(vec, left, right);
        quickSort(vec, left, p - 1);
        quickSort(vec, p+1, right);
    }
}