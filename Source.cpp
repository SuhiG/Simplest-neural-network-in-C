#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define inputs  2
#define pattern  2

double I[pattern][inputs]= {{0.5, 0.5},{1.0, 0.5}};
double T[pattern]={0.0,1.0};
double O[pattern];
double X[pattern];
double w[inputs];
double De_bias;
double de_wei[inputs];
int i,j,k;
double bias;
double learning_rate=0.5;

int main( ){

	srand(10);
	for(j=0;j<inputs;j++){
		w[j] = 2.0 * (double)rand()/RAND_MAX - 1.0;
		printf("w[%d]=%lf,",j,w[j]);
	}
	bias= 2.0*(double)rand()/RAND_MAX-1.0;
	printf("bias=%lf\n",bias);

	for(k=0;k<50;k++){
		for(i=0;i<pattern;i++){
			O[i]=0.0;
			X[i]=0.0;
			for(j=0;j<inputs;j++){
				X[i]+=I[i][j]*w[j];
			}			
			X[i]+=bias;		
			O[i]=1/(1 + exp(-X[i]));
		}

		for(j=0;j<inputs;j++){
			de_wei[j]=0.0;
			for(i=0;i<pattern;i++){
				de_wei[j]+= -(T[i]-O[i])*X[i]*(1-X[i])*I[j][i];
			}
		}
		De_bias=0.0;
		for(i=0;i<pattern;i++){
			De_bias+= -(T[i]-O[i])*X[i]*(1-X[i]);
		}
		for(j=0;j<inputs;j++){
			w[j]+=-learning_rate*de_wei[j];
		}
		bias+=-learning_rate*De_bias;

	}

	
	for(i=0;i<pattern;i++){
		printf("T[%d]=%lf, O[%d]=%lf\n",i,T[i],i,O[i]);
	}



	}

