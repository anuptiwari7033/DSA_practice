class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int i=0;
        int k=INT_MIN;
        int j=n-1;
        while(i<j){
            int p=j-i;
           k=max(min(height[i],height[j])*p,k);
           if(height[i]>height[j]){
            j--;
           }
          else if(height[i]<=height[j]){
            i++;
           }
        }
        return k;
    }
};