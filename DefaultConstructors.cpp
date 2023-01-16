#include <iostream>
using namespace std;

class Person {
private:
    string name{"xxxxx"};
    double balance;
public:
    Person()
    {
        cout << "no arg constructor " << name << endl;
    }
    Person(double balance)
    {
        cout << "arg with double " << name << endl;
    }
    ~Person()
    {

        cout << "Destructor called " << name << endl;
    }
    double get_balance(void)
    {
        return balance;
    }

    string get_name(void)
    {
        return name;
    }


};

// constructor over loading concept
class Person1 {
private:
    string name;
    double balance;
public:
    Person1()
    {
        cout << "no arg constructor " << name << endl;
    }
    Person1(string n, double b)
    {
        name = n;
        balance = b;
        cout << "arg with double " << name << endl;
    }
    ~Person1()
    {
        cout << "Destructor called " << name << endl;
    }
    double get_balance(void)
    {
        return balance;
    }
    string get_name(void)
    {
        return name;
    }


};
// Constructo Initialization list
class Person_2
{
    string name;
    double balance;
public :
    Person_2() :name{ "None"}, balance{0}
    {

    }
    Person_2 (string n, double b) :name{ n }, balance{ b }
    {

    }
    double get_balance(void)
    {
        return balance;
    }
    string get_name(void)
    {
        return name;
    }

};

// Delegating constructor

/* Instead of seperatley initializing each data memeber using differeny constructor i.e. passing different arguments
Initalize the list with all data memebers so that the initilization will be taken care by calling the differenct constructos 
*/
class Person_3
{
    string name;
    double balance;
public:
    Person_3() :Person_3{"None",0}
    {
        cout << "Inside the no arg constructor : Person_3" << endl;
    }
    Person_3(string n) :Person_3{ n,0}
    {
        cout << "Inside the one arg constructor :Person_3" << endl;
    }

    Person_3(string n, double b) :name{ n }, balance{ b }
    {
        cout << "Inside the two arg constructor :Person_3" << endl;
    }
    double get_balance(void)
    {
        return balance;
    }
    string get_name(void)
    {
        return name;
    }

};

// Default constructor with default paramater 

class Person_4
{
    string name;
    double balance;
public:
    Person_4(string n = "None", double b = 0);

    double get_balance(void)
    {
        return balance;
    }
    string get_name(void)
    {
        return name;
    }

};

Person_4 ::Person_4(string n, double b)
    :name{n},balance{b}
{
    cout << "Inside the Default constructor " << endl;
}
// Copy constructor with default paramater 

class Person_5
{
    string name;
    double balance;
public:
    Person_5()
    {
        cout << "Inside the default constructor:Player_5" << endl;
    }
    Person_5(const Person_5 &source);


    double get_balance(void)
    {
        return balance;
    }
    string get_name(void)
    {
        return name;
    }

};

// copy constructor

Person_5::Person_5(const Person_5& source)
    :name(source.name),balance(source.balance)
{
    cout << "Inside the copy constructor" << endl;

}

void display(Person_5 p)
{
    cout << "Name :" << p.get_name() << endl;
    cout << "Balance:" << p.get_balance() << endl;
}

class shallow {
    int* data;
public:
    void set_data(int d) {
        *data = d;
    }
    int get_data(void)
    {
        return *data;
    }
    shallow(int d){
        data = new int;
        *data = d;
        cout << "Insde the shallow  constructor" << endl;
    }
    shallow(const shallow& source);
    ~shallow()
    {
        cout << "Inside the shallow destructor" << endl;
        delete data;
    }
};
shallow::shallow(const shallow& source) : data(source.data ) {
    cout << "Inside the shallow cooy constructor" << endl;

}

void display(shallow p)
{
    cout << "Data :" << p.get_data() << endl;

}

class deep {
    int* data;
public:
    void set_data(int d) {
        *data = d;
    }
    int get_data(void)
    {
        return *data;
    }
    deep(int d) {
        data = new int;
        *data = d;
        cout << "Inside the deep  constructor" << endl;
    }
    deep(const deep& source);
    ~deep()
    {
        cout << "Inside the deep destructor" << endl;
        delete data;
    }

};

deep::deep(const deep& source) :deep{ *source.data } {
    cout << "Inside the deep copy constructor" << endl;
   // data = new int;
   // *data = *source.data;

}

void display_deep(deep p)
{
    cout << "Data :" << p.get_data() << endl;

}

class const_class {
    int data;
public:
    const_class(int d)
    {
        data = d;
    }
    int get_data() {
        return data;
    }
    int get_constdata ()const{
        return data;
    }
};

int main()
{
    {
        Person Frank;
    }
    {
        Person Joe(100.92);
        cout << "Balance is :" << Joe.get_balance() << endl;

    }
    cout << "*************************************************************" << endl;
    Person1 Joe{ "Joe",2.6 };
    cout << "Name is :" << Joe.get_name() << endl;
    cout << "Balance is :" << Joe.get_balance() << endl;
 //   Person1 Dim{ 3.6 };// problem is compilter does not know about the argument
    cout << "*************************************************************" << endl;
    Person_2 Jim;
    cout << "Name is :" << Jim.get_name() << endl;
    cout << "Balance is :" << Jim.get_balance() << endl;
    Person_2 Tim{"jim",12.5};
    cout << "Name is :" << Tim.get_name() << endl;
    cout << "Balance is :" << Tim.get_balance() << endl;
    cout << "*************************************************************" << endl;
    Person_3 Ginger;
    cout << "Name is :" << Ginger.get_name() << endl;
    cout << "Balance is :" << Ginger.get_balance() << endl;
    cout << "*************************************************************" << endl;
    Person_3 Toronto{ "Toronto" };
    cout << "Name is :" << Toronto.get_name() << endl;
    cout << "Balance is :" << Toronto.get_balance() << endl;

    Person_3 Tommy{ "Tommy",1058.0 };
    cout << "Name is :" << Tommy.get_name() << endl;
    cout << "Balance is :" << Tommy.get_balance() << endl;
    cout << "*************************************************************" << endl;
    Person_4 Delhi;
    cout << "Name is :" << Delhi.get_name() << endl;
    cout << "Balance is :" << Delhi.get_balance() << endl;


    Person_4 Gujarath{ "Gujarath" };
    cout << "Name is :" << Gujarath.get_name() << endl;
    cout << "Balance is :" << Gujarath.get_balance() << endl;
    //Person_4 Amristar{569.2};
    cout << "*************************************************************" << endl;
    cout << "Copy constructor Section" << endl;

    Person_5 empty;
    display(empty);

    Person_5 Jimmy(empty);

#if 0 // below shallow copy will cause windows error
    cout << "*************************************************************" << endl;
    shallow obj1(100);
    display(obj1);

    shallow obj2{ obj1 }; // Here the address of Obj1 and Obj2 are same due to shallow copy
    obj2.set_data(300);
    display(obj2);
#endif
    cout << "*************************************************************" << endl;
    deep obj1(100);
    display_deep(obj1);

    deep obj2{ obj1 }; // Here the address are different because of different location created during the copy constructor section.
    obj2.set_data(300);
    display_deep(obj2);

    cout << "**********************************************************************" << endl;
    const const_class obj(10);

    cout << obj.get_constdata() << endl;

  //  cout << obj.get_data() << endl; // This is not allowed becuase c++ treate this method can override the Obj.data 


    return 0;
}
