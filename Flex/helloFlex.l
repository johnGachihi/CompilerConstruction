%option C++ noyywrap

%{
#include <vector>
#include <string>

struct Token {
    std::string token;
    std::string kind;
};

std::vector<Token> tokens;
%}

keyword const|let
identifier [a-zA-Z]+[0-9]*
string	\"[^\n"]+\"
integer [0-9]+
float [0-9]*\.[0-9]+
operator =|==|>
separator ;

%%

\n
{keyword}       tokens.push_back({YYText(), "keyword"});
{identifier}    tokens.push_back({YYText(), "identifier"});
{string}        tokens.push_back({YYText(), "string"});
{operator}      tokens.push_back({YYText(), "operator"});
{integer}       tokens.push_back({YYText(), "integer"});
{float}         tokens.push_back({YYText(), "float"});
{separator}     tokens.push_back({YYText(), "separator"});

%%

int main( int /* argc */, char** /* argv */ )
{
	FlexLexer* lexer = new yyFlexLexer;
	lexer->yylex();

    // Print tokens
    std::cout << "[" << std::endl;
	for (auto& token : tokens) {
	    std::cout << "\t[" << token.token << ", " << token.kind << "]" << std::endl;
	}
    std::cout << "]" << std::endl;
	return 0;
}