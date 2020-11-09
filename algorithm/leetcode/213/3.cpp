class Solution {
public:
    int check(int mid, vector<int>& heights, int bricks, int ladders) {
        vector<int> diff;
        for(int i = 1; i <= mid; ++i) {
            if(heights[i] > heights[i - 1]) {
                diff.push_back(heights[i] - heights[i - 1]);
            }
        }
        
        sort(diff.begin(), diff.end());
        
        int n = diff.size();
        int sum = 0;
        for(int i = 0; i < n - ladders; ++i) {
            sum += diff[i];
        }
        
        return bricks >= sum;
    }
    
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        
        int l = 0;
        int r = n - 1;
        int answer = 0;
        
        while (l <= r) {
            int mid = (l + r) / 2;
            
            if(check(mid, heights, bricks, ladders)) {
                answer = mid;
                l = mid + 1;
            }else {
                r = mid - 1;
            }
        }
        
        return answer;
    }
};
