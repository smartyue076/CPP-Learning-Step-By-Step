#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int v) : val(v), next(nullptr){};
    ListNode(int v, ListNode *n) : val(v), next(n){};
};

bool insert(ListNode *, int, int);

bool append(ListNode *, int);

void print(ListNode *);

bool deletebyindex(ListNode *, int);