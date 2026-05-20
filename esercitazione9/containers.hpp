#pragma once

#include <queue>
#include <stack>

template<typename T>
class lifo {
    std::stack<T> stack_;

public:
    void put(const T& val) {
        stack_.push(val);
    }

    T get() {
        T val = stack_.top();
        stack_.pop();
        return val;
    }

    bool empty() const {
        return stack_.empty();
    }

};

template<typename T>
class fifo {
    std::queue<T> queue_;

public:
    void put(const T& val) {
        queue_.push(val);
    }

    T get() {
        T val = queue_.front();
        queue_.pop();
        return val;
    }

    bool empty() const {
        return queue_.empty();
    }

};
