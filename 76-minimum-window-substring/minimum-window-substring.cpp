class Solution {
public:
    string minWindow(string s, string t) {
        int l=0,r=0;
        int n=s.size();
        int m=t.size();
        int minlen=INT_MAX;
        int count=0;
        int sindex=-1;
        vector<int>hash(256,0);
        
        for (int i=0;i<m;i++){
            hash[t[i]]++;
        }

        while (r<n){
            
            if(hash[s[r]]>0) count++;
             hash[s[r]]--;

             while (count==m){

                if (r-l+1 <minlen) {
                    minlen=r-l+1;
                    sindex=l;
                }
                
                hash[s[l]]++;

                if (hash[s[l]]>0)
                 count--;
                l++;
             }
             r++;
        }
        return sindex==-1 ? "" : s.substr(sindex,minlen);
    }
};