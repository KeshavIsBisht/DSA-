class Solution {
public:

    vector<int> PSE(vector<int>& arr){
        
        int n=arr.size();
        stack <int>st;
        vector<int>pse(n);

        for (int i=0;i<n;i++){
            while (!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            pse[i]=st.empty()?-1:st.top();
            st.push(i);
        }
    return pse;
    }

    vector<int> NSE(vector<int>& arr){
        
        int n=arr.size();
        stack <int>st;
        vector<int>nse(n);

        for (int i=n-1;i>=0;i--){
            while (!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            nse[i]=st.empty()?n:st.top();
            st.push(i);
        }
    return nse;
    }

     int largestRectangleArea(vector<int>& heights) {

     int n= heights.size();
     vector<int>Pse=PSE(heights); 
     vector<int>Nse=NSE(heights);  
     int maxArea=0;

    for (int i=0;i<n;i++){

        int width=Nse[i]-Pse[i]-1;
        int area=heights[i]*width;

        maxArea=max(area,maxArea);
    }
    return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {

        int n=matrix.size();
        int m=matrix[0].size();

        vector<int>heights(m,0);

        int area=0;
        int maxArea=0;

        for (int i=0;i<n;i++){
            
            for (int j=0;j<m;j++){
                if (matrix[i][j]=='1'){
                    heights[j]++;
                }
                else{
                    heights[j]=0;
                }
            }

            area=largestRectangleArea(heights);

            maxArea=max(maxArea,area);

        }
        return maxArea;
        
    }
};