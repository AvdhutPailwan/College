#include<bits/stdc++.h>
using namespace std;

class Car
{
  private:
    int speed;
  public:
    Car()
    {
      this->speed = 0;
    }
    Car(int s)
    {
      this->speed = s;
    }
    Car operator++()
    {
      return Car(++this->speed);
    }

    Car operator++(int)
    {
      return Car(this->speed++);
    }

    Car operator--()
    {
      return Car(--this->speed);
    }

    Car operator--(int)
    {
      return Car(this->speed--);
    }

    int getSpeed()
    {
      return speed;
    }

    void setSpeed(int s)
    {
      this->speed = s;
    }
    
};

int main()
{
  Car honda;

  int s, op, temp;
  bool flag = true;

  while(flag)
  {
    cout<<"Enter the operation :\n1. current speed\t2. pre-increament speed\t3. post-increament speed\t4. pre-decreament speed\t5. post-decrement speed\t6. set speed\t 7. exit\n";
    cin>>op;
    switch (op)
    {
    case 1:
      cout<<endl<<"current speed : "<<honda.getSpeed()<<endl<<endl;
      break;
    case 2:
      cout<<endl<<"pre-increamented speed : "<<(++honda).getSpeed()<<endl;
      break;
    case 3:
      cout<<endl<<"post-increamented speed : "<<(honda++).getSpeed()<<endl;
      break;
    case 4:
      cout<<endl<<"pre-decreamented speed : "<<(--honda).getSpeed()<<endl<<endl;
      break;
    case 5:
      cout<<endl<<"post-decreameanted speed : "<<(honda--).getSpeed()<<endl<<endl;
      break;
    case 6:
      cout<<"Enter speed : ";
      cin>>temp;
      honda.setSpeed(temp);
      cout<<endl<<"speed set to: "<<honda.getSpeed()<<endl<<endl;
      break;
    case 7:
      flag = false;
      break;
    
    default:
      cout<<endl<<"invalid operation!"<<endl<<endl;
      break;
    }
  }

  

  return 0;
}