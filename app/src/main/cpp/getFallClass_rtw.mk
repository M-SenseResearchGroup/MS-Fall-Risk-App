###########################################################################
## Makefile generated for MATLAB file/project 'getFallClass'. 
## 
## Makefile     : getFallClass_rtw.mk
## Generated on : Fri Mar 29 13:35:40 2019
## MATLAB Coder version: 4.2 (R2019a)
## 
## Build Info:
## 
## Final product: ./getFallClass.a
## Product type : static-library
## 
###########################################################################

###########################################################################
## MACROS
###########################################################################

# Macro Descriptions:
# PRODUCT_NAME            Name of the system to build
# MAKEFILE                Name of this makefile
# COMPUTER                Computer type. See the MATLAB "computer" command.

PRODUCT_NAME              = getFallClass
MAKEFILE                  = getFallClass_rtw.mk
COMPUTER                  = MACI64
MATLAB_ROOT               = /Applications/MATLAB_R2019a.app
MATLAB_BIN                = /Applications/MATLAB_R2019a.app/bin
MATLAB_ARCH_BIN           = $(MATLAB_BIN)/maci64
MASTER_ANCHOR_DIR         = 
START_DIR                 = /Users/MelissaSeib/Desktop/CC-Report/MS_Fall_Risk_Application_Master/app/build/intermediates/jniLibs
ARCH                      = maci64
TGT_FCN_LIB               = ISO_C
RELATIVE_PATH_TO_ANCHOR   = .
C_STANDARD_OPTS           = -fno-common -fexceptions
CPP_STANDARD_OPTS         = -fno-common -fexceptions

###########################################################################
## TOOLCHAIN SPECIFICATIONS
###########################################################################

# Toolchain Name:          Clang v3.1 | gmake (64-bit Mac)
# Supported Version(s):    3.1
# ToolchainInfo Version:   R2019a
# Specification Revision:  1.0
# 
#-------------------------------------------
# Macros assumed to be defined elsewhere
#-------------------------------------------

# C_STANDARD_OPTS
# CPP_STANDARD_OPTS

#-----------
# MACROS
#-----------

ARCHS             = x86_64
XCODE_SDK_VER     = $(shell perl $(MATLAB_ROOT)/rtw/c/tools/macsdkver.pl)
XCODE_SDK         = MacOSX$(XCODE_SDK_VER).sdk
XCODE_DEVEL_DIR   = $(shell xcode-select -print-path)
XCODE_SDK_ROOT    = $(XCODE_DEVEL_DIR)/Platforms/MacOSX.platform/Developer/SDKs/$(XCODE_SDK)

TOOLCHAIN_SRCS = 
TOOLCHAIN_INCS = 
TOOLCHAIN_LIBS = 

#------------------------
# BUILD TOOL COMMANDS
#------------------------

# C Compiler: Clang C Compiler
CC = xcrun clang

# Linker: Clang Linker
LD = xcrun clang++

# C++ Compiler: Clang C++ Compiler
CPP = xcrun clang++

# C++ Linker: Clang C++ Linker
CPP_LD = xcrun clang++

# Archiver: Clang Archiver
AR = xcrun ar

# MEX Tool: MEX Tool
MEX_PATH = $(MATLAB_ARCH_BIN)
MEX = "$(MEX_PATH)/mex"

# Download: Download
DOWNLOAD =

# Execute: Execute
EXECUTE = $(PRODUCT)

# Builder: GMAKE Utility
MAKE_PATH = %MATLAB%/bin/maci64
MAKE = "$(MAKE_PATH)/gmake"


#-------------------------
# Directives/Utilities
#-------------------------

CDEBUG              = -g
C_OUTPUT_FLAG       = -o
LDDEBUG             = -g
OUTPUT_FLAG         = -o
CPPDEBUG            = -g
CPP_OUTPUT_FLAG     = -o
CPPLDDEBUG          = -g
OUTPUT_FLAG         = -o
ARDEBUG             =
STATICLIB_OUTPUT_FLAG =
MEX_DEBUG           = -g
RM                  = @rm -f
ECHO                = @echo
MV                  = @mv
RUN                 =

#----------------------------------------
# "Faster Builds" Build Configuration
#----------------------------------------

ARFLAGS              = ruvs
CFLAGS               = -c -isysroot $(XCODE_SDK_ROOT) -arch $(ARCHS) $(C_STANDARD_OPTS) \
                       -O0
CPPFLAGS             = -c -isysroot $(XCODE_SDK_ROOT) -arch $(ARCHS) $(CPP_STANDARD_OPTS) \
                       -O0
CPP_LDFLAGS          = -arch $(ARCHS) -isysroot $(XCODE_SDK_ROOT) -Wl,-rpath,$(MATLAB_ARCH_BIN) -Wl,-rpath,@executable_path -Wl,-rpath,@executable_path/$(RELATIVE_PATH_TO_ANCHOR) -L"$(MATLAB_ARCH_BIN)"
CPP_SHAREDLIB_LDFLAGS  = -dynamiclib -install_name @rpath/$(notdir $(PRODUCT)) -isysroot $(XCODE_SDK_ROOT) -L"$(MATLAB_ARCH_BIN)" \
                         -Wl,$(LD_NAMESPACE) $(LD_UNDEFS)
DOWNLOAD_FLAGS       =
EXECUTE_FLAGS        =
LDFLAGS              = -arch $(ARCHS) -isysroot $(XCODE_SDK_ROOT) -Wl,-rpath,$(MATLAB_ARCH_BIN) -Wl,-rpath,@executable_path -Wl,-rpath,@executable_path/$(RELATIVE_PATH_TO_ANCHOR) -L"$(MATLAB_ARCH_BIN)"
MEX_CPPFLAGS         = -R2018a -MATLAB_ARCH=$(ARCH) $(INCLUDES) \
                         \
                       CXXOPTIMFLAGS="$(C_STANDARD_OPTS)  \
                       -O0 \
                        $(DEFINES)" \
                         \
                       -silent
MEX_CPPLDFLAGS       =
MEX_CFLAGS           = -R2018a -MATLAB_ARCH=$(ARCH) $(INCLUDES) \
                         \
                       COPTIMFLAGS="$(C_STANDARD_OPTS)  \
                       -O0 \
                        $(DEFINES)" \
                         \
                       -silent
MEX_LDFLAGS          = LDFLAGS=='$$LDFLAGS'
MAKE_FLAGS           = -f $(MAKEFILE)
SHAREDLIB_LDFLAGS    = -dynamiclib -install_name @rpath/$(notdir $(PRODUCT)) -isysroot $(XCODE_SDK_ROOT) -L"$(MATLAB_ARCH_BIN)" \
                       -Wl,$(LD_NAMESPACE) $(LD_UNDEFS)



###########################################################################
## OUTPUT INFO
###########################################################################

PRODUCT = ./getFallClass.a
PRODUCT_TYPE = "static-library"
BUILD_TYPE = "Static Library"

###########################################################################
## INCLUDE PATHS
###########################################################################

INCLUDES_BUILDINFO = -I$(START_DIR) -I/Users/MelissaSeib/Desktop/app_code\ copy -I$(MATLAB_ROOT)/extern/include -I$(MATLAB_ROOT)/simulink/include -I$(MATLAB_ROOT)/rtw/c/src -I$(MATLAB_ROOT)/rtw/c/src/ext_mode/common -I$(MATLAB_ROOT)/rtw/c/ert -I$(START_DIR)/CXSparse/Include -I$(START_DIR)/CXSparse/SuiteSparse_config -I$(START_DIR)/CXSparse/CXSparseSupport

INCLUDES = $(INCLUDES_BUILDINFO)

###########################################################################
## DEFINES
###########################################################################

DEFINES_CUSTOM = 
DEFINES_OPTS = -DCS_COMPLEX
DEFINES_STANDARD = -DMODEL=getFallClass -DHAVESTDIO -DUSE_RTMODEL -DUNIX

DEFINES = $(DEFINES_CUSTOM) $(DEFINES_OPTS) $(DEFINES_STANDARD)

###########################################################################
## SOURCE FILES
###########################################################################

SRCS = $(START_DIR)/getFallClass_rtwutil.c $(START_DIR)/getFallClass_data.c $(START_DIR)/getFallClass_initialize.c $(START_DIR)/getFallClass_terminate.c $(START_DIR)/calibrate.c $(START_DIR)/get_calibration.c $(START_DIR)/get_classification.c $(START_DIR)/get_fall_class.c $(START_DIR)/get_features.c $(START_DIR)/get_strides.c $(START_DIR)/pre_process_feats.c $(START_DIR)/staticndx.c $(START_DIR)/vvarstd.c $(START_DIR)/sum.c $(START_DIR)/vecnorm.c $(START_DIR)/mean.c $(START_DIR)/norm.c $(START_DIR)/dot.c $(START_DIR)/strcmp.c $(START_DIR)/any.c $(START_DIR)/CompactSVM.c $(START_DIR)/CompactClassificationModel.c $(START_DIR)/nonSingletonDim.c $(START_DIR)/Gaussian.c $(START_DIR)/bsxfun.c $(START_DIR)/bwfilt.c $(START_DIR)/myButter.c $(START_DIR)/tan.c $(START_DIR)/mpower.c $(START_DIR)/prod.c $(START_DIR)/poly1.c $(START_DIR)/myfiltfilt.c $(START_DIR)/sparse.c $(START_DIR)/sparse1.c $(START_DIR)/introsort.c $(START_DIR)/insertionsort.c $(START_DIR)/filter.c $(START_DIR)/skewness.c $(START_DIR)/kurtosis.c $(START_DIR)/pwelch.c $(START_DIR)/psdesttype.c $(START_DIR)/welch.c $(START_DIR)/welchparse.c $(START_DIR)/computeperiodogram.c $(START_DIR)/fft.c $(START_DIR)/fft1.c $(START_DIR)/psdfreqvec.c $(START_DIR)/computepsd.c $(START_DIR)/extrema.c $(START_DIR)/diff.c $(START_DIR)/ifWhileCond.c $(START_DIR)/nullAssignment.c $(START_DIR)/sign.c $(START_DIR)/sign1.c $(START_DIR)/sort1.c $(START_DIR)/sortIdx.c $(START_DIR)/mergesort.c $(START_DIR)/sortLE.c $(START_DIR)/relop.c $(START_DIR)/xcorr.c $(START_DIR)/crossing0.c $(START_DIR)/getFallClass_emxutil.c $(START_DIR)/rt_nonfinite.c $(START_DIR)/rtGetNaN.c $(START_DIR)/rtGetInf.c $(START_DIR)/CXSparse/Source/cs_add_ri.c $(START_DIR)/CXSparse/Source/cs_add_ci.c $(START_DIR)/CXSparse/Source/cs_amd_ri.c $(START_DIR)/CXSparse/Source/cs_amd_ci.c $(START_DIR)/CXSparse/Source/cs_chol_ri.c $(START_DIR)/CXSparse/Source/cs_chol_ci.c $(START_DIR)/CXSparse/Source/cs_cholsol_ri.c $(START_DIR)/CXSparse/Source/cs_cholsol_ci.c $(START_DIR)/CXSparse/Source/cs_counts_ri.c $(START_DIR)/CXSparse/Source/cs_counts_ci.c $(START_DIR)/CXSparse/Source/cs_cumsum_ri.c $(START_DIR)/CXSparse/Source/cs_cumsum_ci.c $(START_DIR)/CXSparse/Source/cs_dfs_ri.c $(START_DIR)/CXSparse/Source/cs_dfs_ci.c $(START_DIR)/CXSparse/Source/cs_dmperm_ri.c $(START_DIR)/CXSparse/Source/cs_dmperm_ci.c $(START_DIR)/CXSparse/Source/cs_droptol_ri.c $(START_DIR)/CXSparse/Source/cs_droptol_ci.c $(START_DIR)/CXSparse/Source/cs_dropzeros_ri.c $(START_DIR)/CXSparse/Source/cs_dropzeros_ci.c $(START_DIR)/CXSparse/Source/cs_dupl_ri.c $(START_DIR)/CXSparse/Source/cs_dupl_ci.c $(START_DIR)/CXSparse/Source/cs_entry_ri.c $(START_DIR)/CXSparse/Source/cs_entry_ci.c $(START_DIR)/CXSparse/Source/cs_etree_ri.c $(START_DIR)/CXSparse/Source/cs_etree_ci.c $(START_DIR)/CXSparse/Source/cs_fkeep_ri.c $(START_DIR)/CXSparse/Source/cs_fkeep_ci.c $(START_DIR)/CXSparse/Source/cs_gaxpy_ri.c $(START_DIR)/CXSparse/Source/cs_gaxpy_ci.c $(START_DIR)/CXSparse/Source/cs_happly_ri.c $(START_DIR)/CXSparse/Source/cs_happly_ci.c $(START_DIR)/CXSparse/Source/cs_house_ri.c $(START_DIR)/CXSparse/Source/cs_house_ci.c $(START_DIR)/CXSparse/Source/cs_ipvec_ri.c $(START_DIR)/CXSparse/Source/cs_ipvec_ci.c $(START_DIR)/CXSparse/Source/cs_load_ri.c $(START_DIR)/CXSparse/Source/cs_load_ci.c $(START_DIR)/CXSparse/Source/cs_lsolve_ri.c $(START_DIR)/CXSparse/Source/cs_lsolve_ci.c $(START_DIR)/CXSparse/Source/cs_ltsolve_ri.c $(START_DIR)/CXSparse/Source/cs_ltsolve_ci.c $(START_DIR)/CXSparse/Source/cs_lu_ri.c $(START_DIR)/CXSparse/Source/cs_lu_ci.c $(START_DIR)/CXSparse/Source/cs_lusol_ri.c $(START_DIR)/CXSparse/Source/cs_lusol_ci.c $(START_DIR)/CXSparse/Source/cs_malloc_ri.c $(START_DIR)/CXSparse/Source/cs_malloc_ci.c $(START_DIR)/CXSparse/Source/cs_maxtrans_ri.c $(START_DIR)/CXSparse/Source/cs_maxtrans_ci.c $(START_DIR)/CXSparse/Source/cs_multiply_ri.c $(START_DIR)/CXSparse/Source/cs_multiply_ci.c $(START_DIR)/CXSparse/Source/cs_norm_ri.c $(START_DIR)/CXSparse/Source/cs_norm_ci.c $(START_DIR)/CXSparse/Source/cs_permute_ri.c $(START_DIR)/CXSparse/Source/cs_permute_ci.c $(START_DIR)/CXSparse/Source/cs_pinv_ri.c $(START_DIR)/CXSparse/Source/cs_pinv_ci.c $(START_DIR)/CXSparse/Source/cs_post_ri.c $(START_DIR)/CXSparse/Source/cs_post_ci.c $(START_DIR)/CXSparse/Source/cs_print_ri.c $(START_DIR)/CXSparse/Source/cs_print_ci.c $(START_DIR)/CXSparse/Source/cs_pvec_ri.c $(START_DIR)/CXSparse/Source/cs_pvec_ci.c $(START_DIR)/CXSparse/Source/cs_qr_ri.c $(START_DIR)/CXSparse/Source/cs_qr_ci.c $(START_DIR)/CXSparse/Source/cs_qrsol_ri.c $(START_DIR)/CXSparse/Source/cs_qrsol_ci.c $(START_DIR)/CXSparse/Source/cs_scatter_ri.c $(START_DIR)/CXSparse/Source/cs_scatter_ci.c $(START_DIR)/CXSparse/Source/cs_scc_ri.c $(START_DIR)/CXSparse/Source/cs_scc_ci.c $(START_DIR)/CXSparse/Source/cs_schol_ri.c $(START_DIR)/CXSparse/Source/cs_schol_ci.c $(START_DIR)/CXSparse/Source/cs_sqr_ri.c $(START_DIR)/CXSparse/Source/cs_sqr_ci.c $(START_DIR)/CXSparse/Source/cs_symperm_ri.c $(START_DIR)/CXSparse/Source/cs_symperm_ci.c $(START_DIR)/CXSparse/Source/cs_tdfs_ri.c $(START_DIR)/CXSparse/Source/cs_tdfs_ci.c $(START_DIR)/CXSparse/Source/cs_transpose_ri.c $(START_DIR)/CXSparse/Source/cs_transpose_ci.c $(START_DIR)/CXSparse/Source/cs_compress_ri.c $(START_DIR)/CXSparse/Source/cs_compress_ci.c $(START_DIR)/CXSparse/Source/cs_updown_ri.c $(START_DIR)/CXSparse/Source/cs_updown_ci.c $(START_DIR)/CXSparse/Source/cs_usolve_ri.c $(START_DIR)/CXSparse/Source/cs_usolve_ci.c $(START_DIR)/CXSparse/Source/cs_utsolve_ri.c $(START_DIR)/CXSparse/Source/cs_utsolve_ci.c $(START_DIR)/CXSparse/Source/cs_util_ri.c $(START_DIR)/CXSparse/Source/cs_util_ci.c $(START_DIR)/CXSparse/Source/cs_reach_ri.c $(START_DIR)/CXSparse/Source/cs_reach_ci.c $(START_DIR)/CXSparse/Source/cs_spsolve_ri.c $(START_DIR)/CXSparse/Source/cs_spsolve_ci.c $(START_DIR)/CXSparse/Source/cs_ereach_ri.c $(START_DIR)/CXSparse/Source/cs_ereach_ci.c $(START_DIR)/CXSparse/Source/cs_leaf_ri.c $(START_DIR)/CXSparse/Source/cs_leaf_ci.c $(START_DIR)/CXSparse/Source/cs_randperm_ri.c $(START_DIR)/CXSparse/Source/cs_randperm_ci.c $(START_DIR)/CXSparse/Source/cs_operator_ri.c $(START_DIR)/CXSparse/Source/cs_operator_ci.c $(START_DIR)/CXSparse/CXSparseSupport/solve_from_lu.c $(START_DIR)/CXSparse/CXSparseSupport/solve_from_qr.c $(START_DIR)/CXSparse/CXSparseSupport/makeCXSparseMatrix.c $(START_DIR)/CXSparse/CXSparseSupport/unpackCXStruct.c

ALL_SRCS = $(SRCS)

###########################################################################
## OBJECTS
###########################################################################

OBJS = getFallClass_rtwutil.o getFallClass_data.o getFallClass_initialize.o getFallClass_terminate.o calibrate.o get_calibration.o get_classification.o get_fall_class.o get_features.o get_strides.o pre_process_feats.o staticndx.o vvarstd.o sum.o vecnorm.o mean.o norm.o dot.o strcmp.o any.o CompactSVM.o CompactClassificationModel.o nonSingletonDim.o Gaussian.o bsxfun.o bwfilt.o myButter.o tan.o mpower.o prod.o poly1.o myfiltfilt.o sparse.o sparse1.o introsort.o insertionsort.o filter.o skewness.o kurtosis.o pwelch.o psdesttype.o welch.o welchparse.o computeperiodogram.o fft.o fft1.o psdfreqvec.o computepsd.o extrema.o diff.o ifWhileCond.o nullAssignment.o sign.o sign1.o sort1.o sortIdx.o mergesort.o sortLE.o relop.o xcorr.o crossing0.o getFallClass_emxutil.o rt_nonfinite.o rtGetNaN.o rtGetInf.o cs_add_ri.o cs_add_ci.o cs_amd_ri.o cs_amd_ci.o cs_chol_ri.o cs_chol_ci.o cs_cholsol_ri.o cs_cholsol_ci.o cs_counts_ri.o cs_counts_ci.o cs_cumsum_ri.o cs_cumsum_ci.o cs_dfs_ri.o cs_dfs_ci.o cs_dmperm_ri.o cs_dmperm_ci.o cs_droptol_ri.o cs_droptol_ci.o cs_dropzeros_ri.o cs_dropzeros_ci.o cs_dupl_ri.o cs_dupl_ci.o cs_entry_ri.o cs_entry_ci.o cs_etree_ri.o cs_etree_ci.o cs_fkeep_ri.o cs_fkeep_ci.o cs_gaxpy_ri.o cs_gaxpy_ci.o cs_happly_ri.o cs_happly_ci.o cs_house_ri.o cs_house_ci.o cs_ipvec_ri.o cs_ipvec_ci.o cs_load_ri.o cs_load_ci.o cs_lsolve_ri.o cs_lsolve_ci.o cs_ltsolve_ri.o cs_ltsolve_ci.o cs_lu_ri.o cs_lu_ci.o cs_lusol_ri.o cs_lusol_ci.o cs_malloc_ri.o cs_malloc_ci.o cs_maxtrans_ri.o cs_maxtrans_ci.o cs_multiply_ri.o cs_multiply_ci.o cs_norm_ri.o cs_norm_ci.o cs_permute_ri.o cs_permute_ci.o cs_pinv_ri.o cs_pinv_ci.o cs_post_ri.o cs_post_ci.o cs_print_ri.o cs_print_ci.o cs_pvec_ri.o cs_pvec_ci.o cs_qr_ri.o cs_qr_ci.o cs_qrsol_ri.o cs_qrsol_ci.o cs_scatter_ri.o cs_scatter_ci.o cs_scc_ri.o cs_scc_ci.o cs_schol_ri.o cs_schol_ci.o cs_sqr_ri.o cs_sqr_ci.o cs_symperm_ri.o cs_symperm_ci.o cs_tdfs_ri.o cs_tdfs_ci.o cs_transpose_ri.o cs_transpose_ci.o cs_compress_ri.o cs_compress_ci.o cs_updown_ri.o cs_updown_ci.o cs_usolve_ri.o cs_usolve_ci.o cs_utsolve_ri.o cs_utsolve_ci.o cs_util_ri.o cs_util_ci.o cs_reach_ri.o cs_reach_ci.o cs_spsolve_ri.o cs_spsolve_ci.o cs_ereach_ri.o cs_ereach_ci.o cs_leaf_ri.o cs_leaf_ci.o cs_randperm_ri.o cs_randperm_ci.o cs_operator_ri.o cs_operator_ci.o solve_from_lu.o solve_from_qr.o makeCXSparseMatrix.o unpackCXStruct.o

ALL_OBJS = $(OBJS)

###########################################################################
## PREBUILT OBJECT FILES
###########################################################################

PREBUILT_OBJS = 

###########################################################################
## LIBRARIES
###########################################################################

LIBS = 

###########################################################################
## SYSTEM LIBRARIES
###########################################################################

SYSTEM_LIBS =  -L$(MATLAB_ROOT)/sys/os/maci64 -lm -liomp5

###########################################################################
## ADDITIONAL TOOLCHAIN FLAGS
###########################################################################

#---------------
# C Compiler
#---------------

CFLAGS_ = -Xpreprocessor -fopenmp -I$(MATLAB_ROOT)/toolbox/eml/externalDependency/omp/$(ARCH)/include -DOpenMP_omp_LIBRARY=$(MATLAB_ROOT)/sys/os/$(ARCH)/libiomp5.dylib
CFLAGS_BASIC = $(DEFINES) $(INCLUDES)

CFLAGS += $(CFLAGS_) $(CFLAGS_BASIC)

#-----------------
# C++ Compiler
#-----------------

CPPFLAGS_ = -Xpreprocessor -fopenmp -I$(MATLAB_ROOT)/toolbox/eml/externalDependency/omp/$(ARCH)/include -DOpenMP_omp_LIBRARY=$(MATLAB_ROOT)/sys/os/$(ARCH)/libiomp5.dylib
CPPFLAGS_BASIC = $(DEFINES) $(INCLUDES)

CPPFLAGS += $(CPPFLAGS_) $(CPPFLAGS_BASIC)

#---------------
# C++ Linker
#---------------

CPP_LDFLAGS_ = -Wl,-rpath,$(MATLAB_ROOT)/sys/os/$(ARCH)/  

CPP_LDFLAGS += $(CPP_LDFLAGS_)

#------------------------------
# C++ Shared Library Linker
#------------------------------

CPP_SHAREDLIB_LDFLAGS_ = -Wl,-rpath,$(MATLAB_ROOT)/sys/os/$(ARCH)/  

CPP_SHAREDLIB_LDFLAGS += $(CPP_SHAREDLIB_LDFLAGS_)

#-----------
# Linker
#-----------

LDFLAGS_ = -Wl,-rpath,$(MATLAB_ROOT)/sys/os/$(ARCH)/  

LDFLAGS += $(LDFLAGS_)

#--------------------------
# Shared Library Linker
#--------------------------

SHAREDLIB_LDFLAGS_ = -Wl,-rpath,$(MATLAB_ROOT)/sys/os/$(ARCH)/  

SHAREDLIB_LDFLAGS += $(SHAREDLIB_LDFLAGS_)

###########################################################################
## INLINED COMMANDS
###########################################################################

###########################################################################
## PHONY TARGETS
###########################################################################

.PHONY : all build clean info prebuild download execute


all : build
	@echo "### Successfully generated all binary outputs."


build : prebuild $(PRODUCT)


prebuild : 


download : build


execute : download


###########################################################################
## FINAL TARGET
###########################################################################

#---------------------------------
# Create a static library         
#---------------------------------

$(PRODUCT) : $(OBJS) $(PREBUILT_OBJS)
	@echo "### Creating static library "$(PRODUCT)" ..."
	$(AR) $(ARFLAGS)  $(PRODUCT) $(OBJS)
	@echo "### Created: $(PRODUCT)"


###########################################################################
## INTERMEDIATE TARGETS
###########################################################################

#---------------------
# SOURCE-TO-OBJECT
#---------------------

%.o : %.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : %.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/rtw/c/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/rtw/c/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/CXSparse/CXSparseSupport/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/CXSparse/CXSparseSupport/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/CXSparse/Source/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/CXSparse/Source/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : /Users/MelissaSeib/Desktop/app_code\ copy/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : /Users/MelissaSeib/Desktop/app_code\ copy/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


###########################################################################
## DEPENDENCIES
###########################################################################

$(ALL_OBJS) : rtw_proj.tmw $(MAKEFILE)


###########################################################################
## MISCELLANEOUS TARGETS
###########################################################################

info : 
	@echo "### PRODUCT = $(PRODUCT)"
	@echo "### PRODUCT_TYPE = $(PRODUCT_TYPE)"
	@echo "### BUILD_TYPE = $(BUILD_TYPE)"
	@echo "### INCLUDES = $(INCLUDES)"
	@echo "### DEFINES = $(DEFINES)"
	@echo "### ALL_SRCS = $(ALL_SRCS)"
	@echo "### ALL_OBJS = $(ALL_OBJS)"
	@echo "### LIBS = $(LIBS)"
	@echo "### MODELREF_LIBS = $(MODELREF_LIBS)"
	@echo "### SYSTEM_LIBS = $(SYSTEM_LIBS)"
	@echo "### TOOLCHAIN_LIBS = $(TOOLCHAIN_LIBS)"
	@echo "### CFLAGS = $(CFLAGS)"
	@echo "### LDFLAGS = $(LDFLAGS)"
	@echo "### SHAREDLIB_LDFLAGS = $(SHAREDLIB_LDFLAGS)"
	@echo "### CPPFLAGS = $(CPPFLAGS)"
	@echo "### CPP_LDFLAGS = $(CPP_LDFLAGS)"
	@echo "### CPP_SHAREDLIB_LDFLAGS = $(CPP_SHAREDLIB_LDFLAGS)"
	@echo "### ARFLAGS = $(ARFLAGS)"
	@echo "### MEX_CFLAGS = $(MEX_CFLAGS)"
	@echo "### MEX_CPPFLAGS = $(MEX_CPPFLAGS)"
	@echo "### MEX_LDFLAGS = $(MEX_LDFLAGS)"
	@echo "### MEX_CPPLDFLAGS = $(MEX_CPPLDFLAGS)"
	@echo "### DOWNLOAD_FLAGS = $(DOWNLOAD_FLAGS)"
	@echo "### EXECUTE_FLAGS = $(EXECUTE_FLAGS)"
	@echo "### MAKE_FLAGS = $(MAKE_FLAGS)"


clean : 
	$(ECHO) "### Deleting all derived files..."
	$(RM) $(PRODUCT)
	$(RM) $(ALL_OBJS)
	$(ECHO) "### Deleted all derived files."


