#include <iostream>
#include <vector>
#include <stack>
using std::cout, std::cin, std::ios_base;

#define IO_optimization ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl '\n';
struct node {
    char name;
    std::vector<node *> neighbors; // Sort by dictionary order.
    bool visited = false;   // True means visited, otherwise false.
};

std::stack<node *> path;

void DFS(node *start){
    // Print out the information about the node and mark it as visited.
    cout << start->name << " " ; 
    path.push(start);
    start->visited = true;
    // Make all the neighbors to do DFS.
    for (int i = 0; i < start -> neighbors.size(); i++){  
        if (!start -> neighbors[i] -> visited)
            DFS(start -> neighbors[i]);            
    }
    // Back to the previous node.
    path.pop(); 
}

int main(void){
    IO_optimization
    std::vector <node*> graph;
    graph.resize(7);
    char name = 'A';
    // Initialize the every node in the graph
    for (int i = 0; i < 7; i++){ 
        graph[i] = new node;
        graph[i]->name = name + i;
    }
    // The code below is about the link between the nodes 
    // A:
    graph[0]->neighbors.push_back(graph[1]);
    graph[0]->neighbors.push_back(graph[2]);
    graph[0]->neighbors.push_back(graph[4]);
    // B:
    graph[1]->neighbors.push_back(graph[0]);
    graph[1]->neighbors.push_back(graph[3]);
    // C:
    graph[2]->neighbors.push_back(graph[0]);
    graph[2]->neighbors.push_back(graph[3]);
    graph[2]->neighbors.push_back(graph[5]);
    // D:
    graph[3]->neighbors.push_back(graph[1]);
    graph[3]->neighbors.push_back(graph[2]);
    graph[3]->neighbors.push_back(graph[6]);
    // E:
    graph[4]->neighbors.push_back(graph[0]);
    graph[4]->neighbors.push_back(graph[5]);
    // F:
    graph[5]->neighbors.push_back(graph[2]);
    graph[5]->neighbors.push_back(graph[4]);
    graph[5]->neighbors.push_back(graph[6]);
    // G:
    graph[6]->neighbors.push_back(graph[3]);
    graph[6]->neighbors.push_back(graph[5]);
    
    DFS(graph[0]);
    
    return 0;
}

/*
A B C D E F G
0 1 2 3 4 5 6 
*/