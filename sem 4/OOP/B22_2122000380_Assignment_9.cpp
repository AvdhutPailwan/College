#include <iostream>
#include <cstring>
using namespace std;

template <typename T>
class Stack
{
private:
    int size; // size of the stack
    // SYB22 Avdhut Pailwan
public:
    int top; // top of the stack
    T *arr; // a pointer to create dynamic array for stack

    // exception to throw for the for underflow and overflow
    // SYB22 Avdhut Pailwan
    class Underflow
    {
    };
    class Overflow
    {
    };

    // constructor call
    // set top = -1, size = 0
    Stack() : top(-1), size(0) {}

    // push
    // SYB22 Avdhut Pailwan
    void push(T value)
    {
        // determine to allocate new memory or just reallocate the existing memory
        if (!size)
        {
            arr = (T *)malloc(sizeof(T));
            size++;
        }
        else
            arr = (T *)realloc(arr, sizeof(T) * (++size));

        // throw the exception
        if (arr == NULL)
            throw Overflow();

        // push operation
        arr[++top] = value;
    }

    // pop
    // SYB22 Avdhut Pailwan
    T pop()
    {
        // can't actually free memory directly for the certain index and even if we realloc the memory it 
        // contains the data
        T *temp = (T *)malloc(sizeof(T) * (--size));

        //throw the exception
        if (temp == NULL)
            throw Underflow();

        // SYB22 Avdhut Pailwan
        memcpy(temp, arr, sizeof(T) * size);

        T temp2 = arr[top--]; // popped element

        // resizing stack
        free(arr);
        arr = (T *)malloc(sizeof(T) * size);
        memcpy(arr, temp, sizeof(T) * size);
        free(temp);

        return temp2;
    }

    T peek()
    {
        if (arr == NULL)
            throw Underflow();

        return arr[top];
    }

    int getSize(){
        return size;
    }

    ~Stack()
    {
        free(arr);
    }
};

int main()
{
    Stack<int> obj; // SYB22 Avdhut Pailwan
    try
    {
        for (int i = 0; i < 10; i++)
        {
            obj.push(i + 1);
            cout << "pushed : " << obj.peek() << "\tsize : " << obj.getSize() << endl;
        }

        for (int i = 0; i < 11; i++)
        {
            cout << "popped : " << obj.pop() << "\tsize : " << obj.getSize() << endl;
        }
    }
    catch (Stack<int>::Overflow)
    {
        cout << "Stack Overflow!" << endl;
    }
    catch (Stack<int>::Underflow)
    {
        cout << "Stack Underflow!" << endl;
    }

    return 0;
}