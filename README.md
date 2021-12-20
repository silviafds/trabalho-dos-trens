
# Atividade prática 02:  Malha ferroviária  
A presente atividade consiste no desenvolvimento de uma malha ferroviária que comporta 5 trens, todos circulando no sentido horário. Cada trem deve circular em sua malha sem colidir com os demais trens. Além disso, se um trem pode se mover sem causar colisão ou deadlock, ele deve se mover.
## 

# Solução
Para a resolução do problema proposto, tentamos coordenar a entrada dos trens nas regiões críticas utilizando mutexes da classe QMutex do próprio QTCreator. Criando condições baseadas nas posições de cada trem, as quais julgamos em que seriam necessárias uma realização do pedido de alocação ou de liberação de uma região crítica.
## 

# Dificuldades
Não conseguimos desenvolver uma solução para resolver a colisão do trem 2 com o trem 4 no trilho 3.
##

## Atividade desenvolvida por:
- Raíssa Santos
- Silvia Goes Fernandes
