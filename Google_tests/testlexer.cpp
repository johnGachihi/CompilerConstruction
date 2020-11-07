#include "gtest/gtest.h"
#include "../lexer.h"
#include <fstream>


TEST(Lexer, Recognizes_const_keyword) {
    stringstream s;
    s << "const";
    s.flush();

    vector<Token> actual = Lexer::getTokens(s);
    Token expected = {"const", KEYWORD};

    ASSERT_TRUE(actual.size() == 1);
    ASSERT_EQ(expected.token, actual[0].token);
    ASSERT_EQ(expected.kind, actual[0].kind);
}

TEST(Lexer, Recognizes_integer_literal) {
    stringstream s;
    s << 12345;
    s.flush();

    vector<Token> actual = Lexer::getTokens(s);
    Token expected = {"12345", INTEGER};

    ASSERT_TRUE(actual.size() == 1);
    ASSERT_EQ(expected.token, actual[0].token);
    ASSERT_EQ(expected.kind, actual[0].kind);
}

TEST(Lexer, Recognizes_float_literal) {
    stringstream s;
    s << 1.2345;
    s.flush();

    vector<Token> actual = Lexer::getTokens(s);
    Token expected = {"1.2345", FLOAT};

    ASSERT_TRUE(actual.size() == 1);
    ASSERT_EQ(expected.token, actual[0].token);
    ASSERT_EQ(expected.kind, actual[0].kind);
}

TEST(Lexer, Recognizes_string) {
    stringstream s;
    s << "\"abcd\"";
    s.flush();

    vector<Token> actual = Lexer::getTokens(s);
    Token expected = {"\"abcd\"", STRING};

    ASSERT_TRUE(actual.size() == 1);
    ASSERT_EQ(expected.token, actual[0].token);
    ASSERT_EQ(expected.kind, actual[0].kind);
}