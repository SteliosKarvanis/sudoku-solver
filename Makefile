run: program
	@./program
all: *.cpp
	@g++ -std=c++17 -Werror -Wextra -Wall -O0 -g -pedantic -lm $^ -o program

clean:
	@rm program
# for i in {1..10}; do ./program < Casos/$i.in | diff - Casos/$i.out; done
