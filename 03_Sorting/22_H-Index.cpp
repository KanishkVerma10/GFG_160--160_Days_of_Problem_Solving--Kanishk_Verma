// Find H-Index

// Given an integer array citations[], where citations[i] is the number of citations a researcher received for the ith paper. The task is to find the H-index.

// H-Index is the largest value such that the researcher has at least H papers that have been cited at least H times.

// Examples:

// Input: citations[] = [3, 0, 5, 3, 0]
// Output: 3
// Explanation: There are at least 3 papers (3, 5, 3) with at least 3 citations.


// [Expected Approach] Using Counting Sort - O(n) Time and O(n) Space
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();

        vector<int> freq(n+1, 0);

        for(int i=0; i<n; i++){
            if(citations[i] >= n)
                freq[n]++;
            else
                freq[citations[i]]++;
        }

        int idx = n;
    
        // Variable to keep track of the count of papers
        // having at least idx citations
        int s = freq[n]; 
        while (s < idx) {
            idx--;
            s += freq[idx];
        }
    
        // Return the largest index for which the count of 
        // papers with at least idx citations becomes >= idx
        return idx;
    }
};


// [Naive Approach] Using Comparison-based Sorting - O(n*logn) Time and O(1) Space
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        // sorting the citations array in desccending order
        sort(citations.begin(), citations.end(), greater<int>());
        
        int H = 0;
        
        for(int i=0; i<n; i++){
            if(citations[i] > i) 
                H++;
            else
                break;
        }
        
        return H;
    }
};
