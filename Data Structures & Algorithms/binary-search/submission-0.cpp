class Solution {
   public:
    // nums=[-1,0,2,4,6,8]
    // target=3

    int search(vector<int>& nums, int target) {
        int higher_bound = nums.size() - 1;
        int lower_bound{0};
        int div_index{0};
        int val{0};

        while (lower_bound <= higher_bound) {
            div_index = std::floor((higher_bound + lower_bound) / 2);
            val = nums[div_index];

            if (val == target) {
                return div_index;
            }
            if (val < target) {
                lower_bound = div_index + 1;
            } else {
                higher_bound = div_index - 1;
            }
        }

        return -1;
    }
};
