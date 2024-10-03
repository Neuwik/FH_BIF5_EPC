# Compiler settings
CXX_GPP = g++
CXX_CLANG = clang++
CXXFLAGS = -g -Wall -Iinclude

# Directories for g++
GPP_OBJDIR = gpp/obj
GPP_BINDIR = gpp/bin
GPP_TARGET = $(GPP_BINDIR)/Ex1_String.exe

# Directories for clang++
CLANG_OBJDIR = clang/obj
CLANG_BINDIR = clang/bin
CLANG_TARGET = $(CLANG_BINDIR)/Ex1_String.exe

# Source files
SRCDIR = ./
SOURCES = $(SRCDIR)/String.cpp main.cpp

# Object files for g++
GPP_OBJECTS = $(GPP_OBJDIR)/String.o $(GPP_OBJDIR)/main.o

# Object files for clang++
CLANG_OBJECTS = $(CLANG_OBJDIR)/String.o $(CLANG_OBJDIR)/main.o

# Default target: build both g++ and clang++
all: gpp clang

# Build with g++
gpp: $(GPP_TARGET)

$(GPP_TARGET): $(GPP_OBJECTS)
	@mkdir -p $(GPP_BINDIR)
	$(CXX_GPP) $(CXXFLAGS) -o $@ $(GPP_OBJECTS)

$(GPP_OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(GPP_OBJDIR)
	$(CXX_GPP) $(CXXFLAGS) -c -o $@ $<

# Build with clang++
clang: $(CLANG_TARGET)

$(CLANG_TARGET): $(CLANG_OBJECTS)
	@mkdir -p $(CLANG_BINDIR)
	$(CXX_CLANG) $(CXXFLAGS) -o $@ $(CLANG_OBJECTS)

$(CLANG_OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(CLANG_OBJDIR)
	$(CXX_CLANG) $(CXXFLAGS) -c -o $@ $<

# Clean both g++ and clang++ builds
clean:
	rm -rf $(GPP_OBJDIR) $(GPP_BINDIR) $(CLANG_OBJDIR) $(CLANG_BINDIR)

.PHONY: all clean gpp clang
