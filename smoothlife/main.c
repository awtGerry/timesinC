#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 100
#define HEIGHT 100

char levels[] = " @.-wcrA#";
const size_t levels_size = (sizeof(levels)/sizeof(levels[0]));

float red[HEIGHT][WIDTH] = {0};

int x = 0, y = 0;

float m = 0;
float n = 0;
float ra = 21;

float num_random(void) {
    return (float)rand()/(float)RAND_MAX;
}

void red_random(void) {
    for (size_t y = 0; y < HEIGHT; y+=1) {
        for (size_t x = 0; x < WIDTH; x+=1) {
            red[y][x] = num_random();
        }
    }
}

int euclid(int a, int b) {
    return (a%b + b)%b;
}

void mostrar_red(void) {
    for (size_t y = 0; y < HEIGHT; y+=1) {
        for (size_t x = 0; x < WIDTH; x+=1) {
            char out = levels[(int)(red[y][x]*(levels_size - 1))];
            printf("%c", out);
        }
        printf("\n");
    }
}

int main(void) {
    srand(time(0));
    float ri = ra/3; // ra = 3ri

    red_random();

    for (int dy = -(ra - 1); dy <= (ra-1); dy+=1) {
        for (int dx = -(ra - 1); dx <= (ra-1); dx+=1) {
            int res_x = euclid(x + dx, WIDTH);
            int res_y = euclid(y + dy, HEIGHT);
            if (dx*dx + dy*dy <= ri)
                m += red[res_y][res_x];
            else if (dx*dx + dy*dy <= ra*ra)
                n += red[res_y][res_x];
        }
    }

    mostrar_red();

    return 0;
}
