OBJ = screen.o main.o comm.o sound.o
APPNAME = sound

#linking ruleo
$(APPNAME) : $(OBJ)
	gcc -o $(APPNAME) $(OBJ) -lcurl -lm

#compiling rule
%.o : %.c
	gcc -c -o $@ $<

#cleaning rule
clean :
	rm $(APPNAME) $(OBJ)

#archiving ruleo
zip : 
	tar cf appdev.tar *.c *.h makefile
