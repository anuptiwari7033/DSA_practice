class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int left=0;
        int right;
        set<int>sat;
        int ans=0;
        for(right=0;right<n;right++){
          if(sat.count(s[right])==0){
            sat.insert(s[right]);
            ans=max(ans,right-left+1);
          }
          else{
             while(sat.count(s[right])){
              sat.erase(s[left]);
              left++;
             }
             sat.insert(s[right]);
              //ans=max(ans,right-left+1);
          }
        }
        return ans;
    }
};