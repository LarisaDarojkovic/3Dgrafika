#include <iostream>
#include <vector>
#include "splines.h"
using namespace std;

int main(){
    ControlPoint P1(0,0);
    ControlPoint P2(2,4);
    ControlPoint P3(6,4);
    ControlPoint P4(8,0);
    BezierSpline spline(P1, P2, P3, P4, 0.5);
    cout << "Vrijednost Bezierovog splinea: " << "(" << spline.GetPoint(P1.getx(), P1.gety(), 
                                    P2.getx(), P2.gety(), P3.getx(), P3.gety(), P4.getx(), P4.gety(), 0.5)[0] << ", " << 
                                    spline.GetPoint(P1.getx(), P1.gety(), P2.getx(), P2.gety(), P3.getx(), P3.gety(), 
                                    P4.getx(), P4.gety(), 0.5)[4] << ")" << endl;
    HermiteSpline hspline(P1, P2, P3, P4, 0.5);
    vector<float> bezier_to_hermite = hspline.BezierToHermite(spline);
    cout << "Hermite ekvivalentan Bezierovom spline-u je: " << endl;
    cout << "P0 = (" << bezier_to_hermite[0] << ", " << bezier_to_hermite[4] << ")" << endl;
    cout << "P1 = (" << bezier_to_hermite[1] << ", " << bezier_to_hermite[5] << ")" << endl;
    cout << "P2 = (" << bezier_to_hermite[2] << ", " << bezier_to_hermite[6] << ")" << endl;
    cout << "P3 = (" << bezier_to_hermite[3] << ", " << bezier_to_hermite[7] << ")" << endl;

    return 0;
}