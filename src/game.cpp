#include "game.hpp"

#include "raylib.h"
#include "type_aliases.hpp"

#include <chrono>
#include <iostream>


Game::Game()
  :lastFrameTime(std::chrono::steady_clock::now())
{
  std::cout << "[Game]: created.\n";

  InitWindow(
    1000,
    1000,
    "Raylib Prairie King"
  );
  SetWindowState(FLAG_VSYNC_HINT);
}


Game::~Game() {
  CloseWindow();

  std::cout << "[Game]: destroyed.\n";
}


void Game::run() {
  // Main game loop
  while (!WindowShouldClose())
  {
    TimePoint currentFrameTime{ std::chrono::steady_clock::now() };
    TimeMicroseconds deltaTime{
      std::chrono::duration_cast<TimeMicroseconds>(lastFrameTime - currentFrameTime)
    };
    lastFrameTime = currentFrameTime;

    tick(deltaTime);

    draw();
  }
}


void Game::tick(TimeMicroseconds deltaTime) {
  std::cout << deltaTime.count() << '\n';
}


void Game::draw() {
    BeginDrawing();

      ClearBackground(RAYWHITE);

      DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

    EndDrawing();
}
