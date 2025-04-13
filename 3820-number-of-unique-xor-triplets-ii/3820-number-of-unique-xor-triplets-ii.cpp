class Solution {
public:
    int uniqueXorTriplets(vector<int>& n) {
        unordered_set<int>v;
        for(int i=0;i<n.size();i++){
            for(int j=0;j<n.size();j++){
                v.insert(n[i]^n[j]);
            }
        }
        unordered_set<int>st;
        for(int i=0;i<n.size();i++){
            for(auto j:v){
                st.insert(n[i]^j);
            }
        }
        return st.size();
    }
};