Events.on_init(function()
  local pos1 = Position.new(1, -3)
  print(pos1)
  print(pos1.x, pos1.y)

  print(pos1 + Position.new(3.14, 4))

  print(Position.new(4, 4) == Position.new(4, 4))
  print(Position.new(4, 4) <= Position.new(4, 4))
  print(Position.new(4, 4) < Position.new(4, 4))
  print(Position.new(4, 4.01) > Position.new(4, 4))
end)
