#include "generated/Logging.h"
#include "LoggingInternal.h"

#include <cstdarg>

namespace Logging
{
    static std::function<LogFunc> _logger;

    void setLogFunc(const std::function<LogFunc>& func) {
        _logger = func;
    }

    // from ChatGPT:
    void clientLog(const LogLevel level, const char* fmt, ...) {
        va_list args;
        va_start(args, fmt);

        // First, determine the required buffer size
        const auto size = std::vsnprintf(nullptr, 0, fmt, args);
        va_end(args);

        if (size > 0) {
            std::vector<char> buffer(size + 1); // +1 for null terminator

            va_start(args, fmt);
            std::vsnprintf(buffer.data(), buffer.size(), fmt, args);
            va_end(args);

            std::string output(buffer.data(), buffer.data() + buffer.size());
            if (_logger != nullptr) {
                _logger(level, output);
            } else {
                // defer to NI system-level logging if no logger has been set:
                ni_clientLogger(LogLevel_Warning, "Logging::clientLog emergency backup via ni_clientLogger: [%s]", output.c_str());
            }
        } else {
            _logger(LogLevel::Error, "!!! ni_clientLogger: size was <= 0");
        }
    }
}
