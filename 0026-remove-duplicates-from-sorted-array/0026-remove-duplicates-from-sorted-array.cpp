class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i,k=0;
        int n=nums.size();
        vector<int>b;
        set<int>s;
        for(i=0;i<n;i++){
            s.insert(nums[i]);
        }
        
          for(auto it:s){
            nums[k]=it;
            k++;
            }
          
          return k;
    }
};