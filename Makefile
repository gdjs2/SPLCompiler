CC=gcc
FLEX=flex
BISON=bison
FLAGS=-lfl -ly

SRC_DIR=./src
LEX_SRC=splc.l
YACC_SRC=splc.y

splc: .lex .syntax .bin
	$(CC) -o ./bin/$@ $(FLAGS) $(LDFLAGS) $(CPPFLAGS) $(SRC_DIR)/splc.tab.c
texical.o: .lex .syntax .bin
	$(CC) -o ./bin/$@ -lfl $(LDFLAGS) $(CPPFLAGS) $(SRC_DIR)/lex.yy.c 
.lex: $(SRC_DIR)/$(LEX_SRC)
	$(FLEX) -o $(SRC_DIR)/lex.yy.c $<
.syntax: $(SRC_DIR)/$(YACC_SRC)
	$(BISON) -o $(SRC_DIR)/splc.tab.c -d $<
.bin:
	@mkdir -p bin
.PHONY: clean

clean:
	@rm -f $(SRC_DIR)/lex.yy.c
	@rm -f $(SRC_DIR)/splc.tab.c $(SRC_DIR)/splc.tab.h
	@rm -rf ./bin
