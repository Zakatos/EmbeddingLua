

--PlayerTitle = "Squire"
--PlayerName = "Ciaran"
--PlayerFamily = "Wirral"
--PlayerLevel = 20


--Player = {}
         --keys	   --values
--player["Title"] = "Squire"
--player["Name"] = "Ciaran"
--player["Family"] = "Wirral"
--player["Level"] = 20

players = {}
players[0] = {Title = "Squire", Name = "Ciaran", Family = "Wirral", Level = 20}
players[1] = {Title = "Lord", Name = "Diego", Family = "Brazil", Level = 50}

--the two dots concatenate 
function AddStuff(a,b)
	--print("[LUA] AddStuff("..a.. " ,"..b..") called \n") 
	return a + b
end

function GetPlayer(n)
	return player[n]
end

function DoAThing(a,b)

	c = HostFunction(a + 10,b * 3)

	return c
end

