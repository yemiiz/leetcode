# LCR 026. 重排链表
## 题目描述
给定一个单链表 `L` 的头节点 `head` ，单链表 `L` 表示为：
`L0 → L1 → … → Ln-1 → Ln`
请将其重新排列后变为：
`L0 → Ln → L1 → Ln-1 → L2 → Ln-2 → …`
要求不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

## 解题思路拆解
### 方法一：拆分→反转→合并（空间优化版）
要实现链表的重排，核心思路是将原链表拆分为前后两部分，反转后半部分链表，再将前半部分和反转后的后半部分交替合并，最终得到目标链表。整体流程可拆分为以下三个核心步骤：
1. **拆分链表**：使用快慢指针找到链表的中间节点，将链表拆分为前半部分（`head` 开头）和后半部分（中间节点的下一个节点开头）；
2. **反转后半部分链表**：对拆分后的后半部分链表进行反转（提供迭代标准版、swap极简版、递归版三种实现），为后续交替合并做准备；
3. **交替合并链表**：将前半部分链表和反转后的后半部分链表逐个节点交替拼接，完成重排。

#### 代码分步解析
##### 步骤1：拆分链表（快慢指针找中点）
使用快慢指针法定位链表中点，快指针每次走两步，慢指针每次走一步，当快指针走到链表末尾时，慢指针恰好指向链表前半部分的最后一个节点。以此为界，将链表拆分为前半部分（`head`）和后半部分（`head2`）。

```cpp
// 1. 拆分链表：快慢指针找中点，将链表拆分为前半部分(head)和后半部分(head2)
ListNode *slow = head, *fast = head->next;ListNode *slow = head, *fast = head->next；
// 快指针走两步、慢指针走一步，直到快指针无法继续前进
while (fast && fast->next)
{
    slow = slow->next;
    fast = fast->next->next;
}
// 后半部分链表的头节点为慢指针的下一个节点
ListNode *head2 = slow->next;
// 切断前半部分和后半部分的连接，完成拆分
slow->next = nullptr;
```
**注释说明**：
- `slow` 初始为 `head`，`fast` 初始为 `head->next`：避免链表长度为偶数时，慢指针指向中点偏后位置；
- `fast && fast->next`：确保快指针每次能走两步，防止空指针访问；
- `slow->next = nullptr`：切断前半部分和后半部分的关联，保证两部分链表独立。

##### 步骤2：反转后半部分链表（三种实现方式）
###### 方式1：迭代标准版（最稳、易理解）
```cpp
// 2. 反转后半部分链表 - 迭代标准版
ListNode *prev = nullptr, *curr = head2;
while (curr) {
    ListNode *next = curr->next; // 保存当前节点的下一个节点，避免丢失
    curr->next = prev;           // 反转当前节点的指针指向
    prev = curr;                 // 前驱指针后移，指向当前节点
    curr = next;                 // 当前指针后移，指向原下一个节点
}
head2 = prev; // 循环结束后prev是反转后的头节点
```
**核心逻辑**：通过三个指针（`prev`/`curr`/`next`）逐节点反转指针方向，空间复杂度 O(1)，是工业界最常用的标准写法。

###### 方式2：swap极简迭代版（代码精简）
```cpp
// 2. 反转后半部分链表 - swap极简版
ListNode *p1 = nullptr, *q = head2;ListNode *p1 = nullptr, *q = head2；
while (q)
{
    swap(q->next, p1); // 交换q->next和p1，完成当前节点指针反转
    swap(p1, q);       // 交换p1和q，更新反转头节点并移动遍历指针
}
head2 = p1; // p1最终为反转后的头节点
```
**核心逻辑**：通过两次 `swap` 操作合并“反转指针”和“指针后移”，代码极简但逻辑等价于标准版。

###### 方式3：递归版（思想巧妙，适合理解递归逻辑）
```cpp
// 辅助函数：递归反转链表
ListNode* reverseList(ListNode* head) {
    // 递归终止条件：空节点 或 只有一个节点（无需反转）
    if (!head || !head->next) return head;
    // 递归递到链表最后一个节点，newHead是反转后的头节点（原链表尾节点）
    ListNode* newHead = reverseList(head->next);
    // 从后往前反转指针：让下一个节点的next指向当前节点
    head->next->next = head;
    // 切断当前节点的原指针，避免循环引用
    head->next = nullptr;
    // 向上层返回反转后的头节点
    return newHead;
}

// 调用递归反转函数
head2 = reverseList(head2);
```
**核心逻辑**：
- 先“递”到链表末尾，找到反转后的头节点 `newHead`；
- 再“归”的过程中，从后往前逐个反转节点指针；
- 空间复杂度 O(n)（递归栈开销），适合理解递归思想，实际工程中少用。

##### 步骤3：交替合并两个链表
将前半部分链表（`head`）和反转后的后半部分链表（`head2`）逐个节点交替拼接，通过临时指针记录后续节点，避免拼接过程中丢失链表引用。

```cpp
// 3. 合并：将前半部分(head)和反转后的后半部分(head2)交替拼接
ListNode *p = head;       // 前半部分链表的遍历指针
ListNode *p2 = head2;     // 反转后后半部分链表的遍历指针
while (p && p2)
{
    // 记录当前节点的下一个节点，防止拼接后丢失后续链表
    ListNode *next1 = p->next;
    ListNode *next2 = p2->next;

    // 第一步：将p2（后半部分当前节点）拼接到p（前半部分当前节点）的后面
    p->next = p2;
    // 第二步：将前半部分的下一个节点拼接到p2后面，完成一次交替
    p2->next = next1;

    // 更新遍历指针，处理下一组节点
    p = next1;
    p2 = next2;
}
```
**注释说明**：
- `next1`/`next2`：提前记录 `p` 和 `p2` 的下一个节点，避免拼接后无法找到后续节点；
- `p->next = p2`：将后半部分当前节点拼接到前半部分当前节点后；
- `p2->next = next1`：将前半部分的下一个节点拼接到后半部分当前节点后，完成一次交替；
- 循环条件 `p && p2`：确保两个链表都有节点时才拼接，适配链表长度奇偶情况。

#### 完整代码（以迭代标准版为例）
```cpp
#include <iostream>
#include <algorithm>
using namespace std;

// 定义链表节点结构
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
        // 0. 特殊情况处理：空链表或只有一个节点，无需重排
        if(!head || !head->next)
        {
            return;
        }
        else
        {
            // 1. 拆分链表：快慢指针找中点
            ListNode *slow = head, *fast = head->next;
            while (fast && fast->next)
            {
                slow = slow->next;
                fast = fast->next->next;
            }
            ListNode *head2 = slow->next;
            slow->next = nullptr;

            // 2. 反转后半部分链表 - 迭代标准版
            ListNode *prev = nullptr, *curr = head2;
            while (curr) {
                ListNode *next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            head2 = prev;

            // 3. 交替合并两个链表
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
        }
    }
};
```

### 方法二：线性表辅助法（官方解法）
#### 解题思路
链表不支持下标随机访问，无法直接按“前-后-前”的顺序获取节点。因此可以借助**线性表（如vector）** 存储所有链表节点，利用线性表的下标访问特性，直接按目标顺序重新构建链表的指针指向，完成重排。

核心步骤：
1. **存储节点**：遍历原链表，将所有节点依次存入线性表；
2. **重构链表**：使用双指针（左指针从表头、右指针从表尾）交替取节点，修改指针指向，实现 `L0→Ln→L1→Ln-1→…` 的结构；
3. **收尾处理**：最后将链表的尾节点 `next` 置为 `nullptr`，避免循环引用。

#### 代码解析（含详细注释）
```cpp
#include <iostream>   # include & lt; iostream>#包含<；iostream>； #包含&； lt；iostream>
#include <vector>   # include & lt; vector>#包含<；矢量>； #包含&； lt；vector>
using namespace std;   使用命名空间std；

// 定义链表节点结构（与方法一一致）
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution   类解决方案
{
public:   公众:
    void reorderList(ListNode *head)
    {
        // 特殊情况：空链表直接返回
        if (head == nullptr)   If （head == nullptr）
        {
            return;   返回;
        }

        // 1. 将所有链表节点存入vector，利用下标随机访问
        vector<ListNode*> vec;   vector<ListNode*> vec;
        ListNode *node = head;   ListNode *node = head；
        while (node != nullptr)   While (node ！= nullptr)
        {
            vec.emplace_back(node); // 逐个节点存入线性表
            node = node->next;   Node = Node ->next；
        }

        // 2. 双指针交替重构链表：i从头部、j从尾部开始
        int i = 0, j = vec.size() - 1;Int I = 0, j = vec.size() - 1；
        while (i < j)   While （i < j）
        {
            vec[i]->next = vec[j]; // 前节点指向后节点（L0→Ln）
            i++;                   // 左指针右移
            
            // 边界：链表长度为奇数时，i和j会重合，提前终止
            if (i == j)   If （i == j）
            {
                break;   打破;
            }
            
            vec[j]->next = vec[i]; // 后节点指向下一个前节点（Ln→L1）
            j--;                   // 右指针左移
        }
        
        // 3. 收尾：最后一个节点的next置空，避免循环链表
        vec[i]->next = nullptr;
    }
};
```

#### 关键注释说明
- `vec.emplace_back(node)`：仅存储节点指针，不复制节点，保证操作的是原链表节点；
- 双指针循环 `i < j`：左指针 `i` 负责取“前半部分”节点（L0、L1、L2…），右指针 `j` 负责取“后半部分”节点（Ln、Ln-1…）；
- `if (i == j)`：处理链表长度为奇数的情况（如1→2→3→4→5），当 `i=j=2`（对应节点3）时，无需再拼接，避免重复操作；
- `vec[i]->next = nullptr`：必须收尾，否则最后一个节点的 `next` 可能指向其他节点，形成循环链表。

## 反转链表三种实现对比
| 实现方式       | 时间复杂度 | 空间复杂度 | 核心特点                          | 适用场景                  |
|----------------|------------|------------|-----------------------------------|---------------------------|
| 迭代标准版     | O(n)       | O(1)       | 逻辑清晰、稳定性高、工业界常用    | 工程开发、面试首选        |
| swap极简迭代版 | O(n)       | O(1)       | 代码极简、炫技写法                | 快速编码、理解指针交换逻辑 |
| 递归版         | O(n)       | O(n)       | 思想巧妙、递归思维训练            | 算法学习、理解递归本质     |

## 两种重排方法对比分析
| 方法                | 时间复杂度 | 空间复杂度 | 核心优势                  | 适用场景                  |
|---------------------|------------|------------|---------------------------|---------------------------|
| 拆分→反转→合并      | O(n)       | O(1)       | 空间优化，仅用临时指针    | 对空间复杂度要求高的场景  |
| 线性表辅助法        | O(n)       | O(n)       | 逻辑简单，易理解实现      | 追求开发效率、无需省空间  |

## 核心总结
1. 拆分-反转-合并法是**最优解**，时间复杂度 `O(n)`、空间复杂度 `O(1)`，其中反转环节推荐优先使用「迭代标准版」，兼顾稳定性和可读性；
2. 线性表辅助法是**入门友好解**，利用线性表的下标特性规避链表无法随机访问的缺点，逻辑简单但需额外 `O(n)` 空间；
3. 反转链表的三种实现本质都是改变节点指针方向，迭代版无额外空间开销，递归版更适合理解算法思想，可根据场景选择。
