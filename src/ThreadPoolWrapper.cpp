#include "ThreadPoolWrapper.h"

ThreadPoolWrapper::ThreadPoolWrapper(size_t thread_count)
    : pool_(thread_count) {}

ThreadPoolWrapper::~ThreadPoolWrapper() = default;

void ThreadPoolWrapper::enqueue(std::function<void()> task) {
    auto _ = pool_.submit_task(std::move(task));
}