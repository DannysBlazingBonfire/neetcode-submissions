class Solution {
   public:
    bool isValid(string& s) {
        const unordered_map<char, uint8_t> open_types_map{{'(', 0}, {'{', 1}, {'[', 2}};
        const unordered_map<char, uint8_t> close_types_map{{')', 0}, {'}', 1}, {']', 2}};
        stack<char> par_stack{};

        char current{};
        for (size_t _char_index{0}; _char_index < s.size(); _char_index++) {
            current = s[_char_index];
            if (open_types_map.find(current) != open_types_map.end()) {
                par_stack.push(current);
            } else if (close_types_map.find(current) != close_types_map.end()) {
                if (!par_stack.empty()) {
                    auto it_open = open_types_map.find(par_stack.top());
                    auto it_close = close_types_map.find(current);

                    if (it_open->second == it_close->second) {
                        par_stack.pop();
                    } else {
                        return false;
                    }
                } else {
                    return false;
                }
            }
        }

        if (par_stack.empty()) {
            return true;
        }

        return false;
    }
};
