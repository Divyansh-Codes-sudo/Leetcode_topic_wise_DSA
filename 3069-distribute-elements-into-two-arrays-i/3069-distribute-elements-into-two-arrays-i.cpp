class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {

        int n = nums.size();

        if (n <= 2) {
            return nums;
        }


        vector<int> arr1;
        vector<int> arr2;

        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);

        int ind = 2;

        while (ind < n) {
            if (arr1.back() > arr2.back()) {
                arr1.push_back(nums[ind]);
                ind++;
            } else {
                arr2.push_back(nums[ind]);
                ind++;
            }
        }

        for (int i : arr2) {
            arr1.push_back(i);
        }

        return arr1;
    }
};