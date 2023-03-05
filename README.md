# Simulation Techniques Exam

The exam is divided in 2 main parts.
- Simulate p-p and Pb-Pb collisions using Pythia, then analyse charged multiplicity and compare It to [HEP data](https://www.hepdata.net/record/ins1614477). As last step, look at p and $\pi$ transverse momentum distributions.
- Simulate two calorimeters: one parallelepiped made of PbWO4 and another of NaI. Compare their performance with an EM shower.

## Installation

[Pythia](https://www.pythia.org) and [Geant4](https://geant4.web.cern.ch/download/11.1.1.html) are needed.

## Description

The two directories are independent one from each other.

The Pythia folder contains two sub-folders.
- "exam_data" contains data of the simulations I did and ROOT macro to plot the histograms;
- "" contains all the code needed for the simulation of both p-p and Pb-Pb collisions.
- 
The geant4 folder contains three sub-folders.
- "exam_data" contains data of the simulations I did and ROOT macro to plot the histograms;
- "PbWO4" contains all the code needed for the simulation of the PbWO4 calorimeter;
- "NaI" contains all the code needed for the simulation of the NaI calorimeter.
The last two are very very similar, since the only difference is the material.

## Usage

PbWO4 and NaI calorimeter share the same structure.
Download the directories and go into /PbWO4 (or NaI) and then in /build, which contains the macro to run the EM shower and the executable.
```bash
cd ./geant4/PbWO4/build
```

```bash
./exampleB2b -m ExamRun.mac
```
The output will be a ROOT file called "B4.root".
To change the material or the geometry of the calorimeter you have to change the file DetectorConstruction.cc in the folder /src with an editor, like gedit.
```bash
cd ./geant4/PbWO4/src

gedit DetectorConstruction.cc
```
After that, you have to compile again, so go into build and type make.

```bash
cd ../build

make
```
Then you can call again the executable.
You can also change the macro run, for example the energy of the beam or add a magnetic field inside the calorimeter.

```C++
/gun/energy 150 MeV

```
