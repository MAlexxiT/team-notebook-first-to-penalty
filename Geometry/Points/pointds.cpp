#define eps 1e-10
//PI = acos(-1.0)
//M_PI esta en el standard del lenguaje
struct point{
    long double x,y;
    point(){x = 0; y = 0;}
    point(long double _x, long double _y){x = _x; y = _y;}
    bool operator<(const point other) const{
        if(fabs(x-other.x)>eps) return x<other.x;
        return y<other.y;
    }
    bool operator==(const point other) const{
        return (fabs(x-other.x)<=eps) && (fabs(y-other.y)<=eps); 
    }
};
long double hipot(long double a, long double b){return a*a+b*b;}
//el signo de las hipotenusas da igual, pues se elevan al cuadrado.
long double dist(point a, point b){
    long double dx = a.x-b.x;
    long double dy = a.y-b.y;
    return sqrtl(hipot(dx,dy));
}
long double deg_rad(double d){return d*M_PI/180.0;}
long double rad_deg(double r){return r*180.0/M_PI;}
//rota theta grados counteclockwise 
point rotar(point p, long double theta){
    double rad = deg_rad(theta);
    return point(p.x*cos(rad)-p.y*sin(rad), p.x*sin(rad)+p.y*cos(rad));
}