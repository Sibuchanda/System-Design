## What is an Abstract Class in C++?
An abstract class is a class that cannot be instantiated directly. It is designed to be a base class and usually contains at least one pure virtual function.

A pure virtual function is declared like this:

`virtual void display() = 0;`

The = 0 tells the compiler: “This function has no implementation here, it must be overridden by derived classes.”

## Why we need Abstract class? Whithout Abstract class what will be the problem?

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


## Why NO implementation of functions in base class?

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











