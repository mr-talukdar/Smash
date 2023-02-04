#include "raylib.h"
int main(){
    

    int screenWidth{1080};
    int screenHeight{720};

    //circle coordinates
    int circleX=screenWidth/2;
    int circleY=screenHeight/2;
    int circle_radius{25};

    //circle edges
    int l_circle_x{circleX-circle_radius};
    int u_circle_y{circleY-circle_radius};
    int r_circle_x{circleX+circle_radius};
    int b_circle_y{circleY+circle_radius};

    // axe coordinates
    int axePosX=300;
    int axePosY=0;
    int axe_length{50};

    //axe edges
    int l_axe_x{axePosX};
    int r_axe_x{axePosX+axe_length};
    int u_axe_y{axePosY};
    int b_axe_y{axePosY+axe_length};


    int direction=10;

    bool gameOver=  (b_axe_y>=u_circle_y) && 
                    (u_axe_y<=b_circle_y) && 
                    (l_axe_x<=r_circle_x) && 
                    (r_axe_x>= l_circle_x) ;
  
    InitWindow(screenWidth, screenHeight, "Rahul's Window");

    SetTargetFPS(144);
    while (WindowShouldClose()==false)
    {
        BeginDrawing();

        ClearBackground(WHITE);

        if(gameOver){

            DrawText("GameOver!", 540, 360, 20, RED);

        }

        else{

            // update the circle edges
            l_circle_x=circleX-circle_radius;
            r_circle_x=circleX+circle_radius;
            u_circle_y=circleY-circle_radius;
            b_circle_y=circleY+circle_radius;

            //update the rectangle edges
            l_axe_x=axePosX;
            r_axe_x=axePosX+axe_length;
            u_axe_y=axePosY;
            b_axe_y=axePosY+axe_length;

            //updating the gameover value
            gameOver=  (b_axe_y>=u_circle_y) && 
                        (u_axe_y<=b_circle_y) && 
                        (l_axe_x<=r_circle_x) && 
                        (r_axe_x>= l_circle_x) ;

        DrawCircle(circleX, circleY, circle_radius, BLUE);

        DrawRectangle(axePosX,axePosY,axe_length,axe_length,RED);

        axePosY+=direction;
        if(axePosY>= 1080 || axePosY<=0){
            direction= -direction;
        }

        if(IsKeyDown(KEY_D)){

            if(circleX+10!=screenWidth){
                circleX+=10;
            }
          

        }
        else if(IsKeyDown(KEY_A) ){

            if(circleX-10!=0){
                circleX-=10;
            }
        }
        
        }

        EndDrawing();
        
    }
    

}