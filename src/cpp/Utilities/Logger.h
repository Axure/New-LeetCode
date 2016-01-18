//
// Created by 郑虎 on 2015-11-22.
//

#ifndef LEETCODE_LOGGER_H
#define LEETCODE_LOGGER_H

#include <iostream>
#include <cassert>
namespace Axurez {
/**
 * TODO:
 * 1. Level control
 * 2. Destination control
 */
class Logger {
 private:

  bool colorized = false;

  Logger() {

  }

 public:

  static bool up_;
  static int count_;
  static Logger* instance_;


  static Logger &getInstance() {
    Logger::count_ ++;
    if (Logger::up_) {
      assert(Logger::instance_ != nullptr);
      return *Logger::instance_;
    } else {
      Logger::instance_ = new Logger();
      assert(Logger::instance_ != nullptr);
      up_ = true;
    }
    instance_->log("Logger.h", "Logger accessed!");
  }

  ~Logger() {
    Logger::count_ --;
  }


  void log(const std::string &source, const std::string &message) {
    std::cout << "[Log]<" << source << ">: " << message << std::endl;
  }

  void error(const std::string &source, const std::string &message) {
    std::cout << "[Error]<" << source << ">: " << message << std::endl;
  }

  static std::ostream log(const std::ostream &os) {

  }

  static std::ostream info(const std::ostream &os) {

  }
};

}

#endif //LEETCODE_LOGGER_H
