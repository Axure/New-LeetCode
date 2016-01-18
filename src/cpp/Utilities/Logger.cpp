//
// Created by 郑虎 on 2015-11-22.
//

#include "Logger.h"
namespace Axurez {
bool Logger::up_ = false;
int Logger::count_ = 0;
Logger *Logger::instance_ = nullptr;
}