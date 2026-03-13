#pragma once

#include "type_aliases.hpp"


class Game {
  public:
    Game();
    ~Game();

    /*
     * Run method starts the game and controls the game loop.
     */
    void run();

  private:
    // Private member variables
    TimePoint lastFrameTime;

    // Private member functions

    /*
     * Tick function for processing every game tick.
     * Takes an argument `deltaTime` that represents the time in microseconds
     * since the last tick.
     */
    void tick(TimeMicroseconds deltaTime);

    /*
     * Draw function for drawing every frame.
     */
    void draw();
};
