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
CND_PLATFORM=GNU-Linux
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
	${OBJECTDIR}/Bishop.o \
	${OBJECTDIR}/King.o \
	${OBJECTDIR}/Knight.o \
	${OBJECTDIR}/Pawn.o \
	${OBJECTDIR}/Piece.o \
	${OBJECTDIR}/Queen.o \
	${OBJECTDIR}/Rook.o \
	${OBJECTDIR}/main.o


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
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/chess_august

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/chess_august: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/chess_august ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/Bishop.o: Bishop.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Bishop.o Bishop.cpp

${OBJECTDIR}/King.o: King.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/King.o King.cpp

${OBJECTDIR}/Knight.o: Knight.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Knight.o Knight.cpp

${OBJECTDIR}/Pawn.o: Pawn.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Pawn.o Pawn.cpp

${OBJECTDIR}/Piece.o: Piece.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Piece.o Piece.cpp

${OBJECTDIR}/Queen.o: Queen.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Queen.o Queen.cpp

${OBJECTDIR}/Rook.o: Rook.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Rook.o Rook.cpp

${OBJECTDIR}/main.o: main.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
