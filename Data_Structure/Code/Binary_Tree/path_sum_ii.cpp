#include "basic_binary_tree.h"
using namespace std;

class Solution
{
public:
    void backTracking(TreeNode *p, int required)
    {
        if (p != nullptr)
        {
            int val = p->val;
            single.push_back(val);
            if (required - val >= 0)
            {
                if (required - val == 0 && p->left == nullptr && p->right == nullptr)
                {
                    result.push_back(single);
                }
                else
                {
                    backTracking(p->left, required - val);
                    backTracking(p->right, required - val);
                }
            }
            single.pop_back();
        }
        return;
    }


    vector<vector<int>> pathSum(TreeNode *root, int target)
    {
        backTracking(root, target);
        return result;
    }

private:
    vector<int> single;
    vector<vector<int>> result;
};

int main()
{
    Solution s;
    TreeNode *a = new TreeNode(7);
    TreeNode *b = new TreeNode(2);
    TreeNode *c = new TreeNode(5);
    TreeNode *d = new TreeNode(1);
    TreeNode *e = new TreeNode(11, a, b);
    TreeNode *f = new TreeNode(13);
    TreeNode *g = new TreeNode(4, c, d);
    TreeNode *h = new TreeNode(4, e, nullptr);
    TreeNode *i = new TreeNode(8, f, g);
    TreeNode *j = new TreeNode(5, h, i);
    vector<vector<int>> v = s.pathSum(j, 22);
    print_double_vec(v);
    return 0;
}