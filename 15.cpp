#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size(); ++i) {
            if (i != 0 && nums[i] == nums[i-1])
                continue;
            int lo = i + 1, hi = nums.size() - 1;
            int target = -nums[i];
            while (lo < hi) {        
                int left = nums[lo], right = nums[hi];
                int sum = left + right;
                if (sum < target) {
                    while (lo < hi && nums[lo] == left)
                        ++lo;
                }
                else if (sum > target) {
                    while (lo < hi && nums[hi] == right)
                        --hi;
                }                    
                else {
                    result.push_back({nums[i], nums[lo], nums[hi]});
                    while (lo < hi && nums[lo] == left)
                        ++lo;
                    while (lo < hi && nums[hi] == right)
                        --hi;
                }   
            }
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> in{-1,0,1,2,-1,-4};
    auto ans = sol.threeSum(in);
    for (auto a : ans) {
        for (auto b : a)
            cout << b << " ";
        cout << endl;
    }
}