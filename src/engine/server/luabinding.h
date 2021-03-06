#ifndef ENGINE_SERVER_LUABINDING_H
#define ENGINE_SERVER_LUABINDING_H

#include <lua.h>

#define argcheck(cond, narg, expected) \
		if(!(cond)) \
		{ \
			if(g_Config.m_Debug) \
				dbg_msg("Lua/debug", "%s: argcheck: narg=%i expected='%s'", __FUNCTION__, narg, expected); \
			char buf[64]; \
			str_format(buf, sizeof(buf), "expected a %s value, got %s", expected, lua_typename(L, lua_type(L, narg))); \
			return luaL_argerror(L, (narg), (buf)); \
		}


class CLuaBinding
{
	static class CLua *ms_pLua;

public:
	static void StaticInit(CLua *pLua) { ms_pLua = pLua; }

	static int ScriptName(lua_State *L);
	static int Print(lua_State *L);
	static int Throw(lua_State *L);
};

void luaX_openlibs(lua_State *L, const luaL_Reg *lualibs);
void luaX_openlib(lua_State *L, const char *name, lua_CFunction func);
void luaX_register_module(lua_State *L, const char *name);

#endif
