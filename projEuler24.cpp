/*
        | Stephen Penkov | CISP440 | Project Euler #24 | 2/11/17 |
 Purpose: This is a solution to project euler #24. This program finds
 the nth permutation of any given set. The objective was to find the 1,000,000th 
 permutation of the set {0..9}, which comes out to: 2783915460.
 
 */

#include <iostream>
#include <cmath>
#include <deque>

//Define queue in global scope
std::deque<int> my_queue;

void find_permutations(int arr[], int nth_perm, int size);
int factorial(int n);
void print(int arr[], int nth, int set_size);

int main(int argc, const char * argv[]) {
    //Arrays to process
    int cache[10] = {0,1,2,3,4,5,6,7,8,9},
    test_cache[4] = {1,2,3,4},
    //Arrays for printing
    cache2[10] = {0,1,2,3,4,5,6,7,8,9},
    test_cache2[4] = {1,2,3,4};
    
    //Define permutation number and set size
    int nth_permutation = 1000000 - 1, set_size = 10;
    
    std::cout << "| Stephen Penkov | CISP440 | Project Euler #24 | 2/11/17 | " << std::endl;
    
    //Call functions with relevant data
    set_size = 4;
    nth_permutation = 13 - 1;
    find_permutations(test_cache, nth_permutation, set_size);
    print(test_cache2,nth_permutation + 1, set_size);
    
    //Clear the queue
    my_queue.clear();
    
    //Call functions with relevant data
    set_size = 10;
    nth_permutation = 1000000 - 1;
    find_permutations(cache,nth_permutation,set_size);
    print(cache2, nth_permutation + 1, set_size);
    
    
    //Pause
    std::cout << "\n\nPress any key to continue  .  .  . " << std::endl;
    while(!std::cin.get());
    return 0;
}

int factorial(int n ){
    //Function to calculate factorials.
    if(n == 0 || n == 1)
        return 1;
    else
        return n * factorial(n - 1);
}

void find_permutations(int arr[], int nth_perm, int set_size){
    //This function finds the nth permutation of a given set.
    
    int * cache;
    cache = arr;
    int index = 0;
    
    for(int n = set_size - 1; n >= 0; --n){
        //get the index.
        index = floor(nth_perm / factorial(n));
        //n equals zero, process last element, break out of the loop
        if(n == 0){
            my_queue.push_back(cache[n]);
            return;
        }
        //store the number in the set
        my_queue.push_back(cache[index]);
        nth_perm -= (index * factorial(n));
        
        //adjust the array to remove the processed element
        for(int i = index; i < set_size; ++i){
            cache[i] = cache[i + 1];
        }
        --set_size;
    }
    
}

void print(int arr[], int nth, int set_size){
    //Print the contents of the queue.
    std::deque<int>::iterator it;
    int * arr_ptr;
    arr_ptr = arr;
    
    std::cout << "\nThe " << nth << "th permutation in the set ";
    std::cout << "{ ";
    for (int i = 0; i < set_size; ++i) {
        if(i + 1 != set_size)
            std::cout << arr_ptr[i] << ", ";
        else
            std::cout << arr_ptr[i];
   
    }
    std::cout << " } is: ";
    for (it = my_queue.begin(); it != my_queue.end(); ++it){
        std::cout << *it;
    }
    std::cout << ".";
}
