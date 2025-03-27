class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    int maxlen=0,l=0,r=0;
    vector<int> map(256,-1);
    int n=s.size();
    while(r<n){
        if(map[s[r]]!=-1) { //in map if char at ind r seen before
        if(map[s[r]]>=l){
            // If it has been seen and its last recorded index (map[s[r]]) is greater than or equal to l, it means the character is within the current substring defined by the window [l, r]. Therefore, we need to move the left pointer l to the right of the last occurrence of the character to avoid repeating it.
        l=map[s[r]]+1; //in range
        }
        }
int len=r-l+1;
maxlen=max(maxlen,len);
map[s[r]]=r; //This updates the last seen index of the character s[r] to the current index r.
r++;
    }
    return maxlen;
    }
};