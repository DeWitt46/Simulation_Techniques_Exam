// ROOT macro file for the PbWO4 and NaI calorimeter histograms
//
// Can be run from ROOT session:
// root[0] .x plotHisto.C

{
	// Draw histos filled by Pythia simulation
	gStyle->SetOptStat(0); // Hide or not the statistics box


	
    // Open file filled by Pythia simulation
	TFile* inFile = new TFile("Hep_Table7.root", "READ");
//	inFile3->ls(); // To show what's inside
	TDirectory *cartella = (TDirectory*)inFile->Get("Table 7");
	TH1F* multHEP = new TH1F("multHEP","Data", 400, -0.5, 399.5);
	multHEP = (TH1F*)cartella->Get("Hist1D_y1");
	
	
	
	TFile* inFile1 = new TFile("pp7TeV.root", "READ");
	
	TH1F* mult1 = new TH1F("mult","SoftQCD", 400, -0.5, 399.5);
	mult1 = (TH1F*)inFile1->Get("mult"); // multiplicity distribution
	
	TCanvas* c1 = new TCanvas("c1", "", 0, 0, 800, 600);
    c1->Divide(1,2); // Charged multiplicity for pp
    
    c1->cd(1);
    mult1->Draw();
    
	/*
	TH1F* p_pT1 = new TH1F("p_PT1","SoftQCD", 400, -0.5, 399.5);
	p_pT1 = (TH1F*)inFile1->Get("p_pT"); // p transverse momentum
	TH1F* pi_pT1 = new TH1F("pi_PT1","SoftQCD", 400, -0.5, 399.5);
	pi_pT1 = (TH1F*)inFile1->Get("pi_pT"); // pi transverse momentum

	TFile* inFile2 = new TFile("pp7TeV.root", "READ"); // To change into pp13TeV
	
	TH1F* mult2 = new TH1F("mult","SoftQCD", 400, -0.5, 399.5);
	mult2 = (TH1F*)inFile2->Get("mult"); // multiplicity distribution
	TH1F* p_pT2 = new TH1F("p_PT2","SoftQCD", 400, -0.5, 399.5);
	p_pT2 = (TH1F*)inFile2->Get("p_pT"); // p transverse momentum
	TH1F* pi_pT2 = new TH1F("pi_PT2","SoftQCD", 400, -0.5, 399.5);
	pi_pT2 = (TH1F*)inFile2->Get("pi_pT"); // pi transverse momentum
	
	

	TFile* inFile31 = new TFile("PbPb5TeV_H.root", "READ"); // To change into PbPb5TeV_S.root
	
	TH1F* mult31 = new TH1F("mult","SoftQCD", 400, -0.5, 399.5);
	mult31 = (TH1F*)inFile31->Get("mult"); // multiplicity distribution
	TH1F* p_pT31 = new TH1F("p_PT31","SoftQCD", 400, -0.5, 399.5);
	p_pT31 = (TH1F*)inFile31->Get("p_pT"); // p transverse momentum
	TH1F* pi_pT31 = new TH1F("pi_PT31","SoftQCD", 400, -0.5, 399.5);
	pi_pT31 = (TH1F*)inFile31->Get("pi_pT"); // pi transverse momentum	



	TFile* inFile32 = new TFile("PbPb5TeV_H.root", "READ");
	
	TH1F* mult32 = new TH1F("mult","HardQCD", 400, -0.5, 399.5);
	mult32 = (TH1F*)inFile32->Get("mult"); // multiplicity distribution
	TH1F* p_pT32 = new TH1F("p_PT32","HardQCD", 400, -0.5, 399.5);
	p_pT32 = (TH1F*)inFile32->Get("p_pT"); // p transverse momentum
	TH1F* pi_pT32 = new TH1F("pi_PT32","HardQCD", 400, -0.5, 399.5);
	pi_pT32 = (TH1F*)inFile32->Get("pi_pT"); // pi transverse momentum	



	TFile* inFile41 = new TFile("PbPb54TeV_H.root", "READ"); // To change into PbPb54TeV_S.root
	
	TH1F* mult41 = new TH1F("mult","SoftQCD", 400, -0.5, 399.5);
	mult41 = (TH1F*)inFile41->Get("mult"); // multiplicity distribution
	TH1F* p_pT41 = new TH1F("p_PT41","SoftQCD", 400, -0.5, 399.5);
	p_pT41 = (TH1F*)inFile41->Get("p_pT"); // p transverse momentum
	TH1F* pi_pT41 = new TH1F("pi_PT41","SoftQCD", 400, -0.5, 399.5);
	pi_pT41 = (TH1F*)inFile41->Get("pi_pT"); // pi transverse momentum	



	TFile* inFile42 = new TFile("PbPb54TeV_H.root", "READ");
	
	TH1F* mult42 = new TH1F("mult","HardQCD", 400, -0.5, 399.5);
	mult42 = (TH1F*)inFile42->Get("mult"); // multiplicity distribution
	TH1F* p_pT42 = new TH1F("p_PT42","HardQCD", 400, -0.5, 399.5);
	p_pT42 = (TH1F*)inFile42->Get("p_pT"); // p transverse momentum
	TH1F* pi_pT42 = new TH1F("pi_PT42","HardQCD", 400, -0.5, 399.5);
	pi_pT42 = (TH1F*)inFile42->Get("pi_pT"); // pi transverse momentum	

	

    // Create some canvas. Divide them into 2x2 pads
    TCanvas* c1 = new TCanvas("c1", "", 0, 0, 800, 600);
    c1->Divide(1,2); // Charged multiplicity for pp
    
    TCanvas* c2 = new TCanvas("c1", "", 0, 0, 800, 600);
    c2->Divide(1,2); // Charged multiplicity for PbPb. comparison Soft-Hard
    
    TCanvas* c3 = new TCanvas("c3", "", 0, 0, 800, 600);
    c3->Divide(2,2); // p_pT on pi p_T






    // Charged multiplicity for pp
    c1->cd(1);
    // Settings are fine for just one of them
    mult1->SetTitle("Charged multiplicity for p-p at 7 TeV");    
//    hist1->GetXaxis()->SetRangeUser(-0.5, 51);
    mult1->GetXaxis()->SetTitle("N_{ch}");
    mult1->GetYaxis()->SetTitle("P[N_{ch}]");
    mult1->GetYaxis()->SetTitleOffset(1.4);

    mult1->SetLineColor(kRed);
    multHEP->SetLineColor(kGreen);
    mult1->DrawNormalized("HIST"); //Draws only boxes
    multHEP->DrawNormalized("HIST SAME"); //Draws only boxes. same to plot both
	//Draw Legend
	auto legend1 = new TLegend(0.1, 0.7, 0.4, 0.9); //x1,y1,x2,y2
//	legend1->SetHeader("Set Title Here","C"); // option "C" allows to center the header
	legend1->AddEntry(mult1, "Pythia simulation","f");
	legend1->AddEntry(multHEP, "HEP Data","f");	
	legend1->Draw();



    c1->cd(2);
    // Settings are fine for just one of them
    mult2->SetTitle("Charged multiplicity for p-p at 13.6 TeV");    
//    hist1->GetXaxis()->SetRangeUser(-0.5, 51);
    mult2->GetXaxis()->SetTitle("N_{ch}");
    mult2->GetYaxis()->SetTitle("P[N_{ch}]");
    mult2->GetYaxis()->SetTitleOffset(1.4);
    mult2->SetLineColor(kRed);
    mult2->DrawNormalized("HIST"); //Draws only boxes
	//Draw Legend
	auto legend2 = new TLegend(0.1, 0.7, 0.4, 0.9); //x1,y1,x2,y2
//	legend1->SetHeader("The Legend Title","C"); // option "C" allows to center the header
	legend2->AddEntry(mult2, "Pythia simulation","f");
	legend2->Draw();
    
    



	// Charged multiplicity PbPb comparison Soft-Hard   
    c2->cd(1);
    // Settings are fine for just one of them
    mult31->SetTitle("Charged multiplicity for Pb-Pb at 5.02 TeV");    
//    hist1->GetXaxis()->SetRangeUser(-0.5, 51);
    mult31->GetXaxis()->SetTitle("N_{ch}");
    mult31->GetYaxis()->SetTitle("P[N_{ch}]");
    mult31->GetYaxis()->SetTitleOffset(1.4);
    
    mult31->SetLineColor(kRed);
    mult32->SetLineColor(kBlue);
    mult31->DrawNormalized("HIST"); //Draws only boxes
    mult32->DrawNormalized("HIST SAME"); //Draws only boxes. Same for plotting both
	//Draw Legend
	auto legend3 = new TLegend(0.1, 0.7, 0.4, 0.9); //x1,y1,x2,y2
//	legend3->SetHeader("The Legend Title","C"); // option "C" allows to center the header
	legend3->AddEntry(mult31, "Pythia simulation SoftQCD","f");
	legend3->AddEntry(mult32, "Pythia simulation HardQCD","f");	
	legend3->Draw();    
    
    
    
    c2->cd(2);
    // Settings are fine for just one of them
    mult41->SetTitle("Charged multiplicity for Pb-Pb at 5.4 TeV");    
//    hist1->GetXaxis()->SetRangeUser(-0.5, 51);
    mult41->GetXaxis()->SetTitle("N_{ch}");
    mult41->GetYaxis()->SetTitle("P[N_{ch}]");
    mult41->GetYaxis()->SetTitleOffset(1.4);
    
    mult41->SetLineColor(kRed);
    mult42->SetLineColor(kBlue);    
    mult41->DrawNormalized("HIST"); //Draws only boxes
    mult42->DrawNormalized("HIST SAME"); //Draws only boxes. Same for plotting both    
	//Draw Legend
	auto legend4 = new TLegend(0.1, 0.7, 0.4, 0.9); //x1,y1,x2,y2
//	legend4->SetHeader("The Legend Title","C"); // option "C" allows to center the header
	legend4->AddEntry(mult41, "Pythia simulation SoftQCD","f");
	legend4->AddEntry(mult42, "Pythia simulation HardQCD","f");	
	legend4->Draw();
*/	
	
}
