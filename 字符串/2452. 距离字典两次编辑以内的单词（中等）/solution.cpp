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
//2.字典树
struct TrieNode {
    TrieNode* child[26];
    bool isEnd;
    TrieNode() {
        memset(child, 0, sizeof(child));
        isEnd = false;
    }
};

class Solution {
public:
    TrieNode* root = new TrieNode();

    void insert(string& word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->child[idx])
                node->child[idx] = new TrieNode();
            node = node->child[idx];
        }
        node->isEnd = true;
    }

    bool dfs(string& word, int i, TrieNode* node, int cnt) {
        if (cnt > 2)
            return false;
        if (!node)
            return false;

        if (i == word.size()) {
            return node->isEnd;
        }

        int idx = word[i] - 'a';

        // 不修改
        if (node->child[idx]) {
            if (dfs(word, i + 1, node->child[idx], cnt))
                return true;
        }

        // 修改
        if (cnt < 2) {
            for (int c = 0; c < 26; c++) {
                if (c == idx)
                    continue;
                if (node->child[c]) {
                    if (dfs(word, i + 1, node->child[c], cnt + 1))
                        return true;
                }
            }
        }

        return false;
    }

    vector<string> twoEditWords(vector<string>& queries,
                                vector<string>& dictionary) {
        for (auto& w : dictionary)
            insert(w);

        vector<string> res;
        for (auto& q : queries) {
            if (dfs(q, 0, root, 0)) {
                res.push_back(q);
            }
        }
        return res;
    }
};

