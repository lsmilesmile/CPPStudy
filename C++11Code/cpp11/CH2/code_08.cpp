/*
 * @Description: 
 * @Author: liuxiao
 * @Date: 2022-04-26 14:19:11
 */

#include <iostream>

class MyClass {
    public:
    MyClass(std::string _name, int _age) {
        name = _name;
        age = _age;
    }
    std::string name;
    int age;
    static int s;
};

int MyClass::s = 33;

MyClass* getCls() {
    MyClass* pCls = new MyClass("felix", 13);
    return pCls;
}

int main() {
    MyClass* p = getCls();
    std::cout << "name: " << p->name << ", " << "age: " << p->age << std::endl;
    std::cout << MyClass::s << std::endl;
    if (p) {
        delete p;
        p = nullptr;
    }
    return 0;
}
