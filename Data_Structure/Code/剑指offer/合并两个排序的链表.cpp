#include <iostream>
#include "linked_list.h"
using namespace std;

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    ListNode *preHead = new ListNode(-1);
    ListNode *cur = preHead;
    while (l1 != nullptr && l2 != nullptr)
    {
        if (l1->val < l2->val)
        {
            cur->next = l1;
            l1 = l1->next;
        }
        else
        {
            cur->next = l2;
            l2 = l2->next;
        }
        cur = cur->next;
    }

    if (l1 == nullptr && l2 != nullptr)
        cur->next = l2;
    else if (l2 == nullptr && l1 != nullptr)
        cur->next = l1;

    return preHead->next;
}

int main()
{
    ListNode *l1 = new ListNode(1);
    append(l1, 2);
    append(l1, 4);
    ListNode *l2 = new ListNode(1);
    append(l2, 3);
    append(l2, 4);
    ListNode *result = mergeTwoLists(l1, l2);
    print(result);
    return 0;
}