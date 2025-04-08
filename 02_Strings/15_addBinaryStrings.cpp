// Add Binary Strings

// Given two binary strings s1 and s2 consisting of only 0s and 1s. Find the resultant string after adding the two Binary Strings.
// Note: The input strings may contain leading zeros but the output string should not have any leading zeros.

// Input: s1 = "1101", s2 = "111"
// Output: 10100
// Explanation:
//  1101
// + 111
// 10100

string trimLeadingZeros(const string &s){
    size_t firstOne = s.find('1');
    return (firstOne == string::npos) ? "0" : s.substr(firstOne);
}

string addBinary(string& s1, string& s2){
        
    s1 = trimLeadingZeros(s1);
    s2 = trimLeadingZeros(s2);
        
        
        
    if(s1.size() < s2.size()){
        swap(s2, s1)
    }
        
    int n = s1.size();
    int m = s2.size();
    int j = m-1;
    int carry = 0;
        
    for(int i = n-1; i>=0; i--){
            
        int bit1 = s1[i] - '0';
        int sum = bit1 + carry;
            
        if(j >= 0){
            int bit2 = s2[j] - '0';
            sum += bit2;
            j--;
        }
            
        int bit = sum % 2;
        carry = sum / 2;
            
        s1[i] = (char)(bit + '0');
    }
        
    if(carry > 0){
        s1 = '1' + s1;
    }
        
    return s1;
}
