// C program for the above approach

#include <conio.h>
#include <graphics.h>
#include <stdio.h>

// Driver Code
int main()
{
	// Initialize the drivers
	int gm, gd = DETECT, ax, x1 = 100;
	int x2 = 100, x3 = 200, y1 = 100;
	int y2 = 200, y3 = 100;

	// Add in your BGI folder path
	// like below initgraph(&gd, &gm,
	// "C:\\TURBOC3\\BGI");
	initgraph(&gd, &gm, "");
	cleardevice();

	// Draw the graph
	line(getmaxx() / 2, 0, getmaxx() / 2,
		getmaxy());
	line(0, getmaxy() / 2, getmaxx(),
		getmaxy() / 2);

	// Object initially at 2nd quadrant
	printf("Before Reflection Object"
		" in 2nd Quadrant");

	// Set the color
	setcolor(14);
	line(x1, y1, x2, y2);
	line(x2, y2, x3, y3);
	line(x3, y3, x1, y1);
	//getch();

	// After reflection
	printf("\nAfter Reflection");

	// Reflection along origin i.e.,
	// in 4th quadrant
	setcolor(4);
	line(getmaxx() - x1, getmaxy() - y1,
		getmaxx() - x2, getmaxy() - y2);

	line(getmaxx() - x2, getmaxy() - y2,
		getmaxx() - x3, getmaxy() - y3);

	line(getmaxx() - x3, getmaxy() - y3,
		getmaxx() - x1, getmaxy() - y1);

	// Reflection along x-axis i.e.,
	// in 1st quadrant
	setcolor(3);
	line(getmaxx() - x1, y1,
		getmaxx() - x2, y2);
	line(getmaxx() - x2, y2,
		getmaxx() - x3, y3);
	line(getmaxx() - x3, y3,
		getmaxx() - x1, y1);

	// Reflection along y-axis i.e.,
	// in 3rd quadrant
	setcolor(2);
	line(x1, getmaxy() - y1, x2,
		getmaxy() - y2);
	line(x2, getmaxy() - y2, x3,
		getmaxy() - y3);
	line(x3, getmaxy() - y3, x1,
		getmaxy() - y1);
	getch();

	// Close the graphics
	closegraph();
}
