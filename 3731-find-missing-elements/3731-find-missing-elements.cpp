class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        // Store the frequency of each number
        unordered_map<int, int> mp;

        int maxi = 0;
        int mini = 200;

        vector<int> ans;

        // Find the minimum and maximum element
        // while storing all numbers in the hash map
        for (int i : nums) {
            mp[i]++;
            maxi = max(maxi, i);
            mini = min(mini, i);
        }

        // Check every number in the range [mini, maxi]
        // If a number is not present in the map,
        // it is a missing element
        for (int i = mini; i <= maxi; i++) {
            if (mp.find(i) == mp.end())
                ans.push_back(i);
        }

        return ans;
    }
};