
#Makefile有三个非常有用的变量。分别是$@，$^，$<代表的意义分别是：
#$@--目标文件，$^--所有的依赖文件，$<--第一个依赖文件。
TARGET = strtoint link_list tree operator array2search replaceblack sort left_n
all : $(TARGET)
.PHONY : all
CC = gcc
CC+ = g++
objects1 = strtoint.o


#这个规则表示所有的 .o文件都是依赖与相应的.c文件的。相当与%.o:%.c
.c.o:
	$(CC) -c $<
#这个规则表示所有的 .o文件都是依赖与相应的.cpp文件的。
.cpp.o:
	$(CC+) -c $<


strtoint:$(objects1)
	$(CC) -o $@ $^

link_list:link_list.o
	$(CC+) -o $@ $^

tree:tree.o
	$(CC+) -o $@ $^

operator:operator.o
	$(CC+) -o $@ $^

array2search:array2search.o
	$(CC+) -o $@ $^

replaceblack:replaceblack.o
	$(CC) -o $@ $^

sort:sort.o
	$(CC) -o $@ $^

left_n:left_n.o
	$(CC) -o $@ $^


.PHONY:clean
clean :
	rm *.o $(TARGET)


