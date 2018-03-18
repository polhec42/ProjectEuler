import time



def fib(n):
	a = 1
	b = 1
	
	index = 2
	tp = 0

	while(index < n):
		tp = b
		b = a + b
		a = tp
		index+=1

	return b

start_time = time.time()
for i in range(100, 20000):
	c = fib(i)
	if(len(list(str(c))) >= 1000):
		print(i)
		break

print(time.time() - start_time)
