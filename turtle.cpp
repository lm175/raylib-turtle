#include "turtle.h"

float Turtle::lerp(float a, float b, float t) {
    return a + (b - a) * t;
}
void Turtle::drawbuffer(Vector2 position) {
    BeginDrawing();

    ClearBackground(bgColor);
    DrawTexturePro(
        framebuffer.texture,
        Rectangle{0, 0, (float)framebuffer.texture.width, (float)-framebuffer.texture.height},
        Rectangle{0, 0, (float)ScreenWidth, (float)ScreenHeight},
        Vector2{0, 0},
        0.0f, WHITE
    );
    DrawCircleV(position, 5, BLACK); // use a black circle to represent the turtle.

    EndDrawing();
}


Turtle::Turtle(int ScreenWidth, int ScreenHeight, int FPS, int LogLevel)
    : ScreenWidth(ScreenWidth), ScreenHeight(ScreenHeight) {
    SetTraceLogLevel(LogLevel);
    SetTargetFPS(FPS);
    InitWindow(ScreenWidth, ScreenHeight, "Raylib Turtle Graphics");

    framebuffer = LoadRenderTexture(ScreenWidth, ScreenHeight);
    position = { float(ScreenWidth) / 2, float(ScreenHeight) / 2 };
}
Turtle::~Turtle() {
    UnloadRenderTexture(framebuffer);
}

void Turtle::SetFPS(const int FPS) { SetTargetFPS(FPS); }
void Turtle::SetLogLevel(const int LogLevel) { SetTraceLogLevel(LogLevel); }


// turtle's status
void Turtle::speed(unsigned int speed) {
    if (speed > 5) {
        throw std::invalid_argument("speed cannot be greater than 5.");
    } else {
        penSpeed = speed;
    }
}
void Turtle::penup() { this->isPenDown = false; }
void Turtle::pendown() { this->isPenDown = true;}
void Turtle::pensize(float size) { this->penSize = size; }
void Turtle::color(Color penColor) { this->penColor = penColor; }
void Turtle::bgcolor(Color color) { this->bgColor = color; }


// turtle's position
void Turtle::forward(float distance) {
    float drawProgress = 0.0f;
    const float progressIncrement = 0.03125f * pow(2, penSpeed);

    float newX = position.x + distance * cos(angle);
    float newY = position.y - distance * sin(angle);

    while (!WindowShouldClose()) {
        // Draw the contents of the frame buffer.
        BeginTextureMode(framebuffer);
        if (drawProgress > 0.0f) {
            DrawTextureRec(framebuffer.texture, Rectangle{0, 0, (float)framebuffer.texture.width, -(float)framebuffer.texture.height}, Vector2{0, 0}, WHITE);
        }
        float currentX = lerp(position.x, newX, drawProgress);
        float currentY = lerp(position.y, newY, drawProgress);
        if (isPenDown) {
            DrawLineEx(position, { currentX, currentY }, penSize, penColor);
        }
        EndTextureMode();

        // Draws the contents of the frame buffer to the screen.
        drawbuffer({ currentX, currentY });

        // update the `drawProgress`.
        drawProgress += progressIncrement;
        if (drawProgress > 1.0f) break;
    }

    // update position of turtle.
    position = { newX, newY };
}
void Turtle::back(float distance) {
    forward(-distance);
}
void Turtle::left(float degrees) {
    angle += degrees * (M_PI / 180.0f);
}
void Turtle::right(float degrees) {
    angle -= degrees * (M_PI / 180.0f);
}

void Turtle::setxy(Vector2 position) { this->position = position; }
void Turtle::setx(float x) { this->position.x = x; }
void Turtle::sety(float y) { this->position.y = y; }
void Turtle::setheading(float angle) { this->angle = angle; }
void Turtle::home() {
    setxy({float(ScreenWidth) / 2, float(ScreenHeight) / 2});
    setheading(0);
}


// others
void Turtle::clear() {
    framebuffer = LoadRenderTexture(ScreenWidth, ScreenHeight);
}
void Turtle::reset() {
    clear();
    home();
}
void Turtle::done() {
    // keep window open until user close it.
    while (!WindowShouldClose()) {
        drawbuffer(position);
    }
}


// get status
Vector2 Turtle::getPosition() const { return position; }
float Turtle::heading() const { return angle * (180.0f / M_PI); }