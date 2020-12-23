/*
  Test program using images with raylib 
  Tested/Compiled on Windows 10 Machine with Windows C/C++ Compiler
*/
#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>

static void UnLoadGameImages(const char*);
static void UnLoadGameImagesInverted(const char*);
static void FlipImage(void);
static bool IsMouseClickedOnImage(void);

Image     image;
Image     imageInverted;
Texture2D texture;
Texture2D textureInverted;
Vector2   imgPosition;
Vector2   imgPositionInverted;
const int screenWidth = 1000;
const int screenHeight = 500;
int       imgClickCount = 0;

int main(void) {
	InitWindow(screenWidth, screenHeight, "JDG 2020");
	UnLoadGameImages("birds.png");
	UnLoadGameImagesInverted("birds.png");
	SetTargetFPS(60);
	while (!WindowShouldClose()) {
		if (IsMouseClickedOnImage()) {
			FlipImage();
			imgClickCount++;
		}
		BeginDrawing();
		ClearBackground(RAYWHITE);
		DrawTextureV(texture, imgPosition, WHITE);
		DrawTextureV(textureInverted, imgPositionInverted, WHITE);
		EndDrawing();
	}
	UnloadImage(image);
	CloseWindow();
	return 0;
}

void UnLoadGameImages(const char* fileName) {
	image = LoadImage(fileName);
	ImageFormat(&image, UNCOMPRESSED_R8G8B8A8);
	ImageResize(&image, 350, 200);
	texture = LoadTextureFromImage(image);
	imgPosition = { (float)(screenWidth / 2 - texture.width / 2), (float)(screenHeight / 2 - texture.height / 2 - 100) };
}

void UnLoadGameImagesInverted(const char* fileName) {
	imageInverted = LoadImage(fileName);
	ImageFormat(&imageInverted, UNCOMPRESSED_R8G8B8A8);
	ImageResize(&imageInverted, 350, 200);
	ImageColorInvert(&imageInverted);
	textureInverted = LoadTextureFromImage(imageInverted);
	imgPositionInverted = { (float)(screenWidth / 2 - textureInverted.width / 2), (float)(screenHeight / 2 - textureInverted.height / 2 + 65) };
}

static void FlipImage() {
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

bool IsMouseClickedOnImage(void) {
	size_t mouseX = GetMouseX();
	size_t mouseY = GetMouseY();
	if (!IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) return false;
	if (!(mouseX >= 341 && mouseX <= 656)) return false;
	if (!(mouseY >= 50 && mouseY <= 250)) return false;
	return true;
}
