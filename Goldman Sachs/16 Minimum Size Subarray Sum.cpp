class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int n = nums.size();
        
        int ans = INT_MAX;
        int left = 0, right = 0;
        int sum = 0;        
        while(right < n){
            
            // increasing the window to get sum of subarray greater than target
            sum += nums[right];            
            
            // shortening the window to get minimum subarray which exceeds the target
            while(sum >= target){
                ans = min(ans, right - left + 1);
                sum -= nums[left];
                left++;
            }
            
            right++;
        }
        
        // if no subarray's sum is greater than the target, we will return 0
        if(ans == INT_MAX){
            return 0;            
        }
        else{
            return ans;
        }        
    }
};