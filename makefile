CXX			:= gcc
CXX_FLAGS	:= -c -Wall -Wextra -Werror

MAIN_FILE	:= Main
LIB_OBJ 	:= ANSI.o C.o CPP.o PYTHON.o SHELL.o TEXT.o
SRC_DIR		:= ./src
LIB_DIR		:= ./src/lib
CMP_DIR 	:= ./cmp
EXEC_FILE	:= zsat

all: clean compile execute

clean:
	@echo "🧹 Cleaning ..."
	-rm $(CMP_DIR)/*

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

PYTHON.o:
	$(CXX) $(CXX_FLAGS) -c $(LIB_DIR)/PYTHON.c -o $(CMP_DIR)/PYTHON.o

SHELL.o:
	$(CXX) $(CXX_FLAGS) -c $(LIB_DIR)/SHELL.c -o $(CMP_DIR)/SHELL.o

TEXT.o:
	$(CXX) $(CXX_FLAGS) -c $(LIB_DIR)/TEXT.c -o $(CMP_DIR)/TEXT.o

ANSI.o:
	$(CXX) $(CXX_FLAGS) -c $(LIB_DIR)/ANSI.c -o $(CMP_DIR)/ANSI.o