CXX = g++
CXXFLAGS += -std=c++11
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g#

OBJS = inputValidation.o Menu.o BlankSpace.o Character.o Dragon.o DragonRoom.o Dungeon.o FinalRoom.o Muk.o Space.o StoryRoom.o WiseManRoom.o Main.o

SRCS = inputValidation.cpp Menu.cpp BlankSpace.cpp Character.cpp Dragon.cpp DragonRoom.cpp Dungeon.cpp FinalRoom.cpp Muk.cpp Space.cpp StoryRoom.cpp WiseManRoom.cpp Main.cpp

HEADERS = inputValidation.h Menu.h BlankSpace.h Character.h Dragon.h DragonRoom.h Dungeon.h FinalRoom.h Muk.h Space.h StoryRoom.h WiseManRoom.h

Amul Ghul: ${OBJS} ${HEADERS}
		${CXX} ${OBJS} -o AmulGhul

${OBJS}: ${SRCS} ${HEADERS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o AmulGhul
