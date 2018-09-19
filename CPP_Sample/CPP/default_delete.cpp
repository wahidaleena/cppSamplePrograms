#include "iostream"

using namespace std;

class A
{
public:
    A(int a){};
    A(double) = delete;         // conversion disabled
    A& operator=(const A&) = delete;  // assignment operator disabled
};

int main()
{
    A a(10);     // OK
    A b(3.14);   // Error: conversion from double to int disabled
    a = b;       // Error: assignment operator disabled
}
