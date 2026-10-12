class Solution {
public:
    int romanToInt(string s) {
        int n=s.size();
        int sum=0;
       unordered_map<char,int>mp;
       mp.insert({'I',1});
       mp.insert({'V',5});
       mp.insert({'L',50});
       mp.insert({'X',10});
       mp.insert({'C',100});
       mp.insert({'D',500});
       mp.insert({'M',1000});
       for(int i=0;i<n;i++){
        if(i==n-1){
            sum+=mp[s[i]];
        }
        else if(mp[s[i]]>=mp[s[i+1]]){
            sum+=mp[s[i]];
        }
        else{
            sum-=mp[s[i]];
        }
       }
       return sum;
    }
};