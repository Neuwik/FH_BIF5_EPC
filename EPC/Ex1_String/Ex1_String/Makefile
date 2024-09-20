# Compiler
# CXX = g++
CXX = clang++
CXXFLAGS = -g -Wall -Iinclude

# Directories
OBJDIR = Clang/obj
BINDIR = Clang/bin
#OBJDIR = gpp/obj
#BINDIR = gpp/bin

SRCDIR = ./

# Target executable
TARGET = $(BINDIR)/Ex1_String.exe

# Source files
SOURCES = $(SRCDIR)/String.cpp main.cpp
OBJECTS = $(OBJDIR)/String.o $(OBJDIR)/main.o

# Makefile rules
all: $(TARGET)

$(TARGET): $(OBJECTS)
	@mkdir -p $(BINDIR)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJECTS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(OBJDIR)/main.o: main.cpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c -o $(OBJDIR)/main.o main.cpp

clean:
	rm -rf $(OBJDIR) $(BINDIR)

.PHONY: all clean