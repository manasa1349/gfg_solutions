/*
Definition for Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    int sz=0;
    int getSize(Node* root) {
        // code here
        if(!root) return 0;
        sz++;
        if(root->left) getSize(root->left);
        if(root->right) getSize(root->right);
        return sz;
    }
};