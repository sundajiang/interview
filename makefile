
#本工程生成三个目标文件 ： netlayer ip_interface himac_test
all : strtoint link_list tree
.PHONY : all
CC = gcc
CC+ = g++
objects1 = strtoint.o
objects2 = link_list.o
objects3 = tree.o

strtoint:$(objects1)
	$(CC) -o strtoint $(objects1)

strtoint.o: strtoint.c
	$(CC) -c strtoint.c

link_list:$(objects2)
	$(CC+) -o link_list $(objects2)

link_list.o: link_list.cpp
	$(CC+) -c link_list.cpp

tree:$(objects3)
	$(CC+) -o tree $(objects3)

tree.o: tree.cpp
	$(CC+) -c tree.cpp


clean :
	rm *.o strtoint link_list tree


