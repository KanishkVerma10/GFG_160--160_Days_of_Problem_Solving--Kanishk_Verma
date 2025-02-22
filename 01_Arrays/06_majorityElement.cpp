// Majority Element II

// You are given an array of integer arr[] where each number represents a vote to a candidate. Return the candidates that have votes greater than one-third of the total votes, If there's not a majority vote, return an empty array. 

// Note: The answer should be returned in an increasing format.

// Examples:

// Input: arr[] = [2, 1, 5, 5, 5, 5, 6, 6, 6, 6, 6]
// Output: [5, 6]
// Explanation: 5 and 6 occur more n/3 times.

vector<int> findMajority(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans;
        
        int ele1 = -1, ele2 = -1;
        int cnt1 = 0, cnt2 = 0;
        
        for(int i=0; i<n; i++){
            //if an element is equal to any candidate, update the candidate's count
            if(arr[i] == ele1 || arr[i] == ele2){
                if(arr[i] == ele1) cnt1++;
                if(arr[i] == ele2) cnt2++;
            }
            
            //if cnt of a candidate reaches 0, replace the candidate with curr ele and increase cnt
            else if(cnt1 == 0 || cnt2 == 0){
                if(cnt1 == 0){
                    ele1 = arr[i];
                    cnt1++;
                } 
                else if (cnt2 == 0 && arr[i] != ele1){
                    ele2 = arr[i];
                    cnt2++;
                }
            }
            
            //if neither candidate matches and both counts are non zero, decrement the counts
            if((arr[i] != ele1 && arr[i] != ele2) && (cnt1 > 0 && cnt2 > 0)){
                cnt1--;
                cnt2--;
            }
        }
        
        //now we check if the chosen candidates appear more than n/3 time, if yes then push them in ans
        int freq1 = 0, freq2 = 0;
        for(int i=0; i<n; i++){
            if(arr[i] == ele1) freq1++;
            if(arr[i] == ele2) freq2++;
        }
        
        if(freq1 > (n/3)) ans.push_back(ele1);
        if(freq2 > (n/3)) ans.push_back(ele2);
        
        if(ans.size() == 2 && ans[0] > ans[1]){
            swap(ans[0], ans[1]);
        }
        
        return ans;
}
