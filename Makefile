CC=gcc
CFLAGS=-c -Werror
LDLIBS=-lm
SOURCES=colrconv.c
OBJECTS=$(addsuffix .o, $(basename ${SOURCES}))
EXECUTABLE=colrconv

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)

$(OBJECTS): %.o: %.c $(HEADERS)

clean:
	rm -f $(EXECUTABLE) $(OBJECTS)

.PHONY: all clean

