class Solution {
public:

    vector <int> Pse(vector<int>& arr){
        
        int n=arr.size();
        vector<int>pse(n);
        stack<int>st;

        for(int i=0;i<n;i++){
           
            while (!st.empty()&& arr[st.top()]>arr[i]){
                    st.pop();
            }
            pse[i]=st.empty()?-1:st.top();
            st.push(i);
        } 
        return pse ;
    }

    vector <int> Nse(vector<int>& arr){
    
        int n=arr.size();
        vector<int>nsee(n);
        stack<int>st;

        for(int i=n-1;i>=0;i--){
            while (!st.empty()&& arr[st.top()]>=arr[i]){
                    st.pop();
            }
            nsee[i]=st.empty()?n:st.top();
            st.push(i);
        }
    return nsee;
    } 


    int sumSubarrayMins(vector<int>& arr) {
        
        vector<int>NSE=Nse(arr);
        vector<int>PSE=Pse(arr);
        int n=arr.size();

        int total=0;
        int mod=(int)(1000000007);

        for (int i=0;i<n;i++){
            int left=i-PSE[i];
            int right=NSE[i]-i;

            total=(total+(left*right*1LL*arr[i])%mod)%mod;
        }

       return total ;
    }
};