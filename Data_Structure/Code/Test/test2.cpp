#include <iostream>
using namespace std;
class MyInt
{
private:
    int value;

public:
    MyInt() : value(0){};
    MyInt(int val) : value(val){};
    int set(int val);
    int get() const;
    MyInt operator+(const MyInt &sec) const;
    MyInt operator-(const MyInt &sec) const;
    MyInt operator*(const MyInt &sec) const;
    MyInt operator/(const MyInt &sec) const;
    MyInt operator-() const; // -i
    bool operator==(const MyInt &sec) const;
    bool operator!=(const MyInt &sec) const;
    bool operator<(const MyInt &sec) const;
    bool operator>(const MyInt &sec) const;
    MyInt operator++();    // ++i
    MyInt operator++(int); // i++
    MyInt operator--();    // --i
    MyInt operator--(int); // i--
    MyInt &operator+=(const MyInt &sec);
    MyInt &operator-=(const MyInt &sec);
    MyInt &operator*=(const MyInt &sec);
    MyInt &operator/=(const MyInt &sec);
};

int main()
{
    MyInt a;
    MyInt b;
    MyInt c;
    return 0;
}