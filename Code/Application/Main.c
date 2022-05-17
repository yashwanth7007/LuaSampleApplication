#include <stdio.h>
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>

int add(lua_State* L);

int main()
{
    lua_State *L = luaL_newstate();
    luaL_openlibs(L);
    printf("hello from C \n");
    lua_pushcfunction(L, add);
    lua_setglobal(L, "addition");



    luaL_dofile(L,"C:\\work\\Lua\\Code\\Application\\app.lua");


    lua_getglobal(L, "x");

    double x = lua_tonumber(L, -1);

    printf("The value of x in lua is %f", x);

    lua_getglobal(L, "PrintMsg");

    lua_pushstring(L, "hello from lua");
    lua_pushnumber(L, 3);

    lua_pcall(L, 2, 0, 0);

   
    lua_close(L);
    return 0;
}

add(lua_State* L)
{
    double n1 = lua_tonumber(L, -2);
    double n2 = lua_tonumber(L, -1);

    lua_pushnumber(L, (n1 + n2));

    return 1;
}