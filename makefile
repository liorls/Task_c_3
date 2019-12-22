VARIABLE = gcc -Wall -g
CLEAN = *.o *.a *.so mains maind

all: isort txtfindMain clean

isort:
	$(VARIABLE) -o isort.o isort.c

txtfindMain:
	$(VARIABLE) -o txtfindMain.o txtfindMain.c txtfind.c

clean:
	rm -f $(CLEAN)
