//
// Created by zpoint on 2020/5/31.
//

#ifndef COMPILERS_TOKEN_H
#define COMPILERS_TOKEN_H
#include <iostream>

namespace token {
    enum TOKEN {
        INT_KEYWORD,
        INT_LITERAL,
        PLUS,
        MINUS,
        MULTIPLE,
        DIVIDE,
        ASSIGN,
        IDENTIFIER,
        EOF
    };

    class token {
        private:
            enum TOKEN t;
            std::string t_str;
            int value;

        public:
            token(enum TOKEN type, const std::string& str_token): t(type), str_token(t_str) {
                if (type == INT_LITERAL) value = std::stoi(token_str.c_str());
            }
            enum TOKEN getType() { return t; }
            const std::string& getStr() { return t_str; }
            const int getValue() { return value; }
    };

    class Tokens {
        private:
            char c;
            token tk;
            std::istringstream iss;

        public:
            void setStr(const std::string &s) {
                iss.str(s);
            }

            void read() {
                std::string local_token = "";
                bool is_digit = true;
                while (iss.get(c)) {
                    while (c == '\n' || c == ' ') {
                        if (!iss.get(c)) {
                            tk = token::token(token::EOF, local_token);
                        }
                    }
                    if (c == '\n' || c == ' ' || c == ';') break;
                    local_token += c;
                    if (!std::isdigit(c)) is_digit = false;
                    if (c == '+' || c == '-' || c == '*' || c == '/') break;
                }
                if (!local_token) tk = token::token(token::EOF, local_token);
                else if (local_token == "int") { tk = token::token(token::INT_KEYWORD, local_token); }
                else if (is_digit) { tk = token::token(token::INT_LITERAL, local_token); }
                else if (local_token == "+") { tk = token::token(token::PLUS, local_token); }
                else if (local_token == "-") { tk = token::token(token::MINUS, local_token); }
                else if (local_token == "*") { tk = token::token(token::MULTIPLE, local_token); }
                else if (local_token == "/") { tk = token::token(token::DIVIDE, local_token); }
                else tk = token::token(token::IDENTIFIER, local_token);
            }

            token peek() {
                return tk;
            }
    };
}

#endif //COMPILERS_TOKEN_H
