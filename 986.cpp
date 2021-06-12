#include <bits/stdc++.h>
using namespace std;

# define VEC(x, y) 

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> result;
        
        auto first_it = firstList.begin();
        auto second_it = secondList.begin();
        bool first_inside = false, second_inside = false;
        auto first_interval = first_it, second_interval = second_it;
        
        while ( true ) {
            if (first_inside == false) {
                if (first_it == firstList.end())
                    return result;
                first_interval = first_it++;
                first_inside = true;
            }
            if (second_inside == false) {
                if (second_it == secondList.end())
                    return result;
                second_interval = second_it++;
                second_inside = true;
            }
            
            // case 1 : doesn't intersect 
            if ((*first_interval)[0] > (*second_interval)[1]) {
                second_inside = false;
                continue;
            }
            if ((*second_interval)[0] > (*first_interval)[1]) {
                first_inside = false;
                continue;
            }
            
            int start = max((*first_interval)[0], (*second_interval)[0]);
            // case 2 : intersects. 1st ends first
            if ((*first_interval)[1] < (*second_interval)[1]) {
                result.push_back(vector<int>{start, (*first_interval)[1]});
                first_inside = false;
                continue;
            }
            
            // case 3 : intersects. 2nd ends first
            else if ((*first_interval)[1] > (*second_interval)[1]) {
                result.push_back(vector<int>{start, (*second_interval)[1]});
                second_inside = false;
                continue;
            }
            
            // case 4 : intersects. close at the same place
            else {
                result.push_back(vector<int>{start, (*first_interval)[1]});
                first_inside = false;
                second_inside = false;
                continue;
            }
        }
        
        // end consideration: two intervals may still be opened (inside)
        // if (first_it == firstList.end()) {
        //     if (first_inside == false)
        //         return result;
            
        // }        
            
        
    }
};

int main() {
    Solution sol;
    vector<vector<int>> firstList{vector<int>{0,2},vector<int>{5,10},vector<int>{13,23},vector<int>{24,25}};
    vector<vector<int>> secondList{vector<int>{1,5},vector<int>{8,12},vector<int>{15,24},vector<int>{25,26}};
    auto a = sol.intervalIntersection(firstList, secondList);
    for (auto b : a) {
        for (auto c : b)
            cout << c << " ";
        cout << endl;
    }
}