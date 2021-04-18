#include <stdio.h>
#include <stdlib.h>

typedef struct Shape
{
    int x;
    int y;

    void (*display)(void* this);
} Shape;

typedef struct Square
{
    Shape base;
    
    int z;
} Square;

typedef struct Circle
{
    Shape base;

    int radius;    
} Circle;

void squareDisplay(void* this)
{
    Square* square = this;
    printf("I'm a square. X = %d, Y = %d, Z = %d", square->base.x, square->base.y, square->z);
}

Square* _Square(int x, int y, int z)
{
    Square* square = (Square*)malloc(sizeof(Square));
    square->base = (Shape) { x, y };
    square->base.display = squareDisplay;

    return square;
}

void circleDisplay(void* this)
{
    Circle* circle = this;
    printf("I'm a circle. X = %d, Y = %d, Radious = %d", circle->base.x, circle->base.y, circle->radius);
}

Circle* _Circle(int x, int y, int z)
{
    Circle* circle = (Circle*)malloc(sizeof(Circle));
    circle->radius = 200;
    circle->base = (Shape) { x, y };
    circle->base.display = circleDisplay;

    return circle;
}

int main()
{
    Square* square = _Square(5, 5, 5);
    Circle* circle = _Circle(2, 3, 1);

    Shape* shape = (Shape*)square;

    shape->display(shape);

    return 0;
}