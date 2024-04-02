#include "gun.h"

void Gun::addBullet(int num){
    _num += num;
}

bool Gun::fire(){
    if(!_num){
        cout << "There is no bullet in the " << _name << " ! ! !" << endl;
        return false;
    }
    cout << "Boom ! ! !" << endl;
    return true;
}

