class Solution {
  public:
    int myAtoi(string &s) {
        // code here
        
        int i=0,n=s.size();
        long long ans=ans=0;
        while(i<n && s[i]==' '){
            i++;
        }
        int sign;
        if(s[i]=='+'){
            sign=1;
            i++;
        }else if(s[i]=='-'){
            sign=-1;
            i++;
        }else{
            sign=1;
        }
        while(i<n && s[i]=='0'){
            i++;
        }
        if(s[i]<'0' || s[i]>'9'){
            return 0;
        }
        while(s[i]>='0' && s[i]<='9'){
            ans=ans*10+(s[i]-'0');
            
            if (ans * sign >= INT_MAX) return INT_MAX;
            if (ans * sign <= INT_MIN) return INT_MIN;

            i++;
        }
        return ans*sign;
    }
};
