CC=/usr/bin/gcc
CFLAGS=-Werror -pedantic -ggdb
INCLUDE=-I../../util/C/
RM=/bin/rm

sl_list_test: singly_linked_list.o singly_linked_list_test.o
	$(CC) $^ -o $@

singly_linked_list_test.o: singly_linked_list_test.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $<

singly_linked_list.o: singly_linked_list.c singly_linked_list.h
	$(CC) $(CFLAGS) $(INCLUDE) -c $<

clean:
	$(RM)	*.out
	$(RM) *.o
	$(RM) sl_list_test



