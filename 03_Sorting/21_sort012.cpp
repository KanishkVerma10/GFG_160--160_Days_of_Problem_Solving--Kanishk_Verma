// Sort 0s, 1s and 2s

// Given an array arr[] containing only 0s, 1s, and 2s. Sort the array in ascending order.

// You need to solve this problem without utilizing the built-in sort function.

// Examples:

// Input: arr[] = [0, 1, 2, 0, 1, 2]
// Output: [0, 0, 1, 1, 2, 2]
// Explanation: 0s 1s and 2s are segregated into ascending order.

void sortColors(vector<int>& nums) {
    int n = nums.size();
    int i = 0;
    int lt = 0, gt = n-1;

    while(i <= gt){
        //if number is 0(less than 1), put it in the starting of array
        if(nums[i] < 1)
            swap(nums[i], nums[lt]);
            i++;
            lt++;
        //if number is 2(greater than 1), put it in the last of array
        else if(nums[i] > 1)
            swap(nums[i], nums[gt]);
            gt--;
        else
            i++;
    }
}
