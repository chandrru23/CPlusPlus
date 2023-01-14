#include <iostream>
using namespace std;

class Person{
    private:
    string name;
    double balance;
    public:
    Person ()
    {
        cout<<"no arg constructor"<<name<<endl;
    }
    Person(double balance)
    {
        cout<<"arg with double"<<name<<endl;
    }
    ~Person()
    {
        cout<<"Destructor called"<<name<<endl;
    }
    double get_balance(void)
    {
        return balance;
    }


};

// constructor over loading concept
class Person1{
    private:
    string name;
    double balance;
    public:
    Person1 ()
    {
        cout<<"no arg constructor"<<name<<endl;
    }
    Person1(string n,double b)
    {
        name=n;
        balance=b;
        cout<<"arg with double"<<name<<endl;
    }
    ~Person1()
    {
        cout<<"Destructor called"<<name<<endl;
    }
    double get_balance(void)
    {
        return balance;
    }


};

int main()
{
    {
    Person Frank;
    }
    {
        Person Joe(100.92);
        cout<<"Balance is :"<<Joe.get_balance()<<endl;

    }

    Person1 Joe{"Joe",2.6};
    Person1 Dim{3.6};
    return 0;
}
