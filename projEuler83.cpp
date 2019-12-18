/*
                    | Stephen Penkov | CISP440 | Project Euler #83 |
    This is a solution to Project Euler #83. The program traverses the matrix by using a priority queue
    to find the least sum of the matrix.
*/
#include <iostream>
#include <queue>
#include <fstream>

struct Node{int x, y, weight;};
bool operator<(Node x, Node y){
    return x.weight > y.weight;
}

class Graph{
public:
    Graph(int,int);
    Node create_node(int, int, int);
    void visit_util(int, int, int);
    void Dijkstras_find_min_path();
    void input_data(std::string);
private:
    int N, V;
    std::priority_queue<Node> queue;
    int ** matrix;
    bool ** visited;
};

int main()
{
    std::cout << "| Stephen Penkov | CISP440 | Project Euler #83 |\n" << std::endl;
    int n = 80, v = 1600;
    std::string file_name = "matrix.txt";
    Graph G(n,v);
    G.input_data(file_name);
    G.Dijkstras_find_min_path();
    
    n = 5, v = 25;
    Graph test(n,v);
    file_name = "matrix_test.txt";
    test.input_data(file_name);
    test.Dijkstras_find_min_path();
    
    std::cout << "\nPress any key to continue . . .";
    while (!std::cin.get())
    return 0;
}


Graph::Graph(int n, int v){
    N = n;
    V = v;
    
    matrix = new int*[N];
    for(int i = 0; i < N; ++i)
        matrix[i] = new int[N];
    
    visited = new bool*[N];
    for(int i = 0; i < N; ++i)
        visited[i] = new bool[N];
}

Node Graph::create_node(int u, int v, int w){
    Node new_node;
    
    new_node.x = u;
    new_node.y = v;
    new_node.weight = w;
    
    return new_node;
}

void Graph::visit_util(int x, int y, int w){
    //If the index is invalid.
    if(x >= N || x < 0 || y >= N|| y < 0)
        return;
    //If not visited
    if(!visited[x][y]){
        Node next = create_node(x, y,w + matrix[x][y]);
        queue.push(next);
        visited[x][y] = true;
    }
    
    
}

void Graph::Dijkstras_find_min_path(){
    Node current_node = create_node(0, 0, matrix[0][0]);
    queue.push(current_node);
    
    while(!queue.empty()){
        //Node with least weight
        current_node = queue.top();
        queue.pop();
        
        if(current_node.x == N - 1 && current_node.y == N - 1){
            std::cout << "\nThe minimum sum of the " << N << " x " << N << " matrix is: " << current_node.weight << std::endl;
            return;
        }
        //Visit all adjacent nodes.
        visit_util(current_node.x, current_node.y + 1, current_node.weight);
        visit_util(current_node.x, current_node.y - 1, current_node.weight);
        visit_util(current_node.x + 1, current_node.y, current_node.weight);
        visit_util(current_node.x - 1, current_node.y, current_node.weight);
    }
}

void Graph::input_data(std::string file_name){
    std::fstream file;
    file.open(file_name);
    if(!file){
        std::cout << "failed to open file. " << std::endl;
    }
    int vertex = 0;
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            file >> vertex;
            file.ignore();
            matrix[i][j] = vertex;
        }
    }
}
