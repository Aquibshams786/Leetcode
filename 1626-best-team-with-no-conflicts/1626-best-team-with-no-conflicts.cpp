class Solution {
public:
    int best_team(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        vector<pair<int, int>> age_score;
        for(int i = 0; i < n; i++) {
            age_score.push_back({ages[i], scores[i]});
        }
        sort(age_score.begin(), age_score.end());
        vector<int> dp(n);
        int ans = 0;
        for(int i = 0; i < n; i++) {
            dp[i] = age_score[i].second;
            for(int j = 0; j < i; j++) {
                if(age_score[i].second >= age_score[j].second) {
                    dp[i] = max(dp[i], dp[j] + age_score[i].second);
                }
            }
            ans = max(ans, dp[i]);
        }
        
        return ans;
    }
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        return best_team(scores, ages);
    }
};
