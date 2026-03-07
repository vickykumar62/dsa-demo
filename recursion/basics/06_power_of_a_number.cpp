#include<bits/stdc++.h>
using namespace std;

// function to calculate base^power using recursion
int solve(int base , int power){

    // Base Case:
    // Any number raised to power 0 is always 1
    // Example: 2^0 = 1
    if(power == 0) return 1;

    // Recursive Step:
    // We know:
    // base^power = base * base^(power-1)
    // So we reduce the problem size by decreasing power

    return base * solve(base , power-1);
}

int main(){

    int base = 2;
    int power = 7;

    // function call
    int ans = solve(base , power);

    // printing result
    cout << ans << endl;

    return 0;
}