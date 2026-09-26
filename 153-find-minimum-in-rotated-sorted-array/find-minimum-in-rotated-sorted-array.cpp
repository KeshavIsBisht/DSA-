class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int mini=INT_MAX;

        int low=0;
        int high=n-1;

        while (low<=high){

            int mid=low+(high-low)/2;

            if (nums[low]<=nums[high]){
                mini=min(mini,nums[low]);
                break;
            }


            if (nums[low]<=nums[mid]) {
                mini=min(mini,nums[low]);
                low=mid+1;
            }
            else{
                high=mid-1;
                mini=min(mini,nums[mid]);
            }
        }
        return mini;
    }
};