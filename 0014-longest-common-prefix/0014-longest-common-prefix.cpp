class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        int m=strs[0].size();
        if(n==1)
         return strs[0];
         bool t=false;
        for(int i=0;i<m;i++){
          for(int j=0;j<n;j++){
            if(strs[0][i]!=strs[j][i]){
              t=true;
              string ans=strs[0].substr(0,i);
              return ans;
            }
          }
        }
        if(!t)
         return strs[0];
        return "";

    }
};