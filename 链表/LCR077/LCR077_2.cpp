// 利用split和merge来实现归并排序
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
    ListNode *split(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head->next;
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *newhead = slow->next;
        slow->next = nullptr;   //不要忘，负责在sort前半部分的时候把整个都sort
        return newhead;
    }
    ListNode *merge(ListNode *n1,ListNode *n2)
    {
        ListNode dummy;     //很妙，不需要考虑头结点的情况
        ListNode *p = &dummy;
        while(n1 && n2)
        {
            if(n1->val < n2->val)
            {
                p->next = n1;
                n1 = n1->next;
            }
            else
            {
                p->next = n2;
                n2 = n2->next;
            }
            p = p->next;    //不要忘
        }
        if(n1)
            p->next = n1;
        if(n2)
            p->next = n2;
        return dummy.next;
    }
    ListNode *sortList(ListNode *head)
    {
        if(!head || !head->next)
            return head;
        else
        {
            //重点！ 先切分，再排前后部分序，最后合并
            ListNode * newhead = split(head);

            ListNode * firstpart = sortList(head);
            ListNode * secondpart = sortList(newhead);

            return merge(firstpart,secondpart);
            
        }
    }
};