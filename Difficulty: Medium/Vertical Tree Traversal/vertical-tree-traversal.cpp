/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    void func(Node *r,map<int,vector<int>>&mp){
        if(!r) return;
        queue<pair<Node *,int>>q;
        q.push({r,0});
        while(!q.empty()){
            Node *node=q.front().first;
            int val=q.front().second;
            q.pop();
            mp[val].push_back(node->data);
            if(node->left){
                q.push({node->left,val-1});
            }
            if(node->right){
                q.push({node->right,val+1});
            }
        }
        
    }
    vector<vector<int>> verticalOrder(Node *root) {
        // code here
        map<int,vector<int>>mp;
        func(root,mp);
        vector<vector<int>>ans;
        for(auto i:mp){
            ans.push_back(i.second);
        }
        return ans;
    }
};