#ifndef CRYPTBASE64_LIBBASE64_H
#define CRYPTBASE64_LIBBASE64_H

#include <string>

enum Table{
    ASCII,
    Base64,
};

std::string CodeBase64(std::string line,Table table);

#endif //CRYPTBASE64_LIBBASE64_H
