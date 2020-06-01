//
// Created by zpoint on 2020/5/31.
//

#ifndef COMPILERS_PARSER_H
#define COMPILERS_PARSER_H
#include "token.h"
#include "ast.h"

class Parser {
private:
    tokens = token::Tokens();

public:
    ast::ASTNode *match_multiplication() {

    }

    ast::ASTNode *match_addictive() {

    }

    ast::ASTNode *parse(const std::string& line) {
        tokens.setStr(line);
        tokens.read();
        if (tokens.peek().getType() == token::INT_KEYWORD) {
            // intDeclaration : 'int' Id ( = additive) ';'

        }
        matchIntDeclaration();

    }
};


#endif //COMPILERS_PARSER_H
