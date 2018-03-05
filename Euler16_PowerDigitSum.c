#include <stdio.h>

long powTwo(int exp){

	long rezultat = 1;

	for(int i = 1; i <= exp; i++){
		rezultat *= 2;
	}

	return rezultat;
}

long sestevekStevk(long st, int koeficient){

	long vsota = 0;

	while(st >= 1){
		vsota += st % 10;
		st /= 10;
	}
	
	int del = vsota / 9;
	int ostanek = vsota - 9*del;

	if(koeficient == 0){
		//printf("%d\n", del);
		return vsota;
	}else{
		return ostanek;
	}

	
}

int main(){

	for(int i = 0; i < 50; i++){
		int koeficient = i / 6;
		//sestevekStevk(powTwo(i), 0);
		printf("Indeks: %d\tPotenca: %lu\tVsota stevk po %% 9: %lu\t Vsota stevk: %lu\n", i, powTwo(i), sestevekStevk(powTwo(i), 1), sestevekStevk(powTwo(i), 0));
		
	}

	return 0;
}