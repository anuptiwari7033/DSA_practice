class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>v;
        set<vector<int>>sat;
        for(int i=0;i<n-2;i++){
          int j=i+1;
          int k=n-1;
          while(j<k){
            int sum=nums[i]+nums[j]+nums[k];
            if(sum==0){
           sat.insert({nums[i],nums[j],nums[k]});
           j++;
           k--;
            }
            else if(sum>0){
             k--;
            }
            else{
              j++;
            }
          }
        }
        for(auto x:sat){
          v.push_back(x);
        }
        return v;
    }
};