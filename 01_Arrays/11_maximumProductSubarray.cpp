// Maximum Product Subarray

// Given an array arr[] that contains positive and negative integers (may contain 0 as well). Find the maximum product that we can get in a subarray of arr[].

// Note: It is guaranteed that the output fits in a 32-bit integer.

// Examples

// Input: arr[] = [-2, 6, -3, -10, 0, 2]
// Output: 180
// Explanation: The subarray with maximum product is {6, -3, -10} with product = 6 * (-3) * (-10) = 180.

int maxProduct(vector<int> &arr) {
        int n = arr.size();
        
        int currMin = arr[0];
        int currMax = arr[0];
        int maxPro = arr[0];
        
        for(int i=1; i<n; i++){
            int temp = max({arr[i], currMax * arr[i], currMin * arr[i]});
            
            currMin = min({arr[i], currMax * arr[i], currMin * arr[i]});
            
            currMax = temp;
            
            maxPro = max(maxPro, currMax);
}
        
        return maxPro;
    }
