#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int v) : val(v), next(nullptr){};
    ListNode(int v, ListNode *n) : val(v), next(n){};
};

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if (headA == nullptr || headB == nullptr)
            return nullptr;
        ListNode *curA = headA;
        ListNode *curB = headB;
        while (curA != curB)
        {
            if (curA == nullptr)
                curA = headB;
            else
                curA = curA->next;
            if (curB == nullptr)
                curB = headA;
            else
                curB = curB->next;
        }
        return curA;
    }
};