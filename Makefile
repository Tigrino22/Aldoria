################################################
################################################
##########	Makefile de Aldoria		############
################################################
################################################

NAME = Aldoria
CXX = g++
CPPFLAGS = -std=c++17 -Wall -Wextra -Iinclude 
LIBS = -L./lib -lsfml-window -lsfml-graphics -lsfml-system -lsfml-audio
EXEC = bin/Aldoria
DEBUG_FLAGS = -O0 -g
RELEASE_FLAGS = -O2
SRC = $(wildcard src/*.cpp)
OBJ = $(SRC:.cpp=.o)

################################################
##########	Compilation principale 	############
################################################

# Debug target
debug : CPPFLAGS += $(DEBUG_FLAGS)
debug : $(EXEC)

# Release target
release : CPPFLAGS += $(RELEASE_FLAGS)
release : $(EXEC) clean

$(EXEC) : $(OBJ)
	$(CXX) -o $(EXEC) $(OBJ) $(LIBS)
#	Add an RPATH to the executable
	install_name_tool -add_rpath @loader_path/../lib $(EXEC)

%.o : %.c
	$(CXX) $(CPPFLAGS) -o $< -c $@


################################################
###########		Autres commandes 	############
################################################

clean:
	rm -rf $(OBJ)

mrproper :

zip :
