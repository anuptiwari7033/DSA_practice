class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
         int n = nums.size();
        vector<vector<int>> v;
        // int i=0;
        // int j=n-1;
        sort(nums.begin(), nums.end());
        for (int k = 0; k < n - 2; k++) {
            int i = k + 1;
            int j = n - 1;
            while (i < j) {
            int sum = nums[i] + nums[k] + nums[j];
                if (sum == 0) {
                    v.push_back({nums[k], nums[i], nums[j]});
                    i++;
                    j--;
                    while (i < j  && nums[i - 1] == nums[i])
                        i++;
                    while (i < j  && nums[j + 1] == nums[j])
                        j--;
                } else if (sum > 0) {
                    j--;
                } else {
                    i++;
                }
            }
            while (k < n - 2 && nums[k] == nums[k + 1])
                k++;
        }
        return v;
    }
};