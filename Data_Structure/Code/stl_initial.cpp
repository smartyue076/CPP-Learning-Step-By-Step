#include <iostream>
#include <vector>
#include <deque>
#include <list>
using namespace std;

int main()
{
    int size = 5;
    int initial = 0;
    int insert_index = 2;
    int insert_value = 6;

    // vector
    vector<int> vec_a(size);
    vector<int> vec_b(size, initial);
    vec_b.push_back(1);
    vec_b.insert(vec_b.begin(), 6);

    // deque
    deque<int> deq_a(size);
    deque<int> deq_b(size, initial);
}