CC		:= g++
C_FLAGS := 

BIN		:= bin
SRC		:= src
GEN		:= generated
IDLH		:= $(GEN)/hello.hh 
IDLSK		:= $(GEN)/helloSK.cc
SSRC		:= $(SRC)/hello_server.cc $(IDLSK)
CSRC		:= $(SRC)/hello_client.cc $(IDLSK)
INCLUDE	:= -Iinclude -I$(GEN) -I/usr/include/omniORB4
LIB		:= lib

LIBRARIES	:= -lomniORB4 -lomnithread

all: bin/server bin/client

clean:
	$(RM) $(BIN)/* $(GEN)/*

run: all
	./$(BIN)/server

$(IDLH) $(IDLSK): idl/hello.idl
	omniidl -bcxx -Cgenerated idl/hello.idl

$(BIN)/server: $(SSRC) $(IDLH)
	$(CC) $(C_FLAGS) $(INCLUDE) -L$(LIB) $^ -o $@ $(LIBRARIES)

$(BIN)/client: $(CSRC) $(IDLH)
	$(CC) $(C_FLAGS) $(INCLUDE) -L$(LIB) $^ -o $@ $(LIBRARIES)
