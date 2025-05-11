class Solution {
public:
    int maxFreqSum(string s) {
        int n=s.length();
        vector<int> arr(26,0);
        int maxVowel=0;
        int maxConst=0;
        for(int i=0;i<n;i++){
            arr[s[i]-'a']++;
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
                maxVowel=max(maxVowel,arr[s[i]-'a']);
            }else{
                maxConst=max(maxConst,arr[s[i]-'a']);
            }
        }
        return maxConst+maxVowel;

            }
};