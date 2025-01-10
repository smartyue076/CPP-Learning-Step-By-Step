#include <iostream>
#include <unordered_set>
using namespace std;

struct MyListNode
{
    pair<int, int> key_val;
    MyListNode *pre;
    MyListNode *next;
    MyListNode() : key_val(-1, -1), pre(nullptr), next(nullptr) {}
    MyListNode(pair<int, int> x) : key_val(x.first, x.second), pre(nullptr), next(nullptr) {}
    MyListNode(pair<int, int> x, MyListNode *pre, MyListNode *next) : key_val(x.first, x.second), pre(pre), next(next) {}
};

class LRUCache
{
public:
    LRUCache(int capacity)
    {
        this->capacity = capacity;
        dummy_start = new MyListNode();
        dummy_end = new MyListNode();
        dummy_start->next = dummy_end;
        dummy_end->pre = dummy_start;
    }

    int get(int key)
    {
        if (uset.find(key) == uset.end())
            return -1;
        MyListNode *cur = dummy_start;
        int value;
        while (cur != nullptr)
        {
            if (cur->key_val.first == key)
            {
                cur->pre->next = cur->next;
                cur->next->pre = cur->pre;
                break;
            }
            cur = cur->next;
        }
        cur->next = dummy_start->next;
        dummy_start->next->pre = cur;
        dummy_start->next = cur;
        cur->pre = dummy_start;
        return cur->key_val.second;
    }

    void put(int key, int value)
    {
        if (get(key) != -1)
        {
            dummy_start->next->key_val.second = value;
        }
        else
        {
            MyListNode *new_node = new MyListNode(pair<int, int>(key, value));
            if (capacity == 0)
            {
                MyListNode *del_node = dummy_end->pre;
                dummy_end->pre->pre->next = dummy_end;
                dummy_end->pre = dummy_end->pre->pre;
                uset.erase(del_node->key_val.first);
                delete del_node;
            }
            else
            {
                capacity--;
            }
            new_node->next = dummy_start->next;
            dummy_start->next->pre = new_node;
            dummy_start->next = new_node;
            new_node->pre = dummy_start;
            uset.insert(key);
        }
    }

    void printLinkedList()
    {
        MyListNode *cur = dummy_start->next;
        while (cur != nullptr && cur->key_val.first != -1)
        {
            cout << '(' << cur->key_val.first << "," << cur->key_val.second << ")"
                 << "  ";
            cur = cur->next;
        }
        cout << endl;
    }

private:
    MyListNode *dummy_start;
    MyListNode *dummy_end;
    int capacity;
    unordered_set<int> uset;
};

int main()
{
    LRUCache test = LRUCache(1);
    test.put(2, 1);
    test.printLinkedList();
    cout << test.get(1) << endl;
    test.printLinkedList();
    return 0;
}