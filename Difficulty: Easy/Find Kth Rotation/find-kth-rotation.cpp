class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        return min_element(arr.begin(),arr.end())-arr.begin();
    }
};
