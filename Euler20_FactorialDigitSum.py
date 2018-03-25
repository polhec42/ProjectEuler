def factorial(n):
	vsota = 1
	for i in range(1, n+1):
		vsota *= i

	return vsota;

rezultat = 0

tabela = list(str(factorial(100)))

for i in tabela:
	rezultat += int(i)

print(rezultat);