#include "bits/stdc++.h"
using namespace std;

// takes something returns nothing
void say_my_name(string x) {
    cout << "Hello " << x << endl;
}

// takes nothing returns nothing
void greet() {
    cout << "fkoerewreeawsfawsfewrfefrd" << endl;
    cout << "sdfsdf" << endl;
    cout << "fsdfsdf" << endl;
    cout << "sfsfsdfsdf" << endl;
    cout << "sfsdfsdfs" << endl;
    cout << "fsdfsdfsfsfs" << endl;
    cout << "sfsfsdfsdffsfs" << endl;
    cout << "fsfsdfs" << endl;
}

// takes nothing returns something
int get_interest_rate() {
    return 8;
}

// takes something returns something
int add(int a, int b) {
    return a + b;
}

void add(int a, int b, int &c) {
    c = a + b;
}

bool is_multiple(int a, int b) {
    return a % b == 0 ? true : false;
}

// predefined data types: int char float double string, 
// custom data types: address
struct address { 
private:
    int pincode;

public:
    string city;
    
    void get_input_address() {
        cin >> city >> pincode;
        if (pincode < 0) {
            cout << "pincode can't be negative" << endl;
        }
    }
    
};

// address get_input_address() {
//     address x;
//     cin >> x.city >> x.pincode;
//     return x;
// }

struct student {
    string name;
    int rollno;
    address my_address; // {city, pincode}
    
    void print_info() {
        // string city = address.city;
        cout << "My name is " << name << endl;
        cout << "My rool number is " << rollno << endl;
        cout << "I am from " << my_address.city << endl;
    }
};

// void print_info(student s) {
//     // string city = address.city;
//     cout << "My name is " << s.name << endl;
//     cout << "My rool number is " << s.rollno << endl;
//     cout << "I am from " << s.my_address.city << endl;
// }

struct club {
    string name;
    string coordinator;
    int members;
    student students[100];
};

int main() {
    // string s = "Shaivya Jhaldiyal";
    // say_my_name(s); // function call
    
    // string t = "Taara Sinh Aatrey";
    // say_my_name(t); // function call
    // // c = add(a, b);
    
    
    // int a = 2, b = 3, c;
    // add(a, b, c); // c = 5
    
    // int x = 5;
    // int &p = x;
    
    // cout << is_multiple(6, 3) << endl;
    // cout << is_multiple(7, 3) << endl;
    // cout << is_multiple(8, 3) << endl;
    // cout << is_multiple(9, 3) << endl;
        
    // address a = {"Roorkee", 247676};
    // address b = {"Sitamarhi", 843315};
    // address c = {"Gopalganj", 841416};
    
    // cin >> a.city >> a.pincode;
    
    // address a = get_input_address();
    // address b = get_input_address();
    // address c = get_input_address();
    
    address a, b, c;
    a.get_input_address();
    b.get_input_address();
    c.get_input_address();
    
    // cout << a.city << " " << a.pincode << endl;
    // cin >> b.city >> b.pincode;
    // b.city = "Patna";
    // b.pincode = 482005;
    // b.city = a.city;
    // b.pincode = a.pincode;
    // b = a;
    // cout << b.city << " " << b.pincode << endl;
    
    student s = {"Shaivya", 2019336, a};
    student t = {"Taara", 2019348, b};
    student u = {"Anmol", 2019208, c};
    
    club C = {"Saaz", "Anmol", 3, {s, t, u}};
    
    cout << C.coordinator << endl;
    cout << C.members << endl;
    cout << C.students[0].my_address.city << endl;
    C.students[2].print_info();
    // print_info(C.students[2]);
    
    
    return 0;
}