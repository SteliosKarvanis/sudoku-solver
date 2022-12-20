run: program
	@./program
all: *.cpp
	@g++ -std=c++17 -Werror -Wextra -Wall -O0 -g -pedantic -lm -fsanitize=address,leak,undefined $^ -o bin/program

clean:
	@rm program
