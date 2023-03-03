#pragma once
#include<cmath>
#include <iostream>
#include <vector>

using namespace std;

class ControlPoint{
public:
    int x, y;
    ControlPoint() : x(0), y(0) {}
    ControlPoint(int x, int y) : x(x), y(y) {}
    int getx() {return x;}
    int gety() {return y;} 
};

/*1. zadatak*/
class BezierSpline{
    public:
        ControlPoint P1;
        ControlPoint P2;
        ControlPoint P3;
        ControlPoint P4;
        float t;
        
        BezierSpline() : P1(0,0), P2(0,0), P3(0,0), P4(0,0), t(0) {}
        BezierSpline(ControlPoint p1, ControlPoint p2, ControlPoint p3, ControlPoint p4, float t) : P1(p1), P2(p2), P3(p3), P4(p4), t(t) {} 
        
        vector<float> GetPoint(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, float t){
            
            vector<float> arr_x;
            vector<float> arr_y;

            arr_x.push_back(x1);
            arr_x.push_back(x2);
            arr_x.push_back(x3);
            arr_x.push_back(x4);
            arr_y.push_back(y1);
            arr_y.push_back(y2);
            arr_y.push_back(y3);
            arr_y.push_back(y4);

            int n = 4;
            for (int k = 1; k < n; k++){
                for (int i = 0; i < n-k; i++){
                    arr_x[i] = (1-t)*arr_x[i] + t*arr_x[i+1];
                    arr_y[i] = (1-t)*arr_y[i] + t*arr_y[i+1];
                }
            }
            vector<float> result;
            result.push_back(arr_x[0]);
            result.push_back(arr_x[1]);
            result.push_back(arr_x[2]);
            result.push_back(arr_x[3]);
            result.push_back(arr_y[0]);
            result.push_back(arr_y[1]);
            result.push_back(arr_y[2]);
            result.push_back(arr_y[3]);
            return result;
        }
};

/*2. zadatak*/
class HermiteSpline{
    private:
        ControlPoint P1;
        ControlPoint P2;
        ControlPoint P3;
        ControlPoint P4;
        float t;
    public:
        HermiteSpline() : P1(0,0), P2(0,0), P3(0,0), P4(0,0), t(0) {}
        HermiteSpline(ControlPoint p1, ControlPoint p2, ControlPoint p3, ControlPoint p4, float t) : P1(p1), P2(p2), P3(p3), P4(p4), t(t) {}
        vector<float> BezierToHermite(BezierSpline b){
            vector<float> bezierSpline = b.GetPoint(P1.getx(), P1.gety(), P2.getx(), P2.gety(), P3.getx(), P3.gety(), P4.getx(), P4.gety(), 0.5);
            vector<float> result;

            result.push_back(bezierSpline[0]);
            result.push_back(3*(bezierSpline[1] - bezierSpline[0]));
            result.push_back(bezierSpline[2]);
            result.push_back(3*(bezierSpline[3] - bezierSpline[2]));
            result.push_back(bezierSpline[4]);
            result.push_back(3*(bezierSpline[5] - bezierSpline[4]));
            result.push_back(bezierSpline[6]);
            result.push_back(3*(bezierSpline[6] - bezierSpline[6]));

            return result;
        }
};
