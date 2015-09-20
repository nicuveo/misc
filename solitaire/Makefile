OUT=solitaire
IN=$(wildcard *.cc)

# $(OUT): $(IN) Makefile *.cc *.hh *.hxx
# 	g++ -W -Wall -Wextra -ansi -pedantic -g3 -ggdb3 $(IN) -o $(OUT)

$(OUT): $(IN) Makefile *.cc *.hh *.hxx
	g++ -W -Wall -Wextra -ansi -pedantic -O3 -DNDEBUG $(IN) -o $(OUT)
