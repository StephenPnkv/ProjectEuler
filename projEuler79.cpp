

/*
                Stephen Penkov, CISP440, 3.29.17
    Purpose: This is a soluiton to Project Euler #79. It uses a depth-first
    search to find the shortest possible passcode of the given data.
*/
#include<iostream>
#include <list>
#include <fstream>
#include <vector>

class Graph{
public:
    Graph(int size, int num_v);
    
    void print_edges(int vertex);
    void fill_data(std::string file_name);
    
    void depth_first(int start);
    void find_shortest_passcode(int set[]);
    
private:
    std::vector<int> vertices;
    std::list<int> * dfs_codes;
    int num_v;
    std::list<int> * table;
    int table_size;
};

void Graph::depth_first(int start){
    bool * processed = new bool[table_size];
    std::fill_n(processed, table_size, false);
    
    std::list<int>::iterator iter;
    std::list<int> my_queue;
    
    int data = start;
    processed[data] = true;
    my_queue.push_back(data);
    
    while(!my_queue.empty()){
        data = my_queue.back();
        dfs_codes[start].push_back(data);
        my_queue.pop_back();
        
        for(iter = table[data].begin(); iter != table[data].end(); ++iter){
            if(!processed[*iter]){
                processed[*iter] = true;
                my_queue.push_back(*iter);
            }
        }
        
    }
}

void Graph::find_shortest_passcode(int set[]){
    
    int num_dig = table_size - 1;
    
    for(int i = 0; i < table_size; ++i){
        
        depth_first(i);
    }
    std::cout << "\nThe shortest possible secret passcode, of unknown length is:" << std::endl;
    for(int i = 1; i <= num_dig; ++i){
        for (int j = 0; j < table_size; ++j) {
            while(set[j] == -1)
                ++j;
            if(dfs_codes[j].size() == i)
                std::cout << j << " ";
        }
    }
    std::cout << std::endl;
}

Graph::Graph(int size, int num_vert){
    table_size = size;
    table = new std::list<int>[table_size];
    num_v = num_vert;
    dfs_codes = new std::list<int>[table_size];
}

void Graph::print_edges(int vertex){
    std::list<int>::iterator it;
    std::cout << "\n\nVertex " << vertex << " has edges: ";
    if(table[vertex].empty())
        std::cout << "\nTable is empty." << std::endl;
    for(it = table[vertex].begin(); it != table[vertex].end(); ++it){
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void Graph::fill_data(std::string file_name){
    std::ifstream file;
    file.open(file_name);
    if(!file){
        std::cout << "\nFailed to open the file." << std::endl;
        return;
    }
    int v1 = 0, v2 = 0, v3 = 0;
    for(int i = 0; i < (num_v / 3); ++i){
        file >> v1 >> v2 >> v3;
        table[v3].push_back(v1);
        table[v3].push_back(v2);
        table[v2].push_back(v1);
        
    }
    file.close();
}

int main()
{
    std::cout << "| Stephen Penkov | CISP440 | Project Euler #79 | 3/29/17 |\n" << std::endl;
    
    int tableSize = 10, num_vertices = 18;
    //"/Users/stephenpenkov/Desktop/Education!/CISP440/Assignment9/Assignment9/keylog_test.txt"
    std::string data_file = "/Users/stephenpenkov/Desktop/Education!/CISP440/Assignment9/Assignment9/keylog_test.txt";
    int num_set_test[10] = {-1,1,2,3,-1,5,-1,7,8,-1};

    std::cout << "Test case. ";
    Graph test_graph(tableSize, num_vertices);
    test_graph.fill_data(data_file);
    test_graph.find_shortest_passcode(num_set_test);
    
    num_vertices = 150;
    //"/Users/stephenpenkov/Desktop/Education!/CISP440/Assignment9/Assignment9/keylog.txt"
    int num_set[10] = {0,1,2,3,-1,-1,6,7,8,9};
    data_file = "/Users/stephenpenkov/Desktop/Education!/CISP440/Assignment9/Assignment9/keylog.txt";
    Graph G(tableSize,num_vertices);
    G.fill_data(data_file);
    G.find_shortest_passcode(num_set);
    
    std::cout << "\n\nPress any key to continue . . .";
    while (!std::cin.get())
    return 0;
}




