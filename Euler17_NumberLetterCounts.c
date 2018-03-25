#include <stdio.h>

int main(){

	//0-9
	int tabela10[10] = {
		0, 3, 3, 5, 4, 4, 3, 5, 5, 4
	};
	//11-19 -> ničla označuje 10, ki jo ne uporabljam tukaj, ampak v tabeli tabela100
	int tabela19[10] = {
		0, 6, 6, 8, 8, 7, 7, 9, 8, 8
	};
	//20-90 po 10
	int tabela100[10] = {
		0, 3, 6, 6, 5, 5, 5, 7, 6, 6
	};
	//vsota vseh števil
	int sum = 0;

	for(int i = 1; i <= 1000; i++){
		if(i < 10){
			sum += tabela10[i];
		}else if(i < 20 && i > 11){
			sum += tabela19[(i % 10)];
		}else if(i <= 99){
			int enice = i % 10;
			int desetice = i / 10;

			sum += tabela10[enice] + tabela100[desetice];
			/*
			if(i == 42){
				printf("%d\n", tabela10[enice-1] + tabela100[desetice]);
			}*/
		}else if(i <= 999){
			int stotice = i / 100;
			int desetice = i / 10 - stotice*10;
			int enice = i % 10;
			//Format 100, 200, 300, ...
			if(desetice == 0 && enice == 0){
				sum += tabela10[stotice] + 7;
			}
			else if(desetice < 2){
				//Primer 102
				if(desetice == 0){
					sum += tabela10[stotice] + tabela10[enice] + 3+7; //and hundred
				//Primer 112	
				}else if(desetice == 1 && enice != 0){
					sum += tabela10[stotice] + tabela19[enice] + 3+7;
				//Primer 110, 120, 230	
				}else{
					sum += tabela10[stotice] + 3+7+tabela100[desetice]; //110 hundred
				}
			//Vsi ostali primeri	
			}else{
				sum += tabela10[stotice] + tabela100[desetice] + tabela10[enice] + 10;
			}
		//Tisoč
		}else{
			sum += 11; //thousand
		}
	}

	printf("%d\n", sum);
	

	return 0;

}