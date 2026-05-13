#include<stack>

class Solution {
public:
    int evalRPN(const vector<string>& tokens) {
        stack<int> rpn_stack{};
        const unordered_set<string> operator_set{"+", "-", "*", "/"};
        string token{};
        char op{};

        for(size_t i{0}; i < tokens.size(); i++) {
            token = tokens[i];

            if(operator_set.find(token) != operator_set.end()) {
                op = token[0];
                int first, second {};

                second = rpn_stack.top();
                rpn_stack.pop();
                first = rpn_stack.top();
                rpn_stack.pop();

                switch(op) {
                    case '+':
                        rpn_stack.push(first+second);
                    break;
                    case '-':
                        rpn_stack.push(first-second);
                    break;
                    case '*':
                        rpn_stack.push(first*second);
                    break;
                    case '/':
                        rpn_stack.push(first/second);
                    break;

                    default:
                        return -1;
                }

            } else {
                rpn_stack.push(stoi(token));
            }
        }

        return rpn_stack.top();
    }
};
