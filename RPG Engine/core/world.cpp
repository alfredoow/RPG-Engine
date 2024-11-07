#include "world.h"

Map::Map(int width, int height) {
	this->tiles[width * height] = {};
	this->width = width;
	this->height = height;
}

Tile Map::getTile(int x, int y) {
	return tiles[x + y * height];
}

void Map::setTile(int x, int y, Tile tile) {
	tiles[x + y * height] = tile;
}