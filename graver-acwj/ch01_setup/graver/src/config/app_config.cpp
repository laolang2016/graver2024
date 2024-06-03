#include "graver/config/app_config.h"

#include <map>

using namespace graver::config;

using namespace graver::config;

std::unique_ptr<AppConfig> AppConfig::app_config_instance_;
std::mutex                 AppConfig::app_config_mutex_;

AppConfig& AppConfig::GetInstance() {
    if (!app_config_instance_) {
        std::lock_guard<std::mutex> lock(app_config_mutex_);
        if (!app_config_instance_) {
            app_config_instance_.reset(new AppConfig);
        }
    }

    return *app_config_instance_;
}

AppConfig::AppConfig() {
    // 日志级别
#ifdef GRAVER_LOG_LEVEL
    // 定义映射关系
    const std::map<int, spdlog::level::level_enum> levelMap{
        {0, spdlog::level::trace}, {1, spdlog::level::debug},    {2, spdlog::level::info}, {3, spdlog::level::warn},
        {4, spdlog::level::err},   {5, spdlog::level::critical}, {0, spdlog::level::off}};

    // 根据宏定义的值获取相应的日志级别
    m_log_level = levelMap.at(GRAVER_LOG_LEVEL);
#else
    m_log_level = spdlog::level::info;
#endif
}