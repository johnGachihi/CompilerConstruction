//
// Created by john-gachihi on 31/10/2020.
//

#include "lexer.h"

vector<Token> Lexer::getTokens(istream& in) {
    vector<Token> tokens;

    in.peek(); // When input stream is empty turn eof bit on
    while (! in.eof()) {
        char nextCh = (in >> ws).peek();
        if (isalpha(nextCh)) {
            Token string = readKeywordOrIdentifier(in);
            tokens.push_back(string);
        }
        else if (isdigit(nextCh)) {
            Token intOrFloat = readIntOrFloat(in);
            tokens.push_back(intOrFloat);
        }
        else if (nextCh == '"') {
            Token string = readString(in);
            tokens.push_back(string);
        }
        else if (isSeparator((char) nextCh)) {
            Token separator = readSeparator(in);
            tokens.push_back(separator);
        }
        else if (isOperator((char) nextCh)) {
            Token _operator = readOperator(in);
            tokens.push_back(_operator);
        }
        else {
            stringstream message;
            message << "Unknown symbol '" << nextCh << "'";
            throw UnknownSymbolException(message.str());
        }
    }

    return tokens;
}

Token Lexer::readKeywordOrIdentifier(istream& in) {
    Token token;

    char c;
    while(in.get(c)) {
        if (isalpha(c) || isdigit(c)) {
            token.token += c;
        } else {
            in.unget();
            break;
        }
    }

    if (token.token == "const") {
        token.kind = KEYWORD;
    } else {
        token.kind = IDENTIFIER;
    }

    return token;
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
            in.unget();
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

Token Lexer::readSeparator(istream& in) {
    Token token;
    token.kind = SEPARATOR;

    char c;
    while (in.get(c)) {
        if (c == ';') {
            token.token += c;
        }
        else {
            in.unget();
            break;
        }
    }

    return token;
}

bool Lexer::isSeparator(char c) {
    return c == ';';
}

Token Lexer::readOperator(istream& in) {
    Token token;
    token.kind = OPERATOR;

    char c;
    while (in.get(c)) {
        if (c == '=') {
            token.token += c;
        }
        else {
            in.unget();
            break;
        }
    }

    return token;
}

bool Lexer::isOperator(char c) {
    return c == '=';
}
