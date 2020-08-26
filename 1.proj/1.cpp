#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result(2);  // 初始化数组大小
        int loop1, loop2;
        for (loop1 = 0; loop1 < nums.size() - 1; loop1++) {
            for (loop2 = loop1 + 1; loop2 < nums.size(); loop2++) {
                if (nums[loop1] + nums[loop2] == target) {
                    result.at(0) = loop1;
                    result.at(1) = loop2;
                    return result;
                }
            }
        }
        return result;
    }
};