#include <stdlib.h>
#include <stdio.h>


#include "raylib.h"
#include "raymath.h"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"



#define GRID_STEP 10

void DrawCartesianGrid(Rectangle rec, int scaleFactor){

   
  
  float mposX = rec.x + rec.width / 2;
  float mposY = rec.y + rec.height / 2;

  DrawRectangleRec(rec, WHITE);
  for(int i = GRID_STEP+scaleFactor; i <= (rec.width/2); i = i+GRID_STEP+scaleFactor){
    DrawLine(mposX + i, rec.y, mposX + i, rec.height+rec.y, GRAY);
    DrawLine(mposX - i, rec.y, mposX - i, rec.height+rec.y, GRAY);

  }
  
  
  for(int i = GRID_STEP+scaleFactor; i <= (rec.height/2); i = i+GRID_STEP+scaleFactor){
    DrawLine(rec.x, mposY + i, rec.width+rec.x, mposY + i, GRAY);
    DrawLine(rec.x, mposY - i, rec.width+rec.x, mposY - i, GRAY);
}

  

  DrawLine(rec.x, mposY, rec.x+rec.width, mposY, RED);
  DrawLine(mposX, rec.y, mposX, rec.y+rec.height, RED);

}








int main(void){
  bool showMessageBox = false;
  int count = 0;
  int scaleFactor1 = 0;
  int scaleFactor2 = 0;

  int dropdownBox000Active = 0;
  bool dropDown000EditMode = false;
  
  const int winWidth = 840;
  const int winHeight = 600;

  Color scF = {0, 0, 0, 255};
  
  InitWindow(winWidth, winHeight, "WAPL");
  SetTargetFPS(30);

  Rectangle scalingFunctionPlot = {30.0f,   60.0f, 500.0f, 200.0f};
  Rectangle waveletFunctionPlot = {30.0f, scalingFunctionPlot.y+scalingFunctionPlot.height + 80, 500.0f, 200.0f};
  
  char str[12];
  
  while(!WindowShouldClose()){
   
    Vector2 currPos = GetMousePosition();
  
    if(CheckCollisionPointRec(currPos, scalingFunctionPlot)) {
      if((int)GetMouseWheelMove() > 0 && scaleFactor1 <= 50)
	scaleFactor1 += 5;
      else if (scaleFactor1 >= 10 && (int)GetMouseWheelMove() < 0)
	    scaleFactor1 -= 5;
	}

    if(CheckCollisionPointRec(currPos, waveletFunctionPlot)) {
      if((int)GetMouseWheelMove() > 0 && scaleFactor2 <= 50)
	scaleFactor2 += 5;
      else if (scaleFactor2 >= 10 && (int)GetMouseWheelMove() < 0)
	    scaleFactor2 -= 5;
	}

  
    
    BeginDrawing();

       
    
    	ClearBackground(LIGHTGRAY);



  
	DrawText("Scale function", 30, 40, 20, BLACK);
	DrawCartesianGrid(scalingFunctionPlot, scaleFactor1);


	DrawText("Wavelet function", 30, scalingFunctionPlot.y+scalingFunctionPlot.height + 60, 20, BLACK);
	DrawCartesianGrid(waveletFunctionPlot, scaleFactor2);

	

        if (GuiDropdownBox((Rectangle){580.0f , 60.0f, 200.0f, 30.0f}, "Haar;Daubechie;Mayer", &dropdownBox000Active, dropDown000EditMode))
		      dropDown000EditMode = !dropDown000EditMode;

	sprintf(str, "%d", dropDown000EditMode);
        DrawText(str, 580, 30, 16, RED);

   





    EndDrawing();
  }

  CloseWindow();

  
}
