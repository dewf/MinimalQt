module Logging;

enum LogLevel {
    Trace,
    Debug,
    Information,
    Warning,
    Error,
    Critical,
    None
}

delegate void LogFunc(LogLevel level, string text);

void setLogFunc(LogFunc func);
void clearFunc();
