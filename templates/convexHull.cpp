#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

int nP, c, k;

struct Point
{
    double x;
    double y;
};

Point points[10000], cHull[10000];

struct Vector
{
    double a;
    double b;
};

Vector iHat;

double cross(Vector v1, Vector v2)
{
    return v1.a * v2.b - v1.b * v2.a;
}

double dot(Vector v1, Vector v2)
{
    return v1.a * v2.a + v1.b * v2.b;
}

double vA(Vector v)
{
    if(!v.a && !v.b) return 1;
    return sqrt(v.a * v.a + v.b * v.b);
}

double vCos(Vector v1, Vector v2)
{
    return dot(v1, v2)/vA(v1)/vA(v2);
}

double vSin(Vector v1, Vector v2)
{
    return cross(v1, v2)/vA(v1)/vA(v2);
}

bool comp1(Point p1, Point p2)
{
    Vector v1, v2;
    v1.a = p1.x;
    v1.b = p1.y;
    v2.a = p2.x;
    v2.b = p2.y;
    double t1, t2;
    t1 = vCos(iHat, v1);
    //cout << "t of " <<  "(" << v1.a << ", " << v1.b << ")" << " = " << t1 << endl;
    t2 = vCos(iHat, v2);
    //cout << "t of " <<  "(" << v2.a << ", " << v2.b << ")" << " = " << t2 << endl;
    if(t1 == t2)
    {
        return vA(v1) < vA(v2);
    }
    return t1 > t2;
}

bool comp2(Point p1, Point p2)
{
    if(p1.y == p2.y)
    {
        return p1.x < p2.x;
    }
    return p1.y < p2.y;
}

Vector newVector(Point p1, Point p2)
{
    Vector p;
    p.a = p2.x - p1.x;
    p.b = p2.y - p1.y;
    return p;
}

int main()
{
    iHat.a = 1;
    iHat.b = 0;
    while(cin >> c)
    {
        //cout << c << endl;
        for(int aj = 0; aj < c; aj++)
        {
            if(aj) printf("-1\n");
            cin >> nP;
            for(int i = 0 ; i < nP; i++)
            {
                cin >> points[i].x >> points[i].y;
            }
            nP--;

            sort(points, points + nP, comp2);
            points[nP].x = points[0].x;
            points[nP].y = points[0].y;
            //cout << points[0].x << ", " << points[0].y << endl;
            for(int i = 1 ; i <= nP; i++){
                //cout << "B: " << points[i].x << ", " << points[i].y << endl;
                points[i].x -= points[0].x;
                points[i].y -= points[0].y;
                //cout << "A: " << points[i].x << ", " << points[i].y << endl;
            }


            sort(points + 1, points + nP, comp1); //don't sort last point
            for(int i = 0 ; i < nP; i++){
                Vector v;
                v.a = points[i].x;
                v.b = points[i].y;
                //printf("%d: (%.0f, %.0f), cos: %f\n", i+1, points[i].x + points[0].x, points[i].y + points[0].y, vCos(iHat, v));
            }
            int orX = points[0].x, orY = points[0].y;
            points[0].x = points[0].y = 0;

            cHull[0].x = points[0].x;
            cHull[0].y = points[0].y;
            cHull[1].x = points[1].x;
            cHull[1].y = points[1].y;
            int hullHead = 2;
            for(int i = 2 ; i <= nP; i++)
            {
                Vector v1, v2;
                v1.a = cHull[hullHead-1].x - cHull[hullHead-2].x;
                v1.b = cHull[hullHead-1].y - cHull[hullHead-2].y;
                v2.a = points[i].x - cHull[hullHead-1].x;
                v2.b = points[i].y - cHull[hullHead-1].y;
                while(vSin(v1, v2) <= 0)
                {
                    hullHead--;
                    v1.a = cHull[hullHead-1].x - cHull[hullHead-2].x;
                    v1.b = cHull[hullHead-1].y - cHull[hullHead-2].y;
                    v2.a = points[i].x - cHull[hullHead-1].x;
                    v2.b = points[i].y - cHull[hullHead-1].y;
                }
                cHull[hullHead] = points[i];
                hullHead++;

            }
            cout << hullHead << endl;
            for(int i = 0 ; i < hullHead; i++)
            {
                printf("%.0f %.0f\n", i+1, cHull[i].x + orX, cHull[i].y + orY);
            }
            //printf("%.0f %.0f", cHull[0].x + orX, cHull[0].y + orY);
            cin >> k;
        }
    }

}
