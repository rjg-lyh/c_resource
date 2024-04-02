#include "soldier.h"

void Soldier::addBulletToGun(int num){
    _gun->addBullet(num);
}

bool Soldier::fire(){
    if(!_gun->fire()){
        cout << "The soldier failed to fire ! ! !" << endl;
        return false;
    }
    cout << "The soldier fired successfully ! ! !" << endl;
    return true;
}

Soldier::~Soldier(){
    delete _gun;
}