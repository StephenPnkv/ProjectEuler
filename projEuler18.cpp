
/*
 | Stephen Penkov | CISP440 | Project Euler #18 |
 Purpose: This is a solution to Project Euler #18. This algorithm uses breadth
 first traversal to find the largest sum of the given triangle.
 
 
 */

#include <iostream>
#include <list>
#include <fstream>
#include <vector>
#include <stack>

class Graph{
public:
    Graph(int size);
    void add_edges();
    void fill_data(std::string);
    void DFS_find_sum(int start);
    void print_path(int);
    
private:
    std::list<int> * table;
    int table_size;
    std::vector<int> vertices;
    int * shortest_path;
    int * row_number;
    int num_rows;
    
};

int main()
{
    std::cout << "| Stephen Penkov | CISP440 | Project Euler #18 |\n" << std::endl;
    
    int size = 120;
    Graph G(size);
    std::string file_name = "/Users/stephenpenkov/Desktop/Education!/CISP440/Assignment8/ProjEuler18/ProjEuler18/triangle.txt";
    G.fill_data(file_name);
    G.add_edges();
    G.DFS_find_sum(0);
    G.print_path(0) ;
    
    std::cout << "\nPress any key to continue . . .";
    while (!std::cin.get())
        
        return 0;
}



Graph::Graph(int size){
    table_size = size;
    table = new std::list<int>[table_size];
}

void Graph::add_edges(){
    for(int i = 0   ; i < (table_size - num_rows); ++i){
        table[i].push_back((i + 1 + row_number[i]));
        table[i].push_back((i + 2 + row_number[i]));
    }
}

void Graph::DFS_find_sum(int start){
    std::stack<int> my_stack;
    std::list<int>::iterator iter;
    
    shortest_path = new int[table_size];
    std::fill_n(shortest_path, table_size, -1);
    
    int limit = table_size - num_rows,
    parent = start,
    max_sum = 0;
    
    my_stack.push(parent);
    while(!my_stack.empty()){
        
        parent = my_stack.top();
        shortest_path[parent] = vertices[parent];
        max_sum += vertices[parent];
        my_stack.pop();
        
        if(parent > limit)
            return;
        
        int best_sum = 0, path1 = 0, path2 = 0, child = 0, next = 0;
        
        for(iter = table[parent].begin(); iter != table[parent].end(); ++iter){
            path1 = vertices[parent] + vertices[*iter] + vertices[table[*iter].front()];
            path2 = vertices[parent] + vertices[*iter] + vertices[table[*iter].back()];
            
            if(path1 > path2 && path1 > best_sum){
                best_sum = path1;
                child = *iter;
                next = table[*iter].front();
                
            }else if(path2 > path1 && path2 > best_sum){
                best_sum = path2;
                child = *iter;
                next = table[*iter].back();
            }
            
        }
        shortest_path[child] = vertices[child];
        max_sum += vertices[child];
        my_stack.push(next);
        
    }
    
    
}

void Graph::print_path(int v){
    int total = 0;
    for(int i = v; i < table_size; ++i){
        if(shortest_path[i] != -1){
            std::cout << shortest_path[i] << "  ";
            total += shortest_path[i];
        }
        
    }
    std::cout << "\nThe maximum sum of the triangle is: " << total << std::endl;
}

void Graph::fill_data(std::string file_name){
    std::ifstream file;
    file.open(file_name);
    if(!file){
        std::cout << "\nFailed to open the file." << std::endl;
        return;
    }
    
    num_rows = 0;
    file >> num_rows;
    
    row_number = new int[table_size];
    for(int i = 0; i < table_size; ++i){
        row_number[i] = 0;
    }
    
    int vertex = 0,range = 0;
    for(int row = 0; row < num_rows; ++row){
        file >> vertex;
        while(vertex != -1){
            
            vertices.push_back(vertex);
            row_number[range] = row + 1;
            ++range;
            file >> vertex;
            
        }
    }
    row_number[0] = 0;
    file.close();
}























































