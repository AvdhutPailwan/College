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
        return Money(++this->amt);
    }

    // post-increament
    Money operator++(int)
    {
        return Money(this->amt++);
    }

    // pre-decreament
    Money operator--()
    {
        return Money(--this->amt);
    }

    // post-decreament
    Money operator--(int)
    {
        return Money(this->amt--);
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

    cout<<"initial values of m = "<<m.getAmt()<<", n = "<<n.getAmt()<<", k = "<<k.getAmt()<<endl;

    m = ++m + n--;
    cout<<"The value of the equation m = ++m + n-- is "<<m.getAmt()<<endl; // (++m --> 1) + (n-- --> 2000) = 2001
    cout<<"The value of n has become "<<n.getAmt()<<endl; // n --> 1999 due to post-decreament in previous operation
    m = m/n;
    cout<<"The value of the equation m = m/n is "<<m.getAmt()<<endl; // m --> 1.001
    m = m*k++;
    cout<<"The value of the equation m = m*k++ is "<<m.getAmt()<<endl; // 1.001 * 2000 = 2002 after that k --> 2001
    cout<<"The value of k after previous operation is "<<k.getAmt()<<endl; 
    cout<<"The value of --k is "<<(--k).getAmt()<<endl; // 2000
    m = m-n;
    cout<<"The value of m = m - n is "<<m.getAmt()<<endl; // 3.001
    return 0;
}