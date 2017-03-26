# General Purpose x86/x64 Makefile Script

MAINDIR = examples
EXENAME = example
DLLNAME = Infinity

TARGET  	:= bin
TARGET32  	:= bin/x86
TARGET64  	:= bin/x64

COMPILER 	:= g++
BASEFLAGS 	:= -std=c++11 -c -MMD -MP -Wall -Wfatal-errors -O3

INCLUDES 	:= -Iinclude -Idepend/include

LIBDIR32 	:= lib/x86
LIBDIR64 	:= lib/x64

DLLLIB32	:= $(LIBDIR32)/$(DLLNAME).a
DLLLIB64	:= $(LIBDIR64)/$(DLLNAME).a

DLLOPT32	:= -shared -Wl,--out-implib,$(DLLLIB32)
DLLOPT64	:= -shared -Wl,--out-implib,$(DLLLIB64)

LIBS 		:= -lglu32 -lopengl32 -lmingw32 -mwindows -Wl,--no-undefined -lm -ldinput8 -ldxguid -ldxerr8 -luser32 -lgdi32 -lwinmm -limm32 -lole32 -loleaut32 -lshell32 -lversion -luuid -static-libgcc
LIBS32 		:= $(shell ls -d $(LIBDIR32)/depend/*) $(LIBS)
LIBS64 		:= $(shell ls -d $(LIBDIR64)/depend/*) $(LIBS)

SOURCEDIR 	:= source
SRCDIRS 	:= $(shell ls $(SOURCEDIR)/)
SOURCES 	:= $(shell find $(SOURCEDIR)/ -name '*.cpp')

OBJDIR 		:= obj

OBJDIREXE32 := $(OBJDIR)/x86/exe
OBJDIREXE64 := $(OBJDIR)/x64/exe
OBJDIRDLL32 := $(OBJDIR)/x86/dll
OBJDIRDLL64 := $(OBJDIR)/x64/dll

OBJSUBEXE32	:= $(addprefix $(OBJDIREXE32)/, $(SRCDIRS))
OBJSUBEXE64	:= $(addprefix $(OBJDIREXE64)/, $(SRCDIRS))
OBJSUBDLL32	:= $(addprefix $(OBJDIRDLL32)/, $(SRCDIRS))
OBJSUBDLL64	:= $(addprefix $(OBJDIRDLL64)/, $(SRCDIRS))
OBJDUMP 	:= $(patsubst $(SOURCEDIR)/%.cpp, %.o, $(SOURCES))

OBJEXE32	:= $(addprefix $(OBJDIREXE32)/, $(OBJDUMP))
OBJEXE64	:= $(addprefix $(OBJDIREXE64)/, $(OBJDUMP))
OBJDLL32	:= $(addprefix $(OBJDIRDLL32)/, $(OBJDUMP))
OBJDLL64	:= $(addprefix $(OBJDIRDLL64)/, $(OBJDUMP))

MAINSRC 	:= $(shell find $(MAINDIR)/ -name '*.cpp')
MAINDUMP 	:= $(notdir $(MAINSRC:.cpp=.o))

MAINDIREXE32:= $(OBJDIR)/main/x32/exe/$(MAINDIR)
MAINDIREXE64:= $(OBJDIR)/main/x64/exe/$(MAINDIR)
MAINDIRDLL32:= $(OBJDIR)/main/x32/dll/$(MAINDIR)
MAINDIRDLL64:= $(OBJDIR)/main/x64/dll/$(MAINDIR)

MAINEXE32  	:= $(addprefix $(MAINDIREXE32)/, $(MAINDUMP))
MAINEXE64  	:= $(addprefix $(MAINDIREXE64)/, $(MAINDUMP))
MAINDLL32  	:= $(addprefix $(MAINDIRDLL32)/, $(MAINDUMP))
MAINDLL64  	:= $(addprefix $(MAINDIRDLL64)/, $(MAINDUMP))

EXE_ARG 	:= -DEXPORT_AS_EXE -ggdb
DLL_ARG 	:= -DEXPORT_AS_DLL

x64: folder_x64_dll x64dll $(MAINDLL64)
	$(COMPILER) $(MAINDLL64) $(DLLLIB64) -o $(TARGET64)/$(EXENAME).exe
	cd $(TARGET64); ./$(EXENAME).exe; cd -

x64dll_main: folder_x64_dll $(MAINDLL64)
	$(COMPILER) $(MAINDLL64) $(DLLLIB64) -o $(TARGET64)/$(EXENAME).exe
	cd $(TARGET64); ./$(EXENAME).exe; cd -

x64dll: folder_x64lib_dll $(OBJDLL64)
	$(COMPILER) $(OBJDLL64) $(LIBS64) -o $(TARGET64)/$(DLLNAME).dll $(DLLOPT64)

x64exe: folder_x64lib_exe folder_x64_exe $(OBJEXE64) $(MAINEXE64)
	$(COMPILER) $(OBJEXE64) $(MAINEXE64) $(LIBS64) -o $(TARGET64)/$(EXENAME).exe
	./$(TARGET64)/$(EXENAME).exe

folder_x64_exe:
	$(shell mkdir -p $(MAINDIREXE64))

folder_x64lib_exe:
	$(shell mkdir -p $(OBJSUBEXE64))

folder_x64_dll:
	$(shell mkdir -p $(MAINDIRDLL64))

folder_x64lib_dll:
	$(shell mkdir -p $(OBJSUBDLL64))

$(OBJDIREXE64)/%.o: $(SOURCEDIR)/%.cpp
	$(COMPILER) $(BASEFLAGS) $(EXE_ARG) $(INCLUDES) $< -o $@

$(OBJDIRDLL64)/%.o: $(SOURCEDIR)/%.cpp
	$(COMPILER) $(BASEFLAGS) $(DLL_ARG) $(INCLUDES) $< -o $@

$(MAINDIREXE64)/%.o: $(MAINDIR)/%.cpp
	$(COMPILER) $(BASEFLAGS) $(EXE_ARG) $(INCLUDES) $< -o $@

$(MAINDIRDLL64)/%.o: $(MAINDIR)/%.cpp
	$(COMPILER) $(BASEFLAGS) $(INCLUDES) $< -o $@

-include $(OBJEXE32:.o=.d)
-include $(OBJEXE64:.o=.d)
-include $(MAINEXE32:.o=.d)
-include $(MAINEXE64:.o=.d)

-include $(OBJDLL32:.o=.d)
-include $(OBJDLL64:.o=.d)
-include $(MAINDLL32:.o=.d)
-include $(MAINDLL64:.o=.d)