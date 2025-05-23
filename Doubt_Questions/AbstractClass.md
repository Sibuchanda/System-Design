## 1️⃣ What is an Abstract Class in C++?
An abstract class is a class that cannot be instantiated directly. It is designed to be a base class and usually contains at least one pure virtual function.

A pure virtual function is declared like this:

`virtual void display() = 0;`

The = 0 tells the compiler: “This function has no implementation here, it must be overridden by derived classes.”

## 2️⃣Why we need Abstract class? Whithout Abstract class what will be the problem?

I am running a delivery company. There are different types of delivery drivers:
- Bike Driver
- Truck Driver
- Drone Delivery

They all do the same job deliver packages but in their own way.

So what do I do?

I tell every driver:

"You MUST have a way to deliver a package. I don’t care how you do it — bike, truck, drone — but you MUST have that method."

This is what an abstract class does.
It says:

"Every child class MUST follow this rule, but can have their own style of doing it."

### 🚫 What if we don’t use an abstract class?

Then:
- Some drivers might forget to add the deliverPackage() method.
- Our system would crash when you try to call deliverPackage() on a driver that doesn’t have it.
- We will have a messy system where some drivers deliver, and others don’t — no rules! Like if there is 10 to 20 types of delivery methods and if some delivery classes are not have any delivary methods then, they are just polluting the code.


## 3️⃣ Why NO implementation of functions in base class?

Because sometimes, the base class doesn’t know the details.

Let’s say you’re making a program for animals.

` class Animal {
public:
    virtual void makeSound() = 0;  // I don't know what sound, just know every animal makes one
};`

We can’t write a sound here, because:
- A dog barks
- A cat meows
- A cow moos

So the abstract class (Animal) says: "I know every animal makes a sound, but I don’t know which one, so I won’t implement it."

That’s the advantage: it forces every child to define its own behavior, and avoids wrong or default behavior.


## 4️⃣ Why do we use A* obj = new B(); instead of B* obj = new B(); in C++?

We use A* obj = new B(); because it enables runtime polymorphism.
- This means we can write code that works with any class derived from A, not just B.
- The actual method (show()) that gets called is decided at runtime, based on the object type (B in this case).

#### Real-Life Analogy:
Think of A as a Remote Control interface, and B, C, D as different TV brands. With A* obj = new B();, you're saying:

"I can control any brand, as long as it follows the remote interface." This makes our code flexible and scalable.

#### What if we use B* obj = new B();?
- It works, but the code becomes tightly coupled to class B.
- If we later switch to class C, we’ll have to change the type everywhere in the code.
- This reduces reusability and maintainability.

#### Conclusion
- Use **B\* obj = new B();** if you are only working with class B.
- Use **A\* obj = new B();** if you want flexibility to work with any class that inherits A  great for big applications, frameworks, or when writing reusable code.


## 5️⃣ Difference beween `B* obj = new B();` and `B* obj;` ?

`B* obj = new B();` -->  This line creates an object and gives you a pointer to it. Means it will create a new B object in heap memory and give me its address.
- A new object is created in heap (dynamic memory).
- obj now points to that object.
- You can use obj-> to call methods on it.
- You are responsible for deleting it later using delete obj;

#### When to use:
- When you want dynamic memory allocation.
- When you want to pass it around using base class pointers (A* obj = new B();)


B* obj; --> This line just declares a pointer, but does not point to anything yet. Means We are creating a pointer to a B object, but we are not assigning any object to it right now.

#### What happens:
- The pointer exists but contains garbage or NULL until you assign something.
- If you try to use it without assigning, it will crash (undefined behavior).

#### Conclusion 
- B* obj = new B(); is like:
  - "Booking a hotel room and getting the key right away."

- B* obj; is like:
  - "Saying you’ll stay in a hotel, but you haven’t booked or got any room yet."


  ## 6️⃣ What is Abstract class and Interface in C++?

  #### What is an Abstract Class?
  An abstract class is a class that cannot be directly used to create objects, but it can provide:
- Some methods with code (implementation) 
- Some methods without code (pure virtual functions) 

``` 
class Animal {
public:
    virtual void makeSound() = 0;  // pure virtual function
    void breathe() {
        cout << "Animal breathes oxygen" << endl;  // with implementation
    }
};
```
#### What is an Interface (in C++ style)?
C++ doesn't have a built-in interface keyword like Java or C#.
But we simulate an interface by using an abstract class where all methods are pure virtual and there are no data members or implemented methods.

```
class IPrintable {
public:
    virtual void print() = 0;  // only pure virtual methods
    virtual void print2() = 0;  // Two pure virtual methods
};
```

### Difference Between Abstract Class and Interface in C++

| Feature                   | Abstract Class                                 | Interface (in C++)                         |
|---------------------------|-------------------------------------------------|--------------------------------------------|
| Can have method bodies?   | ✅ Yes (some methods can be implemented)        | ❌ No (all must be pure virtual)           |
| Can have data members?    | ✅ Yes                                           | ❌ No                                       |
| Multiple inheritance?     | 🚫 Risky (C++ allows but tricky)                 | ✅ Easy, multiple interfaces possible       |
| Use case                  | Base class with common code                     | Rule book for unrelated classes            |
| Object creation           | ❌ No (can't make object directly)              | ❌ No                                       |













