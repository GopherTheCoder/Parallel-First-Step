%.o:
	cc -g -o obj/$@ -c src/$(@:.o=.c)
%: %.o
	cc -g -o bin/$@ $(addprefix obj/,$^)

main: prime.o