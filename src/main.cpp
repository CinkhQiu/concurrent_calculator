// concurrent_calculator/main.cpp
#include "Logger.h"
#include "ThreadPoolWrapper.h"
#include "Calculator.h"
#include <vector>
#include <string>

void simulate_user_request(int user_id, ThreadPoolWrapper& pool) {
    std::string expression = std::to_string(user_id + 1) + " + " + std::to_string((user_id + 1) * 2);
    pool.enqueue([user_id, expression]() {
        spdlog::info("User {} submitted expression: {}", user_id, expression);
        int result = Calculator::evaluate(expression);
        spdlog::info("User {} got result: {}", user_id, result);
    });
}

int main() {
    init_logger();
    ThreadPoolWrapper pool(4);

    for (int i = 0; i < 10; ++i) {
        simulate_user_request(i, pool);
    }

    // 简单等待所有任务完成
    std::this_thread::sleep_for(std::chrono::seconds(2));
    return 0;
}