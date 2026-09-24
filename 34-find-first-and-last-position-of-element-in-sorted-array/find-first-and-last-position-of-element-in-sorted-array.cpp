class Solution {
public:

    int firstoccurence(vector<int>& nums, int target){
        int n=nums.size();
        int low=0;
        int high=n-1;
        int ans=-1;

        while (low<=high){

            int mid=(low+high)/2;

            if (nums[mid]>target){
                high=mid-1;
            }
            else if (nums[mid]<target){
                low=mid+1;
            }

            else if (nums[mid]==target){
                ans=mid;
                high=mid-1;

            }
        }
        return ans;
    }

     int lastoccurence(vector<int>& nums, int target){
        int n=nums.size();
        int low=0;
        int high=n-1;
        int ans=-1;

        while (low<=high){

            int mid=(low+high)/2;

            if (nums[mid]>target){
                high=mid-1;
            }
            else if (nums[mid]<target){
                low=mid+1;
            }

            else if (nums[mid]==target){
                ans=mid;
                low=mid+1;
            }
        }
        return ans;
    }


    vector<int> searchRange(vector<int>& nums, int target) {
        
        int first=firstoccurence(nums,target);
         int last=lastoccurence(nums,target);

         return {first,last};
    }
};