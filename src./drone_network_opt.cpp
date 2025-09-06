#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

// Locations in the Lagos drone network
vector<string> nodes = {
    "Unilag", "Akoka", "Bariga", "Gbagada",
    "Yaba", "Surulere", "Ojuelegba",
    "Alagomeji", "Jibowu"
};

// Edges with distances
vector<tuple<string, string, int>> edges = {
    {"Unilag","Akoka",2}, {"Unilag","Yaba",3},
    {"Akoka","Bariga",2}, {"Bariga","Gbagada",4},
    {"Yaba","Ojuelegba",2}, {"Ojuelegba","Surulere",3},
    {"Yaba","Alagomeji",1}, {"Alagomeji","Jibowu",2},
    {"Jibowu","Ojuelegba",2}, {"Akoka","Alagomeji",2}
};

int main() {
    int n = nodes.size();
    unordered_map<string,int> idx; // map node name to index
    for(int i=0;i<n;i++) idx[nodes[i]] = i;

    // Distance and next matrices
    vector<vector<int>> dist(n, vector<int>(n, INF));
    vector<vector<int>> next(n, vector<int>(n, -1));

    // Initialize distances
    for(int i=0;i<n;i++) dist[i][i] = 0;
    for(auto &[u,v,w] : edges){
        int ui = idx[u], vi = idx[v];
        dist[ui][vi] = w;
        dist[vi][ui] = w;
        next[ui][vi] = vi;
        next[vi][ui] = ui;
    }

    // Floyd–Warshall algorithm
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dist[i][k] + dist[k][j] < dist[i][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                    next[i][j] = next[i][k];
                }
            }
        }
    }

    // Function to reconstruct path
    auto constructPath = [&](int u, int v){
        vector<int> path;
        if(next[u][v] == -1) return path; // no path
        path.push_back(u);
        while(u != v){
            u = next[u][v];
            path.push_back(u);
        }
        return path;
    };

    // Example queries
    string from, to;
    cout << "Enter source: ";
    cin >> from;
    cout << "Enter destination: ";
    cin >> to;

    if(idx.find(from)==idx.end() || idx.find(to)==idx.end()){
        cout << "Invalid node name!" << endl;
        return 0;
    }

    int u = idx[from], v = idx[to];
    auto path = constructPath(u,v);

    if(path.empty()){
        cout << "No path from " << from << " to " << to << endl;
    } else {
        cout << "Shortest path from " << from << " to " << to << ": ";
        for(int i=0;i<path.size();i++){
            cout << nodes[path[i]];
            if(i+1<path.size()) cout << " -> ";
        }
        cout << " (Distance " << dist[u][v] << " km)" << endl;
    }

    return 0;
}
