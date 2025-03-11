#include <iostream>
#include <string>

using namespace std;

class Person
{
    private:
        int numberkill;
    public:
        //  Constructor   ham khoi tao
        Person(){};
        Person(string _name, string _address,int _age,bool _sex){
            name = _name;
            address = _address;
            age = _age;
            sex = _sex;
        };

        // properties
        string name;
        string address;
        int age;
        bool sex;

        // method
        void work(){
            cout << name << "is working so hard at " << address << endl;
        }
};


int main(){
    Person person1;
    person1.name = "Phan Van An";
    person1.age = 24;
    person1.address = "HCM";
    person1.sex = true;

    cout << "My name is :"<< person1.name << endl;
    cout << "My age is :" << person1.age << endl;
    cout << "My address is :" << person1.address << endl;
    person1.work();

    Person person2("Nguyen Duong", "Binh Duong", 36, true);
    cout << "My name is :"<< person2.name << endl;
    cout << "My age is :" << person2.age << endl;
    cout << "My address is :" << person2.address << endl;
    person2.work();

}