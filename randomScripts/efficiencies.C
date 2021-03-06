// Efficiency histograms for trigger related studies
// author: F.Labe
// date: 24.09.2019
// Run it with following command:
// root -l -b -q cutflowPlots.C

void efficiencies(TString suffix = ""){

  gStyle->SetOptFit(0);
  gStyle->SetOptStat(0);
  gStyle->SetTitleSize(0.06,"x");
  gStyle->SetTitleSize(0.06,"y");
  gStyle->SetLabelSize(0.05,"x");
  gStyle->SetLabelSize(0.05,"y");
  gStyle->SetLabelSize(0.05,"z");
  gStyle->SetTitleYOffset(1.20);
  gStyle->SetTitleXOffset(1.0);
  gStyle->SetPalette(55);

  gStyle->SetPadTopMargin(0.1);
  gStyle->SetPadBottomMargin(0.13);
  gStyle->SetPadLeftMargin(0.18);
  gStyle->SetPadRightMargin(0.17);

  gROOT->ForceStyle();
  Double_t w = 800;
  Double_t h = 600;

  // Reuseable buffers
  TFile *input;
  TH1D *hist;

  // Drawing Definitions
  TCanvas *canvas = new TCanvas("chist", "c", w, h);
  //TLegend *leg = new TLegend(0.22,0.175,0.5,0.33);
  TLegend *leg = new TLegend(0.25,0.21,0.625,0.335);
  canvas->SetLogy();
  leg->SetNColumns(2);

  // Defining paths
  TString pathPresel = "/nfs/dust/cms/user/banthiey/tStartStarV3/Output/DataAndMonteCarlo/";
  TString pathSel = "";
  TString pathReco = "";
  TString fileprefix = "uhh2.AnalysisModuleRunner.MC.";
  TString histname = "N_jets";

  // Defining Steps
  std::vector<TString> preselSteps = {"recoTriggers", "recolepsel", "recophosel", "recojetsel", "recobTag"};
  std::vector<TString> selSteps = {};
  std::vector<TString> recoSteps = {};
  int stepcount = preselSteps.size() + selSteps.size() + recoSteps.size();

  // Adding suffix
  int is_first = true;
  for (auto & step : preselSteps){
    if(is_first) is_first = false;
    else step.Append(suffix);
  }
  for (auto & step : selSteps){
    step.Append(suffix);
  }
  for (auto & step : recoSteps){
    step.Append(suffix);
  }


  // Defining Samples
  std::vector<TString> signalSamples = {"TstarTstarToTgluonTgamma_M-1100_Run2016v3.root", "TstarTstarToTgluonTgamma_M-800_Run2016v3.root"};
  std::vector<TString> BGSamples = {"TTJets.root", "ST.root", "WJets.root", "VV.root", "QCD.root", "DYJets.root"};
  //std::vector<TString> BGSamples = {};

  std::vector<TString> signal_labels = {"Tstar M-1100", "Tstar M-700"};
  std::vector<TString> BG_labels = {"TTJets", "ST", "WJets", "VV", "QCD", "DY"};

  // Defining Drawing options
  std::vector<int> colors_Signal = {1, 1};
  std::vector<int> line_Signal = {2, 3};
  std::vector<int> colors_BG = {810, 800, 600, 416, 867, 880};
  std::vector<TString> labels = {"Lepton Trigger", "Lepton Selection", "Photon Selection", "Jet Selection", "btagginess Selection", "should not be visible"};

  // ########################
  // ## Finish Definitions ##
  // ########################

  // Saving initial values
  std::vector<double> initial_signal;
  std::vector<double> initial_BG;
  double initial_BG_sum = 0;
  for(const auto & sample : signalSamples){
    input = TFile::Open(pathPresel+fileprefix+sample);
    hist = (TH1D*)input->Get(preselSteps.at(0)+"/"+histname);
    initial_signal.push_back(hist->Integral());
  }
  for(const auto & sample : BGSamples){
    input = TFile::Open(pathPresel+fileprefix+sample);
    hist = (TH1D*)input->Get(preselSteps.at(0)+"/"+histname);
    initial_BG.push_back(hist->Integral());
    initial_BG_sum += hist->Integral();
  }
  // if no presel is present:
  /**
  for(const auto & sample : signalSamples){
    input = TFile::Open(pathSel+fileprefix+sample);
    hist = (TH1D*)input->Get(selSteps.at(0)+"/"+histname);
    initial_signal.push_back(hist->Integral());
  }
  for(const auto & sample : BGSamples){
    input = TFile::Open(pathSel+fileprefix+sample);
    hist = (TH1D*)input->Get(selSteps.at(0)+"/"+histname);
    initial_BG.push_back(hist->Integral());
    initial_BG_sum += hist->Integral();
  }
  **/

  // Defining Hists
  std::vector<TH1*> cutflow_Signal;
  std::vector<TH1*> cutflow_BG;
  for(const auto & sample : signalSamples){cutflow_Signal.push_back(new TH1D(sample, sample, stepcount, 0, stepcount));}    // TODO remove ".root" in the end
  for(const auto & sample : BGSamples){cutflow_BG.push_back(new TH1D(sample, sample, stepcount, 0, stepcount));}

  // Filling hists
  int index_step = 1;

  // Preselection
  std::cout << "Start preselSteps." << endl;
  for(const auto & step : preselSteps){
    std::cout << "Start preselStep: " << step << endl;
    int index_sample = 0;
    for(const auto & sample : signalSamples){
      input = TFile::Open(pathPresel+fileprefix+sample);
      hist = (TH1D*)input->Get(step+"/"+histname);
      double val = hist->Integral();
      cutflow_Signal.at(index_sample)->SetBinContent(index_step, val/initial_signal.at(index_sample));
      index_sample++;
    }
    index_sample = 0;
    for(const auto & sample : BGSamples){
      input = TFile::Open(pathPresel+fileprefix+sample);
      hist = (TH1D*)input->Get(step+"/"+histname);
      double val = hist->Integral();
      cutflow_BG.at(index_sample)->SetBinContent(index_step, val/initial_BG.at(index_sample));
      index_sample++;
    }
    index_step++;
  }

  // Selection
  std::cout << "Start selSteps." << endl;
  for(const auto & step : selSteps){
    std::cout << "Start selStep: " << step << endl;
    int index_sample = 0;
    for(const auto & sample : signalSamples){
      input = TFile::Open(pathSel+fileprefix+sample);
      hist = (TH1D*)input->Get(step+"/"+histname);
      double val = hist->Integral();
      cutflow_Signal.at(index_sample)->SetBinContent(index_step, val/initial_signal.at(index_sample));
      index_sample++;
    }
    index_sample = 0;
    for(const auto & sample : BGSamples){
      input = TFile::Open(pathSel+fileprefix+sample);
      hist = (TH1D*)input->Get(step+"/"+histname);
      double val = hist->Integral();
      cutflow_BG.at(index_sample)->SetBinContent(index_step, val/initial_BG.at(index_sample));
      index_sample++;
    }
    index_step++;
  }

  // Reconstruction
  std::cout << "Start recoSteps." << endl;
  for(const auto & step : recoSteps){
    std::cout << "Start recoStep: " << step << endl;
    int index_sample = 0;
    for(const auto & sample : signalSamples){
      input = TFile::Open(pathReco+fileprefix+sample);
      hist = (TH1D*)input->Get(step+"/"+histname);
      double val = hist->Integral();
      cutflow_Signal.at(index_sample)->SetBinContent(index_step, val/initial_signal.at(index_sample));
      index_sample++;
    }
    index_sample = 0;
    for(const auto & sample : BGSamples){
      input = TFile::Open(pathReco+fileprefix+sample);
      hist = (TH1D*)input->Get(step+"/"+histname);
      double val = hist->Integral();
      cutflow_BG.at(index_sample)->SetBinContent(index_step, val/initial_BG.at(index_sample));
      index_sample++;
    }
    index_step++;
  }

  // ##########################
  // ## Finish Filling Hists ##
  // ##########################

  std::cout << "drawing BG" << endl;

  // drawing BG
  int index_draw_BG = 0;
  for(const auto & hist : cutflow_BG){
    int index_label = 1;
    for(const auto & label : labels) {hist->GetXaxis()->SetBinLabel(index_label, label); index_label++;}
    hist->SetLineWidth(3);
    hist->SetTitle("");
    hist->SetLineColor(colors_BG.at(index_draw_BG));
    hist->GetYaxis()->SetTitle("Efficiency");
    if(index_draw_BG == 0){
      hist->SetMinimum(1e-7);
      hist->Draw();
    }
    else hist->Draw("same");
    leg->AddEntry(hist, BG_labels.at(index_draw_BG), "l");
    index_draw_BG++;
  }

  std::cout << "Drawing signal" << endl;

  // drawing signal
  int index_draw_signal = 0;

  for(const auto & hist : cutflow_Signal){
    int index_label = 1;
    for(const auto & label : labels) {hist->GetXaxis()->SetBinLabel(index_label, label); index_label++;}
    hist->SetLineWidth(3);
    hist->SetTitle("");
    hist->SetLineColor(colors_Signal.at(index_draw_signal)); // This can be improved by use of iterator
    hist->SetLineStyle(line_Signal.at(index_draw_signal)); // This can be improved by use of iterator
    hist->GetYaxis()->SetTitle("Efficiency");
    hist->Draw("same");
    leg->AddEntry(hist, signal_labels.at(index_draw_signal), "l");
    index_draw_signal++;
  }

  // Draw legend
  leg->SetBorderSize(0);
  leg->Draw("same");

  // draw Lumi text
  TString infotext = TString::Format("35.9 fb^{-1} (13 TeV)");
  TLatex *text = new TLatex(3.5, 24, infotext);
  text->SetNDC();
  text->SetTextAlign(33);
  text->SetX(0.83);
  text->SetTextFont(42);
  text->SetY(0.935);
  text->SetTextSize(0.0325);
  text->Draw();

  // Draw line after certain bin to split presel, sel,
  bool doLine = false;
  if(doLine){
    double pos1 = cutflow_BG.at(0)->GetBinLowEdge(1+preselSteps.size());
    TLine *line1 = new TLine(pos1,1.25,pos1,1.9);
    //line1->Draw("same");
    double pos2 = cutflow_BG.at(0)->GetBinLowEdge(1+preselSteps.size()+selSteps.size());
    TLine *line2 = new TLine(pos2,1.25,pos2,1.8);
    line2->Draw("same");
  }
  canvas->SaveAs("Cutflow"+suffix+".pdf");

  int index_sample = 0;
  for(const auto & sample : signalSamples){
    double pre_ttag = cutflow_Signal.at(index_sample)->GetBinContent(0);
    double post_ttag = cutflow_Signal.at(index_sample)->GetBinContent(3);
    cout << "For " << sample << " the efficiency is " << post_ttag/pre_ttag << endl;
    index_sample++;
  }

}
