1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        int cnt = 0;
        unordered_set<int>s;
        for(auto it = nums.begin();it!=nums.end();it++)