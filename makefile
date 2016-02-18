# Inclusion Dependency Args

SUFFIXES 	+= .d
NODEPS 		:= clean tags svn

# Variables Entries

MAINDIR = console
NAME 	= Infinity
TARGET  = .

# Main Entries

PROGRAMS = dll exe fastdll fastexe

COMPILER 	:= g++
BASEFLAGS 	:= -std=c++11 -c -MMD -MP -Wall -Wfatal-errors
DLLOPTIONS 	:= -shared -Wl,--out-implib,$(NAME).a
EXEOPTIONS  := 
#EXEOPTIONS  := -Wl,--subsystem,windows

SOURCEDIR 	:= source
OBJDIR 		:= obj
LIBDIR 		:= lib

SRCDIRS 	:= $(shell ls $(SOURCEDIR)/)
INCLUDES 	:= -I./include -I./depend
LIBS 		:= -lmingw32 $(shell ls -d $(LIBDIR)/*) -lglu32 -lopengl32

SOURCES := $(shell find $(SOURCEDIR)/ -name '*.cpp')
OBJDUMP := $(patsubst $(SOURCEDIR)/%.cpp,%.o,$(SOURCES))

MAINSRC := $(shell find $(MAINDIR)/ -name '*.cpp')
MAINDMP := $(patsubst $(MAINDIR)/%.cpp,%.o,$(MAINSRC))

EXE_ARG := -DINFI_BUILD_AS_EXE
DLL_ARG := -DINFI_BUILD_AS_DLL

define build_progs
	$(1)_OBJECTS = $(addprefix $(OBJDIR)/$(1)/,$(OBJDUMP))
	$(1)_MAIN = $(addprefix $(OBJDIR)/$(1)/$(MAINDIR)/,$(MAINDMP))
endef

$(foreach prog,$(PROGRAMS),$(eval $(call build_progs,$(prog))))
RECIPES = $(patsubst %,$(OBJDIR)/%/%.o, $(PROGRAMS))
MAINREP = $(patsubst %,$(OBJDIR)/%/$(MAINDIR)/%.o, $(PROGRAMS))

define mkdir_subobjs
	@echo $(OBJDIR)/$(1)
	mkdir -p $(OBJDIR)/$(1)
	for dir in $(SRCDIRS); \
	do \
		echo $(OBJDIR)/$(1)/$$dir; \
		mkdir -p $(OBJDIR)/$(1)/$$dir; \
	done
endef
define mkdir_objs
	@echo $(OBJDIR)
	mkdir -p $(OBJDIR)
endef
define mkdir_main
	@echo $(OBJDIR)/$(1)/$(MAINDIR)
	mkdir -p $(OBJDIR)/$(1)/$(MAINDIR)
endef

dll: FILE_ARG 	= $(DLL_ARG)
dll: CPPFLAGS 	= $(BASEFLAGS)
dll: SUBDIR		= dll
dll: build_dump $(dll_OBJECTS)
	$(COMPILER) $(dll_OBJECTS) $(LIBS) -o $(TARGET)/$(NAME).dll $(DLLOPTIONS)

exe: FILE_ARG 	= $(EXE_ARG)
exe: CPPFLAGS 	= $(BASEFLAGS)
exe: SUBDIR		= exe
exe: build_maindump $(exe_OBJECTS) $(exe_MAIN)
	$(COMPILER) $(exe_OBJECTS) $(exe_MAIN) $(LIBS) -o $(TARGET)/$(NAME).exe $(EXEOPTIONS)
	$(TARGET)/$(NAME).exe
	
fastdll: FILE_ARG 	= $(DLL_ARG)
fastdll: CPPFLAGS 	= $(BASEFLAGS) -O3
fastdll: SUBDIR		= fastdll
fastdll: build_dump $(fastdll_OBJECTS)
	$(COMPILER) $(fastdll_OBJECTS) $(LIBS) -o $(TARGET)/$(NAME).dll $(DLLOPTIONS) 
	
fastexe: FILE_ARG 	= $(EXE_ARG)
fastexe: CPPFLAGS 	= $(BASEFLAGS) -O3
fastexe: SUBDIR		= fastexe
fastexe: build_maindump $(fastexe_OBJECTS) $(fastexe_MAIN)
	$(COMPILER) $(fastexe_OBJECTS) $(fastexe_MAIN) $(LIBS) -o $(TARGET)/$(NAME).exe $(EXEOPTIONS)
	$(TARGET)/$(NAME).exe

$(RECIPES): $(SOURCEDIR)/%.cpp
	$(COMPILER) $(CPPFLAGS) $(FILE_ARG) $(INCLUDES) $< -o $@
	
$(MAINREP): $(MAINDIR)/%.cpp
	$(COMPILER) $(CPPFLAGS) $(FILE_ARG) $(INCLUDES) $< -o $@
	
build_dump:
	@$(call mkdir_objs)
	@$(call mkdir_subobjs,$(SUBDIR))
	
build_maindump: build_dump
	@$(call mkdir_main,$(SUBDIR))
	
define make_includes
	-include $(patsubst %.o,%.d,$($(1)_OBJECTS))
endef

$(foreach prog,$(PROGRAMS),$(eval $(call make_includes,$(prog))))