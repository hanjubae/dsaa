class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int result = 0;
        int n = scores.size();
        vector<pair<int,int>> players;
        for (int i = 0; i < n; i++) {
            players.push_back(make_pair(ages[i],scores[i]));
        }

        sort(players.begin(), players.end());
        int dp[n];
        for(int i = 0; i < n; i++) {
            dp[i] = players[i].second;
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (players[i].second >= players[j].second && dp[i] < dp[j] + players[i].second) {
                    dp[i] = dp[j] + players[i].second;
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            if (result < dp[i]) {
                result = dp[i];
            }
        }
        return result;
    }
};
