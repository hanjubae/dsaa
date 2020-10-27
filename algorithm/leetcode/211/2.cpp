class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        string result = s;
        queue<string> q;
        set<string> visited;
        int size = s.size();

        q.push(s);
        visited.insert(s);
        while (!q.empty()) {
            string cur = q.front();
            q.pop();

            if (cur < result) {
                result = cur;
            }

            for (int i = 1; i < size; i += 2) {
                cur[i] = ((cur[i] - '0') + a) % 10 + '0';
            }

            if (visited.insert(cur).second) {
                q.push(cur);
            }

            cur = cur.substr(size - b) + cur.substr(0, size - b);

            if (visited.insert(cur).second) {
                q.push(cur);
            }
        }

        return result;
    }
};
