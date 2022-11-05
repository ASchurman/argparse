CPP      = cl
CPPFLAGS = /EHsc /std:c++20
SOURCES  = main.cpp argparse.cpp
OBJS     = $(SOURCES:.cpp=.obj)

all: argparse.exe

argparse.exe: $(OBJS)
	$(CPP) $(CPPFLAGS) $(OBJS) /link /out:argparse.exe

main.obj: argparse.h
argparse.obj: argparse.h

clean:
	del argparse.exe *.obj
