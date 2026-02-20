class Solution {
  public:
    string findLargest(vector<int> &nums) {
        // code here
        vector<string>arr;
        for(int i=0;i<nums.size();i++){
            arr.push_back(to_string(nums[i]));
        }
        sort(arr.begin(),arr.end(),[](const string &a, const string &b) {
            return (a + b) > (b + a);
        });
        if(arr[0]=="0") return "0";
        // return accumulate(arr.begin(),arr.end(),string(""));
        string res="";
        for(int i=0;i<arr.size();i++){
            res+=arr[i];
        }
        return res;
    }
};