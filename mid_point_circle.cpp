//#include<iostream.h>
#include <stdio.h>
#include <dos.h>
#include<graphics.h>
 
void drawcircle(int x0, int y0, int radius)
{
    int x = radius;
    int y = 0;
    int err = 0;
 
    while (x >= y)
    {
putpixel(x0 + x, y0 + y, 7);
putpixel(x0 + y, y0 + x, 7);
putpixel(x0 - y, y0 + x, 7);
putpixel(x0 - x, y0 + y, 7);
putpixel(x0 - x, y0 - y, 7);
putpixel(x0 - y, y0 - x, 7);
putpixel(x0 + y, y0 - x, 7);
putpixel(x0 + x, y0 - y, 7);
 
if (err <= 0)
{
    y += 1;
    err += 2*y + 1;
}
 
if (err > 0)
{
    x -= 1;
    err -= 2*x + 1;
}
    }
}
 
int main()
{
int gd=DETECT, gm, error, x, y, r;
initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
 
// printf("Enter radius of circle: ");
// scanf("%d", &r);
 
// printf("Enter co-ordinates of center(x and y): ");
// scanf("%d %d", &x, &y);
r = 100;
x = 150; y =150;
drawcircle(x, y, r);
delay(10000);
 
return 0;
}