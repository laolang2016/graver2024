#include <cmdline/cmdline.h>
#include <fmt/core.h>
#include <spdlog/spdlog.h>

#include <memory>

#include "graver/config/app_config.h"
#include "graver/util/log_util.h"

using namespace graver;

int main(int argc, char** argv) {
    util::LogUtil::init(config::AppConfig::GetInstance().logLevel(), "../logs/app.log");
    const std::shared_ptr<spdlog::logger> log = util::LogUtil::getLogger("app");

    cmdline::parser arg;

    arg.set_program_name("graver");
    arg.footer("compiler graver");

    arg.add<std::string>("input", 'i', "Input file", true, "");
    arg.add("lex", 'l', "lexer the input file");

    arg.parse_check(argc, argv);

    SPDLOG_LOGGER_DEBUG(log, fmt::format("args:"));
    SPDLOG_LOGGER_DEBUG(log, fmt::format("input file:{}", arg.get<std::string>("input")));
    SPDLOG_LOGGER_DEBUG(log, fmt::format("lexer the input file:{}", arg.exist("lex")));

    spdlog::shutdown();
    return 0;
}
