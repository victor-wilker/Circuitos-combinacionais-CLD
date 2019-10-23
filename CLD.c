/*
	Nome:Victor Wilker
	Circuitos Combinacionais
	29/04/2018
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
//porta E
int and(int A,int B){
	int saida;
	if (A & B)
	{
		saida=1;
	}else{
		saida=0;
	}
	return saida;
}
//porta E negada
int nand(int A,int B){
	int saida;
	if (A==1 && B==1)
	{
		saida=0;
	}else{
		saida=1;
	}
	return saida;
}
//porta OU 
int or(int A,int B){
	int saida;
	if (A || B)
	{
		saida=1;
	}else{
		saida=0;
	}
	
	return saida;
}
// //porta ou negada
int nor(int A,int B){
	int saida;
	if (A || B)
	{
		saida=0;
	}else{
		saida=1;
	}
	
	return saida;
}
//porta ou exclusivo
int xor(int A,int B){
	int saida;
	if (A ^ B)
	{
		saida=1;
	}else{
		saida=0;
	}
	return saida;
}
// // porta ou exclusivo negada
int xnor(int A,int B){
	int x;
	if (A ^ B)
	{
		x=0;
	}else{
		x=1;
	}	
	return x;
}
int not(int A){
	int saida;
	if (A == 1)
	{
		saida=0;
	}else{
		saida=1;
	}

	return saida;
}

// função main//////////////////////////////////////////////////////////////////
int main(){

	int i,j=0;
	FILE *file;	
	char circuit[10000];// vetor para ler as frases
	
	//leitura do aquivo de texto

	file = fopen("teste.txt", "a+");//leitura e escrita	
	if(file == NULL){
			printf("arquivo não encontrado\n");
			system("pause");
			exit(0);			
	}	
	
	while( fgets(circuit,10000, file) != NULL ){// ler o que está no txt	
		
		if(circuit[0] == '%'){
			continue;
		}else{
			
			if (circuit[0] >= '0' && circuit[0] <= '9')
			{
				int portas,ent , port;
				char entradas;
				int s1[32],s2[32],s3[32],s4[32],s5[32],s6[32],s7[32];
				int entrada,E,A,B,C,D,saida,z=1,w=0;
				int A1=1,A2=0,B1=1,B2=0,C1=1,C2=0,D1=1,D2=0,E1=1,E2=0;
				
				//variavel para a tabela vdd
			//leitura do txt linha a linha para identificar as portas
				char saidas1[5],port_ent[5],ent_1[2],ent_2[2],fixa1[2],fixa0[2],fixa3[2],fixa4[2];
				char exp[100];
				
				entradas = circuit[0];	
				portas = circuit[3];
				//transformação de char para inteiros
				char x[2];
				x[0] = entradas;
				x[1] = '\0';
				int k = atoi(x);

				char xy[2];
				xy[0] = portas;
				xy[1] = '\0';
				int ky = atoi(xy);

				k=pow(2,k);
				
				//prende as entradas em 0 ou 1;
					fscanf(file,"%s %s %s %s", fixa1, fixa0,fixa3, fixa4);
	      			printf("%s %s %s %s\n", fixa1, fixa0,fixa3, fixa4);
	      			
	      			if (strcmp(fixa1, "Ap")==0 && strcmp(fixa0, "1")==0)
	      			{
	      				A2=1;
	      			}else if(strcmp(fixa1, "Ap")==0 && strcmp(fixa0, "0")==0)
	      			{
	      				A1=0;
	      			}else if(strcmp(fixa1, "Bp")==0 && strcmp(fixa0, "1")==0)
	      			{
	      				B2=1;
	      			}else if(strcmp(fixa1, "Bp")==0 && strcmp(fixa0, "0")==0)
	      			{
	      				B1=0;
	      			}else if(strcmp(fixa1, "Cp")==0 && strcmp(fixa0, "1")==0)
	      			{
	      				C2=1;
	      			}else if(strcmp(fixa1, "Cp")==0 && strcmp(fixa0, "0")==0)
	      			{
	      				C1=0;
	      			}else if(strcmp(fixa1, "Dp")==0 && strcmp(fixa0, "1")==0)
	      			{
	      				D2=1;
	      			}else if(strcmp(fixa1, "Dp")==0 && strcmp(fixa0, "0")==0)
	      			{
	      				D1=0;
	      			}else if(strcmp(fixa1, "Ep")==0 && strcmp(fixa0, "1")==0)
	      			{
	      				E2=1;
	      			}else if(strcmp(fixa1, "Ep")==0 && strcmp(fixa0, "0")==0)
	      			{
	      				E1=0;
	      			}
	      			////////////// segunda parte para prender cada resultado///
	      			if (strcmp(fixa3, "Ap")==0 && strcmp(fixa4, "1")==0)
	      			{
	      				A2=1;
	      			}else if(strcmp(fixa3, "Ap")==0 && strcmp(fixa4, "0")==0)
	      			{
	      				A1=0;
	      			}else if(strcmp(fixa3, "Bp")==0 && strcmp(fixa4, "1")==0)
	      			{
	      				B2=1;
	      			}else if(strcmp(fixa3, "Bp")==0 && strcmp(fixa4, "0")==0)
	      			{
	      				B1=0;
	      			}else if(strcmp(fixa3, "Cp")==0 && strcmp(fixa4, "1")==0)
	      			{
	      				C2=1;
	      			}else if(strcmp(fixa3, "Cp")==0 && strcmp(fixa4, "0")==0)
	      			{
	      				C1=0;
	      			}else if(strcmp(fixa3, "Dp")==0 && strcmp(fixa4, "1")==0)
	      			{
	      				D2=1;
	      			}else if(strcmp(fixa3, "Dp")==0 && strcmp(fixa4, "0")==0)
	      			{
	      				D1=0;
	      			}else if(strcmp(fixa3, "Ep")==0 && strcmp(fixa4, "1")==0)
	      			{
	      				E2=1;
	      			}else if(strcmp(fixa3, "Ep")==0 && strcmp(fixa4, "0")==0)
	      			{
	      				E1=0;
	      			}


	
	      		for (int i = 0; i < ky; ++i){
	      						

							fscanf(file,"%s %s %s %s", saidas1, port_ent, ent_1, ent_2);
	      					printf("%s %s %s %s\n", saidas1,port_ent, ent_1, ent_2);
	      					if (strcmp(saidas1, "S1") == 0) 
							{
 								for(entrada = 0; entrada < k ; entrada++) {		     		
						      			A = (entrada & 1)?A1:A2; 
										B = (entrada & 2)?B1:B2;  
										C = (entrada & 4)?C1:C2;  
										D = (entrada & 8)?D1:D2;
										E = (entrada & 16)?E1:E2;
								      	if (strcmp(port_ent, "OR") == 0) 
										{
								      	 	s1[entrada]= or(A,B); 
								     	}else if (strcmp(port_ent, "AND") == 0)
										{
								      		s1[entrada]= and(A,B);		     // saída
							     		}else if (strcmp(port_ent, "NOR") == 0) 
										{
								      		 s1[entrada]= nor(A,B);			      		 
										} 
										else if (strcmp(port_ent, "NAND") == 0)
										{
								      			s1[entrada]= nand(A,B);
										}if (strcmp(port_ent, "XOR") == 0) 
										{							
								      		 s1[entrada]= xor(A,B);   		  						 	
										} 
										else if (strcmp(port_ent, "XNOR") == 0)
										{
								      		 s1[entrada]= xnor(A,B);		 
										}if (strcmp(port_ent, "NOT") == 0)
										{
										     s1[entrada]= not(A);	 
										}

										//prende s1
										if (strcmp(fixa1, "S1")==0 && strcmp(fixa0, "0")==0)
										{
											s1[entrada]=0;
										}else if (strcmp(fixa1, "S1")==0 && strcmp(fixa0, "1")==0)
										{
											s1[entrada]=1;
										}	
										//prende s1
										if (strcmp(fixa3, "S1")==0 && strcmp(fixa4, "0")==0)
										{
											s1[entrada]=0;
										}else if (strcmp(fixa3, "S1")==0 && strcmp(fixa4, "1")==0)
										{
											s1[entrada]=1;
										}	
						      	}	 						 
							} 

							///////////////////////////saida S2/////////////////////////////////
							if (strcmp(saidas1, "S2") == 0) 
							{
				
								for (entrada = 0; entrada < k; entrada++)
								{		     		
						      			A = (entrada & 1)?A1:A2; 
										B = (entrada & 2)?B1:B2;  
										C = (entrada & 4)?C1:C2;  
										D = (entrada & 8)?D1:D2;
										E = (entrada & 16)?E1:E2;
						      			if (strcmp(port_ent, "OR") == 0) {
						      		
							      			if (strcmp(ent_1, "A")==0 && strcmp(ent_2, "B")==0)
							      			{
							      				s2[entrada]= or(A,B);
							      			}else if(strcmp(ent_1, "A")==0 && strcmp(ent_2, "C")==0){
							      				s2[entrada]= or(A,C);
							      			}else if(strcmp(ent_1, "A")==0 && strcmp(ent_2, "D")==0){
							      				s2[entrada]= or(A,D);
							      			}else if (strcmp(ent_1, "A")==0 && strcmp(ent_2, "E")==0)
							      			{
							      				s2[entrada]= or(A,E);
							      			}else if(strcmp(ent_1, "B")==0 && strcmp(ent_2, "C")==0){
							      				s2[entrada]= or(B,C);
							      			}else if(strcmp(ent_1, "B")==0 && strcmp(ent_2, "D")==0){
							      				s2[entrada]= or(B,D);
							      			}else if (strcmp(ent_1, "B")==0 && strcmp(ent_2, "E")==0)
							      			{
							      				s2[entrada]= or(B,E);
							      			}else if(strcmp(ent_1, "C")==0 && strcmp(ent_2, "D")==0){
							      				s2[entrada]= or(C,D);
							      			}else if(strcmp(ent_1, "C")==0 && strcmp(ent_2, "E")==0){
							      				s2[entrada]= or(C,E);
							      			}else if(strcmp(ent_1, "D")==0 && strcmp(ent_2, "E")==0){
							      				s2[entrada]= or(D,E);
							      			}

							      			//para entradas com S1
							      			if (strcmp(ent_1, "S1")==0 && strcmp(ent_2, "A")==0)
							      			{
							      				s2[entrada]= or(s1[entrada],A);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "B")==0){
							      				s2[entrada]= or(s1[entrada],B);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "C")==0){
							      				s2[entrada]= or(s1[entrada],C);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "D")==0){
							      				s2[entrada]= or(s1[entrada],D);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "E")==0){
							      				s2[entrada]= or(s1[entrada],E);
							      			}
		
							      			      // saída
							     	
										} 
										else if (strcmp(port_ent, "AND") == 0)
										{
								      		if (strcmp(ent_1, "A")==0 && strcmp(ent_2, "B")==0)
							      			{
							      				s2[entrada]= and(A,B);
							      			}else if(strcmp(ent_1, "A")==0 && strcmp(ent_2, "C")==0){
							      				s2[entrada]= and(A,C);
							      			}else if(strcmp(ent_1, "A")==0 && strcmp(ent_2, "D")==0){
							      				s2[entrada]= and(A,D);
							      			}else if (strcmp(ent_1, "A")==0 && strcmp(ent_2, "E")==0)
							      			{
							      				s2[entrada]= and(A,E);
							      			}else if(strcmp(ent_1, "B")==0 && strcmp(ent_2, "C")==0){
							      				s2[entrada]= and(B,C);
							      			}else if(strcmp(ent_1, "B")==0 && strcmp(ent_2, "D")==0){
							      				s2[entrada]= and(B,D);
							      			}else if (strcmp(ent_1, "B")==0 && strcmp(ent_2, "E")==0)
							      			{
							      				s2[entrada]= and(B,E);
							      			}else if(strcmp(ent_1, "C")==0 && strcmp(ent_2, "D")==0){
							      				s2[entrada]= and(C,D);
							      			}else if(strcmp(ent_1, "C")==0 && strcmp(ent_2, "E")==0){
							      				s2[entrada]= and(C,E);
							      			}else if(strcmp(ent_1, "D")==0 && strcmp(ent_2, "E")==0){
							      				s2[entrada]= and(D,E);
							      			}

							      			//para entradas com S1
							      			if (strcmp(ent_1, "S1")==0 && strcmp(ent_2, "A")==0)
							      			{
							      				s2[entrada]= and(s1[entrada],A);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "B")==0){
							      				s2[entrada]= and(s1[entrada],B);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "C")==0){
							      				s2[entrada]= and(s1[entrada],C);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "D")==0){
							      				s2[entrada]= and(s1[entrada],D);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "E")==0){
							      				s2[entrada]= and(s1[entrada],E);
							      			}
								      		
										 
										}if (strcmp(port_ent, "NOR") == 0) 
										{
								      			if (strcmp(ent_1, "A")==0 && strcmp(ent_2, "B")==0)
							      			{
							      				s2[entrada]= nor(A,B);
							      			}else if(strcmp(ent_1, "A")==0 && strcmp(ent_2, "C")==0){
							      				s2[entrada]= nor(A,C);
							      			}else if(strcmp(ent_1, "A")==0 && strcmp(ent_2, "D")==0){
							      				s2[entrada]= nor(A,D);
							      			}else if (strcmp(ent_1, "A")==0 && strcmp(ent_2, "E")==0)
							      			{
							      				s2[entrada]= nor(A,E);
							      			}else if(strcmp(ent_1, "B")==0 && strcmp(ent_2, "C")==0){
							      				s2[entrada]= nor(B,C);
							      			}else if(strcmp(ent_1, "B")==0 && strcmp(ent_2, "D")==0){
							      				s2[entrada]= nor(B,D);
							      			}else if (strcmp(ent_1, "B")==0 && strcmp(ent_2, "E")==0)
							      			{
							      				s2[entrada]= nor(B,E);
							      			}else if(strcmp(ent_1, "C")==0 && strcmp(ent_2, "D")==0){
							      				s2[entrada]= nor(C,D);
							      			}else if(strcmp(ent_1, "C")==0 && strcmp(ent_2, "E")==0){
							      				s2[entrada]= nor(C,E);
							      			}else if(strcmp(ent_1, "D")==0 && strcmp(ent_2, "E")==0){
							      				s2[entrada]= nor(D,E);
							      			}

							      			//para entradas com S1
							      			if (strcmp(ent_1, "S1")==0 && strcmp(ent_2, "A")==0)
							      			{
							      				s2[entrada]= nor(s1[entrada],A);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "B")==0){
							      				s2[entrada]= nor(s1[entrada],B);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "C")==0){
							      				s2[entrada]= nor(s1[entrada],C);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "D")==0){
							      				s2[entrada]= nor(s1[entrada],D);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "E")==0){
							      				s2[entrada]= nor(s1[entrada],E);
							      			}
								      		
										} 
										else if (strcmp(port_ent, "NAND") == 0)
										{if (strcmp(ent_1, "A")==0 && strcmp(ent_2, "B")==0)
							      			{
							      				s2[entrada]= nand(A,B);
							      			}else if(strcmp(ent_1, "A")==0 && strcmp(ent_2, "C")==0){
							      				s2[entrada]= nand(A,C);
							      			}else if(strcmp(ent_1, "A")==0 && strcmp(ent_2, "D")==0){
							      				s2[entrada]= nand(A,D);
							      			}else if (strcmp(ent_1, "A")==0 && strcmp(ent_2, "E")==0)
							      			{
							      				s2[entrada]= nand(A,E);
							      			}else if(strcmp(ent_1, "B")==0 && strcmp(ent_2, "C")==0){
							      				s2[entrada]= nand(B,C);
							      			}else if(strcmp(ent_1, "B")==0 && strcmp(ent_2, "D")==0){
							      				s2[entrada]= nand(B,D);
							      			}else if (strcmp(ent_1, "B")==0 && strcmp(ent_2, "E")==0)
							      			{
							      				s2[entrada]= nand(B,E);
							      			}else if(strcmp(ent_1, "C")==0 && strcmp(ent_2, "D")==0){
							      				s2[entrada]= nand(C,D);
							      			}else if(strcmp(ent_1, "C")==0 && strcmp(ent_2, "E")==0){
							      				s2[entrada]= nand(C,E);
							      			}else if(strcmp(ent_1, "D")==0 && strcmp(ent_2, "E")==0){
							      				s2[entrada]= nand(D,E);
							      			}

							      			//para entradas com S1
							      			if (strcmp(ent_1, "S1")==0 && strcmp(ent_2, "A")==0)
							      			{
							      				s2[entrada]= nand(s1[entrada],A);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "B")==0){
							      				s2[entrada]= nand(s1[entrada],B);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "C")==0){
							      				s2[entrada]= nand(s1[entrada],C);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "D")==0){
							      				s2[entrada]= nand(s1[entrada],D);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "E")==0){
							      				s2[entrada]= nand(s1[entrada],E);
							      			}
								      		 
										}if (strcmp(port_ent, "XOR") == 0) 
										{
								      			if (strcmp(ent_1, "A")==0 && strcmp(ent_2, "B")==0)
							      			{
							      				s2[entrada]= xor(A,B);
							      			}else if(strcmp(ent_1, "A")==0 && strcmp(ent_2, "C")==0){
							      				s2[entrada]= xor(A,C);
							      			}else if(strcmp(ent_1, "A")==0 && strcmp(ent_2, "D")==0){
							      				s2[entrada]= xor(A,D);
							      			}else if (strcmp(ent_1, "A")==0 && strcmp(ent_2, "E")==0)
							      			{
							      				s2[entrada]= xor(A,E);
							      			}else if(strcmp(ent_1, "B")==0 && strcmp(ent_2, "C")==0){
							      				s2[entrada]= xor(B,C);
							      			}else if(strcmp(ent_1, "B")==0 && strcmp(ent_2, "D")==0){
							      				s2[entrada]= xor(B,D);
							      			}else if (strcmp(ent_1, "B")==0 && strcmp(ent_2, "E")==0)
							      			{
							      				s2[entrada]= xor(B,E);
							      			}else if(strcmp(ent_1, "C")==0 && strcmp(ent_2, "D")==0){
							      				s2[entrada]= xor(C,D);
							      			}else if(strcmp(ent_1, "C")==0 && strcmp(ent_2, "E")==0){
							      				s2[entrada]= xor(C,E);
							      			}else if(strcmp(ent_1, "D")==0 && strcmp(ent_2, "E")==0){
							      				s2[entrada]= xor(D,E);
							      			}

							      			//para entradas com S1
							      			if (strcmp(ent_1, "S1")==0 && strcmp(ent_2, "A")==0)
							      			{
							      				s2[entrada]= xor(s1[entrada],A);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "B")==0){
							      				s2[entrada]= xor(s1[entrada],B);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "C")==0){
							      				s2[entrada]= xor(s1[entrada],C);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "D")==0){
							      				s2[entrada]= xor(s1[entrada],D);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "E")==0){
							      				s2[entrada]= xor(s1[entrada],E);
							      			}
								      		
										} 
										else if (strcmp(port_ent, "XNOR") == 0)
										{
								      		if (strcmp(ent_1, "A")==0 && strcmp(ent_2, "B")==0)
							      			{
							      				s2[entrada]= xnor(A,B);
							      			}else if(strcmp(ent_1, "A")==0 && strcmp(ent_2, "C")==0){
							      				s2[entrada]= xnor(A,C);
							      			}else if(strcmp(ent_1, "A")==0 && strcmp(ent_2, "D")==0){
							      				s2[entrada]= xnor(A,D);
							      			}else if (strcmp(ent_1, "A")==0 && strcmp(ent_2, "E")==0)
							      			{
							      				s2[entrada]= xnor(A,E);
							      			}else if(strcmp(ent_1, "B")==0 && strcmp(ent_2, "C")==0){
							      				s2[entrada]= xnor(B,C);
							      			}else if(strcmp(ent_1, "B")==0 && strcmp(ent_2, "D")==0){
							      				s2[entrada]= xnor(B,D);
							      			}else if (strcmp(ent_1, "B")==0 && strcmp(ent_2, "E")==0)
							      			{
							      				s2[entrada]= xnor(B,E);
							      			}else if(strcmp(ent_1, "C")==0 && strcmp(ent_2, "D")==0){
							      				s2[entrada]= xnor(C,D);
							      			}else if(strcmp(ent_1, "C")==0 && strcmp(ent_2, "E")==0){
							      				s2[entrada]= xnor(C,E);
							      			}else if(strcmp(ent_1, "D")==0 && strcmp(ent_2, "E")==0){
							      				s2[entrada]= xnor(D,E);
							      			}
							      			//para entradas com S1
							      			if (strcmp(ent_1, "S1")==0 && strcmp(ent_2, "A")==0)
							      			{
							      				s2[entrada]= xnor(s1[entrada],A);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "B")==0){
							      				s2[entrada]= xnor(s1[entrada],B);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "C")==0){
							      				s2[entrada]= xnor(s1[entrada],C);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "D")==0){
							      				s2[entrada]= xnor(s1[entrada],D);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "E")==0){
							      				s2[entrada]= xnor(s1[entrada],E);
							      			}
								      		
										}if (strcmp(port_ent, "NOT") == 0)
										{
								      		if (strcmp(ent_1, "A")==0 )
							      			{
							      				s2[entrada]= not(A);
							      			}else if(strcmp(ent_1, "B")==0){
							      				s2[entrada]= not(B);
							      			}else if(strcmp(ent_1, "C")==0){
							      				s2[entrada]= not(C);
							      			}else if (strcmp(ent_1, "D")==0 ){
							      				s2[entrada]= not(D);
							      			}else if(strcmp(ent_1, "E")==0 ){
							      				s2[entrada]= not(E);
							      			}
							      			//para entradas com S1
							      			if (strcmp(ent_1, "S1")==0)
							      			{
							      				s2[entrada]= not(s1[entrada]);
							      			}
								      		
										}
										//prende s2
										if (strcmp(fixa1, "S2")==0 && strcmp(fixa0, "0")==0)
										{
											s2[entrada]=0;
										}else if (strcmp(fixa1, "S2")==0 && strcmp(fixa0, "1")==0)
										{
											s2[entrada]=1;
										}
										if (strcmp(fixa3, "S2")==0 && strcmp(fixa4, "0")==0)
										{
											s2[entrada]=0;
										}else if (strcmp(fixa3, "S2")==0 && strcmp(fixa4, "1")==0)
										{
											s2[entrada]=1;
										}		
								}
				 						 
							} 
							//ler porta s4
							if (strcmp(saidas1, "S3") == 0) 
							{
				
								for(entrada = 0; entrada < k ; entrada++) {	
										A = (entrada & 1)?A1:A2; 
										B = (entrada & 2)?B1:B2;  
										C = (entrada & 4)?C1:C2;  
										D = (entrada & 8)?D1:D2;
										E = (entrada & 16)?E1:E2;
							      	if (strcmp(port_ent, "OR") == 0) {	
										if (strcmp(ent_1, "A")==0 && strcmp(ent_2, "B")==0)
							      			{
							      				s3[entrada]= or(A,B);
							      			}else if(strcmp(ent_1, "A")==0 && strcmp(ent_2, "C")==0){
							      				s3[entrada]= or(A,C);
							      			}else if(strcmp(ent_1, "A")==0 && strcmp(ent_2, "D")==0){
							      				s3[entrada]= or(A,D);
							      			}else if (strcmp(ent_1, "A")==0 && strcmp(ent_2, "E")==0)
							      			{
							      				s3[entrada]= or(A,E);
							      			}else if(strcmp(ent_1, "B")==0 && strcmp(ent_2, "C")==0){
							      				s3[entrada]= or(B,C);
							      			}else if(strcmp(ent_1, "B")==0 && strcmp(ent_2, "D")==0){
							      				s3[entrada]= or(B,D);
							      			}else if (strcmp(ent_1, "B")==0 && strcmp(ent_2, "E")==0)
							      			{
							      				s3[entrada]= or(B,E);
							      			}else if(strcmp(ent_1, "C")==0 && strcmp(ent_2, "D")==0){
							      				s3[entrada]= or(C,D);
							      			}else if(strcmp(ent_1, "C")==0 && strcmp(ent_2, "E")==0){
							      				s3[entrada]= or(C,E);
							      			}else if(strcmp(ent_1, "D")==0 && strcmp(ent_2, "E")==0){
							      				s3[entrada]= or(D,E);
							      			}

							      			//para entradas com S1
							      			if (strcmp(ent_1, "S1")==0 && strcmp(ent_2, "A")==0)
							      			{
							      				s3[entrada]= or(s1[entrada],A);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "B")==0){
							      				s3[entrada]= or(s1[entrada],B);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "C")==0){
							      				s3[entrada]= or(s1[entrada],C);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "D")==0){
							      				s3[entrada]= or(s1[entrada],D);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "E")==0){
							      				s3[entrada]= or(s1[entrada],E);
							      			}
							      			if (strcmp(ent_1, "S2")==0 && strcmp(ent_2, "A")==0)
							      			{
							      				s3[entrada]= or(s2[entrada],A);
							      			}else if(strcmp(ent_1, "S2")==0 && strcmp(ent_2, "B")==0){
							      				s3[entrada]= or(s2[entrada],B);
							      			}else if(strcmp(ent_1, "S2")==0 && strcmp(ent_2, "C")==0){
							      				s3[entrada]= or(s2[entrada],C);
							      			}else if(strcmp(ent_1, "S2")==0 && strcmp(ent_2, "D")==0){
							      				s3[entrada]= or(s2[entrada],D);
							      			}else if(strcmp(ent_1, "S2")==0 && strcmp(ent_2, "E")==0){
							      				s3[entrada]= or(s2[entrada],E);
							      			}
							      			if (strcmp(ent_1, "S2")==0 && strcmp(ent_2, "S1")==0)
							      			{
							      				s3[entrada]= or(s2[entrada],s1[entrada]);
							      			}
		
							      			      // saída
							     	
										} 
										else if (strcmp(port_ent, "AND") == 0)
										{
								      		if (strcmp(ent_1, "A")==0 && strcmp(ent_2, "B")==0)
							      			{
							      				s3[entrada]= and(A,B);
							      			}else if(strcmp(ent_1, "A")==0 && strcmp(ent_2, "C")==0){
							      				s3[entrada]= and(A,C);
							      			}else if(strcmp(ent_1, "A")==0 && strcmp(ent_2, "D")==0){
							      				s3[entrada]= and(A,D);
							      			}else if (strcmp(ent_1, "A")==0 && strcmp(ent_2, "E")==0)
							      			{
							      				s3[entrada]= and(A,E);
							      			}else if(strcmp(ent_1, "B")==0 && strcmp(ent_2, "C")==0){
							      				s3[entrada]= and(B,C);
							      			}else if(strcmp(ent_1, "B")==0 && strcmp(ent_2, "D")==0){
							      				s3[entrada]= and(B,D);
							      			}else if (strcmp(ent_1, "B")==0 && strcmp(ent_2, "E")==0)
							      			{
							      				s3[entrada]= and(B,E);
							      			}else if(strcmp(ent_1, "C")==0 && strcmp(ent_2, "D")==0){
							      				s3[entrada]= and(C,D);
							      			}else if(strcmp(ent_1, "C")==0 && strcmp(ent_2, "E")==0){
							      				s3[entrada]= and(C,E);
							      			}else if(strcmp(ent_1, "D")==0 && strcmp(ent_2, "E")==0){
							      				s3[entrada]= and(D,E);
							      			}

							      			//para entradas com S1
							      			if (strcmp(ent_1, "S1")==0 && strcmp(ent_2, "A")==0)
							      			{
							      				s3[entrada]= and(s1[entrada],A);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "B")==0){
							      				s3[entrada]= and(s1[entrada],B);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "C")==0){
							      				s3[entrada]= and(s1[entrada],C);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "D")==0){
							      				s3[entrada]= and(s1[entrada],D);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "E")==0){
							      				s3[entrada]= and(s1[entrada],E);
							      			}
							      			if (strcmp(ent_1, "S2")==0 && strcmp(ent_2, "A")==0)
							      			{
							      				s3[entrada]= and(s2[entrada],A);
							      			}else if(strcmp(ent_1, "S2")==0 && strcmp(ent_2, "B")==0){
							      				s3[entrada]= and(s2[entrada],B);
							      			}else if(strcmp(ent_1, "S2")==0 && strcmp(ent_2, "C")==0){
							      				s3[entrada]= and(s2[entrada],C);
							      			}else if(strcmp(ent_1, "S2")==0 && strcmp(ent_2, "D")==0){
							      				s3[entrada]= and(s2[entrada],D);
							      			}else if(strcmp(ent_1, "S2")==0 && strcmp(ent_2, "E")==0){
							      				s3[entrada]= and(s2[entrada],E);
							      			}
							      			if (strcmp(ent_1, "S2")==0 && strcmp(ent_2, "S1")==0)
							      			{
							      				s3[entrada]= and(s2[entrada],s1[entrada]);
							      			}
										}if (strcmp(port_ent, "NOR") == 0) 
										{
											if (strcmp(ent_1, "A")==0 && strcmp(ent_2, "B")==0)
							      			{
							      				s3[entrada]= nor(A,B);
							      			}else if(strcmp(ent_1, "A")==0 && strcmp(ent_2, "C")==0){
							      				s3[entrada]= nor(A,C);
							      			}else if(strcmp(ent_1, "A")==0 && strcmp(ent_2, "D")==0){
							      				s3[entrada]= nor(A,D);
							      			}else if (strcmp(ent_1, "A")==0 && strcmp(ent_2, "E")==0)
							      			{
							      				s3[entrada]= nor(A,E);
							      			}else if(strcmp(ent_1, "B")==0 && strcmp(ent_2, "C")==0){
							      				s3[entrada]= nor(B,C);
							      			}else if(strcmp(ent_1, "B")==0 && strcmp(ent_2, "D")==0){
							      				s3[entrada]= nor(B,D);
							      			}else if (strcmp(ent_1, "B")==0 && strcmp(ent_2, "E")==0)
							      			{
							      				s3[entrada]= nor(B,E);
							      			}else if(strcmp(ent_1, "C")==0 && strcmp(ent_2, "D")==0){
							      				s3[entrada]= nor(C,D);
							      			}else if(strcmp(ent_1, "C")==0 && strcmp(ent_2, "E")==0){
							      				s3[entrada]= nor(C,E);
							      			}else if(strcmp(ent_1, "D")==0 && strcmp(ent_2, "E")==0){
							      				s3[entrada]= nor(D,E);
							      			}

							      			//para entradas com S1
							      			if (strcmp(ent_1, "S1")==0 && strcmp(ent_2, "A")==0)
							      			{
							      				s3[entrada]= nor(s1[entrada],A);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "B")==0){
							      				s3[entrada]= nor(s1[entrada],B);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "C")==0){
							      				s3[entrada]= nor(s1[entrada],C);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "D")==0){
							      				s3[entrada]= nor(s1[entrada],D);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "E")==0){
							      				s3[entrada]= nor(s1[entrada],E);
							      			}
							      			if (strcmp(ent_1, "S2")==0 && strcmp(ent_2, "A")==0)
							      			{
							      				s3[entrada]= nor(s2[entrada],A);
							      			}else if(strcmp(ent_1, "S2")==0 && strcmp(ent_2, "B")==0){
							      				s3[entrada]= nor(s2[entrada],B);
							      			}else if(strcmp(ent_1, "S2")==0 && strcmp(ent_2, "C")==0){
							      				s3[entrada]= nor(s2[entrada],C);
							      			}else if(strcmp(ent_1, "S2")==0 && strcmp(ent_2, "D")==0){
							      				s3[entrada]= nor(s2[entrada],D);
							      			}else if(strcmp(ent_1, "S2")==0 && strcmp(ent_2, "E")==0){
							      				s3[entrada]= nor(s2[entrada],E);
							      			}
							      			if (strcmp(ent_1, "S2")==0 && strcmp(ent_2, "S1")==0)
							      			{
							      				s3[entrada]= nor(s2[entrada],s1[entrada]);
							      			}
		
							      			
										} 
										else if (strcmp(port_ent, "NAND") == 0)
										{
											if (strcmp(ent_1, "A")==0 && strcmp(ent_2, "B")==0)
							      			{
							      				s3[entrada]= nand(A,B);
							      			}else if(strcmp(ent_1, "A")==0 && strcmp(ent_2, "C")==0){
							      				s3[entrada]= nand(A,C);
							      			}else if(strcmp(ent_1, "A")==0 && strcmp(ent_2, "D")==0){
							      				s3[entrada]= nand(A,D);
							      			}else if (strcmp(ent_1, "A")==0 && strcmp(ent_2, "E")==0)
							      			{
							      				s3[entrada]= nand(A,E);
							      			}else if(strcmp(ent_1, "B")==0 && strcmp(ent_2, "C")==0){
							      				s3[entrada]= nand(B,C);
							      			}else if(strcmp(ent_1, "B")==0 && strcmp(ent_2, "D")==0){
							      				s3[entrada]= nand(B,D);
							      			}else if (strcmp(ent_1, "B")==0 && strcmp(ent_2, "E")==0)
							      			{
							      				s3[entrada]= nand(B,E);
							      			}else if(strcmp(ent_1, "C")==0 && strcmp(ent_2, "D")==0){
							      				s3[entrada]= nand(C,D);
							      			}else if(strcmp(ent_1, "C")==0 && strcmp(ent_2, "E")==0){
							      				s3[entrada]= nand(C,E);
							      			}else if(strcmp(ent_1, "D")==0 && strcmp(ent_2, "E")==0){
							      				s3[entrada]= nand(D,E);
							      			}

							      			//para entradas com S1
							      			if (strcmp(ent_1, "S1")==0 && strcmp(ent_2, "A")==0)
							      			{
							      				s3[entrada]= nand(s1[entrada],A);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "B")==0){
							      				s3[entrada]= nand(s1[entrada],B);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "C")==0){
							      				s3[entrada]= nand(s1[entrada],C);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "D")==0){
							      				s3[entrada]= nand(s1[entrada],D);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "E")==0){
							      				s3[entrada]= nand(s1[entrada],E);
							      			}
							      			if (strcmp(ent_1, "S2")==0 && strcmp(ent_2, "A")==0)
							      			{
							      				s3[entrada]= nand(s2[entrada],A);
							      			}else if(strcmp(ent_1, "S2")==0 && strcmp(ent_2, "B")==0){
							      				s3[entrada]= nand(s2[entrada],B);
							      			}else if(strcmp(ent_1, "S2")==0 && strcmp(ent_2, "C")==0){
							      				s3[entrada]= nand(s2[entrada],C);
							      			}else if(strcmp(ent_1, "S2")==0 && strcmp(ent_2, "D")==0){
							      				s3[entrada]= nand(s2[entrada],D);
							      			}else if(strcmp(ent_1, "S2")==0 && strcmp(ent_2, "E")==0){
							      				s3[entrada]= nand(s2[entrada],E);
							      			}
							      			if (strcmp(ent_1, "S2")==0 && strcmp(ent_2, "S1")==0)
							      			{
							      				s3[entrada]= nand(s2[entrada],s1[entrada]);
							      			}
		
							      			 
										}if (strcmp(port_ent, "XOR") == 0) 
										{
								      		if (strcmp(ent_1, "A")==0 && strcmp(ent_2, "B")==0)
							      			{
							      				s3[entrada]= xor(A,B);
							      			}else if(strcmp(ent_1, "A")==0 && strcmp(ent_2, "C")==0){
							      				s3[entrada]= xor(A,C);
							      			}else if(strcmp(ent_1, "A")==0 && strcmp(ent_2, "D")==0){
							      				s3[entrada]= xor(A,D);
							      			}else if (strcmp(ent_1, "A")==0 && strcmp(ent_2, "E")==0)
							      			{
							      				s3[entrada]= xor(A,E);
							      			}else if(strcmp(ent_1, "B")==0 && strcmp(ent_2, "C")==0){
							      				s3[entrada]= xor(B,C);
							      			}else if(strcmp(ent_1, "B")==0 && strcmp(ent_2, "D")==0){
							      				s3[entrada]= xor(B,D);
							      			}else if (strcmp(ent_1, "B")==0 && strcmp(ent_2, "E")==0)
							      			{
							      				s3[entrada]= xor(B,E);
							      			}else if(strcmp(ent_1, "C")==0 && strcmp(ent_2, "D")==0){
							      				s3[entrada]= xor(C,D);
							      			}else if(strcmp(ent_1, "C")==0 && strcmp(ent_2, "E")==0){
							      				s3[entrada]= xor(C,E);
							      			}else if(strcmp(ent_1, "D")==0 && strcmp(ent_2, "E")==0){
							      				s3[entrada]= xor(D,E);
							      			}

							      			//para entradas com S1
							      			if (strcmp(ent_1, "S1")==0 && strcmp(ent_2, "A")==0)
							      			{
							      				s3[entrada]= xor(s1[entrada],A);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "B")==0){
							      				s3[entrada]= xor(s1[entrada],B);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "C")==0){
							      				s3[entrada]= xor(s1[entrada],C);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "D")==0){
							      				s3[entrada]= xor(s1[entrada],D);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "E")==0){
							      				s3[entrada]= xor(s1[entrada],E);
							      			}
							      			if (strcmp(ent_1, "S2")==0 && strcmp(ent_2, "A")==0)
							      			{
							      				s3[entrada]= xor(s2[entrada],A);
							      			}else if(strcmp(ent_1, "S2")==0 && strcmp(ent_2, "B")==0){
							      				s3[entrada]= xor(s2[entrada],B);
							      			}else if(strcmp(ent_1, "S2")==0 && strcmp(ent_2, "C")==0){
							      				s3[entrada]= xor(s2[entrada],C);
							      			}else if(strcmp(ent_1, "S2")==0 && strcmp(ent_2, "D")==0){
							      				s3[entrada]= xor(s2[entrada],D);
							      			}else if(strcmp(ent_1, "S2")==0 && strcmp(ent_2, "E")==0){
							      				s3[entrada]= xor(s2[entrada],E);
							      			}
							      			if (strcmp(ent_1, "S2")==0 && strcmp(ent_2, "S1")==0)
							      			{
							      				s3[entrada]= xor(s2[entrada],s1[entrada]);
							      			}
		
							      			
										} 
										else if (strcmp(port_ent, "XNOR") == 0)
										{
								      		if (strcmp(ent_1, "A")==0 && strcmp(ent_2, "B")==0)
							      			{
							      				s3[entrada]= xnor(A,B);
							      			}else if(strcmp(ent_1, "A")==0 && strcmp(ent_2, "C")==0){
							      				s3[entrada]= xnor(A,C);
							      			}else if(strcmp(ent_1, "A")==0 && strcmp(ent_2, "D")==0){
							      				s3[entrada]= xnor(A,D);
							      			}else if (strcmp(ent_1, "A")==0 && strcmp(ent_2, "E")==0)
							      			{
							      				s3[entrada]= xnor(A,E);
							      			}else if(strcmp(ent_1, "B")==0 && strcmp(ent_2, "C")==0){
							      				s3[entrada]= xnor(B,C);
							      			}else if(strcmp(ent_1, "B")==0 && strcmp(ent_2, "D")==0){
							      				s3[entrada]= xnor(B,D);
							      			}else if (strcmp(ent_1, "B")==0 && strcmp(ent_2, "E")==0)
							      			{
							      				s3[entrada]= xnor(B,E);
							      			}else if(strcmp(ent_1, "C")==0 && strcmp(ent_2, "D")==0){
							      				s3[entrada]= xnor(C,D);
							      			}else if(strcmp(ent_1, "C")==0 && strcmp(ent_2, "E")==0){
							      				s3[entrada]= xnor(C,E);
							      			}else if(strcmp(ent_1, "D")==0 && strcmp(ent_2, "E")==0){
							      				s3[entrada]= xnor(D,E);
							      			}

							      			//para entradas com S1
							      			if (strcmp(ent_1, "S1")==0 && strcmp(ent_2, "A")==0)
							      			{
							      				s3[entrada]= xnor(s1[entrada],A);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "B")==0){
							      				s3[entrada]= xnor(s1[entrada],B);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "C")==0){
							      				s3[entrada]= xnor(s1[entrada],C);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "D")==0){
							      				s3[entrada]= xnor(s1[entrada],D);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "E")==0){
							      				s3[entrada]= xnor(s1[entrada],E);
							      			}
							      			if (strcmp(ent_1, "S2")==0 && strcmp(ent_2, "A")==0)
							      			{
							      				s3[entrada]= xnor(s2[entrada],A);
							      			}else if(strcmp(ent_1, "S2")==0 && strcmp(ent_2, "B")==0){
							      				s3[entrada]= xnor(s2[entrada],B);
							      			}else if(strcmp(ent_1, "S2")==0 && strcmp(ent_2, "C")==0){
							      				s3[entrada]= xnor(s2[entrada],C);
							      			}else if(strcmp(ent_1, "S2")==0 && strcmp(ent_2, "D")==0){
							      				s3[entrada]= xnor(s2[entrada],D);
							      			}else if(strcmp(ent_1, "S2")==0 && strcmp(ent_2, "E")==0){
							      				s3[entrada]= xnor(s2[entrada],E);
							      			}
							      			if (strcmp(ent_1, "S2")==0 && strcmp(ent_2, "S1")==0)
							      			{
							      				s3[entrada]= xnor(s2[entrada],s1[entrada]);
							      			}
		
							      			
										}if (strcmp(port_ent, "NOT") == 0)
										{
								      		if (strcmp(ent_1, "A")==0 )
							      			{
							      				s3[entrada]= not(A);
							      			}else if(strcmp(ent_1, "B")==0){
							      				s3[entrada]= not(B);
							      			}else if(strcmp(ent_1, "C")==0){
							      				s3[entrada]= not(C);
							      			}else if (strcmp(ent_1, "D")==0 ){
							      				s3[entrada]= not(D);
							      			}else if(strcmp(ent_1, "E")==0 ){
							      				s3[entrada]= not(E);
							      			}
							      			//para entradas com S1
							      			if (strcmp(ent_1, "S1")==0)
							      			{
							      				s3[entrada]= not(s1[entrada]);
							      			}else if (strcmp(ent_1, "S2")==0)
							      			{
							      				s3[entrada]= not(s2[entrada]);
							      			}
								      		
										}
									//prende s1
										if (strcmp(fixa1, "S3")==0 && strcmp(fixa0, "0")==0)
										{
											s3[entrada]=0;
										}else if (strcmp(fixa1, "S3")==0 && strcmp(fixa0, "1")==0)
										{
											s3[entrada]=1;
										}
										if (strcmp(fixa3, "S3")==0 && strcmp(fixa4, "0")==0)
										{
											s3[entrada]=0;
										}else if (strcmp(fixa3, "S3")==0 && strcmp(fixa4, "1")==0)
										{
											s3[entrada]=1;
										}		
								}			      						 						 
							}
							//saida s4////////////////////////////////////////////////////////////////
							if (strcmp(saidas1, "S4") == 0) 
							{
								for(entrada = 0; entrada < k ; entrada++) {
									 A = (entrada & 1)?A1:A2; 
										B = (entrada & 2)?B1:B2;  
										C = (entrada & 4)?C1:C2;  
										D = (entrada & 8)?D1:D2;
										E = (entrada & 16)?E1:E2;
							      	if (strcmp(port_ent, "OR") == 0) {	
										if (strcmp(ent_1, "A")==0 && strcmp(ent_2, "B")==0)
							      			{
							      				s4[entrada]= or(A,B);
							      			}else if(strcmp(ent_1, "A")==0 && strcmp(ent_2, "C")==0){
							      				s4[entrada]= or(A,C);
							      			}else if(strcmp(ent_1, "A")==0 && strcmp(ent_2, "D")==0){
							      				s4[entrada]= or(A,D);
							      			}else if (strcmp(ent_1, "A")==0 && strcmp(ent_2, "E")==0)
							      			{
							      				s4[entrada]= or(A,E);
							      			}else if(strcmp(ent_1, "B")==0 && strcmp(ent_2, "C")==0){
							      				s4[entrada]= or(B,C);
							      			}else if(strcmp(ent_1, "B")==0 && strcmp(ent_2, "D")==0){
							      				s4[entrada]= or(B,D);
							      			}else if (strcmp(ent_1, "B")==0 && strcmp(ent_2, "E")==0)
							      			{
							      				s4[entrada]= or(B,E);
							      			}else if(strcmp(ent_1, "C")==0 && strcmp(ent_2, "D")==0){
							      				s4[entrada]= or(C,D);
							      			}else if(strcmp(ent_1, "C")==0 && strcmp(ent_2, "E")==0){
							      				s4[entrada]= or(C,E);
							      			}else if(strcmp(ent_1, "D")==0 && strcmp(ent_2, "E")==0){
							      				s4[entrada]= or(D,E);
							      			}

							      			//para entradas com S1
							      			if (strcmp(ent_1, "S1")==0 && strcmp(ent_2, "A")==0)
							      			{
							      				s4[entrada]= or(s1[entrada],A);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "B")==0){
							      				s4[entrada]= or(s1[entrada],B);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "C")==0){
							      				s4[entrada]= or(s1[entrada],C);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "D")==0){
							      				s4[entrada]= or(s1[entrada],D);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "E")==0){
							      				s4[entrada]= or(s1[entrada],E);
							      			}
							      			if (strcmp(ent_1, "S2")==0 && strcmp(ent_2, "A")==0)
							      			{
							      				s4[entrada]= or(s2[entrada],A);
							      			}else if(strcmp(ent_1, "S2")==0 && strcmp(ent_2, "B")==0){
							      				s4[entrada]= or(s2[entrada],B);
							      			}else if(strcmp(ent_1, "S2")==0 && strcmp(ent_2, "C")==0){
							      				s4[entrada]= or(s2[entrada],C);
							      			}else if(strcmp(ent_1, "S2")==0 && strcmp(ent_2, "D")==0){
							      				s4[entrada]= or(s2[entrada],D);
							      			}else if(strcmp(ent_1, "S2")==0 && strcmp(ent_2, "E")==0){
							      				s4[entrada]= or(s2[entrada],E);
							      			}
							      			if (strcmp(ent_1, "S2")==0 && strcmp(ent_2, "S1")==0)
							      			{
							      				s4[entrada]= or(s2[entrada],s1[entrada]);
							      			}
							      			if (strcmp(ent_1, "S3")==0 && strcmp(ent_2, "A")==0)
							      			{
							      				s4[entrada]= or(s3[entrada],A);
							      			}else if(strcmp(ent_1, "S3")==0 && strcmp(ent_2, "B")==0){
							      				s4[entrada]= or(s3[entrada],B);
							      			}else if(strcmp(ent_1, "S3")==0 && strcmp(ent_2, "C")==0){
							      				s4[entrada]= or(s3[entrada],C);
							      			}else if(strcmp(ent_1, "S3")==0 && strcmp(ent_2, "D")==0){
							      				s4[entrada]= or(s3[entrada],D);
							      			}else if(strcmp(ent_1, "S3")==0 && strcmp(ent_2, "E")==0){
							      				s4[entrada]= or(s3[entrada],E);
							      			}
							      			if (strcmp(ent_1, "S3")==0 && strcmp(ent_2, "S1")==0)
							      			{
							      				s4[entrada]= or(s3[entrada],s1[entrada]);
							      			}
							      			if (strcmp(ent_1, "S3")==0 && strcmp(ent_2, "S2")==0)
							      			{
							      				s4[entrada]= or(s3[entrada],s2[entrada]);
							      			}      // saída
							     	
										} 
										else if (strcmp(port_ent, "AND") == 0)
										{
								      		if (strcmp(ent_1, "A")==0 && strcmp(ent_2, "B")==0)
							      			{
							      				s4[entrada]= and(A,B);
							      			}else if(strcmp(ent_1, "A")==0 && strcmp(ent_2, "C")==0){
							      				s4[entrada]= and(A,C);
							      			}else if(strcmp(ent_1, "A")==0 && strcmp(ent_2, "D")==0){
							      				s4[entrada]= and(A,D);
							      			}else if (strcmp(ent_1, "A")==0 && strcmp(ent_2, "E")==0)
							      			{
							      				s4[entrada]= and(A,E);
							      			}else if(strcmp(ent_1, "B")==0 && strcmp(ent_2, "C")==0){
							      				s4[entrada]= and(B,C);
							      			}else if(strcmp(ent_1, "B")==0 && strcmp(ent_2, "D")==0){
							      				s4[entrada]= and(B,D);
							      			}else if (strcmp(ent_1, "B")==0 && strcmp(ent_2, "E")==0)
							      			{
							      				s4[entrada]= and(B,E);
							      			}else if(strcmp(ent_1, "C")==0 && strcmp(ent_2, "D")==0){
							      				s4[entrada]= and(C,D);
							      			}else if(strcmp(ent_1, "C")==0 && strcmp(ent_2, "E")==0){
							      				s4[entrada]= and(C,E);
							      			}else if(strcmp(ent_1, "D")==0 && strcmp(ent_2, "E")==0){
							      				s4[entrada]= and(D,E);
							      			}

							      			//para entradas com S1
							      			if (strcmp(ent_1, "S1")==0 && strcmp(ent_2, "A")==0)
							      			{
							      				s4[entrada]= and(s1[entrada],A);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "B")==0){
							      				s4[entrada]= and(s1[entrada],B);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "C")==0){
							      				s4[entrada]= and(s1[entrada],C);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "D")==0){
							      				s4[entrada]= and(s1[entrada],D);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "E")==0){
							      				s4[entrada]= and(s1[entrada],E);
							      			}
							      			if (strcmp(ent_1, "S2")==0 && strcmp(ent_2, "A")==0)
							      			{
							      				s4[entrada]= and(s2[entrada],A);
							      			}else if(strcmp(ent_1, "S2")==0 && strcmp(ent_2, "B")==0){
							      				s4[entrada]= and(s2[entrada],B);
							      			}else if(strcmp(ent_1, "S2")==0 && strcmp(ent_2, "C")==0){
							      				s4[entrada]= and(s2[entrada],C);
							      			}else if(strcmp(ent_1, "S2")==0 && strcmp(ent_2, "D")==0){
							      				s4[entrada]= and(s2[entrada],D);
							      			}else if(strcmp(ent_1, "S2")==0 && strcmp(ent_2, "E")==0){
							      				s4[entrada]= and(s2[entrada],E);
							      			}
							      			if (strcmp(ent_1, "S2")==0 && strcmp(ent_2, "S1")==0)
							      			{
							      				s4[entrada]= and(s2[entrada],s1[entrada]);
							      			}
							      			if (strcmp(ent_1, "S3")==0 && strcmp(ent_2, "A")==0)
							      			{
							      				s4[entrada]= and(s3[entrada],A);
							      			}else if(strcmp(ent_1, "S3")==0 && strcmp(ent_2, "B")==0){
							      				s4[entrada]= and(s3[entrada],B);
							      			}else if(strcmp(ent_1, "S3")==0 && strcmp(ent_2, "C")==0){
							      				s4[entrada]= and(s3[entrada],C);
							      			}else if(strcmp(ent_1, "S3")==0 && strcmp(ent_2, "D")==0){
							      				s4[entrada]= and(s3[entrada],D);
							      			}else if(strcmp(ent_1, "S3")==0 && strcmp(ent_2, "E")==0){
							      				s4[entrada]= and(s3[entrada],E);
							      			}
							      			if (strcmp(ent_1, "S3")==0 && strcmp(ent_2, "S1")==0)
							      			{
							      				s4[entrada]= and(s3[entrada],s1[entrada]);
							      			}
							      			if (strcmp(ent_1, "S3")==0 && strcmp(ent_2, "S2")==0)
							      			{
							      				s4[entrada]= and(s3[entrada],s2[entrada]);
							      			}
							     	
										 
										}if (strcmp(port_ent, "NOR") == 0) 
										{
											if (strcmp(ent_1, "A")==0 && strcmp(ent_2, "B")==0)
							      			{
							      				s4[entrada]= nor(A,B);
							      			}else if(strcmp(ent_1, "A")==0 && strcmp(ent_2, "C")==0){
							      				s4[entrada]= nor(A,C);
							      			}else if(strcmp(ent_1, "A")==0 && strcmp(ent_2, "D")==0){
							      				s4[entrada]= nor(A,D);
							      			}else if (strcmp(ent_1, "A")==0 && strcmp(ent_2, "E")==0)
							      			{
							      				s4[entrada]= nor(A,E);
							      			}else if(strcmp(ent_1, "B")==0 && strcmp(ent_2, "C")==0){
							      				s4[entrada]= nor(B,C);
							      			}else if(strcmp(ent_1, "B")==0 && strcmp(ent_2, "D")==0){
							      				s4[entrada]= nor(B,D);
							      			}else if (strcmp(ent_1, "B")==0 && strcmp(ent_2, "E")==0)
							      			{
							      				s4[entrada]= nor(B,E);
							      			}else if(strcmp(ent_1, "C")==0 && strcmp(ent_2, "D")==0){
							      				s4[entrada]= nor(C,D);
							      			}else if(strcmp(ent_1, "C")==0 && strcmp(ent_2, "E")==0){
							      				s4[entrada]= nor(C,E);
							      			}else if(strcmp(ent_1, "D")==0 && strcmp(ent_2, "E")==0){
							      				s4[entrada]= nor(D,E);
							      			}

							      			//para entradas com S1
							      			if (strcmp(ent_1, "S1")==0 && strcmp(ent_2, "A")==0)
							      			{
							      				s4[entrada]= nor(s1[entrada],A);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "B")==0){
							      				s4[entrada]= nor(s1[entrada],B);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "C")==0){
							      				s4[entrada]= nor(s1[entrada],C);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "D")==0){
							      				s4[entrada]= nor(s1[entrada],D);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "E")==0){
							      				s4[entrada]= nor(s1[entrada],E);
							      			}
							      			if (strcmp(ent_1, "S2")==0 && strcmp(ent_2, "A")==0)
							      			{
							      				s4[entrada]= nor(s2[entrada],A);
							      			}else if(strcmp(ent_1, "S2")==0 && strcmp(ent_2, "B")==0){
							      				s4[entrada]= nor(s2[entrada],B);
							      			}else if(strcmp(ent_1, "S2")==0 && strcmp(ent_2, "C")==0){
							      				s4[entrada]= nor(s2[entrada],C);
							      			}else if(strcmp(ent_1, "S2")==0 && strcmp(ent_2, "D")==0){
							      				s4[entrada]= nor(s2[entrada],D);
							      			}else if(strcmp(ent_1, "S2")==0 && strcmp(ent_2, "E")==0){
							      				s4[entrada]= nor(s2[entrada],E);
							      			}
							      			if (strcmp(ent_1, "S2")==0 && strcmp(ent_2, "S1")==0)
							      			{
							      				s4[entrada]= nor(s2[entrada],s1[entrada]);
							      			}
							      			if (strcmp(ent_1, "S3")==0 && strcmp(ent_2, "A")==0)
							      			{
							      				s4[entrada]= nor(s3[entrada],A);
							      			}else if(strcmp(ent_1, "S3")==0 && strcmp(ent_2, "B")==0){
							      				s4[entrada]= nor(s3[entrada],B);
							      			}else if(strcmp(ent_1, "S3")==0 && strcmp(ent_2, "C")==0){
							      				s4[entrada]= nor(s3[entrada],C);
							      			}else if(strcmp(ent_1, "S3")==0 && strcmp(ent_2, "D")==0){
							      				s4[entrada]= nor(s3[entrada],D);
							      			}else if(strcmp(ent_1, "S3")==0 && strcmp(ent_2, "E")==0){
							      				s4[entrada]= nor(s3[entrada],E);
							      			}
							      			if (strcmp(ent_1, "S3")==0 && strcmp(ent_2, "S1")==0)
							      			{
							      				s4[entrada]= nor(s3[entrada],s1[entrada]);
							      			}
							      			if (strcmp(ent_1, "S3")==0 && strcmp(ent_2, "S2")==0)
							      			{
							      				s4[entrada]= nor(s3[entrada],s2[entrada]);
							      			}
										} 
										else if (strcmp(port_ent, "NAND") == 0)
										{
											if (strcmp(ent_1, "A")==0 && strcmp(ent_2, "B")==0)
							      			{
							      				s4[entrada]=  nand(A,B);
							      			}else if(strcmp(ent_1, "A")==0 && strcmp(ent_2, "C")==0){
							      				s4[entrada]= nand(A,C);
							      			}else if(strcmp(ent_1, "A")==0 && strcmp(ent_2, "D")==0){
							      				s4[entrada]= nand(A,D);
							      			}else if (strcmp(ent_1, "A")==0 && strcmp(ent_2, "E")==0)
							      			{
							      				s4[entrada]= nand(A,E);
							      			}else if(strcmp(ent_1, "B")==0 && strcmp(ent_2, "C")==0){
							      				s4[entrada]= nand(B,C);
							      			}else if(strcmp(ent_1, "B")==0 && strcmp(ent_2, "D")==0){
							      				s4[entrada]= nand(B,D);
							      			}else if (strcmp(ent_1, "B")==0 && strcmp(ent_2, "E")==0)
							      			{
							      				s4[entrada]= nand(B,E);
							      			}else if(strcmp(ent_1, "C")==0 && strcmp(ent_2, "D")==0){
							      				s4[entrada]= nand(C,D);
							      			}else if(strcmp(ent_1, "C")==0 && strcmp(ent_2, "E")==0){
							      				s4[entrada]= nand(C,E);
							      			}else if(strcmp(ent_1, "D")==0 && strcmp(ent_2, "E")==0){
							      				s4[entrada]= nand(D,E);
							      			}

							      			//para entradas com S1
							      			if (strcmp(ent_1, "S1")==0 && strcmp(ent_2, "A")==0)
							      			{
							      				s4[entrada]= nand(s1[entrada],A);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "B")==0){
							      				s4[entrada]= nand(s1[entrada],B);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "C")==0){
							      				s4[entrada]= nand(s1[entrada],C);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "D")==0){
							      				s4[entrada]= nand(s1[entrada],D);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "E")==0){
							      				s4[entrada]= nand(s1[entrada],E);
							      			}
							      			if (strcmp(ent_1, "S2")==0 && strcmp(ent_2, "A")==0)
							      			{
							      				s4[entrada]= nand(s2[entrada],A);
							      			}else if(strcmp(ent_1, "S2")==0 && strcmp(ent_2, "B")==0){
							      				s4[entrada]= nand(s2[entrada],B);
							      			}else if(strcmp(ent_1, "S2")==0 && strcmp(ent_2, "C")==0){
							      				s4[entrada]= nand(s2[entrada],C);
							      			}else if(strcmp(ent_1, "S2")==0 && strcmp(ent_2, "D")==0){
							      				s4[entrada]= nand(s2[entrada],D);
							      			}else if(strcmp(ent_1, "S2")==0 && strcmp(ent_2, "E")==0){
							      				s4[entrada]= nand(s2[entrada],E);
							      			}
							      			if (strcmp(ent_1, "S2")==0 && strcmp(ent_2, "S1")==0)
							      			{
							      				s4[entrada]= nand(s2[entrada],s1[entrada]);
							      			}
							      			if (strcmp(ent_1, "S3")==0 && strcmp(ent_2, "A")==0)
							      			{
							      				s4[entrada]= nand(s3[entrada],A);
							      			}else if(strcmp(ent_1, "S3")==0 && strcmp(ent_2, "B")==0){
							      				s4[entrada]= nand(s3[entrada],B);
							      			}else if(strcmp(ent_1, "S3")==0 && strcmp(ent_2, "C")==0){
							      				s4[entrada]= nand(s3[entrada],C);
							      			}else if(strcmp(ent_1, "S3")==0 && strcmp(ent_2, "D")==0){
							      				s4[entrada]= nand(s3[entrada],D);
							      			}else if(strcmp(ent_1, "S3")==0 && strcmp(ent_2, "E")==0){
							      				s4[entrada]= nand(s3[entrada],E);
							      			}
							      			if (strcmp(ent_1, "S3")==0 && strcmp(ent_2, "S1")==0)
							      			{
							      				s4[entrada]= nand(s3[entrada],s1[entrada]);
							      			}
							      			if (strcmp(ent_1, "S3")==0 && strcmp(ent_2, "S2")==0)
							      			{
							      				s4[entrada]= nand(s3[entrada],s2[entrada]);
							      			}
										}if (strcmp(port_ent, "XOR") == 0) 
										{
								      		if (strcmp(ent_1, "A")==0 && strcmp(ent_2, "B")==0)
							      			{
							      				s4[entrada]=  xor(A,B);
							      			}else if(strcmp(ent_1, "A")==0 && strcmp(ent_2, "C")==0){
							      				s4[entrada]= xor(A,C);
							      			}else if(strcmp(ent_1, "A")==0 && strcmp(ent_2, "D")==0){
							      				s4[entrada]= xor(A,D);
							      			}else if (strcmp(ent_1, "A")==0 && strcmp(ent_2, "E")==0)
							      			{
							      				s4[entrada]= xor(A,E);
							      			}else if(strcmp(ent_1, "B")==0 && strcmp(ent_2, "C")==0){
							      				s4[entrada]= xor(B,C);
							      			}else if(strcmp(ent_1, "B")==0 && strcmp(ent_2, "D")==0){
							      				s4[entrada]= xor(B,D);
							      			}else if (strcmp(ent_1, "B")==0 && strcmp(ent_2, "E")==0)
							      			{
							      				s4[entrada]= xor(B,E);
							      			}else if(strcmp(ent_1, "C")==0 && strcmp(ent_2, "D")==0){
							      				s4[entrada]= xor(C,D);
							      			}else if(strcmp(ent_1, "C")==0 && strcmp(ent_2, "E")==0){
							      				s4[entrada]= xor(C,E);
							      			}else if(strcmp(ent_1, "D")==0 && strcmp(ent_2, "E")==0){
							      				s4[entrada]= xor(D,E);
							      			}

							      			//para entradas com S1
							      			if (strcmp(ent_1, "S1")==0 && strcmp(ent_2, "A")==0)
							      			{
							      				s4[entrada]= xor(s1[entrada],A);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "B")==0){
							      				s4[entrada]= xor(s1[entrada],B);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "C")==0){
							      				s4[entrada]= xor(s1[entrada],C);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "D")==0){
							      				s4[entrada]= xor(s1[entrada],D);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "E")==0){
							      				s4[entrada]= xor(s1[entrada],E);
							      			}
							      			if (strcmp(ent_1, "S2")==0 && strcmp(ent_2, "A")==0)
							      			{
							      				s4[entrada]= xor(s2[entrada],A);
							      			}else if(strcmp(ent_1, "S2")==0 && strcmp(ent_2, "B")==0){
							      				s4[entrada]= xor(s2[entrada],B);
							      			}else if(strcmp(ent_1, "S2")==0 && strcmp(ent_2, "C")==0){
							      				s4[entrada]= xor(s2[entrada],C);
							      			}else if(strcmp(ent_1, "S2")==0 && strcmp(ent_2, "D")==0){
							      				s4[entrada]= xor(s2[entrada],D);
							      			}else if(strcmp(ent_1, "S2")==0 && strcmp(ent_2, "E")==0){
							      				s4[entrada]= xor(s2[entrada],E);
							      			}
							      			if (strcmp(ent_1, "S2")==0 && strcmp(ent_2, "S1")==0)
							      			{
							      				s4[entrada]= xor(s2[entrada],s1[entrada]);
							      			}
							      			if (strcmp(ent_1, "S3")==0 && strcmp(ent_2, "A")==0)
							      			{
							      				s4[entrada]= xor(s3[entrada],A);
							      			}else if(strcmp(ent_1, "S3")==0 && strcmp(ent_2, "B")==0){
							      				s4[entrada]= xor(s3[entrada],B);
							      			}else if(strcmp(ent_1, "S3")==0 && strcmp(ent_2, "C")==0){
							      				s4[entrada]= xor(s3[entrada],C);
							      			}else if(strcmp(ent_1, "S3")==0 && strcmp(ent_2, "D")==0){
							      				s4[entrada]= xor(s3[entrada],D);
							      			}else if(strcmp(ent_1, "S3")==0 && strcmp(ent_2, "E")==0){
							      				s4[entrada]= xor(s3[entrada],E);
							      			}
							      			if (strcmp(ent_1, "S3")==0 && strcmp(ent_2, "S1")==0)
							      			{
							      				s4[entrada]= xor(s3[entrada],s1[entrada]);
							      			}
							      			if (strcmp(ent_1, "S3")==0 && strcmp(ent_2, "S2")==0)
							      			{
							      				s4[entrada]= xor(s3[entrada],s2[entrada]);
							      			}
										} 
										else if (strcmp(port_ent, "XNOR") == 0)
										{
								      		if (strcmp(ent_1, "A")==0 && strcmp(ent_2, "B")==0)
							      			{
							      				s4[entrada]=  xnor(A,B);
							      			}else if(strcmp(ent_1, "A")==0 && strcmp(ent_2, "C")==0){
							      				s4[entrada]= xnor(A,C);
							      			}else if(strcmp(ent_1, "A")==0 && strcmp(ent_2, "D")==0){
							      				s4[entrada]= xnor(A,D);
							      			}else if (strcmp(ent_1, "A")==0 && strcmp(ent_2, "E")==0)
							      			{
							      				s4[entrada]= xnor(A,E);
							      			}else if(strcmp(ent_1, "B")==0 && strcmp(ent_2, "C")==0){
							      				s4[entrada]= xnor(B,C);
							      			}else if(strcmp(ent_1, "B")==0 && strcmp(ent_2, "D")==0){
							      				s4[entrada]= xnor(B,D);
							      			}else if (strcmp(ent_1, "B")==0 && strcmp(ent_2, "E")==0)
							      			{
							      				s4[entrada]= xnor(B,E);
							      			}else if(strcmp(ent_1, "C")==0 && strcmp(ent_2, "D")==0){
							      				s4[entrada]= xnor(C,D);
							      			}else if(strcmp(ent_1, "C")==0 && strcmp(ent_2, "E")==0){
							      				s4[entrada]= xnor(C,E);
							      			}else if(strcmp(ent_1, "D")==0 && strcmp(ent_2, "E")==0){
							      				s4[entrada]= xnor(D,E);
							      			}

							      			//para entradas com S1
							      			if (strcmp(ent_1, "S1")==0 && strcmp(ent_2, "A")==0)
							      			{
							      				s4[entrada]= xnor(s1[entrada],A);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "B")==0){
							      				s4[entrada]= xnor(s1[entrada],B);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "C")==0){
							      				s4[entrada]= xnor(s1[entrada],C);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "D")==0){
							      				s4[entrada]= xnor(s1[entrada],D);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "E")==0){
							      				s4[entrada]= xnor(s1[entrada],E);
							      			}
							      			if (strcmp(ent_1, "S2")==0 && strcmp(ent_2, "A")==0)
							      			{
							      				s4[entrada]= xnor(s2[entrada],A);
							      			}else if(strcmp(ent_1, "S2")==0 && strcmp(ent_2, "B")==0){
							      				s4[entrada]= xnor(s2[entrada],B);
							      			}else if(strcmp(ent_1, "S2")==0 && strcmp(ent_2, "C")==0){
							      				s4[entrada]= xnor(s2[entrada],C);
							      			}else if(strcmp(ent_1, "S2")==0 && strcmp(ent_2, "D")==0){
							      				s4[entrada]= xnor(s2[entrada],D);
							      			}else if(strcmp(ent_1, "S2")==0 && strcmp(ent_2, "E")==0){
							      				s4[entrada]= xnor(s2[entrada],E);
							      			}
							      			if (strcmp(ent_1, "S2")==0 && strcmp(ent_2, "S1")==0)
							      			{
							      				s4[entrada]= xnor(s2[entrada],s1[entrada]);
							      			}
							      			if (strcmp(ent_1, "S3")==0 && strcmp(ent_2, "A")==0)
							      			{
							      				s4[entrada]= xnor(s3[entrada],A);
							      			}else if(strcmp(ent_1, "S3")==0 && strcmp(ent_2, "B")==0){
							      				s4[entrada]= xnor(s3[entrada],B);
							      			}else if(strcmp(ent_1, "S3")==0 && strcmp(ent_2, "C")==0){
							      				s4[entrada]= xnor(s3[entrada],C);
							      			}else if(strcmp(ent_1, "S3")==0 && strcmp(ent_2, "D")==0){
							      				s4[entrada]= xnor(s3[entrada],D);
							      			}else if(strcmp(ent_1, "S3")==0 && strcmp(ent_2, "E")==0){
							      				s4[entrada]= xnor(s3[entrada],E);
							      			}
							      			if (strcmp(ent_1, "S3")==0 && strcmp(ent_2, "S1")==0)
							      			{
							      				s4[entrada]= xnor(s3[entrada],s1[entrada]);
							      			}
							      			if (strcmp(ent_1, "S3")==0 && strcmp(ent_2, "S2")==0)
							      			{
							      				s4[entrada]= xnor(s3[entrada],s2[entrada]);
							      			}
										}if (strcmp(port_ent, "NOT") == 0)
										{
								      		if (strcmp(ent_1, "A")==0 )
							      			{
							      				s4[entrada]= not(A);
							      			}else if(strcmp(ent_1, "B")==0){
							      				s4[entrada]= not(B);
							      			}else if(strcmp(ent_1, "C")==0){
							      				s4[entrada]= not(C);
							      			}else if (strcmp(ent_1, "D")==0 ){
							      				s4[entrada]= not(D);
							      			}else if(strcmp(ent_1, "E")==0 ){
							      				s4[entrada]= not(E);
							      			}
							      			//para entradas com S1
							      			if (strcmp(ent_1, "S1")==0)
							      			{
							      				s4[entrada]= not(s1[entrada]);
							      			}else if (strcmp(ent_1, "S2")==0)
							      			{
							      				s4[entrada]= not(s2[entrada]);
							      			}else if (strcmp(ent_1, "S3")==0)
							      			{
							      				s4[entrada]= not(s3[entrada]);
							      			}
								      		
										}
								//prende s4
										if (strcmp(fixa1, "S4")==0 && strcmp(fixa0, "0")==0)
										{
											s4[entrada]=0;
										}else if (strcmp(fixa1, "S4")==0 && strcmp(fixa0, "1")==0)
										{
											s4[entrada]=1;
										}if (strcmp(fixa3, "S4")==0 && strcmp(fixa4, "0")==0)
										{
											s4[entrada]=0;
										}else if (strcmp(fixa3, "S4")==0 && strcmp(fixa4, "1")==0)
										{
											s4[entrada]=1;
										}		
								}
				 						 
							} 
							//saida s5////////////////////////////////////////////////////////////////
							if (strcmp(saidas1, "S5") == 0) 
							{
								for(entrada = 0; entrada < k ; entrada++) {
									  	A = (entrada & 1)?A1:A2; 
										B = (entrada & 2)?B1:B2;  
										C = (entrada & 4)?C1:C2;  
										D = (entrada & 8)?D1:D2;
										E = (entrada & 16)?E1:E2;

							      		if (strcmp(port_ent, "OR") == 0) {	
											if (strcmp(ent_1, "A")==0 && strcmp(ent_2, "B")==0){
							      				s5[entrada]= or(A,B);
							      			}else if(strcmp(ent_1, "A")==0 && strcmp(ent_2, "C")==0){
							      				s5[entrada]= or(A,C);
							      			}else if(strcmp(ent_1, "A")==0 && strcmp(ent_2, "D")==0){
							      				s5[entrada]= or(A,D);
							      			}else if (strcmp(ent_1, "A")==0 && strcmp(ent_2, "E")==0)
							      			{
							      				s5[entrada]= or(A,E);
							      			}else if(strcmp(ent_1, "B")==0 && strcmp(ent_2, "C")==0){
							      				s5[entrada]= or(B,C);
							      			}else if(strcmp(ent_1, "B")==0 && strcmp(ent_2, "D")==0){
							      				s5[entrada]= or(B,D);
							      			}else if (strcmp(ent_1, "B")==0 && strcmp(ent_2, "E")==0)
							      			{
							      				s5[entrada]= or(B,E);
							      			}else if(strcmp(ent_1, "C")==0 && strcmp(ent_2, "D")==0){
							      				s5[entrada]= or(C,D);
							      			}else if(strcmp(ent_1, "C")==0 && strcmp(ent_2, "E")==0){
							      				s5[entrada]= or(C,E);
							      			}else if(strcmp(ent_1, "D")==0 && strcmp(ent_2, "E")==0){
							      				s5[entrada]= or(D,E);
							      			}

							      			//para entradas com S1
							      			if (strcmp(ent_1, "S1")==0 && strcmp(ent_2, "A")==0)
							      			{
							      				s5[entrada]= or(s1[entrada],A);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "B")==0){
							      				s5[entrada]= or(s1[entrada],B);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "C")==0){
							      				s5[entrada]= or(s1[entrada],C);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "D")==0){
							      				s5[entrada]= or(s1[entrada],D);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "E")==0){
							      				s5[entrada]= or(s1[entrada],E);
							      			}
							      			if (strcmp(ent_1, "S2")==0 && strcmp(ent_2, "A")==0)
							      			{
							      				s5[entrada]= or(s2[entrada],A);
							      			}else if(strcmp(ent_1, "S2")==0 && strcmp(ent_2, "B")==0){
							      				s5[entrada]= or(s2[entrada],B);
							      			}else if(strcmp(ent_1, "S2")==0 && strcmp(ent_2, "C")==0){
							      				s5[entrada]= or(s2[entrada],C);
							      			}else if(strcmp(ent_1, "S2")==0 && strcmp(ent_2, "D")==0){
							      				s5[entrada]= or(s2[entrada],D);
							      			}else if(strcmp(ent_1, "S2")==0 && strcmp(ent_2, "E")==0){
							      				s5[entrada]= or(s2[entrada],E);
							      			}
							      			if (strcmp(ent_1, "S2")==0 && strcmp(ent_2, "S1")==0)
							      			{
							      				s5[entrada]= or(s2[entrada],s1[entrada]);
							      			}
							      			if (strcmp(ent_1, "S3")==0 && strcmp(ent_2, "A")==0)
							      			{
							      				s5[entrada]= or(s3[entrada],A);
							      			}else if(strcmp(ent_1, "S3")==0 && strcmp(ent_2, "B")==0){
							      				s5[entrada]= or(s3[entrada],B);
							      			}else if(strcmp(ent_1, "S3")==0 && strcmp(ent_2, "C")==0){
							      				s5[entrada]= or(s3[entrada],C);
							      			}else if(strcmp(ent_1, "S3")==0 && strcmp(ent_2, "D")==0){
							      				s5[entrada]= or(s3[entrada],D);
							      			}else if(strcmp(ent_1, "S3")==0 && strcmp(ent_2, "E")==0){
							      				s5[entrada]= or(s3[entrada],E);
							      			}
							      			if (strcmp(ent_1, "S3")==0 && strcmp(ent_2, "S1")==0)
							      			{
							      				s5[entrada]= or(s3[entrada],s1[entrada]);
							      			}if (strcmp(ent_1, "S3")==0 && strcmp(ent_2, "S2")==0){
							      				s5[entrada]= or(s3[entrada],s2[entrada]);
							      			}if (strcmp(ent_1, "S4")==0 && strcmp(ent_2, "A")==0)
							      			{
							      				s5[entrada]= or(s4[entrada],A);
							      			}else if(strcmp(ent_1, "S4")==0 && strcmp(ent_2, "B")==0){
							      				s5[entrada]= or(s4[entrada],B);
							      			}else if(strcmp(ent_1, "S4")==0 && strcmp(ent_2, "C")==0){
							      				s5[entrada]= or(s4[entrada],C);
							      			}else if(strcmp(ent_1, "S4")==0 && strcmp(ent_2, "D")==0){
							      				s5[entrada]= or(s4[entrada],D);
							      			}else if(strcmp(ent_1, "S4")==0 && strcmp(ent_2, "E")==0){
							      				s5[entrada]= or(s4[entrada],E);
							      			}if (strcmp(ent_1, "S4")==0 && strcmp(ent_2, "S3")==0)
							      			{
							      				s5[entrada]= or(s4[entrada],s3[entrada]);
							      			}
							      			if (strcmp(ent_1, "S4")==0 && strcmp(ent_2, "S2")==0)
							      			{
							      				s5[entrada]= or(s4[entrada],s2[entrada]);
							      			}
							      			if (strcmp(ent_1, "S4")==0 && strcmp(ent_2, "S1")==0)
							      			{
							      				s5[entrada]= or(s4[entrada],s1[entrada]);
							      			}
							      			      // saída
							     	
										} 
										else if (strcmp(port_ent, "AND") == 0)
										{
								      		if (strcmp(ent_1, "A")==0 && strcmp(ent_2, "B")==0){
							      				s5[entrada]= and(A,B);
							      			}else if(strcmp(ent_1, "A")==0 && strcmp(ent_2, "C")==0){
							      				s5[entrada]= and(A,C);
							      			}else if(strcmp(ent_1, "A")==0 && strcmp(ent_2, "D")==0){
							      				s5[entrada]= and(A,D);
							      			}else if (strcmp(ent_1, "A")==0 && strcmp(ent_2, "E")==0)
							      			{
							      				s5[entrada]= and(A,E);
							      			}else if(strcmp(ent_1, "B")==0 && strcmp(ent_2, "C")==0){
							      				s5[entrada]= and(B,C);
							      			}else if(strcmp(ent_1, "B")==0 && strcmp(ent_2, "D")==0){
							      				s5[entrada]= and(B,D);
							      			}else if (strcmp(ent_1, "B")==0 && strcmp(ent_2, "E")==0)
							      			{
							      				s5[entrada]= and(B,E);
							      			}else if(strcmp(ent_1, "C")==0 && strcmp(ent_2, "D")==0){
							      				s5[entrada]= and(C,D);
							      			}else if(strcmp(ent_1, "C")==0 && strcmp(ent_2, "E")==0){
							      				s5[entrada]= and(C,E);
							      			}else if(strcmp(ent_1, "D")==0 && strcmp(ent_2, "E")==0){
							      				s5[entrada]= and(D,E);
							      			}

							      			//para entradas com S1
							      			if (strcmp(ent_1, "S1")==0 && strcmp(ent_2, "A")==0)
							      			{
							      				s5[entrada]= and(s1[entrada],A);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "B")==0){
							      				s5[entrada]= and(s1[entrada],B);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "C")==0){
							      				s5[entrada]= and(s1[entrada],C);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "D")==0){
							      				s5[entrada]= and(s1[entrada],D);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "E")==0){
							      				s5[entrada]= and(s1[entrada],E);
							      			}
							      			if (strcmp(ent_1, "S2")==0 && strcmp(ent_2, "A")==0)
							      			{
							      				s5[entrada]= and(s2[entrada],A);
							      			}else if(strcmp(ent_1, "S2")==0 && strcmp(ent_2, "B")==0){
							      				s5[entrada]= and(s2[entrada],B);
							      			}else if(strcmp(ent_1, "S2")==0 && strcmp(ent_2, "C")==0){
							      				s5[entrada]= and(s2[entrada],C);
							      			}else if(strcmp(ent_1, "S2")==0 && strcmp(ent_2, "D")==0){
							      				s5[entrada]= and(s2[entrada],D);
							      			}else if(strcmp(ent_1, "S2")==0 && strcmp(ent_2, "E")==0){
							      				s5[entrada]= and(s2[entrada],E);
							      			}
							      			if (strcmp(ent_1, "S2")==0 && strcmp(ent_2, "S1")==0)
							      			{
							      				s5[entrada]= and(s2[entrada],s1[entrada]);
							      			}
							      			if (strcmp(ent_1, "S3")==0 && strcmp(ent_2, "A")==0)
							      			{
							      				s5[entrada]= and(s3[entrada],A);
							      			}else if(strcmp(ent_1, "S3")==0 && strcmp(ent_2, "B")==0){
							      				s5[entrada]= and(s3[entrada],B);
							      			}else if(strcmp(ent_1, "S3")==0 && strcmp(ent_2, "C")==0){
							      				s5[entrada]= and(s3[entrada],C);
							      			}else if(strcmp(ent_1, "S3")==0 && strcmp(ent_2, "D")==0){
							      				s5[entrada]= and(s3[entrada],D);
							      			}else if(strcmp(ent_1, "S3")==0 && strcmp(ent_2, "E")==0){
							      				s5[entrada]= and(s3[entrada],E);
							      			}
							      			if (strcmp(ent_1, "S3")==0 && strcmp(ent_2, "S1")==0)
							      			{
							      				s5[entrada]= and(s3[entrada],s1[entrada]);
							      			}if (strcmp(ent_1, "S3")==0 && strcmp(ent_2, "S2")==0){
							      				s5[entrada]= and(s3[entrada],s2[entrada]);
							      			}if (strcmp(ent_1, "S4")==0 && strcmp(ent_2, "A")==0)
							      			{
							      				s5[entrada]= and(s4[entrada],A);
							      			}else if(strcmp(ent_1, "S4")==0 && strcmp(ent_2, "B")==0){
							      				s5[entrada]= and(s4[entrada],B);
							      			}else if(strcmp(ent_1, "S4")==0 && strcmp(ent_2, "C")==0){
							      				s5[entrada]= and(s4[entrada],C);
							      			}else if(strcmp(ent_1, "S4")==0 && strcmp(ent_2, "D")==0){
							      				s5[entrada]= and(s4[entrada],D);
							      			}else if(strcmp(ent_1, "S4")==0 && strcmp(ent_2, "E")==0){
							      				s5[entrada]= and(s4[entrada],E);
							      			}if (strcmp(ent_1, "S4")==0 && strcmp(ent_2, "S3")==0)
							      			{
							      				s5[entrada]= and(s4[entrada],s3[entrada]);
							      			}
							      			if (strcmp(ent_1, "S4")==0 && strcmp(ent_2, "S2")==0)
							      			{
							      				s5[entrada]= and(s4[entrada],s2[entrada]);
							      			}
							      			if (strcmp(ent_1, "S4")==0 && strcmp(ent_2, "S1")==0)
							      			{
							      				s5[entrada]= and(s4[entrada],s1[entrada]);
							      			}
							      			      // saída
							     	
										 
										}if (strcmp(port_ent, "NOR") == 0) 
										{
											if (strcmp(ent_1, "A")==0 && strcmp(ent_2, "B")==0){
							      				s5[entrada]= nor(A,B);
							      			}else if(strcmp(ent_1, "A")==0 && strcmp(ent_2, "C")==0){
							      				s5[entrada]= nor(A,C);
							      			}else if(strcmp(ent_1, "A")==0 && strcmp(ent_2, "D")==0){
							      				s5[entrada]= nor(A,D);
							      			}else if (strcmp(ent_1, "A")==0 && strcmp(ent_2, "E")==0)
							      			{
							      				s5[entrada]= nor(A,E);
							      			}else if(strcmp(ent_1, "B")==0 && strcmp(ent_2, "C")==0){
							      				s5[entrada]= nor(B,C);
							      			}else if(strcmp(ent_1, "B")==0 && strcmp(ent_2, "D")==0){
							      				s5[entrada]= nor(B,D);
							      			}else if (strcmp(ent_1, "B")==0 && strcmp(ent_2, "E")==0)
							      			{
							      				s5[entrada]= nor(B,E);
							      			}else if(strcmp(ent_1, "C")==0 && strcmp(ent_2, "D")==0){
							      				s5[entrada]= nor(C,D);
							      			}else if(strcmp(ent_1, "C")==0 && strcmp(ent_2, "E")==0){
							      				s5[entrada]= nor(C,E);
							      			}else if(strcmp(ent_1, "D")==0 && strcmp(ent_2, "E")==0){
							      				s5[entrada]= nor(D,E);
							      			}

							      			//para entradas com S1
							      			if (strcmp(ent_1, "S1")==0 && strcmp(ent_2, "A")==0)
							      			{
							      				s5[entrada]= nor(s1[entrada],A);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "B")==0){
							      				s5[entrada]= nor(s1[entrada],B);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "C")==0){
							      				s5[entrada]= nor(s1[entrada],C);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "D")==0){
							      				s5[entrada]= nor(s1[entrada],D);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "E")==0){
							      				s5[entrada]= nor(s1[entrada],E);
							      			}
							      			if (strcmp(ent_1, "S2")==0 && strcmp(ent_2, "A")==0)
							      			{
							      				s5[entrada]= nor(s2[entrada],A);
							      			}else if(strcmp(ent_1, "S2")==0 && strcmp(ent_2, "B")==0){
							      				s5[entrada]= nor(s2[entrada],B);
							      			}else if(strcmp(ent_1, "S2")==0 && strcmp(ent_2, "C")==0){
							      				s5[entrada]= nor(s2[entrada],C);
							      			}else if(strcmp(ent_1, "S2")==0 && strcmp(ent_2, "D")==0){
							      				s5[entrada]= nor(s2[entrada],D);
							      			}else if(strcmp(ent_1, "S2")==0 && strcmp(ent_2, "E")==0){
							      				s5[entrada]= nor(s2[entrada],E);
							      			}
							      			if (strcmp(ent_1, "S2")==0 && strcmp(ent_2, "S1")==0)
							      			{
							      				s5[entrada]= nor(s2[entrada],s1[entrada]);
							      			}
							      			if (strcmp(ent_1, "S3")==0 && strcmp(ent_2, "A")==0)
							      			{
							      				s5[entrada]= nor(s3[entrada],A);
							      			}else if(strcmp(ent_1, "S3")==0 && strcmp(ent_2, "B")==0){
							      				s5[entrada]= nor(s3[entrada],B);
							      			}else if(strcmp(ent_1, "S3")==0 && strcmp(ent_2, "C")==0){
							      				s5[entrada]= nor(s3[entrada],C);
							      			}else if(strcmp(ent_1, "S3")==0 && strcmp(ent_2, "D")==0){
							      				s5[entrada]= nor(s3[entrada],D);
							      			}else if(strcmp(ent_1, "S3")==0 && strcmp(ent_2, "E")==0){
							      				s5[entrada]= nor(s3[entrada],E);
							      			}
							      			if (strcmp(ent_1, "S3")==0 && strcmp(ent_2, "S1")==0)
							      			{
							      				s5[entrada]= nor(s3[entrada],s1[entrada]);
							      			}if (strcmp(ent_1, "S3")==0 && strcmp(ent_2, "S2")==0){
							      				s5[entrada]= nor(s3[entrada],s2[entrada]);
							      			}if (strcmp(ent_1, "S4")==0 && strcmp(ent_2, "A")==0)
							      			{
							      				s5[entrada]= nor(s4[entrada],A);
							      			}else if(strcmp(ent_1, "S4")==0 && strcmp(ent_2, "B")==0){
							      				s5[entrada]= nor(s4[entrada],B);
							      			}else if(strcmp(ent_1, "S4")==0 && strcmp(ent_2, "C")==0){
							      				s5[entrada]= nor(s4[entrada],C);
							      			}else if(strcmp(ent_1, "S4")==0 && strcmp(ent_2, "D")==0){
							      				s5[entrada]= nor(s4[entrada],D);
							      			}else if(strcmp(ent_1, "S4")==0 && strcmp(ent_2, "E")==0){
							      				s5[entrada]= nor(s4[entrada],E);
							      			}if (strcmp(ent_1, "S4")==0 && strcmp(ent_2, "S3")==0)
							      			{
							      				s5[entrada]= nor(s4[entrada],s3[entrada]);
							      			}
							      			if (strcmp(ent_1, "S4")==0 && strcmp(ent_2, "S2")==0)
							      			{
							      			}
							      				s5[entrada]= nor(s4[entrada],s2[entrada]);
							      			if (strcmp(ent_1, "S4")==0 && strcmp(ent_2, "S1")==0)
							      			{
							      				s5[entrada]= nor(s4[entrada],s1[entrada]);
							      			}
							      			      // saída
										} 
										else if (strcmp(port_ent, "NAND") == 0)
										{
											if (strcmp(ent_1, "A")==0 && strcmp(ent_2, "B")==0){
							      				s5[entrada]= nand(A,B);
							      			}else if(strcmp(ent_1, "A")==0 && strcmp(ent_2, "C")==0){
							      				s5[entrada]= nand(A,C);
							      			}else if(strcmp(ent_1, "A")==0 && strcmp(ent_2, "D")==0){
							      				s5[entrada]= nand(A,D);
							      			}else if (strcmp(ent_1, "A")==0 && strcmp(ent_2, "E")==0)
							      			{
							      				s5[entrada]= nand(A,E);
							      			}else if(strcmp(ent_1, "B")==0 && strcmp(ent_2, "C")==0){
							      				s5[entrada]= nand(B,C);
							      			}else if(strcmp(ent_1, "B")==0 && strcmp(ent_2, "D")==0){
							      				s5[entrada]= nand(B,D);
							      			}else if (strcmp(ent_1, "B")==0 && strcmp(ent_2, "E")==0)
							      			{
							      				s5[entrada]= nand(B,E);
							      			}else if(strcmp(ent_1, "C")==0 && strcmp(ent_2, "D")==0){
							      				s5[entrada]= nand(C,D);
							      			}else if(strcmp(ent_1, "C")==0 && strcmp(ent_2, "E")==0){
							      				s5[entrada]= nand(C,E);
							      			}else if(strcmp(ent_1, "D")==0 && strcmp(ent_2, "E")==0){
							      				s5[entrada]= nand(D,E);
							      			}

							      			//para entradas com S1
							      			if (strcmp(ent_1, "S1")==0 && strcmp(ent_2, "A")==0)
							      			{
							      				s5[entrada]= nand(s1[entrada],A);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "B")==0){
							      				s5[entrada]= nand(s1[entrada],B);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "C")==0){
							      				s5[entrada]= nand(s1[entrada],C);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "D")==0){
							      				s5[entrada]= nand(s1[entrada],D);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "E")==0){
							      				s5[entrada]= nand(s1[entrada],E);
							      			}
							      			if (strcmp(ent_1, "S2")==0 && strcmp(ent_2, "A")==0)
							      			{
							      				s5[entrada]= nand(s2[entrada],A);
							      			}else if(strcmp(ent_1, "S2")==0 && strcmp(ent_2, "B")==0){
							      				s5[entrada]= nand(s2[entrada],B);
							      			}else if(strcmp(ent_1, "S2")==0 && strcmp(ent_2, "C")==0){
							      				s5[entrada]= nand(s2[entrada],C);
							      			}else if(strcmp(ent_1, "S2")==0 && strcmp(ent_2, "D")==0){
							      				s5[entrada]= nand(s2[entrada],D);
							      			}else if(strcmp(ent_1, "S2")==0 && strcmp(ent_2, "E")==0){
							      				s5[entrada]= nand(s2[entrada],E);
							      			}
							      			if (strcmp(ent_1, "S2")==0 && strcmp(ent_2, "S1")==0)
							      			{
							      				s5[entrada]= nand(s2[entrada],s1[entrada]);
							      			}
							      			if (strcmp(ent_1, "S3")==0 && strcmp(ent_2, "A")==0)
							      			{
							      				s5[entrada]= nand(s3[entrada],A);
							      			}else if(strcmp(ent_1, "S3")==0 && strcmp(ent_2, "B")==0){
							      				s5[entrada]= nand(s3[entrada],B);
							      			}else if(strcmp(ent_1, "S3")==0 && strcmp(ent_2, "C")==0){
							      				s5[entrada]= nand(s3[entrada],C);
							      			}else if(strcmp(ent_1, "S3")==0 && strcmp(ent_2, "D")==0){
							      				s5[entrada]= nand(s3[entrada],D);
							      			}else if(strcmp(ent_1, "S3")==0 && strcmp(ent_2, "E")==0){
							      				s5[entrada]= nand(s3[entrada],E);
							      			}
							      			if (strcmp(ent_1, "S3")==0 && strcmp(ent_2, "S1")==0)
							      			{
							      				s5[entrada]= nand(s3[entrada],s1[entrada]);
							      			}if (strcmp(ent_1, "S3")==0 && strcmp(ent_2, "S2")==0){
							      				s5[entrada]= nand(s3[entrada],s2[entrada]);
							      			}if (strcmp(ent_1, "S4")==0 && strcmp(ent_2, "A")==0)
							      			{
							      				s5[entrada]= nand(s4[entrada],A);
							      			}else if(strcmp(ent_1, "S4")==0 && strcmp(ent_2, "B")==0){
							      				s5[entrada]= nand(s4[entrada],B);
							      			}else if(strcmp(ent_1, "S4")==0 && strcmp(ent_2, "C")==0){
							      				s5[entrada]= nand(s4[entrada],C);
							      			}else if(strcmp(ent_1, "S4")==0 && strcmp(ent_2, "D")==0){
							      				s5[entrada]= nand(s4[entrada],D);
							      			}else if(strcmp(ent_1, "S4")==0 && strcmp(ent_2, "E")==0){
							      				s5[entrada]= nand(s4[entrada],E);
							      			}if (strcmp(ent_1, "S4")==0 && strcmp(ent_2, "S3")==0)
							      			{
							      				s5[entrada]= nand(s4[entrada],s3[entrada]);
							      			}
							      			if (strcmp(ent_1, "S4")==0 && strcmp(ent_2, "S2")==0)
							      			{
							      				s5[entrada]= nand(s4[entrada],s2[entrada]);
							      			}
							      				
							      			if (strcmp(ent_1, "S4")==0 && strcmp(ent_2, "S1")==0)
							      			{
							      				s5[entrada]= nand(s4[entrada],s1[entrada]);
							      			}
							      			      // saída
										}if (strcmp(port_ent, "XOR") == 0) 
										{
								      		if (strcmp(ent_1, "A")==0 && strcmp(ent_2, "B")==0){
							      				s5[entrada]= xor(A,B);
							      			}else if(strcmp(ent_1, "A")==0 && strcmp(ent_2, "C")==0){
							      				s5[entrada]= xor(A,C);
							      			}else if(strcmp(ent_1, "A")==0 && strcmp(ent_2, "D")==0){
							      				s5[entrada]= xor(A,D);
							      			}else if (strcmp(ent_1, "A")==0 && strcmp(ent_2, "E")==0)
							      			{
							      				s5[entrada]= xor(A,E);
							      			}else if(strcmp(ent_1, "B")==0 && strcmp(ent_2, "C")==0){
							      				s5[entrada]= xor(B,C);
							      			}else if(strcmp(ent_1, "B")==0 && strcmp(ent_2, "D")==0){
							      				s5[entrada]= xor(B,D);
							      			}else if (strcmp(ent_1, "B")==0 && strcmp(ent_2, "E")==0)
							      			{
							      				s5[entrada]= xor(B,E);
							      			}else if(strcmp(ent_1, "C")==0 && strcmp(ent_2, "D")==0){
							      				s5[entrada]= xor(C,D);
							      			}else if(strcmp(ent_1, "C")==0 && strcmp(ent_2, "E")==0){
							      				s5[entrada]= xor(C,E);
							      			}else if(strcmp(ent_1, "D")==0 && strcmp(ent_2, "E")==0){
							      				s5[entrada]= xor(D,E);
							      			}

							      			//para entradas com S1
							      			if (strcmp(ent_1, "S1")==0 && strcmp(ent_2, "A")==0)
							      			{
							      				s5[entrada]= xor(s1[entrada],A);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "B")==0){
							      				s5[entrada]= xor(s1[entrada],B);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "C")==0){
							      				s5[entrada]= xor(s1[entrada],C);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "D")==0){
							      				s5[entrada]= xor(s1[entrada],D);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "E")==0){
							      				s5[entrada]= xor(s1[entrada],E);
							      			}
							      			if (strcmp(ent_1, "S2")==0 && strcmp(ent_2, "A")==0)
							      			{
							      				s5[entrada]= xor(s2[entrada],A);
							      			}else if(strcmp(ent_1, "S2")==0 && strcmp(ent_2, "B")==0){
							      				s5[entrada]= xor(s2[entrada],B);
							      			}else if(strcmp(ent_1, "S2")==0 && strcmp(ent_2, "C")==0){
							      				s5[entrada]= xor(s2[entrada],C);
							      			}else if(strcmp(ent_1, "S2")==0 && strcmp(ent_2, "D")==0){
							      				s5[entrada]= xor(s2[entrada],D);
							      			}else if(strcmp(ent_1, "S2")==0 && strcmp(ent_2, "E")==0){
							      				s5[entrada]= xor(s2[entrada],E);
							      			}
							      			if (strcmp(ent_1, "S2")==0 && strcmp(ent_2, "S1")==0)
							      			{
							      				s5[entrada]= xor(s2[entrada],s1[entrada]);
							      			}
							      			if (strcmp(ent_1, "S3")==0 && strcmp(ent_2, "A")==0)
							      			{
							      				s5[entrada]= xor(s3[entrada],A);
							      			}else if(strcmp(ent_1, "S3")==0 && strcmp(ent_2, "B")==0){
							      				s5[entrada]= xor(s3[entrada],B);
							      			}else if(strcmp(ent_1, "S3")==0 && strcmp(ent_2, "C")==0){
							      				s5[entrada]= xor(s3[entrada],C);
							      			}else if(strcmp(ent_1, "S3")==0 && strcmp(ent_2, "D")==0){
							      				s5[entrada]= xor(s3[entrada],D);
							      			}else if(strcmp(ent_1, "S3")==0 && strcmp(ent_2, "E")==0){
							      				s5[entrada]= xor(s3[entrada],E);
							      			}
							      			if (strcmp(ent_1, "S3")==0 && strcmp(ent_2, "S1")==0)
							      			{
							      				s5[entrada]= xor(s3[entrada],s1[entrada]);
							      			}if (strcmp(ent_1, "S3")==0 && strcmp(ent_2, "S2")==0){
							      				s5[entrada]= xor(s3[entrada],s2[entrada]);
							      			}if (strcmp(ent_1, "S4")==0 && strcmp(ent_2, "A")==0)
							      			{
							      				s5[entrada]= xor(s4[entrada],A);
							      			}else if(strcmp(ent_1, "S4")==0 && strcmp(ent_2, "B")==0){
							      				s5[entrada]= xor(s4[entrada],B);
							      			}else if(strcmp(ent_1, "S4")==0 && strcmp(ent_2, "C")==0){
							      				s5[entrada]= xor(s4[entrada],C);
							      			}else if(strcmp(ent_1, "S4")==0 && strcmp(ent_2, "D")==0){
							      				s5[entrada]= xor(s4[entrada],D);
							      			}else if(strcmp(ent_1, "S4")==0 && strcmp(ent_2, "E")==0){
							      				s5[entrada]= xor(s4[entrada],E);
							      			}if (strcmp(ent_1, "S4")==0 && strcmp(ent_2, "S3")==0)
							      			{
							      				s5[entrada]= xor(s4[entrada],s3[entrada]);
							      			}
							      			if (strcmp(ent_1, "S4")==0 && strcmp(ent_2, "S2")==0)
							      			{
							      				s5[entrada]= xor(s4[entrada],s2[entrada]);
							      			}
							      				
							      			if (strcmp(ent_1, "S4")==0 && strcmp(ent_2, "S1")==0)
							      			{
							      				s5[entrada]= xor(s4[entrada],s1[entrada]);
							      			}
							      			
										} 
										else if (strcmp(port_ent, "XNOR") == 0)
										{
								      		if (strcmp(ent_1, "A")==0 && strcmp(ent_2, "B")==0){
							      				s5[entrada]= xnor(A,B);
							      			}else if(strcmp(ent_1, "A")==0 && strcmp(ent_2, "C")==0){
							      				s5[entrada]= xnor(A,C);
							      			}else if(strcmp(ent_1, "A")==0 && strcmp(ent_2, "D")==0){
							      				s5[entrada]= xnor(A,D);
							      			}else if (strcmp(ent_1, "A")==0 && strcmp(ent_2, "E")==0)
							      			{
							      				s5[entrada]= xnor(A,E);
							      			}else if(strcmp(ent_1, "B")==0 && strcmp(ent_2, "C")==0){
							      				s5[entrada]= xnor(B,C);
							      			}else if(strcmp(ent_1, "B")==0 && strcmp(ent_2, "D")==0){
							      				s5[entrada]= xnor(B,D);
							      			}else if (strcmp(ent_1, "B")==0 && strcmp(ent_2, "E")==0)
							      			{
							      				s5[entrada]= xnor(B,E);
							      			}else if(strcmp(ent_1, "C")==0 && strcmp(ent_2, "D")==0){
							      				s5[entrada]= xnor(C,D);
							      			}else if(strcmp(ent_1, "C")==0 && strcmp(ent_2, "E")==0){
							      				s5[entrada]= xnor(C,E);
							      			}else if(strcmp(ent_1, "D")==0 && strcmp(ent_2, "E")==0){
							      				s5[entrada]= xnor(D,E);
							      			}

							      			//para entradas com S1
							      			if (strcmp(ent_1, "S1")==0 && strcmp(ent_2, "A")==0)
							      			{
							      				s5[entrada]= xnor(s1[entrada],A);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "B")==0){
							      				s5[entrada]= xnor(s1[entrada],B);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "C")==0){
							      				s5[entrada]= xnor(s1[entrada],C);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "D")==0){
							      				s5[entrada]= xnor(s1[entrada],D);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "E")==0){
							      				s5[entrada]= xnor(s1[entrada],E);
							      			}
							      			if (strcmp(ent_1, "S2")==0 && strcmp(ent_2, "A")==0)
							      			{
							      				s5[entrada]= xnor(s2[entrada],A);
							      			}else if(strcmp(ent_1, "S2")==0 && strcmp(ent_2, "B")==0){
							      				s5[entrada]= xnor(s2[entrada],B);
							      			}else if(strcmp(ent_1, "S2")==0 && strcmp(ent_2, "C")==0){
							      				s5[entrada]= xnor(s2[entrada],C);
							      			}else if(strcmp(ent_1, "S2")==0 && strcmp(ent_2, "D")==0){
							      				s5[entrada]= xnor(s2[entrada],D);
							      			}else if(strcmp(ent_1, "S2")==0 && strcmp(ent_2, "E")==0){
							      				s5[entrada]= xnor(s2[entrada],E);
							      			}
							      			if (strcmp(ent_1, "S2")==0 && strcmp(ent_2, "S1")==0)
							      			{
							      				s5[entrada]= xnor(s2[entrada],s1[entrada]);
							      			}
							      			if (strcmp(ent_1, "S3")==0 && strcmp(ent_2, "A")==0)
							      			{
							      				s5[entrada]= xnor(s3[entrada],A);
							      			}else if(strcmp(ent_1, "S3")==0 && strcmp(ent_2, "B")==0){
							      				s5[entrada]= xnor(s3[entrada],B);
							      			}else if(strcmp(ent_1, "S3")==0 && strcmp(ent_2, "C")==0){
							      				s5[entrada]= xnor(s3[entrada],C);
							      			}else if(strcmp(ent_1, "S3")==0 && strcmp(ent_2, "D")==0){
							      				s5[entrada]= xnor(s3[entrada],D);
							      			}else if(strcmp(ent_1, "S3")==0 && strcmp(ent_2, "E")==0){
							      				s5[entrada]= xnor(s3[entrada],E);
							      			}
							      			if (strcmp(ent_1, "S3")==0 && strcmp(ent_2, "S1")==0)
							      			{
							      				s5[entrada]= xnor(s3[entrada],s1[entrada]);
							      			}if (strcmp(ent_1, "S3")==0 && strcmp(ent_2, "S2")==0){
							      				s5[entrada]= xnor(s3[entrada],s2[entrada]);
							      			}if (strcmp(ent_1, "S4")==0 && strcmp(ent_2, "A")==0)
							      			{
							      				s5[entrada]= xnor(s4[entrada],A);
							      			}else if(strcmp(ent_1, "S4")==0 && strcmp(ent_2, "B")==0){
							      				s5[entrada]= xnor(s4[entrada],B);
							      			}else if(strcmp(ent_1, "S4")==0 && strcmp(ent_2, "C")==0){
							      				s5[entrada]= xnor(s4[entrada],C);
							      			}else if(strcmp(ent_1, "S4")==0 && strcmp(ent_2, "D")==0){
							      				s5[entrada]= xnor(s4[entrada],D);
							      			}else if(strcmp(ent_1, "S4")==0 && strcmp(ent_2, "E")==0){
							      				s5[entrada]= xnor(s4[entrada],E);
							      			}if (strcmp(ent_1, "S4")==0 && strcmp(ent_2, "S3")==0)
							      			{
							      				s5[entrada]= xnor(s4[entrada],s3[entrada]);
							      			}
							      			if (strcmp(ent_1, "S4")==0 && strcmp(ent_2, "S2")==0)
							      			{
							      				s5[entrada]= xnor(s4[entrada],s2[entrada]);
							      			}
							      				
							      			if (strcmp(ent_1, "S4")==0 && strcmp(ent_2, "S1")==0)
							      			{
							      				s5[entrada]= xnor(s4[entrada],s1[entrada]);
							      			}
							      			
										}if (strcmp(port_ent, "NOT") == 0)
										{
								      		if (strcmp(ent_1, "A")==0 )
							      			{
							      				s5[entrada]= not(A);
							      			}else if(strcmp(ent_1, "B")==0){
							      				s5[entrada]= not(B);
							      			}else if(strcmp(ent_1, "C")==0){
							      				s5[entrada]= not(C);
							      			}else if (strcmp(ent_1, "D")==0 ){
							      				s5[entrada]= not(D);
							      			}else if(strcmp(ent_1, "E")==0 ){
							      				s5[entrada]= not(E);
							      			}
							      			//para entradas com S1
							      			if (strcmp(ent_1, "S1")==0)
							      			{
							      				s5[entrada]= not(s1[entrada]);
							      			}else if (strcmp(ent_1, "S2")==0)
							      			{
							      				s5[entrada]= not(s2[entrada]);
							      			}else if (strcmp(ent_1, "S3")==0)
							      			{
							      				s5[entrada]= not(s3[entrada]);
							      			}else if (strcmp(ent_1, "S4")==0)
							      			{
							      				s5[entrada]= not(s4[entrada]);
							      			}
								      		
									}
								
								//prende s5
										if (strcmp(fixa1, "S5")==0 && strcmp(fixa0, "0")==0)
										{
											s5[entrada]=0;
										}else if (strcmp(fixa1, "S5")==0 && strcmp(fixa0, "1")==0)
										{
											s5[entrada]=1;
										}if (strcmp(fixa3, "S5")==0 && strcmp(fixa4, "0")==0)
										{
											s5[entrada]=0;
										}else if (strcmp(fixa3, "S5")==0 && strcmp(fixa4, "1")==0)
										{
											s5[entrada]=1;
										}		

								}
				 						 
							} 

							if (strcmp(saidas1, "S6") == 0) 
							{
								for(entrada = 0; entrada < k ; entrada++) {
									  	A = (entrada & 1)?A1:A2; 
										B = (entrada & 2)?B1:B2;  
										C = (entrada & 4)?C1:C2;  
										D = (entrada & 8)?D1:D2;
										E = (entrada & 16)?E1:E2;
							      		if (strcmp(port_ent, "OR") == 0) {	
											if (strcmp(ent_1, "A")==0 && strcmp(ent_2, "B")==0){
							      				s6[entrada]= or(A,B);
							      			}else if(strcmp(ent_1, "A")==0 && strcmp(ent_2, "C")==0){
							      				s6[entrada]= or(A,C);
							      			}else if(strcmp(ent_1, "A")==0 && strcmp(ent_2, "D")==0){
							      				s6[entrada]= or(A,D);
							      			}else if (strcmp(ent_1, "A")==0 && strcmp(ent_2, "E")==0)
							      			{
							      				s6[entrada]= or(A,E);
							      			}else if(strcmp(ent_1, "B")==0 && strcmp(ent_2, "C")==0){
							      				s6[entrada]= or(B,C);
							      			}else if(strcmp(ent_1, "B")==0 && strcmp(ent_2, "D")==0){
							      				s6[entrada]= or(B,D);
							      			}else if (strcmp(ent_1, "B")==0 && strcmp(ent_2, "E")==0)
							      			{
							      				s6[entrada]= or(B,E);
							      			}else if(strcmp(ent_1, "C")==0 && strcmp(ent_2, "D")==0){
							      				s6[entrada]= or(C,D);
							      			}else if(strcmp(ent_1, "C")==0 && strcmp(ent_2, "E")==0){
							      				s6[entrada]= or(C,E);
							      			}else if(strcmp(ent_1, "D")==0 && strcmp(ent_2, "E")==0){
							      				s6[entrada]= or(D,E);
							      			}

							      			//para entradas com S1
							      			if (strcmp(ent_1, "S1")==0 && strcmp(ent_2, "A")==0)
							      			{
							      				s6[entrada]= or(s1[entrada],A);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "B")==0){
							      				s6[entrada]= or(s1[entrada],B);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "C")==0){
							      				s6[entrada]= or(s1[entrada],C);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "D")==0){
							      				s6[entrada]= or(s1[entrada],D);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "E")==0){
							      				s6[entrada]= or(s1[entrada],E);
							      			}
							      			if (strcmp(ent_1, "S2")==0 && strcmp(ent_2, "A")==0)
							      			{
							      				s6[entrada]= or(s2[entrada],A);
							      			}else if(strcmp(ent_1, "S2")==0 && strcmp(ent_2, "B")==0){
							      				s6[entrada]= or(s2[entrada],B);
							      			}else if(strcmp(ent_1, "S2")==0 && strcmp(ent_2, "C")==0){
							      				s6[entrada]= or(s2[entrada],C);
							      			}else if(strcmp(ent_1, "S2")==0 && strcmp(ent_2, "D")==0){
							      				s6[entrada]= or(s2[entrada],D);
							      			}else if(strcmp(ent_1, "S2")==0 && strcmp(ent_2, "E")==0){
							      				s6[entrada]= or(s2[entrada],E);
							      			}
							      			if (strcmp(ent_1, "S2")==0 && strcmp(ent_2, "S1")==0)
							      			{
							      				s6[entrada]= or(s2[entrada],s1[entrada]);
							      			}
							      			if (strcmp(ent_1, "S3")==0 && strcmp(ent_2, "A")==0)
							      			{
							      				s6[entrada]= or(s3[entrada],A);
							      			}else if(strcmp(ent_1, "S3")==0 && strcmp(ent_2, "B")==0){
							      				s6[entrada]= or(s3[entrada],B);
							      			}else if(strcmp(ent_1, "S3")==0 && strcmp(ent_2, "C")==0){
							      				s6[entrada]= or(s3[entrada],C);
							      			}else if(strcmp(ent_1, "S3")==0 && strcmp(ent_2, "D")==0){
							      				s6[entrada]= or(s3[entrada],D);
							      			}else if(strcmp(ent_1, "S3")==0 && strcmp(ent_2, "E")==0){
							      				s6[entrada]= or(s3[entrada],E);
							      			}
							      			if (strcmp(ent_1, "S3")==0 && strcmp(ent_2, "S1")==0)
							      			{
							      				s6[entrada]= or(s3[entrada],s1[entrada]);
							      			}if (strcmp(ent_1, "S3")==0 && strcmp(ent_2, "S2")==0){
							      				s6[entrada]= or(s3[entrada],s2[entrada]);
							      			}if (strcmp(ent_1, "S4")==0 && strcmp(ent_2, "A")==0)
							      			{
							      				s6[entrada]= or(s4[entrada],A);
							      			}else if(strcmp(ent_1, "S4")==0 && strcmp(ent_2, "B")==0){
							      				s6[entrada]= or(s4[entrada],B);
							      			}else if(strcmp(ent_1, "S4")==0 && strcmp(ent_2, "C")==0){
							      				s6[entrada]= or(s4[entrada],C);
							      			}else if(strcmp(ent_1, "S4")==0 && strcmp(ent_2, "D")==0){
							      				s6[entrada]= or(s4[entrada],D);
							      			}else if(strcmp(ent_1, "S4")==0 && strcmp(ent_2, "E")==0){
							      				s6[entrada]= or(s4[entrada],E);
							      			}if (strcmp(ent_1, "S4")==0 && strcmp(ent_2, "S3")==0)
							      			{
							      				s6[entrada]= or(s4[entrada],s3[entrada]);
							      			}
							      			if (strcmp(ent_1, "S4")==0 && strcmp(ent_2, "S2")==0)
							      			{
							      				s6[entrada]= or(s4[entrada],s2[entrada]);
							      			}
							      			if (strcmp(ent_1, "S4")==0 && strcmp(ent_2, "S1")==0){
							      				s6[entrada]= or(s4[entrada],s1[entrada]);
							      			}
							      			if (strcmp(ent_1, "S5")==0 && strcmp(ent_2, "A")==0)
							      			{
							      				s6[entrada]= or(s5[entrada],A);
							      			}else if(strcmp(ent_1, "S5")==0 && strcmp(ent_2, "B")==0){
							      				s6[entrada]= or(s5[entrada],B);
							      			}else if(strcmp(ent_1, "S5")==0 && strcmp(ent_2, "C")==0){
							      				s6[entrada]= or(s5[entrada],C);
							      			}else if(strcmp(ent_1, "S5")==0 && strcmp(ent_2, "D")==0){
							      				s6[entrada]= or(s5[entrada],D);
							      			}else if(strcmp(ent_1, "S5")==0 && strcmp(ent_2, "E")==0){
							      				s6[entrada]= or(s5[entrada],E);
							      			}if (strcmp(ent_1, "S5")==0 && strcmp(ent_2, "S3")==0)
							      			{
							      				s6[entrada]= or(s5[entrada],s3[entrada]);
							      			}
							      			if (strcmp(ent_1, "S5")==0 && strcmp(ent_2, "S2")==0)
							      			{
							      				s6[entrada]= or(s5[entrada],s2[entrada]);
							      			}
							      			if (strcmp(ent_1, "S5")==0 && strcmp(ent_2, "S1")==0)
							      			{
							      				s6[entrada]= or(s5[entrada],s1[entrada]);
							      			}if (strcmp(ent_1, "S5")==0 && strcmp(ent_2, "S4")==0)
							      			{
							      				s6[entrada]= or(s5[entrada],s4[entrada]);
							      			}      // saída
							     	
										} 
										else if (strcmp(port_ent, "AND") == 0)
										{
								      		if (strcmp(ent_1, "A")==0 && strcmp(ent_2, "B")==0){
							      				s6[entrada]= and(A,B);
							      			}else if(strcmp(ent_1, "A")==0 && strcmp(ent_2, "C")==0){
							      				s6[entrada]= and(A,C);
							      			}else if(strcmp(ent_1, "A")==0 && strcmp(ent_2, "D")==0){
							      				s6[entrada]= and(A,D);
							      			}else if (strcmp(ent_1, "A")==0 && strcmp(ent_2, "E")==0)
							      			{
							      				s6[entrada]= and(A,E);
							      			}else if(strcmp(ent_1, "B")==0 && strcmp(ent_2, "C")==0){
							      				s6[entrada]= and(B,C);
							      			}else if(strcmp(ent_1, "B")==0 && strcmp(ent_2, "D")==0){
							      				s6[entrada]= and(B,D);
							      			}else if (strcmp(ent_1, "B")==0 && strcmp(ent_2, "E")==0)
							      			{
							      				s6[entrada]= and(B,E);
							      			}else if(strcmp(ent_1, "C")==0 && strcmp(ent_2, "D")==0){
							      				s6[entrada]= and(C,D);
							      			}else if(strcmp(ent_1, "C")==0 && strcmp(ent_2, "E")==0){
							      				s6[entrada]= and(C,E);
							      			}else if(strcmp(ent_1, "D")==0 && strcmp(ent_2, "E")==0){
							      				s6[entrada]= and(D,E);
							      			}

							      			//para entradas com S1
							      			if (strcmp(ent_1, "S1")==0 && strcmp(ent_2, "A")==0)
							      			{
							      				s6[entrada]= and(s1[entrada],A);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "B")==0){
							      				s6[entrada]= and(s1[entrada],B);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "C")==0){
							      				s6[entrada]= and(s1[entrada],C);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "D")==0){
							      				s6[entrada]= and(s1[entrada],D);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "E")==0){
							      				s6[entrada]= and(s1[entrada],E);
							      			}
							      			if (strcmp(ent_1, "S2")==0 && strcmp(ent_2, "A")==0)
							      			{
							      				s6[entrada]= and(s2[entrada],A);
							      			}else if(strcmp(ent_1, "S2")==0 && strcmp(ent_2, "B")==0){
							      				s6[entrada]= and(s2[entrada],B);
							      			}else if(strcmp(ent_1, "S2")==0 && strcmp(ent_2, "C")==0){
							      				s6[entrada]= and(s2[entrada],C);
							      			}else if(strcmp(ent_1, "S2")==0 && strcmp(ent_2, "D")==0){
							      				s6[entrada]= and(s2[entrada],D);
							      			}else if(strcmp(ent_1, "S2")==0 && strcmp(ent_2, "E")==0){
							      				s6[entrada]= and(s2[entrada],E);
							      			}
							      			if (strcmp(ent_1, "S2")==0 && strcmp(ent_2, "S1")==0)
							      			{
							      				s6[entrada]= and(s2[entrada],s1[entrada]);
							      			}
							      			if (strcmp(ent_1, "S3")==0 && strcmp(ent_2, "A")==0)
							      			{
							      				s6[entrada]= and(s3[entrada],A);
							      			}else if(strcmp(ent_1, "S3")==0 && strcmp(ent_2, "B")==0){
							      				s6[entrada]= and(s3[entrada],B);
							      			}else if(strcmp(ent_1, "S3")==0 && strcmp(ent_2, "C")==0){
							      				s6[entrada]= and(s3[entrada],C);
							      			}else if(strcmp(ent_1, "S3")==0 && strcmp(ent_2, "D")==0){
							      				s6[entrada]= and(s3[entrada],D);
							      			}else if(strcmp(ent_1, "S3")==0 && strcmp(ent_2, "E")==0){
							      				s6[entrada]= and(s3[entrada],E);
							      			}
							      			if (strcmp(ent_1, "S3")==0 && strcmp(ent_2, "S1")==0)
							      			{
							      				s6[entrada]= and(s3[entrada],s1[entrada]);
							      			}if (strcmp(ent_1, "S3")==0 && strcmp(ent_2, "S2")==0){
							      				s6[entrada]= and(s3[entrada],s2[entrada]);
							      			}if (strcmp(ent_1, "S4")==0 && strcmp(ent_2, "A")==0)
							      			{
							      				s6[entrada]= and(s4[entrada],A);
							      			}else if(strcmp(ent_1, "S4")==0 && strcmp(ent_2, "B")==0){
							      				s6[entrada]= and(s4[entrada],B);
							      			}else if(strcmp(ent_1, "S4")==0 && strcmp(ent_2, "C")==0){
							      				s6[entrada]= and(s4[entrada],C);
							      			}else if(strcmp(ent_1, "S4")==0 && strcmp(ent_2, "D")==0){
							      				s6[entrada]= and(s4[entrada],D);
							      			}else if(strcmp(ent_1, "S4")==0 && strcmp(ent_2, "E")==0){
							      				s6[entrada]= and(s4[entrada],E);
							      			}if (strcmp(ent_1, "S4")==0 && strcmp(ent_2, "S3")==0)
							      			{
							      				s6[entrada]= and(s4[entrada],s3[entrada]);
							      			}
							      			if (strcmp(ent_1, "S4")==0 && strcmp(ent_2, "S2")==0)
							      			{
							      				s6[entrada]= and(s4[entrada],s2[entrada]);
							      			}
							      			if (strcmp(ent_1, "S4")==0 && strcmp(ent_2, "S1")==0){
							      				s6[entrada]= and(s4[entrada],s1[entrada]);
							      			}
							      			if (strcmp(ent_1, "S5")==0 && strcmp(ent_2, "A")==0)
							      			{
							      				s6[entrada]= and(s5[entrada],A);
							      			}else if(strcmp(ent_1, "S5")==0 && strcmp(ent_2, "B")==0){
							      				s6[entrada]= and(s5[entrada],B);
							      			}else if(strcmp(ent_1, "S5")==0 && strcmp(ent_2, "C")==0){
							      				s6[entrada]= and(s5[entrada],C);
							      			}else if(strcmp(ent_1, "S5")==0 && strcmp(ent_2, "D")==0){
							      				s6[entrada]= and(s5[entrada],D);
							      			}else if(strcmp(ent_1, "S5")==0 && strcmp(ent_2, "E")==0){
							      				s6[entrada]= and(s5[entrada],E);
							      			}if (strcmp(ent_1, "S5")==0 && strcmp(ent_2, "S3")==0)
							      			{
							      				s6[entrada]= and(s5[entrada],s3[entrada]);
							      			}
							      			if (strcmp(ent_1, "S5")==0 && strcmp(ent_2, "S2")==0)
							      			{
							      				s6[entrada]= and(s5[entrada],s2[entrada]);
							      			}
							      			if (strcmp(ent_1, "S5")==0 && strcmp(ent_2, "S1")==0)
							      			{
							      				s6[entrada]= and(s5[entrada],s1[entrada]);
							      			}if (strcmp(ent_1, "S5")==0 && strcmp(ent_2, "S4")==0)
							      			{
							      				s6[entrada]= and(s5[entrada],s4[entrada]);
							      			}   
										}if (strcmp(port_ent, "NOR") == 0) 
										{
											if (strcmp(ent_1, "A")==0 && strcmp(ent_2, "B")==0){
							      				s6[entrada]= nor(A,B);
							      			}else if(strcmp(ent_1, "A")==0 && strcmp(ent_2, "C")==0){
							      				s6[entrada]= nor(A,C);
							      			}else if(strcmp(ent_1, "A")==0 && strcmp(ent_2, "D")==0){
							      				s6[entrada]= nor(A,D);
							      			}else if (strcmp(ent_1, "A")==0 && strcmp(ent_2, "E")==0)
							      			{
							      				s6[entrada]= nor(A,E);
							      			}else if(strcmp(ent_1, "B")==0 && strcmp(ent_2, "C")==0){
							      				s6[entrada]= nor(B,C);
							      			}else if(strcmp(ent_1, "B")==0 && strcmp(ent_2, "D")==0){
							      				s6[entrada]= nor(B,D);
							      			}else if (strcmp(ent_1, "B")==0 && strcmp(ent_2, "E")==0)
							      			{
							      				s6[entrada]= nor(B,E);
							      			}else if(strcmp(ent_1, "C")==0 && strcmp(ent_2, "D")==0){
							      				s6[entrada]= nor(C,D);
							      			}else if(strcmp(ent_1, "C")==0 && strcmp(ent_2, "E")==0){
							      				s6[entrada]= nor(C,E);
							      			}else if(strcmp(ent_1, "D")==0 && strcmp(ent_2, "E")==0){
							      				s6[entrada]= nor(D,E);
							      			}

							      			//para entradas com S1
							      			if (strcmp(ent_1, "S1")==0 && strcmp(ent_2, "A")==0)
							      			{
							      				s6[entrada]= nor(s1[entrada],A);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "B")==0){
							      				s6[entrada]= nor(s1[entrada],B);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "C")==0){
							      				s6[entrada]= nor(s1[entrada],C);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "D")==0){
							      				s6[entrada]= nor(s1[entrada],D);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "E")==0){
							      				s6[entrada]= nor(s1[entrada],E);
							      			}
							      			if (strcmp(ent_1, "S2")==0 && strcmp(ent_2, "A")==0)
							      			{
							      				s6[entrada]= nor(s2[entrada],A);
							      			}else if(strcmp(ent_1, "S2")==0 && strcmp(ent_2, "B")==0){
							      				s6[entrada]= nor(s2[entrada],B);
							      			}else if(strcmp(ent_1, "S2")==0 && strcmp(ent_2, "C")==0){
							      				s6[entrada]= nor(s2[entrada],C);
							      			}else if(strcmp(ent_1, "S2")==0 && strcmp(ent_2, "D")==0){
							      				s6[entrada]= nor(s2[entrada],D);
							      			}else if(strcmp(ent_1, "S2")==0 && strcmp(ent_2, "E")==0){
							      				s6[entrada]= nor(s2[entrada],E);
							      			}
							      			if (strcmp(ent_1, "S2")==0 && strcmp(ent_2, "S1")==0)
							      			{
							      				s6[entrada]= nor(s2[entrada],s1[entrada]);
							      			}
							      			if (strcmp(ent_1, "S3")==0 && strcmp(ent_2, "A")==0)
							      			{
							      				s6[entrada]= nor(s3[entrada],A);
							      			}else if(strcmp(ent_1, "S3")==0 && strcmp(ent_2, "B")==0){
							      				s6[entrada]= nor(s3[entrada],B);
							      			}else if(strcmp(ent_1, "S3")==0 && strcmp(ent_2, "C")==0){
							      				s6[entrada]= nor(s3[entrada],C);
							      			}else if(strcmp(ent_1, "S3")==0 && strcmp(ent_2, "D")==0){
							      				s6[entrada]= nor(s3[entrada],D);
							      			}else if(strcmp(ent_1, "S3")==0 && strcmp(ent_2, "E")==0){
							      				s6[entrada]= nor(s3[entrada],E);
							      			}
							      			if (strcmp(ent_1, "S3")==0 && strcmp(ent_2, "S1")==0)
							      			{
							      				s6[entrada]= nor(s3[entrada],s1[entrada]);
							      			}if (strcmp(ent_1, "S3")==0 && strcmp(ent_2, "S2")==0){
							      				s6[entrada]= nor(s3[entrada],s2[entrada]);
							      			}if (strcmp(ent_1, "S4")==0 && strcmp(ent_2, "A")==0)
							      			{
							      				s6[entrada]= nor(s4[entrada],A);
							      			}else if(strcmp(ent_1, "S4")==0 && strcmp(ent_2, "B")==0){
							      				s6[entrada]= nor(s4[entrada],B);
							      			}else if(strcmp(ent_1, "S4")==0 && strcmp(ent_2, "C")==0){
							      				s6[entrada]= nor(s4[entrada],C);
							      			}else if(strcmp(ent_1, "S4")==0 && strcmp(ent_2, "D")==0){
							      				s6[entrada]= nor(s4[entrada],D);
							      			}else if(strcmp(ent_1, "S4")==0 && strcmp(ent_2, "E")==0){
							      				s6[entrada]= nor(s4[entrada],E);
							      			}if (strcmp(ent_1, "S4")==0 && strcmp(ent_2, "S3")==0)
							      			{
							      				s6[entrada]= nor(s4[entrada],s3[entrada]);
							      			}
							      			if (strcmp(ent_1, "S4")==0 && strcmp(ent_2, "S2")==0)
							      			{
							      				s6[entrada]= nor(s4[entrada],s2[entrada]);
							      			}
							      			if (strcmp(ent_1, "S4")==0 && strcmp(ent_2, "S1")==0){
							      				s6[entrada]= nor(s4[entrada],s1[entrada]);
							      			}
							      			if (strcmp(ent_1, "S5")==0 && strcmp(ent_2, "A")==0)
							      			{
							      				s6[entrada]= nor(s5[entrada],A);
							      			}else if(strcmp(ent_1, "S5")==0 && strcmp(ent_2, "B")==0){
							      				s6[entrada]= nor(s5[entrada],B);
							      			}else if(strcmp(ent_1, "S5")==0 && strcmp(ent_2, "C")==0){
							      				s6[entrada]= nor(s5[entrada],C);
							      			}else if(strcmp(ent_1, "S5")==0 && strcmp(ent_2, "D")==0){
							      				s6[entrada]= nor(s5[entrada],D);
							      			}else if(strcmp(ent_1, "S5")==0 && strcmp(ent_2, "E")==0){
							      				s6[entrada]= nor(s5[entrada],E);
							      			}if (strcmp(ent_1, "S5")==0 && strcmp(ent_2, "S3")==0)
							      			{
							      				s6[entrada]= nor(s5[entrada],s3[entrada]);
							      			}
							      			if (strcmp(ent_1, "S5")==0 && strcmp(ent_2, "S2")==0)
							      			{
							      				s6[entrada]= nor(s5[entrada],s2[entrada]);
							      			}
							      			if (strcmp(ent_1, "S5")==0 && strcmp(ent_2, "S1")==0)
							      			{
							      				s6[entrada]= nor(s5[entrada],s1[entrada]);
							      			}if (strcmp(ent_1, "S5")==0 && strcmp(ent_2, "S4")==0)
							      			{
							      				s6[entrada]= nor(s5[entrada],s4[entrada]);
							      			}     // saída
										} 
										else if (strcmp(port_ent, "NAND") == 0)
										{
											if (strcmp(ent_1, "A")==0 && strcmp(ent_2, "B")==0){
							      				s6[entrada]= nand(A,B);
							      			}else if(strcmp(ent_1, "A")==0 && strcmp(ent_2, "C")==0){
							      				s6[entrada]= nand(A,C);
							      			}else if(strcmp(ent_1, "A")==0 && strcmp(ent_2, "D")==0){
							      				s6[entrada]= nand(A,D);
							      			}else if (strcmp(ent_1, "A")==0 && strcmp(ent_2, "E")==0)
							      			{
							      				s6[entrada]= nand(A,E);
							      			}else if(strcmp(ent_1, "B")==0 && strcmp(ent_2, "C")==0){
							      				s6[entrada]= nand(B,C);
							      			}else if(strcmp(ent_1, "B")==0 && strcmp(ent_2, "D")==0){
							      				s6[entrada]= nand(B,D);
							      			}else if (strcmp(ent_1, "B")==0 && strcmp(ent_2, "E")==0)
							      			{
							      				s6[entrada]= nand(B,E);
							      			}else if(strcmp(ent_1, "C")==0 && strcmp(ent_2, "D")==0){
							      				s6[entrada]= nand(C,D);
							      			}else if(strcmp(ent_1, "C")==0 && strcmp(ent_2, "E")==0){
							      				s6[entrada]= nand(C,E);
							      			}else if(strcmp(ent_1, "D")==0 && strcmp(ent_2, "E")==0){
							      				s6[entrada]= nand(D,E);
							      			}

							      			//para entradas com S1
							      			if (strcmp(ent_1, "S1")==0 && strcmp(ent_2, "A")==0)
							      			{
							      				s6[entrada]= nand(s1[entrada],A);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "B")==0){
							      				s6[entrada]= nand(s1[entrada],B);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "C")==0){
							      				s6[entrada]= nand(s1[entrada],C);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "D")==0){
							      				s6[entrada]= nand(s1[entrada],D);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "E")==0){
							      				s6[entrada]= nand(s1[entrada],E);
							      			}
							      			if (strcmp(ent_1, "S2")==0 && strcmp(ent_2, "A")==0)
							      			{
							      				s6[entrada]= nand(s2[entrada],A);
							      			}else if(strcmp(ent_1, "S2")==0 && strcmp(ent_2, "B")==0){
							      				s6[entrada]= nand(s2[entrada],B);
							      			}else if(strcmp(ent_1, "S2")==0 && strcmp(ent_2, "C")==0){
							      				s6[entrada]= nand(s2[entrada],C);
							      			}else if(strcmp(ent_1, "S2")==0 && strcmp(ent_2, "D")==0){
							      				s6[entrada]= nand(s2[entrada],D);
							      			}else if(strcmp(ent_1, "S2")==0 && strcmp(ent_2, "E")==0){
							      				s6[entrada]= nand(s2[entrada],E);
							      			}
							      			if (strcmp(ent_1, "S2")==0 && strcmp(ent_2, "S1")==0)
							      			{
							      				s6[entrada]= nand(s2[entrada],s1[entrada]);
							      			}
							      			if (strcmp(ent_1, "S3")==0 && strcmp(ent_2, "A")==0)
							      			{
							      				s6[entrada]= nand(s3[entrada],A);
							      			}else if(strcmp(ent_1, "S3")==0 && strcmp(ent_2, "B")==0){
							      				s6[entrada]= nand(s3[entrada],B);
							      			}else if(strcmp(ent_1, "S3")==0 && strcmp(ent_2, "C")==0){
							      				s6[entrada]= nand(s3[entrada],C);
							      			}else if(strcmp(ent_1, "S3")==0 && strcmp(ent_2, "D")==0){
							      				s6[entrada]= nand(s3[entrada],D);
							      			}else if(strcmp(ent_1, "S3")==0 && strcmp(ent_2, "E")==0){
							      				s6[entrada]= nand(s3[entrada],E);
							      			}
							      			if (strcmp(ent_1, "S3")==0 && strcmp(ent_2, "S1")==0)
							      			{
							      				s6[entrada]= nand(s3[entrada],s1[entrada]);
							      			}if (strcmp(ent_1, "S3")==0 && strcmp(ent_2, "S2")==0){
							      				s6[entrada]= nand(s3[entrada],s2[entrada]);
							      			}if (strcmp(ent_1, "S4")==0 && strcmp(ent_2, "A")==0)
							      			{
							      				s6[entrada]= nand(s4[entrada],A);
							      			}else if(strcmp(ent_1, "S4")==0 && strcmp(ent_2, "B")==0){
							      				s6[entrada]= nand(s4[entrada],B);
							      			}else if(strcmp(ent_1, "S4")==0 && strcmp(ent_2, "C")==0){
							      				s6[entrada]= nand(s4[entrada],C);
							      			}else if(strcmp(ent_1, "S4")==0 && strcmp(ent_2, "D")==0){
							      				s6[entrada]= nand(s4[entrada],D);
							      			}else if(strcmp(ent_1, "S4")==0 && strcmp(ent_2, "E")==0){
							      				s6[entrada]= nand(s4[entrada],E);
							      			}if (strcmp(ent_1, "S4")==0 && strcmp(ent_2, "S3")==0)
							      			{
							      				s6[entrada]= nand(s4[entrada],s3[entrada]);
							      			}
							      			if (strcmp(ent_1, "S4")==0 && strcmp(ent_2, "S2")==0)
							      			{
							      				s6[entrada]= nand(s4[entrada],s2[entrada]);
							      			}
							      			if (strcmp(ent_1, "S4")==0 && strcmp(ent_2, "S1")==0){
							      				s6[entrada]= nand(s4[entrada],s1[entrada]);
							      			}
							      			if (strcmp(ent_1, "S5")==0 && strcmp(ent_2, "A")==0)
							      			{
							      				s6[entrada]= nand(s5[entrada],A);
							      			}else if(strcmp(ent_1, "S5")==0 && strcmp(ent_2, "B")==0){
							      				s6[entrada]= nand(s5[entrada],B);
							      			}else if(strcmp(ent_1, "S5")==0 && strcmp(ent_2, "C")==0){
							      				s6[entrada]= nand(s5[entrada],C);
							      			}else if(strcmp(ent_1, "S5")==0 && strcmp(ent_2, "D")==0){
							      				s6[entrada]= nand(s5[entrada],D);
							      			}else if(strcmp(ent_1, "S5")==0 && strcmp(ent_2, "E")==0){
							      				s6[entrada]= nand(s5[entrada],E);
							      			}if (strcmp(ent_1, "S5")==0 && strcmp(ent_2, "S3")==0)
							      			{
							      				s6[entrada]= nand(s5[entrada],s3[entrada]);
							      			}
							      			if (strcmp(ent_1, "S5")==0 && strcmp(ent_2, "S2")==0)
							      			{
							      				s6[entrada]= nand(s5[entrada],s2[entrada]);
							      			}
							      			if (strcmp(ent_1, "S5")==0 && strcmp(ent_2, "S1")==0)
							      			{
							      				s6[entrada]= nand(s5[entrada],s1[entrada]);
							      			}if (strcmp(ent_1, "S5")==0 && strcmp(ent_2, "S4")==0)
							      			{
							      				s6[entrada]= nand(s5[entrada],s4[entrada]);
							      			}      // saída
										}if (strcmp(port_ent, "XOR") == 0) 
										{
								      		if (strcmp(ent_1, "A")==0 && strcmp(ent_2, "B")==0){
							      				s6[entrada]= xor(A,B);
							      			}else if(strcmp(ent_1, "A")==0 && strcmp(ent_2, "C")==0){
							      				s6[entrada]= xor(A,C);
							      			}else if(strcmp(ent_1, "A")==0 && strcmp(ent_2, "D")==0){
							      				s6[entrada]= xor(A,D);
							      			}else if (strcmp(ent_1, "A")==0 && strcmp(ent_2, "E")==0)
							      			{
							      				s6[entrada]= xor(A,E);
							      			}else if(strcmp(ent_1, "B")==0 && strcmp(ent_2, "C")==0){
							      				s6[entrada]= xor(B,C);
							      			}else if(strcmp(ent_1, "B")==0 && strcmp(ent_2, "D")==0){
							      				s6[entrada]= xor(B,D);
							      			}else if (strcmp(ent_1, "B")==0 && strcmp(ent_2, "E")==0)
							      			{
							      				s6[entrada]= xor(B,E);
							      			}else if(strcmp(ent_1, "C")==0 && strcmp(ent_2, "D")==0){
							      				s6[entrada]= xor(C,D);
							      			}else if(strcmp(ent_1, "C")==0 && strcmp(ent_2, "E")==0){
							      				s6[entrada]= xor(C,E);
							      			}else if(strcmp(ent_1, "D")==0 && strcmp(ent_2, "E")==0){
							      				s6[entrada]= xor(D,E);
							      			}

							      			//para entradas com S1
							      			if (strcmp(ent_1, "S1")==0 && strcmp(ent_2, "A")==0)
							      			{
							      				s6[entrada]= xor(s1[entrada],A);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "B")==0){
							      				s6[entrada]= xor(s1[entrada],B);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "C")==0){
							      				s6[entrada]= xor(s1[entrada],C);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "D")==0){
							      				s6[entrada]= xor(s1[entrada],D);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "E")==0){
							      				s6[entrada]= xor(s1[entrada],E);
							      			}
							      			if (strcmp(ent_1, "S2")==0 && strcmp(ent_2, "A")==0)
							      			{
							      				s6[entrada]= xor(s2[entrada],A);
							      			}else if(strcmp(ent_1, "S2")==0 && strcmp(ent_2, "B")==0){
							      				s6[entrada]= xor(s2[entrada],B);
							      			}else if(strcmp(ent_1, "S2")==0 && strcmp(ent_2, "C")==0){
							      				s6[entrada]= xor(s2[entrada],C);
							      			}else if(strcmp(ent_1, "S2")==0 && strcmp(ent_2, "D")==0){
							      				s6[entrada]= xor(s2[entrada],D);
							      			}else if(strcmp(ent_1, "S2")==0 && strcmp(ent_2, "E")==0){
							      				s6[entrada]= xor(s2[entrada],E);
							      			}
							      			if (strcmp(ent_1, "S2")==0 && strcmp(ent_2, "S1")==0)
							      			{
							      				s6[entrada]= xor(s2[entrada],s1[entrada]);
							      			}
							      			if (strcmp(ent_1, "S3")==0 && strcmp(ent_2, "A")==0)
							      			{
							      				s6[entrada]= xor(s3[entrada],A);
							      			}else if(strcmp(ent_1, "S3")==0 && strcmp(ent_2, "B")==0){
							      				s6[entrada]= xor(s3[entrada],B);
							      			}else if(strcmp(ent_1, "S3")==0 && strcmp(ent_2, "C")==0){
							      				s6[entrada]= xor(s3[entrada],C);
							      			}else if(strcmp(ent_1, "S3")==0 && strcmp(ent_2, "D")==0){
							      				s6[entrada]= xor(s3[entrada],D);
							      			}else if(strcmp(ent_1, "S3")==0 && strcmp(ent_2, "E")==0){
							      				s6[entrada]= xor(s3[entrada],E);
							      			}
							      			if (strcmp(ent_1, "S3")==0 && strcmp(ent_2, "S1")==0)
							      			{
							      				s6[entrada]= xor(s3[entrada],s1[entrada]);
							      			}if (strcmp(ent_1, "S3")==0 && strcmp(ent_2, "S2")==0){
							      				s6[entrada]= xor(s3[entrada],s2[entrada]);
							      			}if (strcmp(ent_1, "S4")==0 && strcmp(ent_2, "A")==0)
							      			{
							      				s6[entrada]= xor(s4[entrada],A);
							      			}else if(strcmp(ent_1, "S4")==0 && strcmp(ent_2, "B")==0){
							      				s6[entrada]= xor(s4[entrada],B);
							      			}else if(strcmp(ent_1, "S4")==0 && strcmp(ent_2, "C")==0){
							      				s6[entrada]= xor(s4[entrada],C);
							      			}else if(strcmp(ent_1, "S4")==0 && strcmp(ent_2, "D")==0){
							      				s6[entrada]= xor(s4[entrada],D);
							      			}else if(strcmp(ent_1, "S4")==0 && strcmp(ent_2, "E")==0){
							      				s6[entrada]= xor(s4[entrada],E);
							      			}if (strcmp(ent_1, "S4")==0 && strcmp(ent_2, "S3")==0)
							      			{
							      				s6[entrada]= xor(s4[entrada],s3[entrada]);
							      			}
							      			if (strcmp(ent_1, "S4")==0 && strcmp(ent_2, "S2")==0)
							      			{
							      				s6[entrada]= xor(s4[entrada],s2[entrada]);
							      			}
							      			if (strcmp(ent_1, "S4")==0 && strcmp(ent_2, "S1")==0){
							      				s6[entrada]= xor(s4[entrada],s1[entrada]);
							      			}
							      			if (strcmp(ent_1, "S5")==0 && strcmp(ent_2, "A")==0)
							      			{
							      				s6[entrada]= xor(s5[entrada],A);
							      			}else if(strcmp(ent_1, "S5")==0 && strcmp(ent_2, "B")==0){
							      				s6[entrada]= xor(s5[entrada],B);
							      			}else if(strcmp(ent_1, "S5")==0 && strcmp(ent_2, "C")==0){
							      				s6[entrada]= xor(s5[entrada],C);
							      			}else if(strcmp(ent_1, "S5")==0 && strcmp(ent_2, "D")==0){
							      				s6[entrada]= xor(s5[entrada],D);
							      			}else if(strcmp(ent_1, "S5")==0 && strcmp(ent_2, "E")==0){
							      				s6[entrada]= xor(s5[entrada],E);
							      			}if (strcmp(ent_1, "S5")==0 && strcmp(ent_2, "S3")==0)
							      			{
							      				s6[entrada]= xor(s5[entrada],s3[entrada]);
							      			}
							      			if (strcmp(ent_1, "S5")==0 && strcmp(ent_2, "S2")==0)
							      			{
							      				s6[entrada]= xor(s5[entrada],s2[entrada]);
							      			}
							      			if (strcmp(ent_1, "S5")==0 && strcmp(ent_2, "S1")==0)
							      			{
							      				s6[entrada]= xor(s5[entrada],s1[entrada]);
							      			}if (strcmp(ent_1, "S5")==0 && strcmp(ent_2, "S4")==0)
							      			{
							      				s6[entrada]= xor(s5[entrada],s4[entrada]);
							      			} 
										} 
										else if (strcmp(port_ent, "XNOR") == 0)
										{
								      		if (strcmp(ent_1, "A")==0 && strcmp(ent_2, "B")==0){
							      				s6[entrada]= xnor(A,B);
							      			}else if(strcmp(ent_1, "A")==0 && strcmp(ent_2, "C")==0){
							      				s6[entrada]= xnor(A,C);
							      			}else if(strcmp(ent_1, "A")==0 && strcmp(ent_2, "D")==0){
							      				s6[entrada]= xnor(A,D);
							      			}else if (strcmp(ent_1, "A")==0 && strcmp(ent_2, "E")==0)
							      			{
							      				s6[entrada]= xnor(A,E);
							      			}else if(strcmp(ent_1, "B")==0 && strcmp(ent_2, "C")==0){
							      				s6[entrada]= xnor(B,C);
							      			}else if(strcmp(ent_1, "B")==0 && strcmp(ent_2, "D")==0){
							      				s6[entrada]= xnor(B,D);
							      			}else if (strcmp(ent_1, "B")==0 && strcmp(ent_2, "E")==0)
							      			{
							      				s6[entrada]= xnor(B,E);
							      			}else if(strcmp(ent_1, "C")==0 && strcmp(ent_2, "D")==0){
							      				s6[entrada]= xnor(C,D);
							      			}else if(strcmp(ent_1, "C")==0 && strcmp(ent_2, "E")==0){
							      				s6[entrada]= xnor(C,E);
							      			}else if(strcmp(ent_1, "D")==0 && strcmp(ent_2, "E")==0){
							      				s6[entrada]= xnor(D,E);
							      			}

							      			//para entradas com S1
							      			if (strcmp(ent_1, "S1")==0 && strcmp(ent_2, "A")==0)
							      			{
							      				s6[entrada]= xnor(s1[entrada],A);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "B")==0){
							      				s6[entrada]= xnor(s1[entrada],B);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "C")==0){
							      				s6[entrada]= xnor(s1[entrada],C);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "D")==0){
							      				s6[entrada]= xnor(s1[entrada],D);
							      			}else if(strcmp(ent_1, "S1")==0 && strcmp(ent_2, "E")==0){
							      				s6[entrada]= xnor(s1[entrada],E);
							      			}
							      			if (strcmp(ent_1, "S2")==0 && strcmp(ent_2, "A")==0)
							      			{
							      				s6[entrada]= xnor(s2[entrada],A);
							      			}else if(strcmp(ent_1, "S2")==0 && strcmp(ent_2, "B")==0){
							      				s6[entrada]= xnor(s2[entrada],B);
							      			}else if(strcmp(ent_1, "S2")==0 && strcmp(ent_2, "C")==0){
							      				s6[entrada]= xnor(s2[entrada],C);
							      			}else if(strcmp(ent_1, "S2")==0 && strcmp(ent_2, "D")==0){
							      				s6[entrada]= xnor(s2[entrada],D);
							      			}else if(strcmp(ent_1, "S2")==0 && strcmp(ent_2, "E")==0){
							      				s6[entrada]= xnor(s2[entrada],E);
							      			}
							      			if (strcmp(ent_1, "S2")==0 && strcmp(ent_2, "S1")==0)
							      			{
							      				s6[entrada]= xnor(s2[entrada],s1[entrada]);
							      			}
							      			if (strcmp(ent_1, "S3")==0 && strcmp(ent_2, "A")==0)
							      			{
							      				s6[entrada]= xnor(s3[entrada],A);
							      			}else if(strcmp(ent_1, "S3")==0 && strcmp(ent_2, "B")==0){
							      				s6[entrada]= xnor(s3[entrada],B);
							      			}else if(strcmp(ent_1, "S3")==0 && strcmp(ent_2, "C")==0){
							      				s6[entrada]= xnor(s3[entrada],C);
							      			}else if(strcmp(ent_1, "S3")==0 && strcmp(ent_2, "D")==0){
							      				s6[entrada]= xnor(s3[entrada],D);
							      			}else if(strcmp(ent_1, "S3")==0 && strcmp(ent_2, "E")==0){
							      				s6[entrada]= xnor(s3[entrada],E);
							      			}
							      			if (strcmp(ent_1, "S3")==0 && strcmp(ent_2, "S1")==0)
							      			{
							      				s6[entrada]= xnor(s3[entrada],s1[entrada]);
							      			}if (strcmp(ent_1, "S3")==0 && strcmp(ent_2, "S2")==0){
							      				s6[entrada]= xnor(s3[entrada],s2[entrada]);
							      			}if (strcmp(ent_1, "S4")==0 && strcmp(ent_2, "A")==0)
							      			{
							      				s6[entrada]= xnor(s4[entrada],A);
							      			}else if(strcmp(ent_1, "S4")==0 && strcmp(ent_2, "B")==0){
							      				s6[entrada]= xnor(s4[entrada],B);
							      			}else if(strcmp(ent_1, "S4")==0 && strcmp(ent_2, "C")==0){
							      				s6[entrada]= xnor(s4[entrada],C);
							      			}else if(strcmp(ent_1, "S4")==0 && strcmp(ent_2, "D")==0){
							      				s6[entrada]= xnor(s4[entrada],D);
							      			}else if(strcmp(ent_1, "S4")==0 && strcmp(ent_2, "E")==0){
							      				s6[entrada]= xnor(s4[entrada],E);
							      			}if (strcmp(ent_1, "S4")==0 && strcmp(ent_2, "S3")==0)
							      			{
							      				s6[entrada]= xnor(s4[entrada],s3[entrada]);
							      			}
							      			if (strcmp(ent_1, "S4")==0 && strcmp(ent_2, "S2")==0)
							      			{
							      				s6[entrada]= xnor(s4[entrada],s2[entrada]);
							      			}
							      			if (strcmp(ent_1, "S4")==0 && strcmp(ent_2, "S1")==0){
							      				s6[entrada]= xnor(s4[entrada],s1[entrada]);
							      			}
							      			if (strcmp(ent_1, "S5")==0 && strcmp(ent_2, "A")==0)
							      			{
							      				s6[entrada]= xnor(s5[entrada],A);
							      			}else if(strcmp(ent_1, "S5")==0 && strcmp(ent_2, "B")==0){
							      				s6[entrada]= xnor(s5[entrada],B);
							      			}else if(strcmp(ent_1, "S5")==0 && strcmp(ent_2, "C")==0){
							      				s6[entrada]= xnor(s5[entrada],C);
							      			}else if(strcmp(ent_1, "S5")==0 && strcmp(ent_2, "D")==0){
							      				s6[entrada]= xnor(s5[entrada],D);
							      			}else if(strcmp(ent_1, "S5")==0 && strcmp(ent_2, "E")==0){
							      				s6[entrada]= xnor(s5[entrada],E);
							      			}if (strcmp(ent_1, "S5")==0 && strcmp(ent_2, "S3")==0)
							      			{
							      				s6[entrada]= xnor(s5[entrada],s3[entrada]);
							      			}
							      			if (strcmp(ent_1, "S5")==0 && strcmp(ent_2, "S2")==0)
							      			{
							      				s6[entrada]= xnor(s5[entrada],s2[entrada]);
							      			}
							      			if (strcmp(ent_1, "S5")==0 && strcmp(ent_2, "S1")==0)
							      			{
							      				s6[entrada]= xnor(s5[entrada],s1[entrada]);
							      			}if (strcmp(ent_1, "S5")==0 && strcmp(ent_2, "S4")==0)
							      			{
							      				s6[entrada]= xnor(s5[entrada],s4[entrada]);
							      			} 
										}if (strcmp(port_ent, "NOT") == 0)
										{
								      		if (strcmp(ent_1, "A")==0 )
							      			{
							      				s6[entrada]= not(A);
							      			}else if(strcmp(ent_1, "B")==0){
							      				s6[entrada]= not(B);
							      			}else if(strcmp(ent_1, "C")==0){
							      				s6[entrada]= not(C);
							      			}else if (strcmp(ent_1, "D")==0 ){
							      				s6[entrada]= not(D);
							      			}else if(strcmp(ent_1, "E")==0 ){
							      				s6[entrada]= not(E);
							      			}
							      			//para entradas com S1
							      			if (strcmp(ent_1, "S1")==0)
							      			{
							      				s6[entrada]= not(s1[entrada]);
							      			}else if (strcmp(ent_1, "S2")==0)
							      			{
							      				s6[entrada]= not(s2[entrada]);
							      			}else if (strcmp(ent_1, "S3")==0)
							      			{
							      				s6[entrada]= not(s3[entrada]);
							      			}else if (strcmp(ent_1, "S4")==0)
							      			{
							      				s6[entrada]= not(s4[entrada]);
							      			}else if (strcmp(ent_1, "S5")==0)
							      			{
							      				s6[entrada]= not(s5[entrada]);
							      			}
								      		
									}
									//prende s1
										if (strcmp(fixa1, "S6")==0 && strcmp(fixa0, "0")==0)
										{
											s6[entrada]=0;
										}else if (strcmp(fixa1, "S6")==0 && strcmp(fixa0, "1")==0)
										{
											s6[entrada]=1;
										}
										if (strcmp(fixa3, "S6")==0 && strcmp(fixa4, "0")==0)
										{
											s6[entrada]=0;
										}else if (strcmp(fixa3, "S6")==0 && strcmp(fixa4, "1")==0)
										{
											s6[entrada]=1;
										}		

								}
				 						 
							} 
				}//FIM DO FOR




				fscanf(file,"%s %s  ", saidas1, port_ent);
	      		printf("%s %s \n", saidas1, port_ent);
	      	
				//impressão da tabela verdade
	      		if (strcmp(port_ent, "S4")==0 )
				{
						fprintf(file,"\n\n");
						fprintf(file,"--------------------\n");
						fprintf(file,"tabela verdade\n");
						fprintf(file,"--------------------\n");
						fprintf(file,"E D C B A |F\n");
						fprintf(file,"--------------------\n");

						for (entrada = 0; entrada < k; entrada++)
						{
							A = (entrada & 1)?A1:A2; 
							B = (entrada & 2)?B1:B2;  
							C = (entrada & 4)?C1:C2;  
							D = (entrada & 8)?D1:D2;
							E = (entrada & 16)?E1:E2;
							
							fprintf(file,"%d %d %d %d %d |%d\n",E,D,C,B,A,s4[entrada] );
						}
					
				}else if (strcmp(port_ent, "S3")==0 )
				{
					fprintf(file,"\n\n");
						fprintf(file,"--------------------\n");
						fprintf(file,"tabela verdade\n");
						fprintf(file,"--------------------\n");
						fprintf(file,"E D C B A |F\n");
					for (entrada = 0; entrada < k; entrada++)
					{	A = (entrada & 1)?A1:A2; 
							B = (entrada & 2)?B1:B2;  
							C = (entrada & 4)?C1:C2;  
							D = (entrada & 8)?D1:D2;
							E = (entrada & 16)?E1:E2;
						fprintf(file,"%d %d %d %d %d |%d\n",E,D,C,B,A,s3[entrada] );
					}
					
				}else if (strcmp(port_ent, "S2")==0 )
				{
					fprintf(file,"\n\n");
						fprintf(file,"--------------------\n");
						fprintf(file,"tabela verdade\n");
						fprintf(file,"--------------------\n");
						fprintf(file,"E D C B A |F\n");
					for (entrada = 0; entrada < k; entrada++)
					{
						A = (entrada & 1)?A1:A2; 
							B = (entrada & 2)?B1:B2;  
							C = (entrada & 4)?C1:C2;  
							D = (entrada & 8)?D1:D2;
							E = (entrada & 16)?E1:E2;
						fprintf(file,"%d %d %d %d %d |%d\n",E,D,C,B,A,s2[entrada] );
					}
					
				}else if (strcmp(port_ent, "S5")==0 )
				{
					fprintf(file,"\n\n");
						fprintf(file,"--------------------\n");
						fprintf(file,"tabela verdade\n");
						fprintf(file,"--------------------\n");
						fprintf(file,"E D C B A | F\n");
					for (entrada = 0; entrada < k; entrada++)
					{
							A = (entrada & 1)?A1:A2; 
							B = (entrada & 2)?B1:B2;  
							C = (entrada & 4)?C1:C2;  
							D = (entrada & 8)?D1:D2;
							E = (entrada & 16)?E1:E2;
						fprintf(file,"%d %d %d %d %d |%d\n",E,D,C,B,A,s5[entrada] );
					}
					
				}else if (strcmp(port_ent, "S6")==0 )
				{
					fprintf(file,"\n\n");
						fprintf(file,"--------------------\n");
						fprintf(file,"tabela verdade\n");
						fprintf(file,"--------------------\n");
						fprintf(file,"E D C B A | F\n");

					for (entrada = 0; entrada < k; entrada++)
					{
						A = (entrada & 1)?A1:A2; 
							B = (entrada & 2)?B1:B2;  
							C = (entrada & 4)?C1:C2;  
							D = (entrada & 8)?D1:D2;
							E = (entrada & 16)?E1:E2;
						fprintf(file,"%d %d %d %d %d |%d\n",E,D,C,B,A,s6[entrada] );
					}
					
				}else if (strcmp(port_ent, "S7")==0 )
				{
					fprintf(file,"\n\n");
						fprintf(file,"--------------------\n");
						fprintf(file,"tabela verdade\n");
						fprintf(file,"--------------------\n");
						fprintf(file,"E D C B A | F\n");
					for (entrada = 0; entrada < k; entrada++)
					{
						A = (entrada & 1)?A1:A2; 
							B = (entrada & 2)?B1:B2;  
							C = (entrada & 4)?C1:C2;  
							D = (entrada & 8)?D1:D2;
							E = (entrada & 16)?E1:E2;

						fprintf(file,"%d %d %d %d %d |%d\n",E,D,C,B,A,s7[entrada] );
					}
					
				}
				
	      	}

		}//fim do else  
		
	}//fim do primeiro while 



	fclose(file);//fecha o arquivo de texto
	return 0;
}
