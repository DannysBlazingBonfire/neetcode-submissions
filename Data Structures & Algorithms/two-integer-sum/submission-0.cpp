class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> vec_map{};
        int selected{};
        int candidate{};

        for(int i{0}; i < nums.size(); i++) {
            selected = nums[i];
            candidate = target - selected;
            if(vec_map.contains(candidate)) {
                return {vec_map.at(candidate), i};
            }

            vec_map[selected] = i;
        }

        return {};
    }
};
