#pragma once
#include <iostream>

using namespace std;

class Gun{
    private:
        string _name;
        int _num;
    public:
        Gun(string name, int num):_name(name), _num(num){}
        void addBullet(int num);
        bool fire();
};