#include "raylib.h"
#include "tile.h"
#include <iostream>
#include <cmath>

int main()
{
	InitWindow(800, 650, "tile"); //13x11
	//tile array
	Tile tileArr[13 * 11];
	Tile master = Tile("resources/mapTile_077.png");

	//Tile topLeft = Tile("resources/mapTile_077.png");
	Tile topRight = Tile("resources/mapTile_076.png");
	Tile bottomLeft = Tile("resources/mapTile_075.png");
	Tile bottomRight = Tile("resources/mapTile_020.png");
	SetTargetFPS(120);
	tileArr[11 + (13 * 9)] = bottomRight;// top right
	tileArr[0 + (13 * 9)] = bottomLeft;// top right
	tileArr[11] = topRight;// top right
	int lineX = 0;
	int lineY = 0;

	while (!WindowShouldClose())
	{

		BeginDrawing();
		ClearBackground(RAYWHITE);

		// change tile at mouse location on key press ///////////////////////////////

		int tileX = (int)(GetMousePosition().x / 64);
		int tileY = (int)(GetMousePosition().y / 64);
		tileX = ((tileX <= 0)?(0):(tileX >= 13) ? (13) : (tileX));
		tileY = ((tileY <= 0) ? (0) : (tileY >= 13) ? (13) : (tileY));
		Tile *tempTile = &tileArr[tileX + (13 * tileY)];
		
		if(IsMouseButtonDown(MOUSE_LEFT_BUTTON)) { // place & place
			if ((tileX == 11 || tileX == 0) && (tileY == 9 || tileY == 0)) {
				tempTile->CopyTo(master);
			} else {
				master.CopyTo(tileArr[tileX + (13 * tileY)]);
			}
		}
		if (IsMouseButtonPressed(MOUSE_RIGHT_BUTTON)) { // line start
			lineX = tileX;
			lineY = tileY;
		}
		if (IsMouseButtonReleased(MOUSE_RIGHT_BUTTON)) { // line start
			int x0 = lineX;
			int y0 = lineY;
			int x1 = tileX;
			int y1 = tileX;
			if (x0 < x1) {
				x0 = x0 ^ x1;
				x1 = x0 ^ x1;
				x0 = x0 ^ x1;
				y0 = y0 ^ y1;
				y1 = y0 ^ y1;
				y0 = y0 ^ y1;
			}
			float slope = (y1 - y0) / (x1 - x0);
			int y = 0;
			for (int x = x0; x > x1; x++) {
				if (!((x == 11 || x == 0) && (slope*x == 9 || slope * x == 0))) {
					x = ((x <= 0) ? (0) : (x >= 13) ? (13) : (x));
					y = ((slope*x <= 0) ? (0) : (slope*x >= 13) ? (13) : (slope*x));
					std::cout << y;
					master.CopyTo(tileArr[x + (13 * y)]);
				}
			}
		}

		// draw tiles ///////////////////////////////////////////////////////////////

		for (int i = 0; i < 13; i++) {
			for (int j = 0; j < 11; j++) {
				tileArr[i + 13*j].Draw(i*64,j*64);
			}
		}

		DrawFPS(700, 15);
		EndDrawing();
	}
	CloseWindow();
	return 0;
}

