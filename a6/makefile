default: prog 

hashMap.o: hashMap.c hashMap.h 
	gcc -Wall -std=c99 -pedantic-errors -c hashMap.c  -ggdb

prog: hashMap.o main.c
	gcc -Wall -std=c99 -pedantic-errors -o prog hashMap.o  main.c -ggdb

spellcheck: hashMap.o spellcheck.c
	gcc -Wall -std=c99 -pedantic-errors -o spell hashMap.o  spellcheck.c  -ggdb
	
clean:
	rm hashMap.o	

cleanall: clean
	rm prog
