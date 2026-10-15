class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();

        for(int i = 0 ; i < n ; i++){
            set<int> distelem;

            for (int j = i ; j < n ; j++){
                distelem.insert(nums[j]);
                sum += (distelem.size() * distelem.size());
            }
        }
        return sum;
    }
};