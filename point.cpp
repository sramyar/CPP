#include<iostream>

using namespace std;

class point{
    public:
    double x,y;

    public:
    point(double X, double Y)
    {
        this->x = X;
        this->y = Y;
    }
    point():x(0.01),y(0.01){}

    const point& operator+ (const point& p1)
    {
        const point& sum = point(p1.x + this->x, p1.y + this->y);
        return sum;
    }

    
};

ostream& operator<<(ostream& out, const point& p)
    {
        out << "(" << p.x <<", " << p.y << ")" << endl;
        return out;
    }


int main(void)
{
    point a = point(1.1,2.2);
    point b = point();
    cout << a;
    cout << (b);
    return 0;
}