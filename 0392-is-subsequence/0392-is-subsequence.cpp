class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0,j=0;
        while(i<s.size() && j<t.size()){
            if(s[i]==t[j]){
                i++; //if equal move to next char in s
            }
            j++; // then move for next element in t
        }
        return i==s.size(); //all char in s have been matched if i== len of s then s subseq of t
    }
};