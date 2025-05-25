CC     = gcc
CFLAGS = -Wall -g -std=c99
CCLINK = $(CC)
OBJS   = stack.o student.o
EXEC = prog.exe
RM = *.exe $(OBJS)

prog.exe: $(OBJS)
	$(CCLINK) $(OBJS)-o $(EXEC)

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	rm -fr $(RM)
