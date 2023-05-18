#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Person
{

public:
    int id;

    string name;
};


int main()
{
    int choice=-1, len; // choice is for menu and len is for string length in Person obj -> name.

    bool keep_going = true; // condition for while loop to keep repeating menu until user wants to stop

    Person *obj = new Person(); // create a single Person object and reuse it until the end of the program

    // check if file containing the objects exists. if doesn't exist then create it.
    ifstream read_person("person.bin", ios::binary);
    ofstream write_person;

    if(read_person)
        write_person.open("person.bin", ios::app | ios::binary);
    else
        write_person.open("person.bin", ios::binary);

    write_person.close();
    read_person.close();
    // check ends here.


    // menu for the program
    while (keep_going)
    {
        cout<<"1. Create a Person\t2. Display all Person\t 3. Exit :\t";
        cin>>choice; // take the index of the menu option to perform that operation.

        switch (choice)
        {
        case 1:
            // take id and name of the person
            cout<<"\tid : ";
            cin>>obj->id;
            cout<<"\tname : ";
            cin.ignore();
            getline(cin, obj->name);

            // write the object into the file person.bin
            write_person.open("person.bin", ios::app | ios::binary); // open file in append mode to write
            write_person.write(reinterpret_cast<char*>(&obj->id), sizeof(int)); // write id of person
            len = obj->name.length(); // calculate length of the name
            write_person.write(reinterpret_cast<char*>(&len), sizeof(int)); // store length in person.bin
            write_person.write(obj->name.c_str(), len); // write the name of the person converting it to const char *
            write_person.close(); // close the file so the changes to the file will be saved immediately.
            

            break;
        case 2:
            read_person.open("person.bin", ios::binary); // open file in read mode

            // read the objects and display it.
            while(read_person.good()){
                read_person.read(reinterpret_cast<char*>(&obj->id), sizeof(int));
                if(!read_person) break; // condition so that last object won't be printed double.
                read_person.read(reinterpret_cast<char*>(&len), sizeof(int)); // retrive length of string name
                char buffer[len]; // create buffer of the name length
                read_person.read(buffer, len); // read name into the buffer.
                obj->name.assign(buffer,len); // set object name.
                cout<<"id : "<<obj->id<<endl<<"name : "<<obj->name<<endl; // display the object
            }
            read_person.close(); // close the file
            
            break;
        case 3:
            keep_going = false;
            break;
        default:
            cout<<"\nInvalid choice!\n";
            break;
        }
    }
    delete(obj); // free the allocated memory for the object.
    return 0;
}