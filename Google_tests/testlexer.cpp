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

TEST(Lexer, Recognizes_identifier) {
    stringstream s;
    s << "abc123";
    s.flush();

    vector<Token> actual = Lexer::getTokens(s);
    Token expected = {"abc123", IDENTIFIER};

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

TEST(Lexer, Recognizes_separator) {
    stringstream s;
    s << ';';
    s.flush();

    vector<Token> actual = Lexer::getTokens(s);
    Token expected = {";", SEPARATOR};

    ASSERT_TRUE(actual.size() == 1);
    ASSERT_EQ(expected.token, actual[0].token);
    ASSERT_EQ(expected.kind, actual[0].kind);
}

TEST(Lexer, Identifies_operator) {
    stringstream s;
    s << '=';
    s.flush();

    vector<Token> actual = Lexer::getTokens(s);
    Token expected = {"=", OPERATOR};

    ASSERT_TRUE(actual.size() == 1);
    ASSERT_EQ(expected.token, actual[0].token);
    ASSERT_EQ(expected.kind, actual[0].kind);
}

TEST(Lexer, Throws_on_encountering_unrecognized_symbol) {
    stringstream s;
    s << '~';
    s.flush();

    try {
        Lexer::getTokens(s);
        FAIL();
    } catch (UnknownSymbolException& ex) {
        ASSERT_STREQ(ex.what(), "Unknown symbol '~'");
    } catch (exception $ex1) {
        FAIL();
    }
}

TEST(Lexer, Ignores_whitespace_and_newline) {
    stringstream s;
    s << "  \"abcd\n\"";
    s.flush();

    vector<Token> actual = Lexer::getTokens(s);
    Token expected = {"\"abcd\"", STRING};

    ASSERT_TRUE(actual.size() == 1);
    ASSERT_EQ(expected.token, actual[0].token);
    ASSERT_EQ(expected.kind, actual[0].kind);
}

TEST(Lexer, Recognizes_tokens_in_a_statment) {
    stringstream s;
    s << "\"abcd\" 123  const abcd";
    s.flush();

    vector<Token> actual = Lexer::getTokens(s);
    Token expected0 = {"\"abcd\"", STRING};
    Token expected1 = {"123", INTEGER};
    Token expected2 = {"const", KEYWORD};
    Token expected3 = {"abcd", IDENTIFIER};

    ASSERT_TRUE(actual.size() == 4);
    ASSERT_EQ(expected0.token, actual[0].token);
    ASSERT_EQ(expected0.kind, actual[0].kind);
    ASSERT_EQ(expected1.token, actual[1].token);
    ASSERT_EQ(expected1.kind, actual[1].kind);
    ASSERT_EQ(expected2.token, actual[2].token);
    ASSERT_EQ(expected2.kind, actual[2].kind);
    ASSERT_EQ(expected3.token, actual[3].token);
    ASSERT_EQ(expected3.kind, actual[3].kind);
}

TEST(Lexer, Recognizes_different_concatenated_tokens) {
    stringstream s;
    s << "120;abc=20";
    s.flush();

    vector<Token> actual = Lexer::getTokens(s);
    Token expected0 = {"120", INTEGER};
    Token expected1 = {";", SEPARATOR};
    Token expected2 = {"abc", IDENTIFIER};
    Token expected3 = {"=", OPERATOR};
    Token expected4 = {"20", INTEGER};

    ASSERT_EQ(actual.size(), 5);
    ASSERT_EQ(expected0.token, actual[0].token);
    ASSERT_EQ(expected0.kind, actual[0].kind);
    ASSERT_EQ(expected1.token, actual[1].token);
    ASSERT_EQ(expected1.kind, actual[1].kind);
    ASSERT_EQ(expected2.token, actual[2].token);
    ASSERT_EQ(expected2.kind, actual[2].kind);
    ASSERT_EQ(expected3.token, actual[3].token);
    ASSERT_EQ(expected3.kind, actual[3].kind);
    ASSERT_EQ(expected4.token, actual[4].token);
    ASSERT_EQ(expected4.kind, actual[4].kind);
}