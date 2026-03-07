#include<bits/stdc++.h>
using namespace std;

// Recursive Binary Search Function
int solve(int start , int end , int num , vector<int>&arr){

    // Base Case:
    // If start crosses end, the element is not present
    if(start > end) return -1;

    // Find middle index
    int mid = (start + end) / 2;

    // If the middle element is the target
    if(num == arr[mid]) 
        return mid;

    // If target is smaller than middle element
    // Search in the left half
    if(num < arr[mid]){
        return solve(start , mid-1 , num , arr);
    }

    // Otherwise search in the right half
    return solve(mid+1 , end , num , arr);
}

int main(){

    // Sorted array (Binary Search works only on sorted data)
    vector<int> arr = {1,3,4,5,8,10,18,19,23,33};

    int num = 25;
    int n = arr.size();

    // Call recursive binary search
    int index = solve(0 , n-1 , num , arr);

    // Check result
    if(index != -1)
        cout << "present at index -> " << index << endl;
    else
        cout << "not present ";

    return 0;
}