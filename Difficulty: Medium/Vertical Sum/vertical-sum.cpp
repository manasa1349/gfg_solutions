/* Structure of binary tree node
class Node{
public:
    int data;
    Node* left, right;
    Node(int item)
    {
        data = item;
        left = nullptr;
        right = nullptr;
    }
}
*/
class Solution {
  public:
    vector<int> verticalSum(Node* root) {
        // code here
        queue<pair<Node*,int>>q;
        q.push({root,0});
        map<int,int>mp;
        while(!q.empty()){
            Node *node=q.front().first;
            int lvl=q.front().second;
            q.pop();
            mp[lvl]+=node->data;
            if(node->left){
                q.push({node->left,lvl-1});
            }
            if(node->right){
                q.push({node->right,lvl+1});
            }
        }
        vector<int>vec;
        for(auto i:mp){
            vec.push_back(i.second);
        }
        return vec;
    }
};