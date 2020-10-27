class Solution {
public:
    int find(vector<int>& p, int x) {
        return p[x] == x ? x : find(p, p[x]);
    }
    
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        vector<int> p(n+1);
        
        for(int i = 1; i <= n; ++i) {
            p[i] = i;
        }
        
        for(int i = threshold + 1; i <= n; ++i) {
            for(int j = i * 2; j <= n; ++j) {
                if (j % i == 0) {
                    int x = find(p, i);
                    int y = find(p, j);
                    
                    if (x != y) {
                        p[y] = x;
                    }
                }
            }
        }
        
        vector<bool> answer;
        
        for(vector<int> q : queries) {
            answer.push_back(find(p, q[0]) == find(p, q[1]));
        }
        
        return answer;
    }
};
