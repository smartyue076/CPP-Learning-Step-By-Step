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

vector<int> reversePrint(ListNode *head)
{
    if (head == nullptr)
        return {};
    vector<int> result;
    ListNode *cur = head;
    while (cur != nullptr)
    {
        result.push_back(cur->val);
        cur = cur->next;
    }
    reverse(result.begin(),result.end());
    return result;
}