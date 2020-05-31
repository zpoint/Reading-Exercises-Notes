//
// Created by zpoint on 2020/5/31.
//
#pragma once
#include "lexer.h"
#include "token.h"

class Token {
private:
    std::string token_str;
    int int_val;
    enum TOKEN token;

    void dispatch() {
        if (token_str == "+") {
            token = PLUS;
        }
        else if (token_str == "-") {
            token = MINUS;
        }
        else if (token_str == "*") {
            token = STARS;
        }
        else if (token_str == "") {
            token = MY_EOF;
        }
        else {
                token = INT;
                int_val = std::stoi(token_str.c_str());
        }
    }

public:
    Token() = default;
    Token(const enum TOKEN t, const std::string &ts): token_str(ts) {dispatch();}

    const enum TOKEN getType() const {
        return token;
    }

    const std::string& getStr() const {
        return token_str;
    }

    const int getInt() const {
        return int_val;
    }

    bool setValue(const std::string &ts) {
        token_str = ts;
        dispatch();
        return true;
    }
};

class Tokens {
private:
    Lexer my_lexer;
    Token token;
    std::istream &is = std::cin;

public:
    Tokens () {consume();}

    void consume() {
        token.setValue(my_lexer.next());
    }

    const Token& peek() {
        return token;
    }

    const Token& read() {
        return token;
    }
};