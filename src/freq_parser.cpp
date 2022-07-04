#include "freq_parser.hpp"

#include "fstream"
#include <algorithm>
#include <iostream>


std::unordered_map<std::string, size_t> FreqParser::parse(std::istream &stream)
{
    std::string const symbols{"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    std::unordered_map<std::string, size_t> words_count;
    std::string word;

    if (!stream.good()) {
        std::cout << "error occurred in input stream" << std::endl;
        return words_count;
    }

    std::string contents;
    stream.seekg(0, std::ios::end);
    contents.resize(stream.tellg());
    stream.seekg(0, std::ios::beg);
    stream.read(&contents[0], contents.size());
    std::cout << "input read into std::string" << std::endl;

    size_t begin = 0;
    size_t position = 0;

    while ((begin = contents.find_first_of(symbols, position)) != std::string::npos)
    {
        position = contents.find_first_not_of(symbols, begin + 1);
        word = contents.substr(begin, position - begin);
        std::for_each(word.begin(), word.end(), [](char& c) { c = std::tolower(c); });

        words_count[word]++;
    }
    return words_count;
}

struct comp {
    bool operator()(const std::pair<std::string, size_t>& l, const std::pair<std::string, size_t>& r) const {
        if (l.second == r.second)
            return l.first < r.first;
        return l.second > r.second;
    }
};

void FreqParser::save(std::unordered_map<std::string, size_t>& dict, std::ofstream& out)
{
    if (!out.good())
    {
        std::cout << "file could not be opened" << std::endl;
        return;
    }
    if (dict.empty())
    {
        std::cout << "the dict is empty, nothing to save" << std::endl;
        return;
    }
    std::vector<std::pair<std::string, size_t>> v(dict.begin(), dict.end());
    std::sort(v.begin(), v.end(), comp());

    for (const auto& it: v)
    {
        out << it.second << " : " << it.first << std::endl;
    }
}