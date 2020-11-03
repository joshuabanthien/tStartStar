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
  // jets
  book<TH1F>("N_gamma", "N_{#gamma} gen", 20, 0, 20);
  book<TH1F>("pt_gamma", "p_{T}^{#gamma} [GeV/c] gen", 40, 0, 200);
  book<TH1F>("eta_gamma", "#eta^{#gamma} gen", 40, -2.1, 2.1);




}


void genHists::fill(const Event & event){
  // fill the histograms. Please note the comments in the header file:
  // 'hist' is used here a lot for simplicity, but it will be rather
  // slow when you have many histograms; therefore, better
  // use histogram pointers as members as in 'UHH2/common/include/ElectronHists.h'

  // Don't forget to always use the weight when filling.
  double weight = event.weight;

  std::vector<GenParticle> GenParticles = *event.genparticles;
  std::vector<GenParticle> GenPhotons;

  for(const GenParticle & thisgenparticle : GenParticles){
    if(thisgenparticle.pdgId() == 22 && thisgenparticle.status()==23){
      GenPhotons.push_back(thisgenparticle);
    }
  }

  int Ngenphotons = GenPhotons.size();
  hist("N_gamma")->Fill(Ngenphotons, weight);
  for (const GenParticle & thisgamma : GenPhotons){
      hist("pt_gamma")->Fill(thisgamma.pt(), weight);
      hist("eta_gamma")->Fill(thisgamma.eta(), weight);
  }


}

genHists::~genHists(){}
