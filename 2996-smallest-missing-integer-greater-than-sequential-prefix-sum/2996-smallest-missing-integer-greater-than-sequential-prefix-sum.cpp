class Solution {
public:
    int missingInteger(vector<int>& nums) {
        unordered_map <int , int> mp;

        for(int num : nums){
            mp[num]++;
        }

        int presum = nums[0];
        int i = 1;

        while (i < nums.size()){
            if (nums[i] == nums[i-1]+1){
                presum += nums[i];
                i++;
            }else{
                break;
            }
        }

        while (mp.find(presum) != mp.end()){
            presum++;
        }

        return presum;

    }
};