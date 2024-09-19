# Compiler
CC = cl
CXX = $(CC)
LD = link

# Compiler Flags
CXXFLAGS = /Zi /W4 /Iinclude
LDFLAGS =

# Directories
OBJDIR = obj\Debug\src
BINDIR = bin\Debug
SRCDIR = src

# Source files and object files
SOURCES = $(SRCDIR)\String.cpp main.cpp
OBJECTS = $(OBJDIR)\String.obj $(OBJDIR)\main.obj

# Target executable
TARGET = $(BINDIR)\Ex1_String.exe

# Makefile rules
all: $(TARGET)

$(TARGET): $(OBJECTS)
	@mkdir $(BINDIR)
	cmd.exe /c "$(VCINSTALLDIR)bin\link.exe" $(LDFLAGS) /OUT:$(TARGET) $(OBJECTS)

$(OBJDIR)\%.obj: $(SRCDIR)\%.cpp
	@mkdir $(OBJDIR)
	cmd.exe /c "$(VCINSTALLDIR)bin\cl.exe" $(CXXFLAGS) /c /Fo$@ $<

$(OBJDIR)\main.obj: main.cpp
	@mkdir $(OBJDIR)
	cmd.exe /c "$(VCINSTALLDIR)bin\cl.exe" $(CXXFLAGS) /c /Fo$(OBJDIR)\main.obj main.cpp

clean:
	del /Q $(OBJDIR)\*.obj
	rmdir /S /Q $(OBJDIR)
	del /Q $(TARGET)

.PHONY: all clean
