class Solution {
  public:
    void rearrangeQueue(queue<int> &q) {
        // code here
        queue<int>f,s;
        int sz=q.size()/2;
        while(q.size()>sz){
            f.push(q.front());
            q.pop();
        }
        while(!q.empty()){
            s.push(q.front());
            q.pop();
        }
        while(!f.empty() && !s.empty()){
            q.push(f.front());
            q.push(s.front());
            f.pop();
            s.pop();
        }
    }
};