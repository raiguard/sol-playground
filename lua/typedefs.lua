--- @meta

--- @class Events
Events = {}
--- Register a handler to execute on game initialization.
--- @param handler fun()
function Events.on_init(handler) end
--- Register a handler to execute when a player is created.
--- @param handler fun(player: Player)
function Events.on_player_created(handler) end
--- Register a handler to execute on every game tick. Returning `true` will end the game.
--- @param handler fun(tick: integer): boolean
function Events.on_tick(handler) end

--- @class Player
--- @field name string
--- @field position Position
Player = {}
--- Move the player by the given delta, returning the new position.
--- @param delta Position
--- @return Position
function Player:move(delta) end

--- @class Position
--- @operator add(Position): Position
--- @operator sub(Position): Position
--- @operator mul(Position): Position
--- @operator div(Position): Position
--- @operator add(number): Position
--- @operator sub(number): Position
--- @operator mul(number): Position
--- @operator div(number): Position
--- @field x number
--- @field y number
Position = {}
--- @overload fun(): Position
--- @overload fun(xy: number): Position
--- @overload fun(x: number, y: number): Position
--- @overload fun(vec: Vector): Position
function Position.new() end
--- @return Position
function Position:abs() end
--- @param other Position
--- @return number
function Position:distance_to(other) end

--- @class Vector : Position
--- @field magnitude number
Vector = {}
--- @overload fun(): Vector
--- @overload fun(x: number, y: number): Vector
--- @overload fun(pos: Position): Vector
--- @overload fun(from: Position, to: Position): Vector
function Vector.new() end
--- @return Vector
function Vector:get_norm() end
