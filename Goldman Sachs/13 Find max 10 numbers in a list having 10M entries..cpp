class Solution {
public:
    int findKthLargest(vector<int>& arr, int k) {
        int n = arr.size();
        priority_queue<int> maxheap;
    for(int i =0;i < n; i++)
    { 
        maxheap.push(arr[i]);
    }
    vector<int> ans;
    while(k--)
    {
        int x = maxheap.top();
        maxheap.pop();
        ans.push_back(x);
    }
    // return ans ;
        return ans[ans.size() - 1];
        
    }
};