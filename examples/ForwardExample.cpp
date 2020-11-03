#include <iostream>
#include <functional>
#include <utility> 

/*
#move #forward #Variadic #Template
*/

// Проблематика
// Пускай у нас есть функция которая имеет параметр ссылочного типа.
// Если передавать в эту функцию r-value переменную то всё поламается см.Секцию 1
// И наоборот, для параметра r-value, передача аргумента l-value так же приведёт к ошибке
// Казалось бы в чём проблема пиши для каждого типа свою функцию, но это делать лень
// По этой причине была придумана такая вещь как Forward
int foo(int var){ 
    //to do smth with var
    return var * 10; 
};

int foo_lValue( int & var)
{
    //to do smth with var
    return var * 10; 
}

int foo_rValue( int && var)
{
    //to do smth with var
    return var * 10; 
}


//TODO тут надо что-то написать про преобразование типов ссылок из && в &, и обратные метаморфозы

// Собственно нашу задачу можно сделать используя шаблоны
template<typename Funk, typename T>
T r_to_l_hack(Funk func, T && r_value){
    return func( std::forward<T>(r_value));
}

template <typename Funk, typename...Args>
auto apply( Funk funk, Args && ... args) -> decltype(funk( std::forward<Args>(args)... ))
{
    return funk( std::forward<Args>(args)... );
}

static int _main(int argc, char **argv)
{
    /* //СЕКЦИЯ 1
    {
        int var = 1;
        foo_lValue(var);   // OK
        foo_lValue(1);     // NOT OK

        foo_rValue(var);   // NOT OK
        foo_rValue(1);     // OK
       
        //Так же можно передавать лямбды
        //auto foo = [](int x){ return x * 10; };
        r_to_l_hack(foo, 2);            // int &r_to_l_hack < int (*)(int var),   int & > (int (*func)(int var),   int &  r_value)
        r_to_l_hack(foo, var);          // int &r_to_l_hack < int (*)(int var),   int & > (int (*func)(int var),   int &  r_value)
        r_to_l_hack(foo_lValue, 2);     // int r_to_l_hack  < int (*)(int &var),  int   > (int (*func)(int &var),  int && r_value)
        r_to_l_hack(foo_lValue, var);   // int &r_to_l_hack < int (*)(int &var),  int & > (int (*func)(int &var),  int &  r_value)
        r_to_l_hack(foo_rValue, 2);     // int r_to_l_hack  < int (*)(int &&var), int   > (int (*func)(int &&var), int && r_value)
        r_to_l_hack(foo_rValue, var);   // int &r_to_l_hack < int (*)(int &&var), int & > (int (*func)(int &&var), int &  r_value)
    }
    */


    auto fun = [](std::string a, std::string const &b) { return a += b; };

    std::string s("world!");

    // s передаётся по lvalue ссылке,
    // а временный объект по rvalue ссылке
    s = apply(fun, std::string("s"), s);

    return EXIT_SUCCESS;
}