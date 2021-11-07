run: program
	@./program
all: *.cpp
	@g++ -std=c++17 -Werror -Wextra -Wall -O0 -g -pedantic -lm -fsanitize=address,leak,undefined $^ -o program

clean:
	@rm program
