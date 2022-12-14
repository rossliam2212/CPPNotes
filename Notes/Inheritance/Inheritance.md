# [Inheritance Notes](https://github.com/rossliam2212/CPPNotes/blob/master/Notes/Inheritance/InheritanceNotes.txt)

## Constructors & Destructors

### Constructors and Class Initialization
- A Derived class inherits from its Base class.
    - The Base part of the Derived MUST be initialized BEFORE the Derived class is initialized.
    - When a Derived object is created:
        - Base class constructor executes then.
        - Derived class constructor executes


- A Derived class does NOT inherit:
  - Base class constructor
  - Base class destructor
  - Base class overloaded assignment operators
  - Base class friend functions

- However, the Derived class constructors, destructors, and overloaded assignment
  operators can invoke the Base class versions.

- C++11 allows explicit inheritance of Base 'non-special' constructors with:
    - using Base::Base; anywhere in the Derived class declaration.
    - Lots of rules involved, often better to define constructors yourself.

### Destructors
- Class destructors are invoked in the reverse order as constructors.
    - The Derived part of the Derived class MUST be destroyed BEFORE the Base class destructor is invoked.
    - When a Derived object is destroyed:
        - Derived class destructor executes then.
        - Base class destructor executes
        - Each destructor should free resources allocated in it's own constructor


### Passing Arguments to Base Constructors

```c++
class Base {
public:
    Base();
    Base(int);
    //....
};

Derived::Derived(int x)
    : Base(x), {optional initializers for derived} {
    // code
}
```

## Copy/Move Constructor and Overloaded operator= (Assignment)
- Not inherited from Base class
- You may not need to provide your own
    - Compiler-provided versions may be just fine
- We can explicitly invoke the Base class versions from the Derived class

### Copy Constructor:
- Can invoke Base copy constructor explicitly
  - Derived object 'other' will be sliced

```c++
Derived::Derived(const Derived& other)
        : Base(other), {Derived initialization list}
    {
        // code
    }
```

### Copy Constructor Example:
```c++
class Base {
    private:
        int value;

    public:
        // Same constructors as previous examples

        Base(const Base& other) : value{other.value} {
            std::cout << "Base copy constructor" << std::endl;
        }
    };

    class Derived : pubic Base {
    private:
        int doubledValue;

    public:
        // Same constructors as previous examples

        Derived(const Derived& other)
            : Base(other), doubledValue{other.doubledValue} {
            std::cout << "Derived copy constructor" << std::endl;
        }
    };
```

### operator= Example:
```c++
class Base {
    private:
        int value;

    public:
        // Same constructors as previous examples

        Base& operator=(const Base& rhs) {
            if (this != &rhs) {
                value = rhs.value; // assign
            }

            return *this;
        }
    };

    class Derived : public Base {
    private:
        int doubledValue;

    public:
        // Same constructors as previous examples

        Derived& operator=(const Derived& rhs) {
            if (this != &rhs) {
                Base::operator=(rhs);               // Assign Base part
                doubledValue = rhs.doubledValue;    // Assign Derived part
            }
            return *this
        }
    };
```

- Most of the time you do not need to provide your own Copy/Move constructors and overloaded operator=

- If you DO NOT define them in Derived
    - then the compiler will create them and automatically call the Base class's version

- If you DO provide Derived versions
    - then you MUST invoke the Base versions explicitly yourself

- Be careful with raw pointers
    - Especially if Base and Derived each have raw pointers
    - Provide them with deep copy semantics

## Redefining Base Class Methods
- Derived class can directly invoke Base class methods
- Derived class can override or redefine Base class methods
- Very powerful in the context of polymorphism

### Example:
```c++
class Account {
    public:
        void deposit(double amount) { balance += amount; }
    };

    class SavingsAccount : public Account {
    public:
        void deposit(double amount) {    // Redefine Base class method
            amount += someInterest;
            Account::deposit(amount);    // Invoke Base class method
        }
    };
```

### Static binding of method calls:
- Binding of which method to use is done at compile time
  - Default binding for C++ is static
  - Derived class objects will use Derived::deposit
  - But, we can explicitly invoke Base::deposit from Derived::deposit
  - Ok, but limited - much more powerful approach is dynamic binding ([Polymorphism section]())

```c++
    Base b;
    b.deposit(1000.0);              // Base::deposit

    Derived d;
    d.deposit(1000.0);              // Derived::deposit

    Base* ptr = new Derived();
    ptr->deposit(1000.0);           // Base::deposit ?????
```

## Multiple Inheritance

                            Person
                              |
            Employee----------|---------Student
               |
               |
       |-------|--------------|
    Faculty  Administrator   Staff
       |-------|
           |
        Department
          Chair

- A Derived class inherits from two or more Base classes at the same time
- The Base classes may below to unrelated class hierarchies
- A Department Chair
    - Is-A Faculty and
    - Is-A Administrator

### Syntax:
```c++
class DepartmentChair : public Faculty, public Administrator {
    // ....
};
```

- Multiple inheritance has some compelling use-cases
- Can be easily misused
- Can be very complex