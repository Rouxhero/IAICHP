CFLAGS = -Wall -Wshadow -O3 -g -march=native -pthread -fopenmp -fopt-info-vec
LDLIBS = -lm -fopenmp -fopt-info-vec



example1: example1.o genann.o

example1_bis: example1_bis.o genann.o

example1_double: example1_double.o genann.o

example1_double_par: example1_double_par.o genann.o

clean:
	$(RM) *.o
	$(RM) test example1  example1_bis example1_double example1_double_par

