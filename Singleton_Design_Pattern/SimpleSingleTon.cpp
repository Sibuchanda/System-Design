// ============================SECOND PROGRAM ============================

// This code is not Thread safe. Like if two thread executes paralally, then two objects can be created

#include<iostream>
using namespace std;

class Singleton {
private:
    static Singleton *instance;

    Singleton() {
        cout << "Singleton Constructor called" << endl;
    }

public:
    static Singleton *getInstance() {
        if(instance == nullptr) {
            instance = new Singleton();
        }
        return instance;
    }
};

// Initialize static member ( In C++ we can not initialize static member inside the class)
Singleton *Singleton::instance = nullptr;

int main() {
    Singleton *s1 = Singleton::getInstance();
    Singleton *s2 = Singleton::getInstance();

    cout << (s1 == s2) << endl;
}