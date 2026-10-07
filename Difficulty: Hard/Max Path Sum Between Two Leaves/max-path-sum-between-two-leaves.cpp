class Solution {
public:
    int ans;
    int solve(Node* root) {
        if (root == nullptr)
            return 0;

        // Leaf node
        if (root->left == nullptr && root->right == nullptr)
            return root->data;

        // Only right child
        if (root->left == nullptr) {
            int rightSum = solve(root->right);
            return root->data + rightSum;
        }

        // Only left child
        if (root->right == nullptr) {
            int leftSum = solve(root->left);
            return root->data + leftSum;
        }

        // Both children exist
        int leftSum = solve(root->left);
        int rightSum = solve(root->right);

        // Path from leaf -> left subtree -> root -> right subtree -> leaf
        ans = max(ans, leftSum + root->data + rightSum);

        // Return best root-to-leaf path
        return root->data + max(leftSum, rightSum);
    }

    int maxPathSum(Node* root) {
        if (root == nullptr)
            return -1;

        ans = INT_MIN;

        solve(root);

        // Fewer than two leaves
        if (ans == INT_MIN)
            return -1;

        return ans;
    }
};