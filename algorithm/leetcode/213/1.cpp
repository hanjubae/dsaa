class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        int n = 0;
        for(vector<int> piece : pieces) {
            int piece_size = piece.size();
            int idx = 0;
            for(int i = 0; i < arr.size(); ++i) {
                if(arr[i] == piece[idx]) {
                    for(int j = 1; j < piece_size; ++j) {
                        if(i + j >= arr.size()) {
                            return false;
                        }
                        if(arr[i + j] != piece[idx + j]) {
                            return false;
                        }
                    }
                    n++;
                }
            }
        }
        
        return n == pieces.size();
    }
};
