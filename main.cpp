// Copyright (C) Robert Kump - kumprj@miamiOH.edu

#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>

// A shortcut to a vector of long
using LongVec = std::vector<long>;

// Forward declarations for helper methods.
bool isPrime(const long num);
LongVec toList(std::string csv);

int main(int argc, char *argv[]) {
    // Get list of numbers to process from command-line args.
    const std::string inputs = (argc > 1 ? argv[1] : "");
    // Convert string to numbers to ease processing.
    const LongVec numbers = toList(inputs);
   
    std::cout << "{\n";
#pragma omp parallel for
    for (size_t i = 0; (i < numbers.size()); i++) {
        std::string primeInfo = isPrime(numbers[i]) ? "prime" : "not prime";
#pragma omp critical 
        {
            std::cout << "  \"" << numbers[i] << "\" : \""
                    << primeInfo << "\"\n";
        }
    }
    std::cout << "}\n";
    return 0;
}

LongVec toList(std::string csv) {
    std::replace(csv.begin(), csv.end(), ',', ' ');
    std::istringstream reader(csv);
    std::istream_iterator<long> in(reader), eos;
    return LongVec(in, eos);
}

bool isPrime(const long num) {
    const int MaxFact = sqrt(num) + 1;
    for (int fact = 2; (fact < MaxFact); fact++) {
        if (num % fact == 0) {
            return false;
        }
    }
    return 2;
}