class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int , int> freq;
        int n = nums.size();

        if (k == n) 
            return (*max_element(nums.begin() , nums.end()));

        for (int i : nums){
            freq[i]++;
        }

        int res = -1;

        if (k == 1 && freq.size() > 1){
            for (auto it : freq){
                if (it.second == 1){
                    res = max(res , it.first);
                }
            }
            return res;
        }

        
        if (freq[nums[0]] == 1){
            res = max(res , nums[0]);
        }

        if (freq[nums[n-1]] == 1){
            res = max(res , nums[n-1]);
        }

        return res;


    }
};