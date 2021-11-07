#include <iostream>
#include <cmath>
#include "arrays.h"

using namespace std;

//struct Boundary
//{
//    int minX;
//    int minY;
//    int maxX;
//    int maxY;
//};
//
//Boundary findBoundary(int x0, int y0, int xn, int yn)
//{
//    Boundary result;
//    result.minX = min(x0,xn);
//    result.minY = min(y0,yn);
//    result.maxX = max(x0,xn);
//    result.maxY = max(y0,yn);
//    return result;
//}
//
//int calcUselessDistance(Boundary boundary, int x, int y)
//{
//    int xUseless = 0;
//    if (x < boundary.minX)
//        xUseless = boundary.minX - x;
//    else if (x > boundary.maxX)
//        xUseless = x - boundary.maxX;
//
//    int yUseless = 0;
//    if (y < boundary.minY)
//        yUseless = boundary.minY - y;
//    else if (y > boundary.maxY)
//        yUseless = y - boundary.maxY;
//    return xUseless + yUseless;
//}

int calcTotalManhattanDistance(int x[], int y[], int len)
{
    int sum=0;
    for(int i=0; i<len-1; i++)
        sum += abs(x[i+1]-x[i])+ abs(y[i+1]-y[i]);
    return sum;
}

int main()
{
    int len;
    cin >> len;

    if (len < 2)
    {
        cout << "invalid num points, expected value >= 2";
        return 1;
    }

    int x[len],y[len];
    for(int i=0; i<len ; i++)
        cin >> x[i] >> y[i];

    if (len == 2)
    {
        int sum = calcTotalManhattanDistance(x,y, len);
        cout << sum << endl;
        return 0;
    }

    int lenDecreasedBy1 = len-1;
    int resultX[lenDecreasedBy1], resultY[lenDecreasedBy1];

    int tobeRemoved = -1;
    int minDistance = INT_MAX;
    for (int i=1; i<len - 1; i++)
    {
        // remove point at i
        arrays::removeIntArrayAt(x, len, i, resultX);
        arrays::removeIntArrayAt(y, len, i, resultY);

        int distance = calcTotalManhattanDistance(resultX, resultY, lenDecreasedBy1);
        cout << "if remove point at " << i << " -> distance: " << distance << endl;

        if (distance < minDistance)
        {
            minDistance = distance;
            tobeRemoved = i;
        }
    }

    cout << "so, we will remove point at " << tobeRemoved << " to get min remaining distance " << minDistance << endl;

//    Boundary boundary = findBoundary(x[0], y[0], x[len-1],y[len-1]);
//    int maxUselessDistance = 0;
//    int uselessPointIndex = -1;
//    for (int i=1; i < len - 1; i++)
//    {
//        int uld = calcUselessDistance(boundary, x[i], y[i]);
//        if(uld <= maxUselessDistance)
//            continue;
//
//        maxUselessDistance = uld;
//        uselessPointIndex = i;
//    }
//
//
//    if (uselessPointIndex == -1)
//    {
//        cout << "there're no useless point, default skip second point";
//        uselessPointIndex = 1;
//    }
//
//    int optimizedX[len-1];
//    int optimizedY[len-1];
//
//    arrays::removeIntArrayAt(x, len, uselessPointIndex, optimizedX);
//    arrays::removeIntArrayAt(y, len, uselessPointIndex, optimizedY);
//
//    int sum = calcTotalManhattanDistance(optimizedX, optimizedY, len-1);
//    cout << sum << endl;
    return 0;
}
