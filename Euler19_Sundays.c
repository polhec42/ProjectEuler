#include <stdio.h>
#include <stdbool.h>


bool jePrestopno(int leto){
	if(leto % 4 == 0){
		if(leto % 100 == 0 && leto % 400 != 0){
			return false;
		}else if(leto % 400 == 0){
			return true;
		}
		return true;
	}
	return false;
}

int steviloNedelj(){

	int stDni[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int teden = 7;
	int trPozicija = 1;

	int stNedelj = 0;

	for(int trLeto = 1901; trLeto <= 2000; trLeto++){
		//Poskrbimo, da je število dni v mesecu v skladju z prestopnimi leti	
		if(jePrestopno(trLeto)){
			stDni[1] = 29;
		}else{
			stDni[1] = 28;
		}

		for(int trMesec = 0; trMesec < 12; trMesec++){

			if(trPozicija == 6){
				stNedelj++;
			}

			trPozicija = (stDni[trMesec] + trPozicija) % teden;

		}
	}

	return stNedelj;

}



int main(){
	

	/*
	for(int i = 2000; i < 2018; i++){
		printf("Leto %d je prestopno? %d\n", i, jePrestopno(i));	
	}
	*/

	printf("Med letom 1. 1. 1901 in 31. 12. 2000 je bilo %d nedelj 1. v mesecu\n", steviloNedelj());

	return 0;


	

}