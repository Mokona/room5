-- Setup ----------------------------------------------------------------------

local worldWidth = 4
local worldHeight = 8
local levelMaxWidth = 32
local levelMaxHeight = 24
local outputDir = "F:/www/MO5/room5/room5/data/level" -- CHANGER LE CHEMIN, ICI C'EST POUR MON PC
local doLog = true
local saveBin = true

-- Dialog -----------------------------------------------------------------
local dlg = Dialog("Export slices")
dlg:file{
	id = "directory",
	label = "Output directory:",
	filename = outputDir,
	open = false
}
dlg:check{id = "bin", label = "Save binary:", selected = saveBin}
dlg:button{id = "ok", text = "Export"}
dlg:show()

saveBin = dlg.data.bin

-- Initialize -----------------------------------------------------------------

if doLog then print("Export - Start") end

local spr = app.activeSprite
if not spr then return print "No active sprite" end

if ColorMode.TILEMAP == nil then ColorMode.TILEMAP = 4 end
assert(ColorMode.TILEMAP == 4)

local fs = app.fs
local pc = app.pixelColor
local content = ""
local filename = ""
local currentRoom = ""
local roomIndex = 0

-- Function to write data to a file
local function write_text(filename, data)
	if doLog then print("Export - Write: " .. filename) end
	local file = io.open(filename, "w")
	file:write(data)
	assert(file:close())
end

-- Function to write data to a file
local function write_data(filename, data)
	if doLog then print("Export - Write: " .. filename) end
	local file = io.open(filename, "wb")
	local str = string.char(table.unpack(data))
	file:write(str)
	assert(file:close())
end

-- Function to export the tileset index layout
local function export_cel(cel, cColStart, cColEnd, cRowStart, cRowEnd)

	local bounds = Rectangle{ x = 0, y = 0, width = levelMaxWidth, height = levelMaxHeight }
	roomIndex = 1

	if cel.image.colorMode == ColorMode.TILEMAP then

		local tilemap = cel.image
		for row=cRowStart,cRowEnd do

			for col=cColStart,cColEnd do

				-- Initialize room variables
				currentRoom = ""
				bounds.x = col * levelMaxWidth
				bounds.y = row * levelMaxHeight
				levelWidth = levelMaxWidth
				levelHeight = levelMaxHeight
				lineLength = 0
				content = "const unsigned char g_Level" .. string.format("%03i", roomIndex) .. "[] = {"
				dataTab = {}

				-- Parsing room bounds
				for it in tilemap:pixels(bounds) do

					-- Get local coordinate
					localX = it.x % levelMaxWidth
					localY = it.y % levelMaxHeight

					-- Get tile index value
					local val = pc.tileI(it())
					if (val == nil) then 
						val = 0
					end

					-- Check room boundaries
					if (val == 256) then
						if (localX == 0) then
							levelHeight = localY
						else
							levelWidth = localX
						end
					end

					-- Store valid index in the data table
					if (localX < levelWidth and localY < levelHeight) then
						-- Line break
						if (lineLength % levelWidth) == 0 then 
							content = content .. "\n\t"
						end
						-- Add tile index
						content = content .. string.format("%3i", val) ..", "
						lineLength = lineLength + 1
						dataTab[#dataTab + 1] = val
					end
				end
				content = content .. "\n};\n\n"

				-- Save level size
				defines = "#define LEVEL" .. string.format("%03i", roomIndex) .. "_WIDTH " .. levelWidth
				defines = defines .. "\n#define LEVEL" .. string.format("%03i", roomIndex) .. "_HEIGHT " .. levelHeight
				defines = defines .. "\nextern const unsigned char g_Level" .. string.format("%03i", roomIndex) .. "[];"
				content = content .. defines

				-- Save level data
				if (saveBin) then -- Binary
					filename = outputDir .. "/level" .. string.format("%03i", roomIndex)..".bin"
					write_data(filename, dataTab)
					filename = outputDir .. "/level" .. string.format("%03i", roomIndex).."_def.h"
					write_text(filename, defines)
				else -- Text
					filename = outputDir .. "/level" .. string.format("%03i", roomIndex)..".h"
					write_text(filename, content)
				end
				roomIndex = roomIndex + 1
			end
		end
	end
end

-- Function to parse the given layer
local function export_layers(layers)
	local t = ""
	for _,layer in ipairs(layers) do
		if layer.isImage and layer.name=="MAIN" then
			if #layer.cels >= 1 then
				export_cel(layer.cels[1], 0, worldWidth - 1, 0, worldHeight - 1)
			end
		end
	end
end

-- Start parsing Asprite data -------------------------------------------------

fs.makeDirectory(outputDir)
export_layers(spr.layers)

if doLog then print("Export - End") end