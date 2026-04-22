//1.暴力
class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans; // 这里必须是 string 类型
        for (string query : queries) {
            bool found = false;
            for (string s : dictionary) {
                // 长度不同的字符串，无法通过2次编辑变成相同，直接跳过
                if (query.size() != s.size()) continue;
                
                int dis = 0;
                for (int i = 0; i < query.size(); ++i) {
                    if (query[i] != s[i]) {
                        dis++;
                        // 差异数超过2时，提前终止比较
                        if (dis > 2) break;
                    }
                }
                if (dis <= 2) {
                    found = true;
                    break;
                }
            }
            if (found) {
                ans.push_back(query);
            }
        }
        return ans;
    }
};