#define VIDEO_MODE 0xA000

#define WSCREEN 320
#define HSCREEN 200

void set_pixel(int x, int y, unsigned char COLOR);

void draw_line
(
    int x0, int y0,
    int x1, int y1,
    unsigned char COLOR
);
