EXE_NAME  = cfightlog
INC = -I../include
SRC = ../source
vpath %.cpp ../source
EXE_PATH = $(DESTDIR)/$(EXE_NAME)/

OBJS = main.o \
    handleTrd.o \
    sendMgr.o \
    sendTrd.o \
    cfg.o \
    aes.o

CC = g++ -g
GC = gcc -g
CFLAGS = -O0 -fPIC $(INC) -D_DEBUG -DEXENAME='"$(EXE_NAME)"'

$(EXE_NAME):$(OBJS)
	$(CC) $(OBJS) -o ../$(EXE_NAME) -lz -lm -lpthread -lcurl

%.o:%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

%.o:%.c
	$(GC) $(CFLAGS) -c $< -o $@

clean:
	-rm *.o ../$(EXE_NAME)

install:
	mkdir -p $(EXE_PATH)
	cp ../$(EXE_NAME) $(EXE_PATH)