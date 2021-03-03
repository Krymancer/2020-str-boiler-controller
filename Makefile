CC=gcc
IPATH=-Iinc/
SRC=src
OBJ=obj
BIN=bin
FLAGS=-lpthread -w 

SRC_FILES=$(wildcard $(SRC)/*.c)
OBJ_FILES=$(patsubst $(SRC)/%.c,$(OBJ)/%.o,$(SRC_FILES))

all: app
	@echo "Sucess"
	
clean:
	@rm -rf $(OBJ)/*.o $(BIN)/*

app: $(OBJ_FILES)
	@$(CC) -o $(BIN)/$@ $^ $(FLAGS)

$(OBJ)/%.o: $(SRC)/%.c
	@$(CC) $(IPATH) $(FLAGS) -c -o $@ $<

run:
	@$(BIN)/app $(ARGS)