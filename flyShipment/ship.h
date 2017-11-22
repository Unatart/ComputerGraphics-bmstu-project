#ifndef SHIP_H
#define SHIP_H

#include "point.h"
#include "polygon.h"
#include "sceneobj.h"

struct ship_sizes {
    int L;
    int H;
    int Wb;
    int Wt;
};

class Ship : public SceneObject{
public:
    void createShip(int L, int H, int Wt, int Wb);

    void move(double dx, double dy, double dz) ;

    void rotate(double dxy, double dyz, double dzx) ;
    void resize(double k) = 0;

    void rotate(double dxy, double dyz, double dzx, const Point& center);
    void resize(double k, const Point& center) ;

private:
    ship_sizes ship_size;
    std::vector<ShipPolygon> ship;
    Point center;
};



#endif // SHIP_H
