#include <iostream>
#include <fstream>
#include <string>
//#include <ctype.h>
//#include <stdlib.h>

int main () {
  std::ifstream input_file;
  std::string input_file_loc;

  std::cout << "Enter the file location and name: ";

  std::cin >> input_file_loc;
  input_file.open(input_file_loc.c_str());
  return 0;
}
