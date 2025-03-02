// Anagram

// Given two strings s1 and s2 consisting of lowercase characters. The task is to check whether two given strings are an anagram of each other or not. 
// An anagram of a string is another string that contains the same characters, only the order of characters can be different. For example, "act" and "tac" 
// are an anagram of each other. Strings s1 and s2 can only contain lowercase alphabets.

// Note: You can assume both the strings s1 & s2 are non-empty.

// Examples :

// Input: s1 = "geeks", s2 = "kseeg"
// Output: true
// Explanation: Both the string have same characters with same frequency. So, they are anagrams.

bool areAnagrams(string& s1, string& s2) {
    //making a frequency array
    vector<int> freq1(26, 0);
    vector<int> freq2(26, 0);
        
    int n = s1.size();
    int m = s2.size();
        
    //traversing s1
    for(int i=0; i<n; i++){
        char ch = s1[i];
        int index = ch - 'a';
            
        //update the freq array
        freq1[index]++;
    }
        
    //traversing s2
    for(int i=0; i<m; i++){
        char ch = s2[i];
        int index = ch - 'a';
            
        //update the freq array
        freq2[index]++;
    }
        
    if(freq1 == freq2)
        return true;
    else
        return false;
}
