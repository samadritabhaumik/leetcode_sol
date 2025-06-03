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
public:
 void solve(TreeNode* root,vector<int>& inorder){
        if(!root)   return;
        solve(root->left,inorder);
        inorder.push_back(root->val);
        solve(root->right,inorder);
    }
    TreeNode *contruct(vector<int>& in,int low,int high){
        if(low>high)    return NULL;
        int mid = low + (high-low)/2;
        TreeNode *curr = new TreeNode(in[mid]);
        curr->left  = contruct(in,low,mid-1);
        curr->right = contruct(in,mid+1,high);
        return curr;
    }
    TreeNode* balanceBST(TreeNode* root) {
        if(!root)   return NULL;
        vector<int> inorder;
        solve(root,inorder);
        return contruct(inorder,0,inorder.size()-1);
    }
};