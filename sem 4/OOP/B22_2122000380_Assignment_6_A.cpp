#include<iostream>
using namespace std;

class Money{

    private:
        double *amt;

    public :

        Money(double a = 0){
            this->amt = new double();
            *this->amt = a;
        }


        friend istream& operator>>(istream &in, Money &m);

        friend ostream& operator<<(ostream &out, const Money &m);


        ~Money(){
            delete(this->amt);
        }
};

istream& operator>>(istream &in, Money &m){
    in>>*m.amt;
    return in;
}

ostream& operator<<(ostream &out, const Money &m){
    out<<"The amount is "<<*m.amt<<endl;
    return out;
}

int main()
{
    Money* obj = new Money(); // created object using dynamic memory allocation
    Money* obj2 = new Money(57.2233); // created object using dynamic memory allocation with initial value of amt

    cout<<*obj; // default value for amt
    cout<<*obj2;

    cin>>*obj; // insert a value for amt

    cout<<*obj; // shows the value in amt

    
    delete(obj); // free the allocated memory to Money object calls the destructor
    return 0;
}