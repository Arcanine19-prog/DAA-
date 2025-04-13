#include <iostream>
#include <cmath>
using namespace std;

struct Point
{
    double x, y;
};
int orientation(Point p, Point q, Point r)
{
    double val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0)
        return 0;
    return (val > 0) ? 1 : 2;
}
bool onSegment(Point p, Point q, Point r)
{
    return (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
            q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y));
}
bool doIntersect(Point p1, Point q1, Point p2, Point q2, Point &intersection)
{
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);

    if (o1 != o2 && o3 != o4)
    {
        double a1 = q1.y - p1.y;
        double b1 = p1.x - q1.x;
        double c1 = a1 * p1.x + b1 * p1.y;
        
        double a2 = q2.y - p2.y;
        double b2 = p2.x - q2.x;
        double c2 = a2 * p2.x + b2 * p2.y;
        double det = a1 * b2 - a2 * b1;
        if (det != 0)
        {
            intersection.x = (b2 * c1 - b1 * c2) / det;
            intersection.y = (a1 * c2 - a2 * c1) / det;
        }
        return true;
    }
    return false;
}
bool areParallel(Point p1, Point q1, Point p2, Point q2)
{
    return ((q1.y - p1.y) * (q2.x - p2.x) == (q2.y - p2.y) * (q1.x - p1.x));
}
bool areCollinear(Point p1, Point q1, Point p2, Point q2)
{
    return (orientation(p1, q1, p2) == 0 && orientation(p1, q1, q2) == 0);
}

int main() {
    const int num_segments = 6;
    Point segments[num_segments][2];

    // Input points
    for (int i = 0; i < num_segments; i++) {
        cin >> segments[i][0].x >> segments[i][0].y;
        cin >> segments[i][1].x >> segments[i][1].y;
    }

    char labels[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L'};

    for (int i = 0; i < num_segments; i++) {
        for (int j = i + 1; j < num_segments; j++) {
            Point intersection;
            if (doIntersect(segments[i][0], segments[i][1], segments[j][0], segments[j][1], intersection)) {
                cout << "Line " << labels[i * 2] << labels[i * 2 + 1] << " and " << labels[j * 2] << labels[j * 2 + 1] << " Intersection at (" << intersection.x << ", " << intersection.y << ")\n";
            } else if (areCollinear(segments[i][0], segments[i][1], segments[j][0], segments[j][1])) {
                cout << "Line " << labels[i * 2] << labels[i * 2 + 1] << " and " << labels[j * 2] << labels[j * 2 + 1] << " are Collinear\n";
            } else if (areParallel(segments[i][0], segments[i][1], segments[j][0], segments[j][1])) {
                cout << "Line " << labels[i * 2] << labels[i * 2 + 1] << " and " << labels[j * 2] << labels[j * 2 + 1] << " are Parallel\n";
            } else {
                cout << "Line " << labels[i * 2] << labels[i * 2 + 1] << " and " << labels[j * 2] << labels[j * 2 + 1] << " have No Intersection\n";
            }
        }
    }
    return 0;
}