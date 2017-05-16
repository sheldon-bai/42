

This C file overrides the malloc() and free() functions, calls printf() whenever they are called, and counts the number of invocations.

At the end of the program, it prints either OK or FAIL depending on whether or not all malloc() calls were free()d.

To use it, download the file to ~/lib/alloc_wrap.c and put this in your makefile:

ifdef ALLOCWRAP
	LDFLAGS += $(HOME)/lib/alloc_wrap.c -ldl
endif 

where LDFLAGS is like CFLAGS, but it's only included when compiling a binary.
like this, note the lack of -c:
	$(CC) $(LDFLAGS) -o $@ $^

To test with allocwrap, compile your tests with "make re ALLOCWRAP=1 test".

