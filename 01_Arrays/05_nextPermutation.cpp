// Next Permutation

// Given an array of integers arr[] representing a permutation, implement the next permutation that rearranges the numbers into the lexicographically next greater permutation. If no such permutation exists, rearrange the numbers into the lowest possible order (i.e., sorted in ascending order). 

// Note - A permutation of an array of integers refers to a specific arrangement of its elements in a sequence or linear order.

// Examples:

// Input: arr = [2, 4, 1, 7, 5, 0]
// Output: [2, 4, 5, 0, 1, 7]
// Explanation: The next permutation of the given array is {2, 4, 5, 0, 1, 7}.
// Input: arr = [3, 2, 1]
// Output: [1, 2, 3]
// Explanation: As arr[] is the last permutation, the next permutation is the lowest one.

void reverse(vector<int> &arr, int s, int e){
        while(s < e){
            swap(arr[s], arr[e]);
            s++;
            e--;
        }
    }
 
    void nextPermutation(vector<int>& arr) {
        int n = arr.size();
        
        int i = n-2;
        int pivot = -1;
        
        while(i >= 0 && arr[i] >= arr[i+1]){
            i--;
        }
        
        pivot = i;
        
        //if i = -1 after backward traversal, reverse the whole array
        if(i == -1){
            reverse(arr, 0, n-1);
        }
        else{
            //search and swap element just greater than pivot in right side of pivot
            for(int j=n-1; j>pivot; j--){
                if(arr[j] > arr[pivot]){
                    swap(arr[j], arr[pivot]);
                    break;
                }
            }
        
            //reverse the array after pivot
            reverse(arr, pivot+1, n-1);
        }
    }
