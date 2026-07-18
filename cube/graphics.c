#include "cube.h"

void set_pixel(int x, int y, unsigned char COLOR)
{
    unsigned char* vga = (unsigned char*) VIDEO_MODE;
    vga[y * WSCREEN + x] = COLOR;
}

void draw_line
(
    int x0, int y0,
    int x1, int y1,
    unsigned char COLOR
)
{
    int dx =  abs(x1 - x0);
    int dy = -abs(y1 - y0);

    int sx = (x0 < x1) ? 1 : -1;
    int sy = (y0 < y1) ? 1 : -1;

    int error = dx + dy;

    while (true)
    {
        set_pixel(x0, y0, COLOR);

        if (x0 == x1 && y0 == y1)
        {
            break;
        }

        int e2 = 2 * error;

        if (e2 >= dy)
        {
            if (x0 == x1)
            {
                break;
            }

            error += dy;
            x0 += sx;
        }

        if (e2 <= dx)
        {
            if (y0 == y1)
            {
                break;
            }

            error += dx;
            y0 += sy;
        }
    }
}