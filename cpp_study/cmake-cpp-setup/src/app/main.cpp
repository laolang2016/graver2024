extern "C" {
#include <lua/lauxlib.h>
#include <lua/lua.h>
#include <lua/lualib.h>
}

#include <iostream>
#include <memory>

#include "graver/common/common.h"
#include "graver/person/person.h"

int main(int argc, char** argv) {
    UNUSED(argc);
    UNUSED(argv);
    auto person = std::make_unique<Person>(18, "laolang");
    std::cout << "Hello . My name is " << person->name() << " ." << std::endl;

    std::cout << "lua" << std::endl;

    // 创建 lua 状态
    lua_State* L = luaL_newstate();

    // 启用基本的 lua 库
    luaopen_base(L);

    // 加载 lua 文件
    luaL_loadfile(L, "main.lua");

    // 运行 lua 文件
    int ret = lua_pcall(L, 0, 0, 0);
    std::cout << "ret:" << ret << std::endl;

    return 0;
}
