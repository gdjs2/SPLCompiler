CC=gcc
FLEX=flex
BISON=bison
LDFLAGS=
CPPFLAGS=

SRC_DIR=./src
LEX_SRC=splc.l
YACC_SRC=splc.y

.lex: $(SRC_DIR)/$(LEX_SRC)
	$(FLEX) -o $(SRC_DIR)/lex.yy.c $<
.syntax: $(SRC_DIR)/$(YACC_SRC)
	$(BISON) -o $(SRC_DIR)/splc.tab.c -d $<
.PHONY: clean

clean:
	@rm $(SRC_DIR)/lex.yy.c
	@rm $(SRC_DIR)/splc.tab.c $(SRC_DIR)/splc.tab.h
