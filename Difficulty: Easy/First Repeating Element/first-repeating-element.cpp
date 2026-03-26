class Solution {
  public:
    int firstRepeated(vector<int> &arr) {
        // code here
        unordered_map<int, int> myMap;
        
        for(int val: arr) myMap[val]++;
        
        for(int i=0; i<arr.size(); i++){
            if(myMap[arr[i]] > 1) return i+1;
        }
        return -1;
    }
};