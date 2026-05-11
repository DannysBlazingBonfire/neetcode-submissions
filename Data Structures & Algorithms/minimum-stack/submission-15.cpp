#include <forward_list>

class MinStack {
public:
    MinStack(): _stack{}, _min_values{}, _min{INT_MAX} {}
    
    void push(const int val) {
        if(val <= _min) {
            _min = val;
        }

        _min_values.push_front(_min);
        _stack.push_front(val);
    }
    
    void pop() {
        _min_values.pop_front();
        _stack.pop_front();

        if (_min_values.empty()) {
            _min = INT_MAX;
        } else {
            _min = _min_values.front();
        }
    }
    
    int top() {
        return _stack.front();
    }
    
    int getMin() {
        return _min;
    }

private:
    forward_list<int> _stack;
    forward_list<int> _min_values;
    int _min;
};
