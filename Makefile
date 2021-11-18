CC=g++
FLEX=flex
BISON=bison
FLAGS=-lfl -ly -std=c++17 -Iinc $(CFLAG)

SRC_DIR=./src
INC_DIR=./inc
LEX_SRC=splc.ll
YACC_SRC=splc.yy
TREE_NODE_SRC=tree_node.cpp
TYPE_SRC=type.cpp

splc: .lex .syntax .bin $(SRC_DIR)/$(TREE_NODE_SRC) $(SRC_DIR)/$(TYPE_SRC)
	$(CC) -o ./bin/$@ $(FLAGS) $(LDFLAGS) $(CPPFLAGS) $(SRC_DIR)/splc.tab.cc $(SRC_DIR)/$(TREE_NODE_SRC) $(SRC_DIR)/$(TYPE_SRC)
texical.o: .lex .syntax .bin
	$(CC) -o ./bin/$@ -lfl $(LDFLAGS) $(CPPFLAGS) $(SRC_DIR)/lex.yy.cc
.lex: $(SRC_DIR)/$(LEX_SRC)
	$(FLEX) -o $(SRC_DIR)/lex.yy.cc --header-file=$(INC_DIR)/lex.yy.hh $<
.syntax: $(SRC_DIR)/$(YACC_SRC)
	$(BISON) -o $(SRC_DIR)/splc.tab.cc --header=$(INC_DIR)/splc.tab.hh $<
.bin:
	@mkdir -p bin
.PHONY: clean

clean:
	@rm -f $(SRC_DIR)/lex.yy.cc $(INC_DIR)/lex.yy.hh
	@rm -f $(SRC_DIR)/splc.tab.cc $(INC_DIR)/splc.tab.hh
	@rm -rf ./bin
