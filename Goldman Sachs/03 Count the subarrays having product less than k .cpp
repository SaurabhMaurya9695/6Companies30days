class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& nums, int n, long long k) {
        if (k <= 1) return 0;
        long long  prod = 1, ans = 0, left = 0;
        for (int right = 0; right < nums.size(); right++) {
            prod *= nums[right];
            while (prod >= k) prod /= nums[left++]; // divide all the nums element until prod.
            ans += right - left + 1;
        }
        return ans;
    }
};

/// This question is also done using prefix suma with binary search .