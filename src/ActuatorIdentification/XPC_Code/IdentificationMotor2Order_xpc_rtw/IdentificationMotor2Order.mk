# Copyright 1996-2010 The MathWorks, Inc.
#
# File    : xpc_vc.tmf 
#
# $Revision: 1.1.6.29 $
# $Date: 2010/11/17 12:18:09 $
#
# Abstract:
#       Template makefile for building a Windows NT-based
#       stand-alone generic real-time version of Simulink model using
#       generated C code and the
#          Microsoft Visual C/C++ compiler versions: 6.0, 7.1, 8.0
#
#       Note that this template is automatically customized by the Real-Time
#       Workshop build procedure to create "<model>.mk"
#
#       The following defines can be used to modify the behavior of the
#       build:
#
#    OPT_OPTS       - Optimization option. Default is -O2. To enable
#                     debugging specify as OPT_OPTS=-Zd.
#    OPTS           - User specific options.
#    USER_SRCS      - Additional user sources, such as files needed by
#                     S-functions.
#    USER_INCLUDES  - Additional include paths
#                     (i.e. USER_INCLUDES="-Iwhere-ever -Iwhere-ever2")


#------------------------ Macros read by make_rtw -----------------------------
#
# The following macros are read by the code generation build procedure:
#
#  MAKECMD         - This is the command used to invoke the make utility
#  HOST            - What platform this template makefile is targeted for
#                    (i.e. PC or UNIX)
#  BUILD           - Invoke make from the code generation build procedure
#                    (yes/no)?
#  SYS_TARGET_FILE - Name of system target file.
HOST            = PC
BUILD           = yes
MAKECMD         = nmake
SYS_TARGET_FILE = xpctarget.tlc
COMPILER_TOOL_CHAIN = vc

DEBUG_BUILD     = 0

#---------------------- Tokens expanded by make_rtw ---------------------------
#
# The following tokens, when wrapped with "|>" and "|<" are expanded by the
# build procedure.
#
#  MODEL_NAME      - Name of the Simulink block diagram
#  MODEL_MODULES   - Any additional generated source modules
#  MAKEFILE_NAME   - Name of makefile created from template makefile <model>.mk
#  MATLAB_ROOT     - Path to were MATLAB is installed.
#  MATLAB_BIN      - Path to MATLAB executable.
#  S_FUNCTIONS     - List of S-functions.
#  S_FUNCTIONS_LIB - List of S-functions libraries to link.
#  NUMST           - Number of sample times
#  TID01EQ         - yes (1) or no (0): Are sampling rates of continuous task
#                    (tid=0) and 1st discrete task equal.
#  NCSTATES        - Number of continuous states
#  BUILDARGS       - Options passed in at the command line.
#  MULTITASKING    - yes (1) or no (0): Is solver mode multitasking
#  EXT_MODE        - yes (1) or no (0): Build for external mode
#  MEX_OPT_FILE    - Original file name of the mexopt.bat.

MODEL           = IdentificationMotor2Order
MODULES         = IdentificationMotor2Order_capi.c IdentificationMotor2Order_data.c rtGetInf.c rtGetNaN.c rt_logging.c rt_logging_mmi.c rt_matrx.c rt_nonfinite.c rt_printf.c rtw_modelmap_utils.c xpc_datatype_ground.c 
MAKEFILE        = IdentificationMotor2Order.mk
MATLAB_ROOT     = D:\programacion\old_matlab
ALT_MATLAB_ROOT = D:\programacion\old_matlab
MATLAB_BIN      = D:\programacion\old_matlab\bin
ALT_MATLAB_BIN  = D:\programacion\old_matlab\bin
MASTER_ANCHOR_DIR = 
START_DIR       = E:\Documentos\u\11.Semester_XI\sensores\proyecto\ENTREGA-FINAL-RC-380-2011\CONTROLADORES\PRISMMATIC\cd\Software\ActuatorIdentification\XPC_Code
S_FUNCTIONS     = fifowrite.c fiforead.c addiamondmm16atcustom.c asciiencode.c sersetupbase.c
S_FUNCTIONS_LIB = 
NUMST           = 1
TID01EQ         = 0
NCSTATES        = 0
BUILDARGS       =  GENERATE_REPORT=0 EXT_MODE=1
MULTITASKING    = 0
EXT_MODE        = 0
MEX_OPT_FILE    = -f "$(MATLAB_BIN)\$(ML_ARCH)\mexopts\msvc100opts.bat"

MODELREFS       = 
SHARED_SRC      = 
SHARED_SRC_DIR  = 
SHARED_BIN_DIR  = 
SHARED_LIB      = 
VISUAL_VER      = 10.0
TGT_FCN_LIB     = XPC_BLAS

OPTIMIZATION_FLAGS   = /O2 /Oy-

#--------------------------- Model and reference models -----------------------
MODELLIB                  = IdentificationMotor2Orderlib.lib
MODELREF_LINK_LIBS        = 
MODELREF_LINK_RSPFILE     = IdentificationMotor2Order_ref.rsp
MODELREF_INC_PATH         = 
RELATIVE_PATH_TO_ANCHOR   = ..
# ..\..\..\..\..\..\.. or .. or even . if you want it
MODELREF_TARGET_TYPE      = NONE

!if "$(MATLAB_ROOT)" != "$(ALT_MATLAB_ROOT)"
MATLAB_ROOT = $(ALT_MATLAB_ROOT)
!endif
!if "$(MATLAB_BIN)" != "$(ALT_MATLAB_BIN)"
MATLAB_BIN = $(ALT_MATLAB_BIN)
!endif
#--------------------------- Tool Specifications ------------------------------

CPU=i386
!include $(MATLAB_ROOT)\rtw\c\tools\vctools.mak

PERL = $(MATLAB_ROOT)\sys\perl\win32\bin\perl

#------------------------------ Include/Lib Path ------------------------------

MATLAB_INCLUDES =                    $(MATLAB_ROOT)\simulink\include
MATLAB_INCLUDES = $(MATLAB_INCLUDES);$(MATLAB_ROOT)\extern\include
MATLAB_INCLUDES = $(MATLAB_INCLUDES);$(MATLAB_ROOT)\rtw\c\src
MATLAB_INCLUDES = $(MATLAB_INCLUDES);$(MATLAB_ROOT)\rtw\c\libsrc
MATLAB_INCLUDES = $(MATLAB_INCLUDES);$(MATLAB_ROOT)\rtw\c\src\ext_mode\common

# Additional file include paths
MATLAB_INCLUDES = $(MATLAB_INCLUDES);$(START_DIR)\IdentificationMotor2Order_xpc_rtw
MATLAB_INCLUDES = $(MATLAB_INCLUDES);$(START_DIR)


XPC_INCLUDES    = $(MATLAB_ROOT)\toolbox\rtw\targets\xpc\target\build\include;.
XPC_INCLUDES    = $(XPC_INCLUDES);$(MATLAB_ROOT)\toolbox\rtw\targets\xpc\target\build\xpcblocks\include
XPC_INCLUDES    = $(XPC_INCLUDES);$(MATLAB_ROOT)\toolbox\rtw\targets\xpc\target\build\xpcblocks\thirdpartydrivers
INCLUDE         = .;..;$(XPC_INCLUDES);$(MATLAB_INCLUDES);$(INCLUDE);$(MODELREF_INC_PATH)

!if "$(SHARED_SRC_DIR)" != ""
INCLUDE = $(INCLUDE);$(SHARED_SRC_DIR)
!endif

#----------------- Compiler and Linker Options --------------------------------


# Optimization Options
#   Set  OPT_OPTS=-Zi  for debugging symbols
DEFAULT_OPT_OPTS = /W3
OPT_OPTS = $(DEFAULT_OPT_OPTS)

# General User Options
OPTS =
#/GD

CC_OPTS = $(OPTS) $(OPT_OPTS) /c /nologo $(OPTIMIZATION_FLAGS) 

CPP_REQ_DEFINES = -DMODEL=$(MODEL) -DRT -DNUMST=$(NUMST) \
                  -DTID01EQ=$(TID01EQ) -DNCSTATES=$(NCSTATES) \
                  -DMT=$(MULTITASKING) -DHAVESTDIO -DXPCMSVISUALC \
                  -DXPCCALLCONV=__cdecl  -DUSE_RTMODEL -DERT_CORE

# Uncomment this line to move warning level to W4
# cflags = $(cflags:W3=W4)
CFLAGS = $(cvarsmt) $(CFLAGS_VERSPECIFIC) $(CC_OPTS) $(CPP_REQ_DEFINES) $(USER_INCLUDES)
CPPFLAGS = $(cflags) $(cvarsmt) $(CPPFLAGS_VERSPECIFIC) /GX \
           $(CPP_OPTS) $(CC_OPTS) $(CPP_REQ_DEFINES) $(USER_INCLUDES)

LDFLAGS = /NOLOGO /DLL /SUBSYSTEM:CONSOLE /DEF:xpcvcdll.def $(EXT_LIB) /Include:_malloc

#----------------------------- Source Files -----------------------------------
#Standalone executable
!if "$(MODELREF_TARGET_TYPE)" == "NONE"
PRODUCT   = $(RELATIVE_PATH_TO_ANCHOR)\$(MODEL).dlm
REQ_SRCS  = $(MODEL).c $(MODULES) xpctarget.c

#Model Reference Target
!else
PRODUCT   = $(MODELLIB)
REQ_SRCS  = $(MODULES)
!endif


USER_SRCS =

SRCS = $(REQ_SRCS) $(USER_SRCS) $(S_FUNCTIONS)
OBJS_CPP_UPPER = $(SRCS:.CPP=.obj)
OBJS_CPP_LOWER = $(OBJS_CPP_UPPER:.cpp=.obj)
OBJS_C_UPPER = $(OBJS_CPP_LOWER:.C=.obj)
OBJS = $(OBJS_C_UPPER:.c=.obj)
SHARED_OBJS = $(SHARED_SRC:.c=.obj)
# ------------------------- Libraries ------------------------------
LIBS =


LIBS = $(LIBS) xpcruntime.lib

!if "$(TGT_FCN_LIB)" == "XPC_BLAS"
BLASLIBS = $(MATLAB_ROOT)\toolbox\rtw\targets\xpc\target\build\lib\libatlas.a $(MATLAB_ROOT)\toolbox\rtw\targets\xpc\target\build\lib\libcblas.a
!else
BLASLIBS = 
!endif

# ---------------------------- Linker Script ----------------------------------

CMD_FILE = $(MODEL).lnk
GEN_LNK_SCRIPT = $(MATLAB_ROOT)\rtw\c\tools\mkvc_lnk.pl

#--------------------------------- Rules --------------------------------------
!if "$(MODELREF_TARGET_TYPE)" == "NONE"
#--- Stand-alone model ---
..\$(MODEL).dlm : $(MODEL)_xpc.dll
	$(MATLAB_ROOT)\toolbox\rtw\targets\xpc\xpc\bin\mkusrdlm -c+ -q+ $(MODEL)_xpc.dll ..\$(MODEL)
	@cmd /C "echo ### Created DLM $@"
#	@del $(MODEL)_xpc.dll
#	@del $(MODEL).pdb

$(MODEL)_xpc.dll : set_environment_variables $(OBJS) $(SHARED_LIB) $(LIBS) $(MODELREF_LINK_LIBS)
	@cmd /C "echo ### Linking ..."
	$(PERL) $(GEN_LNK_SCRIPT) $(CMD_FILE) $(OBJS)
	$(LD) $(LDFLAGS) $(BLASLIBS) $(LIBS) $(S_FUNCTIONS_LIB) $(CANLIB) $(SHARED_LIB) @$(CMD_FILE) @$(MODELREF_LINK_RSPFILE) -out:$@
	@del $(CMD_FILE)
	@cmd /C "echo ### Created DLL $@"

!else
#--- Model reference Target ---
$(PRODUCT) : set_environment_variables $(OBJS) $(SHARED_LIB) $(LIBS)
	@cmd /C "echo ### Linking ..."
	$(PERL) $(GEN_LNK_SCRIPT) $(CMD_FILE) $(OBJS)
	$(LD) -lib /OUT:$(MODELLIB) @$(CMD_FILE) $(S_FUNCTIONS_LIB) $(BLASLIBS)
	@cmd /C "echo ### Created static library $(MODELLIB)"
!endif

{$(MATLAB_ROOT)\rtw\c\src}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<

xpcruntime.lib: xpcimports.obj xpcPCFunctions.obj
	$(LIBCMD) /nologo /out:$@ $**

# Additional sources

{$(MATLAB_ROOT)\rtw\c\src}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<
{$(MATLAB_ROOT)\toolbox\rtw\targets\xpc\target\build\xpcblocks}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<
{$(MATLAB_ROOT)\toolbox\rtw\targets\xpc\target\build\xpcblocks\thirdpartydrivers}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<


{$(MATLAB_ROOT)\rtw\c\src}.cpp.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CPPFLAGS) $<

{$(MATLAB_ROOT)\toolbox\rtw\targets\xpc\target\build\xpcblocks}.cpp.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CPPFLAGS) $<

{$(MATLAB_ROOT)\toolbox\rtw\targets\xpc\target\build\xpcblocks\thirdpartydrivers}.cpp.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CPPFLAGS) $<



# Look in simulink/src helper files

{$(MATLAB_ROOT)\simulink\src}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<

# Libraries:





# Put this rule last, otherwise nmake will check toolboxes first

{$(MATLAB_ROOT)\toolbox\rtw\targets\xpc\target\build\src}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<

{$(MATLAB_ROOT)\toolbox\rtw\targets\xpc\target\build\xpcblocks\include}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<

xpctarget.obj : $(MATLAB_ROOT)\toolbox\rtw\targets\xpc\target\build\src\xpctarget.c xpcoptions.h
	@cmd /C "echo ### Compiling xpctarget.c"
	$(CC) $(CFLAGS) $(MATLAB_ROOT)\toolbox\rtw\targets\xpc\target\build\src\xpctarget.c

{$(MATLAB_ROOT)\toolbox\rtw\targets\xpc\target\build\xpcblocks}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<

{$(MATLAB_ROOT)\toolbox\rtw\targets\xpc\target\build\xpcblocks\thirdpartydrivers}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<

{..}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<

.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<

.cpp.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CPPFLAGS) $<

{$(RELATIVE_PATH_TO_ANCHOR)}.c.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CFLAGS) $<

{$(RELATIVE_PATH_TO_ANCHOR)}.cpp.obj :
	@cmd /C "echo ### Compiling $<"
	$(CC) $(CPPFLAGS) $<

!if "$(SHARED_LIB)" != ""
$(SHARED_LIB) : $(SHARED_SRC)
	@cmd /C "echo ### Creating $@"
	@$(CC) $(CFLAGS) -Fo$(SHARED_BIN_DIR)\ $?
	@$(LIBCMD) /nologo /out:$@ $(SHARED_OBJS)
	@cmd /C "echo ### $@ Created"
!endif

set_environment_variables:
	@set INCLUDE=$(INCLUDE)
	@set LIB=$(LIB)

#----------------------------- Dependencies -----------------------------------

$(OBJS) : $(MAKEFILE) rtw_proj.tmw

xpcPCFunctions.obj xpcimports.obj: $(MAKEFILE) rtw_proj.tmw
