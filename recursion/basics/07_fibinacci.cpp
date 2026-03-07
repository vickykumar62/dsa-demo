#include<bits//stdc++.h>
using namespace std;
int fibonacci(int n){
    if(n==1) return 0;
    if(n==2) return 1;
    return fibonacci(n-1) + fibonacci(n-2);
}
int main(){
    int n = 10;
    int ans = fibonacci(n); // fibonacci of n = fibonacci(n-1) + fibonacci(n-2)
    cout<<ans<<endl;
    return 0;
}