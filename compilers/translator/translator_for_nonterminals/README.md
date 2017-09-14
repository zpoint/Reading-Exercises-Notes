# translator for nonterminals

	cd compilers/translator/translator_for_nonterminals/
	g++ -std=c++11 translator_for_nonterminals.cpp

    ./a.out
    Enter something, I will parse:
    3+4
    34+
    Enter something, I will parse:
    3+4-6
    34+6-
    Enter something, I will parse:
    5-8+2
    58-2+
    Enter something, I will parse: