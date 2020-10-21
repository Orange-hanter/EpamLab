#include <ostream>
#include <typeinfo>
#include <utility>
#include <functional>

template <class T>
struct Array
{
    // все объявленные ниже методы уже реализованы
    explicit Array(size_t size = 0)
    {
        data_ = new T[size];
        size_ = size;
    };
    Array(Array const &a) = default;
    Array &operator=(Array const &a);
    ~Array() { delete[] data_; };

    size_t size() const { return size_; };
    T &operator[](size_t i) { return data_[i]; };
    T const &operator[](size_t i) const { return data_[i]; };

    void swap(Array &obj)
    {
        std::swap(data_, obj.data_);
        std::swap(size_, obj.size_);
    }

    // реализуйте перемещающий конструктор
    Array(Array &&obj) : Array()
    {
        swap(obj);
    }
    // реализуйте перемещающий оператор присваивания
    Array &operator=(Array &&obj)
    {

        Array::swap(obj);
        return *this;
    }

private:
    size_t size_;
    T *data_;
};

#include <tuple>
// принимает std::tuple произвольного размера
template <int Pos1, int Pos2, class T>
auto to_pair(std::tuple<int, double, char const *> t) -> decltype(std::make_pair(std::get<Pos1>(t), std::get<Pos2>(t)))
{
    decltype(std::get<Pos1>(t)) par1 = std::get<Pos1>(t);
    decltype(std::get<Pos2>(t)) par2 = std::get<Pos2>(t);
    auto res = std::pair<decltype(par1), decltype(par2)>(par1, par2);
    return res;
}

template <int Pos1, int Pos2, class T>
auto to_pair(T t) -> decltype(std::make_pair(std::get<Pos1>(t), std::get<Pos2>(t)))
{
    decltype(std::get<Pos1>(t)) par1 = std::get<Pos1>(t);
    decltype(std::get<Pos2>(t)) par2 = std::get<Pos2>(t);
    auto res = std::pair<decltype(par1), decltype(par2)>(par1, par2);
    return res;
}

// определение структуры Point уже подключено
struct Point
{
    constexpr Point(double x, double y)
        : x(x), y(y)
    {
    }

    double x = 0;
    double y = 0;
};

// сложение
constexpr Point operator+(const Point & lOp,const Point & rOp)
{
    return Point( lOp.x + rOp.x,  lOp.y + rOp.y);
}

// вычитание
constexpr Point operator-(const Point & lOp,const Point & rOp)
{
    return Point( lOp.x - rOp.x,  lOp.y - rOp.y);
}

// скалярное произведение
constexpr double operator*(const Point & lOp,const Point & rOp)
{
    return  lOp.x * rOp.x + lOp.y * rOp.y;
}






template<class F>
void for_each_int(int * p, int * q, F f)
{
    for ( ; p != q; ++p )
        f(*p);
}

int main(int argc, char const *argv[])
{
    int m[10] = {1,2,3,4,5,6,7,8,9,10};

    constexpr auto square_fun = [](int& num){ num *= num; };
    for_each_int(m, m + 10, square_fun); // теперь m = {1,4,9,16,25,36,49,64,81,100};
    std::cout << *m;

}
