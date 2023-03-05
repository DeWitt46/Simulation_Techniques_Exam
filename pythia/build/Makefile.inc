# PYTHIA configuration file.
# Generated on Wed Nov 23 18:10:48 CET 2022 with the user supplied options:
# --with-root
# --with-root-bin=/data/dataalice/AliceSoftware/root6/build1/bin/
# --with-root-lib=/data/dataalice/AliceSoftware/root6/build1/lib
# --with-root-include=/data/dataalice/AliceSoftware/root6/build1/include
# --with-hepmc3
# --with-hepmc3-bin=/data/dataalice/corso-programmazione-avanzata/HepMC3-3.2.5/hepmc3-install/bin/
# --with-hepmc3-lib=/data/dataalice/corso-programmazione-avanzata/HepMC3-3.2.5/hepmc3-install/lib64/
# --with-hepmc3-include=/data/dataalice/corso-programmazione-avanzata/HepMC3-3.2.5/include/
# --with-hepmc2
# --with-hepmc2-lib=/data/dataalice/corso-programmazione-avanzata/build-hepmc2/lib
# --with-hepmc2-include=/data/dataalice/corso-programmazione-avanzata/build-hepmc2/include

# Install directory prefixes.
PREFIX_BIN=/data/dataalice/corso-programmazione-avanzata/pythia8308/bin
PREFIX_INCLUDE=/data/dataalice/corso-programmazione-avanzata/pythia8308/include
PREFIX_LIB=/data/dataalice/corso-programmazione-avanzata/pythia8308/lib
PREFIX_SHARE=/data/dataalice/corso-programmazione-avanzata/pythia8308/share/Pythia8

# Compilation flags (see ./configure --help for further documentation).
CXX=g++
CXX_COMMON=-O2 -std=c++11 -pedantic -W -Wall -Wshadow -fPIC -pthread
CXX_SHARED=-shared
CXX_SONAME=-Wl,-soname,
LIB_SUFFIX=.so
OBJ_COMMON=

EVTGEN_USE=false
EVTGEN_CONFIG=
EVTGEN_BIN=
EVTGEN_INCLUDE=
EVTGEN_LIB=

FASTJET3_USE=false
FASTJET3_CONFIG=
FASTJET3_BIN=
FASTJET3_INCLUDE=
FASTJET3_LIB=

HEPMC2_USE=true
HEPMC2_CONFIG=
HEPMC2_BIN=
HEPMC2_INCLUDE=-I/data/dataalice/corso-programmazione-avanzata/build-hepmc2/include
HEPMC2_LIB=-L/data/dataalice/corso-programmazione-avanzata/build-hepmc2/lib -Wl,-rpath,/data/dataalice/corso-programmazione-avanzata/build-hepmc2/lib -lHepMC

HEPMC3_USE=true
HEPMC3_CONFIG=HepMC3-config
HEPMC3_BIN=/data/dataalice/corso-programmazione-avanzata/HepMC3-3.2.5/hepmc3-install/bin/
HEPMC3_INCLUDE=-I/data/dataalice/corso-programmazione-avanzata/HepMC3-3.2.5/include
HEPMC3_LIB=-L/data/dataalice/corso-programmazione-avanzata/HepMC3-3.2.5/hepmc3-install/lib64 -Wl,-rpath,/data/dataalice/corso-programmazione-avanzata/HepMC3-3.2.5/hepmc3-install/lib64 -lHepMC3

LHAPDF5_USE=false
LHAPDF5_CONFIG=
LHAPDF5_BIN=
LHAPDF5_INCLUDE=
LHAPDF5_LIB=

LHAPDF6_USE=false
LHAPDF6_CONFIG=
LHAPDF6_BIN=
LHAPDF6_INCLUDE=
LHAPDF6_LIB=

POWHEG_USE=false
POWHEG_CONFIG=
POWHEG_BIN=
POWHEG_INCLUDE=
POWHEG_LIB=

RIVET_USE=false
RIVET_CONFIG=
RIVET_BIN=
RIVET_INCLUDE=
RIVET_LIB=

ROOT_USE=true
ROOT_CONFIG=root-config
ROOT_BIN=/data/dataalice/AliceSoftware/root6/build1/bin/
ROOT_INCLUDE=-I/data/dataalice/AliceSoftware/root6/build1/include
ROOT_LIB=-L/data/dataalice/AliceSoftware/root6/build1/lib -Wl,-rpath,/data/dataalice/AliceSoftware/root6/build1/lib -lCore

GZIP_USE=false
GZIP_CONFIG=
GZIP_BIN=
GZIP_INCLUDE=
GZIP_LIB=

PYTHON_USE=false
PYTHON_CONFIG=
PYTHON_BIN=
PYTHON_INCLUDE=
PYTHON_LIB=

MG5MES_USE=false
MG5MES_CONFIG=
MG5MES_BIN=
MG5MES_INCLUDE=
MG5MES_LIB=

OPENMP_USE=false
OPENMP_CONFIG=
OPENMP_BIN=
OPENMP_INCLUDE=
OPENMP_LIB=

MPICH_USE=false
MPICH_CONFIG=
MPICH_BIN=
MPICH_INCLUDE=
MPICH_LIB=

HDF5_USE=false
HDF5_CONFIG=
HDF5_BIN=
HDF5_INCLUDE=
HDF5_LIB=

HIGHFIVE_USE=false
HIGHFIVE_CONFIG=
HIGHFIVE_BIN=
HIGHFIVE_INCLUDE=
HIGHFIVE_LIB=
