// program implementing stack and its operations using template class.

#include <iostream>

using namespace std;


template <class T>
class Stack
{
    T* a;
    int top, MAX;
public:
    Stack(int n)
    {
        MAX= n;
        a= new T[MAX];
        top=-1;
    }
    void push(T ele)
    {
        if(top>=MAX-1)
            cout<<"Stack Overflow\n";
        else
        {
            a[++top]=ele;
            cout<<ele<<" is pushed into the stack\n";
        }
    }
    T pop()
    {
        if(isempty())
        {
            cout<<"Stack underflow\n";
            return NULL;
        }
        cout<<a[top]<<" is popped from the stack\n";
        return a[top--];
    }
    T peek()
    {
        if(isempty())
        {
            cout<<"Stack is empty\n";
            return NULL;
        }
        cout<<a[top]<<" is the top element\n";
        return a[top];
    }
    bool isempty()
    {
        return top<0;
    }
    int size()
    {
        return top+1;
    }
    void display()
    {
        if(isempty())
        {
            cout<<"Stack is empty\n";
            return ;
        }
        for(int i=0; i<=top; i++)
            cout<<"\t"<<a[i];
        cout<<endl;
    }
    ~Stack()
    {
        delete a;
    }
};

template<class type>
void stackOperation()
{
    int n,choice;
    type ele;
    cout<<"Enter the maximum size of the stack : ";
    cin>>n;
    Stack<type> s(n);
menu:
    cout<<"\nWhich operation do you want to perform?"<<endl
        <<"1: push"<<endl
        <<"2: pop"<<endl
        <<"3: peek"<<endl
        <<"4: size"<<endl
        <<"5: isempty"<<endl
        <<"6: display stack"<<endl
        <<"Any other : Exit"<<endl
        <<"Enter your choice : ";
    cin>>choice;
    cout<<endl;
    switch(choice)
    {
    case 1 :
        cout<<"Enter the element to push : ";
        cin>>ele;
        s.push(ele);
        break;
    case 2 :
        s.pop();
        break;
    case 3 :
        s.peek();
        break;
    case 4 :
        cout<<"The stack has "<<s.size()<<" elements\n";
        break;
    case 5 :
        cout<<"The stack is"<<((s.isempty())?"":" not")<<" empty\n";
        break;
    case 6 :
        cout<<"Stack elements : ";
        s.display();
        break;
    default :
        return;
    }
    goto menu;

}


int main()
{
    int type;
    char choice;
typeChoice:
    cout<<"Which type of stack do you want to create? \n1. Integer\n2. Floating Point\n3. Double Floating Point\n4. Character\nEnter your choice : ";
    cin>>type;
    switch(type)
    {
    case 1 :
        stackOperation<int>();
        break;
    case 2 :
        stackOperation<float>();
        break;
    case 3 :
        stackOperation<double>();
        break;
    case 4 :
        stackOperation<char>();
        break;
    default :
        cout<<"Invalid choice!!\n\n";
        goto typeChoice;
    }
    cout<<"\nDo you want to create another stack? (y/n) : ";
    cin>>choice;
    cout<<endl;
    if(choice== 'y')
        goto typeChoice;
    return 0;
}
