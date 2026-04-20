## 1️⃣ What is Object-Oriented Programming (OOP)?

OOP is a programming paradigm based on the concept of **objects**, where each object represents a real-world entity with:
- **Data** (attributes)
- **Behavior** (methods)

### Why OOP?
OOP helps in building systems that are:
- Modular
- Reusable
- Easy to maintain
- Scalable


## 2️⃣ Core OOP Concepts


## 1. Encapsulation

Encapsulation is the process of **binding data and methods together** and restricting direct access to the data.

The internal state of an object should not be directly modified from outside. Instead, access should be controlled through methods.

### Real-Life Analogy:
Think of a **Bank Account**:
- You cannot directly access or change the balance.
- You must use controlled methods like `deposit()` and `withdraw()`.

This protects the data from accidental or unauthorized changes.



## 2. Abstraction

Abstraction means **hiding complex implementation details** and showing only the essential features to the user.

Users interact with a system without knowing how it works internally.

### Real-Life Analogy:
Think of **driving a car**:
- You use the steering wheel, brake, and accelerator.
- You don't need to understand how the engine combustion works internally.



## 2. 1. Types of Abstraction

### Abstract Class
A class that **cannot be instantiated** and is meant to be extended by child classes.

It provides a base structure with:
- Some **implemented** methods
- Some **unimplemented** (pure virtual) methods

#### Real-Life Analogy:
A **Vehicle blueprint**:
- It defines that every vehicle must have a `start()` method.
- But the actual implementation differs — a car starts differently from a bike.


###  Interface (Conceptual in C++)
An interface is a **contract** that defines what methods a class must implement, without providing any implementation itself.

It enforces structure and consistency across classes.

#### Real-Life Analogy:
Think of a **USB port standard**:
- Any USB device must follow the same connection rules.
- But what happens internally inside each device can differ completely.


## 3. Inheritance

Inheritance is a mechanism where one class **(child/subclass)** acquires the properties and behavior of another class **(parent/superclass)**.

### Benefits:
- Code reuse
- Reducing duplication
- Improving maintainability


## 3. 1. Types of Inheritance


###  Single Inheritance
A class inherits from **only one** parent class. This is the simplest and most commonly used form of inheritance in C++.

#### Real-Life Analogy:
`Person → Student`
- A Student is a type of Person and inherits properties like `name` and `age`.

---

###  Multiple Inheritance
A class inherits from **more than one** parent class, combining features from multiple parents.

#### ⚠️ Important Note:
C++ **supports multiple inheritance directly**, unlike Java. However, it can introduce complexity — especially the **Diamond Problem (ambiguity)**, which occurs when multiple parent classes share the same base class.

#### Real-Life Analogy:
A **Smart Device** can act as both:
- A Phone
- A Camera

---

###  Multilevel Inheritance
A class inherits from a parent, which itself inherits from another class — forming a **chain**.

#### Real-Life Analogy:
`Animal → Mammal → Dog`
- Dog inherits from Mammal.
- Mammal inherits from Animal.

---

###  Hierarchical Inheritance
**Multiple child classes** inherit from a single parent class.

#### Real-Life Analogy:
`Vehicle → Car, Bike, Truck`
- All share common properties from `Vehicle`.
- Each has its own specific behavior.

---

###  Hybrid Inheritance
A **combination** of two or more types of inheritance (for example, multiple + multilevel).

#### ⚠️ Important Note:
C++ allows hybrid inheritance, but it can lead to ambiguity issues like the **Diamond Problem**. To resolve this, C++ provides **virtual inheritance**.

#### Real-Life Analogy:
A **Smart Car system**:
- Inherits from `Vehicle` (hierarchical)
- Also combines features like `GPS` and `Camera` (multiple inheritance)

---

## 4. Polymorphism

Polymorphism means **"one interface, multiple implementations"**.

The same function behaves differently depending on the object that calls it.

#### Real-Life Analogy:
Think of a **Payment System**:
- Credit Card payment
- UPI payment
- Net Banking

All use the same method `pay()`, but the internal behavior differs for each.

---

## 4. 1. Types of Polymorphism

###  Compile-Time Polymorphism (Static)
Method behavior is **decided at compile time**.

Achieved using **function overloading** or **operator overloading** in C++.

#### Key Point:
C++ **fully supports** method overloading, unlike JavaScript.

#### Real-Life Analogy:
Think of a **Calculator**:
- Adding two numbers → `add(int a, int b)`
- Adding three numbers → `add(int a, int b, int c)`

Same function name, different inputs — decision made at compile time.

---

###  Runtime Polymorphism (Dynamic)
Method behavior is **decided at runtime**.

Achieved using **function overriding** with **virtual functions**.

####  Key Point:
- Base class defines a `virtual` function.
- Child class **overrides** it with its own implementation.
- The decision of which method to call happens at **runtime** using a base class reference or pointer.

#### Real-Life Analogy:
Think of a **Payment Gateway**:
- Same method: `pay()`
- Different behavior based on the payment type selected at runtime.

---

##  Important Interview Notes

1. C++ supports **all inheritance types**, including multiple and hybrid.
2. C++ handles ambiguity in multiple/hybrid inheritance using **virtual inheritance**.
3. **Compile-time polymorphism** is achieved using **function/operator overloading**.
4. **Runtime polymorphism** is achieved using **virtual functions** (overriding).