class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n = l.size();
        vector<bool> result(n);

        for (int i = 0; i < n; ++i) {
            vector<int> temp(nums.begin() + l[i], nums.begin() + r[i] + 1);
            sort(temp.begin(), temp.end());

            result[i] = true;

            int diff = temp[1] - temp[0];
            int m = temp.size();
            for (int j = 2; j < m; ++j) {
                if (diff != temp[j] - temp[j - 1]) {
                    result[i] = false;
                    break;
                }
            }
        }

        return result;
    }
};
