--[[
	This module reads a name from the user, then prints:
	"Hello, $USER"
	If no name provided, prints "Hello, neo..."
--]]

local name = io.read()

if name ~= "" then
	print("Hello, "..name.."...")
else
	print("Hello, neo...")
end