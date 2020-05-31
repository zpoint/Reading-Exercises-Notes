//
// Created by zpoint on 2020/5/31.
//
#pragma once
#include <iostream>
#include "token.h"

class Lexer {
private:
    char a;
    std::string str;
public:
    std::string next() {
        str = "";
        while ((a = std::getchar()) != EOF)
        {
            if (a == ' ' or a == '\n')
            {
                if (str.size() > 0) {

                    return str;
                }
                else
                    continue;
            }
            str += a;
        }
        return "";
    }
};