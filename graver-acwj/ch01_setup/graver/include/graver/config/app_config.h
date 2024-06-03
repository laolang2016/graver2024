#pragma once

#include <spdlog/common.h>

#include <mutex>

namespace graver::config {

class AppConfig {
public:
    static AppConfig& GetInstance();

    AppConfig(const AppConfig&)            = delete;
    AppConfig& operator=(const AppConfig&) = delete;
    ~AppConfig()                           = default;

private:
    AppConfig();

private:
    static std::unique_ptr<AppConfig> app_config_instance_;
    static std::mutex                 app_config_mutex_;

public:
    [[nodiscard]] inline spdlog::level::level_enum logLevel() const noexcept {
        return m_log_level;
    }

private:
    spdlog::level::level_enum m_log_level;
};

}  // namespace graver::config