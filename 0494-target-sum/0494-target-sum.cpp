class Solution {
   int solve(vector<int>& nums, int target,int sum,int i,int n){
        if(i>=n){
            if(sum==target){
                return 1;
            }
            else{
                return 0;
            }
        }
        int a=solve(nums,target,sum-nums[i],i+1,n);
        int b=solve(nums,target,sum+nums[i],i+1,n);
        return a+b;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // int findTargetSumWays(vector<int>& nums, int target) {
    // int count=0;
     int n=nums.size();
     int sum=0;
    //  vector<int>v;
    //  solve(nums,target,n,v,sum,0,count);
    //     return count;
     return solve(nums,target,sum,0,n);
    }
};