class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26 , 0);

        for(char &ch : word){
            freq[ch - 'a']++;
        }

        sort(begin(freq) , end(freq) , greater<int>());

        int ans = 0;

        for(int i = 0 ; i < 26 ; i++){
            int f = freq[i];
            int press = (i/8) + 1;

            ans += f*press;
        }

        return ans;

    }
};