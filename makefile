all: oht.c 
	gcc -Wall -o oht oht.c -framework ApplicationServices

clean: 
	$(RM) oht

