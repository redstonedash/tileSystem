#include "tile.h"
#define _CRT_SECURE_NO_WARNINGS
#include "raylib.h"
#include <iostream>
#include <string>

Tile::Tile()
{
	Image image = LoadImage("resources/mapTile_187.png");
	ImageFormat(&image, UNCOMPRESSED_R8G8B8A8);
	tileTexture = LoadTextureFromImage(image);
}

Tile::~Tile()
{
	UnloadTexture(tileTexture);
}

Tile::Tile(std::string imageFilename)
{
	Image image = LoadImage(imageFilename.c_str());
	ImageFormat(&image, UNCOMPRESSED_R8G8B8A8);
	tileTexture = LoadTextureFromImage(image);
}

void Tile::Draw(int x, int y)
{
	DrawTexture(tileTexture, x, y, tint);
}

void Tile::CopyTo(Tile &tile) {
	tile.tileTexture = tileTexture;
	tile.tint = tint;
}
