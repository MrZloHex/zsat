CXX			:= gcc
CXX_FLAGS	:= -c -Wall -Wextra -Werror

MAIN_FILE	:= Main
LIB_OBJ 	:= C.o CPP.o
SRC_DIR		:= ./src
LIB_DIR		:= ./src/lib
CMP_DIR 	:= ./cmp
EXEC_FILE	:= zsat

all: clean compile execute

clean:
	@echo "🧹 Cleaning ..."
	-rm $(CMP_DIR)/$(MAIN_FILE).o $(EXEC_FILE)

execute:
	@echo "🚀 Executing ..."
	$(CMP_DIR)/$(EXEC_FILE) tests/c.c


compile: $(MAIN_FILE).o $(LIB_OBJ)
	@echo "🚧 Building ..."
	$(CXX) $(CMP_DIR)/*.o -o $(CMP_DIR)/$(EXEC_FILE)

$(MAIN_FILE).o:
	$(CXX) $(CXX_FLAGS) -c $(SRC_DIR)/$(MAIN_FILE).c -o $(CMP_DIR)/$(MAIN_FILE).o

C.o:
	$(CXX) $(CXX_FLAGS) -c $(LIB_DIR)/C.c -o $(CMP_DIR)/C.o

CPP.o:
	$(CXX) $(CXX_FLAGS) -c $(LIB_DIR)/CPP.c -o $(CMP_DIR)/CPP.o