#include<iostream>
using namespace std;

class INR{	
    private:
		float rupees;

	public:

		INR(){}

		INR(float amount):rupees(amount){}
        
		operator float(){
			return rupees;
		}

        float getRupee(){
            return this->rupees;
        }

        friend istream& operator>>(istream &in, INR &m);

        friend ostream& operator<<(ostream &out, const INR &m);

        ~INR(){}		
};

istream& operator>>(istream &in, INR &m){
    in>>m.rupees;
    return in;
}

ostream& operator<<(ostream &out, const INR &m){
    out<<m.rupees;
    return out;
}

class USD{
    private:
		float dollar;

	public:		

		USD(){}

		USD(INR indianCurrency):dollar(indianCurrency.getRupee()/82.03){}

		operator INR(){
			INR temp(dollar*82.03);
			return temp;
		}

        float getDollar(){
            return this->dollar;
        }
        
        friend istream& operator>>(istream &in, USD &m);

        friend ostream& operator<<(ostream &out, const USD &m);

        ~USD(){}
};

istream& operator>>(istream &in, USD &m){
    in>>m.dollar;
    return in;
}

ostream& operator<<(ostream &out, const USD &m){
    out<<m.dollar;
    return out;
}

int main()
{
    float amount = 123.50f;
	cout<<"Amount = 123.50"<<endl;
	
	INR India = amount;			// float to INR
	cout<<"Float to INR : "<<"Rupees = "<<India<<endl;
	
	float amount2 = India;		// INR to float
	cout<<"INR to float : Amount = "<<amount2<<endl;
	
	USD USA = India;			// INR to USD
	cout<<"123.50 INR to USD : "<<USA<<endl;

    INR India2 = USA;			//USD to INR
	cout<<"1.50555 USD to INR : "<<"Rupees = "<<India<<endl;
    return 0;
}