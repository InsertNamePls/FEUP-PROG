#include <cmath>
#include <ostream>
#include <iostream>
#include "exc3.h"
class solid {
public:
    virtual double volume () const{
        return 0;
    }
    virtual double area () const{
        return 0;
    }
    virtual double AV () const{
        if(volume() == 0 ) return -1;
        return area()/volume();
    }
    virtual double sides() const{
        return 0;
    }
    virtual void print(std::ostream& out) const {
        out << "Area: " << area() << std::endl
            << "Volume: " << volume() << std::endl
                << "AV: " << AV() << std::endl
                << "Sides: " << sides() << std::endl;
    }
};

class sphere : public solid {
protected:
    int radius;
public:
    sphere(int radius){
       this->radius = radius;
    }
    double volume () const override{
        return 4/3*(M_PI*(radius*radius));
    }
    double area () const override{
        return 4*M_PI*radius*radius;
    }
    double sides() const override{return 0;}


};

class cuboid: public solid{
protected:
    double lx,ly,lz;
public:
    cuboid(double lx, double ly, double lz){
        this->lx = lx;
        this->ly = ly;
        this->lz = lz;
    }
    virtual double volume () const override{
        return lx*ly*lz;
    }
    virtual double area () const override{
        return 2*(lx*ly+lx*lz+ly*lz);
    }
    double sides() const override {return 6;}
};
class cube final : public cuboid {
public:
    cube(double edge): cuboid(edge,edge,edge){}
};

int main(void){

    sphere s(1.0);
    cuboid c1(1.0, 2.0, 3.0);
    cube c2(2.5);

    s.print(std:: cout);
    c1.print(std:: cout);
    c2.print(std:: cout);
}