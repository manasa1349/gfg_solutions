/* BST Node
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        
        Node* pre = NULL;
        Node* suc = NULL;

        Node* curr = root;

        while (curr) {
            if (curr->data < key) {
                pre = curr;
                curr = curr->right;
            } else if (curr->data > key) {
                suc = curr;
                curr = curr->left;
            } else {
                // predecessor
                Node* t = curr->left;
                while (t) {
                    pre = t;
                    t = t->right;
                }

                // successor
                t = curr->right;
                while (t) {
                    suc = t;
                    t = t->left;
                }
                break;
            }
        }

        return {pre, suc};

    }
};