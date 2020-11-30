#pragma once
#include "PCH.h"


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

/*
SELECT param0[,param_N] SORURCE param WHERE expr1[, expr2, ...]
*/
class TokenStream{

private:
    bool full {false};
    Token buffer;
    vector<string> cmdList;
    static Token::tokenKind nextFild ;

public:
    TokenStream(): full {false} { 
        nextFild = Token::CMD;
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

        string lexem;
        /*
        switch (nextFild)
        {
            case Token::CMD:
                 lexem = getLexem();
                auto funk([&lexem](auto i){ return lexem == i; } );
                if (std::none_of(cmdList.cbegin(), cmdList.cend(), funk)) {
                    std::cerr << "ERROR! INCORRECT EXPRESSION IN WORD " 
                                << lexem 
                                << std::endl;
                    cin.clear();
                    nextFild = Token::CMD;
                    return Token("", Token::NONE);
                }

                if (lexem == "SELECT" )
                    nextFild = Token::FILD;
                else if (lexem == "SORT_BY")
                    nextFild = Token::EXPR;
                else if (lexem == "SELECT" )

                return Token(lexem, Token::CMD);
                break;

            case Token::FILD:
                lexem = getLexem();
                return Token(lexem, Token::FILD);
                break;

            case Token::SOURCE:
                break;
            case Token::EXPR:
                break;

            default:
                break;
        }
        */
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
    
private:
    string filterPunctuation(const string &s){
        const char* forbiden {", "};
        //TODO not separated cases like "select name,age from db where name > 0"
        const auto idx_start(s.find_first_not_of(forbiden));
        const auto idx_end(s.find_last_not_of(forbiden));
        return s.substr(idx_start, idx_end - idx_start + 1 );
    }

    string getLexem(){
        string charset;
        cin >> charset;
        std::transform(charset.begin(), charset.end(), charset.begin(), [](auto c) { return std::toupper(c); });

    }
};
