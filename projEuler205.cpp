
/*
        | Stephen Penkov | CISP440 | Project Euler #205 | 3/15/17 |
 Purpose: This is a solution to Project Euler #205. The function counts the number of ways
 to achieve a certain sum, and stores it in the array. The probability of Pete beating Collin
 is the ratio of the total winning combinations to the total possible combinations.
 */

#include <iostream>
#include <iomanip>
#include <cmath>

void peter1(int arr[]);
void collin1(int arr[]);
void peter2(int arr[]);
void collin2(int arr[]);

int main()
{
    std::cout << "| Stephen Penkov | CISP440 | Project Euler #205 | 3/15/17 |" << std::endl;
    
    long double total = 0;
    int ways_six_sided_die1[12] = {0}, ways_four_sided_die1[12] = {0},
    ways_six_sided_die2[36] = {0}, ways_four_sided_die2[36] = {0};
    
    //test case
    peter1(ways_four_sided_die1);
    collin1(ways_six_sided_die1);
    
    for (int i = 0; i < 12; i++)
        for (int j = 0; j < i; j++)
            total += ways_six_sided_die1[j] * ways_four_sided_die1[i];
    
    long double tot_possible_combinations = (pow(4, 3) * pow(6, 2));
    total /= tot_possible_combinations;
    std::cout << "\nTest Case: " << std::endl;
    std::cout << "The probability that Pete beats Collin is: ";
    std::cout << std::setprecision(7) << total << "." << std::endl;
    
    //problem
    peter2(ways_four_sided_die2);
    collin2(ways_six_sided_die2);
    
    for (int i = 0; i < 36; i++)
        for (int j = 0; j < i; j++)
            total += ways_six_sided_die2[j] * ways_four_sided_die2[i];
    
    tot_possible_combinations = (pow(4, 9) * pow(6, 6));
    total /= tot_possible_combinations;
    std::cout << "\nProblem: ";
    std::cout << "\nThe probability that Pete beats Collin is: ";
    std::cout << std::setprecision(7) << total << "." << std::endl;
    
    std::cout << "\nPress any key to continue . . . " << std::endl;
    while (!std::cin.get())
        return 0;
}

//These functions just iterate each level and count up the number of ways
//to achieve a sum.
void peter1(int arr[]){
    int sum = 0;
    for (int i = 1; i < 5; i++)
        for (int j = 1; j < 5; j++)
            for (int k = 1; k < 5; k++){
                sum = i + j + k;
                ++arr[sum - 1];
            }
    
}

void collin1(int arr[]){
    int sum = 0;
    for (int i = 1; i < 7; i++)
        for (int j = 1; j < 7; j++){
            sum = i + j;
            ++arr[sum - 1];
        }
}

void peter2(int arr[]){
    int sum = 0;
    for (int i = 1; i < 5; i++)
        for (int j = 1; j < 5; j++)
            for (int k = 1; k < 5; k++)
                for (int l = 1; l < 5; l++)
                    for (int m = 1; m < 5; m++)
                        for (int n = 1; n < 5; n++)
                            for (int o = 1; o < 5; o++)
                                for (int p = 1; p < 5; p++)
                                    for (int q = 1; q < 5; q++){
                                        sum = i + j + k + l + m + n + o + p + q;
                                        ++arr[sum - 1];
                                    }
}

void collin2(int arr[]){
    int sum = 0;
    for (int i = 1; i < 7; i++)
        for (int j = 1; j < 7; j++)
            for (int k = 1; k < 7; k++)
                for (int l = 1; l < 7; l++)
                    for (int m = 1; m < 7; m++)
                        for (int n = 1; n < 7; n++){
                            sum = i + j + k + l + m + n;
                            ++arr[sum - 1];
                        }
    
}

