#include <iostream>
#include <vector>
// #include <utility>
using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        vector<pair<Node *, int>> vec;
        Node *cur = head;

        Node *new_dummy = new Node(-1);
        Node *new_cur = new_dummy;
        int count = 0;
        while (cur != nullptr)
        {
            Node *new_node = new Node(cur->val);
            vec.push_back(make_pair(cur->random, -1));
            for (int i = 0; i < vec.size(); i++)
            {
                if (vec[i].first == cur)
                {
                    vec[i].second = count;
                    break;
                }
            }
            new_cur->next = new_node;
            new_cur = new_cur->next;
            cur = cur->next;
            count++;
        }

        for (int i = 0; i < vec.size(); i++)
        {
            new_cur = new_dummy->next;
            if (vec[i].first != nullptr)
            {
                int count = vec[i].second;
                Node *search_cur;
                while (count--)
                {
                    search_cur = search_cur->next;
                }
                new_cur->random = search_cur;
            }
            else
            {
                new_cur->random = nullptr;
            }
            new_cur = new_cur->next;
        }
        return new_dummy->next;
    }
};