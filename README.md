# Estruturas de Dados
Os programas foram desenvolvidos durante as aulas de Estruturas de Dados. 
As estruturas de dados presentes nesse projeto são: 
- Fila: FIFO (First-in, First-Out).
- Pilha: LIFO (Last-in, First-Out).
- Lista: coleções dinâmicas que podem variar de tamanho, de acordo com a necessidade.
Cada estrutura possui dois tipos de implementação, uma utilizando arrays, e outra utilizando nós. 

### 1. Implementação com Array (Estática)
Utiliza um array de tamanho fixo para armazenar os elementos.

-   **Vantagens:** Acesso aos elementos é muito rápido, pois eles são armazenados em posições de memória contíguas. É simples de implementar para um número fixo de elementos.
-   **Desvantagens:** O tamanho do array é definido no momento da compilação e não pode ser alterado. Isso pode resultar em desperdício de memória (se o array for muito grande) ou em um erro de "overflow" (se for pequeno demais). Inserções e remoções no meio da lista são lentas, pois exigem o deslocamento de todos os elementos subsequentes.

### 2. Implementação com Nós e Ponteiros (Dinâmica)
Utiliza uma estrutura Nó, que contêm o dado e um ponteiro para o próximo nó. No caso das listas duplamente encadeadas, há também um ponteiro para o nó anterior.

-   **Vantagens:** A lista pode crescer ou diminuir dinamicamente durante a execução do programa, utilizando a memória apenas conforme necessário. Inserções e remoções são rápidas, pois exigem apenas a reatribuição de ponteiros.
-   **Desvantagens:** O acesso a um elemento específico (por exemplo, o décimo item) é mais lento, pois é necessário "caminhar" pela lista a partir do início. 

# Busca Binária
Busca Binária é um algoritmo eficiente para procurar um elemento em um array ordenado, realizando sucessivas divisões do espaço de procura até encontrar o item desejado.
Foi utilizado o Algoritmo ShellSort para a ordenação do array. 