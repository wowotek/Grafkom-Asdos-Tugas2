CC = g++
CFLAGS = -W -Wall 
CDEP = -lGL -lGLU -lglut

all: clean Tugas

clean:
	@rm binary/*

shape.o: src/shape.cpp src/shape.hpp
	${CC} ${CFLAGS} -c src/shape.cpp -o binary/shape.o

object.o: src/object.hpp src/object.cpp
	${CC} ${CFLAGS} -c src/object.cpp -o binary/object.o

render.o: src/render.cpp src/render.hpp
	${CC} ${CFLAGS} -c src/render.cpp -o binary/render.o

main.o: src/main.cpp
	${CC} ${CFLAGS} -c src/main.cpp -o binary/main.o

Tugas: shape.o object.o render.o main.o
	${CC} ${CFLAGS} binary/main.o binary/shape.o binary/render.o binary/object.o ${CDEP} -o binary/Tugas