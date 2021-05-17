CXX			:= gcc
CXX_FLAGS	:= -c -Wall -Wextra

MAIN_FILE	:= Main
SRC_DIR		:= ./src
EXEC_FILE	:= zsat

all: clean compile execute

clean:
	@echo "🧹 Cleaning ..."
	-rm $(MAIN_FILE).o $(EXEC_FILE) 

compile: $(MAIN_FILE).o
	@echo "🚧 Building ..."
	$(CXX) $(MAIN_FILE).o -o $(EXEC_FILE)

$(MAIN_FILE).o:
	$(CXX) $(CXX_FLAGS) $(SRC_DIR)/$(MAIN_FILE).c

execute:
	@echo "🚀 Executing ..."
	./$(EXEC_FILE) tests/cpp.cpp