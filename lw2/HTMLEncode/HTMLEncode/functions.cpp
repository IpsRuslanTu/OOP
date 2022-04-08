#include <map>
#include "functions.h"

std::string HTMLEncode(std::string const& text)
{
    std::map <char, std::string> crypt = { {'\"', "&quot;"}, {'\'', "&apos;"}, {'<', "&lt;"},
    {'>', "&gt;"}, {'&', "&amp;"} };//название переменной не отражает сути содержимого
    std::map <char, std::string> ::iterator it;//если переменная используется внутри цикла, то и обьявлять ее нужно внутри цикла
    std::string buffer = text;
    int offset;

    size_t found = buffer.find_first_of("\"\'<>&"); //"\"\'<>&" вынести в константу
    while (found != std::string::npos)
    {
        offset = 1;
        it = crypt.find(buffer[found]);
        buffer.replace(found, 1, it->second);
        offset = it->second.size();
        found = buffer.find_first_of("\"\'<>&", found + offset);
    }
    return buffer;
}