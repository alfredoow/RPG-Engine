#include <iostream>
#include "raylib.h"

#include "core/inventory.h"
#include "core/world.h"
#include "core/player.h"

Weapon iron_sword = Weapon("iron sword", 15);
Armor quartz_ring = Armor("quartz ring", 0, 6, 3, 0);

Player player = Player(10, 1, 1);

const int MAP_W = 5;
const int MAP_H = 5;
const int MAP_S = MAP_W * MAP_H;

Tile map[MAP_S];
char rendered_map[MAP_S];

Texture tex_tiles_atlas;
Texture tex_player;

Camera2D camera;

void drawTiles();

int main() {
	InitWindow(640, 360, "RPG TEST");

	for (int x = 0; x < MAP_W; x++) {
		for (int y = 0; y < MAP_H; y++) {
			map[x + y * MAP_H].solid = (x == 0 || x == MAP_W - 1 || y == 0 || y == MAP_H - 1) ? true : false;
		}
	}

	camera.target = { (float)player.x, (float)player.y };

	tex_tiles_atlas = LoadTexture("resources/gfx/overworld_atlas.png");
	tex_player = LoadTexture("resources/gfx/player.png");

	while (!WindowShouldClose()) {
		if (IsKeyPressed(KEY_A) && !map[(player.x - 1) + player.y * MAP_H].solid) {
			player.x -= 1;
		}

		if (IsKeyPressed(KEY_D) && !map[(player.x + 1) + player.y * MAP_H].solid) {
			player.x += 1;
		}

		if (IsKeyPressed(KEY_W) && !map[player.x + (player.y - 1) * MAP_H].solid) {
			player.y -= 1;
		}

		if (IsKeyPressed(KEY_S) && !map[player.x + (player.y + 1) * MAP_H].solid) {
			player.y += 1;
		}

		BeginDrawing();
		ClearBackground(DARKBLUE);
		drawTiles();
		DrawTexturePro(tex_player, { 0, 0, 16, 16 }, { (float)player.x * 32, (float)player.y * 32, 32, 32 }, { 0, 0 }, 0, WHITE);
		EndDrawing();
	}

	return 0;
}

void drawTiles() {
	for (int x = 0; x < MAP_W; x++) {
		for (int y = 0; y < MAP_H; y++) {
			int i = x + y * MAP_H;
			Tile t = map[i];

			if (t.solid) {
				DrawTexturePro(tex_tiles_atlas, { TILE_WALL, 0, 16, 16 }, { (float)x * 32, (float)y * 32, (float)32, (float)32 }, { 0, 0 }, 0, WHITE);
			} else {
				DrawTexturePro(tex_tiles_atlas, { TILE_FLOOR, 0, 16, 16 }, { (float)x * 32, (float)y * 32, (float)32, (float)32 }, { 0, 0 }, 0, WHITE);
			}
		}
	}
}
