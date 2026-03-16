/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    int ans=0;
    unordered_map<int,int>mp;
    void funcsum(Node *root,int k,int sum){
        if(!root){
            return;
        }
        sum+=root->data;
        if(sum == k){
            ans++;
        }
        if(mp.find(sum-k)!=mp.end()){
            ans+=mp[sum-k];
        }
        mp[sum]++;
        if(root->left){
            funcsum(root->left,k,sum);
        }
        if(root->right){
            funcsum(root->right,k,sum);
        }
        mp[sum]--;
    } 
    int countAllPaths(Node *root, int k) {
        // code here
        funcsum(root,k,0);
        return ans;
        
    }
};