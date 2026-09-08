class Solution {
public:
    int countCommas(int n) {
        if (n < 1000) return 0;

        int ans = 0;

        for (int i = 1000 ; i<= n ; i++){
            int digi = floor(log10(i)) + 1;
            int coma = (digi-1) / 3;
            ans += coma;
        }

        return ans;
    }
};