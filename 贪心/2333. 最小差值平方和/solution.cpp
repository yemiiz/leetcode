class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        vector<int> a(1e5 + 1,0);
        int k = k1+k2;
        for(auto it = 0;it!=nums1.size();it++){
            a[abs(nums1[it] - nums2[it])]++;
        }
        for(int i = a.size() - 1;k > 0 && i > 0;i--){
            int change = min(k,a[i]);
            a[i - 1] += change;
            k-=change;
            a[i] -= change;
        }
        long long ans = 0;
        for(long long i = 0; i < a.size(); i++){    //这里要用longlong，底下计算i*i会溢出
            if(a[i]){
                ans+=i*i*a[i];
            }
        }
        return ans;
    }
};