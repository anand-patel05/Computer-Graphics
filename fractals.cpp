#include <graphics.h>
#include <stdio.h>
#define MAXCOUNT 30

void fractal(float left, float top, float xside, float yside)
{
	float xscale, yscale, zx, zy, cx, tempx, cy;
	int x, y, i, j;
	int maxx, maxy, count;

	maxx = getmaxx();

	maxy = getmaxy();

	xscale = xside / maxx;
	yscale = yside / maxy;

	rectangle(0, 0, maxx, maxy);

	for (y = 1; y <= maxy - 1; y++) {
		for (x = 1; x <= maxx - 1; x++)
		{
			// c_real
			cx = x * xscale + left;

			// c_imaginary
			cy = y * yscale + top;

			// z_real
			zx = 0;

			// z_imaginary
			zy = 0;
			count = 0;

			while ((zx * zx + zy * zy < 4) && (count < MAXCOUNT))
			{
				// tempx = z_real*_real - z_imaginary*z_imaginary + c_real
				tempx = zx * zx - zy * zy + cx;

				// 2*z_real*z_imaginary + c_imaginary
				zy = 2 * zx * zy + cy;

				// Updating z_real = tempx
				zx = tempx;

				// Increment count
				count = count + 1;
			}

			// To display the created fractal
			putpixel(x, y, count);
		}
	}
}

// Driver code
int main()
{

	int gd = DETECT, gm, errorcode;

	float left, top, xside, yside;

	left = -1.75;
	top = -0.25;
	xside = 0.25;
	yside = 0.45;
	char driver[] = "";

	initgraph(&gd, &gm, driver);

	// Function calling
	fractal(left, top, xside, yside);

	getch();
	
	closegraph();

	return 0;
}
