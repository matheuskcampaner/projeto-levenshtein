# Projeto Levenshtein - Integração C + Lua

## Descrição

Demonstração de integração entre C e Lua, com funções de cálculo de **Levenshtein** e **Hamming**.

## Estrutura

- `src/`: código-fonte C.
- `lua/`: script de demonstração.
- `Makefile`: automação de build.

## Como compilar

```bash
make
```

## Como executar

```bash
make run
```

## Como limpar

```bash
make clean
```

## Dependências

- GCC
- Lua 5.3 ou superior

## Alterações na biblioteca Levenshtein

- Ajustada para compilação integrada.
- Adicionada função `hamming`.

## Licença

MIT License.