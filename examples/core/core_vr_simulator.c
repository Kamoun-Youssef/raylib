/*******************************************************************************************
*
*   raylib [core] example - Oculus Rift CV1
*
*   Compile example using:
*   gcc -o $(NAME_PART).exe $(FILE_NAME) -I..\src\external -I..\src\external\OculusSDK\LibOVR\Include /
*       -L. -L..\src\external\OculusSDK\LibOVR -lLibOVRRT32_1 -lraylib -lglfw3 -lopengl32 -lgdi32 -std=c99 /
*       -Wl,-allow-multiple-definition
*
*   #define SUPPORT_OCULUS_RIFT_CV1 / RLGL_OCULUS_SUPPORT
*       Enable Oculus Rift CV1 functionality
*
*   This example has been created using raylib 1.5 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2016 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"

int main()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    int screenWidth = 1080;
    int screenHeight = 600;
    
    // NOTE: screenWidth/screenHeight should match VR device aspect ratio
    
    InitWindow(screenWidth, screenHeight, "raylib [core] example - oculus rift");

    InitVrSimulator(HMD_OCULUS_RIFT_CV1);               // Init VR simulator (Oculus Rift CV1 parameters)
    
    // Define the camera to look into our 3d world
    Camera camera;
    camera.position = (Vector3){ 5.0f, 2.0f, 5.0f };    // Camera position
    camera.target = (Vector3){ 0.0f, 2.0f, 0.0f };      // Camera looking at point
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
    camera.fovy = 60.0f;                                // Camera field-of-view Y
    
    Vector3 cubePosition = { 0.0f, 0.0f, 0.0f };
    
    SetCameraMode(camera, CAMERA_FIRST_PERSON);         // Set first person camera mode
    
    SetTargetFPS(90);                   // Set our game to run at 90 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())        // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        UpdateCamera(&camera);          // Update camera (simulator mode)

        if (IsKeyPressed(KEY_SPACE)) ToggleVrMode();    // Toggle VR mode
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);
            
            BeginVrDrawing();

                Begin3dMode(camera);

                    DrawCube(cubePosition, 2.0f, 2.0f, 2.0f, RED);
                    DrawCubeWires(cubePosition, 2.0f, 2.0f, 2.0f, MAROON);

                    DrawGrid(40, 1.0f);

                End3dMode();
            
            EndVrDrawing();

            DrawFPS(10, 10);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseVrSimulator();
    
    CloseWindow();          // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}