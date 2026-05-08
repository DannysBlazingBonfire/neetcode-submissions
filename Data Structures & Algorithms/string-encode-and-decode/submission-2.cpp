#include <bitset>

class Solution {
public:

    string encode(const vector<string>& strs) {
        string encoded_str{};
        encoded_str.reserve(sizeof(strs) + strs.size());
        string current_str{};
        char encrypted_char{};

        // iterate string elements
        for(size_t i{0}; i < strs.size(); i++) {
            current_str = strs[i];
            if(current_str.empty()) { 
                encoded_str.push_back({});
                encoded_str.push_back(split_char);
                continue;
            }

            // iterate characters
            for(auto _char : current_str) {
                // invert bits and XOR the char byte with key.
                encrypted_char = _XOR_with_key(_invert_bits(_char));
                encoded_str.push_back(encrypted_char);
            }

            if(i == strs.size() - 1) { break; }
            encoded_str.push_back(split_char);
        }

        return encoded_str;
    }

    vector<string> decode(const string s) {
        vector<string> decoded_vec{};
        string str_element{};
        char decoded_char{};
        
        for(size_t _char{0}; _char < s.length(); _char++) {
            if(s[_char] == '\0') {
                continue;
            }

            if(s[_char] == split_char) {
                decoded_vec.push_back(str_element);
                str_element.clear();
                continue;
            }

            if(_char == s.length() - 1) {
                decoded_char = _invert_bits(_XOR_with_key(s[_char]));
                str_element.push_back(decoded_char);
                decoded_vec.push_back(str_element);
                continue;
            }

            decoded_char = _invert_bits(_XOR_with_key(s[_char]));
            str_element.push_back(decoded_char);
        }

        return decoded_vec;
    }

private:
    inline char _invert_bits(char c) { return (~c); }
    inline char _XOR_with_key(char c) { return (c^encryption_key); }

    const uint8_t encryption_key{69};
    const char split_char{'-'};
};
