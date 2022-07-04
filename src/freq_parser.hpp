#ifndef FREQ_DICT_FREQ_PARSER_HPP
#define FREQ_DICT_FREQ_PARSER_HPP

#include <istream>
#include <unordered_map>

class FreqParser
{
public:
    static std::unordered_map<std::string, size_t> parse(std::istream& stream);
    static void save(std::unordered_map<std::string, size_t> &dict, std::ofstream &out);
};

#endif//FREQ_DICT_FREQ_PARSER_HPP
