SRC_FILES = $(wildcard src/**/*.cpp) $(wildcard src/*.cpp)
OBJ_FILES = $(SRC_FILES:.cpp=.o)

all: chess

chess : $(OBJ_FILES)
	g++ -std=c++17 -I/usr/local/include $(OBJ_FILES) -L/usr/local/lib -lraylib -lm -ldl -pthread -o chess

%.o: %.cpp
	g++ -std=c++17 -I/usr/local/include -c $< -o $@

clean:
	rm -rf $(OBJ_FILES)