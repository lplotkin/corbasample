CC		:= g++
C_FLAGS := 

BIN		:= bin
SRC		:= src
JAVA		:= $(SRC)/java
IDLSRC		:= idl/hello.idl
JAVAIDL		:= $(JAVA)/helloHelper.java $(JAVA)/helloHolder.java $(JAVA)/hello.java $(JAVA)/helloOperations.java $(JAVA)/_helloStub.java
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
	$(RM) $(BIN)/* $(GEN)/* $(JAVA)/*.class $(JAVAIDL)

run: all
	./$(BIN)/server

java: $(IDLSRC)
	idlj -td $(JAVA) $(IDLSRC)
	javac src/java/*.java

$(IDLH) $(IDLSK): $(IDLSRC)
	omniidl -bcxx -Cgenerated $(IDLSRC)

$(BIN)/server: $(SSRC) $(IDLH)
	$(CC) $(C_FLAGS) $(INCLUDE) -L$(LIB) $^ -o $@ $(LIBRARIES)

$(BIN)/client: $(CSRC) $(IDLH)
	$(CC) $(C_FLAGS) $(INCLUDE) -L$(LIB) $^ -o $@ $(LIBRARIES)
