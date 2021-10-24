#include "raylib.h"
int main()
{
    //window dimensions
    int width{800};
    int height{450};

    //InitWindow function takes three functions: width, height and title
    InitWindow(width, height, "Sabrina's Window");

    //circle coordinates
    int circle_X{200};
    int circle_Y{200};
    int circle_RADIUS{25};

    //circle edges

    //x coordinate of the circle's left edge
    int l_circle_x{circle_X - circle_RADIUS};
    //x coordinate of the circle's right edge
    int r_circle_x{circle_X + circle_RADIUS};
    //y coordinate of the circle's upper edge
    int u_circle_Y{circle_Y - circle_RADIUS};
    //y coordinate of the circle's bottom edge
    int b_circle_Y{circle_Y + circle_RADIUS};

    //axe coordinates
    int axe_X{400};
    int axe_Y{0};
    int axe_LENGTH{50};

    //axe edges
    int l_axe_x{axe_X};
    int r_axe_x{axe_X + axe_LENGTH};
    int u_axe_y{axe_Y};
    int b_axe_y{axe_Y + axe_LENGTH};

    int direction{10};

    bool collision_with_axe = 
                        (b_axe_y >= u_circle_Y) && 
                        (u_axe_y <= b_circle_Y) && 
                        (r_axe_x >= l_circle_x) && 
                        (l_axe_x <= r_circle_x);

    //moves the circle at 60 frames per second
    SetTargetFPS(60);

    while (WindowShouldClose() == false)
    {
        BeginDrawing();
        ClearBackground(WHITE);

        if (collision_with_axe != false)
        {
            DrawText("Game Over!", 400, 200, 20, RED);
        }
        else
        {
            //game logic BEGINS

            //update the edges
            l_circle_x = circle_X - circle_RADIUS;
            r_circle_x = circle_X + circle_RADIUS;
            u_circle_Y = circle_Y - circle_RADIUS;
            b_circle_Y = circle_Y + circle_RADIUS;
            l_axe_x = axe_X;
            r_axe_x = axe_X + axe_LENGTH;
            u_axe_y = axe_Y;
            b_axe_y = axe_Y + axe_LENGTH;

            //update collision with axe
            collision_with_axe = 
                        (b_axe_y >= u_circle_Y) && 
                        (u_axe_y <= b_circle_Y) && 
                        (r_axe_x >= l_circle_x) && 
                        (l_axe_x <= r_circle_x);

            DrawCircle(circle_X, circle_Y, circle_RADIUS, BLUE);
            DrawRectangle(axe_X, axe_Y, axe_LENGTH, axe_LENGTH, RED);

            //move the axe
            axe_Y += direction;

            //check axe_Y coordinate
            if (axe_Y > height || axe_Y < 0)
            {
                //axe_Y will go in the opposite direction
                direction = -direction;
            }

            if (IsKeyDown(KEY_D) && circle_X < width)
            {
                //moves the circle to the right
                circle_X += 10;
            }

            //0 is the x coordiante of the left side of the window
            if (IsKeyDown(KEY_A) && circle_X > 0)
            {
                //moves the circle to the left
                circle_X -= 10;
            }

            //game logic ENDS
        }

        EndDrawing();
    }
}
