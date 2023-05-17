#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using std::cin, std::cout, std::min, std::max, std::vector;

struct Point
{
public:
    int x = 0, y = 0;
    bool wasThere = false;

    Point() = default;
    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
};

// double distance(const int &x1, const int &y1, const int &x2, const int &y2)
double distance(const Point &p1, const Point &p2)
{
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

double sloap(const Point &p1, const Point &p2)
{
    return (p2.y - p1.y) / double(p2.x - p1.x);
}

int orientation(const Point &p1, const Point &p2, const Point &another)
{
    int result = (p2.y - p1.y) * (another.x - p2.x) - (p2.x - p1.x) * (another.y - p2.y);

    if (result == 0)
        return 0;              // ! collinear
    return result > 0 ? 1 : 2; // ! clock or counterclock
}

bool onSegment(Point p, Point q, Point r)
{
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
        return true;

    return false;
}

bool isIntersect(const Point &p1, const Point &p2, const Point &q1, const Point &q2)
{
    // *** p1,p2 - first segment
    // *** q1,q2 - second segment
    int ori0 = orientation(p1, p2, q1); // * first dot to first segment
    int ori1 = orientation(p1, p2, q2); // * second dot to first segment
    int ori2 = orientation(q1, q2, p1); // * first dot to second segment
    int ori3 = orientation(q1, q2, p2); // * second dot to second segment

    if (ori0 != ori1 && ori2 != ori3)
        return true; // ! general case

    if (ori0 == 0 && onSegment(p1, q1, p2))
        return true; // ! p1, p2, q1 - collinear, q1 - lies on first segment

    if (ori1 == 0 && onSegment(p1, q2, p2))
        return true; // ! p1, p2, q2 - collinear, q2 - lies on first segment

    if (ori2 == 0 && onSegment(q1, p1, q2))
        return true; // ! q1, q2, p1 - collinear, p1 - lies on second segment

    if (ori3 == 0 && onSegment(q1, p2, q2))
        return true; // ! q1, q2, p1 - collinear, p1 - lies on second segment

    return false;
}

void test_orientation();

void test_isIntersect();

void output_Point(const Point *points, const int &size);

void findStart(const Point *points, const int &size, int &x, int &y)
{
    x = y = 10000;
    int curX, curY;
    for (int i = 0; i < size; i++)
    {
        if (points[i].wasThere)
            continue;

        curX = points[i].x;
        curY = points[i].y;
        if (curX < x)
        {
            x = curX;
            y = curY;
            continue;
        }
        if (curY < y && x == curX)
            y = curY;
    }
}

int main()
{
    // test_orientation();
    // test_isIntersect();
    int size = 3, x, y, counter = 0;
    Point *points = new Point[size];

    // vector<int> x = {0, 3, 1, 3, 3, 5};
    // vector<int> y = {0, 0, 2, 1, -1, 0};

    // vector<int> x = {0, 0, 1, 3, 0, 3};
    // vector<int> y = {0, 3, 2, 3, 4, 5};

    for (int i = 0; i < size; i++)
    {
        cout << "Enter x,y: ";
        cin >> x >> y;

        points[i].x = x;
        points[i].y = y;
    }

    output_Point(points, size);

    while (counter != size - 1)
    {
        findStart(points, size, x, y);
        cout << "Point: " << x << ',' << y << '\n';
    }

    return 0;
}

void test_orientation()
{
    Point p1 = {0, 0}, p2 = {4, 4}, p3 = {1, 2};
    int o = orientation(p1, p2, p3);
    if (o == 0)
        cout << "Linear";
    else if (o == 1)
        cout << "Clockwise";
    else
        cout << "CounterClockwise";
    cout << '\n';

    p1 = {0, 0}, p2 = {4, 4}, p3 = {1, 1};
    o = orientation(p1, p2, p3);
    if (o == 0)
        cout << "Linear";
    else if (o == 1)
        cout << "Clockwise";
    else
        cout << "CounterClockwise";
    cout << '\n';

    p1 = {1, 2}, p2 = {4, 4}, p3 = {0, 0};
    o = orientation(p1, p2, p3);
    if (o == 0)
        cout << "Linear";
    else if (o == 1)
        cout << "Clockwise";
    else
        cout << "CounterClockwise";
}

void test_isIntersect()
{
    Point p1 = {1, 1}, q1 = {10, 1};
    Point p2 = {1, 2}, q2 = {10, 2};
    isIntersect(p1, q1, p2, q2) ? cout << "Yes\n" : cout << "No\n";

    p1 = {10, 0}, q1 = {0, 10};
    p2 = {0, 0}, q2 = {10, 10};
    isIntersect(p1, q1, p2, q2) ? cout << "Yes\n" : cout << "No\n";

    p1 = {-5, -5}, q1 = {0, 0};
    p2 = {1, 1}, q2 = {10, 10};
    isIntersect(p1, q1, p2, q2) ? cout << "Yes\n" : cout << "No\n";
}

void output_Point(const Point *points, const int &size)
{
    for (int i = 0; i < size; i++)
        cout << i + 1 << ": " << points[i].x << ',' << points[i].y << '\n';
}