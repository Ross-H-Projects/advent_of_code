#include <iostream>
#include <fstream>
#include <string>
//#include <algorithm>
//#include <ctype.h>
//#include <stdlib.h>

int parse_file (int* nums, int nums_length);

int main () {
    std::string path = "input.txt";
    std::ifstream input_file(path.c_str());
    std::string line;
    
    if (input_file.is_open()) {
        // all input is on the same line
        std::getline(input_file, line);
    } else {
        std::cout << "Unable to open file.\n";
        return -1;
    }
    
    int nums_length = line.length();
    int nums[nums_length];
    for (int i = 0; i < nums_length; i++) {
        nums[i] = line.at(i) - '0';
    }

    int res = parse_file(nums, nums_length);
    std::cout << "Solution: " << res;
    return 0;
}

int parse_file (int *nums, int length) {
    int half_way_index;
    int sum = 0;
    for (int i = 0; i < length; i++) {
        half_way_index = (i + (length / 2)) % length;
        if (nums[i] == nums[half_way_index]) {
            sum += nums[i];
        }
    }
    return sum;
}

