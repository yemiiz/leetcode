class Solution {
public:
    bool isaeiou(char c)
    {
        return (cha == 'a' || cha == 'e' || cha == 'i' || cha == 'o' || cha == 'u');
    }
    int maxVowels(string s, int k) {
        int l = 0, r = 0, sum = 0, ans = 0;
        while (r < s.size())
        {
            sum += isaeiou(s[r]);
            if (r - l + 1 >= k)
            {
                ans = max(ans, sum);
                sum -= isaeiou(s[l++]);
            }
            r++;
        }
        return ans;
    }
};