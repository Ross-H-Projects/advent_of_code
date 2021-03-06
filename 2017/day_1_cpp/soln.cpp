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
    int before = 0; // can be set to 0 as place holder
    int sum = 0;
    for (int i = 0; i < length; i++) {
        if (nums[i] == before) {
            sum += nums[i];
        }
        if (i == length - 1 && nums[i] == nums[0]) {
            sum += nums[i];
        }
        before = nums[i];
    }
    return sum;
}

