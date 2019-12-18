
/*
    | Stephen Penkov | CISP440: Project Euler #3 | 2/8/17 |
 Purpose: This algorithm is a solution to Project Euler #3. It uses
 brute force to find factors of any number, and removes the factor from the
 input through division to reduce CPU time.
 
 */

#include <iostream>
#include <cmath>
#include <deque>
#include <time.h>

typedef long long BigNum;
//queue defined in global scopes
std::deque<int> my_queue;

//function definition.
void print_heading();
void find_primes(BigNum num);
void print_primes(BigNum num);
bool is_prime(int num);

int main()
{
    //clock variables to calculate algorithm runtime.
    clock_t t;
    t = clock();
    
    //test data
    BigNum num1 = 65975, num2 = 600851475143;
    print_heading();
    
    //function calls
    find_primes(num1);
    print_primes(num1);
    
    //clear queue
    my_queue.clear();
    
    //call again
    find_primes(num2);
    print_primes(num2);
    
    //calc clock time
    t = clock() - t;
    std::cout << "\nSolutions found in: " << 1000 *(((float)t) / CLOCKS_PER_SEC) << " ms." << std::endl;
    
    //pause screen
    std::cout << "\n\nPress any key to continue . . . " << std::endl;
    while (!std::cin.get())
        
    return 0;
    
}

void print_heading(){
    //Print the heading
    std::cout << "| Stephen Penkov | CISP440 | Project Euler #3 | 2/6/17 |\n" << std::endl;
}

bool is_prime(int num){
    for (int i = 3; i <= 9; ++i) {
        if(num % i == 0)
            return false;
    }
    return true;
}
void find_primes(BigNum n){
    //This algorithm uses brute force, looping through
    //odd numbers since no evens are prime. If a factor is found, it's added to the queue
    //and is taken out of the n through division. If n equals 1,
    //the algorithm terminates since all factors are found.
    BigNum num = n;
    //Start at 3 to eliminate the 1's, handle 2's later.
    for (int i = 3; i < n; i+=2) {
        //Break when all factors are found.
    
        if (num == 1)
            break;
    
        //Handle 2's
        if(i == 3 && num % 2 == 0){
            my_queue.push_back(2);
            num /= 2;
        }
        
        if(num % i == 0){
            //Prime factor found, remove the factor from the number to
            //reduce iterations. Perfect squares of primes factors are handled by processing
            //the factor once, but continuing division to finish the function call.
            double root = sqrt(i);
            if(root == floor(root)){
                num /= i;
            }else{
                my_queue.push_back(i);
                num /= i;
            }
            
        }
    }
    
}

void print_primes(BigNum num){
    //Print the set by iterating through the queue.
    std::deque<int>::iterator it;
    
    std::cout << "The set of the prime factors of " << num << " is: ";
    std::cout << "{ ";
    for (it = my_queue.begin(); it != my_queue.end(); ++it) {
        if((it + 1) == my_queue.end())
            std::cout << *it;
        else
            std::cout << *it << ", ";
    }
    std::cout << " }\n";
}



