objects = main.o JumpListRand.o #JumpListDet.o

all: main

main: $(objects)
	g++ -o main $(objects)

main.o: src/main.cpp
	g++ -c src/main.cpp 

JumpListRand.o: src/JumpListRand.cpp src/JumpListRand.h
	g++ -c src/JumpListRand.cpp

# JumpListDet.o: src/JumpListDet.cpp src/JumpListDet.h
# 	g++ -c src/JumpListDet.cpp

clean:
	rm -f main *.o