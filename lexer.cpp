//
// Created by john-gachihi on 31/10/2020.
//

#include "lexer.h"

vector<Token> Lexer::getTokens(istream& in) {
    vector<Token> tokens;

    int nextCh = in.peek();
    if (isalpha(nextCh)) {
        Token identifier = readKeyword(in);
        tokens.push_back(identifier);
    }
    else if (isdigit(nextCh)) {
        Token intOrFloat = readIntOrFloat(in);
        tokens.push_back(intOrFloat);
    }
    else if (nextCh == '"') {
        Token string = readString(in);
        tokens.push_back(string);
    }

    return tokens;
}

Token Lexer::readKeyword(istream& in) {
    string identifier;

    char c;
    while(in.get(c)) {
        if (isalpha(c) || isdigit(c)) {
            identifier += c;
        } else {
            break;
        }
    }

    return {identifier, KEYWORD};
}

Token Lexer::readIntOrFloat(istream& in) {
    Token token;
    token.kind = INTEGER;

    char c;
    while(in.get(c)) {
        if (isdigit(c)) {
            token.token += c;
        }
        else if (c == '.' && token.kind == INTEGER) {
            token.token += c;
            token.kind = FLOAT;
        }
        else {
            break;
        }
    }

    return token;
}

Token Lexer::readString(istream& in) {
    Token token;
    int numOfDoubleQuotes = 0;

    char c;
    while (in.get(c)) {
        if (numOfDoubleQuotes == 2) {
            break;
        }
        if (c == '"') {
            token.token += c;
            numOfDoubleQuotes++;
        }
        else if (isprint(c)) {
            token.token += c;
        }
    }
    token.kind = STRING;

    return token;
}
