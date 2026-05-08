
class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> value_map{};

        for(int i{0}; i < nums.size(); i++) {
            if(value_map.count(nums[i])) { return true; }

            value_map.insert(nums[i]);
        }
        
        return false;
    }
};