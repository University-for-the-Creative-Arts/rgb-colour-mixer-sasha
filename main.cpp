#include "raylib.h"
#include <stdio.h>


typedef struct {
    int red;
    int green;
    int blue;
    Color color;
} ColorMixer;


void DrawColorDisplay(ColorMixer *mixer) {
    
    DrawRectangle(300, 220, 100, 100, mixer->color);

    DrawText(TextFormat("R: %d", mixer->red),   100, 200, 30, RED);
    DrawText(TextFormat("G: %d", mixer->green), 100, 250, 30, GREEN);
    DrawText(TextFormat("B: %d", mixer->blue),  100, 300, 30, BLUE);
}

int main(void) {
    const int screenWidth = 960;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "RPG Colour Mixer");
    SetTargetFPS(60);

    ColorMixer mixer = { 128, 128, 128, { 128, 128, 128, 255 } };

    int *r = &mixer.red;
    int *g = &mixer.green;
    int *b = &mixer.blue;

    while (!WindowShouldClose()) {
        
        
        if (IsKeyDown(KEY_R)) (*r)++;
        if (IsKeyDown(KEY_T)) (*r)--;

        if (IsKeyDown(KEY_G)) (*g)++;
        if (IsKeyDown(KEY_H)) (*g)--;

        if (IsKeyDown(KEY_B)) (*b)++;
        if (IsKeyDown(KEY_N)) (*b)--;

        mixer.color = (Color){ mixer.red, mixer.green, mixer.blue, 255 };

        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawText("Red R/T, Green G/H, Blue B/N", 100, 100, 20, DARKGRAY);
            DrawColorDisplay(&mixer); 
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
