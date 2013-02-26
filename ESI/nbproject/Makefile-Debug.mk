#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/enemy.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/character.o \
	${OBJECTDIR}/laser.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-L/usr/lib -Wl,-Bsymbolic-functions -lalleg -lm -lXxf86vm -lXcursor -lXpm -lXext -lX11 -lpthread -ldl `pkg-config --cflags --libs allegro-5.0 allegro_acodec-5.0 allegro_audio-5.0 allegro_color-5.0 allegro_dialog-5.0 allegro_font-5.0 allegro_image-5.0 allegro_main-5.0 allegro_memfile-5.0 allegro_physfs-5.0 allegro_primitives-5.0 allegro_ttf-5.0`  

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/esi

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/esi: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} `pkg-config --cflags --libs allegro-5.0 allegro_acodec-5.0 allegro_audio-5.0 allegro_color-5.0 allegro_dialog-5.0 allegro_font-5.0 allegro_image-5.0 allegro_main-5.0 allegro_memfile-5.0 allegro_physfs-5.0 allegro_primitives-5.0 allegro_ttf-5.0` -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/esi  ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/enemy.o: enemy.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g `pkg-config --cflags --cflags allegro-5.0 allegro_acodec-5.0 allegro_audio-5.0 allegro_color-5.0 allegro_dialog-5.0 allegro_font-5.0 allegro_image-5.0 allegro_main-5.0 allegro_memfile-5.0 allegro_physfs-5.0 allegro_primitives-5.0 allegro_ttf-5.0`    -MMD -MP -MF $@.d -o ${OBJECTDIR}/enemy.o enemy.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g `pkg-config --cflags --cflags allegro-5.0 allegro_acodec-5.0 allegro_audio-5.0 allegro_color-5.0 allegro_dialog-5.0 allegro_font-5.0 allegro_image-5.0 allegro_main-5.0 allegro_memfile-5.0 allegro_physfs-5.0 allegro_primitives-5.0 allegro_ttf-5.0`    -MMD -MP -MF $@.d -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/character.o: character.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g `pkg-config --cflags --cflags allegro-5.0 allegro_acodec-5.0 allegro_audio-5.0 allegro_color-5.0 allegro_dialog-5.0 allegro_font-5.0 allegro_image-5.0 allegro_main-5.0 allegro_memfile-5.0 allegro_physfs-5.0 allegro_primitives-5.0 allegro_ttf-5.0`    -MMD -MP -MF $@.d -o ${OBJECTDIR}/character.o character.cpp

${OBJECTDIR}/laser.o: laser.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g `pkg-config --cflags --cflags allegro-5.0 allegro_acodec-5.0 allegro_audio-5.0 allegro_color-5.0 allegro_dialog-5.0 allegro_font-5.0 allegro_image-5.0 allegro_main-5.0 allegro_memfile-5.0 allegro_physfs-5.0 allegro_primitives-5.0 allegro_ttf-5.0`    -MMD -MP -MF $@.d -o ${OBJECTDIR}/laser.o laser.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/esi

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
