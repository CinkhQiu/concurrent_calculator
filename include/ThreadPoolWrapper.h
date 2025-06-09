#pragma once
#include <functional>
#include <BS_thread_pool.hpp>

class ThreadPoolWrapper {
public:
    ThreadPoolWrapper(size_t thread_count);
    ~ThreadPoolWrapper();

    void enqueue(std::function<void()> task);

private:
    BS::thread_pool<> pool_;
};