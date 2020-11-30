#include "UHH2/tStartStar/include/recoHists.h"
#include "UHH2/core/include/Event.h"

#include "TH1F.h"
#include "TH2F.h"
#include <iostream>

using namespace std;
using namespace uhh2;
using namespace uhh2examples;

recoHists::recoHists(Context & ctx, const string & dirname): Hists(ctx, dirname){
  // book all histograms here

  // jets
  book<TH1F>("N_jets", "N_{jets} reco", 20, 0, 20);
  book<TH1F>("HT_jets", "HT_{jets} reco", 40, 0, 12000);
  book<TH1F>("pt_jet1", "p_{T}^{jet1} [GeV/c] reco", 40, 0, 6000);
  book<TH1F>("eta_jet1", "#eta^{jet1} reco", 40, -4, 4);
  book<TH1F>("phi_jet1", "#phi^{jet1} reco", 40, -4, 4);
  book<TH1F>("pt_jet2", "p_{T}^{jet2} [GeV/c] reco", 40, 0, 4500);
  book<TH1F>("eta_jet2", "#eta^{jet2} reco", 40, -4, 4);
  book<TH1F>("phi_jet2", "#phi^{jet2} reco", 40, -4, 4);
  book<TH1F>("pt_jet3", "p_{T}^{jet3} [GeV/c] reco", 40, 0, 2500);
  book<TH1F>("eta_jet3", "#eta^{jet3} reco", 40, -4, 4);
  book<TH1F>("phi_jet3", "#phi^{jet3} reco", 40, -4, 4);

  // gamma
  book<TH1F>("N_gamma", "N_{#gamma} reco", 20, 0, 20);
  book<TH1F>("pt_gamma", "p_{T}^{#gamma} [GeV/c] reco", 40, 0, 4000);
  book<TH1F>("eta_gamma", "#eta^{#gamma} reco", 40, -4, 4);
  book<TH1F>("phi_gamma", "#phi^{#gamma} reco", 40, -4, 4);

  // mu
  book<TH1F>("N_mu", "N_{#mu} reco", 20, 0, 20);
  book<TH1F>("pt_mu", "p_{T}^{#mu} [GeV/c] reco", 40, 0, 2500);
  book<TH1F>("eta_mu", "#eta^{#mu} reco", 40, -4, 4);
  book<TH1F>("phi_mu", "#phi^{#mu} reco", 40, -4, 4);

  // electrons
  book<TH1F>("N_e", "N_{e} reco", 20, 0, 20);
  book<TH1F>("pt_e", "p_{T}^{e} [GeV/c] reco", 40, 0, 4000);
  book<TH1F>("eta_e", "#eta^{e} reco", 40, -4, 4);
  book<TH1F>("phi_e", "#phi^{e} reco", 40, -4, 4);

}


void recoHists::fill(const Event & event){
  // fill the histograms. Please note the comments in the header file:
  // 'hist' is used here a lot for simplicity, but it will be rather
  // slow when you have many histograms; therefore, better
  // use histogram pointers as members as in 'UHH2/common/include/ElectronHists.h'

  // Don't forget to always use the weight when filling.
  double weight = event.weight;

  std::vector<Jet>* jets = event.jets;

  int Njets = event.jets->size();
  hist("N_jets")->Fill(Njets, weight);

  if( Njets >= 1){
    hist("pt_jet1")->Fill(jets->at(0).pt(), weight);
    hist("eta_jet1")->Fill(jets->at(0).eta(), weight);
    hist("phi_jet1")->Fill(jets->at(0).phi(), weight);
  }

  if( Njets >= 2){
    hist("pt_jet2")->Fill(jets->at(1).pt(), weight);
    hist("eta_jet2")->Fill(jets->at(1).eta(), weight);
    hist("phi_jet2")->Fill(jets->at(1).phi(), weight);
  }

  if( Njets >= 3){
    hist("pt_jet3")->Fill(jets->at(2).pt(), weight);
    hist("eta_jet3")->Fill(jets->at(2).eta(), weight);
    hist("phi_jet3")->Fill(jets->at(2).phi(), weight);
  }


  int Nphotons = event.photons->size();
  hist("N_gamma")->Fill(Nphotons, weight);
  for (const Photon & thisgamma : *event.photons){
      hist("pt_gamma")->Fill(thisgamma.pt(), weight);
      hist("eta_gamma")->Fill(thisgamma.eta(), weight);
      hist("phi_gamma")->Fill(thisgamma.phi(), weight);
  }


  int Nmuons = event.muons->size();
  hist("N_mu")->Fill(Nmuons, weight);
  for (const Muon & thismu : *event.muons){
      hist("pt_mu")->Fill(thismu.pt(), weight);
      hist("eta_mu")->Fill(thismu.eta(), weight);
      hist("phi_mu")->Fill(thismu.phi(), weight);
  }


  int Nelectrons = event.electrons->size();
  hist("N_e")->Fill(Nelectrons, weight);
  for (const Electron & thise : *event.electrons){
      hist("pt_e")->Fill(thise.pt(), weight);
      hist("eta_e")->Fill(thise.eta(), weight);
      hist("phi_e")->Fill(thise.phi(), weight);
  }


  double ht_jets = 0;
  for (const Jet & thisjet : *event.jets){
    ht_jets = ht_jets + thisjet.pt();
  }
  hist("HT_jets")->Fill(ht_jets, weight);


}

recoHists::~recoHists(){}
