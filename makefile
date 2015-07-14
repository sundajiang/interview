
#Makefile有三个非常有用的变量。分别是$@，$^，$<代表的意义分别是：
#$@--目标文件，$^--所有的依赖文件，$<--第一个依赖文件。
TARGET = strtoint link_list tree operator array2search replaceblack
all : $(TARGET)
.PHONY : all
CC = gcc
CC+ = g++
objects1 = strtoint.o
objects2 = link_list.o
objects3 = tree.o
objects4 = operator.o
objects5 = array2search.o
objects6 = replaceblack.o

#这个规则表示所有的 .o文件都是依赖与相应的.c文件的。相当与%.o:%.c
.c.o:
	$(CC) -c $<
#这个规则表示所有的 .o文件都是依赖与相应的.cpp文件的。
.cpp.o:
	$(CC+) -c $<


strtoint:$(objects1)
	$(CC) -o $@ $^

link_list:$(objects2)
	$(CC+) -o $@ $^

tree:$(objects3)
	$(CC+) -o $@ $^

operator:$(objects4)
	$(CC+) -o $@ $^

array2search:$(objects5)
	$(CC+) -o $@ $^

replaceblack:$(objects6)
	$(CC) -o $@ $^


.PHONY:clean
clean :
	rm *.o $(TARGET)


