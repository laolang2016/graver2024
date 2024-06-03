#include <fmt/core.h>

#include <memory>

#include "doctest/doctest.h"
#include "graver/util/log_util.h"

using namespace graver;

TEST_SUITE("test_common") {
    TEST_CASE("test_common_one") {
        std::shared_ptr<spdlog::logger> log = util::LogUtil::getLogger("test_common_one");
        SPDLOG_LOGGER_INFO(log, fmt::format("test_common_one start"));
        SPDLOG_LOGGER_INFO(log, fmt::format("test_common_one end"));
    }
}