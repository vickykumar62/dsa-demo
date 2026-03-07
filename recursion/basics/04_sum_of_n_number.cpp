#include<bits/stdc++.h>
using namespace std;

// parameterized recursion , Answer is passed in parameters.
void solve(int &ans , int n){
    if(n < 1) return;

    ans += n;
    solve(ans , n-1);
}

// functional recursion means return type , Function returns the answer.
int solve2(int n){
    if(n == 1) return 1;

    return n + solve2(n-1);
}

int main(){

    int n = 10;

    // first approach
    int ans = 0;
    solve(ans , n);
    cout << ans << endl;

    // second approach
    int temp = solve2(n);
    cout << temp << endl;

    return 0;
}