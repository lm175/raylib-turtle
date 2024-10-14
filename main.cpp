#include "turtle.h"
#include <iostream>

int main()
{
    Turtle turtle;
    for (int i = 0; i < 4; i++) {
        turtle.forward(100);
        turtle.right(90);
    }
    turtle.done();
    return 0;
}