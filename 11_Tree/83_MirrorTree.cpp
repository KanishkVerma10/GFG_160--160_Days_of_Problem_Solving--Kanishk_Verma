// Mirror Tree

// Given a binary tree, convert the binary tree to its Mirror tree.

// Mirror of a Binary Tree T is another Binary Tree M(T) with left and right children of all non-leaf nodes interchanged.     

class Solution {
  public:
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node* node) {
        if(node == NULL){
            return;
        }
        
        queue<Node*> q;
        q.push(node);
        
        while(!q.empty()){
            Node* temp = q.front();
            q.pop();
            
            swap(temp->left, temp->right);
            
            if(temp->left != NULL){
                q.push(temp->left);
            }
            if(temp->right != NULL){
                q.push(temp->right);
            }
        }
    }
};
