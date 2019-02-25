#include <iostream>
#include <fstream>
#include <string>

int* parse_file (std::string, int);

int main () {
  std::string path = "input.txt";
  parse_file(path, 3);
  return 0;
}

int* parse_file (std::string path, int members) {
  int *member_mapping = new int[members];
  std::string line;
  std::ifstream input_file(path.c_str());

  if (input_file.is_open()) {
    while (std::getline(input_file, line)) {
      std::cout << line << "\n";
    }
    input_file.close();
  } else {
    std::cout << "Unable to open file.\n";
  }

  return member_mapping;
}
