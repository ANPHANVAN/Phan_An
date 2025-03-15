#include <iostream>
#include <string>
using namespace std;

class Animal
{
private:
    string hero;

protected:
    string skills = "run so fast";
public:
    Animal(){};
    string name;
    int leg;
    int age;
    bool breath = true;

    void eating() {
        cout << "eating\n";
    };
};

class Person : public Animal
{
private:
    string zin;

protected:
    string talk = "papa";

public:
    Person(){};
    string handshaking;
    string wellcom;

    void set_skill(string _skill){
        skills = _skill;
    };

    string get_skills(){
        return skills;
    };

};



class Dog  : public Animal {
    private:
        string spy;
    protected:
    public:
        Dog(){};

        void behavior(){
            cout << "friend with person";
        };

};

int main(){
    Person person;
    person.name = "person";
    person.handshaking = "Handshaking";
    person.wellcom = "Hello bro";
    person.set_skill("comunicate so good");

    cout <<  person.name << " have skill " << person.get_skills() << endl;
}