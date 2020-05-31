//
// Created by zpoint on 2020/5/31.
//

#include "ast.h"
#include "token.cpp"

//
// Created by zpoint on 2020/5/30.
//
class Constructor {
private:
    Tokens tokens;

    AST* match_intliteral() {
        const Token t = tokens.read();
        if (t.getType() == INT) {
            AST* node = new AST(t.getInt());
            tokens.consume();
            return node;
        }
        else {
            std::cerr << "expect intliteral, got: " << t.getStr() << std::endl;
            throw std::runtime_error("error");
        }
    }

    AST* match_multiplication() {
        AST* left = match_intliteral();
        if (tokens.peek().getType() == STARS) {
            tokens.consume();
            AST* right = match_multiplication();
            return new AST(multiplication, left, right);
        }
        return left;
    }

    AST* match_addictive() {
        AST* left = match_multiplication();
        if (tokens.peek().getType() == PLUS) {
            tokens.consume();
            AST* right = match_addictive();
            return new AST(addictive, left, right);
        }
        return left;
    }

public:
    AST* construct() {
        return match_addictive();
    };
};

int main() {
    Constructor c;
    AST* root = c.construct();
    root->traverse();
}
