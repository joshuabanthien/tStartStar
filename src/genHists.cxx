#include "UHH2/tStartStar/include/genHists.h"
#include "UHH2/core/include/Event.h"

#include "TH1F.h"
#include "TH2F.h"
#include <iostream>

using namespace std;
using namespace uhh2;
using namespace uhh2examples;

genHists::genHists(Context & ctx, const string & dirname): Hists(ctx, dirname){
  // book all histograms here


  // gamma
  book<TH1F>("N_gamma", "N_{#gamma} gen", 20, 0, 20);
  book<TH1F>("pt_gamma", "p_{T}^{#gamma} [GeV/c] gen", 40, 0, 500);
  book<TH1F>("eta_gamma", "#eta^{#gamma} gen", 40, -4, 4);
  book<TH1F>("phi_gamma", "#phi^{#gamma} gen", 40, -4, 4);

  // mu
  book<TH1F>("N_mu", "N_{#mu} gen", 20, 0, 20);
  book<TH1F>("pt_mu", "p_{T}^{#mu} [GeV/c] gen", 40, 0, 500);
  book<TH1F>("eta_mu", "#eta^{#mu} gen", 40, -4, 4);
  book<TH1F>("phi_mu", "#phi^{#mu} gen", 40, -4, 4);

  // electrons
  book<TH1F>("N_e", "N_{e} gen", 20, 0, 20);
  book<TH1F>("pt_e", "p_{T}^{e} [GeV/c] gen", 40, 0, 500);
  book<TH1F>("eta_e", "#eta^{e} gen", 40, -4, 4);
  book<TH1F>("phi_e", "#phi^{e} gen", 40, -4, 4);

}


void genHists::fill(const Event & event){
  // fill the histograms. Please note the comments in the header file:
  // 'hist' is used here a lot for simplicity, but it will be rather low when you have many histograms; therefore, better
  // use histogram pointers as members as in 'UHH2/common/include/ElectronHists.h'

  // Don't forget to always use the weight when filling.
  double weight = event.weight;

  std::vector<GenParticle> GenParticles = *event.genparticles;
  std::vector<GenParticle> GenPhotons;
  std::vector<GenParticle> GenMuons;
  std::vector<GenParticle> GenElectrons;

  for(const GenParticle & thisgenparticle : GenParticles){
    if(thisgenparticle.pdgId() == 22 && thisgenparticle.status()==1){
      GenPhotons.push_back(thisgenparticle);
    }
  }

  for(const GenParticle & thisgenparticle : GenParticles){
    if(thisgenparticle.pdgId() == 13 && thisgenparticle.status()==1){
      GenMuons.push_back(thisgenparticle);
    }
  }

  for(const GenParticle & thisgenparticle : GenParticles){
    if(thisgenparticle.pdgId() == 11 && thisgenparticle.status()==1){
      GenElectrons.push_back(thisgenparticle);
    }
  }

  int Ngenphotons = GenPhotons.size();
  hist("N_gamma")->Fill(Ngenphotons, weight);
  for (const GenParticle & thisgamma : GenPhotons){
      hist("pt_gamma")->Fill(thisgamma.pt(), weight);
      hist("eta_gamma")->Fill(thisgamma.eta(), weight);
      hist("phi_gamma")->Fill(thisgamma.phi(), weight);
  }

  int Ngenmuons = GenMuons.size();
  hist("N_mu")->Fill(Ngenmuons, weight);
  for (const GenParticle & thismu : GenMuons){
      hist("pt_mu")->Fill(thismu.pt(), weight);
      hist("eta_mu")->Fill(thismu.eta(), weight);
      hist("phi_mu")->Fill(thismu.phi(), weight);
  }

  int Ngenelectrons = GenElectrons.size();
  hist("N_e")->Fill(Ngenelectrons, weight);
  for (const GenParticle & thise : GenElectrons){
      hist("pt_e")->Fill(thise.pt(), weight);
      hist("eta_e")->Fill(thise.eta(), weight);
      hist("phi_e")->Fill(thise.phi(), weight);
  }

}

genHists::~genHists(){}
