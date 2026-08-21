class Solution {
  public:
    int transform(string &s1, string &s2) {
        // code here
        int n = s1.size();
        
        if (n != s2.size()) return -1;
        
        unordered_map<char , int> mp;
        
        for (char ch : s1){
            mp[ch]++;
        }
        
        for (char ch : s2){
            mp[ch]--;
        }
        
        for (auto &it : mp){
            if (it.second != 0) return -1;
        }
        
        
        int i = n-1;
        int j = n-1;
        
        while (i >= 0 && j>=0){
            if (s1[i] == s2[j]) i--,j--;
            
            else i--;
        }
        
        return j+1;
    }
};
