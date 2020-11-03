#pragma once
#include <cassert>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using std::string;
using std::cin;
using std::vector;

struct Token
{
    string value;
    enum tokenKind{
        CMD,    // SELECT, INSERT, DELETE, SORT_BY
        FILD,   // assotiative name of filds, keepd in ""
        SOURCE, // name of file where saved data, leed after
        EXPR,    // expression
        NONE
    } kind;

    Token() = default;
    Token(string _value, tokenKind _kind) : value(_value), kind(_kind){}
};


class TokenStream
{
private:
    bool full {false};
    Token buffer;
    vector<string> cmdList;
    static Token::tokenKind nextFild ;
public:
    TokenStream(): full {false} { nextFild = Token::CMD;
        cmdList.push_back("SELECT");
        cmdList.push_back("INSERT");
        cmdList.push_back("DELETE");
        cmdList.push_back("SORT_BY");
    };
    ~TokenStream() {};

    Token get(){
        if(full){
            full = false;
            return buffer;
        }

        string charset;
        switch (nextFild)
        {
        case Token::CMD:
            cin >> charset;
            std::transform(charset.begin(), charset.end(), charset.begin(), [](auto c) { return std::toupper(c); });

            if (std::none_of(cmdList.cbegin(), cmdList.cend(), [&charset](auto i){ return charset == i; })) {
                std::cerr << "ERROR! INCORRECT EXPRESSION IN WORD " << charset << std::endl;
                cin.clear();
                nextFild = Token::CMD;
                return Token("", Token::NONE);
            }

            return Token(charset, Token::CMD);
            break;

        case Token::FILD:
            char ch;
            cin >> ch;
            if (ch == '"')
            do{
                cin >> ch;
                charset += ch;
            }while(ch != '"');
            return Token(charset, Token::FILD);
            break;

        case Token::SOURCE:
            break;
        case Token::EXPR:
            break;

        default:
            break;
        }
        return Token("", Token::NONE);
       /* switch (ch)
        {
        case '"':
            cin.putback(ch);
            cin >> charset;
            return Token(charset, Token::tokenKind::FILD);
            break;
        
        default:
            cin >> charset;
            std::transform(charset.begin(), charset.end(), charset.begin(), [](auto c) { return std::toupper(c); });
            break;
        }*/
    }


    void putback(Token t){
        assert(full && "Attempt to owerride full buffer");
        buffer = t;
        full = true;
    }
};
