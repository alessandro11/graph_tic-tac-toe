CFLAGS += -g -Wall

all: gen-graph

.SUFFIXES:	.c
.c.o:
	${CC} ${CFLAGS} -c $<

gen-graph: gen-graph.o
	${CC} -o ${@} $^

gen-graph.o: gen-graph.c

clean:
	-rm -rf *.o gen-graph
