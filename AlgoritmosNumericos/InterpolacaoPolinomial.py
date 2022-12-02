def pol_interp(xi, fxi, x):
  n = len(xi)
  total = 0
  l = []
  print(f'Polinomio de grau {n-1}')
  for i in range(n):
    dom = 1
    den = 1
    for j in range(n):
      if i != j:
        dom *= x - xi[j]
        den *= xi[i] - xi[j]
        
    l.append(dom/den)
    total += l[i]*fxi[i]

  print()
  return total



xi = [55, 70, 85, 100, 115, 130]
fxi = [14.08, 13.56, 13.28, 12.27, 11.30, 10.40]

x = int(input("Digite o valor que deseja verificar: "))

print(pol_interp(xi, fxi, x))
