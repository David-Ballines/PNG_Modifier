EXENAME = images
OBJS = main.o PNG.o HSLAPixel.o lodepng.o Image.o

CXX = clang++
CXXFLAGS = $(stuff) -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic
LD = clang++
LDFLAGS = -std=c++1y -stdlib=libc++ -lpthread -lm

all : $(EXENAME)

$(EXENAME) : $(OBJS)
	$(LD) $(OBJS) $(LDFLAGS) -o $(EXENAME)

main.o : main.cpp Image.h stuff/PNG.h stuff/HSLAPixel.h
	$(CXX) $(CXXFLAGS) main.cpp

Image.o : Image.cpp Image.h
	$(CXX) $(CXXFLAGS) Image.cpp

PNG.o : stuff/PNG.cpp stuff/PNG.h stuff/HSLAPixel.h stuff/lodepng/lodepng.h
	$(CXX) $(CXXFLAGS) stuff/PNG.cpp

HSLAPixel.o : stuff/HSLAPixel.cpp stuff/HSLAPixel.h 
	$(CXX) $(CXXFLAGS) stuff/HSLAPixel.cpp

lodepng.o : stuff/lodepng/lodepng.cpp stuff/lodepng/lodepng.h 
	$(CXX) $(CXXFLAGS) stuff/lodepng/lodepng.cpp

clean : 
				-rm -f *.o $(EXENAME)