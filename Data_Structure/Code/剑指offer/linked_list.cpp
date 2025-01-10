#include "linked_list.h"
using namespace std;

bool insert(ListNode *pHead, int idx, int val)
{
    if (idx < 0)
        return false;
    if (pHead == nullptr)
    {
        pHead->val = val;
        pHead->next = nullptr;
        return true;
    }

    ListNode *pnew = new ListNode(val);
    if (idx == 0)
    {
        pnew->next = pHead;
        pHead = pnew;
        return true;
    }

    ListNode *cur = pHead;
    idx--;
    while (idx--)
    {
        if (cur != nullptr)
            cur = cur->next;
        else
            return false;
    }
    if (cur == nullptr)
        return false;
    ListNode *pnext = cur->next;
    cur->next = pnew;
    pnew->next = pnext;
    return true;
}

bool append(ListNode *pHead, int val)
{
    if (pHead == nullptr)
    {
        pHead->val = val;
        pHead->next = nullptr;
        return true;
    }

    ListNode *pnew = new ListNode(val);
    ListNode *cur = pHead;
    while (cur->next != nullptr)
        cur = cur->next;
    cur->next = pnew;
    return true;
}

void print(ListNode *pHead)
{
    if (pHead == nullptr)
    {
        cout << "null" << endl;
        return;
    }
    ListNode *cur = pHead;
    while (cur != nullptr)
    {
        cout << cur->val << "\t";
        cur = cur->next;
    }
    cout << endl;
    return;
}

bool deletebyindex(ListNode *pHead, int idx)
{
    if (idx < 0)
        return false;
    if (idx == 0)
    {
        if (pHead == nullptr)
            return false;
        else if (pHead->next == nullptr)
        {
            pHead = nullptr;
            return true;
        }
        else
        {
            pHead = pHead->next;
            return true;
        }
    }

    ListNode *cur = pHead;
    idx--;
    while (idx--)
    {
        if (cur != nullptr)
            cur = cur->next;
        else
            return false;
    }
    ListNode *pdelete = cur->next;
    cur->next = cur->next->next;
    delete pdelete;
    return true;
}

// int main()
// {
//     ListNode *pHead = new ListNode(1);
//     append(pHead, 2);
//     append(pHead, 3);
//     append(pHead, 4);
//     insert(pHead, 2, 6);
//     print(pHead);
//     deletebyindex(pHead, 2);
//     print(pHead);
//     return 0;
// }