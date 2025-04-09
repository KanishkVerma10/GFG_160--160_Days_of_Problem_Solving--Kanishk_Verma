// Ways to Reach the n'th Stair

// You are climbing a staircase. It takes n steps to reach the top.

// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

 

// Example 1:

// Input: n = 2
// Output: 2
// Explanation: There are two ways to climb to the top.
// 1. 1 step + 1 step
// 2. 2 steps
// Example 2:

// Input: n = 3
// Output: 3
// Explanation: There are three ways to climb to the top.
// 1. 1 step + 1 step + 1 step
// 2. 1 step + 2 steps
// 3. 2 steps + 1 step

class Solution {
    public:
        // DP - just like the fibonacci question, using memoization
        int solve(int n, vector<int> &dp){
            if(n <= 1)
                return 1;
    
            if(dp[n] != -1){
                return dp[n];
            }
    
            // store the count of each n in the dp vector to use in the future
            dp[n] = solve(n-1, dp) + solve(n-2, dp);
            return dp[n];
        }
    
        int climbStairs(int n) {
            // make a dp array of size n+1 and initialize each element by -1
            vector<int> dp(n+1, -1);
            return solve(n, dp);
        }
    };