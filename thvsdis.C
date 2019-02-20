//Plotting Threshold vs. Global DAC units
{

   TCanvas *c1 = new TCanvas("c1","Untuned threshold vs Dispersion",200,40,700,500);
   c1->SetGrid();

   // Creating multigraph
   TMultiGraph *mg = new TMultiGraph();
   mg->SetTitle("Untuned Threshold Dispersion vs. VTH1");

   //Create the points and error
   const Int_t n = 8;
   Double_t x1[] = {200,300,400,500,600,650,700,750};
   Double_t dx1[] = {0.1,0.1,0.1,0.1,0.1,0.1,0.1,0.1};
   Double_t y1[] = {359.5, 341, 357.6, 400, 511, 637.9, 1035, 1223};
   Double_t dy1[] = {4.1, 4.2, 4.6,5.6,7.6,11.5,16,21.8};

   //Adding the points to a graph
   gr1 = new TGraphErrors(n,x1,y1,dx1,dy1);
   gr1->SetMarkerStyle(21);
   gr1->SetMarkerColor(3);
   gr1->SetLineColor(1);
   gr1->SetLineWidth(2);
   gr1->SetFillStyle(0);

   //Putting the graph into multigraph
   mg->Add(gr1);

   // Draw the multigraph and set outlook
   mg->Draw("AP");
   mg->GetXaxis()->SetTitle("VTH1 [DAC]");
   mg->GetXaxis()->SetLabelSize(0.05);
   mg->GetXaxis()->SetTitleSize(0.05);
   mg->GetXaxis()->SetTitleOffset(1);
   mg->GetXaxis()->SetLabelFont(42);
   mg->GetXaxis()->CenterTitle();

   mg->GetYaxis()->SetTitle("Dispersion [e] ");
   mg->GetYaxis()->SetLabelSize(0.05);
   mg->GetYaxis()->SetTitleSize(0.05);
   mg->GetYaxis()->SetTitleOffset(1);
   mg->GetYaxis()->SetLabelFont(42);
   mg->GetYaxis()->CenterTitle();
   gStyle->SetOptFit(0001);

   //Creating the fit function
   f = new TF1("f","[0] + [1]*x^3 - [2]*x^2 ",200,700);
   f->SetParNames("quad","u");
   mg->Fit(f);

   return c1;
}
