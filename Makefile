CC := g++
SRCFOLDER := src
BUILDFOLDER := build
SRCFILE := $(wildcard ${SRCFOLDER}/*.cpp)
OBJECTFILE := $(patsubst ${SRCFOLDER}/%.cpp,${BUILDFOLDER}/%.o,${SRCFILE})
CFLAGS = -ltins -std=c++11 -g -Wall
CFLAGS += -Iinclude

PHONY: all clean main

all: clean main

main: ${BUILDFOLDER}/main

${BUILDFOLDER}/main: ${OBJECTFILE}
	${CC} -o $@ $^ ${CFLAGS} 

${BUILDFOLDER}/%.o: ${SRCFOLDER}/%.cpp
	${CC} -c -o $@ $< ${CFLAGS}

clean:
	rm -rf ${BUILDFOLDER}
	mkdir ${BUILDFOLDER}
