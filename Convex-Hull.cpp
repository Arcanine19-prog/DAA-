// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// struct Point{
//     int x,y;
// };
// Point p0;

// int orientation(Point p,Point q,Point r){
//     int val=(q.y-p.y)*(r.x-q.x)-(q.x-p.x)*(r.y-q.y);
//     if(val==0)return 0;
//     return (val>0)?1:2;
// }

// int distance(Point p1,Point p2){
//     return (p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y);
// }

// bool compare(Point p1,Point p2){
//     int o=orientation(p0,p1,p2);
//     if(o==0) return distance(p0,p1)<distance(p0,p2);
//     return(o==2);
// }

// void addToHull(vector<Point>& hull,Point next){
//     if(hull.size()<2){
//         hull.push_back(next);
//         return;
//     }
//     Point q=hull.back();
//     hull.pop_back();
//     Point p=hull.back();
   
//     if(orientation(p,q,next)==2){
//         hull.push_back(q);
//         hull.push_back(next);
//     }
//     else{
//         addToHull(hull,next);
//     }
// }

// void printHull(const vector<Point>& hull){
//     cout<<"The points in the convex hull are:\n";
//     for(const auto& p: hull){
//         cout<<p.x<<" "<<p.y<<"\n";
//     }
// }

// void convexHull(vector<Point>& points){
//     int n=points.size();
//     int minY=0;
   
//     for(int i=1;i<n;i++){
//         if((points[i].y<=points[i].y) &&(points[i].x<points[i].x)){
//             minY=i;
//         }
//     }
   
//     swap(points[0],points[minY]);
//     p0=points[0];
   
//     sort(points.begin()+1,points.end(),compare);
   
//     int m=1;
//     for(int i=1;i<n;i++){
//         while(i<n-1 && orientation(p0,points[i],points[i+1])==0){
//             i++;
//         }
//         points[m++]=points[i];
//     }
//     if(m<3){
//         cout<<"Convex hull not possible\n";
//         return;
//     }
   
//     vector<Point> hull={points[0],points[1]};
//     for(int i=2;i<m;i++){
//         addToHull(hull,points[i]);
//     }
//     printHull(hull);
// }


// int main(){
//     int n;
//     cin>>n;
//     vector<Point> points(n);
//     for(int i=0;i<n;i++){
//         cin>>points[i].x>>points[i].y;
//     }
//     convexHull(points);
//     return 0;
   
// }



#include <iostream>
#include <climits>
#include <cstdlib>
#include <algorithm>

using namespace std;

struct Point {
    int x, y;
};

Point* p0; // Global pointer to the reference point

// Find the point with the lowest y (and lowest x if tie)
int findLowest(Point* p, int n) {
    int ind = 0;
    for (int i = 1; i < n; i++) {
        if (p[i].y < p[ind].y || (p[i].y == p[ind].y && p[i].x < p[ind].x)) {
            ind = i;
        }
    }
    return ind;
}

// Return orientation: 0 -> colinear, 1 -> counterclockwise, -1 -> clockwise
int orientation(Point* p1, Point* p2, Point* p3) {
    int val = (p2->x - p1->x) * (p3->y - p1->y) - (p2->y - p1->y) * (p3->x - p1->x);
    if (val > 0) return 1;       // counterclockwise
    else if (val < 0) return -1; // clockwise
    return 0;                    // colinear
}

// Squared distance between two points
int dist(Point* p1, Point* p2) {
    return (p1->x - p2->x) * (p1->x - p2->x) + (p1->y - p2->y) * (p1->y - p2->y);
}

// Compare function for qsort
int compare(const void* vp1, const void* vp2) {
    Point* p1 = (Point*)vp1;
    Point* p2 = (Point*)vp2;
    int o = orientation(p0, p1, p2);
    if (o == 0) {
        return dist(p0, p1) < dist(p0, p2) ? -1 : 1;
    }
    return (o == 1) ? -1 : 1;
}

// Graham's Scan to find convex hull
void convexHull(Point* p, int n) {
    if (n < 3) {
        cout << "Convex hull not possible\n";
        return;
    }

    int minInd = findLowest(p, n);
    swap(p[0], p[minInd]);

    p0 = p;

    qsort(p + 1, n - 1, sizeof(Point), compare);

    // Remove colinear points, keep the farthest
    int m = 1;
    for (int i = 1; i < n; i++) {
        while (i < n - 1 && orientation(p0, &p[i], &p[i + 1]) == 0) {
            i++;
        }
        p[m++] = p[i];
    }

    if (m < 3) {
        cout << "Convex hull not possible after removing colinear points\n";
        return;
    }

    Point* hull = new Point[m];
    int size = 0;

    hull[size++] = p[0];
    hull[size++] = p[1];
    hull[size++] = p[2];

    for (int i = 3; i < m; i++) {
        while (size >= 2 && orientation(&hull[size - 2], &hull[size - 1], &p[i]) <= 0) {
            size--;
        }
        hull[size++] = p[i];
    }

    cout << "\nConvex Hull:\n";
    for (int i = 0; i < size; i++) {
        cout << hull[i].x << " " << hull[i].y << endl;
    }

    delete[] hull;
}

int main() {
    int n;
    cout << "Enter number of points: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid number of points.\n";
        return 0;
    }

    Point* p = new Point[n];
    cout << "Enter " << n << " points (x y):\n";
    for (int i = 0; i < n; i++) {
        cin >> p[i].x >> p[i].y;
    }

    convexHull(p, n);

    delete[] p;
    return 0;
}
