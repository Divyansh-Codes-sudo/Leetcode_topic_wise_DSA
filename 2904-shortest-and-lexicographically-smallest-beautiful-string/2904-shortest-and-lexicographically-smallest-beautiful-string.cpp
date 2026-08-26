class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();

        int l = 0 , ones = 0;
        string res = "";

        for (int r = 0 ; r < n ; r++){
            if (s[r] == '1') ones++;

            while (l<r && (ones > k || s[l]=='0')){
                if (s[l]=='1') ones--;
                l++;
            }

            if (ones == k){
                string sub = s.substr(l , r-l+1);

                if (res=="" || sub.size()<res.size() || (sub.size() == res.size() && sub < res)){
                    res = sub;
                }
            }
        }
        return res;

    }
};