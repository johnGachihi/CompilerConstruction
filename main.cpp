#include <iostream>
#include <string>
#include "lexer.h"
using namespace std;

string tokenKindToString(TokenKind);

    /*
     * The lexical analyser created is for a simple hypothetical
     * language called JohnLang having the following kinds of tokens:
     *
     * |-------------------------------------------|
     * | integer literals   | eg, 1, 12, 123       |
     * |--------------------|----------------------|
     * | float literals     | eg, 1.2, 12.3, 123.4 |
     * |--------------------|----------------------|
     * | string literals    | eg, "a", "abcd"      |
     * |--------------------|----------------------|
     * | keywords           | const                |
     * |--------------------|----------------------|
     * | identifiers        | eg, a, abc, a1       |
     * |--------------------|----------------------|
     * | operators          | =                    |
     * |--------------------|----------------------|
     * | separators         | ;                    |
     * |-------------------------------------------|
     *
     * In the main() method below, the Lexical Analyser takes in a file
     * input stream for a file containing the following code:
     *      const a = 234;
     *      const a1 = "string";
     * It breaks down this code into JohnLang tokens and identifies
     * what kind of token each one is.
     * As output, the Lexical Analyser gives a list of tokens that may
     * be represented as follows;
     *
     * {
	 *      [const, keyword],
     *      [a, identifier],
     *      [=, operator],
     *      [234, integer],
     *      [;, separator],
     *      [const, keyword],
     *      [a1, identifier],
     *      [=, operator],
     *      ["string", string],
     * }
     *
     * The output contains a list of tokens as seen in the code and
     * the token type for each token.,
     */
int main() {
    fstream mFile("source.jg", ios_base::in | ios_base::out | ios_base::trunc);
    mFile << "const a = 234;\nconst a1 = \"string\"";
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
