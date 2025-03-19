// Binary Tree Level Order Traversal

// Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

vector<vector<int>> levelOrder(Node *root) {
    if (root == NULL) {
        return {};
    }

    queue<Node*> q;
    vector<vector<int>> ans;
    q.push(root);
    q.push(NULL); // NULL is used to mark levels

    vector<int> level; // Temporary vector to store current level nodes

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp == NULL) {
            ans.push_back(level); // Store the completed level
            level.clear(); // Clear for the next level
            
            if (!q.empty()) {
                q.push(NULL);
            }
        } else {
            level.push_back(temp->data); // Store node data
            
            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
    }

    return ans;
}
