//依旧前括号入栈后括号出栈，奇数深度是A、偶数深度是B
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> ans;
        int dep = 0;
        for(char &c : seq)
        {
            if(c == '('){
                dep++;
                ans.push_back(dep%2);
            }else{
                ans.push_back(dep%2);
                dep--;

            }
        }
        return ans;

    }
};