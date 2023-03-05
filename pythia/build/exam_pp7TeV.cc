// Headers and Namespaces.

// ROOT, for histogramming.
#include "TH1.h"

// ROOT, for saving file.
#include "TFile.h"

// Pythia headers.
#include "Pythia8/Pythia.h"

// Multithreading
#include "Pythia8/PythiaParallel.h"

// Progress Log
#include "Pythia8Plugins/ProgressLog.h"

using namespace Pythia8; // Let Pythia8:: be implicit.



int main() { // Begin main program without card file.

	// Set up generation.
	// Use the PythiaParallel class for parallel generation.
	PythiaParallel pythia;

	// Create file on which histogram(s) can be saved.
	TFile* outFile = new TFile("pp7TeV.root", "RECREATE");
	
	// Book histogram.
	TH1F *mult = new TH1F("mult","charged multiplicity", 400, -0.5, 150.5);
	TH1F *p_pT = new TH1F("p_pT","proton pT", 400, -0.1, 3);
	TH1F *pi_pT = new TH1F("pi_pT","pion pT", 400, -0.1, 3);
	
	cout << endl;
	cout << "!ccccccccccccccccccccccccccccccc" << endl;
	cout << "p-p at 7 TeV" << endl;		
	cout << "!ccccccccccccccccccccccccccccccc" << endl;
	cout << endl;
			
	// Read in commands from external file doesn't work with parallel.
	pythia.readFile("exam_settings.cmnd", 0);
	
		
	pythia.init(); // Initialize generation; incoming pp beams is default.

	// Set up Pythia just for reading number of Events bc I can't do It with PythiaParallel
	Pythia reader;
	reader.readFile("exam_settings.cmnd", 0);	
	const int nEvents = reader.mode("Main:numberOfEvents");

	// Initialise the printout of run progress information.
	ProgressLog logger(nEvents);

	int iEvent = 0;
	
	// Use PythiaParallel::run to generate the specified number of events.
	pythia.run( 
   	// This defines a lambda function that acts as a callback.
   	// This function is called for each event generated.
   	// The argument is the Pythia instance that generated the event.
		[&](Pythia& pythiaNow) {
		
			// Event counter
			iEvent += 1;
			
			// pythiaNow gives a reference to the instance that generated the event.
			Event& event = pythiaNow.event;	

			//Particle Loop to access properties of each particle event[i]
			// Find number of all final charged particles.
			int nCharged = 0;
			
			for (int i = 0; i < event.size(); ++i) {
			// Any cut If necessary
				if (event[i].isFinal() && event[i].isCharged() && event[i].eta() > -2.4 && event[i].eta() < 2.4)
				++nCharged;
				if (event[i].isFinal() && event[i].id() == 2212) p_pT->Fill(event[i].pT());
				if (event[i].isFinal() && event[i].id() == 211)  pi_pT->Fill(event[i].pT());

			} // End particle loop
			
			//Note that this callback is called synchronously,
			// which ensures two threads cannot write to histogram at the same time.
			mult->Fill(nCharged);

			// Intermittently report run progress.
			logger(iEvent);
			
		} // End callback
	); // End parallel run
							
	pythia.stat(); // To obtain statistics
		
	// Save histogram on file and close file.
	mult->Write();
	p_pT->Write();
	pi_pT->Write();
	delete outFile;
				
	return 0;

} // End main program with error-free return.
