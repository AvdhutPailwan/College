#include<iostream>
#include<sstream>
#include<string>
using namespace std;

class Person{

	private:

		int id;

		string name;

	public:

		Person(int id=0,string name="blank"){
			this->id = id;
			this->name = name;
		}

		stringstream toString(){
			stringstream s;
			s<<"id = "<<id<<"\tname = "<<name;
			return s;
		}

};

int main()
{
	int i, j, id;
	i=j=0;
	
	string name;
	
	
	Person *obj[20];
	
	
	bool flag = true;
	
	while(flag)
	{
		cout<<"Enter the option     1.Create a Object	2.Display all objects 3.exit\n";
		int op;
		cin>>op;
		switch(op)
		{
		case 1:
			if(i >19)
			{
				cout<<"storage full!"<<endl;
			}else{
				cout<<"Enter id and name :"<<endl;
				cin>>id>>name;
				obj[i++] =new Person(id,name);
			}
			break;
		case 2:
			if(!i){
				cout<<"No object is created"<<endl;
			}else{
				for(j = 0; j<i; j++){
					cout<<"\n"<<obj[j]->toString().str()<<endl;
				}
			}
		
			break;
		case 3:
			flag = false;
			break;
		}
	}

	for(int j = 0; j<i; j++){
		delete(obj[j]);
	}
	return 0;
}
