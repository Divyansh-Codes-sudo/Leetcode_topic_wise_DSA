class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int maxi = 0;
        unordered_set<int> mp;
        for (int i: nums){
            mp.insert(i);
            maxi = max(maxi , i);
        }

        int i = k;

        while (i <= maxi+k){
            if (i%k == 0 && mp.find(i)==mp.end()) return i;

            i += k;
        }

        return 0;
    }

};