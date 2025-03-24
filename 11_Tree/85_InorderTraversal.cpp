// Inorder Traversal

// Given a Binary Tree, your task is to return its In-Order Traversal.

// An inorder traversal first visits the left child (including its entire subtree), then visits the node, and finally visits the right 
// child (including its entire subtree).

class Solution {
  public:
    // Function to return a list containing the inorder traversal of the tree.
    void solve(Node* root, vector<int> & ans){
        if(root == NULL){
            return;
        }
        
        solve(root->left, ans);
        ans.push_back(root->data);
        solve(root->right, ans);
    }
    
    vector<int> inOrder(Node* root) {
        vector<int> ans;
        solve(root, ans);
        return ans;
    }
};
