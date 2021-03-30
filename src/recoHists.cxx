#include "UHH2/tStartStar/include/recoHists.h"
#include "UHH2/core/include/Event.h"
#include "UHH2/common/include/TTbarGen.h"

#include "TH1F.h"
#include "TH2F.h"
#include <iostream>

using namespace std;
using namespace uhh2;
using namespace uhh2examples;

recoHists::recoHists(Context & ctx, const string & dirname): Hists(ctx, dirname){
  // book all histograms here
  h_ttbargen = ctx.get_handle<TTbarGen>("ttbargen");
  // jets
  book<TH1F>("N_jets", "N_{jets} reco", 20, 0, 20);
  book<TH1F>("HT_jets", "HT_{jets} reco", 40, 0, 5000);
  book<TH1F>("N_topjets", "N_{topjets} reco", 20, 0, 20);
  book<TH1F>("pt_topjet1", "p_{T}^{topjet1} [GeV/c] reco", 40, 0, 6000);
  book<TH1F>("eta_topjet1", "#eta^{topjet1} reco", 40, -4, 4);
  book<TH1F>("phi_topjet1", "#phi^{topjet1} reco", 40, -4, 4);
  book<TH1F>("pt_topjet2", "p_{T}^{topjet2} [GeV/c] reco", 40, 0, 6000);
  book<TH1F>("eta_topjet2", "#eta^{topjet2} reco", 40, -4, 4);
  book<TH1F>("phi_topjet2", "#phi^{topjet2} reco", 40, -4, 4);
  book<TH1F>("pt_jet1", "p_{T}^{jet1} [GeV/c] reco", 40, 0, 6000);
  book<TH1F>("eta_jet1", "#eta^{jet1} reco", 40, -4, 4);
  book<TH1F>("phi_jet1", "#phi^{jet1} reco", 40, -4, 4);
  book<TH1F>("pt_jet2", "p_{T}^{jet2} [GeV/c] reco", 40, 0, 4500);
  book<TH1F>("eta_jet2", "#eta^{jet2} reco", 40, -4, 4);
  book<TH1F>("phi_jet2", "#phi^{jet2} reco", 40, -4, 4);
  book<TH1F>("pt_jet3", "p_{T}^{jet3} [GeV/c] reco", 40, 0, 2500);
  book<TH1F>("eta_jet3", "#eta^{jet3} reco", 40, -4, 4);
  book<TH1F>("phi_jet3", "#phi^{jet3} reco", 40, -4, 4);
  book<TH1F>("N_jets_looseBtag", "loose btag N_{jets} reco", 20, 0, 20);
  book<TH1F>("N_jets_mediumBtag", "medium btag N_{jets} reco", 20, 0, 20);
  book<TH1F>("N_jets_tightBtag", "tight btag N_{jets} reco", 20, 0, 20);


  // gamma
  book<TH1F>("N_gamma", "N_{#gamma} reco", 20, 0, 20);
  book<TH1F>("pt_gamma", "p_{T}^{#gamma} [GeV/c] reco", 40, 0, 4000);
  book<TH1F>("eta_gamma", "#eta^{#gamma} reco", 40, -4, 4);
  book<TH1F>("phi_gamma", "#phi^{#gamma} reco", 40, -4, 4);
  book<TH1F>("gamma puppiChargedHadronIso", "#gamma puppiChargedHadronIso", 40, 0, 40);
  book<TH1F>("gamma puppiNeutralHadronIso", "#gamma puppiNeutralHadronIso", 40, 0, 40);
  book<TH1F>("gamma puppiPhotonIso", "#gamma puppiPhotonIso", 40, 0, 40);
  book<TH1F>("gamma trackIso", "#gamma trackIso", 40, 0, 40);
  book<TH1F>("gamma ecalIso", "#gamma ecalIso", 40, 0, 40);
  book<TH1F>("gamma hcalIso", "#gamma hcalIso", 40, 0, 40);
  book<TH1F>("gamma caloIso", "#gamma caloIso", 40, 0, 40);
  book<TH1F>("gamma patParticleIso", "#gamma patParticleIso", 40, 0, 40);
  book<TH1F>("gamma chargedHadronIso", "#gamma chargedHadronIso", 40, 0, 40);
  book<TH1F>("gamma neutralHadronIso", "#gamma neutralHadronIso", 40, 0, 40);
  book<TH1F>("gamma photonIso", "#gamma photonIso", 40, 0, 40);
  book<TH1F>("gamma puChargedHadronIso", "#gamma puChargedHadronIso", 40, 0, 40);

  book<TH1F>("N_gamma_real", "N_{#gamma} reco real", 20, 0, 20);
  book<TH1F>("pt_gamma_real", "p_{T}^{#gamma} [GeV/c] reco real", 40, 0, 4000);
  book<TH1F>("eta_gamma_real", "#eta^{#gamma} reco real", 40, -4, 4);
  book<TH1F>("phi_gamma_real", "#phi^{#gamma} reco real", 40, -4, 4);
  book<TH1F>("real gamma puppiChargedHadronIso", "real #gamma puppiChargedHadronIso", 40, 0, 40);
  book<TH1F>("real gamma puppiNeutralHadronIso", "real #gamma puppiNeutralHadronIso", 40, 0, 40);
  book<TH1F>("real gamma puppiPhotonIso", "real #gamma puppiPhotonIso", 40, 0, 40);
  book<TH1F>("real gamma trackIso", "real #gamma trackIso", 40, 0, 40);
  book<TH1F>("real gamma ecalIso", "real #gamma ecalIso", 40, 0, 40);
  book<TH1F>("real gamma hcalIso", "real #gamma hcalIso", 40, 0, 40);
  book<TH1F>("real gamma caloIso", "real #gamma caloIso", 40, 0, 40);
  book<TH1F>("real gamma patParticleIso", "real #gamma patParticleIso", 40, 0, 40);
  book<TH1F>("real gamma chargedHadronIso", "real #gamma chargedHadronIso", 40, 0, 40);
  book<TH1F>("real gamma neutralHadronIso", "real #gamma neutralHadronIso", 40, 0, 40);
  book<TH1F>("real gamma photonIso", "real #gamma photonIso", 40, 0, 40);
  book<TH1F>("real gamma puChargedHadronIso", "real #gamma puChargedHadronIso", 40, 0, 40);

  book<TH1F>("N_gamma_fake", "N_{#gamma} reco fake", 20, 0, 20);
  book<TH1F>("pt_gamma_fake", "p_{T}^{#gamma} [GeV/c] reco fake", 40, 0, 4000);
  book<TH1F>("eta_gamma_fake", "#eta^{#gamma} reco fake", 40, -4, 4);
  book<TH1F>("phi_gamma_fake", "#phi^{#gamma} reco fake", 40, -4, 4);
  book<TH1F>("fake gamma puppiChargedHadronIso", "fake #gamma puppiChargedHadronIso", 40, 0, 40);
  book<TH1F>("fake gamma puppiNeutralHadronIso", "fake #gamma puppiNeutralHadronIso", 40, 0, 40);
  book<TH1F>("fake gamma puppiPhotonIso", "fake #gamma puppiPhotonIso", 40, 0, 40);
  book<TH1F>("fake gamma trackIso", "fake #gamma trackIso", 40, 0, 40);
  book<TH1F>("fake gamma ecalIso", "fake #gamma ecalIso", 40, 0, 40);
  book<TH1F>("fake gamma hcalIso", "fake #gamma hcalIso", 40, 0, 40);
  book<TH1F>("fake gamma caloIso", "fake #gamma caloIso", 40, 0, 40);
  book<TH1F>("fake gamma patParticleIso", "fake #gamma patParticleIso", 40, 0, 40);
  book<TH1F>("fake gamma chargedHadronIso", "fake #gamma chargedHadronIso", 40, 0, 40);
  book<TH1F>("fake gamma neutralHadronIso", "fake #gamma neutralHadronIso", 40, 0, 40);
  book<TH1F>("fake gamma photonIso", "fake #gamma photonIso", 40, 0, 40);
  book<TH1F>("fake gamma puChargedHadronIso", "fake #gamma puChargedHadronIso", 40, 0, 40);

  book<TH1F>("fraction of real gammas", "fraction of real gammas", 11, 0, 1.1);

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

  book<TH1F>("real_N_e", "real N_{e} reco", 20, 0, 20);
  book<TH1F>("fake_N_e", "fake N_{e} reco", 20, 0, 20);
  book<TH1F>("real_pt_e", "real p_{T}^{e} [GeV/c] reco", 40, 0, 4000);
  book<TH1F>("real_eta_e", "real #eta^{e} reco", 40, -4, 4);
  book<TH1F>("real_phi_e", "real #phi^{e} reco", 40, -4, 4);
  book<TH1F>("fake_pt_e", "fake p_{T}^{e} [GeV/c] reco", 40, 0, 4000);
  book<TH1F>("fake_eta_e", "fake #eta^{e} reco", 40, -4, 4);
  book<TH1F>("fake_phi_e", "fake #phi^{e} reco", 40, -4, 4);

  book<TH1F>("fraction of real electrons", "fraction of real electrons", 11, 0, 1.1);

  //deltaR
  book<TH1F>("min deltaR photons leptons", "min #Delta R #gamma leptons", 40, 0, 7);
  book<TH1F>("min deltaR photons jets", "min #Delta R #gamma jets", 40, 0, 7);
  book<TH1F>("min deltaR jets leptons", "min #Delta R jets leptons", 40, 0, 7);
  book<TH1F>("min deltaR photons electrons", "min #Delta R #gamma electrons", 40, 0, 7);
  book<TH1F>("min deltaR photons muons", "min #Delta R #gamma muons", 40, 0, 7);
  book<TH1F>("deltaR photon1 electrons", "#Delta R #gamma 1 electrons", 40, 0, 7);
  book<TH1F>("deltaR photon2 electrons", "#Delta R #gamma 2 electrons", 40, 0, 7);
  book<TH1F>("deltaR photon3 electrons", "#Delta R #gamma 3 electrons", 40, 0, 7);
  book<TH1F>("min deltaR real photons electrons", "min #Delta R real #gamma electrons", 40, 0, 7);
  book<TH1F>("min deltaR fake photons electrons", "min #Delta R fake #gamma electrons", 40, 0, 7);
  book<TH1F>("min deltaR real photons jets", "min #Delta R real #gamma jets", 40, 0, 7);
  book<TH1F>("min deltaR fake photons jets", "min #Delta R fake #gamma jets", 40, 0, 7);
  book<TH1F>("min deltaR real electrons photons", "min #Delta R real electrons #gamma", 40, 0, 7);
  book<TH1F>("min deltaR fake electrons photons", "min #Delta R fake electrons #gamma", 40, 0, 7);
  book<TH1F>("min deltaR real electrons jets", "min #Delta R real electrons jets", 40, 0, 7);
  book<TH1F>("min deltaR fake electrons jets", "min #Delta R fake electrons jets", 40, 0, 7);
  book<TH1F>("min deltaR real electrons real photons", "min #Delta R real electrons real #gamma", 40, 0, 7);


  is_mc = ctx.get("dataset_type") == "MC";

}


void recoHists::fill(const Event & event){
  // fill the histograms. Please note the comments in the header file:
  // 'hist' is used here a lot for simplicity, but it will be rather
  // slow when you have many histograms; therefore, better
  // use histogram pointers as members as in 'UHH2/common/include/ElectronHists.h'

  // Don't forget to always use the weight when filling.
  double weight = event.weight;

  TTbarGen ttbargen = event.get(h_ttbargen);

  std::vector<Jet>* jets = event.jets;
  std::vector<Jet> looseBjets;
  std::vector<Jet> mediumBjets;
  std::vector<Jet> tightBjets;
  GenParticle genTstarGamma;
  std::vector<GenParticle> GenParticles = *event.genparticles;
  std::vector<GenParticle> GenPhotons;
  std::vector<Photon> realRecoPhotons;
  std::vector<Photon> fakeRecoPhotons;
  std::vector<GenParticle> GenElectrons;
  std::vector<Electron> realRecoElectrons;
  std::vector<Electron> fakeRecoElectrons;


  for (const Jet & thisjet : *event.jets){
    if(thisjet.btag_DeepCSV() > 0.22){
      looseBjets.push_back(thisjet);
    }
    if(thisjet.btag_DeepCSV() > 0.63){
      mediumBjets.push_back(thisjet);
    }
    if(thisjet.btag_DeepCSV() > 0.90){
      tightBjets.push_back(thisjet);
    }
  }



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

  int NlooseBjets = looseBjets.size();
  hist("N_jets_looseBtag")->Fill(NlooseBjets, weight);

  int NmediumBjets = mediumBjets.size();
  hist("N_jets_mediumBtag")->Fill(NmediumBjets, weight);

  int NtightBjets = tightBjets.size();
  hist("N_jets_tightBtag")->Fill(NtightBjets, weight);


  int ntopjets = event.topjets->size();
  hist("N_topjets")->Fill(ntopjets, weight);

  if(event.topjets->size()>0){
    hist("eta_topjet1")->Fill(event.topjets->at(0).eta(), weight);
    hist("pt_topjet1")->Fill(event.topjets->at(0).pt(), weight);
    hist("phi_topjet1")->Fill(event.topjets->at(0).phi(), weight);
  }

  if(event.topjets->size()>1){
    hist("eta_topjet2")->Fill(event.topjets->at(1).eta(), weight);
    hist("pt_topjet2")->Fill(event.topjets->at(1).pt(), weight);
    hist("phi_topjet2")->Fill(event.topjets->at(1).phi(), weight);
  }


  int Nphotons = event.photons->size();
  hist("N_gamma")->Fill(Nphotons, weight);
  for (const Photon & thisgamma : *event.photons){
      hist("pt_gamma")->Fill(thisgamma.pt(), weight);
      hist("eta_gamma")->Fill(thisgamma.eta(), weight);
      hist("phi_gamma")->Fill(thisgamma.phi(), weight);
      hist("gamma puppiChargedHadronIso")->Fill(thisgamma.puppiChargedHadronIso(), weight);
      hist("gamma puppiNeutralHadronIso")->Fill(thisgamma.puppiNeutralHadronIso(), weight);
      hist("gamma puppiPhotonIso")->Fill(thisgamma.puppiPhotonIso(), weight);
      hist("gamma trackIso")->Fill(thisgamma.trackIso(), weight);
      hist("gamma ecalIso")->Fill(thisgamma.ecalIso(), weight);
      hist("gamma hcalIso")->Fill(thisgamma.hcalIso(), weight);
      hist("gamma caloIso")->Fill(thisgamma.caloIso(), weight);
      hist("gamma patParticleIso")->Fill(thisgamma.patParticleIso(), weight);
      hist("gamma chargedHadronIso")->Fill(thisgamma.chargedHadronIso(), weight);
      hist("gamma neutralHadronIso")->Fill(thisgamma.neutralHadronIso(), weight);
      hist("gamma photonIso")->Fill(thisgamma.photonIso(), weight);
      hist("gamma puChargedHadronIso")->Fill(thisgamma.puChargedHadronIso(), weight);
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


double min_deltaR_eg = 1000;
double min_deltaR_mg = 1000;
double min_deltaR_lg = 1000;
double min_deltaR_lj = 1000;
for (const Electron & thise : *event.electrons){
  for (const Photon & thisgamma : *event.photons){
    double calc_deltaR = deltaR(thise, thisgamma);
    if(calc_deltaR < min_deltaR_lg) min_deltaR_lg = calc_deltaR;
    if(calc_deltaR < min_deltaR_eg) min_deltaR_eg = calc_deltaR;
  }

  for (const Jet & thisjet : *event.jets){
    double calc_deltaR = deltaR(thise, thisjet);
    if(min_deltaR_lj > calc_deltaR) min_deltaR_lj = calc_deltaR;
  }
}


for (const Muon & thismu : *event.muons){

  for (const Photon & thisgamma : *event.photons){
    double calc_deltaR = deltaR(thismu, thisgamma);
    if(calc_deltaR < min_deltaR_lg) min_deltaR_lg = calc_deltaR;
    if(calc_deltaR < min_deltaR_mg) min_deltaR_mg = calc_deltaR;
  }

  for (const Jet & thisjet : *event.jets){
    double calc_deltaR = deltaR(thismu, thisjet);
    if(calc_deltaR < min_deltaR_lj) min_deltaR_lj = calc_deltaR;
  }
}

hist("min deltaR photons leptons")->Fill(min_deltaR_lg, weight);
hist("min deltaR jets leptons")->Fill(min_deltaR_lj, weight);
hist("min deltaR photons electrons")->Fill(min_deltaR_eg, weight);
hist("min deltaR photons muons")->Fill(min_deltaR_mg, weight);


double min_deltaR_gj = 1000;
for (const Photon & thisgamma : *event.photons){

    for (const Jet & thisjet : *event.jets){
      double calc_deltaR = deltaR(thisgamma, thisjet);
      if(calc_deltaR < min_deltaR_gj) min_deltaR_gj = calc_deltaR;
    }
}
hist("min deltaR photons jets")->Fill(min_deltaR_gj, weight);



if( Nphotons > 0 ){
  for( const Electron & thise : *event.electrons ){
    double calc_deltaR = deltaR(thise, event.photons->at(0));
    hist("deltaR photon1 electrons")->Fill(calc_deltaR, weight);
  }
}

if( Nphotons > 1 ){
  for( const Electron & thise : *event.electrons ){
    double calc_deltaR = deltaR(thise, event.photons->at(1));
    hist("deltaR photon2 electrons")->Fill(calc_deltaR, weight);
  }
}

if( Nphotons > 2 ){
  for( const Electron & thise : *event.electrons ){
    double calc_deltaR = deltaR(thise, event.photons->at(2));
    hist("deltaR photon3 electrons")->Fill(calc_deltaR, weight);
  }
}



for( const GenParticle & thisgenparticle : GenParticles ){
  if( thisgenparticle.pdgId() == 22 && thisgenparticle.status()==1 ){
    GenPhotons.push_back(thisgenparticle);
  }
}

for( const GenParticle & thisgenparticle : GenParticles ){
  if( thisgenparticle.pdgId() == 11 && thisgenparticle.status()==1 ){
    GenElectrons.push_back(thisgenparticle);
  }
}


if( ttbargen.IsSemiLeptonicDecay() && ttbargen.ChargedLepton().pdgId() == 11 ){

  for( const Photon & thisgamma : *event.photons ){
    double min_deltaR = 1000;
    for ( const GenParticle & thisgengamma : GenPhotons ){
      double calc_deltaR = deltaR(thisgamma, thisgengamma);
      if(calc_deltaR < min_deltaR) min_deltaR = calc_deltaR;
    }
    if(min_deltaR < 0.2) realRecoPhotons.push_back(thisgamma);
    if(min_deltaR >= 0.2) fakeRecoPhotons.push_back(thisgamma);
  }

  int Nrealphotons = realRecoPhotons.size();
  hist("N_gamma_real")->Fill(Nrealphotons, weight);
  for (const Photon & thisgamma : realRecoPhotons){
      hist("pt_gamma_real")->Fill(thisgamma.pt(), weight);
      hist("eta_gamma_real")->Fill(thisgamma.eta(), weight);
      hist("phi_gamma_real")->Fill(thisgamma.phi(), weight);
      hist("real gamma puppiChargedHadronIso")->Fill(thisgamma.puppiChargedHadronIso(), weight);
      hist("real gamma puppiNeutralHadronIso")->Fill(thisgamma.puppiNeutralHadronIso(), weight);
      hist("real gamma puppiPhotonIso")->Fill(thisgamma.puppiPhotonIso(), weight);
      hist("real gamma trackIso")->Fill(thisgamma.trackIso(), weight);
      hist("real gamma ecalIso")->Fill(thisgamma.ecalIso(), weight);
      hist("real gamma hcalIso")->Fill(thisgamma.hcalIso(), weight);
      hist("real gamma caloIso")->Fill(thisgamma.caloIso(), weight);
      hist("real gamma patParticleIso")->Fill(thisgamma.patParticleIso(), weight);
      hist("real gamma chargedHadronIso")->Fill(thisgamma.chargedHadronIso(), weight);
      hist("real gamma neutralHadronIso")->Fill(thisgamma.neutralHadronIso(), weight);
      hist("real gamma photonIso")->Fill(thisgamma.photonIso(), weight);
      hist("real gamma puChargedHadronIso")->Fill(thisgamma.puChargedHadronIso(), weight);
  }

  int Nfakephotons = fakeRecoPhotons.size();
  hist("N_gamma_fake")->Fill(Nfakephotons, weight);
  for (const Photon & thisgamma : fakeRecoPhotons){
      hist("pt_gamma_fake")->Fill(thisgamma.pt(), weight);
      hist("eta_gamma_fake")->Fill(thisgamma.eta(), weight);
      hist("phi_gamma_fake")->Fill(thisgamma.phi(), weight);
      hist("fake gamma puppiChargedHadronIso")->Fill(thisgamma.puppiChargedHadronIso(), weight);
      hist("fake gamma puppiNeutralHadronIso")->Fill(thisgamma.puppiNeutralHadronIso(), weight);
      hist("fake gamma puppiPhotonIso")->Fill(thisgamma.puppiPhotonIso(), weight);
      hist("fake gamma trackIso")->Fill(thisgamma.trackIso(), weight);
      hist("fake gamma ecalIso")->Fill(thisgamma.ecalIso(), weight);
      hist("fake gamma hcalIso")->Fill(thisgamma.hcalIso(), weight);
      hist("fake gamma caloIso")->Fill(thisgamma.caloIso(), weight);
      hist("fake gamma patParticleIso")->Fill(thisgamma.patParticleIso(), weight);
      hist("fake gamma chargedHadronIso")->Fill(thisgamma.chargedHadronIso(), weight);
      hist("fake gamma neutralHadronIso")->Fill(thisgamma.neutralHadronIso(), weight);
      hist("fake gamma photonIso")->Fill(thisgamma.photonIso(), weight);
      hist("fake gamma puChargedHadronIso")->Fill(thisgamma.puChargedHadronIso(), weight);
  }

  double min_deltaR_jRg = 1000;
  double min_deltaR_eRg = 1000;
  for(const Photon & thisgamma : realRecoPhotons){
    for(const Electron & thise : *event.electrons){
      double calc_deltaR = deltaR(thise, thisgamma);
      if(calc_deltaR < min_deltaR_eRg) min_deltaR_eRg = calc_deltaR;
    }
    for(const Jet & thisjet : *event.jets){
      double calc_deltaR = deltaR(thisjet, thisgamma);
      if(calc_deltaR < min_deltaR_jRg) min_deltaR_jRg = calc_deltaR;
    }
  }
  hist("min deltaR real photons electrons")->Fill(min_deltaR_eRg, weight);
  hist("min deltaR real photons jets")->Fill(min_deltaR_jRg, weight);

  double min_deltaR_jFg = 1000;
  double min_deltaR_eFg = 1000;
  for(const Photon & thisgamma : fakeRecoPhotons){
    for(const Electron & thise : *event.electrons){
      double calc_deltaR = deltaR(thise, thisgamma);
      if(calc_deltaR < min_deltaR_eFg) min_deltaR_eFg = calc_deltaR;
    }
    for(const Jet & thisjet : *event.jets){
      double calc_deltaR = deltaR(thisjet, thisgamma);
      if(calc_deltaR < min_deltaR_jFg) min_deltaR_jFg = calc_deltaR;
    }
    hist("min deltaR fake photons electrons")->Fill(min_deltaR_eFg, weight);
    hist("min deltaR fake photons jets")->Fill(min_deltaR_jFg, weight);
  }


  double NrealphotonsRatio = realRecoPhotons.size();
  double NfakephotonsRatio = fakeRecoPhotons.size();
  if(NrealphotonsRatio + NfakephotonsRatio > 0){
    double ratioFakeGammaRealGamma = NrealphotonsRatio/(NrealphotonsRatio + NfakephotonsRatio);
    hist("fraction of real gammas")->Fill(ratioFakeGammaRealGamma, weight);
  }


  for( const Electron & thise : *event.electrons ){
    double min_deltaR = 1000;
    for ( const GenParticle & thisgenelectron : GenElectrons ){
      double calc_deltaR = deltaR(thise, thisgenelectron);
      if(calc_deltaR < min_deltaR) min_deltaR = calc_deltaR;
    }
    if(min_deltaR < 0.2) realRecoElectrons.push_back(thise);
    if(min_deltaR >= 0.2) fakeRecoElectrons.push_back(thise);
  }

  double NrealElectronsRatio = realRecoElectrons.size();
  double NfakeElectronsRatio = fakeRecoElectrons.size();
  if(NrealElectronsRatio + NfakeElectronsRatio > 0){
    double ratioFakeElectronsRealElectrons = NrealElectronsRatio/(NrealElectronsRatio + NfakeElectronsRatio);
    hist("fraction of real electrons")->Fill(ratioFakeElectronsRealElectrons, weight);
  }

  int NrealElectrons = realRecoElectrons.size();
  int NfakeElectrons = fakeRecoElectrons.size();
  hist("real_N_e")->Fill(NrealElectrons, weight);
  hist("fake_N_e")->Fill(NfakeElectrons, weight);

  for(const Electron & thise : realRecoElectrons){
    hist("real_pt_e")->Fill(thise.pt(), weight);
    hist("real_eta_e")->Fill(thise.eta(), weight);
    hist("real_phi_e")->Fill(thise.phi(), weight);
  }

  for(const Electron & thise : fakeRecoElectrons){
    hist("fake_pt_e")->Fill(thise.pt(), weight);
    hist("fake_eta_e")->Fill(thise.eta(), weight);
    hist("fake_phi_e")->Fill(thise.phi(), weight);
  }

  double min_deltaR_jFe = 1000;
  double min_deltaR_gFe = 1000;
  for(const Electron & thise : fakeRecoElectrons){
    for(const Photon & thisgamma : *event.photons){
      double calc_deltaR = deltaR(thise, thisgamma);
      if(calc_deltaR < min_deltaR_gFe) min_deltaR_gFe = calc_deltaR;
    }
    for(const Jet & thisjet : *event.jets){
      double calc_deltaR = deltaR(thisjet, thise);
      if(calc_deltaR < min_deltaR_jFe) min_deltaR_jFe = calc_deltaR;
    }
    hist("min deltaR fake electrons photons")->Fill(min_deltaR_gFe, weight);
    hist("min deltaR fake electrons jets")->Fill(min_deltaR_jFe, weight);
  }

  double min_deltaR_jRe = 1000;
  double min_deltaR_gRe = 1000;
  for(const Electron & thise : realRecoElectrons){
    for(const Photon & thisgamma : *event.photons){
      double calc_deltaR = deltaR(thise, thisgamma);
      if(calc_deltaR < min_deltaR_gRe) min_deltaR_gRe = calc_deltaR;
    }
    for(const Jet & thisjet : *event.jets){
      double calc_deltaR = deltaR(thisjet, thise);
      if(calc_deltaR < min_deltaR_jRe) min_deltaR_jRe = calc_deltaR;
    }
    hist("min deltaR real electrons photons")->Fill(min_deltaR_gRe, weight);
    hist("min deltaR real electrons jets")->Fill(min_deltaR_jRe, weight);
  }


  double min_deltaR_RgRe = 1000;
  for(const Electron & thise : realRecoElectrons){
    for(const Photon & thisgamma : realRecoPhotons){
      double calc_deltaR = deltaR(thise, thisgamma);
      if(calc_deltaR < min_deltaR_RgRe) min_deltaR_RgRe = calc_deltaR;
    }
    hist("min deltaR real electrons real photons")->Fill(min_deltaR_RgRe, weight);
  }

}








  if(is_mc){
  double ht_jets = 0;
  for (const Jet & thisjet : *event.jets){
    ht_jets = ht_jets + thisjet.pt();
  }
  hist("HT_jets")->Fill(ht_jets, weight);
  }


}

recoHists::~recoHists(){}
