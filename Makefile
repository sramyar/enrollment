#------------------------------------------------------------------------------
#  Makefile for prog3 
# 
#  make             	makes enrollment
#  make clean       	removes object files
#  make check       	runs valgrind to check for memory errors
#
#  Enrollment.h		This defines some application specific structs. You can modify this as needed.
#  Enrollment.c		This is the application code that you have to write.
#
#  HashTable.h		Given. Don't touch this.
#  HashTable.c		This is where you implement HashTable functions listed in HashTable.h
#  Dictionary.h		Given. Don't touch this. The enrollment application will include this.
#  Dictionary.h		This is where you implment Dictionary functions listed in Dictionary.h
#------------------------------------------------------------------------------

Enrollment:	Enrollment.o HashTable.o Dictionary.o
	cc -o prog3 Enrollment.o HashTable.o Dictionary.o

Enrollment.o:	Enrollment.h Enrollment.c
	cc -c Enrollment.c

HashTable.o:	HashTable.h HashTable.c
	cc -c HashTable.c

Dictionary.o:	Dictionary.h Dictionary.c HashTable.o
	cc -c Dictionary.c

clean:
	rm -f prog3 Enrollment Enrollment.o HashTable.o Dictionary.o

check: 
	valgrind --leak-check=full ./prog3