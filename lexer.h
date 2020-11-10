//
// Created by john-gachihi on 31/10/2020.
//

#ifndef COMPILERCONSTRUCTION_LEXER_H
#define COMPILERCONSTRUCTION_LEXER_H

#include <fstream>
#include <string>
#include <vector>
#include <cctype>
#include <sstream>
#include "exceptions.h"
using namespace std;

enum TokenKind {
    STRING,
    KEYWORD,
    INTEGER,
    FLOAT,
    IDENTIFIER,
    SEPARATOR,
    OPERATOR
};

struct Token {
    string token;
    TokenKind kind;
};

class Lexer {
public:
    static vector<Token> getTokens(istream&);

private:
    istream s;
    vector<Token> tokens;

    static Token readKeywordOrIdentifier(istream&);
    static Token readIntOrFloat(istream&);
    static Token readString(istream&);
    static Token readSeparator(istream&);
    static Token readOperator(istream&);

    static bool isSeparator(char c);
    static bool isOperator(char c);
};


#endif //COMPILERCONSTRUCTION_LEXER_H
