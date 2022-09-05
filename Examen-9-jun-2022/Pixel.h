// RORIGO ALEJANDRO CHAVEZ AVALOS A01635547
#ifndef PIXEL_H
#define PIXEL_H
#include "Punto3d.h"
class Pixel:public Punto{
    public:
        Pixel();
        Pixel(int, int ,std::string);
        std::string mostrar() override;
        std::string getColor() const;
        void setColor(std::string);
    private:
        std::string color;
};
#endif // clase pixel