#include <stdio.h>
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>
#include "levenshtein.h"

// Função que expõe o cálculo da distância de Levenshtein para o interpretador Lua
static int l_levenshtein(lua_State *L) {
    const char *s1 = luaL_checkstring(L, 1); // Primeiro argumento da pilha: string 1
    const char *s2 = luaL_checkstring(L, 2); // Segundo argumento da pilha: string 2
    int distance = levenshtein(s1, s2);      // Chama a função C
    lua_pushinteger(L, distance);            // Retorna a distância para o Lua
    return 1; // Número de valores retornados para o Lua
}

// Função que expõe o cálculo da distância de Hamming para o interpretador Lua
static int l_hamming(lua_State *L) {
    const char *s1 = luaL_checkstring(L, 1); // Primeiro argumento da pilha: string 1
    const char *s2 = luaL_checkstring(L, 2); // Segundo argumento da pilha: string 2
    int distance = hamming(s1, s2);          // Chama a função C
    lua_pushinteger(L, distance);            // Retorna a distância para o Lua
    return 1; // Número de valores retornados para o Lua
}

int main(void) {
    // Cria um novo estado da máquina virtual Lua
    lua_State *L = luaL_newstate();

    // Abre as bibliotecas padrão do Lua
    luaL_openlibs(L);

    // Registra as funções C no ambiente global do Lua
    lua_register(L, "levenshtein", l_levenshtein);
    lua_register(L, "hamming", l_hamming);

    // Executa o script Lua de demonstração
    if (luaL_dofile(L, "lua/demo.lua")) {
        // Caso haja erro ao rodar o script, imprime a mensagem no stderr
        fprintf(stderr, "Erro ao executar Lua: %s\n", lua_tostring(L, -1));
    }

    // Encerra o estado Lua e libera recursos
    lua_close(L);
    return 0;
}
