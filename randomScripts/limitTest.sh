#!/bin/bash

cd /nfs/dust/cms/user/banthiey/tStartStarV3/CMSSW_10_2_17/src/HiggsAnalysis/CombinedLimit/

sh clean.sh

python create_datacard.py

sh env_standalone.sh

python run_limits.py .
