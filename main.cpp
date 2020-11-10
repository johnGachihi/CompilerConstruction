#include <iostream>
#include <fstream>
#include <string>
#include "lexer.h"
using namespace std;

string tokenKindToString(TokenKind);

int main() {
    fstream mFile("sample.txt", ios_base::in | ios_base::out | ios_base::trunc);
    mFile << "const a = 234;";
    mFile.seekg(0);

    vector<Token> tokens = Lexer::getTokens(mFile);
    cout << '{' << endl;
    for (auto & token : tokens) {
        cout << "\t[" << token.token << ", " << tokenKindToString(token.kind) << "]," << endl;
    }
    cout << '}' << endl;

    mFile.close();
}

string tokenKindToString(TokenKind kind) {
    switch (kind) {
        case STRING: return "string";
        case KEYWORD: return "keyword";
        case INTEGER: return "integer";
        case FLOAT: return "float";
        case IDENTIFIER: return "identifier";
        case SEPARATOR: return "separator";
        case OPERATOR: return "operator";
    }
}
