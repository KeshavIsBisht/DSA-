class Solution {
public:
    int mySqrt(int x) {
        long long low=1;
        long long high=x;
        long long ans=0;
        
        while (low<=high){
            long long mid=(low+high)/2;

            if (mid*mid > x){
                high=mid-1;
            }
            else if (mid*mid < x){
                low=mid+1;
                ans=mid;
            }
            else if (mid*mid==x){
                return mid;
            }

        }
        return ans;
    }
};