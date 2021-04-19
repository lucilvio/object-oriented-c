#include <stdio.h>
#include <stdlib.h>

#include "shape.h"

// Type implementation details. Client code doesn't have access to this code.

void squareDisplay(void* this)
{
    Square* square = this;
    printf("I'm a square. X = %d, Y = %d, Side = %d\n", square->base.x, square->base.y, square->side);
}

void displaySide(Square* this)
{
    printf("Square side: %d\n", this->side);
}

Square* _square(int x, int y, int side)
{
    Square* square = (Square*)malloc(sizeof(Square));
    square->base = (Shape) { x, y };
    square->base.display = squareDisplay;
    
    square->side = side;
    square->displaySide = displaySide;

    return square;
}

void __square(Square* square)
{
    free(square);
}

void circleDisplay(void* this)
{
    Circle* circle = this;
    printf("I'm a circle. X = %d, Y = %d, Radius = %d\n", circle->base.x, circle->base.y, circle->radius);
}

void displayRadius(Circle* this)
{
    printf("Circle radius: %d\n", this->radius);
}

Circle* _circle(int x, int y, int radius)
{
    Circle* circle = (Circle*)malloc(sizeof(Circle));
    circle->base = (Shape) { x, y };
    circle->base.display = circleDisplay;
    
    circle->radius = radius;
    circle->displayRadius = displayRadius;

    return circle;
}

void __circle(Circle* circle)
{
    free(circle);
}