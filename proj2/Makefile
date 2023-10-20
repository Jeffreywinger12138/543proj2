CC=gcc 
CCFLAGS=-c -g -Wall -m32 -ffreestanding
LDFLAGS=-g -Wall -m32 -ffreestanding
LINK= gcc 

TARGETS=util-program attack1 attack3 attack4 attack5 attack6 attack7

.c.o : 
	${CC} ${CCFLAGS} $< -o $@

attack1-binary : attack1.o util-program.o
	${LINK} ${LDFLAGS} attack1.o util-program.o -o $@

attack3-binary : attack3.o util-program.o
	${LINK} ${LDFLAGS} attack3.o util-program.o -o $@

attack4-binary : attack4.o util-program.o
	${LINK} ${LDFLAGS} attack4.o util-program.o -o $@

attack5-binary : attack5.o util-program.o
	${LINK} ${LDFLAGS} attack5.o util-program.o -o $@

attack6-binary : attack6.o util-program.o
	${LINK} ${LDFLAGS} attack6.o util-program.o -o $@

attack7-binary : attack7.o util-program.o
	${LINK} ${LDFLAGS} attack7.o util-program.o -o $@


