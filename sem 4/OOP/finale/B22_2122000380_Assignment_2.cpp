#include<iostream>


using namespace std;

class Stack{

      private: 

               int top=-1;

               int array[10];

    public:

              int push(int); // push the value in the stack, return -1 if stack is full, return 1 if number is pushed in stack

              int pop(); // return the top value and decrement the top by 1, if stack is empty return -1;

             int peek();// return the top value of stack, if stack is empty return -1;

};

int Stack::push(int a){
	if(top == 9) 
		return -1;
	array[++top] = a;
	return 1;	
}

int Stack::pop(){
	if(top == -1)
		return -1;
	return array[top--];
}

int Stack::peek(){
	if(top == -1)
		return -1;
	return array[top];
}

int main()
{
	Stack obj;
	
	int flag = 1, temp;
	
	
	while(flag)
	{
		cout<<"1. Push an item on stack\n2. Pop item from stack\n3. Peek\n4. Stop\n	: ";
		int operation;
		cin>>operation;
		
		switch(operation)
		{
		case 1:
			cout<<"Enter the data to push on to the stack : ";
			cin>>temp;
			
			if(obj.push(temp) == -1)
				cout<<"\nstack overflow!\n"<<endl;
			else
				cout<<"\npush success!\n"<<endl;
			break;
		case 2:
			temp = obj.pop();
			if(temp == -1)
				cout<<"\nstack underflow!\n"<<endl;
			else
				cout<<endl<<temp<<" popped\n"<<endl;
			break;
		case 3:
			temp = obj.peek();
			if(temp == -1)
				cout<<"\nstack underflow!\n"<<endl;
			else
				cout<<endl<<temp<<endl;
			break;
		case 4:
			flag = 0;
			break;
		}
	}
	
	
	return 0;
}
