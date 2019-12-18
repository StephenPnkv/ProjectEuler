/*
    | Stephen Penkov | Assignment 1 | CISP440 | 1/24/17 |
 Purpose: This cpp file contains the solution to Project Euler problem #66, utilizing 
 a brute force technique.
 
 */

#include <iostream>
#include <math.h>

bool is_square(int num);
void calculate(int d_lim, int y_lim, int * greatest_x, int * target);



int main(){
    
    int greatest_x = 0, target = 0;
    
    const int y_lim = 10000;
    const int d_lim1 = 7, d_lim2 = 1000;
    std::cout << "| Stephen Penkov | Project Euler #66 | CISP440 | 1/25/17 |\n" << std::endl;
    
    calculate(d_lim1, y_lim, &greatest_x, &target);
    std::cout << "For D less than or equal to 7, the largest value of x is "
    << greatest_x << " when D is " << target << "." << std::endl;
    calculate(d_lim2, y_lim, &greatest_x, &target);

    std::cout << "For D less than or equal to 50, the largest value of x is "
              << greatest_x << " when D is " << target << "." << std::endl;
    
    std::cout << "\nPress Any Key To Continue . . . " << std::endl;
    while (!std::cin.get())
    
    
    return 0;
    
}

bool is_square(int num){
    double result = 0.0;
    result = sqrt(num);
    if(result == floor(result))
        return true;
    else
        return false;
}

void calculate(int d_lim, int y_lim, int * greatest_x, int * target ){
    double x = 0;
    for(int d = 2; d <= d_lim; ++d){
        //if its a perfect square, increment.
        if(is_square(d))
            ++d;
        //get values for y to solve for x.
        for(int y = 1; y < y_lim; ++y){
            // x = (1 + Dy^2)^(1/2)
            x = sqrt(1 + (d*y*y));
            //its a whole number, solution found.
            if(x == floor(x)){
                //set the greatest x found.
                if(x > *greatest_x){
                    *greatest_x = x;
                    *target = d;
                }
                break;
                
            }
            
        }
    }
}













