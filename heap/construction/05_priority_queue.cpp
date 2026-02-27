#include<bits/stdc++.h>
using namespace std;
int main(){
    priority_queue<int>pq1; // max heap
    pq1.push(5); // 5
    pq1.push(3); // 5 3
    pq1.push(4); // 5 4 3
    pq1.push(8); // 8 5 4 3

    pq1.top(); // 8
    pq1.pop(); // 5 4 3

    priority_queue<int , vector<int> , greater<int>>pq2; // min heap , just opposite of the max heap
    return 0;
}