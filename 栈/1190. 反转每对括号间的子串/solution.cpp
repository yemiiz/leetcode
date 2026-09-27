class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> stk;
        string str;
        for(auto &c:s)
        {
            if(c == '('){
                stk.push(str);
                str = "";
            }
            else if(c == ')')
            {
                reverse(str.begin(),str.end());
                str = stk.top() + str;
                stk.pop();
            }
            else{
                str.push_back(c);
            }

        }
        return str;
    }
};