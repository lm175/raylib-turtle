#ifndef TURTLE_GRAPHICS_H
#define TURTLE_GRAPHICS_H
#define _USE_MATH_DEFINES

#include <raylib.h>
#include <cmath>
#include <stdexcept>


class Turtle {
private:
    Vector2 position; // Turtle's position.
    float angle = 0; // Current heading.
    Color penColor = BLACK; // Color of lines.
    unsigned int penSpeed = 2; // Turtle's speed.
    bool isPenDown = true; // Whether or not to put pen down.
    float penSize = 1; // Size of lines.
    int ScreenWidth; // Width of draw window.
    int ScreenHeight; // Height of draw window.
    RenderTexture2D framebuffer; // A frame buffer that stores the state of the previous frame.
    Color bgColor = RAYWHITE;

    // Linear interpolation function.
    float lerp(float a, float b, float t);
    // Draws the contents of the frame buffer to the screen.
    void drawbuffer(Vector2 position);

public:
    // `ScreenWidth`, `ScreenHeight`, `FPS`, `LogLevel` parameters can be set during initialization.
    Turtle(int ScreenWidth = 800, int ScreenHeight = 600, int FPS = 60, int LogLevel = 7);
    ~Turtle();


    // Set the frame rate.
    void SetFPS(const int FPS);
    // Set the log level.
    void SetLogLevel(const int LogLevel);


    // Set the turtle's movement speed, minimum 0, maximum 5.
    void speed(unsigned int speed);
    // Lift the pen and move the turtle after execution without lines.
    void penup();
    // Drop the pen which allows the turtle to draw lines while moving.
    void pendown();
    // Resize the pen.
    void pensize(float size);
    // Adjust pen-color.
    void color(Color color);
    // Adjust background-color.
    void bgcolor(Color color);


    // Go forward.
    void forward(float distance);
    // Go back.
    void back(float distance);
    // Turn left.
    void left(float degrees);
    // Turn right.
    void right(float degrees);
    // Set position.
    void setxy(Vector2 position);
    // Set x position.
    void setx(float x);
    // Set y position.
    void sety(float y);
    // Set turtle's heading.
    void setheading(float angle);
    // Go back to center and set heading to right.
    void home();


    // Clear all traces left by the turtle on the screen.
    void clear();
    // Clear the screen and reset the turtle's position and orientation.
    void reset();


    // Get turtle's current position.
    Vector2 getPosition() const;
    // Get turtle's current heading.
    float heading() const;


    // Keep the window open.
    void done();
};


class TurtleAlgorithms : public Turtle {
public:
    void task_A1(int, int);
    void task_A2(int, int);
    void task_A3(int, int);
    void task_A4(int, int);
    void task_A5(int, int);
    void task_A6(int, int);
    void task_A7(int, int);
    void task_A8(int, int);
    void task_A9(int, int);
    void task_A10(int, int);
    void task_A11(int, int);
    void task_A12(int, int);
    void task_A13(int, int);
    void task_B1(int, int);
    void task_B2(int, int);
    void task_B3(int, int);
    void task_B4(int, int);
    void task_B5(int, int);
    void task_B6(int, int);
    void task_B7(int, int);
    void task_B8(int, int);
    void task_C1(int, int);
    void task_C2(int, int);
    void task_C3(int, int);
    void task_C6(int, int);
    void task_C7(int, int);
};


#endif // TURTLE_GRAPHICS_H