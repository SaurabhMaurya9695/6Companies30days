class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& str) {
        map<string , vector<string>> mp;
        for(int i =0; i< str.size() ; i++ )
        {
            string s = str[i];
            sort(s.begin() , s.end());
            mp[s].push_back(str[i]); // stores with all pair and value
        }
        // after storing iterate over map;
        vector<vector<string>> ans(mp.size());
        int idx = 0;
        for(auto x : mp)
        {
            auto v = x.second;
            for(int i =0; i< v.size() ;i++)
            {
                ans[idx].push_back(v[i]);
                
            }
            idx++;
        }
        return ans ;
    }
};