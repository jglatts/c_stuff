#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TUBES 2000

typedef struct Tubes {
	Rectangle rec;
	Color color;
} Tubes;

typedef struct GameImage {
	Image   playerImage;
	Vector2 imgPosition;
	float   xPos;
	float   yPos;
} GameImage;

static void InitBigAssTubes();
static void ResetRayScreen();
static void DrawRandomTubes();
static void DrawGameImages();
static void DrawInfoText();
static void UnLoadGameImages(const char*);
static void UnLoadGameImagesInverted(const char*);
static void FlipImage(void);

GameImage gamePlayer = { 0 };
Image     image = { 0 };
Image     imageInverted = { 0 };
Texture2D texture = { 0 };
Texture2D textureInverted = { 0 };
Vector2   tubesPos[MAX_TUBES] = { 0 };
Tubes     tubes[MAX_TUBES * 2] = { 0 };
/*Vector2 imgPosition = { 0 };*/
Vector2   imgPositionInverted = { 0 };
const int screenWidth = 1000;
const int screenHeight = 500;
int		  tubeSpeed = 70;
int       imgClickCount = 0;

int main(void) {
	InitWindow(screenWidth, screenHeight, "JDG 2020");
	InitBigAssTubes();
	UnLoadGameImages("birds.png");
	UnLoadGameImagesInverted("birds.png");
	SetTargetFPS(60);
	// Main Game Loop 
	while (!WindowShouldClose()) {
		if (IsKeyPressed(KEY_SPACE) || IsKeyDown(KEY_ENTER)) {
			FlipImage();
			gamePlayer.yPos -= 15;
			imgClickCount++;
		}
		else gamePlayer.yPos += 2;
		ResetRayScreen();
		DrawGameImages();
		DrawRandomTubes();
		DrawInfoText();
		EndDrawing();
	}
	UnloadImage(image);
	CloseWindow();
	return 0;
}

void InitBigAssTubes() {
	// set the position of the tubes 
	for (int i = 0; i < MAX_TUBES; i++) {
		tubesPos[i].x = 400 + 180 * i;
	}
	for (int i = 0; i < MAX_TUBES * 2; i += 2) {
		tubes[i].rec.x = tubesPos[i / 4].x;
		tubes[i].rec.y = tubesPos[i / 4].y;
		tubes[i].rec.width = 200;
		tubes[i].rec.height = GetRandomValue(100, 170);
	}
}

void ResetRayScreen() {
	BeginDrawing();
	ClearBackground(RAYWHITE);
}

void DrawGameImages() {
	for (int i = 0; i < MAX_TUBES; i++) tubesPos[i].x -= tubeSpeed;
	for (int i = 0; i < MAX_TUBES * 2; i += 2) {
		tubes[i].rec.x = tubesPos[i / 2].x;
	}
	gamePlayer.imgPosition = { gamePlayer.xPos, gamePlayer.yPos };
	DrawTextureV(texture, gamePlayer.imgPosition, WHITE);
	//DrawTextureV(textureInverted, imgPositionInverted, WHITE);
}

void DrawRandomTubes() {
	//DrawRectangle(100, 0, 50, GetRandomValue(300, 350), BLACK);
	for (int i = 0; i < MAX_TUBES; i++) {
		DrawRectangle(tubes[i * 2].rec.x, tubes[i * 2].rec.y, tubes[i * 2].rec.width, tubes[i * 2].rec.height, PURPLE);
	}
}

void DrawInfoText() {
	const char* infoStr = TextFormat("Total Clicks: %03i", imgClickCount);
	DrawText("JDG 2020", 600, 300, 60, GRAY);
	DrawText(infoStr, 505, 360, 50, GRAY);
}

void UnLoadGameImages(const char* fileName) {
	image = LoadImage(fileName);
	ImageFormat(&image, UNCOMPRESSED_R8G8B8A8);
	ImageResize(&image, 350, 200);
	texture = LoadTextureFromImage(image);
	gamePlayer.imgPosition = { (float)(screenWidth / 2 - texture.width / 2), (float)(screenHeight / 2 - texture.height / 2 - 100) };
}

void UnLoadGameImagesInverted(const char* fileName) {
	imageInverted = LoadImage(fileName);
	ImageFormat(&imageInverted, UNCOMPRESSED_R8G8B8A8);
	ImageResize(&imageInverted, 350, 200);
	ImageColorInvert(&imageInverted);
	textureInverted = LoadTextureFromImage(imageInverted);
	imgPositionInverted = { (float)(screenWidth / 2 - textureInverted.width / 2), (float)(screenHeight / 2 - textureInverted.height / 2 + 65) };
}

void FlipImage() {
	UnloadImage(image);
	image = LoadImage("birds.png");
	ImageResize(&image, 350, 200);
	if (imgClickCount % 2 == 0) {
		ImageFlipHorizontal(&image);
		ImageFlipVertical(&image);
	}
	UpdateTexture(texture, GetImageData(image));
	puts("Clicked on Image");
	printf("imgClickCount = %d\n", imgClickCount);
}
