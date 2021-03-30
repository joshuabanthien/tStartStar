#include "UHH2/tStartStar/include/genHists.h"
#include "UHH2/core/include/Event.h"
#include <UHH2/common/include/TTbarGen.h>
#include "UHH2/tStartStar/include/recoHists.h"


#include "TH1F.h"
#include "TH2F.h"
#include <iostream>

using namespace std;
using namespace uhh2;
using namespace uhh2examples;

genHists::genHists(Context & ctx, const string & dirname): Hists(ctx, dirname){
  // book all histograms here

  h_ttbargen = ctx.get_handle<TTbarGen>("ttbargen");
  // gamma
  book<TH1F>("N_gamma", "N_{#gamma} gen", 20, 0, 500);
  book<TH1F>("pt_gamma", "p_{T}^{#gamma} [GeV/c] gen", 40, 0, 500);
  book<TH1F>("eta_gamma", "#eta^{#gamma} gen", 40, -4, 4);
  book<TH1F>("phi_gamma", "#phi^{#gamma} gen", 40, -4, 4);

  book<TH1F>("deltaR_genTstarGamma_leadingGamma", "#Delta R genTstarGamma, leading Gamma", 14, 0, 7);
  book<TH1F>("deltaR_genTstarGamma_2ndleadingGamma", "#Delta R genTstarGamma, 2nd to leading Gamma", 14, 0, 7);
  book<TH1F>("deltaR_genTstarGamma_3rdleadingGamma", "#Delta R genTstarGamma, 3rd to leading Gamma", 14, 0, 7);

  book<TH1F>("deltaR_matchedleadingGamma_genTstarGamma", "#Delta R genTstarGamma, matched leading Gamma", 14, 0, 7);
  book<TH1F>("min_deltaR_electrons_matchedleadingGamma", "min #Delta R electrons matched leading Gamma", 14, 0, 7);

  book<TH1F>("pt_matchedGamma", "p_{T}^{#gamma} matched [GeV/c]", 40, 0, 500);
  book<TH1F>("eta_matchedGamma", "#eta^{#gamma} matched", 40, -4, 4);
  book<TH1F>("phi_matchedGamma", "#phi^{#gamma} matched", 40, -4, 4);

  book<TH1F>("N_matchedGammaCandidates", "N_{matchedGammaCandidates}", 20, 0, 20);

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



  book<TH1F>("deltaR_genE_recoE", "deltaR_genE_recoE", 30, 0, 6);
  book<TH1F>("deltaR_genG_recoG", "deltaR_genG_recoG", 30, 0, 6);


  is_mc = ctx.get("dataset_type") == "MC";

}


void genHists::fill(const Event & event){
  // fill the histograms. Please note the comments in the header file:
  // 'hist' is used here a lot for simplicity, but it will be rather low when you have many histograms; therefore, better
  // use histogram pointers as members as in 'UHH2/common/include/ElectronHists.h'

  // Don't forget to always use the weight when filling.
  if(!is_mc) return;
  TTbarGen ttbargen = event.get(h_ttbargen);

  double weight = event.weight;

  std::vector<GenParticle> GenParticles = *event.genparticles;
  std::vector<GenParticle> GenPhotons;
  std::vector<GenParticle> GenMuons;
  std::vector<GenParticle> GenElectrons;
  std::vector<Photon> Photons = *event.photons;
  std::vector<Photon> matchedPhotonCandidates;
  GenParticle genTstarGamma;
  Photon leadingGamma;
  Photon secondleadingGamma;
  Photon thirdleadingGamma;
  Photon matchedleadingGamma;


  for(const GenParticle & thisgenparticle : GenParticles){
    if(thisgenparticle.pdgId() == 22 && thisgenparticle.status()==1){
      GenPhotons.push_back(thisgenparticle);
    //  if(GenParticles.at(thisgenparticle.mother1()).pdgId() == 9000005 or GenParticles.at(thisgenparticle.mother1()).pdgId() == -9000005 ){ genTstarGamma = thisgenparticle ;}
      if(thisgenparticle.mother1() == ttbargen.Top().mother1() || thisgenparticle.mother1() == ttbargen.Antitop().mother1() ){ genTstarGamma = thisgenparticle ;}
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

  if(ttbargen.IsSemiLeptonicDecay()){

    double min_deltaR_genErecoE = 1000;

    for (const Electron & thise : *event.electrons){
        double calc_deltaR = deltaR(thise, ttbargen.ChargedLepton());
        if(calc_deltaR < min_deltaR_genErecoE) min_deltaR_genErecoE = calc_deltaR;
    }

    hist("deltaR_genE_recoE")->Fill(min_deltaR_genErecoE, weight);


    if (Photons.size()>0){


      if(ttbargen.ChargedLepton().pdgId()==11 || ttbargen.ChargedLepton().pdgId()==-11){

        for(const Photon & thisgamma : *event.photons){

          double min_deltaR_thisgamma_electrons = 1000;
          for (const Electron & thise : *event.electrons){
              double calc_deltaR = deltaR(thise, thisgamma);
              if(calc_deltaR < min_deltaR_thisgamma_electrons) min_deltaR_thisgamma_electrons = calc_deltaR;
          }

          if(min_deltaR_thisgamma_electrons > 0.1){
            matchedPhotonCandidates.push_back(thisgamma);
          }

        }

      hist("N_matchedGammaCandidates")->Fill(matchedPhotonCandidates.size(), weight);

      if(matchedPhotonCandidates.size()>0){
        matchedleadingGamma = matchedPhotonCandidates.at(0);
        double deltaR_matchedleadingGamma_genTstarGamma = deltaR(matchedleadingGamma, genTstarGamma);
        hist("pt_matchedGamma")->Fill(matchedleadingGamma.pt(), weight);
        hist("eta_matchedGamma")->Fill(matchedleadingGamma.eta(), weight);
        hist("phi_matchedGamma")->Fill(matchedleadingGamma.phi(), weight);
        hist("deltaR_matchedleadingGamma_genTstarGamma")->Fill(deltaR_matchedleadingGamma_genTstarGamma, weight);
      }

      }

    //  if(ttbargen.ChargedLepton().pdgId()==13){

    //  }


    }

  }

  double min_deltaR_genGrecoG = 1000;

  for (const Photon & thisgamma : *event.photons){
      double calc_deltaR = deltaR(thisgamma, genTstarGamma);
      if(calc_deltaR < min_deltaR_genGrecoG) min_deltaR_genGrecoG = calc_deltaR;
  }

  hist("deltaR_genG_recoG")->Fill(min_deltaR_genGrecoG, weight);






}

genHists::~genHists(){}
