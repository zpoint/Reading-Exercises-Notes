//
// Created by zpoint on 2020/5/31.
//

#ifndef COMPILERS_AST_H
#define COMPILERS_AST_H


namespace ast {
    enum NodeType {
        DECLARE, // LEFT, RIGHT = nullptr
        ADD, // SUB
        MUL, // DIV
        INT, // int val
        ASSIGN // LEFT = RIGHT
    };

    class ASTNode {
    private:
        class ASTNode* left;
        class ASTNode* right;
        int val;
        enum NodeType type;
    public:
        ASTNode(enum NodeType type_, ASTNode* left_, ASTNode* right_): type(type_), left(left_), right(right_) { }
        ASTNode(int value): val(value),  type(INT) { }

    };
}



#endif //COMPILERS_AST_H
