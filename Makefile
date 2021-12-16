WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR) $(TFLAGS) 
VALGRIND = valgrind --tool=memcheck --leak-check=yes --verbose

EXEC = test_tree
SRCS = tree.c test_tree.c ftree.c
OBJS = $(SRCS:%.c=%.o)

runtest: $(EXEC)
	$(EXEC)

%.o: %.c
	$(GCC) -c $< -o $@

$(EXEC): $(OBJS)
	$(GCC) $^ -o $@

clean:
	rm -f $(EXEC) *.o
	rm -rf outputs
	rm -rf memchecks
