// RORIGO ALEJANDRO CHAVEZ AVALOS A01635547
#ifndef PUNTO3D_H
#define PUNTO3D_H
#include "Punto.h"
class Punto3d:public Punto{
    public:
        Punto3d();
        Punto3d(int, int ,int );
        std::string mostrar() override;
        int getZ() const;
        void setZ(int);
    private:
        int z;
};
#endif //clase PUNTO3D