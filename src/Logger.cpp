#include "Logger.h"

void init_logger() {
    try {
        auto logger = spdlog::basic_logger_mt("file_logger", "logs/calculator.log");
        spdlog::set_default_logger(logger);
        spdlog::set_pattern("[%Y-%m-%d %H:%M:%S] [%l] %v");
        spdlog::info("Logger initialized");
    } catch (const spdlog::spdlog_ex& ex) {
        std::cerr << "Logger initialization failed: " << ex.what() << std::endl;
    }
}