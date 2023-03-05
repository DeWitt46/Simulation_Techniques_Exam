// ROOT macro file for the NaI calorimeter histograms
//
// Can be run from ROOT session:
// root[0] .x plotHisto.C

{
	// Draw histos filled by Geant4 simulation
    gStyle->SetOptStat(0); // Hide or not the statistics box
	
    // Open file filled by Geant4 simulation    
	TFile* inFile1 = new TFile("NaI_lowE_lowD.root", "READ");    

	TH1D* hist1 = new TH1D("hist1","Data", 400, -0.5, 399.5);
	hist1 = (TH1D*)inFile1->Get("Eabs");    
	TH1D* hist2 = new TH1D("hist2","Data", 400, -0.5, 399.5);
	hist2 = (TH1D*)inFile1->Get("Egap");
	
	
	
	TFile* inFile2 = new TFile("NaI_lowE_highD.root", "READ");

	TH1D* hist3 = new TH1D("hist3","Data", 400, -0.5, 399.5);
	hist3 = (TH1D*)inFile2->Get("Eabs");    
	TH1D* hist4 = new TH1D("hist4","Data", 400, -0.5, 399.5);
	hist4 = (TH1D*)inFile2->Get("Labs");



	TFile* inFile3 = new TFile("NaI_lowE_rightD.root", "READ");

	TH1D* hist5 = new TH1D("hist5","Data", 400, -0.5, 399.5);
	hist5 = (TH1D*)inFile3->Get("Eabs");    
	
	
	
	TFile* inFile4 = new TFile("NaI_highE_rightD.root", "READ");

	TH1D* hist6 = new TH1D("hist6","Data", 400, -0.5, 399.5);
	hist6 = (TH1D*)inFile4->Get("Eabs");    



    // Create some canvas. Divide some into 1x2 pads
    TCanvas* c1 = new TCanvas("c1", "", 0, 0, 800, 600);
    c1->Divide(1,2); //lowElowD E_abs and E_gap
    
    TCanvas* c2 = new TCanvas("c2", "", 0, 0, 800, 600);
    c2->Divide(1,2); // lowEhighD E_abs and L_abs
    
    TCanvas* c3 = new TCanvas("c3", "", 0, 0, 800, 600); // lowErightD and highErightD E_abs
    c3->Divide(1,1);


    // Draw Eabs histogram in the pad 1 and Egap in the pad 2
    c1->cd(1);
    // Settings
    hist1->SetTitle("Edep in NaI calorimeter");    
    hist1->GetXaxis()->SetRangeUser(-0.5, 51);
    hist1->GetXaxis()->SetTitle("E [MeV]");
    hist1->GetYaxis()->SetTitle("counts");
    hist1->GetYaxis()->SetTitleOffset(1.4);
    hist1->SetLineColor(kRed);
    hist1->Draw(""); // Draws only errorbars
    hist1->Draw("HIST SAME"); //Draws only boxes. same to plot both
	//Draw Legend
	auto legend1 = new TLegend(0.6, 0.7, 0.9, 0.9); //x1,y1,x2,y2
//	legend1->SetHeader("The Legend Title","C"); // option "C" allows to center the header
	legend1->AddEntry(hist1, "3 cm thick absorber","f");
	legend1->Draw();
	
    c1->cd(2);    
    // Settings
    hist2->SetTitle("Edep in NaI calorimeter");    
    hist2->GetXaxis()->SetRangeUser(-0.04, 0.06);
    hist2->GetXaxis()->SetTitle("E [MeV]");
    hist2->GetYaxis()->SetTitle("counts");
    hist2->SetLineColor(kRed);
    hist2->Draw(""); // Draws only errorbars
    hist2->Draw("HIST SAME"); //Draws only boxes. same to plot both
	//Draw Legend
	auto legend2 = new TLegend(0.6, 0.7, 0.9, 0.9); //x1,y1,x2,y2
//	legend2->SetHeader("The Legend Title","C"); // option "C" allows to center the header
	legend2->AddEntry(hist2, "0 cm thick lAr gap","f");
	legend2->Draw();


    // Draw Eabs histogram in the pad 1 and Labs in the pad 2
    c2->cd(1);
    // Settings
    hist3->SetTitle("Edep in NaI calorimeter");    
    hist3->GetXaxis()->SetRangeUser(30.5, 51);
    hist3->GetXaxis()->SetTitle("E [MeV]");
    hist3->GetYaxis()->SetTitle("counts");
    hist3->GetYaxis()->SetTitleOffset(1.4);
    hist3->SetLineColor(kRed);
    hist3->Draw(""); // Draws only errorbars
    hist3->Draw("HIST SAME"); //Draws only boxes. same to plot both
	//Draw Legend
	auto legend3 = new TLegend(0.1, 0.7, 0.4, 0.9); //x1,y1,x2,y2
//	legend3->SetHeader("The Legend Title","C"); // option "C" allows to center the header
	legend3->AddEntry(hist3, "30 cm thick absorber","f");
	legend3->Draw();
	
    c2->cd(2);    
    // Settings
	hist4->SetTitle("Track length in NaI calorimeter");
    hist4->GetXaxis()->SetRangeUser(70.5, 111);
    hist4->GetXaxis()->SetTitle("Track Length [mm]");
    hist4->GetYaxis()->SetTitle("counts");
    hist4->GetYaxis()->SetTitleOffset(1.4);    
    hist4->SetLineColor(kGreen);
    hist4->Draw(""); // Draws only errorbars
    hist4->Draw("HIST SAME"); //Draws only boxes. same to plot both
	//Draw Legend
	auto legend4 = new TLegend(0.1, 0.7, 0.4, 0.9); //x1,y1,x2,y2
//	legend4->SetHeader("The Legend Title","C"); // option "C" allows to center the header
	legend4->AddEntry(hist4, "30 cm thick absorber","f");
	legend4->Draw();


    // Draw the two Eabs histograms in the same pad
    c3->cd(1);
    // Settings are fine for just one of them
    hist5->GetXaxis()->SetRangeUser(-0.5, 101);
    hist5->SetTitle("Edep in 10 cm thick NaI calorimeter");
    hist5->GetXaxis()->SetTitle("E [MeV]");
    hist5->GetYaxis()->SetTitle("counts");
    hist5->GetYaxis()->SetTitleOffset(1.4);
    hist5->SetLineColor(kRed);
    hist5->Draw(""); // Draws only errorbars
    hist5->Draw("HIST SAME"); //Draws only boxes. same to plot both
    hist6->SetLineColor(kBlue);
    hist6->Draw("SAME"); // Draws only errorbars
    hist6->Draw("HIST SAME"); //Draws only boxes. same to plot both
	//Draw Legend
	auto legend5 = new TLegend(0.6, 0.7, 0.9, 0.9); //x1,y1,x2,y2
//	legend5->SetHeader("The Legend Title","C"); // option "C" allows to center the header
	legend5->AddEntry(hist5, "50 MeV EM shower","f");
	legend5->AddEntry(hist6, "100 MeV EM shower","f");	
	legend5->Draw();

/*   
    THStack hs("hs","test stacked histograms");
    hist1->SetFillColor(kRed);
    hs.Add(hist1);
    hist3->SetFillColor(kBlue);
    hs.Add(hist3);

    TCanvas c2("c2","stacked hists",10,10,700,900);
    c2.cd(1);
    hs.Draw();
    hs->Draw("nostack");
*/

}
