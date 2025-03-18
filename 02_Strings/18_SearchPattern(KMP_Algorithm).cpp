// Search Pattern (KMP-Algorithm)

// Given two strings, one is a text string txt and the other is a pattern string pat. The task is to print the indexes of all the occurrences of the pattern string in the text string. Use 0-based indexing while returning the indices. 
// Note: Return an empty list in case of no occurrences of pattern.

// Examples :

// Input: txt = "abcab", pat = "ab"
// Output: [0, 3]
// Explanation: The string "ab" occurs twice in txt, one starts at index 0 and the other at index 3. 
// Input: txt = "abesdu", pat = "edu"
// Output: []
// Explanation: There's no substring "edu" present in txt.

class Solution {
  public:
    void constructLPS(string &pat, vector<int> &lps){
        int len = 0;
        
        lps[0] = 0;
        
        int i = 1;
        
        while(i < pat.length()){
            // If character matches, increase the size of lps
            if(pat[i] == pat[len]){
                len++;
                lps[i] = len;
                i++;
            }
            // if there is mismatch
            else{
                if(len != 0){
                    len = lps[len-1];
                }
                else{ // if len = 0
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }
  
    vector<int> search(string& pat, string& txt) {
        int n = txt.length();
        int m = pat.length();
        
        vector<int> lps(m);
        vector<int> res;
        
        constructLPS(pat, lps);
        
        int i = 0;
        int j = 0;
        
        while(i < n){
            //if character matches, move voth pointers forward
            if(txt[i] == pat[j]){
                i++;
                j++;
                
                if(j == m){
                    res.push_back(i-j);
                    
                    j = lps[j-1];
                }
            }
            // if there is a mismatch
            else{
                if(j != 0){
                    j = lps[j-1];
                }
                else{
                    i++;
                }
            }
        }
        
        return res;
    }
};
