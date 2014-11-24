CC=gcc
CFLAGS=-o3 -c
SOURCES=data_exchange.c help_func.c http_client.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=http_client

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o $(EXECUTABLE)
