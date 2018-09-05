class Base
{
    virtual void f(int);
};

class Derived : public Base
{
    virtual void f(float) override;  // Error
};

class A final
{
    virtual void f(int);
};

class B
{
    // no class can override f()
    virtual void f() final; 
};