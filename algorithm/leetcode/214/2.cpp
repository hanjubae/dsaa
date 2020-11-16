class Solution {
public:
    int minDeletions(string s) {
        int result = 0;
        int alpha[26] = {0, };
        for(char& c : s) {
            alpha[c - 'a']++;
        }
        int mask[100001] = {0, };

        for(int i = 0; i < 26; ++i) {
            if(alpha[i] == 0) continue;
            if(mask[alpha[i]] == 0) {
                mask[alpha[i]] = 1;
            }else {
                int cnt = alpha[i];
                while(cnt >= 0) {
                    if(mask[cnt] != 0) {
                        cnt--;
                        result ++;
                    }else {
                        break;
                    }
                }
                if(cnt > 0) mask[cnt] = 1;
            }
        }
        return result;
    }
};
