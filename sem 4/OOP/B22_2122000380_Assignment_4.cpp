#include<iostream>
#include<sstream>
#include<string>
using namespace std;

class Person{

	private:
		int id;

		string name;

	public:
		static int count;
		Person(string name="blank"){
			id = count++;
			this->name = name;
		}

		stringstream toString(){
			stringstream s;
			s<<"id = "<<id<<"\tname = "<<name;
			return s;
		}

};

int Person::count = 1;


class Student:public Person{

        private:

              int fees;

        public:

              Student(string name="blank",int fees = -1):Person(name)
              {
                        this->fees = fees;
              }

              stringstream toString()
              {
                        stringstream s = Person::toString();
                        s<<"\tfees = Rs. "<<fees;
                        return s;
              }

};





int main()
{
	int i, j, size,   fees;
	i=j=size=0;
	
	string name;
	
	
	Student *obj[20];
	
	
	bool flag = true;
	
	while(flag)
	{
		cout<<"\nEnter the option	1.Create a Student Object	2.Display all Student Objects 3.exit\n";
		int op;
		cin>>op;
		switch(op)
		{
		case 1:
			if(size >19)
			{
				cout<<"storage full!"<<endl;
			}else{
				cout<<"Enter name and fees :"<<endl;
				cin>>name>>fees;
				 obj[i++] = new Student(name, fees);
				size++;
			}
			break;
		case 2:
			if(!size){
				cout<<"No object is created"<<endl;
			}else{
				for(j = 0; j<size; j++){
					cout<<"\n"<<obj[j]->toString().str()<<endl;
				}
			}
		
			break;
		case 3:
			flag = false;
			break;
		}
	}
	return 0;
}
