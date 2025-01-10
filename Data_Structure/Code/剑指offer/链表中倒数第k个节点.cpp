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

ListNode *getKthFromEnd(ListNode *head, int k)
{
    ListNode *low = head;
    ListNode *high = head;
    while (k--)
    {
        if (high!=nullptr)
            high = high->next;
        else
            return nullptr;
    }

    while (high != nullptr)
    {
        low = low->next;
        high = high->next;
    }
    return low;
}