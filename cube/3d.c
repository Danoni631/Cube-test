#include "cube.h"

void rotate_x(VERTEX* vertex, float angle)
{
    vertex->y = cos(angle) * vertex->y - sin(angle) * vertex->z;
    vertex->z = sin(angle) * vertex->y + cos(angle) * vertex->z;
}

void rotate_y(VERTEX* vertex, float angle)
{
    vertex->y = cos(angle) * vertex->x + sin(angle) * vertex->z;
    vertex->z = sin(angle) * vertex->x + cos(angle) * vertex->z; 
}

void rotate_z(VERTEX* vertex, float angle)
{
    vertex->y = cos(angle) * vertex->x - sin(angle) * vertex->z;
    vertex->z = sin(angle) * vertex->x + cos(angle) * vertex->z; 
}

void draw_cube
(
    VERTEX* vtx,
    EDGE* edges,
    int size,
    int edge_num,
    unsigned char color
)
{
    int cx = (WSCREEN / 2) - (size / 2);
    int cy = (HSCREEN / 2) - (size / 2);

    for (int i = 0; i < edge_num; i++)
    {
        draw_line
        (
            vtx[edges[i].x].x + cx,
            vtx[edges[i].x].y + cy,
            vtx[edges[i].y].x + cx,
            vtx[edges[i].y].y + cy,
            color
        );
    }
}