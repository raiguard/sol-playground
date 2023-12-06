Events.on_init(function()
  local pos1 = Position.new()
  print(pos1.x, pos1.y)

  local sum = pos1 + Position.new(3.14, 4)
  print(sum)

  local mod = Position.new(4, 4) % Position.new(3, 4)
  print(mod)

  print(Position.new(4, 4) == Position.new(4, 4))
  print(Position.new(4, 4) <= Position.new(4, 4))
  print(Position.new(4, 4) < Position.new(4, 4))
  print(Position.new(4, 4.01) > Position.new(4, 4))
end)

--- @param other Position
--- @return Position
function Position:__mod(other)
  return Position.new(self.x % other.x, self.y % other.y)
end
