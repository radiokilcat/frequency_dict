#include "freq_parser.hpp"
#include <chrono>
#include <fstream>
#include <iomanip>
#include <iostream>

int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        std::cout << "usage: ./freq_dict input_file output_file" << std::endl;
        return 1;
    }
    std::string inputFile  = argv[1];
    std::string outputFile = argv[2];

    auto start = std::chrono::high_resolution_clock::now();
    auto start_t = std::chrono::high_resolution_clock::to_time_t(start);

    std::cout << "start at: " << std::put_time(std::localtime(&start_t), "%X") << std::endl;
    std::fstream inputStream;
    inputStream.open(inputFile, std::fstream::in);
    if (inputStream.fail())
    {
        std::cout << "file " << inputFile << " could not be opened" << std::endl;
        return 1;
    }

    auto test = FreqParser::parse(inputStream);

    std::ofstream outputStream;
    outputStream.open(outputFile, std::fstream::out);
    if (outputStream.fail())
    {
        std::cout << "file " << outputFile << " could not be opened" << std::endl;
        return 1;
    }

    FreqParser::save(test, outputStream);

    auto end = std::chrono::high_resolution_clock::now();
    auto end_t = std::chrono::high_resolution_clock::to_time_t(end);

    std::cout << "finished at: " << std::put_time(std::localtime(&end_t), "%X") << std::endl;
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    std::cout << "elapsed time: " << elapsed << " milliseconds" <<  std::endl;

    return 0;
}