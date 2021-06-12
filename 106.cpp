#include <bits/stdc++.h>
using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* build(vector<int>& io, int iolo, int iohi, vector<int>& po, int polo, int pohi) {
        if (pohi == polo)
            return new TreeNode(po[pohi]);
        
        int i;
        for (i = iohi; i >= iolo; --i) 
            if (io[i] == po[pohi])
                break;
        
        TreeNode* root = new TreeNode(io[i]);
        if (iohi > i) {
            root->right = build(io, i + 1, iohi, po, pohi - iohi + i, pohi - 1);
        }
        if (iolo < i) {
            root->left = build(io, iolo, i - 1, po, polo, polo + i - iolo - 1);
        }
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(inorder, 0, inorder.size(), postorder, 0, postorder.size());
    }
};

int main() {
    vector<int> in{9,3,15,20,7}, post{9,15,7,20,3};
    Solution sol;
    TreeNode *ans = sol.buildTree(in, post);
    return 0;

}