class Solution {
public:
    vector<vector<string>> groupAnagrams(const vector<string>& strs) {
        vector<vector<string>> result{};
        unordered_map<string, vector<string>> sorted_anagram_map{};

        // Sort anagram strings
        string current_str{};
        for(size_t i{0}; i < strs.size(); i++) {
            current_str = strs[i];
            sort(current_str.begin(), current_str.end());
            sorted_anagram_map[current_str].push_back(strs[i]);
        }

        for(auto groups : sorted_anagram_map) {
            result.push_back(groups.second);
        }

        return result;   
    }
};
