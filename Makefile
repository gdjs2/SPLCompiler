CC=g++
FLEX=flex
BISON=bison
FLAGS=-lfl -ly -std=c++11 -Iinc

SRC_DIR=./src
LEX_SRC=splc.l
YACC_SRC=splc.yy
TREE_NODE_SRC=tree_node.cpp
TYPE_SRC=type.c

splc: .lex .syntax .bin $(SRC_DIR)/$(TREE_NODE_SRC)
	$(CC) -o ./bin/$@ $(FLAGS) $(LDFLAGS) $(CPPFLAGS) $(SRC_DIR)/splc.tab.cc $(SRC_DIR)/$(TREE_NODE_SRC)
texical.o: .lex .syntax .bin
	$(CC) -o ./bin/$@ -lfl $(LDFLAGS) $(CPPFLAGS) $(SRC_DIR)/lex.yy.c 
.lex: $(SRC_DIR)/$(LEX_SRC)
	$(FLEX) -o $(SRC_DIR)/lex.yy.c $<
.syntax: $(SRC_DIR)/$(YACC_SRC)
	$(BISON) -o $(SRC_DIR)/splc.tab.cc -d $<
.bin:
	@mkdir -p bin
.PHONY: clean

clean:
	@rm -f $(SRC_DIR)/lex.yy.c
	@rm -f $(SRC_DIR)/splc.tab.c $(SRC_DIR)/splc.tab.h
	@rm -rf ./bin
