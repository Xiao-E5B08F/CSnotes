#include <iostream>
#include <vector>
using std::cout, std::cin, std::ios_base;

#define IO_optimization ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl '\n';
struct node {
    char name;
    std::vector <node *> neighbors;
};

std::vector<node *> visited_nodes;
void DFS(node *start){
    cout << start -> name << " ";
    visited_nodes.push_back(start);
    for (int i = 0; i < start -> neighbors.size(); i++){
        bool visited = false;
        for (int j = 0; j < visited_nodes.size(); j++){
            if (start->neighbors[i]->name == visited_nodes[j]->name)
                visited = true;
        }
        if( !visited )
            DFS(start->neighbors[i]);
    }

}
int main(void){
    IO_optimization
    std::vector <node*> graph;
    graph.resize(7);
    char name = 'A';
    for (int i = 0; i < 7; i++){
        graph[i] = new node;
        graph[i]->name = name + i;
        //cout << graph[i]->name << " ";
    }
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