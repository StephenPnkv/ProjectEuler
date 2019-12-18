/*
        | Stephen Penkov | CISP440 | Project Euler #25 | 2/22/17 |
 Purpose: This is a solutoin to Project Euler 25. To find the first term that contains
 1,000 digits, take the logarithm of the general solution when n = 999, and get the next highest whole number
 to get the proper index.
 */

#include <iostream>
#include <cmath>

int calc_nth_fib_index(int num_digits);

int main(int argc, const char * argv[]) {
    std::cout << "| Stephen Penkov | CISP440 | Project Euler #25 | 2/17/17 |" << std::endl;
    
    int digits;
    int index;
    
    digits = 3 - 1;
    index = calc_nth_fib_index(digits);
    std::cout << "\nThe first term to contain 3 digits is the " << index << "th term." << std::endl;
    
    digits = 1000 - 1;
    index = calc_nth_fib_index(digits);
    std::cout << "The first term to contain 1000 digits is the " << index << "th term." << std::endl;
        
    std::cout << "\nPress any key to continue . . . ";
    while(!getchar());
    
    return 0;
}

int calc_nth_fib_index(int num_digits){
    //This function takes the logarithm of the general solution to the fibonacci
    //sequence in order to find the first term with 1,000 digits. Since the fib number is large,
    //the second root, ((1 - sqrt(5)) / 2) may be ommitted.
    
    double root = (1 + sqrt(5)) / 2, term_num = 0;
    
    term_num = num_digits + (0.5 * log10(5));
    term_num /= log10(root);
    return ceil(term_num);
}
