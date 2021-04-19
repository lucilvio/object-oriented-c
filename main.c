#include <stdio.h>
#include <stdlib.h>

#include "shape.h"

int main()
{
    Square* square = _square(5, 5, 8);
    square->displaySide(square);

    Circle* circle = _circle(2, 3, 200);
    circle->displayRadius(circle);

    Shape* shape = (Shape*)square;

    shape->display(shape);

    shape = (Shape*)circle;

    shape->display(shape);
    
    __square(square);
    __circle(circle);

    return 0;
}