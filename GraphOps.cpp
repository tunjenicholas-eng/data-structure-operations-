#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <unordered_set>
#include <algorithm> // For std::remove
using namespace std;

class Graph {
private:
    unordered_map<int, vector<int>> adjList;

public:
    // 1. Add Vertex
    void addVertex(int v) {
        if (adjList.find(v) == adjList.end()) {
            adjList[v] = vector<int>();
            cout << "Vertex " << v << " added." << endl;
        }
    }

    // 2. Add Edge
    void addEdge(int src, int dest) {
        addVertex(src); // Ensure vertices exist
        addVertex(dest);
        adjList[src].push_back(dest);
        adjList[dest].push_back(src); // Undirected graph
        cout << "Edge added between " << src << " and " << dest << endl;
    }

    // 3. Remove Edge
    void removeEdge(int src, int dest) {
        if (adjList.count(src) && adjList.count(dest)) {
            adjList[src].erase(remove(adjList[src].begin(), adjList[src].end(), dest), adjList[src].end());
            adjList[dest].erase(remove(adjList[dest].begin(), adjList[dest].end(), src), adjList[dest].end());
            cout << "Edge removed between " << src << " and " << dest << endl;
        }
    }

    // 4. Remove Vertex
    void removeVertex(int v) {
        if (adjList.count(v)) {
            // Remove all edges pointing to this vertex from neighbors
            for (int neighbor : adjList[v]) {
                adjList[neighbor].erase(remove(adjList[neighbor].begin(), adjList[neighbor].end(), v), adjList[neighbor].end());
            }
            adjList.erase(v); // Remove the vertex itself
            cout << "Vertex " << v << " removed." << endl;
        }
    }

    // 5. Traversal (Breadth-First Search)
    void BFS(int start) {
        if (adjList.find(start) == adjList.end()) return;
        unordered_set<int> visited;
        queue<int> q;
        
        q.push(start);
        visited.insert(start);

        cout << "BFS Traversal starting at " << start << ": ";
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            cout << current << " ";
            for (int neighbor : adjList[current]) {
                if (visited.find(neighbor) == visited.end()) {
                    visited.insert(neighbor);
                    q.push(neighbor);
                }
            }
        }
        cout << endl;
    }
};

int main() {
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    
    g.BFS(0);
    
    g.removeEdge(0, 1);
    g.removeVertex(3);
    
    g.BFS(0); 

    return 0;
}