class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
       vector<vector<int>>list(numCourses);
       vector<int>result;
        vector<int>inorder(numCourses,0);
       for(auto x:prerequisites){
        list[x[1]].push_back(x[0]);
           inorder[x[0]]++;
      } 
      queue<int>q;
        for(int i=0;i<inorder.size();i++){
          if(inorder[i]==0){
            q.push(i);
          }
        }
        int c=0;
     while(!q.empty()){
        int node=q.front();
        q.pop();
          c++;
          result.push_back(node);

          for(auto x:list[node]){
            inorder[x]--;
            if(inorder[x]==0){
                q.push(x);
            }
          }
     }
     if(c==numCourses){
        return result;
     }
     return {};
    }
};