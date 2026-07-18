typedef struct
{
    float x, y, z;
} VERTEX;

typedef struct
{
    int x, y;
} EDGE;

void rotate_x(VERTEX* vertex, float angle);
void rotate_y(VERTEX* vertex, float angle);
void rotate_z(VERTEX* vertex, float angle);

void draw_cube
(
    VERTEX* vtx,
    EDGE* edges,
    int size,
    int edge_num,
    unsigned char color
);