#pragma once
#include "raylib.h"
#include <string>
#include <iostream>
#include "raylib.h"
class Tile {
public:
	Texture2D tileTexture;
	Color tint = WHITE;
	Tile();
	~Tile();
	Tile(std::string imageFilename);
	void Draw(int x, int y);
	void CopyTo(Tile &tile);
};