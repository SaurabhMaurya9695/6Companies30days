bool canPair(vector<int> nums, int k) 
    {
        // for divisbility check of k first number shouyld leaves remainder x then second num,ber should lev
        // leaves remainder k - x;
        map<int,int> mp;
        for(auto x : nums)
        {
            mp[x % k]++;
        }
        if(mp[0] % 2 != 0)
        {
            return false;
        }
        for(auto it: mp)
        {
            int rem = it.first;
            int freq = it.second;
            if(rem != 0 && mp[k -rem] != freq)
            {
                return false;
            }
        }
        return true;
    }
    // ******************************** not work for -ives**********************
bool canArrange(vector<int>& arr, int k) {
        
        unordered_map<int,int>mp;
        vector<int>num;
        for(auto val:arr)
        {
            //int rem=abs(val)%k; this will give wrong ans, example (-9%5)
            int rem=(((val%k)+k)%k);
            mp[rem]++;
        }
        
        for(auto p:mp)
        {
            //cout<<p.first<<"->"<<p.second<<" ";
            if(p.first==0)
            {
                if(p.second %2 != 0)
                    return false;
            }
            else
            {
                if(p.second!=mp[k-p.first])
                    return false;
            }
            
        }
        return true;
        
    }
