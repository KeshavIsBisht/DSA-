class Solution {
public:
    int numberOfSubstrings(string s) {
       vector<int>lastseen={-1,-1,-1};
        int count=0;

      for (int i=0;i<s.size();i++){
        lastseen[s[i]-'a']=i;
      

      if (lastseen[0]!=-1&&lastseen[1]!=-1&&lastseen[2]!=-1){
        count+=min({lastseen[0],lastseen[1],lastseen[2]})+1;
      }
      }
      return count;
    }
};