# Sobre

Este repositório contém códigos em C que desenvolvi enquanto estudava a linguagem.

Aprendi um pouco da linguagem C em 2016 com a ajuda do site [cprogressivo.net](https://www.cprogressivo.net/) e pesquisas na internet, inicialmente eu tinha feito no Windows, mas fiz alterações para funcionar no Linux.

Esses códigos estavam salvos no meu HD, eu não usava nenhum sistema de controle de versão, como o Git, e nem plataforma de hospedagem de código, como o GitHub, agora que lembrei deles, resolvi postá-los aqui para não perdê-los.

Por ser um repositório criado apenas para armazenar meu progresso e desenvolvimento enquanto aprendia C, não me preocupei com convenção de commit, apenas commitei com o nome do arquivo que alterei.

---

## Como executar

Para compilar eu usei o compilador GCC versão 11.3.0 com o padrão C11 no Ubuntu 22.04 (64 bits).

Na raiz do repositório execute os seguintes comandos:

1. Compilar:
> Crie a pasta `bin` caso não exista.
```
gcc -std=c11 ./src/codigo_fonte.c -o ./bin/codigo_compilado.out
```

2. Executar:
```
./bin/codigo_compilado.out
```
