#include "cube.h"

void animate()
{
    float size = 80;

    float angleX = 0.001;
    float angleY = 0.001;
    float angleZ = 0.001;

    VERTEX vtx[] =
    {
        {size,  0.0, 0.0},
        {size, size, 0.0},
        {0.0,  size, 0.0},
        {0.0,   0.0, 0.0},

        {size,  0.0, size},
        {size, size, size},
        {0.0,  size, size},
        {0.0,   0.0, size}
    };

    EDGE edges[] =
    {
        {0, 1},
        {1, 2},
        {2, 3},
        {3, 0},
    
        {0, 4},
        {1, 5},
        {2, 6},
        {3, 7},

        {4, 5},
        {5, 6},
        {6, 7},
        {7, 4}
    };

    while (true)
    {
        int totvtx = sizeof(vtx) / sizeof(vtx[0]);
        int totedges = sizeof(edges) / sizeof(edges[0]);

        for (int i = 0; i < totvtx; i++)
        {
            rotate_x(&vtx[i], angleX);
            rotate_y(&vtx[i], angleY);
            rotate_z(&vtx[i], angleZ);
        }

        draw_cube(vtx, edges, size, totedges, 0x0F);

        delay(10000 * 100);

        draw_cube(vtx, edges, size, totedges, 0x00);
    }
}