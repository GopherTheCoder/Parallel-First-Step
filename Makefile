vpath %.c src/
vpath %.o obj/

serial: smain.o prime.o
	cc -g -o bin/$@ $^

parallel: pmain.o prime.o
	cc -g -fopenmp $^ -o bin/$@

obj/smain.o: main.c
	cc -g -c $^ -o $@

obj/pmain.o: main.c
	cc -g -DPARALLEL -fopenmp -c $^ -o $@

obj/prime.o: prime.c
	cc -g -c $^ -o $@

clean:
	rm -f bin/* obj/*