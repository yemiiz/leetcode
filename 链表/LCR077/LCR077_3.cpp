// 利用迭代的方式实现归并排序——AI
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
        if (!head || !head->next)
            return head;
        int len = 0;
        ListNode *cur = head;
        while (cur)
        {
            len++;
            cur = cur->next;
        }

        ListNode dummy(0, head);
        for (int step = 1; step < len; step <<= 1)
        {
            ListNode *prev = &dummy;
            cur = dummy.next;

            while (cur)
            {
                // 切第一段 h1
                ListNode *h1 = cur;
                for (int i = 1; i < step && cur->next; i++)
                {
                    cur = cur->next;
                }
                ListNode *h2 = cur->next;
                cur->next = nullptr;
                cur = h2;

                // 切第二段 h2（这里必须加 cur != nullptr）
                ListNode *h2_temp = cur; // 改名避免冲突
                for (int i = 1; i < step && cur && cur->next; i++)
                {
                    cur = cur->next;
                }
                ListNode *next = nullptr;
                if (cur)
                {
                    next = cur->next;
                    cur->next = nullptr;
                }

                // 合并
                ListNode *merged = merge(h1, h2_temp);
                prev->next = merged;
                while (prev->next)
                    prev = prev->next;
                cur = next;
            }
        }
        return dummy.next;
    }

private:
    ListNode *merge(ListNode *h1, ListNode *h2)
    {
        ListNode dummy;
        ListNode *cur = &dummy;
        while (h1 && h2)
        {
            if (h1->val <= h2->val)
            {
                cur->next = h1;
                h1 = h1->next;
            }
            else
            {
                cur->next = h2;
                h2 = h2->next;
            }
            cur = cur->next;
        }
        cur->next = h1 ? h1 : h2;
        return dummy.next;
    }
};