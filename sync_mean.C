//Plotting the Threshold vs. mean


{

  //SET POINTS:
  Int_t Num_points = 16;
  Int_t Start = 100;

  double int x1[Num_points];
  double int dx1[Num_points];
  double int y1[Num_points];
  double int dy1[Num_points];


   TCanvas *c1 = new TCanvas("c1","Untuned Mean vs. SyncVth",200,40,700,500);
   c1->SetGrid();

   // create the multigraph
   TMultiGraph *mg = new TMultiGraph();
   mg->SetTitle("Untuned Mean vs. SyncVth");


  ifstream myfile ("example.txt");

  float mean_v_fit, mean_e_fit, std_m_fit, std_e_fit, mean_v, mean_e, std_m, std_e, mvp;

   if (myfile.is_open()){
     for (int i; i < Num_points; i++){
        x1[i] = (Start + i*50);
       dx1[i] = 0.1;
       myfile >> mean_v_fit >> mean_e_fit >> std_m_fit >> std_e_fit >> mean_v >> mean_e >> std_m >> std_e >> mvp;
        y1[i] = mean_v;
        dy1[i] = mean_e;
     }
   myfile.close();
   }

   // create the 1st TGraph
   gr1 = new TGraphErrors(Num_points,x1,y1,dx1,dy1);
   gr1->SetMarkerStyle(21);
   gr1->SetMarkerColor(3);
   gr1->SetLineColor(1);
   gr1->SetLineWidth(2);
   gr1->SetFillStyle(0);
   gr1->SetTitle("Linear fit");


   // put the graphs in the multigraph
   mg->Add(gr1);

   // draw the multigraph
   mg->Draw("AP");
   mg->GetXaxis()->SetTitle("SyncVth [DAC]");
   mg->GetXaxis()->SetLabelSize(0.05);
   mg->GetXaxis()->SetTitleSize(0.05);
   mg->GetXaxis()->SetTitleOffset(1);
   mg->GetXaxis()->SetLabelFont(42);
   mg->GetXaxis()->CenterTitle();

   mg->GetYaxis()->SetTitle("Threshold Mean [e] ");
   mg->GetYaxis()->SetLabelSize(0.05);
   mg->GetYaxis()->SetTitleSize(0.05);
   mg->GetYaxis()->SetTitleOffset(1);
   mg->GetYaxis()->SetLabelFont(42);
   mg->GetYaxis()->CenterTitle();
   gStyle->SetOptFit(0001);

      lin = new TF1("lin","[0] + [1]*x",50,890);
      lin->SetParameters(900,26);
      gr1->Fit(lin,"","",50,890);
      lin->SetParNames("p0","p1");

      c1->BuildLegend();


   return c1;
}
