#include "turtle.h"

void TurtleAlgorithms::task_A1(int side, int min) {
    if (side < min) {
        return;
    }
    for (int i = 0; i < 4; i++) {
        forward(side);
        task_A1(side / 2, min);
        right(90);
    }
}

void TurtleAlgorithms::task_A2(int side, int min) {
    if (side < min) {
        return;
    }
    for (int i = 0; i < 3; i++) {
        forward(side);
        task_A2(side / 2, min);
        right(120);
    }
}

void TurtleAlgorithms::task_A3(int side, int min) {
    if (side < min) {
        return;
    }
    left(90);
    for (int i = 0; i < 4; i++) {
        forward(side);
        task_A3(side / 2, min);
        right(90);
    }
    right(90);
}

void TurtleAlgorithms::task_A4(int side, int min) {
    if (side < min) {
        return;
    }
    left(60);
    for (int i = 0; i < 3; i++) {
        forward(side);
        task_A4(side / 2, min);
        right(120);
    }
    right(60);
}

void TurtleAlgorithms::task_A5(int side, int min) {
    if (side < min) {
        return;
    }
    right(60);
    for (int i = 0; i < 3; i++) {
        forward(side);
        task_A5(side / 2, min);
        right(120);
    }
    left(60);
}

void TurtleAlgorithms::task_A6(int side, int min) {
    if (side < min) {
        return;
    }
    left(90);
    for (int i = 0; i < 4; i++) {
        forward(side / 4);
        task_A6(side / 2, min);
        forward(side / 4 * 3);
        right(90);
    }
    right(90);
}

void TurtleAlgorithms::task_A7(int side, int min) {
    if (side < min) {
        return;
    }
    left(60);
    for (int i = 0; i < 3; i++) {
        forward(side / 3);
        task_A7(side / 2, min);
        forward(side / 3 * 2);
        right(120);
    }
    right(60);
}

void TurtleAlgorithms::task_A8(int side, int min) {
    if (side < min) {
        return;
    }
    left(120);
    for (int i = 0; i < 6; i++) {
        forward(side / 4);
        task_A8(side / 2, min);
        forward(side / 4 * 3);
        right(60);
    }
    right(120);
}

void TurtleAlgorithms::task_A9(int side, int min) {
    while (side > min) {
        forward(side);
        right(90);
        side -= min;
    }
}

void TurtleAlgorithms::task_A10(int side, int min) {
    while (side > min) {
        forward(side);
        left(120);
        side -= min;
    }
}

void TurtleAlgorithms::task_A11(int side, int min) {
    while (side > min) {
        forward(side);
        left(60);
        side -= min;
    }
}

void TurtleAlgorithms::task_A12(int side, int min) {
    if (side < min) {
        return;
    }
    for (int i = 0; i < 3; i++) {
        task_A12(side / 2, min);
        forward(side);
        right(120);
    }
}

void TurtleAlgorithms::task_A13(int side, int min) {
    if (side < min) {
        return;
    }
    forward(side);
    left(45);
    task_A13(side / 3 * 2, min);
    right(90);
    task_A13(side / 3 * 2, min);
    left(45);
    back(side);
}

void TurtleAlgorithms::task_B1(int side, int min) {
    if (side < min) {
        return;
    }
    for (int i = 0; i < 2; i++) {
        right(90);
        forward(side);
        right(90);
        forward(side);
        task_B1(side / 2, min);
    }
}

void TurtleAlgorithms::task_B2(int side, int min) {
    if (side < min) {
        return;
    }
    left(120);
    for (int i = 0; i < 3; i++) {
        forward(side / 4);
        task_B2(side / 2, min);
        forward(side / 4 * 3);
        right(60);
        forward(side);
        right(60);
    }
    right(120);
}

void TurtleAlgorithms::task_B3(int side, int min) {
    if (side < min) {
        return;
    }
    left(90);
    for (int i = 0; i < 2; i++) {
        forward(side);
        right(90);
        forward(side / 4);
        task_B3(side / 2, min);
        forward(side / 4 * 3);
        right(90);
    }
    right(90);
}

void TurtleAlgorithms::task_B4(int side, int min) {
    if (side < min) {
        return;
    }
    left(90);
    for (int i = 0; i < 2; i++) {
        forward(side);
        task_B4(side / 2, min);
        right(90);
        forward(side);
        right(90);
    }
    right(90);
}

void TurtleAlgorithms::task_B5(int side, int min) {
    if (side < min) {
        return;
    }
    for (int i = 0; i < 4; i++) {
        forward(side);
        right(90);
        task_B5(side / 3, min);
    }
}

void TurtleAlgorithms::task_B6(int side, int min) {
    if (side < min) {
        return;
    }
    for (int i = 0; i < 3; i++) {
        forward(side);
        right(120);
        task_B6(side / 3, min);
    }
}

void TurtleAlgorithms::task_B7(int side, int min) {
    if (side < min) {
        return;
    }
    right(60);
    for (int i = 0; i < 3; i++){
        forward(side);
        right(60);
        forward(side / 2);
        task_B7(side / 2, min);
        forward(side / 2);
        right(60);
    }
    left(60);
}

void TurtleAlgorithms::task_B8(int side, int min) {
    if (side < min) {
        return;
    }
    left(45);
    for (int i = 0; i < 3; i++) {
        forward(side);
        task_B8(side / 3 * 2, min);
        back(side);
        right(45);
    }
    left(90);
}

void TurtleAlgorithms::task_C1(int side, int min) {
    while (side > min) {
        forward(side);
        left(124);
        side -= min;
    }
}

void TurtleAlgorithms::task_C2(int side, int min) {
    while (side > min) {
        forward(side);
        left(144);
        side -= min;
    }
}

void TurtleAlgorithms::task_C3(int side, int min) {
    while (side > min) {
        forward(side);
        left(100);
        side -= min;
    }
}

void TurtleAlgorithms::task_C6(int side, int min) {
    if (side < min) {
        return;
    }
    for (int i = 0; i < 3; i++) {
        forward(side);
        task_C6(side / 2, min);
        back(side);
        right(120);
    }
    task_C6(side / 2, min);
}

void TurtleAlgorithms::task_C7(int side, int min) {
    if (side < min) {
        return;
    }
    for (int i = 0; i < 4; i++) {
        forward(side);
        task_C7(side / 3, min);
        back(side);
        right(90);
    }
    task_C7(side / 3, min);
}
