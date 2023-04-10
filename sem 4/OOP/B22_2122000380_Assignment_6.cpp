#include <iostream>
using namespace std;

class Money
{

private:
    double amt;

public:
    // default constructor
    Money()
    {
        this->amt = 0;
    }

    // constructor with 1 argument
    Money(double a)
    {
        this->amt = a;
    }


    // copy constructor
    Money(Money &a)
    {
        this->amt = a.getAmt();
    }


    // pre-increament
    Money operator++()
    {
        ++this->amt;
        return *this;
    }

    // post-increament
    Money operator++(int)
    {
        this->amt++;
        return *this;
    }

    // pre-decreament
    Money operator--()
    {
        --this->amt;
        return *this;
    }

    // post-decreament
    Money operator--(int)
    {
        this->amt--;
        return *this;
    }

    // addition
    Money operator+ (Money a)
    {
        this->amt = this->amt + a.getAmt();
        return *this;
    }

    // subtraction
    Money operator- (Money a)
    {
        this->amt = this->amt - a.getAmt();
        return *this;
    }

    // multiplication
    Money operator* (Money a)
    {
        this->amt = this->amt * a.getAmt();
        return *this;
    }

    // division
    Money operator/ (Money a)
    {
        this->amt = this->amt / a.getAmt();
        return *this;
    }

    void setAmt(double a)
    {
        this->amt = a;
    }

    double getAmt()
    {
        return this->amt;
    }
};


int main()
{
    Money m;        // call with default constructor
    Money n(2000);  // call with parameterized constructor
    Money k = n;    // calling the copy constructor same as ---> Money k(n);

    m = ++m + n--;
    cout<<"The value of the equation m = ++m + n-- is "<<m.getAmt()<<endl; // ++m --> 1 + n-- --> 2000 = 2001
    cout<<"The value of n has become "<<n.getAmt()<<endl; // n --> 1999 due to post-decreament in previous operation
    m = m/n;
    cout<<"The value of the equation m = m/n is "<<m.getAmt()<<endl; // m --> 1.001
    m = m*k++;
    cout<<"The value of the equation m = m*k++ is "<<m.getAmt()<<endl; // 
    cout<<"The value of k after previous operation is "<<k.getAmt()<<endl; // 
    return 0;
}