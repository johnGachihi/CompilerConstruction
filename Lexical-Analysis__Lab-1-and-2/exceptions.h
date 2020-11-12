//
// Created by john-gachihi on 10/11/2020.
//

#ifndef COMPILERCONSTRUCTION_EXCEPTIONS_H
#define COMPILERCONSTRUCTION_EXCEPTIONS_H

#include <stdexcept>
using namespace std;

class UnknownSymbolException : public runtime_error {
public:
    explicit UnknownSymbolException(const string& message) : runtime_error(message) {}
};

#endif //COMPILERCONSTRUCTION_EXCEPTIONS_H
