class Solution {
public:
    int getMaximumGenerated(int n) {
        if (n <= 1) {
            return n;
        }
        int result = 1;
        int arr[101] = {0, };
        arr[0] = 0;
        arr[1] = 1;
        
        for(int i = 2; i <= n; ++i) {
            if(i%2 == 0) {
                arr[i] = arr[i / 2];
            }else {
                int half = i / 2;
                arr[i] = arr[half] + arr[half + 1];
            }
            
            if(arr[i] > result) {
                result = arr[i];
            }
        }
        
        return result;
    }
};
