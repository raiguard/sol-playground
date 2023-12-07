#include "lua.hpp"
#include "player.hpp"
#include <chrono>
#include <iostream>
#include <map>
#include <thread>

static constexpr std::chrono::duration sixtyIshFPS = std::chrono::milliseconds(1000) / 60;

int main(int, char**) {
  Lua lua;
  lua.init();

  std::map<std::string, std::shared_ptr<Player>> players;

  for (int i = 0; i < 5; i++) {
    std::string name = std::format("player-{}", i);
    players[name] = std::make_shared<Player>(name);
    if (lua.onPlayerCreated)
      lua.onPlayerCreated->call(players[name]);
  }

  using clock = std::chrono::steady_clock;
  auto next_frame = clock::now();
  for (int tick = 0;; tick++) {
    next_frame = clock::now() + sixtyIshFPS;

    if (lua.onTick)
      if (bool res = lua.onTick->call(tick); res)
        break;

    std::this_thread::sleep_until(next_frame);
  }
}
