/* Binary Tree Node Structure
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; 
*/

class Solution {
  public:
    Node *prev=nullptr;
    int ans=INT_MAX;
    void func(Node *root){
        if(!root){
            return;
        }
        func(root->left);
        if(prev){
            ans=min(ans,abs(root->data-prev->data));
        }
        prev=root;
        func(root->right);
    }
    int absDiff(Node *root) {
        // code here
        prev=nullptr;
        ans=INT_MAX;
        func(root);
        return ans;
    }
};