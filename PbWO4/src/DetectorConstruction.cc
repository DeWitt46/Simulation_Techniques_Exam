//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
//
/// \file DetectorConstruction.cc
/// \brief Implementation of the B4:DetectorConstruction class

#include "DetectorConstruction.hh"

#include "G4Material.hh"
#include "G4NistManager.hh"

#include "G4Box.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4PVReplica.hh"
#include "G4GlobalMagFieldMessenger.hh"
#include "G4AutoDelete.hh"

#include "G4GeometryManager.hh"
#include "G4PhysicalVolumeStore.hh"
#include "G4LogicalVolumeStore.hh"
#include "G4SolidStore.hh"

#include "G4VisAttributes.hh"
#include "G4Colour.hh"

#include "G4PhysicalConstants.hh"
#include "G4SystemOfUnits.hh"

namespace B4
{

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4ThreadLocal
G4GlobalMagFieldMessenger* DetectorConstruction::fMagFieldMessenger = nullptr;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

DetectorConstruction::DetectorConstruction()
{
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

DetectorConstruction::~DetectorConstruction()
{
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4VPhysicalVolume* DetectorConstruction::Construct()
{
	// Define materials
	DefineMaterials();

	// Define volumes
	return DefineVolumes();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void DetectorConstruction::DefineMaterials()
{
	// Lead material defined using NIST Manager
	auto nistManager = G4NistManager::Instance();
	nistManager->FindOrBuildMaterial("G4_Pb");

	// Try building PbWO4 - Lead Tungstate
	G4double a;  // mass of a mole;
	G4double z;  // z=mean number of protons;	
	G4double z_Pb, a_Pb;
	G4double z_W, a_W;
	G4double z_O, a_O;	
	G4double density_PbWO4;
	
	G4String name, symbol;
	G4int ncomponents, natoms;
	a_Pb = 208.2*g/mole;
	z_Pb = 82;
	G4Element* elPb = new G4Element(name="Lead",symbol="Pb" , z = z_Pb, a_Pb);

	a_W = 183.84*g/mole;
	z_W = 74;
	G4Element* elW = new G4Element(name="Tungsten" ,symbol="W" , z = z_W, a_W);
	
	a_O = 16.00*g/mole;
	z_O = 8;
	G4Element* elO = new G4Element(name="Oxygen" ,symbol="O" , z = z_O, a_O);

	density_PbWO4 = 8.28*g/cm3;
	G4Material* PbWO4 = new G4Material(name="LeadTungstate",density_PbWO4,ncomponents=3);
	PbWO4->AddElement(elPb, natoms=1);
	PbWO4->AddElement(elW, natoms=1);	
	PbWO4->AddElement(elO, natoms=4);		
	// Done	

		
	// Liquid argon material
	G4double density;
	new G4Material("liquidArgon", z=18., a= 39.95*g/mole, density= 1.390*g/cm3);
	// The argon by NIST Manager is a gas with a different density

	// Vacuum
	new G4Material("Galactic", z=1., a=1.01*g/mole,density= universe_mean_density,
                  kStateGas, 2.73*kelvin, 3.e-18*pascal);

	// Print materials
	G4cout << *(G4Material::GetMaterialTable()) << G4endl;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4VPhysicalVolume* DetectorConstruction::DefineVolumes()
{
	// Geometry parameters
	G4int nofLayers = 1;
	G4double absoThickness = 4.5*cm;
	G4double gapThickness =  0.*cm;
	G4double absorberDisplacement =  1.*m;	
	G4double calorSizeXY  = 20.*cm;

	auto layerThickness = absoThickness + gapThickness + absorberDisplacement;
	auto calorThickness = nofLayers * layerThickness;
	auto worldSizeXY = 1.2 * calorSizeXY;
	auto worldSizeZ  = 1.2 * calorThickness;

	// Get materials
	auto defaultMaterial = G4Material::GetMaterial("Galactic");
	auto absorberMaterial = G4Material::GetMaterial("LeadTungstate");
	auto gapMaterial = G4Material::GetMaterial("liquidArgon");

	if ( ! defaultMaterial || ! absorberMaterial || ! gapMaterial ) {
		G4ExceptionDescription msg;
		msg << "Cannot retrieve materials already defined.";
		G4Exception("DetectorConstruction::DefineVolumes()",
			"MyCode0001", FatalException, msg);
	}

	//
	// World
	//
	auto worldS
		= new G4Box("World",           // its name
								worldSizeXY/2, worldSizeXY/2, worldSizeZ/2); // its size

	auto worldLV
	= new G4LogicalVolume(
							worldS,           // its solid
							defaultMaterial,  // its material
							"World");         // its name

	auto worldPV
		= new G4PVPlacement(
							0,                // no rotation
							G4ThreeVector(),  // at (0,0,0)
							worldLV,          // its logical volume
							"World",          // its name
							0,                // its mother  volume
							false,            // no boolean operation
							0,                // copy number
							fCheckOverlaps);  // checking overlaps

	//
	// Calorimeter
	//
//	auto calorimeterS
//		= new G4Box("Calorimeter",     // its name
//							calorSizeXY/2, calorSizeXY/2, calorThickness/2); // its size

//	auto calorLV
//		= new G4LogicalVolume(
//							calorimeterS,     // its solid
//							defaultMaterial,  // its material
//							"Calorimeter");   // its name

//	new G4PVPlacement(
//							0,                // no rotation
//							G4ThreeVector(),  // at (0,0,0)
//							calorLV,          // its logical volume
//							"Calorimeter",    // its name
//							worldLV,          // its mother  volume
//							false,            // no boolean operation
//							0,                // copy number
//							fCheckOverlaps);  // checking overlaps

	//
	// Layer
	//
//	auto layerS
//		= new G4Box("Layer",           // its name
//							calorSizeXY/2, calorSizeXY/2, layerThickness/2); // its size

//	auto layerLV
//		= new G4LogicalVolume(
//							layerS,           // its solid
	//						defaultMaterial,  // its material
	//						"Layer");         // its name

	//new G4PVReplica(
	//						"Layer",          // its name
	//						layerLV,          // its logical volume
	//						calorLV,          // its mother
	//						kZAxis,           // axis of replication
	//						nofLayers,        // number of replica
		//					layerThickness);  // witdth of replica

	//
	// Absorber
	//
	auto absorberS
		= new G4Box("Abso",            // its name
							calorSizeXY/2, calorSizeXY/2, absoThickness/2); // its size

	auto absorberLV
		= new G4LogicalVolume(
							absorberS,        // its solid
							absorberMaterial, // its material
							"Abso");          // its name

	fAbsorberPV
		= new G4PVPlacement(
							0,                // no rotation
							G4ThreeVector(0., 0., absorberDisplacement/2), // its position
							absorberLV,       // its logical volume
							"Abso",           // its name
							worldLV,          // its mother  volume
							false,            // no boolean operation
							0,                // copy number
							fCheckOverlaps);  // checking overlaps

  //
  // Gap
  //
//  auto gapS
//    = new G4Box("Gap",             // its name
//                 calorSizeXY/2, calorSizeXY/2, gapThickness/2); // its size

//  auto gapLV
//    = new G4LogicalVolume(
//                 gapS,             // its solid
//                 gapMaterial,      // its material
  //               "Gap");           // its name

  //fGapPV
  //  = new G4PVPlacement(
  //               0,                // no rotation
  //               G4ThreeVector(0., 0., absoThickness/2), // its position
  //               gapLV,            // its logical volume
  //               "Gap",            // its name
  //               layerLV,          // its mother  volume
  //               false,            // no boolean operation
  //               0,                // copy number
  //               fCheckOverlaps);  // checking overlaps

	//
	// print parameters
	//
	G4cout
		<< G4endl
		<< "------------------------------------------------------------" << G4endl
		<< "---> The calorimeter is " << nofLayers << " layers of: [ "
		<< absoThickness/cm << "cm of " << absorberMaterial->GetName()
		<< " + "
		<< gapThickness/mm << "mm of " << gapMaterial->GetName() << " ] " << G4endl
		<< " at " << absorberDisplacement/cm << "cm from interaction point."
		<< "------------------------------------------------------------" << G4endl;

	//
	// Visualization attributes
	//

	//worldLV is by default white and visible
	auto simpleBoxVisAtt= new G4VisAttributes(G4Colour(0., 0., 1.));
	simpleBoxVisAtt->SetVisibility(true);
	absorberLV->SetVisAttributes(simpleBoxVisAtt);

	//
	// Always return the physical World
	//
	return worldPV;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void DetectorConstruction::ConstructSDandField()
{
	// Create global magnetic field messenger.
	// Uniform magnetic field is then created automatically if
	// the field value is not zero.
	G4ThreeVector fieldValue;
	fMagFieldMessenger = new G4GlobalMagFieldMessenger(fieldValue);
	fMagFieldMessenger->SetVerboseLevel(1);

	// Register the field messenger for deleting
	G4AutoDelete::Register(fMagFieldMessenger);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

}

