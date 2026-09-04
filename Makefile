test: printbill.o newcustomer.o main.o 
	gcc -o test printbill.o newcustomer.o main.o 

newcustomer.o: newcustomer.h newcustomer.c
	gcc -c newcustomer.h newcustomer.c

printbill.o: printbill.h printbill.c
	gcc -c printbill.h printbill.c

main.o: main.c
	gcc -c main.c

clean:
	rm-f test printbill.o newcustomer.o main.o

