OBJ = screen.o testscreen.o comm.o
APPNAME = screentest

#linking rule
$(APPNAME) : $(OBJ)
	gcc -o $(APPNAME) $(OBJ) -lcurl

#compiling rule
%.o : %.c
	gcc -c -o $@ $<

#cleaning rule
clean :
	rm $(APPNAME) $(OBJ)

#archiving ruleo
zip : 
	tar cf appdev.tar *.c *.h makefile
