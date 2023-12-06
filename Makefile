CXX	  = /usr/bin/clang++
CFLAGS  = -std=c++20 -g
LDFLAGS = -llua

BUILDDIR = build
SOURCEDIR = src

SOURCES = $(wildcard $(SOURCEDIR)/*.cpp)
OBJECTS = $(patsubst $(SOURCEDIR)/%.cpp, $(BUILDDIR)/%.o, $(SOURCES))

NAME = solpg
BINARY = $(BUILDDIR)/solpg

RM = rm -rf
MKDIR = mkdir

.PHONY: all clean run

all: $(BINARY)

$(BUILDDIR)/:
	$(MKDIR) -p $(BUILDDIR)

$(BINARY): $(BUILDDIR)/$(OBJECTS)
	$(CXX) $(CFLAGS) $(LDFLAGS) $(OBJECTS) -o $(BINARY)

$(BUILDDIR)/%.o: $(SOURCEDIR)/%.cpp $(SOURCEDIR)/%.hpp
	$(CXX) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(BINARY)
	$(RM) $(BUILDDIR)

run: $(BINARY)
	$(BINARY)
