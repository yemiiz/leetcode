
#include <iostream>
#include <algorithm>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    void reorderList(ListNode *head)
    {
        //0. special
        if(!head || !head->next)
        {
            return;
        }
        else
        {
            // 1. split
            ListNode *slow = head, *fast = head->next;
            while (fast && fast->next)
            {
                slow = slow->next;
                fast = fast->next->next;
            }
            ListNode *head2 = slow->next;
            slow->next = nullptr;

            // 2. reverse head2
            ListNode *p1 = nullptr, *q = head2;
            while (q)
            {
                swap(q->next, p1);
                swap(p1, q);
            }
            head2 = p1;

            //3.merge
            ListNode *p = head;
            ListNode *p2 = head2;
            while (p && p2)
            {
                ListNode *next1 = p->next;
                ListNode *next2 = p2->next;

                p->next = p2;
                p2->next = next1;

                p = next1;
                p2 = next2;
            }

            //head = p->next;   错误！！！
            //head = dummy2.next; 正确
        }
    }
};