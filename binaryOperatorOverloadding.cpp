#include<iostream>

using namespace std;

class Student{
    private:
        string name;
        int age;

    public:
        Student(){
            this->age = 18;
        }

        Student(string name, int age){
            this->name = name;
            this->age = age;
        }

        string getName(){
            return this->name;
        }

        void setName(string name){
            this->name = name;
        }

        int getAge(){
            return this->age;
        }

        void setAge(int age){
            this->age = age;
        }

        /*
        int operator+(int age){
            return this->age + age;
        }

        Student operator+(Student other){
            Student student(this->name + " " + other.getName(),
                            this->age + other.getAge());
            return student;
        }
        */

        friend int operator+(Student s, int age){
            return s.age + age;
        }

        friend Student operator+(Student near, Student far){
            Student student(near.name + " " + far.name,
                            near.age + far.age);
            return student;
        }

        friend int operator+(int age, Student s){
            return s.age + age;
        }
};

int main(){
    Student s1("Monira", 20);
    Student s2("Akhi", 21);

    // Binary operator overloading with function
    cout << "Binary operator overloading with function" << endl;

    //Case-1: s1+7
    cout << "Case-1: For s1+7" << endl;
    int totalAge = s1 + 7;
    cout << totalAge << endl;

    //Case-2: s1+s2
    cout << "Case-2: For s1+s2" << endl;
    Student superStudent = s1 + s2;
    cout << superStudent.getName() << ", " << superStudent.getAge() << endl;


    //Case-3: 7+S1 (Won't work with native function overloading...)
    cout << "Case-3: For 7+S1 (Won't work with native function overloading...)" << endl;
    cout << 7 + s1 << endl;

    return 0;
}
