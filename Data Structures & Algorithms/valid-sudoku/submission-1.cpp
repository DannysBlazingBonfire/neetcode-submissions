class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> seen_row_set{};
        unordered_set<char> seen_col_set{};
        unordered_set<char> square{};
        // Counters to keep track of 3x3 squares
        uint8_t row_counter{0};
        uint8_t col_counter{0};
        uint8_t row_spacer{0};
        uint8_t col_spacer{0};

        for (uint8_t row{0}; row < board.size(); row++) {
            for (uint8_t col{0}; col < board[row].size(); col++) {
                // independantly iterate squares row / col here
                if (col_counter == 3) {
                    row_counter++;
                    col_counter = 0;
                }

                if (row_counter == 3) {
                    row_counter = 0;
                }

                if (board[row_spacer + row_counter][col_spacer + col_counter] != '.') {
                    auto is_unique =
                        square.insert(board[row_spacer + row_counter][col_spacer + col_counter]);
                    if (!is_unique.second) {
                        return false;
                    }
                }

                if (row_counter == 2 && col_counter == 2) {
                    square.clear();
                }

                col_counter++;
                //----------------------squares----------------------------
                if (board[row][col] != '.') {
                    // Full row
                    auto unique = seen_row_set.insert(board[row][col]);
                    if (!unique.second) {
                        return false;
                    }
                }
                if (board[col][row] != '.') {
                    // Full column
                    auto unique = seen_col_set.insert(board[col][row]);
                    if (!unique.second) {
                        return false;
                    }
                }
            }
            seen_row_set.clear();
            seen_col_set.clear();
            col_spacer += 3;

            if (col_spacer == 9) {
                col_spacer = 0;
                row_spacer += 3;
            }
        }

        return true;
    }
};

/*

Rules:

* Each row must contain the digits 1-9 without duplicates

* Each column must contain the digits 1-9 without duplicates

* Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without duplicates.

*/