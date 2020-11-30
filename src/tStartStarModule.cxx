#include <iostream>
#include <memory>

#include "UHH2/core/include/AnalysisModule.h"
#include "UHH2/core/include/Event.h"
#include "UHH2/common/include/CommonModules.h"
#include "UHH2/common/include/CleaningModules.h"
#include "UHH2/common/include/ElectronHists.h"
#include "UHH2/common/include/NSelections.h"
#include "UHH2/tStartStar/include/tStartStarSelections.h"
#include "UHH2/tStartStar/include/tStartStarHists.h"
#include "UHH2/tStartStar/include/genHists.h"
#include "UHH2/tStartStar/include/recoHists.h"
#include "UHH2/common/include/PhotonIds.h"
#include "UHH2/common/include/MuonIds.h"
#include "UHH2/common/include/ElectronIds.h"
#include "UHH2/common/include/TriggerSelection.h"


using namespace std;
using namespace uhh2;

namespace uhh2examples {

/** \brief Basic analysis example of an AnalysisModule (formerly 'cycle') in UHH2
 *
 * This is the central class which calls other AnalysisModules, Hists or Selection classes.
 * This AnalysisModule, in turn, is called (via AnalysisModuleRunner) by SFrame.
 */
class tStartStarModule: public AnalysisModule {
public:

    explicit tStartStarModule(Context & ctx);
    virtual bool process(Event & event) override;

private:

    std::unique_ptr<CommonModules> common;

    std::unique_ptr<JetCleaner> jetcleaner;

    std::unique_ptr<Selection> electronTrigger;
    std::unique_ptr<Selection> muonTrigger;
    // declare the Selections to use. Use unique_ptr to ensure automatic call of delete in the destructor,
    // to avoid memory leaks.

    // store the Hists collection as member variables. Again, use unique_ptr to avoid memory leaks.
    std::unique_ptr<Hists> reco_nocuts;
    std::unique_ptr<Hists> gen_nocuts;
    std::unique_ptr<Hists> reco_CM;
    std::unique_ptr<Hists> gen_CM;
    std::unique_ptr<Hists> reco_triggers;
    std::unique_ptr<Hists> gen_triggers;
    std::unique_ptr<Hists> reco_lepsel;
    std::unique_ptr<Hists> gen_lepsel;
    std::unique_ptr<Hists> reco_phosel;
    std::unique_ptr<Hists> gen_phosel;
    std::unique_ptr<Hists> reco_jetsel;
    std::unique_ptr<Hists> gen_jetsel;
};


tStartStarModule::tStartStarModule(Context & ctx){
    // In the constructor, the typical tasks are to initialize the
    // member variables, in particular the AnalysisModules such as
    // CommonModules or some cleaner module, Selections and Hists.
    // But you can do more and e.g. access the configuration, as shown below.

    cout << "Hello World from tStartStarModule!" << endl;

    // If needed, access the configuration of the module here, e.g.:
    string testvalue = ctx.get("TestKey", "<not set>");
    cout << "TestKey in the configuration was: " << testvalue << endl;

    // If running in SFrame, the keys "dataset_version", "dataset_type", "dataset_lumi",
    // and "target_lumi" are set to the according values in the xml file. For CMSSW, these are
    // not set automatically, but can be set in the python config file.
    for(auto & kv : ctx.get_all()){
        cout << " " << kv.first << " = " << kv.second << endl;
    }

    // 1. setup other modules. CommonModules and the JetCleaner:
    common.reset(new CommonModules());



    common->switch_metcorrection();
    common->switch_jetlepcleaner();
    common->switch_jetPtSorter();

    double jet_pt(30.);
    common->set_jet_id(AndId<Jet>(PtEtaCut(jet_pt, 2.4), JetPFID(JetPFID::WP_TIGHT_PUPPI)));

    ElectronId eleID;
        double electron_pt(20.);
        eleID = ElectronID_Summer16_tight_noIso;
        common->set_electron_id(AndId<Electron>(PtEtaSCCut(electron_pt, 2.4), eleID));

    MuonId muID;
        double muon_pt(20.);
        muID = MuonID(Muon::Highpt);
    //    muID = MuonID(Muon::CutBasedIdTight);
        common->set_muon_id(AndId<Muon>(PtEtaCut(muon_pt, 2.4), muID));

    PhotonId phoID = PhotonTagID(Photon::mvaPhoID_Fall17_iso_V2_wp90);
        common->set_photon_id(AndId<Photon>(PtEtaCut(20., 2.4), phoID));

    common->init(ctx);

    // jetcleaner.reset(new JetCleaner(ctx, s30.0, 2.4));

    // note that the JetCleaner is only kept for the sake of example;
    // instead of constructing a jetcleaner explicitly,
    // the cleaning can also be achieved with less code via CommonModules with:
    // common->set_jet_id(PtEtaCut(30.0, 2.4));
    // before the 'common->init(ctx)' line.

    // 2. set up selections
    electronTrigger.reset(new TriggerSelection("HLT_Ele27_WPTight_Gsf_v*"));
    muonTrigger.reset(new TriggerSelection("HLT_IsoMu24_v*"));


    // 3. Set up Hists classes:
    reco_CM.reset(new recoHists(ctx, "recoCM"));
    gen_CM.reset(new genHists(ctx, "genCM"));
    reco_triggers.reset(new recoHists(ctx, "recoTriggers"));
    gen_triggers.reset(new genHists(ctx, "genTriggers"));
    reco_nocuts.reset(new recoHists(ctx, "recoNoCuts"));
    gen_nocuts.reset(new genHists(ctx, "genNoCuts"));
    reco_lepsel.reset(new recoHists(ctx, "recolepsel"));
    gen_lepsel.reset(new genHists(ctx, "genlepsel"));
    reco_phosel.reset(new recoHists(ctx, "recophosel"));
    gen_phosel.reset(new genHists(ctx, "genphosel"));
    reco_jetsel.reset(new recoHists(ctx, "recojetsel"));
    gen_jetsel.reset(new genHists(ctx, "genjetsel"));
}


bool tStartStarModule::process(Event & event) {
    // This is the main procedure, called for each event. Typically,
    // do some pre-processing by calling the modules' process method
    // of the modules constructed in the constructor (1).
    // Then, test whether the event passes some selection and -- if yes --
    // use it to fill the histograms (2).
    // Finally, decide whether or not to keep the event in the output (3);
    // this is controlled by the return value of this method: If it
    // returns true, the event is kept; if it returns false, the event
    // is thrown away.

    //cout << "tStartStarModule: Starting to process event (runid, eventid) = (" << event.run << ", " << event.event << "); weight = " << event.weight << endl;

    // 1. run all modules other modules.
    // Note that it returns a bool, that may be False
    // (e.g. Golden JSON, MET filters), and therefore user should return early
    reco_nocuts->fill(event);
    gen_nocuts->fill(event);

    bool commonResult = common->process(event);
    if (!commonResult) return false;
    // jetcleaner->process(event);

    // 2. test selections and fill histograms
    reco_CM->fill(event);
    gen_CM->fill(event);


    bool pass_trigger = (electronTrigger->passes(event) || muonTrigger->passes(event));
    if(!pass_trigger) return false;

    reco_triggers->fill(event);
    gen_triggers->fill(event);


    const bool pass_lep1 = (((event.muons->size() == 1) || (event.electrons->size() == 1)) && (event.electrons->size()+event.muons->size()) == 1);
    if(!pass_lep1) return false;


    reco_lepsel->fill(event);
    gen_lepsel->fill(event);


    const bool pass_pho1 = (event.photons->size() == 1);
    if(!pass_pho1) return false;

    reco_phosel->fill(event);
    gen_phosel->fill(event);

    bool pass_njet = (event.jets->size() >= 2);
    if(!pass_njet) return false;

    reco_jetsel->fill(event);
    gen_jetsel->fill(event);

    // 3. decide whether or not to keep the current event in the output:
    return true;
}

// as we want to run the ExampleCycleNew directly with AnalysisModuleRunner,
// make sure the tStartStarModule is found by class name. This is ensured by this macro:
UHH2_REGISTER_ANALYSIS_MODULE(tStartStarModule)

}
