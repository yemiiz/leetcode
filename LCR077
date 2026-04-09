#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    ListNode *sortList(ListNode *head)
    {
        ListNode *p = head;
        vector<int> v;
        while (p != nullptr)
        {
            v.push_back(p->val);
            p = p->next;
        }
        sort(v.begin(), v.end(), greater<int>()); // greater是标准库提供的
        ListNode *temp = nullptr;
        for (int i = 0; i < v.size(); i++)
        {
            ListNode *head1 = new ListNode();

            head1->val = v[i];
            head1->next = temp;
            temp = head1;
        }
        return temp;
    }
};