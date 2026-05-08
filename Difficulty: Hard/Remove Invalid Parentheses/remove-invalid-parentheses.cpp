class Solution {
  public:
    bool valid(string s){
        int cnt=0;
        for(auto i:s){
            if(i=='('){
                cnt++;
            }else if(i==')'){
                cnt--;
                if(cnt<0){
                    return false;
                }
            }
        }
        return cnt==0;
    }
    vector<string> validParenthesis(string &s) {
        //bfs
        queue<string>q;
        vector<string>ans;
        unordered_set<string>vis;
        vis.insert(s);
        q.push(s);
        bool chk=false;
        while(!q.empty()){
            string cur=q.front();
            q.pop();
            if(valid(cur)){
                ans.push_back(cur);
                chk=true;
            }
            if(chk){
                continue;
            }
            for(int i=0;i<cur.size();i++){
                if(cur[i]!=')' && cur[i]!='('){
                    continue;
                }
                string str=cur.substr(0,i)+cur.substr(i+1);
                if(vis.find(str)==vis.end()){
                    vis.insert(str);
                    q.push(str);
                }
            }
        }
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};
