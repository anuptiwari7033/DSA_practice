class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
           vector<vector<int>>v;
        set<vector<int>>sat;
        for(int i=0;i<n-3;i++){
          // int t=target-nums[i];
           for(int b=i+1;b<n-2;b++){
            int c=b+1;
            int d=n-1;
            while(c<d){
            long sum=(long)nums[i]+nums[b]+nums[c]+nums[d];
            if(sum==target){
           sat.insert({nums[i],nums[b],nums[c],nums[d]});
           c++;
           d--;
            }
            else if(sum>target){
             d--;
            }
            else{
              c++;
            }
          }
           }
        }
         for(auto x:sat){
          v.push_back(x);
        }
        return v;
    }
};