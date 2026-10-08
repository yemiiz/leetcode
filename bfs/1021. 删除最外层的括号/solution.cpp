class Solution {
    bool is_valid(const string& s) {
        int left = 0; // 未配对的左括号的个数
        for (char ch : s) {
            if (ch == '(') {
                left++;
            } else if (ch == ')') {
                if (left == 0) { // 右括号太多了
                    return false;
                }
                left--; // 左右括号配对
            }
        }
        return left == 0; // 所有左括号都要有对应的右括号
    }

public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        unordered_set<string> cur = {s}; // 起点
        while (true) {
            for (auto& t : cur) {
                if (is_valid(t)) {
                    ans.push_back(t);
                }
            }
            if (!ans.empty()) { // cur 中存在有效括号字符串
                return ans;
            }

            unordered_set<string> nxt;
            for (auto& t : cur) {
                // 枚举删除 t[i]
                for (int i = 0; i < t.size(); i++) {
                    if (t[i] == '(' || t[i] == ')') {
                        nxt.insert(t.substr(0, i) + t.substr(i + 1));
                    }
                }
            }
            cur = move(nxt);
        }
    }
};
