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
        Student operator++(){
            this->age++;
            return *this;
        }

        Student operator++(int notUsed){
            Student temp = *this;
            this->age++;
            return temp;
        }

        Student operator--(){
            this->age--;
            return *this;
        }

        Student operator--(int notUsed){
            Student temp = *this;
            this->age--;
            return temp;
        }
        */

        friend Student operator++(Student& s){
            s.age++;
            return s;
        }

        friend Student operator++(Student& s, int notUsed){
            Student temp = s;
            s.age++;
            return temp;
        }

        friend Student operator--(Student& s){
            s.age--;
            return s;
        }

        friend Student operator--(Student& s, int notUsed){
            Student temp = s;
            s.age--;
            return temp;
        }
};

int main(){
    Student s1("Monira", 20);

    // Unary operator overloading with function
    cout << "Unary operator overloading with function" << endl;
    //Case-1: ++s1
    Student s2 = ++s1;
    cout << "Case-1: For ++s1: " << endl;
    cout << "S1: " <<s1.getName() << ", " << s1.getAge() << endl;
    cout << "S2: " <<s2.getName() << ", " << s2.getAge() << endl;

    //Case-2: s1++
    Student s3 = s1++;
    cout << "Case-2: For s1++: " << endl;
    cout << "S1: "<< s1.getName() << ", " << s1.getAge() << endl;
    cout << "S3: "<< s3.getName() << ", " << s3.getAge() << endl;

    //Case-3: --s1
    Student s4 = --s1;
    cout << "Case-3: For --s1: " << endl;
    cout << "S1: "<< s1.getName() << ", " << s1.getAge() << endl;
    cout << "S4: "<< s4.getName() << ", " << s4.getAge() << endl;

    //Case-4: s1--
    Student s5 = s1--;
    cout << "Case-4: For s1--: " << endl;
    cout << "S1: "<< s1.getName() << ", " << s1.getAge() << endl;
    cout << "S5: "<< s5.getName() << ", " << s5.getAge() << endl;


    return 0;
}

