// C++ program for Mid-point line generation
#include<bits/stdc++.h>
using namespace std;
 
// Header file for including graphics functions
// #include<graphics.h>
 
// midPoint function for line generation
void midPoint(int X1, int Y1, int X2, int Y2)
{
    // calculate dx & dy
    int dx = X2 - X1;
    int dy = Y2 - Y1;
 
    // initial value of decision parameter d
    int d = dy - (dx/2);
    int x = X1, y = Y1;
 
    // Plot initial given point
    // putpixel(x,y) can be used to print pixel
    // of line in graphics
    cout << x << "," << y << "\n";
 
    // iterate through value of X
    while (x < X2)
    {
        x++;
 
        // E or East is chosen
        if (d < 0)
            d = d + dy;
 
        // NE or North East is chosen
        else
        {
            d += (dy - dx);
            y++;
        }
 
        // Plot intermediate points
        // putpixel(x,y) is used to print pixel
        // of line in graphics
        cout << x << "," << y << "\n";
    }
}
 
// Driver program
int main()
{
    // graphics driver and mode
    // used in graphics.h
    // int gd = DETECT, gm;
 
    // Initialize graphics function
    // initgraph (&gd, &gm, "");
 
    int X1 = 10, Y1 = 10, X2 = 100, Y2 = 500;
    midPoint(X1, Y1, X2, Y2);
    return 0;
}
