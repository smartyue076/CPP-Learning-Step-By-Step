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

ListNode *reverseList(ListNode *head)
{
    ListNode *pre = nullptr;
    ListNode *cur = head;
    while (cur != nullptr)
    {
        ListNode *next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    return pre;
}