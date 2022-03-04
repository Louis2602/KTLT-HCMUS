#include <iostream>
#include <cmath>
using namespace std;

struct Point{
    float x;
    float y;
};
void checkQuadrant(Point a) {
    if(a.x > 0 && a.y > 0)
        cout << "Up-right";
    else if(a.x > 0 && a.y < 0)
        cout << "Down-right";
    else if(a.x < 0 && a.y > 0)
        cout << "Up-left";
    else
        cout << "Down-left";
}
float CalcDistance(Point a, Point b) {
    return abs(sqrt((a.x*a.x - b.x*b.x)+(a.y*a.y - b.y*b.y)));
}
void midPoint(Point a, Point b, Point &mid)  {
    mid.x = (a.x + b.x)/2;
    mid.y = (a.y + b.y)/2;
}
int main() {
    Point a;
    cin >> a.x >> a.y;
    // checkQuadrant(a);
    Point b;
    cin >> b.x >> b.y;
    // float distance;
    // distance = CalcDistance(a, b);
    // cout << distance;
    Point mid;
    midPoint(a, b, mid);
    cout << "Mid point = (" << mid.x << " , " << mid.y << ")\n";
    return 0;
}
