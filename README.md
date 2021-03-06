# ed-1-ifc
Relatório Lista Hashing

Para resolução do problema proposto foi utilizado a lista duplamente encadeada, como solicitado, foi então implementado adição de dados manualmente ou por importação de arquivo, busca de itens pelo nome, impressão das listas e impressão da quantidade total de elementos nas listas.

As estruturas foram criadas de modo a que são feitas uma lista a qual recebe dentro dela elementos de "Chaves" que guardam os valores da chave em questão e possui implementado dentro da mesma uma estrutura de lista para guardar os elementos, dessa forma possibilitando a criação de uma lista hash com tamanhos dinamicos.

Para a função modular que iria realizar o espalhamento foi utilizada uma função que calcula o valor na tabela ASCII de cada caractere da palavra, a multiplica por uma constante e divide o valor pelo tamanho(M) da tabela, nos exemplos foi utilizado os tamanhos 11 e 13 por serem números primos e gerarem um espalhamento mais satisfatório

Figura 1 - Tabela ASCII
<br />
<img src="https://dkrn4sk0rn31v.cloudfront.net/uploads/2020/05/ascii-7bits-v2.png" >
<br />
Fonte - Tedesco, 2020

Para exemplificar o processo de espalhamento utilizaremos a palavra : EXEMPLO.
Convertendo o valor individual de cada caracter desta palavra obtemos o seguinte resultado:
<img src="/exemplo.png" >

O método funciona utilizando uma variável acumuladora. Cada letra, após convertida a ASCII, é dividida por M da tabela e utiliza o resto do valor M da tabela, em seguida o resto é multiplicado pela constante, neste caso 31 e adicionado ao valor anterior, em seguida é dividido pelo valor M novamente e o resto deste valor é incrementado a variável que repete o mesmo processo até o último caractere da palavra, onde por fim é definido a chave Hash no qual a palavra ser inserida. Neste exemplo foi utilizado o valor M de 11 para demonstrar.

Foi então deste modo procurado o hashing ideal utilizando essa função, adotando M como um número primo, sempre buscando utilizar o menor valor possível para M. Após serem inseridos esses dados, obtivemos os seguintes resultados utilizando os valores 11 e 13 para M.

Figura 3 - Gráfico utilizando M como 11 
<img src="/img1.png" >

Figura 4 - Gráfico utilizando M como 13
<img src="/img2.png" >

Como foi verificado a média utilizando M como 11 foi de ≅ 0,16 e no caso de 13 foi de ≅ 0,002, tendo um espalhamento pouco, porém mais próximo ao ideal. Ao utilizarmos números primos obtivemos melhores resultados para expalhamentos, tendendo a ter um valor de espalhamento melhor utilizando o M entre 20 e 30.

Ao utilizar a lista encadeada dupla, o tratamento de colisão não foi necessário, pois como cada elemento tem ligação entre os mesmos nenhuma colisão irá ocorrer, pois cada chave está ligada a próxima e cada elemento dentro da chave está ligado ao próximo elemento subsequente. Utilizando o tratamento de colisão por encadeamento que já é feito ao inserir o item, não sendo necessário a utilização da sondagem linear.

Para ordenação dos itens de forma alfabética foi utilizado um método de quicksort mais simplificado pois não foi possível implementar corretamente o método. O método ordena utilizando os extremos da lista, percorrendo a lista inteira e considerando o pivô como o item final, e caso o valor comparado seja menor que o pivô, os itens são invertidos, e ao fim insere o pivô no local correto. Como o método é feito com os elementos extremos tem uma eficiência reduzida na ordenação do mesmo.

REFERÊNCIAS

TEDESCO, Kennedy. Uma introdução a ASCII e Unicode: veja um pouco mais sobre os sistemas de codificação de caracteres ascii e unicode. Veja um pouco mais sobre os sistemas de codificação de caracteres ASCII e Unicode. 2020. Disponível em: https://www.treinaweb.com.br/blog/uma-introducao-a-ascii-e-unicode. Acesso em: 12 jul. 2021.

Link para vídeo com o codigo : https://drive.google.com/file/d/1oFlMQ5ld6b2nVI0RfD-FaGEEEI9kxU8_/view?usp=sharing
