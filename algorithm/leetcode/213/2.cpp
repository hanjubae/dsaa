class Solution {
public:
    int countVowelStrings(int n) {
        int d[6][51] = {0, };
        d[1][1] = 5;
        d[2][1] = 4;
        d[3][1] = 3;
        d[4][1] = 2;
        d[5][1] = 1;
        
        if(n == 1) {
            return 5;
        }
        for(int i = 2; i < n; ++i) {
            for(int j = 1; j <= 5; ++j) {
                for(int k = j; k <= 5; ++k) {
                    d[j][i] += d[k][i-1];
                }
            }
        }
        
        int result = 0;
        for(int i = 1; i <= 5; ++i) {
            result += d[i][n-1];
        }
        
        return result;
    }
};
