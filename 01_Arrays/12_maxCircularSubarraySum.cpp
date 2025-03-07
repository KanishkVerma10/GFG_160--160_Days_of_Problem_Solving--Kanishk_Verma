// Max Circular Subarray Sum

// Given an array of integers arr[] in a circular fashion. Find the maximum subarray sum that we can get if we assume the array to be circular.

// Examples:

// Input: arr[] = [8, -8, 9, -9, 10, -11, 12]
// Output: 22
// Explanation: Starting from the last element of the array, i.e, 12, and moving in a circular fashion, we have max subarray as 12, 8, -8, 9, -9, 10, 
//   which gives maximum sum as 22.

int circularSubarraySum(vector<int> &arr) {
        int totalSum = 0;
        int currMaxSum = 0, currMinSum = 0;
        int maxSum = arr[0], minSum = arr[0];
        
        for(int i=0; i<arr.size(); i++){
            currMaxSum = max(currMaxSum + arr[i], arr[i]);
            maxSum = max(maxSum, currMaxSum);
            
            currMinSum = min(currMinSum + arr[i], arr[i]);
            minSum = min(minSum, currMinSum);
            
            totalSum = totalSum + arr[i];
        }
        
        int normalSum = maxSum;
        
        int circularSum = totalSum - minSum;
        
        if(minSum == totalSum){
            return normalSum;
        }
        
        return max(normalSum, circularSum);
    }
