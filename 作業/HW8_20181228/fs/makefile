BIN=bin
OBJ=obj
SRC=src
.PHONY: clean $(BIN) $(OBJ)

all: clean dirs $(BIN)/hw8 #  $(BIN)/HelloWorldApp

# $(BIN)/HelloWorldApp: hello_world.cpp hello_world.h  $(OBJ)/text_frame.o | $(BIN)
# 	g++ -std=c++11 $< $(OBJ)/text_frame.o `wx-config --libs` `wx-config --cxxflags` -o $@ -pthread
#

$(BIN)/hw8: $(SRC)/windows.cpp $(OBJ)/texts.o $(SRC)/windows.h $(SRC)/node.h $(SRC)/tree_frame.h $(SRC)/node_iterator.h $(SRC)/node_builder.h | $(BIN)
	g++ -std=c++11 $< $(OBJ)/texts.o `wx-config --libs` `wx-config --cxxflags` -o $@ -lpthread

$(OBJ)/texts.o: $(SRC)/texts.cpp $(SRC)/texts.h | $(OBJ)
	g++ -std=c++11 -c $< `wx-config --cxxflags` -o $@

dirs:
	mkdir -p $(BIN) $(OBJ)

clean:
	rm -rf $(BIN) $(OBJ)
