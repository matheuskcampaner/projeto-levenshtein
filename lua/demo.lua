print("Demonstração do cálculo de distância de Levenshtein:")

local pares = {
    {"kitten", "sitting"},
    {"flaw", "lawn"},
    {"gumbo", "gambol"},
    {"book", "back"}
}

for _, par in ipairs(pares) do
    local s1, s2 = par[1], par[2]
    local distancia = levenshtein(s1, s2)
    print(string.format("Levenshtein entre '%s' e '%s': %d", s1, s2, distancia))
end

print("\nDemonstração do cálculo de distância de Hamming:")

local pares_hamming = {
    {"karolin", "kathrin"},
    {"karolin", "kerstin"},
    {"1011101", "1001001"},
    {"2173896", "2233796"}
}

for _, par in ipairs(pares_hamming) do
    local s1, s2 = par[1], par[2]
    local distancia = hamming(s1, s2)
    if distancia >= 0 then
        print(string.format("Hamming entre '%s' e '%s': %d", s1, s2, distancia))
    else
        print(string.format("Erro: tamanhos diferentes entre '%s' e '%s'", s1, s2))
    end
end
