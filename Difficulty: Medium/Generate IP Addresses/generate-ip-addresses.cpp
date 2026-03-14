class Solution {
  public:
    void func(string s,string k,int idx,int dcnt,string ds,vector<string>&ans){
        if(idx == s.size()){
            if(dcnt == 3 && k != "" && stoi(k) <= 255){
                ds += k;
                ans.push_back(ds);
            }
            return;
        }
        
        // try extending current number
        if(k.size() < 3){
            string newk = k + s[idx];
            
            if(stoi(newk) <= 255){
                // avoid leading zero
                if(!(k == "0")){
                    func(s, newk, idx+1, dcnt, ds, ans);
                }
            }
        }
        
        // place dot and start new segment
        if(dcnt < 3 && k != ""){
            if(stoi(k) <= 255){
                func(s, "", idx, dcnt+1, ds + k + ".", ans);
            }
        }
    }
    vector<string> generateIp(string &s) {
        // code here
        
        vector<string>ans;
        func(s, "", 0, 0, "", ans);
        return ans;
    }
};