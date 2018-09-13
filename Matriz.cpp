#include <iostream>
#include <stdlib.h>
#include "Matriz.h"

using namespace std;

void matriz(int x,int y){
	int cont;
	float w, k;
	cont = 1;
	w = -0.7;
	k = -0.3;
	for(int i = 0; i < x; i++){
		for(int j = 0; j < y; j++){
			if(cont >= 2 && cont < 4){
				vertices[i][j] = w;
				vertices[i][j+1] = k;
				w = w + 0.3;
				k = k * 2;
				break;
			}else if(cont >= 5 && cont < 7){
				vertices[i][j] = -w ;
				vertices[i][j+1] = k;
				w = w + 0.3;
				k = k * 2;
				break;
			}else if( cont >= 8 && cont < 10){
				vertices[i][j] = w ;
				vertices[i][j+1] = -k;
				w = w + 0.3;
				k = k * 2;
				break;
			}else if( cont >= 11 && cont < 13){
				vertices[i][j] = -w ;
				vertices[i][j+1] = -k;
				w = w + 0.3;
				k = k * 2;
				break;
			}else if( cont >= 14 && cont < 16){
				vertices[i][j] = w ;
				vertices[i][j+1] = k;
				w = -w;
				break;
			}else if( cont >= 17 && cont < 19){
				vertices[i][j] = w ;
				vertices[i][j+1] = -k;
				w = -w;
				break;
				
			}else if( cont >= 20 && cont < 22){
				vertices[i][j] = w ;
				vertices[i][j+1] = k;
				k = -k;
				break;
				
			}else if( cont >= 23 ){
				vertices[i][j] = -w ;
				vertices[i][j+1] = k;
				k = -k;
				break;
			}else
				vertices[i][j] = 0.0;
		}
		
		cont++;
		if(cont == 4 || cont == 7 || cont == 10){
			w = -0.7;
			k = -0.3;
		}else if(cont == 13 || cont == 16 ){
			w = -0.35;
			k = -0.6;
		}else if(cont == 19 || cont == 22){
			w = -0.7;
			k = -0.25;
		}
	}
	
}
