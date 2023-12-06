--- @meta

--- @class Position
--- @field x number
--- @field y number
--- @operator add(Position): Position
Position = {
  --- @param x number?
  --- @param y number?
  --- @return Position
  new = function(x, y) end,
}

--- @class events
Events = {
  --- Register a handler to execute on game initialization.
  --- @param handler fun()
  on_init = function(handler) end
}
