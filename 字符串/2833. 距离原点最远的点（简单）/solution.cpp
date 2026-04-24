//用ranges的写法
class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int cnt_r = ranges::count(moves, 'R');
        int cnt_l = ranges::count(moves, 'L');
        return abs(cnt_r - cnt_l) + moves.size() - cnt_r - cnt_l;
    }
};

//作者：灵茶山艾府