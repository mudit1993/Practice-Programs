#include <stdio.h>
#include <stdlib.h>

// Utility function to find minimum of two integers
int min(int x, int y) { return (x < y)? x: y; }

double calcAngle(double h, double m)
{
    // validate the input
    if (h <0 || m < 0 || h >12 || m > 60)
        printf("Wrong input");

    if (h == 12) h = 0;
    if (m == 60) m = 0;

    // Calculate the angles moved by hour and minute hands
    // with reference to 12:00
    double hour_angle = 0.5 * (h*60 + m);//359.5
    double minute_angle = 6*m;  //354

    // Find the difference between two angles
    double angle = abs(hour_angle - minute_angle);

    // Return the smaller angle of two possible angles
    angle = min(360-angle, angle);

    return angle;
}

// Driver program to test above function
int main()
{
    printf("%lf \n", calcAngle(11, 59));
    printf("%lf \n", calcAngle(3, 30));
    return 0;
}