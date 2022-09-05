// RORIGO ALEJANDRO CHAVEZ AVALOS A01635547
#ifndef PUNTO_H
#define PUNTO_H
#include <iostream>

class Punto{
    public:
        Punto();
        Punto(int, int);
        virtual std::string mostrar();
        friend std::ostream& operator<< (std::ostream &, Punto*);
        int getX() const;
        int getY() const;
        void setX(int);
        void setY(int);
    private:
        int x;
        int y;
};
#endif //clase punto