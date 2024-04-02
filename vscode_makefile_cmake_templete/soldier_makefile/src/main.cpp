#include "soldier.h"

int main(){
    Gun* gun = new Gun("AK47", 0);
    Soldier* soldier = new Soldier("Lyh", gun);
    // soldier->addBulletToGun(10);
    soldier->fire();
    delete soldier;
    return 1;
}