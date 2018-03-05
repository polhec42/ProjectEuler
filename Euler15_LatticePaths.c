#include <stdio.h>


void print(int iMax, int jMax, long polje[iMax][jMax]){
	for(int i = 0; i < iMax; i++){
		for(int j = 0; j < jMax; j++){
			printf("%lu ", polje[i][j]);
		}
		printf("\n");
	}

}

int main(){
	/*

	Prvi pristop: Sicer je napačen, ampak kocko sem rezdelil na palčke ampak se stvar zakomplicira :D 

	Imamo polje 20x20, v resnici nas zanimajo stranice:
	21 stranic po 20 polj
	20 stranic po 21 polj
	
	Vrstni red:
	20
	21
	20
	21
	20
	...
	
	
	int polje1[21][20];
	int polje2[20][21];

	long polje1[21][20];
	long polje2[20][21];

	int zadnjaVrstica1 = -1;
	int zadnjaVrstica2 = -1;

	for(int i = 0; i < 41; i++){
		if(i % 2 == 0){
			zadnjaVrstica1++;
			for(int j = 0; j < 20; j++){
				//če je prva vrstica
				

				if(i == 0){
					polje1[i][j] = 1;
					
				//če je prvi stolpec
				}else if(j == 0){
					polje1[zadnjaVrstica1][j] = 1;
				}else{
					//printf("%d\n", polje1[i][j]);
					polje1[zadnjaVrstica1][j] = polje1[zadnjaVrstica1][j-1] + polje2[zadnjaVrstica2][j];
				}

			}
			
			/*
			print(3, 2, polje1);
			printf("\n");

		}else{
			zadnjaVrstica2++;
			for(int j = 0; j < 21; j++){
				//če je prvi stolpec
				

				if(j == 0){
					polje2[zadnjaVrstica2][j] = 1;
				}else{
					polje2[zadnjaVrstica2][j] = polje2[zadnjaVrstica2][j-1] + polje1[zadnjaVrstica1][j-1];
				}

			}
		}
	}
	
	print(3, 2, polje1);
	print(2, 3, polje2);
	
	print(21, 20, polje1);
	print(20, 21, polje2);
	printf("%lu \n", polje1[20][18] + polje2[19][20]);
	
	int polje1[21][20];
	int polje2[20][21];
	*/
	/*
	Eleganten način:
	Podobno kot naloga Mravlja, samo da dodam ša eno vrstico in en stolpec, 
	saj tokrat gledam vozlišča in ne kvadratke
	*/
	long polje[21][21];

	for(int i = 0; i < 21; i++){
		for(int j = 0; j < 21; j++){
			if(i == 0){
				polje[i][j] = 1;
			}else if(j == 0){
				polje[i][j] = 1;
			}else{
				polje[i][j] = polje[i][j-1] + polje[i-1][j];
			}
		}
	}	

	printf("%lu\n", polje[20][20]);
	
	return 0;

}
