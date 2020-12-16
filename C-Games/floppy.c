#include "raylib.h"
#include <stdio.h>
#include <string.h>

#define MAX_TUBES          100
#define FLOPPY_RADIUS      32
#define TUBES_WIDTH        80
#define TUBES_HEIGHT_SCALE 8

typedef struct Floppy {
	Vector2 position;
	int radius;
	Color color;
} Floppy;

typedef struct Tubes {
	Rectangle rec;
	Color color;
	bool active;
} Tubes;

static const int screenWidth = 1200;
static const int screenHeight = 550;

static bool gameOver = false;
static bool pause = false;
static int score = 0;
static int hiScore = 0;

static Floppy floppy = { 0 };
static Tubes tubes[MAX_TUBES * 2] = { 0 };
static Vector2 tubesPosTop[MAX_TUBES] = { 0 };
static Vector2 tubesPosBtm[MAX_TUBES] = { 0 };
static Vector3 min = { 50.0, 50.0, 0.0 };
static Vector3 max = { screenWidth - 50.0, screenHeight - 50.0, 0.0 };
static BoundingBox bb = { min, max };
static char floppyMsg[50];
static int tubesSpeedX = 0;
static bool superfx = false;

static void InitGame(void);         // Initialize game
static void UpdateGame(void);       // Update game (one frame)
static void DrawGame(void);         // Draw game (one frame)
static void UnloadGame(void);       // Unload game
static void UpdateDrawFrame(void);  // Update and Draw (one frame)
bool IsValInRange(int);		        // Check if the Y val is inside the bounding box

int main(void)
{
	InitWindow(screenWidth, screenHeight, "sample game: floppy");
	InitGame();
	SetTargetFPS(60);
	// Main game loop
	while (!WindowShouldClose()) 
	{
		UpdateDrawFrame();
	}
	UnloadGame();         
	CloseWindow();        
	return 0;
}

void InitGame(void)
{
	floppy.radius = FLOPPY_RADIUS;
	floppy.position = { 80.00, (float)screenHeight / 2 - floppy.radius };
	tubesSpeedX = 2;
	for (int i = 0; i < MAX_TUBES; i++)
	{
		tubesPosTop[i].x = 400 + 180 * i;
		tubesPosTop[i].y = 50;
	}
	for (int i = 0; i < MAX_TUBES * 2; i += 2)
	{
		tubes[i].rec.x = tubesPosTop[i / 4].x;
		tubes[i].rec.y = tubesPosTop[i / 4].y;
		tubes[i].rec.width = TUBES_WIDTH;
		tubes[i].rec.height = GetRandomValue(150, 250);
		tubes[i + 1].rec.x = tubesPosTop[i / 4].x;
		tubes[i + 1].rec.y = 350;
		tubes[i + 1].rec.width = TUBES_WIDTH;
		tubes[i + 1].rec.height = 150;
		tubes[i / 4].active = true;
	}
	score = 0;
	gameOver = false;
	superfx = false;
	pause = false;
}

bool IsValInRange(int val) 
{
	return (val >= 50 && val <= 500) || (val <= -50 && val >= -500);
}

void UpdateGame(void)
{
	if (!gameOver)
	{
		if (IsKeyPressed('P')) pause = !pause;
		if (!pause)
		{
			for (int i = 0; i < MAX_TUBES; i++) tubesPosTop[i].x -= tubesSpeedX;
			for (int i = 0; i < MAX_TUBES * 2; i += 2)
			{
				tubes[i].rec.x = tubesPosTop[i / 2].x;
				tubes[i + 1].rec.x = tubesPosTop[i / 2].x;
			}
			if (IsKeyDown(KEY_SPACE) && !gameOver) floppy.position.y -= 3;
			else floppy.position.y += 1;
			// Check Collisions
			for (int i = 0; i < MAX_TUBES * 2; i++)
			{
				if (CheckCollisionCircleRec(floppy.position, floppy.radius, tubes[i].rec))
				{
					strcpy(floppyMsg, "Floppy Did Not Make It :(");
					gameOver = true;
					pause = false;
				}
				else if ((tubesPosTop[i / 2].x < floppy.position.x) && tubes[i / 2].active && !gameOver)
				{
					strcpy(floppyMsg, "Floppy Made It !!");
					score += 100;
					tubes[i / 2].active = false;
					superfx = true;
					if (score > hiScore) hiScore = score;
				}
			}
		}
	}
	else
	{
		if (IsKeyPressed(KEY_ENTER))
		{
			InitGame();
			gameOver = false;
		}
	}
}

void DrawGame(void)
{
	BeginDrawing();
	ClearBackground(RAYWHITE);
	DrawBoundingBox(bb, BLACK);
	if (!gameOver)
	{
		DrawCircleGradient(floppy.position.x, floppy.position.y, floppy.radius, GREEN, SKYBLUE);
		// Draw tubes
		for (int i = 0; i < MAX_TUBES; i++)
		{
			//printf("Tubes[i*2] X = %.2f\nY = %.2f\n", tubes[i * 2].rec.x, tubes[i * 2].rec.y);
			//printf("Tubes[i*2+1] X = %.2f\nY = %.2f\n", tubes[i * 2].rec.x, tubes[i * 2 + 1].rec.y);
			DrawRectangle(tubes[i * 2].rec.x, tubes[i * 2].rec.y, tubes[i * 2].rec.width, tubes[i * 2].rec.height, PURPLE);
			DrawRectangle(tubes[i * 2 + 1].rec.x, tubes[i * 2 + 1].rec.y, tubes[i * 2 + 1].rec.width, tubes[i * 2 + 1].rec.height, PURPLE);
		}
		if (superfx)
		{
			DrawRectangle(0, 0, screenWidth, screenHeight, WHITE);
			superfx = false;
		}
		DrawText(TextFormat("%04i", score), 20, 20, 40, GRAY);
		DrawText(TextFormat("HI-SCORE: %04i", hiScore), 20, 70, 20, LIGHTGRAY);
		DrawText(floppyMsg, 20, 100, 20, LIGHTGRAY);
		if (pause) DrawText("GAME PAUSED", screenWidth / 2 - MeasureText("GAME PAUSED", 40) / 2, screenHeight / 2 - 40, 40, GRAY);
	}
	else DrawText("PRESS [ENTER] TO PLAY AGAIN", GetScreenWidth() / 2 - MeasureText("PRESS [ENTER] TO PLAY AGAIN", 20) / 2, GetScreenHeight() / 2 - 50, 20, GRAY);
	EndDrawing();
}

void UpdateDrawFrame(void)
{
	UpdateGame();
	DrawGame();
}

void UnloadGame(void)
{
	// TODO: Unload all dynamic loaded data (textures, sounds, models...)
}
