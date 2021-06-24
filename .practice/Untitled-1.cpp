#include <stdio.h>
#include <graphics.h>
#include <math.h>

#define X 640
#define Y 480

void lineBresenham(int, int, int, int, int);

int main(void)
{
    int x1, y1, x2, y2;
    printf("Enter the points: ");
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    initwindow(X, Y);

    circle(x1, y1, 5);
    circle(x2, y2, 5);

    lineBresenham(x1, y1, x2, y2, 12);

    getch();
    return 0;
}

void lineBresenham(int x1, int y1, int x2, int y2, int color)

{
    int x, y, xInc, yInc, d, dx, dy, absDx, absDy;

    x = x1;
    y = y1;
    dx = x2 - x1;
    dy = y2 - y1;
    absDx = abs(dx);
    absDy = abs(dy);

    if (x1 == x2 && y1 == y2)
        putpixel(x1, y1, color);
    else if (y1 == y2)
    {
        if (x1 < x2)
            xInc = 1;
        else
            xInc = -1;

        while (x != x2)
        {
            putpixel(x, y, color);
            x += xInc;
            delay(1);
        }
        putpixel(x, y, color);
    }
    else if (x1 == x2)
    {

        if (y1 < y2)
            yInc = 1;
        else
            yInc = -1;
        while (y != y2)
        {
            putpixel(x, y, color);
            y = y + yInc;
            delay(1);
        }
        putpixel(x, y, color);
    }
    else if (absDy < absDx)
    {

        if (x1 < x2)
            xInc = 1;
        else
            xInc = -1;

        if (y1 < y2)
            yInc = 1;
        else
            yInc = -1;

        d = 2 * absDy - absDx;
        while (x != x2)
        {
            if (d > 0)
            {
                d = d + 2 * absDy - 2 * absDx;
                y += yInc;
            }
            else
                d = d + 2 * absDy;
            x += xInc;
            putpixel(x, y, color);
            delay(1);
        }
    }
    else
    {

        if (x1 < x2)
            xInc = 1;
        else
            xInc = -1;

        if (y1 < y2)
            yInc = 1;
        else
            yInc = -1;

        d = 2 * absDx - absDy;

        while (y != y2)
        {
            if (d > 0)
            {
                d = d + 2 * absDx - 2 * absDy;
                x += xInc;
            }
            else
                d = d + 2 * absDx;
            y += yInc;
            delay(1);
            putpixel(x, y, color);
        }
    }
}