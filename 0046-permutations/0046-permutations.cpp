class Solution {
public:
void solve(vector<vector<int>>&ans,vector<int>&temp,vector<int>& nums,int ind,vector<bool>&v){
    if(temp.size()==nums.size()){
        ans.push_back(temp);
        return;
    }
   // temp.push_back(nums[ind]);
    for(int i=0;i<nums.size();i++){
        // if(ind!=i){
        //     temp.push_back(nums[i]);
        // }
        if(v[i])continue;
        v[i]=true;
         temp.push_back(nums[i]);
        solve(ans,temp,nums,i+1,v);
        temp.pop_back();
        v[i]=false;
    }

}
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans;
        vector<int>temp;
        int ind=0;
        vector<bool>v(nums.size(),false);
        solve(ans,temp,nums,ind,v);
        return ans;
    }
};