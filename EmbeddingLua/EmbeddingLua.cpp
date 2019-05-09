#include <iostream>
#include <string>


extern "C"
{
#include "Lua535/include/lua.h"
#include "Lua535/include/lauxlib.h"
#include "Lua535/include/lualib.h"
}

#ifdef _WIN32
#pragma comment(lib,"lua535/liblua53.a")
#endif

bool CheckLua(lua_State *L,int r)
{
	if(r != LUA_OK)
	{
		std::string errormsg = lua_tostring(L,-1);
		std::cout << errormsg << std::endl;

		return false;
	}

	return true;
}

int lua_HostFunction(lua_State *L)
{
	float a = (float)lua_tonumber(L,1);
	float b = (float)lua_tonumber(L, 2);

	std::cout << "[C++] HostFunction(" << a << "," << b << ") called "<< std::endl;

	float c = a * b;

	lua_pushnumber(L,c);

	return 1;
}


int main()
{
	struct Player
	{
		std::string title;
		std::string name;
		std::string family;
		int level;
	} player;

	std::string cmd = "a = 7 + 11 + math.sin(23.7)";

	lua_State *L = luaL_newstate();
	luaL_openlibs(L);

	lua_register(L,"HostFunction",lua_HostFunction);


	if(CheckLua(L,luaL_dofile(L,"Test.lua")))
	{
	
		lua_getglobal(L,"DoAThing");
		if(lua_isfunction(L,-1))
		{
			lua_pushnumber(L,5.0f);
			lua_pushnumber(L, 6.0f);

			if(CheckLua(L,lua_pcall(L,2,1,0)))
			{


				std::cout << "[C++] Called in Lua AddStuff(5.0f,6.0f), got " << (float)lua_tonumber(L,-1) << std::endl;
			}


		}

		/*lua_getglobal(L,"player");
		if(lua_istable(L,-1))
		{
			lua_pushstring(L,"Name");
			lua_gettable(L,-2);
			player.name = lua_tostring(L,-1);
			lua_pop(L,1);

			lua_pushstring(L, "Family");
			lua_gettable(L, -2);
			player.family = lua_tostring(L, -1);
			lua_pop(L, 1);

			lua_pushstring(L, "Title");
			lua_gettable(L, -2);
			player.title = lua_tostring(L, -1);
			lua_pop(L, 1);

			lua_pushstring(L, "Level");
			lua_gettable(L, -2);
			player.level = lua_tonumber(L, -1);
			lua_pop(L, 1);

		}*/

	}

	//std::cout << player.title << " " << player.name << " of " << player.family << " Lvl " << player.level << std::endl;

	system("pause");
	lua_close(L);
	return 0;
}