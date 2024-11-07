#pragma once

#define TILE_GRASS 0
#define TILE_ROCK 16
#define TILE_FLOOR 32
#define TILE_WALL 48

struct Tile {
	bool solid = false;
};

class Map {
private:
	int width = 0;
	int height = 0;
	Tile tiles[];
public:
	Map(int width, int height);

	Tile getTile(int x, int y);
	void setTile(int x, int y, Tile tile);
};