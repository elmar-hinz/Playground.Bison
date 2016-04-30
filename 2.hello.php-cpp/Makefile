RESULT          = extension.so
CPP             = g++-5
LD              = g++-5

LIBRARY_DIR		= $(shell php-config --extension-dir)

RM              = rm -f
CPP_FLAGS       = -Wall -c -I. -O2 -std=c++11
LD_FLAGS        = -Wall -shared -O2

SOURCES			= $(wildcard *.cpp)
OBJECTS         = $(SOURCES:%.cpp=%.o)

all:	${OBJECTS} ${RESULT}

${RESULT}: ${OBJECTS}
		${LD} ${LD_FLAGS} -o $@ ${OBJECTS} -lphpcpp

clean:
		${RM} *.obj *~* ${OBJECTS} ${RESULT}

${OBJECTS}:
		${CPP} ${CPP_FLAGS} -fpic -o $@ ${@:%.o=%.cpp}

install:
		cp -f ${RESULT} ${LIBRARY_DIR}
