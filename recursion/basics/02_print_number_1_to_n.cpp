#include<bits/stdc++.h>
using namespace std;

void solve(int idx , int n){
    if(idx>n) return ;
    
    cout<<idx<<endl;
    solve(idx+1,n);
}
int main(){

    int n = 10;
    solve(1,n);
    return 0;
}