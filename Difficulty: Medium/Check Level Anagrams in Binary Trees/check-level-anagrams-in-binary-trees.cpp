/* Structure of binary tree Node
class Node {
    public:
    int data;
    Node *left, *right;
    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    bool areAnagrams(Node* root1, Node* root2) {
        // code here
        queue<Node *>q1,q2;
        q1.push(root1);
        q2.push(root2);
        while(!q1.empty() || !q2.empty()){
            if(q1.empty()) return false;
            if(q2.empty()) return false;
            
            int n1=q1.size();
            int n2=q2.size();
            unordered_map<int,int>mp1,mp2;
            
            while(n1--){
                Node* node=q1.front();
                q1.pop();
                if(node->left){
                    q1.push(node->left);
                }
                if(node->right){
                    q1.push(node->right);
                }
                mp1[node->data]++;
            }
            
            while(n2--){
                Node* node=q2.front();
                q2.pop();
                if(node->left){
                    q2.push(node->left);
                }
                if(node->right){
                    q2.push(node->right);
                }
                mp2[node->data]++;
            }
            
            for(auto &it:mp1){
                if(mp2.find(it.first)==mp2.end() || mp2[it.first]!=it.second){
                    return false;
                }
            }
            for(auto &it:mp2){
                if(mp1.find(it.first)==mp1.end() || mp1[it.first]!=it.second){
                    return false;
                }
            }
        }
        return true;
    }
};
