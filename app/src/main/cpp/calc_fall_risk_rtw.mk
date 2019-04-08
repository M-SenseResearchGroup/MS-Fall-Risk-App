###########################################################################
## Makefile generated for MATLAB file/project 'calc_fall_risk'. 
## 
## Makefile     : calc_fall_risk_rtw.mk
## Generated on : Mon Apr 08 18:26:53 2019
## MATLAB Coder version: 4.2 (R2019a)
## 
## Build Info:
## 
## Final product: ./calc_fall_risk.a
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

PRODUCT_NAME              = calc_fall_risk
MAKEFILE                  = calc_fall_risk_rtw.mk
COMPUTER                  = MACI64
MATLAB_ROOT               = /Applications/MATLAB_R2019a.app
MATLAB_BIN                = /Applications/MATLAB_R2019a.app/bin
MATLAB_ARCH_BIN           = $(MATLAB_BIN)/maci64
MASTER_ANCHOR_DIR         = 
START_DIR                 = /Users/MelissaSeib/Desktop/app_code/codegen/lib/calc_fall_risk
ARCH                      = maci64
TGT_FCN_LIB               = ISO_C++
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

PRODUCT = ./calc_fall_risk.a
PRODUCT_TYPE = "static-library"
BUILD_TYPE = "Static Library"

###########################################################################
## INCLUDE PATHS
###########################################################################

INCLUDES_BUILDINFO = -I$(START_DIR) -I/Users/MelissaSeib/Desktop/app_code_in_C++ -I$(MATLAB_ROOT)/extern/include -I$(MATLAB_ROOT)/simulink/include -I$(MATLAB_ROOT)/rtw/c/src -I$(MATLAB_ROOT)/rtw/c/src/ext_mode/common -I$(MATLAB_ROOT)/rtw/c/ert -I$(START_DIR)/CXSparse/Include -I$(START_DIR)/CXSparse/SuiteSparse_config -I$(START_DIR)/CXSparse/CXSparseSupport

INCLUDES = $(INCLUDES_BUILDINFO)

###########################################################################
## DEFINES
###########################################################################

DEFINES_CUSTOM = 
DEFINES_OPTS = -DCS_COMPLEX
DEFINES_STANDARD = -DMODEL=calc_fall_risk -DHAVESTDIO -DUSE_RTMODEL -DUNIX

DEFINES = $(DEFINES_CUSTOM) $(DEFINES_OPTS) $(DEFINES_STANDARD)

###########################################################################
## SOURCE FILES
###########################################################################

SRCS = $(START_DIR)/calc_fall_risk_rtwutil.cpp $(START_DIR)/calc_fall_risk_data.cpp $(START_DIR)/calc_fall_risk_initialize.cpp $(START_DIR)/calc_fall_risk_terminate.cpp $(START_DIR)/calc_fall_risk.cpp $(START_DIR)/get_calibration.cpp $(START_DIR)/calibrate.cpp $(START_DIR)/get_features.cpp $(START_DIR)/bwfilt.cpp $(START_DIR)/myButter.cpp $(START_DIR)/rdivide_helper.cpp $(START_DIR)/abs.cpp $(START_DIR)/mpower.cpp $(START_DIR)/power.cpp $(START_DIR)/combineVectorElements.cpp $(START_DIR)/poly.cpp $(START_DIR)/myfiltfilt.cpp $(START_DIR)/sparse.cpp $(START_DIR)/sparse1.cpp $(START_DIR)/introsort.cpp $(START_DIR)/insertionsort.cpp $(START_DIR)/nextpow2.cpp $(START_DIR)/filter.cpp $(START_DIR)/bsxfun.cpp $(START_DIR)/vecnorm.cpp $(START_DIR)/mean.cpp $(START_DIR)/var.cpp $(START_DIR)/vvarstd.cpp $(START_DIR)/skewness.cpp $(START_DIR)/sum.cpp $(START_DIR)/nan_sum_or_mean.cpp $(START_DIR)/nanmean.cpp $(START_DIR)/kurtosis.cpp $(START_DIR)/rectwin.cpp $(START_DIR)/pwelch.cpp $(START_DIR)/psdesttype.cpp $(START_DIR)/strcmp.cpp $(START_DIR)/welch.cpp $(START_DIR)/welchparse.cpp $(START_DIR)/any1.cpp $(START_DIR)/fix.cpp $(START_DIR)/computeperiodogram.cpp $(START_DIR)/computeDFT.cpp $(START_DIR)/fft.cpp $(START_DIR)/fft1.cpp $(START_DIR)/bluesteinSetup.cpp $(START_DIR)/psdfreqvec.cpp $(START_DIR)/computepsd.cpp $(START_DIR)/extrema.cpp $(START_DIR)/diff.cpp $(START_DIR)/ifWhileCond.cpp $(START_DIR)/nullAssignment.cpp $(START_DIR)/sign.cpp $(START_DIR)/sign1.cpp $(START_DIR)/sort1.cpp $(START_DIR)/nonSingletonDim.cpp $(START_DIR)/sortIdx.cpp $(START_DIR)/mergesort.cpp $(START_DIR)/sortLE.cpp $(START_DIR)/relop.cpp $(START_DIR)/xcorr.cpp $(START_DIR)/ifft.cpp $(START_DIR)/CompactSVM.cpp $(START_DIR)/CompactClassificationModel.cpp $(START_DIR)/pre_process_feats.cpp $(START_DIR)/dot.cpp $(START_DIR)/Gaussian.cpp $(START_DIR)/get_strides.cpp $(START_DIR)/crossing0.cpp $(START_DIR)/norm.cpp $(START_DIR)/calc_fall_risk_emxutil.cpp $(START_DIR)/rt_nonfinite.cpp $(START_DIR)/rtGetNaN.cpp $(START_DIR)/rtGetInf.cpp $(START_DIR)/CXSparse/Source/cs_add_ri.cpp $(START_DIR)/CXSparse/Source/cs_add_ci.cpp $(START_DIR)/CXSparse/Source/cs_amd_ri.cpp $(START_DIR)/CXSparse/Source/cs_amd_ci.cpp $(START_DIR)/CXSparse/Source/cs_chol_ri.cpp $(START_DIR)/CXSparse/Source/cs_chol_ci.cpp $(START_DIR)/CXSparse/Source/cs_cholsol_ri.cpp $(START_DIR)/CXSparse/Source/cs_cholsol_ci.cpp $(START_DIR)/CXSparse/Source/cs_counts_ri.cpp $(START_DIR)/CXSparse/Source/cs_counts_ci.cpp $(START_DIR)/CXSparse/Source/cs_cumsum_ri.cpp $(START_DIR)/CXSparse/Source/cs_cumsum_ci.cpp $(START_DIR)/CXSparse/Source/cs_dfs_ri.cpp $(START_DIR)/CXSparse/Source/cs_dfs_ci.cpp $(START_DIR)/CXSparse/Source/cs_dmperm_ri.cpp $(START_DIR)/CXSparse/Source/cs_dmperm_ci.cpp $(START_DIR)/CXSparse/Source/cs_droptol_ri.cpp $(START_DIR)/CXSparse/Source/cs_droptol_ci.cpp $(START_DIR)/CXSparse/Source/cs_dropzeros_ri.cpp $(START_DIR)/CXSparse/Source/cs_dropzeros_ci.cpp $(START_DIR)/CXSparse/Source/cs_dupl_ri.cpp $(START_DIR)/CXSparse/Source/cs_dupl_ci.cpp $(START_DIR)/CXSparse/Source/cs_entry_ri.cpp $(START_DIR)/CXSparse/Source/cs_entry_ci.cpp $(START_DIR)/CXSparse/Source/cs_etree_ri.cpp $(START_DIR)/CXSparse/Source/cs_etree_ci.cpp $(START_DIR)/CXSparse/Source/cs_fkeep_ri.cpp $(START_DIR)/CXSparse/Source/cs_fkeep_ci.cpp $(START_DIR)/CXSparse/Source/cs_gaxpy_ri.cpp $(START_DIR)/CXSparse/Source/cs_gaxpy_ci.cpp $(START_DIR)/CXSparse/Source/cs_happly_ri.cpp $(START_DIR)/CXSparse/Source/cs_happly_ci.cpp $(START_DIR)/CXSparse/Source/cs_house_ri.cpp $(START_DIR)/CXSparse/Source/cs_house_ci.cpp $(START_DIR)/CXSparse/Source/cs_ipvec_ri.cpp $(START_DIR)/CXSparse/Source/cs_ipvec_ci.cpp $(START_DIR)/CXSparse/Source/cs_load_ri.cpp $(START_DIR)/CXSparse/Source/cs_load_ci.cpp $(START_DIR)/CXSparse/Source/cs_lsolve_ri.cpp $(START_DIR)/CXSparse/Source/cs_lsolve_ci.cpp $(START_DIR)/CXSparse/Source/cs_ltsolve_ri.cpp $(START_DIR)/CXSparse/Source/cs_ltsolve_ci.cpp $(START_DIR)/CXSparse/Source/cs_lu_ri.cpp $(START_DIR)/CXSparse/Source/cs_lu_ci.cpp $(START_DIR)/CXSparse/Source/cs_lusol_ri.cpp $(START_DIR)/CXSparse/Source/cs_lusol_ci.cpp $(START_DIR)/CXSparse/Source/cs_malloc_ri.cpp $(START_DIR)/CXSparse/Source/cs_malloc_ci.cpp $(START_DIR)/CXSparse/Source/cs_maxtrans_ri.cpp $(START_DIR)/CXSparse/Source/cs_maxtrans_ci.cpp $(START_DIR)/CXSparse/Source/cs_multiply_ri.cpp $(START_DIR)/CXSparse/Source/cs_multiply_ci.cpp $(START_DIR)/CXSparse/Source/cs_norm_ri.cpp $(START_DIR)/CXSparse/Source/cs_norm_ci.cpp $(START_DIR)/CXSparse/Source/cs_permute_ri.cpp $(START_DIR)/CXSparse/Source/cs_permute_ci.cpp $(START_DIR)/CXSparse/Source/cs_pinv_ri.cpp $(START_DIR)/CXSparse/Source/cs_pinv_ci.cpp $(START_DIR)/CXSparse/Source/cs_post_ri.cpp $(START_DIR)/CXSparse/Source/cs_post_ci.cpp $(START_DIR)/CXSparse/Source/cs_print_ri.cpp $(START_DIR)/CXSparse/Source/cs_print_ci.cpp $(START_DIR)/CXSparse/Source/cs_pvec_ri.cpp $(START_DIR)/CXSparse/Source/cs_pvec_ci.cpp $(START_DIR)/CXSparse/Source/cs_qr_ri.cpp $(START_DIR)/CXSparse/Source/cs_qr_ci.cpp $(START_DIR)/CXSparse/Source/cs_qrsol_ri.cpp $(START_DIR)/CXSparse/Source/cs_qrsol_ci.cpp $(START_DIR)/CXSparse/Source/cs_scatter_ri.cpp $(START_DIR)/CXSparse/Source/cs_scatter_ci.cpp $(START_DIR)/CXSparse/Source/cs_scc_ri.cpp $(START_DIR)/CXSparse/Source/cs_scc_ci.cpp $(START_DIR)/CXSparse/Source/cs_schol_ri.cpp $(START_DIR)/CXSparse/Source/cs_schol_ci.cpp $(START_DIR)/CXSparse/Source/cs_sqr_ri.cpp $(START_DIR)/CXSparse/Source/cs_sqr_ci.cpp $(START_DIR)/CXSparse/Source/cs_symperm_ri.cpp $(START_DIR)/CXSparse/Source/cs_symperm_ci.cpp $(START_DIR)/CXSparse/Source/cs_tdfs_ri.cpp $(START_DIR)/CXSparse/Source/cs_tdfs_ci.cpp $(START_DIR)/CXSparse/Source/cs_transpose_ri.cpp $(START_DIR)/CXSparse/Source/cs_transpose_ci.cpp $(START_DIR)/CXSparse/Source/cs_compress_ri.cpp $(START_DIR)/CXSparse/Source/cs_compress_ci.cpp $(START_DIR)/CXSparse/Source/cs_updown_ri.cpp $(START_DIR)/CXSparse/Source/cs_updown_ci.cpp $(START_DIR)/CXSparse/Source/cs_usolve_ri.cpp $(START_DIR)/CXSparse/Source/cs_usolve_ci.cpp $(START_DIR)/CXSparse/Source/cs_utsolve_ri.cpp $(START_DIR)/CXSparse/Source/cs_utsolve_ci.cpp $(START_DIR)/CXSparse/Source/cs_util_ri.cpp $(START_DIR)/CXSparse/Source/cs_util_ci.cpp $(START_DIR)/CXSparse/Source/cs_reach_ri.cpp $(START_DIR)/CXSparse/Source/cs_reach_ci.cpp $(START_DIR)/CXSparse/Source/cs_spsolve_ri.cpp $(START_DIR)/CXSparse/Source/cs_spsolve_ci.cpp $(START_DIR)/CXSparse/Source/cs_ereach_ri.cpp $(START_DIR)/CXSparse/Source/cs_ereach_ci.cpp $(START_DIR)/CXSparse/Source/cs_leaf_ri.cpp $(START_DIR)/CXSparse/Source/cs_leaf_ci.cpp $(START_DIR)/CXSparse/Source/cs_randperm_ri.cpp $(START_DIR)/CXSparse/Source/cs_randperm_ci.cpp $(START_DIR)/CXSparse/Source/cs_operator_ri.cpp $(START_DIR)/CXSparse/Source/cs_operator_ci.cpp $(START_DIR)/CXSparse/CXSparseSupport/solve_from_lu.cpp $(START_DIR)/CXSparse/CXSparseSupport/solve_from_qr.cpp $(START_DIR)/CXSparse/CXSparseSupport/makeCXSparseMatrix.cpp $(START_DIR)/CXSparse/CXSparseSupport/unpackCXStruct.cpp

ALL_SRCS = $(SRCS)

###########################################################################
## OBJECTS
###########################################################################

OBJS = calc_fall_risk_rtwutil.o calc_fall_risk_data.o calc_fall_risk_initialize.o calc_fall_risk_terminate.o calc_fall_risk.o get_calibration.o calibrate.o get_features.o bwfilt.o myButter.o rdivide_helper.o abs.o mpower.o power.o combineVectorElements.o poly.o myfiltfilt.o sparse.o sparse1.o introsort.o insertionsort.o nextpow2.o filter.o bsxfun.o vecnorm.o mean.o var.o vvarstd.o skewness.o sum.o nan_sum_or_mean.o nanmean.o kurtosis.o rectwin.o pwelch.o psdesttype.o strcmp.o welch.o welchparse.o any1.o fix.o computeperiodogram.o computeDFT.o fft.o fft1.o bluesteinSetup.o psdfreqvec.o computepsd.o extrema.o diff.o ifWhileCond.o nullAssignment.o sign.o sign1.o sort1.o nonSingletonDim.o sortIdx.o mergesort.o sortLE.o relop.o xcorr.o ifft.o CompactSVM.o CompactClassificationModel.o pre_process_feats.o dot.o Gaussian.o get_strides.o crossing0.o norm.o calc_fall_risk_emxutil.o rt_nonfinite.o rtGetNaN.o rtGetInf.o cs_add_ri.o cs_add_ci.o cs_amd_ri.o cs_amd_ci.o cs_chol_ri.o cs_chol_ci.o cs_cholsol_ri.o cs_cholsol_ci.o cs_counts_ri.o cs_counts_ci.o cs_cumsum_ri.o cs_cumsum_ci.o cs_dfs_ri.o cs_dfs_ci.o cs_dmperm_ri.o cs_dmperm_ci.o cs_droptol_ri.o cs_droptol_ci.o cs_dropzeros_ri.o cs_dropzeros_ci.o cs_dupl_ri.o cs_dupl_ci.o cs_entry_ri.o cs_entry_ci.o cs_etree_ri.o cs_etree_ci.o cs_fkeep_ri.o cs_fkeep_ci.o cs_gaxpy_ri.o cs_gaxpy_ci.o cs_happly_ri.o cs_happly_ci.o cs_house_ri.o cs_house_ci.o cs_ipvec_ri.o cs_ipvec_ci.o cs_load_ri.o cs_load_ci.o cs_lsolve_ri.o cs_lsolve_ci.o cs_ltsolve_ri.o cs_ltsolve_ci.o cs_lu_ri.o cs_lu_ci.o cs_lusol_ri.o cs_lusol_ci.o cs_malloc_ri.o cs_malloc_ci.o cs_maxtrans_ri.o cs_maxtrans_ci.o cs_multiply_ri.o cs_multiply_ci.o cs_norm_ri.o cs_norm_ci.o cs_permute_ri.o cs_permute_ci.o cs_pinv_ri.o cs_pinv_ci.o cs_post_ri.o cs_post_ci.o cs_print_ri.o cs_print_ci.o cs_pvec_ri.o cs_pvec_ci.o cs_qr_ri.o cs_qr_ci.o cs_qrsol_ri.o cs_qrsol_ci.o cs_scatter_ri.o cs_scatter_ci.o cs_scc_ri.o cs_scc_ci.o cs_schol_ri.o cs_schol_ci.o cs_sqr_ri.o cs_sqr_ci.o cs_symperm_ri.o cs_symperm_ci.o cs_tdfs_ri.o cs_tdfs_ci.o cs_transpose_ri.o cs_transpose_ci.o cs_compress_ri.o cs_compress_ci.o cs_updown_ri.o cs_updown_ci.o cs_usolve_ri.o cs_usolve_ci.o cs_utsolve_ri.o cs_utsolve_ci.o cs_util_ri.o cs_util_ci.o cs_reach_ri.o cs_reach_ci.o cs_spsolve_ri.o cs_spsolve_ci.o cs_ereach_ri.o cs_ereach_ci.o cs_leaf_ri.o cs_leaf_ci.o cs_randperm_ri.o cs_randperm_ci.o cs_operator_ri.o cs_operator_ci.o solve_from_lu.o solve_from_qr.o makeCXSparseMatrix.o unpackCXStruct.o

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

SYSTEM_LIBS =  -L$(MATLAB_ROOT)/sys/os/maci64 -lm -lstdc++ -liomp5

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


%.o : /Users/MelissaSeib/Desktop/app_code_in_C++/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : /Users/MelissaSeib/Desktop/app_code_in_C++/%.cpp
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


