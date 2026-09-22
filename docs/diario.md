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
- O que mudou no código, e se os seis testes continuaram passando:
- O que entendi que não sabia antes:

## Missão 1: LISTAR_ASTRONAUTAS e HISTORICO

- Primeira mensagem (o pedido do plano):
- O plano que a IA apresentou, resumido:
- Mudei algo no plano antes de liberar?
- Resultado de `testar.sh missao1` e de `testar.sh parte1`:
- Precisei refazer? O que mudou no pedido:

## Missão 2: SALVAR e CARREGAR

- Primeira mensagem:
- O plano, resumido:
- O formato do arquivo (cole cinco linhas do `dados_teste.txt`):
- Resultado de `testar.sh missao2` e de `testar.sh parte1`:
- Precisei refazer? O que mudou no pedido:

## Missão 3: RELATORIO

- Primeira mensagem:
- O plano, resumido:
- Resultado de `testar.sh missao3` e de `testar.sh parte1`:
- Precisei refazer? O que mudou no pedido:

## Missão 4: livre

- O que escolhi e por quê:
- O comando novo, a saída que eu esperava e o nome do meu arquivo de comandos
  (escritos antes de pedir):
- Primeira mensagem:
- O que veio, comparado com o que eu esperava:
- `testar.sh parte1` continuou passando?
- Aceitei, ajustei ou descartei? Por quê:

## Fechamento

- O que a IA fez que eu não conseguiria fazer sozinho nesse prazo:
- Onde ela errou ou fez algo que eu não pedi:
- O que eu faria diferente da próxima vez:
