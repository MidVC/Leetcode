#include <vector>
#include <iostream>
#include <string>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    void preorderTraversalrecur(vector<int> &ans, TreeNode *node) {
        if (!node) return;
        ans.push_back(node->val);
        preorderTraversalrecur(ans, node->left);
        preorderTraversalrecur(ans, node->right);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preorderTraversalrecur(ans, root);
        return ans;
    }

};

int main() {
    Solution s;
    // vector<int> v{1,1,1};
    // cout << s.longestSubarray(v) << endl;
}
