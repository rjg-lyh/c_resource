#include "gun.h"

class Soldier{
    private:
        string _name;   
        Gun* _gun;
    public:
        Soldier(string name, Gun* gun):_name(name), _gun(gun){}
        void addBulletToGun(int num);
        bool fire();
        ~Soldier();
};