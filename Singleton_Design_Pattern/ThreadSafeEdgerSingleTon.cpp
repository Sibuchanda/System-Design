// ============================FOURTH PROGRAM ============================

// SafeEdger means -> Create object quickly. But the problem is if there is an object that is very big and used frequently, then in such case when the appliation runs it created the object and if the object is not used then it holds all the memory resources.

#include<iostream>
#include <mutex>

using namespace std;

class Singleton {
private:
    static Singleton* instance;

    Singleton() { 
        cout << "Singleton Constructor Called!" << endl; 
    }
 
public:
    static Singleton* getInstance() {
        return instance;
    }
};
 
// Initialize static members (Here we directly create the object instead of assigning nullptr )
Singleton* Singleton::instance = new Singleton();

int main() {
    Singleton* s1 = Singleton::getInstance();
    Singleton* s2 = Singleton::getInstance();

    cout << (s1 == s2) << endl;
}