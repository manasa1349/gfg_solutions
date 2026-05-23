/* Structure for Tree Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    int func(Node *root){
        if(!root){
            return 0;
        }
        int l=func(root->left);
        int r=func(root->right);
        int val= root->data+l+r;
        root->data=l+r;
        return val;
    }
    void toSumTree(Node *root) {
        // code here
        int tsum=func(root);
    }
};