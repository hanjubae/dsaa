class Solution {
  public:
      char slowestKey(vector<int>& releaseTimes, string keysPressed) {
      int times[26] = { 0, };
      int result = -1;
      int resultIdx = 0;
      int n = releaseTimes.size();
      times[keysPressed[0] - 'a'] = releaseTimes[0];
      for (int i = 1; i < n; ++i) {
          int idx = keysPressed[i] - 'a';
          int time = releaseTimes[i] - releaseTimes[i - 1];

          if (times[idx] < time) {
              times[idx] = time;
          }
      }

      for (int i = 0; i < 26; ++i) {
          if (result <= times[i]) {
              result = times[i];
              resultIdx = i;
          }
      }

      return 'a' + resultIdx;
  }
};
