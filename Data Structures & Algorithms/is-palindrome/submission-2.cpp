#include <iostream>
#include <locale>

class Solution {
   public:
    bool isPalindrome(string s) {
        int i{0}, j = s.length() - 1;

        if (s.length() == 0) {
            return false;
        }

        while (i < j) {
            while ((!std::isalnum(s[i])) && i < j) {
                i++;
            }

            while ((!std::isalnum(s[j])) && i < j) {
                j--;
            }

            if (static_cast<char>(tolower(s[i])) != static_cast<char>(tolower(s[j]))) {
                return false;
            }

            i++, j--;
        }
        return true;
    }
};
