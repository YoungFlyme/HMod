-- set all the info
print("++++++++++LUA ALIVE!++++++++++++++++")

Srv.Console:Print(0, "dennis", "blub")

Srv.Console:Register("dennis_is_krass", "r", "much dennis!", function(result)
	Srv.Console:Print(0, "you dennissed!", "with: " .. result:GetString(0)) 
end)

Srv.Console:Register("make_dennis", "", "dew it!", function(result)
	local ninjadude = Srv.Game:CreateEntityPickup(2, 3) -- 3 5
	ninjadude:BindClass("Dennis")
	table.insert(Character.ents, ninjadude)
	print(#Character.ents, tostring(ninjadude))
	Srv.Console:Print(0, "make_dennis", "made a dennis!")
end)
