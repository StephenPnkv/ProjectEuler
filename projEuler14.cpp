/*
            | Stephen Penkov | CISP440 | Project Euler #14 | 2/22/17 |
    Purpose: This is a solution to Project Euler #14. It calculates the chain sizes by
    recursively calling the calculate_chain_length() function to get the chain size. If the 
    sequence reaches a term, where the chain was already processed, the size is extracted from
    the array and summed into the current size.
 
 
 */
#include <iostream>

const int limit = 1000000;
int processed_chain_sizes[limit] = {0};
void calculate_chain_length(long int num, int processed, int &count);

int main(int argc, const char * argv[]) {
    
    int sequence_size = 0, target_term = 0, largest_sequence_size = 0;
    
    std::cout << "\n| Stephen Penkov | CISP440 | Project Euler #14 | 2/22/17 | \n" << std::endl;
    
    for(int i = 1; i <= limit; ++i){
        //call function calculate the chain size for every number less than one million.
        calculate_chain_length(i, i - 1, sequence_size);
        
        //Print test case.
        if(i == 13){
            std::cout << "The number 13 produces a sequence of "
            << sequence_size << " terms." << std::endl;
        }
        
        //Store the chain size for the processed term.
        processed_chain_sizes[i] = sequence_size;
        
        //Keep track of the starting term with the largest chain size.
        if(sequence_size > largest_sequence_size){
            largest_sequence_size = sequence_size;
            target_term = i;
        }
        //Reset the size.
        sequence_size = 0;
    }
    
    //Print result
    std::cout << "The number " << target_term << " produces the largest sequence of "
              << largest_sequence_size << " terms." << std::endl;
    std::cout << "\nPress any key to continue . . . ";
    while(!std::cin.get());
    return 0;
}

void calculate_chain_length(long int num, int processed_term, int &sequence_size){
    //If the number is one, the function terminates as the entire chain is processed.
    if(num == 1){
        ++sequence_size;
        processed_chain_sizes[processed_term + 1] = sequence_size;
        return;
    }
    //When the term number gets reduced to a number less than the starting number, the
    //algorithm retrieves the cached size to reduce unnecessary computations.
    if(num <= processed_term){
        sequence_size += processed_chain_sizes[num];
        return;
    }
    
    //Recursive calls and operations. If the number is even, divide by two, increment
    //the chain size. If odd, multiply by 3 and add 1, increment chain size. Call the
    //function again recursively until the number has been reduced to 1.
    if(num % 2 == 0){
        num /= 2;
        ++sequence_size;
        calculate_chain_length(num, processed_term, sequence_size);
        
    }else{
        num = (3 * num) + 1;
        ++sequence_size;
        calculate_chain_length(num, processed_term, sequence_size);
    }
}
