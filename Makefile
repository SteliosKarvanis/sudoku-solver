run: program
	@./program
all: *.cpp
	@g++ -std=c++17 -Werror -Wextra -Wall -O0 -g -pedantic -lm -fsanitize=address,leak,undefined $^ -o program


# for i in {1..10}; do ./program < Casos/$i.in | diff - Casos/$i.out; done
