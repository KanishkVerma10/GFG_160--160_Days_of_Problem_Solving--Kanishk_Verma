// Rotate Array

// Given an array arr[]. Rotate the array to the left (counter-clockwise direction) by d steps, where d is a positive integer. Do the mentioned 
// change in the array in place.

// Note: Consider the array as circular.

// Examples :

// Input: arr[] = [1, 2, 3, 4, 5], d = 2
// Output: [3, 4, 5, 1, 2]
// Explanation: when rotated by 2 elements, it becomes 3 4 5 1 2.

class Solution{
public:   
    void reverse(vector<int> &arr, int i, int j){
        while(i < j){
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
  
// Function to rotate an array by d elements in counter-clockwise direction.
void rotateArr(vector<int>& arr, int d) {
        int n = arr.size();
        if(n == 0) return;
        d = d % n;
        
        if(d == 0) return;
        
        //reverse the 1st d elements
        reverse(arr, 0, d-1);
        
        //reverse the last (n-d) elements
        reverse(arr, d, n-1);
        
        //reverse all the elements of the array
        reverse(arr, 0, n-1);
    }
};
