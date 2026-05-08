class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, const int k) {
        unordered_map<int, int> int_freq_map{};
        vector<int> result{};

        // store int frequencies
        for(size_t i{0}; i < nums.size(); i++) {
            int_freq_map[nums[i]]++;
        }

        vector<pair<int, int>> v {int_freq_map.begin(), int_freq_map.end()};
        sort(v.begin(), v.end(), _comp);

        auto r_it = v.rbegin();
        for(size_t i{0}; i < k; i++) {
            result.push_back(r_it->first);
            r_it++;
        }

        return result;
    }
    
    static bool _comp(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    }
};