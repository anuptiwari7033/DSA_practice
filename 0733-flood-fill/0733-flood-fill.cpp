class Solution {
public:
vector<vector<int>>v={{-1,0},{1,0},{0,1},{0,-1}};
void solve(vector<vector<int>>& image, int i, int j, int color,int n,int m,int newcolor){
  if(i<0||i>=n||j<0||j>=m){
    return;
  }
  if(image[i][j]!=newcolor){
    return;
  }
  image[i][j]=color;
  for(auto x:v){
    solve(image,i+x[0],j+x[1],color,n,m,newcolor);
  }

}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
      //  image[sr][sc]=-1;
      if(image[sr][sc]==color){
        return image;
      }
        solve(image,sr,sc,color,n,m,image[sr][sc]);
        return image;
    }
};