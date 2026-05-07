/*
Definition for Node
struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = right = nullptr;
    }
};
*/

bool func(Node *root1,Node *root2){
    if(!root1 && !root2){
        return true;
    }
    if(!root1 || !root2 || root1->data!=root2->data){
        return false;
    }
    return func(root1->left,root2->left)&& func(root1->right,root2->right);
}

class Solution {
  public:
    bool isSubTree(Node *root1, Node *root2) {
        // code here
        if(!root1){
            return false;
        }
        if(root1->data==root2->data && func(root1,root2)){
            return true;
        }
        return isSubTree(root1->left,root2) || isSubTree(root1->right,root2);
    }
};