typedef struct shape
{
    int x, y;

    void (*display)(void*);
} Shape;

typedef struct circle
{
    Shape base;

    int radius;

    void (*displayRadius)(struct circle*);
} Circle;

extern Circle* _circle(int, int, int);
extern void __circle(Circle*);

typedef struct square
{
    Shape base;

    int side;

    void (*displaySide)(struct square*);
} Square;

extern Square* _square(int, int, int);
extern void __square(Square*);