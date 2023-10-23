#include "bits/stdc++.h"
using namespace std;


// parent class
class person {
public:
    string name;
    int year_of_birth;
    string gender;
    
    // overloading happens when we have multiple functions with same name
    // but different signature
    // greet and greet(string message) are two overloaded functions
    
    // s1
    void greet() {
        cout << "Hello there!" << endl;
    }
    
    // s2
    // void greet(string message) {
    //     cout << message << endl;
    // }
    
    person(string a, int b, string c) {
        name = a;
        year_of_birth = b;
        gender = c;
    }
    
    person() {
        
    }
    
};

// two functions with same name but different signature in same class : overloading
// two functions with same name but same/different signaure


// child class
class teacher : public person /* this is inheritance */ {
public:
    string faculty_id;
    string subject;
    
    // s3
    void greet() {
        cout << "Good morning students!" << endl;
    }
    
    teacher(string a, int b, string c, string d, string e) : person(a, b, c) {
        faculty_id = d;
        subject = e;
    }
};

class student {
    
};

// class is like a custom data type
// object is like a variable
// data type: int, float
// int x, y;
// person shaivya, taara;


int main() {
    person shaivya("Shaivya Jhaldiyal", 2001, "Female");
    person taara("Taara Sinh Aatrey", 2001, "Male");
    
    shaivya.greet();
    // shaivya.greet("Hi there!");
    // taara.greet();
    
    teacher ayan("Ayan Seal", 1970, "Male", "JAJEHIJH", "C++");
    
    ayan.greet();
    // ayan.greet("Greetings!");
    
    return 0;
}