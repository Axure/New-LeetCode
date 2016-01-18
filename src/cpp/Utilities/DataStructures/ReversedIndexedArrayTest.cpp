#include "ReverseIndexedArray.hpp"
#include "../Logger.h"
#include <string>
#include <iostream>
int main() {

  auto ria = Axurez::DataStructure::RIA<int, std::string>();
  ria[5] = "321";
  ria[5];


  Axurez::Logger::getInstance().log("ReversedIndexedArray.hpp", "haha");
  try {
    std::cout << ria.at(4) << std::endl;
  } catch (std::out_of_range ex){
    std::cout << ex.what() << std::endl;
  }

  try {

    ria.findIndex("haha");
  } catch (std::exception ex) {

  }

  std::cout << ria.size() << std::endl;
  std::cout << ria.at(5)<< std::endl;
//  std::cout << ria[2];
  return 0;
}