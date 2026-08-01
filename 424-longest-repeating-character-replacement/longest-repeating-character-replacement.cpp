class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0,r=0;
        int maxlen=0;
        int maxfrq=0;
        vector<int>hash(26,0);

        while (r<s.size()){

            hash[s[r]-'A']++;
            maxfrq=max(maxfrq, hash[s[r]-'A']);

            if ((r-l+1) - maxfrq > k ){
                hash[s[l]-'A']--;
                l++;
            }

            else{
                 maxlen=max(maxlen, r-l+1);
            }
            r++;
        }
        return maxlen;
    }
};