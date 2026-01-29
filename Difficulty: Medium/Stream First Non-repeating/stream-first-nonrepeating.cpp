class Solution {
  public:
    string firstNonRepeating(string &s) {
        // code here
        unordered_map<char,int>mp;
        queue<char>q;
        string res;
        q.push(s[0]);
        mp[s[0]]++;
        res+=s[0];
        for(int i=1;i<s.size();i++){
            q.push(s[i]);
            mp[s[i]]++;
            // if(!q.empty() && s[i]==q.front()){
            //     q.pop();
            // }
            while(!q.empty() && mp.find(q.front())!=mp.end() && mp[q.front()]>1){
                q.pop();
            }
            if(!q.empty()){
                res+=(q.front());
            }else{
                res+='#';
            }
        }
        return res;
    }
};
//aabc
// geeksforgeeks