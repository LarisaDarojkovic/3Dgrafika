#include<iostream>
#include<vector>
#include <cmath>
#include "splines.h"

using namespace std;

pair<BezierSpline, BezierSpline> SubdivideBezier(BezierSpline bs, float t) {
    ControlPoint P12((1-t)*bs.P1.getx() + t*bs.P2.getx(), (1-t)*bs.P1.gety() + t*bs.P2.gety());
    ControlPoint P23((1-t)*bs.P2.getx() + t*bs.P3.getx(), (1-t)*bs.P2.gety() + t*bs.P3.gety());
    ControlPoint P34((1-t)*bs.P3.getx() + t*bs.P4.getx(), (1-t)*bs.P3.gety() + t*bs.P4.gety());
    ControlPoint P123((1-t)*P12.getx() + t*P23.getx(), (1-t)*P12.gety() + t*P23.gety());
    ControlPoint P234((1-t)*P23.getx() + t*P34.getx(), (1-t)*P23.gety() + t*P34.gety());
    ControlPoint P1234((1-t)*P123.getx() + t*P234.getx(), (1-t)*P123.gety() + t*P234.gety());

    BezierSpline bs1(bs.P1, P12, P123, P1234, t);
    BezierSpline bs2(P1234, P234, P34, bs.P4, t);

    return make_pair(bs1, bs2);
}

ostream& operator<<(ostream& os, ControlPoint& p) {
    return os << "(" << p.getx() << ", " << p.gety() << ")";
}

int main(){
    float t = 0.5;
    ControlPoint P1(0,0);
    ControlPoint P2(2,4);
    ControlPoint P3(6,4);
    ControlPoint P4(8,0);
    BezierSpline spline(P1, P2, P3, P4, t);

    pair<BezierSpline,BezierSpline> main_splain = SubdivideBezier(spline, t);

    cout << "BezierSpline 1: " << main_splain.first.P1 << ", " << main_splain.first.P2 << ", " << main_splain.first.P3 << ", " << main_splain.first.P4 << endl;
    cout << "BezierSpline 2: " << main_splain.second.P1 << ", " << main_splain.second.P2 << ", " << main_splain.second.P3 << ", " << main_splain.second.P4 << endl;

    return 0;
}
