class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int temp;
        unordered_map<int, int> ht;
        for (int i = 0; i < nums.size(); i++) {
            temp = target - nums[i];
            if (ht.count(temp)) {
                return {ht[temp], i};
            }
            ht[nums[i]] = i;
        }
        return {};
    }
};