--[[
	This module creates a file in the directory where fakecmd is installed.
--]]

local file = io.open("amogus.txt", "a")

if file ~= nil then
    file:write("Dababy school of sussy amogus")
    file:close() 
end