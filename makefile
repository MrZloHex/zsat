CXX			:= gcc
CXX_FLAGS	:= -c -Wall -Wextra -Werror

MAIN_FILE	:= Main
SRC_DIR		:= ./src
CMP_DIR 	:= ./cmp
EXEC_FILE	:= zsat

all: clean compile execute

clean:
	@echo "🧹 Cleaning ..."
	-rm $(CMP_DIR)/*

execute:
	@echo "🚀 Executing ..."
	$(CMP_DIR)/$(EXEC_FILE) tests/c.c

compile: $(MAIN_FILE).o
	@echo "🚧 Building ..."
	$(CXX) $(CMP_DIR)/*.o -o $(CMP_DIR)/$(EXEC_FILE)

$(MAIN_FILE).o:
	$(CXX) $(CXX_FLAGS) -c $(SRC_DIR)/$(MAIN_FILE).c -o $(CMP_DIR)/$(MAIN_FILE).o
