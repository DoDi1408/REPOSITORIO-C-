#ifndef COORDPOLAR_H
#define COORDPOLAR_H

class CoordPolar{

    public:
        CoordPolar();
        CoordPolar(double, double);
        double getR() const;
        double getAngulo() const;
        void setR(double);
        void setAngulo(double);
        //CoordPolar operator *(const CoordPolar& cp);
    private:
        double r;
        double angulo;
};

#endif // COORDPOLAR_H