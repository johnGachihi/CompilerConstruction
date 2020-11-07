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
#include <iostream> // TODO: Temporary
using namespace std;

enum TokenKind {
    STRING,
    KEYWORD,
    INTEGER,
    FLOAT
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

    static Token readKeyword(istream&);
    static Token readIntOrFloat(istream&);
    static Token readString(istream&);
};


#endif //COMPILERCONSTRUCTION_LEXER_H
