#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class CQueue
{
public:
    CQueue()
    {
    }

    void appendTail(int value)
    {
        inS.push(value);
        return;
    }

    int deleteHead()
    {
        int result = 0;
        if (!outS.empty())
        {
            result = outS.top();
            outS.pop();
        }
        else
        {
            if (inS.empty())
                return -1;
            else
            {
                while (!inS.empty())
                {
                    int val = inS.top();
                    inS.pop();
                    outS.push(val);
                }
                result = outS.top();
                outS.pop();
            }
        }
        return result;
    }

private:
    stack<int> inS;
    stack<int> outS;
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */