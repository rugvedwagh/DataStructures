 void createGraph(TreeNode* root, vector<vector<int>>& adj) {
    if (!root) {
        return;
    }

    if (root->left) {
        adj[root->val].push_back(root->left->val);
        adj[root->left->val].push_back(root->val);
        dfs(root->left, adj);
    }

    if (root->right) {
        adj[root->val].push_back(root->right->val);
        adj[root->right->val].push_back(root->val);
        dfs(root->right, adj);
    }
}
