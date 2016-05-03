RESULT          = extension.so


ifdef CXX
	COMPILER			= ${CXX}
	LINKER				=  ${CXX}
else
	COMPILER			= g++
	LINKER				= g++
endif


LIBRARY_DIR		= $(shell php-config --extension-dir)

RM              = rm -f
CPP_FLAGS       = -Wall -c -I. -O2 -std=c++11
LD_FLAGS        = -Wall -shared -O2 -undefined dynamic_lookup

SOURCES			= $(wildcard *.cpp)
OBJECTS         = $(SOURCES:%.cpp=%.o)

all:	 ${OBJECTS} ${RESULT}

cycle:	clean ${OBJECTS} ${RESULT} install
		php extension.php

${RESULT}: ${OBJECTS}
		${LINKER} ${LD_FLAGS} -o $@ ${OBJECTS} -lphpcpp

clean:
		${RM} *.obj *~* ${OBJECTS} ${RESULT}

${OBJECTS}:
		${COMPILER} ${CPP_FLAGS} -fpic -o $@ ${@:%.o=%.cpp}

install:
		cp -f ${RESULT} ${LIBRARY_DIR}
