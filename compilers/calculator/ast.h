//
// Created by zpoint on 2020/5/31.
//

#ifndef COMPILERS_AST_H
#define COMPILERS_AST_H
#include <iostream>

enum AST_TYPE {
    addictive,
    multiplication,
    IntLiteral
};

class AST {
private:
    class AST* left;
    class AST* right;
    enum AST_TYPE type;
    int int_val;
public:
    void traverse(const std::string prefix=std::string(""));
    AST(enum AST_TYPE type_, AST* left_, AST* right_): type(type_), left(left_), right(right_) { }
    AST(int int_value): type(IntLiteral), int_val(int_value) { }
    const enum AST_TYPE getType() {
        return type;
    }
};

void AST::traverse(const std::string prefix) {
    if (type == addictive || type == multiplication) {
        std::cout << (prefix + (type == addictive ? "addictive" : "multiplication")) << std::endl;
        left->traverse(prefix+"\t");
        right->traverse(prefix+"\t");
    }
    else {
        std::cout << prefix << "IntLiteral: " << int_val << std::endl;
    }
}

#endif //COMPILERS_AST_H
