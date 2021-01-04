/*
	...Work in Progress...
*/
#include "raylib.h"
#include <stdlib.h>
#include <time.h>

#define SCREEN_WIDTH  800
#define SCREEN_HEIGHT 450
#define BAR_WIDTH	  90
#define BAR_HEIGHT	  10
#define PLAYER_RADIUS 20
#define MAX_BARS      32

typedef struct Bars
{
	Rectangle rec;
	Color color;
	bool active;
} Bars;

typedef struct BallPlayer 
{
	Vector2 position;
	Color color;
	int radius;
} BallPlayer;

Bars allBars[MAX_BARS] = {0};
BallPlayer player = {0};
bool gameStarted = false;

void InitBounceGame();
void UpdateBounceGame();
void DrawBounceGame();
void CheckSpaceKey();
void CheckLeftRight();
void CheckGameCollison();
void CheckGameStart();
void ResetScreen();

int main(void)
{
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "JDG : Ball Bounce");
	InitBounceGame();
	SetTargetFPS(60);
	// Main game loop
	while (!WindowShouldClose())
	{
		ResetScreen();
		UpdateBounceGame();
		DrawBounceGame();
		EndDrawing();
		if (!gameStarted) CheckGameStart();
	}
	CloseWindow();
	return 0;
}

void InitBounceGame()
{
	srand((unsigned)time(NULL));
	player.radius = PLAYER_RADIUS;
	player.color = DARKBLUE;
	player.position = { SCREEN_WIDTH / 2, SCREEN_HEIGHT - 25 };
	// loop to draw board with no colliding bars
	while (1) 
	{
		for (int i = 0; i < MAX_BARS; ++i)
		{
			allBars[i].active = false;
			allBars[i].color = BLACK;
			allBars[i].rec.x = GetRandomValue(5, 600);
			allBars[i].rec.y = GetRandomValue(5, 400);
			allBars[i].rec.width = BAR_WIDTH;
			allBars[i].rec.height = BAR_HEIGHT;
			if (i > 0)
			{
				for (int j = 0; j < i; ++j)
				{
					if (CheckCollisionRecs(allBars[i].rec, allBars[j].rec)) break;
				}
			}
		}
		break;
	}
}

void UpdateBounceGame() 
{
	if (gameStarted)
	{
		CheckGameCollison();
	}
	CheckSpaceKey();
	CheckLeftRight();
}

void CheckGameStart()
{
	if (IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_ENTER))
		gameStarted = true;
}

void CheckGameCollison()
{
	for (int i = 0; i < MAX_BARS; ++i)
	{
		Vector2 v = { player.position.x , player.position.y };
		if (CheckCollisionCircleRec(v, PLAYER_RADIUS, allBars[i].rec))
		{
			// add game logic here
			exit(1);
		}
	}
}

void CheckSpaceKey()
{
	if (gameStarted) 
	{
		if (IsKeyDown (KEY_SPACE))
		{
			player.position.y -= 10;
		}
		else
		{
			player.position.y += .75;
		}
	}
}

void CheckLeftRight()
{
	if (gameStarted)
	{
		if (IsKeyPressed(KEY_LEFT) || IsKeyDown(KEY_LEFT))
		{
			player.position.x -= 5;
		}
		if (IsKeyPressed(KEY_RIGHT) || IsKeyDown(KEY_RIGHT))
		{
			player.position.x += 5;
		}
	}
}

void DrawBounceGame()
{
	DrawCircle(player.position.x, player.position.y, PLAYER_RADIUS, BLUE);
	for (int i = 0; i < MAX_BARS; ++i)
	{
		DrawRectangleRec(allBars[i].rec, BLACK);
		//DrawRectangle(allBars[i].posX, allBars[i].posY, BAR_WIDTH, BAR_HEIGHT, BLACK);		
	}
}

void ResetScreen() 
{
	BeginDrawing();
	ClearBackground(RAYWHITE);
}
