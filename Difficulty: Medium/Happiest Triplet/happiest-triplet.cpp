class Solution {
  public:
    vector<int> smallestDiff(vector<int>& a, vector<int>& b, vector<int>& c) {
        // code here.
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        sort(c.begin(),c.end());
        int i=0,j=0,k=0;
        int x,y,z;
        int mndiff=INT_MAX;
        while(i<a.size() && j<b.size() && k<c.size()){
            int mn=min({a[i],b[j],c[k]});
            int mx=max({a[i],b[j],c[k]});
            if(mx-mn < mndiff){
                mndiff=mx-mn;
                x=mx;
                z=mn;
                y=a[i]+b[j]+c[k]-mn-mx;
            }
            if(a[i]==mn)i++;
            else if(b[j]==mn)j++;
            else k++;
        }
        return {x,y,z};
    }
};