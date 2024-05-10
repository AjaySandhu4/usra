objects = main.o JumpListRand.o JumpListDet.o

all: main

main: $(objects)
	g++ -o main $(objects)

main.o: src/main.cc 
	g++ -c src/main.cc 

# JumpList.o: JumpList.h
# 	g++ -c JumpList.cc

JumpListRand.o: headers/JumpListRand.h
	g++ -c src/JumpListRand.cc

JumpListDet.o: headers/JumpListDet.h
	g++ -c src/JumpListDet.cc

clean:
	rm -f main *.o