--- @meta

--- @class Position
--- @operator add(Position): Position
--- @field x number
--- @field y number
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
