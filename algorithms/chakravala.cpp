//Implementation of chakravala's method using GNU's multi precision library
//Compile with g++ -o chakravala chakravala.cpp -lgmp -lgmpxx
#include <iostream>
#include <gmpxx.h>
#include <cmath>

using namespace std;

mpz_class chakravala(int n) {

    mpz_class curr_x,curr_p,curr_y,opti_p,curr_k;
    mpz_class next_p_low,next_p_high,next_p,next_k,next_x,next_y;
    mpz_class diff,curr_k_abs;
    int sq = sqrt(n);
    curr_p = curr_x = opti_p = sq;
    curr_k = (curr_p *curr_p) - n;

    curr_y = 1;

    if(sq*sq == n)
        return 0;

    if(curr_k == 1) {
        return curr_x;
    }

    while(1){

    curr_k_abs = abs(curr_k);
    diff = (curr_p+opti_p)%curr_k_abs;
    next_p_low = opti_p - diff;
    next_p_high = next_p_low + curr_k_abs;

    if(next_p_low<1)
        next_p = next_p_high;
    else next_p = (abs( (next_p_low*next_p_low) - n) < abs( (next_p_high*next_p_high) - n))?next_p_low:next_p_high;

    next_k = ((next_p*next_p) - n)/curr_k;
    next_x = ((next_p*curr_x) + (n*curr_y))/curr_k_abs;
    next_y = ((next_p*curr_y) + curr_x)/curr_k_abs;

    
    //Replace with -1 to solve negative Pell's equation
    if(next_k==1) {
        return next_x;
    }

    curr_k = next_k;
    curr_p = next_p;
    curr_x = next_x;
    curr_y = next_y;

    }

}

int main()
{
    mpz_class high = 0,high_n = 0;
    mpz_class curr;

    for(int i=2;i<100;++i) {
        cout<<chakravala(i)<<" "<<i<<endl;
    }

    return 0;
}
