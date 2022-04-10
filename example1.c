#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "genann.h"
#include <math.h>
#include <sys/time.h>
#ifdef _OPENMP
#include <omp.h>
#endif
#define NB_TIMES 100
double my_gettimeofday(){
  struct timeval tmp_time;
  gettimeofday(&tmp_time, NULL);
  return tmp_time.tv_sec + (tmp_time.tv_usec * 1.0e-6L);
}

int main(int argc, char *argv[])
{
  int nb;
    if (argc < 2){
      nb = 1 ;
    }else{
      nb = atoi(argv[1]);
    }
    // printf("GENANN example 1.\n");
    // printf("Train a small ANN to the XOR function using backpropagation.\n");

    /* This will make the neural network initialize differently each run. */
    /* If you don't get a good result, try again for a different result. */
    srand(time(0));
    double debut=0.0, fin=0.0;
    /* Input and expected out data for the XOR function. */
    const double input[16][4] = {
        {0, 0,0,0},
        {0, 0,0,1},
        {0, 0,1,0},
        {0, 0,1,1},
        {0, 1,0,0},
        {0, 1,0,1},
        {0, 1,1,0},
        {0, 1,1,1},
        {1, 0,0,0},
        {1, 0,0,1},
        {1, 0,1,0},
        {1, 0,1,1},
        {1, 1,0,0},
        {1, 1,0,1},
        {1, 1,1,0},
        {1, 1,1,1},
        
    };
    const double output[16] = {
        0, 
        1,
        1,
        0,
        1,
        0,
        0,
        1,
        1,
        0,
        0,
        1,
        0,
        1,
        1,
        0
        };
    int i;

    /* New network with 2 inputs,
     * 1 hidden layer of 3 neurons,
     * and 1 output. */
    
    // printf("Naif Version :\n");
    //   for (int j = 0; j <16;j++){
    //     printf("Output for [%1.f, %1.f, %1.f, %1.f] is %1.f.\n", input[j][0], input[j][1], input[j][2],input[j][3], *genann_run(ann, input[j]));
    //   }
    /* Train on the four labeled data points many times. */
    double times[NB_TIMES]; 
    int fail[NB_TIMES]; 
    for (int time = 0; time < NB_TIMES;time++){
        genann *ann = genann_init(4, 1, 3, 1);
        debut = my_gettimeofday();
#pragma omp simd
        for (i = 0; i < nb; ++i) { //Generation
            for (int j = 0; j <16;j++){ // Chaque case de l'entraiement
                genann_train(ann, input[j], output + j, 3);
            }
        }
        fin = my_gettimeofday();
        times[time] = fin - debut;
        fail[time] = 0;
        for (int j = 0; j <16;j++){
          double rep = *genann_run(ann, input[j]);
          if(floor(rep+0.5) != floor(output[j])){
            fail[time]++;
          } 
        }
        genann_free(ann);
      }
      
      
    // fprintf( stdout, "For n=%d: performance = %g Gflop/s \n",
	//    n, (((double) 2)*n*n*n / ((fin - debut)/NB_TIMES) )/ ((double) 1e9) ); /* 2n^3 flops */
      double timeTotal = 0;
      int failTotal = 0;
      for (int time = 0; time < NB_TIMES;time++){
            timeTotal += times[time];
            failTotal += fail[time];
      }

    fprintf( stdout, " %f",timeTotal/NB_TIMES);
    /* Run the network and see what it predicts. */
    // printf("trained Version :\n");
    printf(" %d \n",((failTotal/NB_TIMES)*100)/16);
    return 0;
}
