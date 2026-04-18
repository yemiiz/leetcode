class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& 
factory) {
        sort(robot.begin(),robot.end());
        sort(factor.begin(),factor.end(),[](const vector<int>& a,const vector<int>&
b)
        {
            return a[0] < b[0];
        });
        //factory[j][0]是位置，factory[j][1]是上限，j是第几个
        long long cnt = 0;
        for(auto it = robot.begin();it!=robot.end();it++)
        {
            
        }
    }
};
