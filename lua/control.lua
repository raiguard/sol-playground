--- @type table<string, {player: Player, target: Position}>
local players = {}

Events.on_init(function()
  local vec1 = Vector.new(5, 3)
  print(vec1)
  print(vec1:get_norm())
  print(vec1.magnitude)
  vec1.magnitude = 1
  print(vec1)
  print(vec1.magnitude)
end)

Events.on_player_created(function(player)
  local data = {
    target = Position.new(math.random(-500, 500), math.random(-500, 500)),
    player = player,
  }
  players[player.name] = data
  print("Created " .. tostring(player) .. " with target position " .. tostring(data.target))
end)

Events.on_tick(function()
  for _, data in pairs(players) do
    local player = data.player
    local delta = Vector.new(player.position, data.target)
    delta.magnitude = math.min(delta.magnitude, 1)
    player:move(delta)
    if player.position:distance_to(data.target) < 0.0001 then
      print("Player " .. player.name .. " reached the target!")
      players[player.name] = nil
    end
  end
  return not next(players)
end)
