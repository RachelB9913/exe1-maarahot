OBJECTS_LOOP=basicClassification.o advancedClassificationLoop.o 
OBJECTS_REC=basicClassification.o advancedClassificationRecursion.o
OBJECTS_MAIN= main.o
CC = gcc
AR = ar
FLAGS = -Wall -g


all: libclassloops.a libclassrec.a libclassrec.so libclassloops.so mains maindloop maindrec
loop: libclassloops.a
recursives: libclassrec.a
recursived: libclassrec.so
loopd: libclassloops.so
#make mains
mains: $(OBJECTS_MAIN) libclassrec.a						#static
	$(CC) $(FLAGS) -o mains $(OBJECTS_MAIN) libclassrec.a
#make maindloop
maindloop: $(OBJECTS_MAIN)									#dinamic
	$(CC) $(FLAGS) -o maindloop $(OBJECTS_MAIN) ./libclassloops.so
#make maindrec
maindrec: $(OBJECTS_MAIN)									#dinamic
	$(CC) $(FLAGS) -o maindrec $(OBJECTS_MAIN) ./libclassrec.so
#make loops
libclassloops.a: $(OBJECTS_LOOP)
	$(AR) -rcs libclassloops.a $(OBJECTS_LOOP)
#make recursives
libclassrec.a: $(OBJECTS_REC)
	$(AR) -rcs libclassrec.a $(OBJECTS_REC)
#make recursived
libclassrec.so: $(OBJECTS_REC)							
	$(CC) -shared -o libclassrec.so $(OBJECTS_REC)
#make loopd
libclassloops.so: $(OBJECTS_LOOP)
	$(CC) -shared -o libclassloops.so $(OBJECTS_LOOP)
#the compilation of the other classes
basicClassification.o: basicClassification.c NumClass.h
	$(CC) $(FLAGS) -c -fPIC -o basicClassification.o basicClassification.c 

advancedClassificationLoop.o: advancedClassificationLoop.c NumClass.h
	$(CC) $(FLAGS) -c -fPIC -o advancedClassificationLoop.o advancedClassificationLoop.c

advancedClassificationRecursion.o: advancedClassificationRecursion.c NumClass.h
	$(CC) $(FLAGS) -c -fPIC -o advancedClassificationRecursion.o advancedClassificationRecursion.c

main.o: main.c NumClass.h
	$(CC) $(FLAGS) -c -fPIC -o main.o main.c

.PHONY: clean all

clean:
	rm -f *.o *.a *.so maindrec maindloop mains
#rm -f !(*.h|*.c|*.txt|Makefile) אפשר ככה?? מה לא למחוק.. 
