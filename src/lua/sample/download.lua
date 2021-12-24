--[[
	This downloads a file from the internet.
	It is also proof as to why you should only install runtime modules
	from trusted sources.

	Note: It doesn't work without lua-socket installed. This is intended behavior.
	I will NOT include lua-socket with fake-cmd, for this exact reason
--]]

local http = require("socket.http")

local res, err = http.request("https://i.ytimg.com/vi/9SklO4OFEJI/maxresdefault.jpg")

if not res then error(err) end

-- saves response to file
local f = assert(io.open("sussy.jpg", "wb"))
f:write(res)
f:close()