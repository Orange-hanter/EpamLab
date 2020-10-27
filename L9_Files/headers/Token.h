#pragma once
#include <cassert>
#include <iostream>
#include <string>

using std::string;
using std::cin;


struct Token
{
    char kind;
    string value;
};

Token::Token(/* args */)
{
}

Token::~Token()
{
}


class TokenStream
{
private:
    bool full {false};
    Token buffer;
public:
    TokenStream() = default;
    ~TokenStream() {};

    Token get(){
        if(full){
            full = false;
            return buffer;
        }

        char ch;
        cin >> ch;
        switch (ch)
        {
        case ';':
            /* exit case */
            break;
        
        default:
            break;
        }
    }


    void putback(Token t){
        assert(full && "Attempt to owerride full buffer");
        buffer = t;
        full = true;
    }
};

