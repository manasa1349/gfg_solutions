class Solution {
  public:
    bool isItPossible(string &s1, string &s2) {
        // code here
        int i=0,j=0;
        int n=s1.size(),m=s2.size();
        while(i<n || j<m){
            while(i<n && s1[i]=='#'){
                i++;
            }
            while(j<m && s2[j]=='#'){
                j++;
            }
            
            if(i>=n && j>=m) break;
            if(i>=n || j>=m) return false;
            
            
            if(s1[i]!=s2[j]) return false;
            if(s1[i]=='A' && i<j) return false;
            if(s1[i]=='B' && i>j) return false;
            i++;
            j++;
        }
        return true;
    }
};