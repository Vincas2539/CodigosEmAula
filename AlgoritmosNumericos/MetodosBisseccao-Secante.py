import matplotlib.pyplot as plt
import numpy as np

# No enunciado é pedido para resolvermos a raiz da função, mas lendo o problema em si, isso não faz sentido, então resolvemo apenas resolver o problema

# Sla vamo tentar plotar o grafico
def printaGrafico():
  T = np.arange(0, 10, 0.1)
  s = 1-(1+T+((T**2)/2))*np.exp(-T)

  plt.axhline(y=0.1, xmin=0.1, xmax=0.2) # Ponto 1
  plt.axhline(y=0.9, xmin=0.48, xmax=0.58) # Ponto 2

  plt.xlabel('Tempo')
  plt.ylabel('g(T)')

  plt.grid()
  plt.plot(T, s)
  plt.show()

def g(x):
  g = (1-(1+x+((x**2)/2))*np.exp(-x))
  return g

def bisseccao(y):
  E = 10 **-5                        # Precisão de erro 
  e = 1                              # Variavel para calculo de erro  
  a, b, aux = 0, 0, 0        
  x=0                                # seta o x para '0' para achar o g(x) mais proximo a y 
  while(g(x)<y):                     # loop para achar o x onde g(x) seja mais proximo possivel de y
    a = x                            # guarda o valor mais proximo de x para que g(x) seja menor que y 
    x += 1                           # aumenta x em 1 para nao entrar em loop infinito
  x=100                              # seta o x para '100' para achar o g(x) mais proximo a y
  while(g(x)>y):                     # loop para achar o x onde g(x) seja mais proximo possivel de y
    b = x                            # guarda o valor mais proximo de x para que g(x) seja maior que y  
    x -= 1                           # diminui x em 1 para nao entrar em loop infinito
  while(abs(e)>E):                   # enquanto o modulo de erro for menor que a precisao de erro desejada
    aux = (a+b)/2                    # divide os valores de x mais proximos a x por 2 para realizar a media 
    #print(f'a = {a}')
    #print(f'b = {b}')
    if (g(aux) < y):                 # faz a troca de a ou b pelo auxiliar(media)
      a = aux                        # troca o valor de a pelo do auxiliar 
    else:
      b = aux                        # troca o valor de b pelo do auxiliar 

    
    e = b-a
    #print(f'Erro: {abs(e)}')
    
  return aux                         # retorna o valor de x que eh a resolucao


def secante(y):
  E = 10 **-5
  #E1 = 10 **-5                      # Precisão de erro 
  #E2 = 10 **-5
  #saida = False
  e = 1                              # Variavel para calculo de erro  
  a, b = 0, 0
  xant, xpos = 0, 0
  x=0                                # seta o x para '0' para achar o g(x) mais proximo a y 
  while((g(x)-y)<0):                 # loop para achar o x onde g(x) seja mais proximo possivel de y
    a = x                            # guarda o valor mais proximo de x para que g(x) seja menor que y 
    x += 1                           # aumenta x em 1 para nao entrar em loop infinito
  x=100                              # seta o x para '100' para achar o g(x) mais proximo a y
  while((g(x)-y)>0):                 # loop para achar o x onde g(x) seja mais proximo possivel de y
    b = x                            # guarda o valor mais proximo de x para que g(x) seja maior que y  
    x -= 1                           # diminui x em 1 para nao entrar em loop infinito
    
  while(abs(e)>E):   #not saida# enquanto o modulo de erro for menor que a precisao de erro desejada
    xant = a
    xpos = b
    sec = (xant*(g(xpos)-y)-xpos*(g(xant)-y))/((g(xpos)-y)-(g(xant)-y))      # formula alterada para calculo com g(T) = 0
    if ((g(sec)-y) < 0):                                                     
      a = sec
      xant = b
      xpos = a
    else:
      b = sec
      xant = a
      xpos = b

    e = g(xpos)-y                     # calculo do erro com x    
    
  return xpos                         # retorna o x




op = 12
while(op != 0):
  op = int(input('Metodos:\n[1] Bisseccao\n[2] Secante\n[3] Mostra o grafico\n\n[0] Sair\n\nEscolha o metodo que deseja resolver o problema: '))
  if op == 1:                        # escolhe a opcao '1'
    T1 = bisseccao(0.1)              # chama a funcao para y igual a 0.1   
    print(f'T1: {T1}')               # printa o valor
    T2 = bisseccao(0.9)              # chama a funcao para y igual a 0.9
     
    print(f'T2: {T2}')               # printa o valor
    print(f'Tempo de subida = {T2 - T1}\n')    # printa T2 - T1
  elif op == 2:                      # escolhe a opcao '2'
    T1 = secante(0.1)                # chama a funcao para y igual a 0.9
    print(f'T1: {T1}')               # printa o valor
    T2 = secante(0.9)                # chama a funcao para y igual a 0.9
    
    print(f'T2: {T2}')               # printa o valor
    print(f'Tempo de subida = {T2 - T1}\n')    # printa T2 - T1

  elif op == 3:
    printaGrafico()
  else:
    print("Opcao invalida!\n")