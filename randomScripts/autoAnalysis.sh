#!/bin/bash

echo Merging the root files...

cd /nfs/dust/cms/user/banthiey/tStartStarV3/Output/MonteCarlo/2016
hadd uhh2.AnalysisModuleRunner.MC.QCD.root uhh2.AnalysisModuleRunner.MC.MC_QCD_HT1000to1500_Run2016v3.root uhh2.AnalysisModuleRunner.MC.MC_QCD_HT100to200_Run2016v3.root uhh2.AnalysisModuleRunner.MC.MC_QCD_HT1500to2000_Run2016v3.root uhh2.AnalysisModuleRunner.MC.MC_QCD_HT2000toInf_Run2016v3.root uhh2.AnalysisModuleRunner.MC.MC_QCD_HT200to300_Run2016v3.root uhh2.AnalysisModuleRunner.MC.MC_QCD_HT300to500_Run2016v3.root uhh2.AnalysisModuleRunner.MC.MC_QCD_HT500to700_Run2016v3.root uhh2.AnalysisModuleRunner.MC.MC_QCD_HT50to100_Run2016v3.root uhh2.AnalysisModuleRunner.MC.MC_QCD_HT700to1000_Run2016v3.root

hadd uhh2.AnalysisModuleRunner.MC.ST.root uhh2.AnalysisModuleRunner.MC.MC_ST_s-channel_inclusiveDecays_Run2016v3.root uhh2.AnalysisModuleRunner.MC.MC_ST_t-channel_antitop_inclusiveDecays_Run2016v3.root uhh2.AnalysisModuleRunner.MC.MC_ST_t-channel_top_inclusiveDecays_Run2016v3.root uhh2.AnalysisModuleRunner.MC.MC_ST_tW_antitop_NoFullyHadronicDecays_P8M1_PUMoriond17_Run2016v3.root uhh2.AnalysisModuleRunner.MC.MC_ST_tW_top_NoFullyHadronicDecays_P8M1_PUMoriond17_Run2016v3.root

hadd uhh2.AnalysisModuleRunner.MC.VV.root uhh2.AnalysisModuleRunner.MC.MC_WWToLNuQQ_Run2016v3.root uhh2.AnalysisModuleRunner.MC.MC_WZToLNu2Q_Run2016v3.root

hadd uhh2.AnalysisModuleRunner.MC.WJets.root uhh2.AnalysisModuleRunner.MC.WJetsToLNu_Pt-100To250_Run2016v3.root uhh2.AnalysisModuleRunner.MC.WJetsToLNu_Pt-250To400_Run2016v3.root uhh2.AnalysisModuleRunner.MC.WJetsToLNu_Pt-400To600_Run2016v3.root uhh2.AnalysisModuleRunner.MC.WJetsToLNu_Pt-600ToInf_Run2016v3.root

hadd uhh2.AnalysisModuleRunner.MC.DYJets.root uhh2.AnalysisModuleRunner.MC.DYJetsToLL_M-50_HT-100to200_Run2016v3.root uhh2.AnalysisModuleRunner.MC.DYJetsToLL_M-50_HT-1200to2500_Run2016v3.root uhh2.AnalysisModuleRunner.MC.DYJetsToLL_M-50_HT-200to400_Run2016v3.root uhh2.AnalysisModuleRunner.MC.DYJetsToLL_M-50_HT-2500toInf_Run2016v3.root uhh2.AnalysisModuleRunner.MC.DYJetsToLL_M-50_HT-400to600_Run2016v3.root uhh2.AnalysisModuleRunner.MC.DYJetsToLL_M-50_HT-600to800_Run2016v3.root uhh2.AnalysisModuleRunner.MC.DYJetsToLL_M-50_HT-70to100_Run2016v3.root uhh2.AnalysisModuleRunner.MC.DYJetsToLL_M-50_HT-800to1200_Run2016v3.root

mv uhh2.AnalysisModuleRunner.MC.TTJets_TuneCUETP8M1_Run2016v3.root uhh2.AnalysisModuleRunner.MC.TTJets.root

echo Finished merging the root files!


echo Moving merged root files to the correct folder...

mv uhh2.AnalysisModuleRunner.MC.ST.root /nfs/dust/cms/user/banthiey/tStartStarV3/Output/DataAndMonteCarlo
mv uhh2.AnalysisModuleRunner.MC.VV.root /nfs/dust/cms/user/banthiey/tStartStarV3/Output/DataAndMonteCarlo
mv uhh2.AnalysisModuleRunner.MC.WJets.root /nfs/dust/cms/user/banthiey/tStartStarV3/Output/DataAndMonteCarlo
mv uhh2.AnalysisModuleRunner.MC.DYJets.root /nfs/dust/cms/user/banthiey/tStartStarV3/Output/DataAndMonteCarlo
mv uhh2.AnalysisModuleRunner.MC.TTJets.root /nfs/dust/cms/user/banthiey/tStartStarV3/Output/DataAndMonteCarlo
mv uhh2.AnalysisModuleRunner.MC.QCD.root /nfs/dust/cms/user/banthiey/tStartStarV3/Output/DataAndMonteCarlo
mv uhh2.AnalysisModuleRunner.MC.TstarTstarToTgluonTgamma_M-700_Run2016v3.root /nfs/dust/cms/user/banthiey/tStartStarV3/Output/DataAndMonteCarlo
mv uhh2.AnalysisModuleRunner.MC.TstarTstarToTgluonTgamma_M-800_Run2016v3.root /nfs/dust/cms/user/banthiey/tStartStarV3/Output/DataAndMonteCarlo
mv uhh2.AnalysisModuleRunner.MC.TstarTstarToTgluonTgamma_M-900_Run2016v3.root /nfs/dust/cms/user/banthiey/tStartStarV3/Output/DataAndMonteCarlo
mv uhh2.AnalysisModuleRunner.MC.TstarTstarToTgluonTgamma_M-1000_Run2016v3.root /nfs/dust/cms/user/banthiey/tStartStarV3/Output/DataAndMonteCarlo
mv uhh2.AnalysisModuleRunner.MC.TstarTstarToTgluonTgamma_M-1100_Run2016v3.root /nfs/dust/cms/user/banthiey/tStartStarV3/Output/DataAndMonteCarlo
mv uhh2.AnalysisModuleRunner.MC.TstarTstarToTgluonTgamma_M-1200_Run2016v3.root /nfs/dust/cms/user/banthiey/tStartStarV3/Output/DataAndMonteCarlo
mv uhh2.AnalysisModuleRunner.MC.TstarTstarToTgluonTgamma_M-1300_Run2016v3.root /nfs/dust/cms/user/banthiey/tStartStarV3/Output/DataAndMonteCarlo
mv uhh2.AnalysisModuleRunner.MC.TstarTstarToTgluonTgamma_M-1400_Run2016v3.root /nfs/dust/cms/user/banthiey/tStartStarV3/Output/DataAndMonteCarlo
mv uhh2.AnalysisModuleRunner.MC.TstarTstarToTgluonTgamma_M-1500_Run2016v3.root /nfs/dust/cms/user/banthiey/tStartStarV3/Output/DataAndMonteCarlo
mv uhh2.AnalysisModuleRunner.MC.TstarTstarToTgluonTgamma_M-1600_Run2016v3.root /nfs/dust/cms/user/banthiey/tStartStarV3/Output/DataAndMonteCarlo

sleep 60

echo Finished moving the root files!


echo Creating Plots...

cd /nfs/dust/cms/user/banthiey/plotter/SFramePlotter/steerFiles/

Plots -f MCfullSample.steer

cd /nfs/dust/cms/user/banthiey/tStartStarV3/CMSSW_10_2_17/src/UHH2/tStartStar/randomScripts

root -l -b -q efficiencies.C

cd /nfs/dust/cms/user/banthiey/tStartStarV3/CMSSW_10_2_17/src/HiggsAnalysis/CombinedLimit/

sh clean.sh

python create_datacard.py

sh env_standalone.sh

python run_limits.py .

echo Analysis finished!
