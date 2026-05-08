class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) { return false; }

        unordered_map<char, int> string_map_s{};
        unordered_map<char, int> string_map_t{};
        unordered_set<char> chars_set{};

        for(int i{0}; i < s.length(); i++) {
            string_map_s[s[i]]++;
            string_map_t[t[i]]++;
            chars_set.insert(s[i]);
        }

        char cmp_char{};
        for(auto it = chars_set.begin(); it != chars_set.end(); it++) {
            cmp_char = *it;
            if(string_map_s[cmp_char] != string_map_t[cmp_char]) { return false; }
        }

        return true;
    }
};
