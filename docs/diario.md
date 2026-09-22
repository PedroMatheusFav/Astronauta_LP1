# Diário da atividade

Escreva com as suas palavras. Frases curtas bastam. Não cole a conversa inteira
com a IA. Cole só os pedidos que você enviou.

## Ambiente

- Versão do OpenCode (`opencode --version`): 1.18.32
- Modelo usado: Big Pickle

## Parte 1: antes de programar

- O que cada classe guarda:
Astronauta: guarda cpf, nome e idade
Voo: guarda codigo
Agencia: guarda tanto Astronauta e suas variaveis quanto os Voos

- O que acontece em `LANCAR_VOO`, em palavras:
se o comando for igual "lançar voo" recebe um valor e associa a "codigo", pega a variavel "codigo" e associa a agencia.

- Uma dúvida que eu tinha antes de começar:
porque todos os cout tem "<< comando " se a parte "TODO", ja recebe todo valor o caminho e até o comando tipo quando o comando é lançar voo e o TODO = agencia.lancarVoo(codigo);

## Parte 1: uso de IA para entender algo

- O que perguntei (ou "não usei"): usei pra quebrar os 3 slides em partes menores e mais interativas para entender como aplicar o codigo.

- O que aprendi: aprendi que todas as classes devem ter private e public, alem disso tem que ter os GETERS pra ter acesso as variaveis do private, o CONSTRUTOR que vai definir as variaveis da nossa classe e oque vai ter de valores dentro dela (algumas classes nao tem esses construtores), e por fim as AÇOES que vão fazer os trabalhos pesados, seria os nossos f(x) e g(x), onde entra um valor e sai outro valor (y) seguindo um algoritmo/equação especifica.

## Primeiro contato: revisão sem editar ----------------------------------------------------------------------------------

- As três melhorias que a IA sugeriu, em uma linha cada:
  1. Getters que copiam o vetor inteiro
  2. Validação repetida "voo nao esta planejado"
  3. Estado do voo como enum em vez de string

- A que escolhi e por quê: escolhi a primeira porque é uma melhoria facil de fazer e vai deixar mais otimizado o programa.
- O que mudou no código, e se os seis testes continuaram passando: adicionou um termo "const", pelo visto sem isso o programa tava criando um vector novo toda vez que tava chamando ele. teve que dar uma editada mas os 6 testes estão funcionando agora.

- O que entendi que não sabia antes: o termo "const" é util pra deixar o programa mais otimizado e da pra fazer os testes muito facil com o opencode.

## Missão 1: LISTAR_ASTRONAUTAS e HISTORICO

- Primeira mensagem (o pedido do plano): vamos fazer a missao 1, para faze-la preciso que vc analise o codigo main e os imput e output da missao 1 que estão dentro da pasta de testes, antes de fazer as modificações me diga seu plano para adicionar a lista de astronauta e o historico que aparece nos output da missao 1. E me de um resumo tb para eu colocar no diario.

- O plano que a IA apresentou, resumido:
│ Missão 1 — LISTAR_ASTRONAUTAS e HISTORICO
  │
  │ Fiz o comando LISTAR_ASTRONAUTAS: ele mostra os astronautas em três grupos — disponíveis, em voo e mortos — na ordem de cadastro, com o formato CPF Nome (X anos). Quem está em um voo em
  │ curso aparece com - voo <codigo>, e grupo vazio mostra (nenhum).
  │
  │ Fiz também o HISTORICO cpf: ele lista os voos que foram lançados com o astronauta a bordo, com o estado atual de cada um, na ordem de cadastro dos voos. Se o CPF é desconhecido, imprime um
  │ erro.
  │
  │ Um aprendizado: não precisei criar uma estrutura extra para o histórico. Como só dá para colocar ou tirar astronauta de um voo planejado, depois do lançamento a lista de passageiros fica
  │ congelada — então o histórico é só olhar os voos lançados em que o CPF aparece.
  │
  │ Testes: bash testes/testar.sh missao1 e bash testes/testar.sh parte1.

- Mudei algo no plano antes de liberar? nao
- Resultado de `testar.sh missao1` e de `testar.sh parte1`: sucesso
- Precisei refazer? O que mudou no pedido: nada

## Missão 2: SALVAR e CARREGAR

- Primeira mensagem: vamos fazer a missao 2, para faze-la preciso que vc analise o codigo main e os imput e output da missao 2 que estão dentro da pasta de testes, antes de fazer as modificações me diga seu plano para adicionar os elementos que aparecem no output da missao 2. E me de um resumo tb para eu colocar no diario.

- O plano, resumido: Pedi pra Missão 2: comandos SALVAR e CARREGAR. O plano foi: adicionar #include <fstream>, dois setters no Astronauta (vivo/disponível) e um no Voo (estado), e na Agencia os métodos salvarDados e carregarDados. O CARREGAR lê primeiro para vetores temporários e só troca os dados se a leitura funcionar, para não perder nada se o arquivo não existir. O formato é texto: seção ASTRONAUTAS com cpf idade vivo disponivel nome e seção VOOS com codigo quantidade estado e os CPFs abaixo. (Depois de rodar, eu preencho as 5 linhas do dados_teste.txt de verdade.)

- O formato do arquivo (cole cinco linhas do `dados_teste.txt`): 
  ASTRONAUTAS 3
  111 30 1 1 Ana Maria
  222 35 0 0 Bruno Costa
  333 28 1 1 Carla Souza
  VOOS 3

- Resultado de `testar.sh missao2` e de `testar.sh parte1`: sucesso
- Precisei refazer? O que mudou no pedido: precisei pedir para ele ignorar o CRLF, parece que esse negocio ta dando erro e ele fica em um loop por causa disso.

## Missão 3: RELATORIO

- Primeira mensagem: vamos fazer a missao 2, para faze-la preciso que vc analise o codigo main e os imput e output da missao 2 que estão dentro da pasta de testes, antes de fazer as modificações me diga seu plano para adicionar os elementos que aparecem no output da missao 2. E me de um resumo tb para eu colocar no diario.

- O plano, resumido: Missão 3 – RELATORIO. Pei o plano antes de editar. O plano foi criar um método relatorio() na classe Agencia e ligar o comando RELATORIO no main. A saída tem 9 linhas: voos por estado, astronautas cadastrados/vivos/mortos, astronauta mais experiente e taxa de sucesso. Decisão importante: a experiência (número de voos lançados em que o astronauta estava a bordo) é calculada na hora, percorrendo os voos que não estão mais "planejados", e não guardada como contador no astronauta — assim não preciso mudar o arquivo de save da Missão 2 e o teste 05 ( relatório depois de carregar) passa sem mudar o formato. No empate de experiência, vence o cadastrado primeiro, usando comparação com >. A taxa de sucesso é a divisão inteira sucessos * 100 / finalizados. Só alterei src/main.cpp.

- Resultado de `testar.sh missao3` e de `testar.sh parte1`: sucesso
- Precisei refazer? O que mudou no pedido: precisei pedir para ele ignorar o CRLF, parece que esse negocio ta dando erro e ele fica em um loop por causa disso.

## Missão 4: livre

- O que escolhi e por quê: escolhi o limite de tripulação porque era oque parecia mais facil e rapido de fazer.
- O comando novo, a saída que eu esperava e o nome do meu arquivo de comandos
  (escritos antes de pedir): VerificarVoo, a saida que eu espero é que ele diga se esta lotado ou disponivel o voo, eu vou só implementar isso no main então nao vou criar um arquivo de comando novo.

- Primeira mensagem: preciso adicionar uma função nova ao meu codigo main, a acão é de limite de tripulação, um voo vai ter um certo numero limite de passageiros,o comando tera nome de VerificarVoo e essa função nova será aplicada no nosso main,junto dessa implementação eu preciso que vc faça um arquivo com os input de teste para esse programa e outro arquivo com os output esperados, me mostre o plano para executar essas ações.

- O que veio, comparado com o que eu esperava: eu dei uma missão bem subjetiva e o programa sabendo disso me fez algumas perguntas antes de fazer o projeto, em relação a execução do programa veio perfeito.

- `testar.sh parte1` continuou passando? sim
- Aceitei, ajustei ou descartei? Por quê: não precisei fazer nenhum ajuste extra.

## Fechamento

- O que a IA fez que eu não conseguiria fazer sozinho nesse prazo: bom eu passei 3 dias pra fazer só a parte 1 da atividade, o fato dela ter feito as 4 missoes em umas 4h é algo que eu nao consiguiria fazer sozinho, em relação a codigo eu acho que tudo que ela fez eu consiguiria fazer soque de um jeito diferente.

- Onde ela errou ou fez algo que eu não pedi: ela corrigiu textos do meu projeto principal, ela viu o erro, me alertou e eu concenti para que ela o corrigisse.
- O que eu faria diferente da próxima vez: começar vendo o plano é algo que eu vou aplicar em futuros projetos que eu va usar a ia, é realmente muito melhor ver oque ela quer fazer e alterar antes que ela faça, economiza tempo.
