/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    vector<int> node;
    void getKthSmallest(TreeNode* root, int k) {
        if(!root || node.size() >= k) return;
        
        getKthSmallest(root->left, k);
        node.push_back(root->val);
        getKthSmallest(root->right, k);
    }
    
public:
    int kthSmallest(TreeNode* root, int k) {
        getKthSmallest(root, k);
        return node[k-1];
    }
};