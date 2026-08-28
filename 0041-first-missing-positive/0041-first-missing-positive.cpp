class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> s;
        int x = 0;
        for (int i : nums){
            s.insert(i);
            x = max(x , i);
        }

        if (x < 0) return 1;

        for (int i = 1 ; i <= x ; i++){
            if (s.find(i)==s.end()) return i;
        }

        return x+1;





    }
};