# Exercício 1 

O programa é compilado em duas etapas: 
1) Cada arquivo `.c` é traduzido para um arquivo objeto `.o`.
2) O ligador combina os arquivos objeto para gerar o executável.

# Resultado:
A função `foo()`, definida em `temp2.c`, altera o valor da variável global `a` de `1024` para `-3`.

# Exercício 2 

As letras exibidas pelo comando `nm` indicam o tipo e a localização dos símbolos.
1) U = é um símbolo indefinido no módulo, sua definição deve ser encontrada em outro módulo.
2) T = é um símbolo definido na seção de código.

No arquivo `temp1.o`, a variável `a` aparece como `D`, a função `main` como `T` e a função `foo` como `U`.
No arquivo `temp2.o`, a variável `b` aparece como `D`, a função `foo` como `T` e a variável `a` como `U`.

# Exercício 3 

Ao substituir `int a = 1024;` por `char a = 1;` em `temp1.c`, ocorre um erro de tipos conflitantes. Este erro é detectado durante a compilação**, porque `temp1.h` declara `a` como `extern int a`, enquanto o arquivo tenta defini-la como `char`.
Isso demonstra a importância de incluir os arquivos de cabeçalho também nos módulos que definem os símbolos, para garantir a consistencia das declarações.

# Exercício 4.1

A compilação e a ligação podem ocorrer sem erros, pois o ligador identifica o símbolo pelo nome e não verifica a compatibilidade entre os tipos declarados nos diferentes módulos.
Entretanto, `temp1.c` considera `a` uma variável `int`, enquanto `temp2.c` a utiliza como `char`.

Assim, a atribuição `a = -3` modifica apenas um byte da variável original. 
Em uma arquitetura x86-64 little-endian, partindo de `1024`, o valor normalmente passa a ser `1277`, esse comportamento resulta de declarações incompatíveis e não deve ser considerado válido em um programa C correto.

# Exercício 4.2

Ocorre um erro na etapa de ligação, porque `temp1.c` e `temp2.c` passam a definir uma variável global chamada `a`, assiml, o ligador encontra duas definições globais do mesmo símbolo e informa um erro de múltipla definição.
Com `nm`, podemos observar que `a` aparece como um símbolo global definido nos dois arquivos objeto.

# Exercício 4.3 

A compilação e a ligação ocorrem normalmente. A palavra-chave `static`, nesse contexto, faz com que a variável `a` de `temp2.c` tenha ligação interna, ou seja, seja acessível apenas dentro desse módulo.
Consequentemente, existem duas variáveis distintas chamadas `a`. A função `foo()` altera somente a variável local ao módulo `temp2.c`, enquanto a variável global de `temp1.c` permanece com o valor `1024`.

# Resultado:

No `nm`, a variável `a` de `temp2.o` aparece com a letra minúscula `d`, indicando um símbolo local na seção de dados.

# Exercício 5.1 

Ao remover o cabeçalho `temp2.h` e substituir `foo()` por `b()`, o compilador pode interpretar `b` como uma função declarada implicitamente, dependendo da versão e das opções utilizadas.
O ligador encontra o símbolo global `b` definido em `temp2.o`, mas esse símbolo corresponde a uma variável inteira, não a uma função.
Se o executável for gerado e a chamada alcançar o endereço de `b`, o programa tentará executar os bytes da variável como instruções de máquina.
Isso pode provocar uma falha de execução, mesmo com a opção `-Wa,--execstack`, pois essa opção não torna automaticamente a seção de dados executável.

# Exercício 5.2

O valor hexadecimal `0xC3` corresponde ao opcode da instrução `ret` na arquitetura x86-64.
Como a máquina utiliza a representação little-endian, o inteiro `0x000000C3` é armazenado com os bytes `C3 00 00 00`, se a execução alcançar o primeiro byte de `b` e a memória permitir a execução, a instrução `ret` fará o programa retornar imediatamente da chamada.
Portanto, em sistemas Linux modernos, a seção de dados normalmente não possui permissão de execução. Portanto, o programa pode continuar apresentando uma falha de segmentação, demonstrando que o ligador resolve referências a símbolos pelo nome, mas não garante que uma variável esteja sendo utilizada como uma função.
