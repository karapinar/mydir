//                                              
//  MetResolution_NVtx.c                        
//                                              
//                                              
//  Created by Guler Karapinar on 4/23/14.      
//                                              
/////////////////////////////////////////////////////////////////                                              



#include <memory>
#include <fstream>
#include <ostream>
#include <iostream>
#include <stdio.h>
#include "TLorentzVector.h"
#include <vector>
#include <sstream>
#include "TFile.h"
#include "TTree.h"
#include "TCanvas.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TLegend.h"
#include "TProfile.h"
#include "TF1.h"
#include "TMath.h"
#include "TRandom1.h"
#include "TROOT.h"
#include "TVector2.h"
#include "TVector3.h"
#include "TH1D.h"
#include "TH2D.h"
#include "TTree.h"
#include "TString.h"
#include "TChain.h"
#include <cmath>
#include "TGraph.h"
#include "TGraphErrors.h"
#include "TProfile.h"
#include "TError.h"



using namespace std;


void MetResolution_NVtx_Zee()
{
    gSystem->Load("libDelphes");
    
    // Load shared library
    gSystem->Load("libExRootAnalysis.so");
    gSystem->Load("libPhysics");
    
    // Create chain of root trees
    TChain chain("Delphes");
    //chain.Add("DY140_14TeV_upgrade.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/001.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/003.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/006.root");
    //chain.Add("/afs/cern.ch/work/g/gkarapin/sample/007.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/009.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/011.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/012.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/013.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/015.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/016.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/017.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/018.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/021.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/022.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/024.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/026.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/027.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/028.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/029.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/030.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/032.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/034.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/035.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/036.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/038.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/039.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/040.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/043.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/044.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/046.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/048.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/049.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/050.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/051.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/052.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/053.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/054.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/055.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/057.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/058.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/061.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/062.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/063.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/065.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/066.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/068.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/069.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/070.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/072.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/073.root");
    //chain.Add("/afs/cern.ch/work/g/gkarapin/sample/075.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/077.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/078.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/079.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/080.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/081.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/082.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/083.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/084.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/085.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/086.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/087.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/089.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/090.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/091.root");
    //chain.Add("/afs/cern.ch/work/g/gkarapin/sample/093.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/095.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/096.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/097.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/102.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/103.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/113.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/114.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/115.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/117.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/118.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/123.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/124.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/125.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/126.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/127.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/129.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/130.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/140.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/141.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/142.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/144.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/145.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/147.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/148.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/149.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/150.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/151.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/152.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/154.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/164.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/165.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/167.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/168.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/170.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/171.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/172.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/173.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/175.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/177.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/178.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/179.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/193.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/194.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/195.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/196.root");
    //chain.Add("/afs/cern.ch/work/g/gkarapin/sample/197.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/198.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/199.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/202.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/205.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/206.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/207.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/208.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/218.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/219.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/220.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/221.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/223.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/224.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/225.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/226.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/227.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/228.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/229.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/230.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/232.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/233.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/234.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/235.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/236.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/237.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/238.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/240.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/243.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/244.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/247.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/248.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/249.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/250.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/251.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/256.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/257.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/259.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/260.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/262.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/263.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/264.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/266.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/267.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/268.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/269.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/272.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/273.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/274.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/277.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/278.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/279.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/280.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/281.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/283.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/284.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/286.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/287.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/289.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/290.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/291.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/293.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/295.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/296.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/297.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/299.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/300.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/301.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/302.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/303.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/304.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/306.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/310.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/311.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/313.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/314.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/315.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/316.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/317.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/318.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/319.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/320.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/321.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/322.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/323.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/324.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/325.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/327.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/330.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/331.root");
    //chain.Add("/afs/cern.ch/work/g/gkarapin/sample/333.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/334.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/338.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/339.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/342.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/344.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/345.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/346.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/347.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/349.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/350.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/352.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/353.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/354.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/355.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/356.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/357.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/360.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/361.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/362.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/363.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/364.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/365.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/366.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/367.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/369.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/371.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/372.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/373.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/374.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/375.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/376.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/377.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/378.root");
    //chain.Add("/afs/cern.ch/work/g/gkarapin/sample/380.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/381.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/382.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/383.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/385.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/386.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/387.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/389.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/391.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/392.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/393.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/394.root");
    //chain.Add("/afs/cern.ch/work/g/gkarapin/sample/395.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/397.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/399.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/400.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/401.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/402.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/403.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/405.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/407.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/409.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/410.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/411.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/412.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/413.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/414.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/415.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/416.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/417.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/419.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/420.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/421.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/424.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/425.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/426.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/427.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/428.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/429.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/430.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/431.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/432.root");
    //chain.Add("/afs/cern.ch/work/g/gkarapin/sample/433.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/434.root");
    chain.Add("/afs/cern.ch/work/g/gkarapin/sample/435.root");
     //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    
    // Create object of class ExRootTreeReader
    ExRootTreeReader *treeReader = new ExRootTreeReader(&chain);
    Long64_t nentries = treeReader->GetEntries();

    std::cout << "can you read my tree ?" << std::endl;

    // Get pointers to branches used in this analysis
    TClonesArray *branchElectron = treeReader->UseBranch("Electron");
    TClonesArray *branchMissingET = treeReader->UseBranch("MissingET");
    TClonesArray *branchNPU = treeReader->UseBranch("NPU");
    
    Long64_t nentries = treeReader->GetEntries();
    
    const int qTnbins = 35;
    double qTxbins[qTnbins+1] = {0., 2, 4., 6, 8., 10, 12.5, 15, 17.5, 20., 22.5, 25.,28, 31,34,37, 40,43.5, 47, 51,55, 60, 65,70,76,82,89,97,106,116,127,139,152, 166,181,200}
    
    //Define histograms
    
    TH1D * histElectronEta = new TH1D("histElectronEta",";Electron #eta; number of events", 60, -3, 3);
    TH1D * histElectron1Pt = new TH1D("histElectron1Pt",";Electron1 P_{T} [GeV]; number of events", 200, 0.0, 200.0); 
    TH1D * histElectron2Pt = new TH1D("histElectron2Pt",";Electron2 P_{T} [GeV]; number of events", 200, 0.0, 200.0); 
    TH1D * histZmass   = new TH1D("histZmass","; Invariant mass of Z [GeV]; number of events", 120, 60.0, 120.0);
    TH1D * histZpT  = new TH1D("histZpT",";transverse momentum of Z, q_{T} [GeV]; number of events", 200, 0.0, 400.0);
    TH1D * histnvtx  = new TH1D("histnvtx",";number of vertices; number of events", 200, 0.0, 200);
    
    TH1D * histMet  = new TH1D("histMet",";#slash{E}_{T} [GeV]; number of events", 200, 0.0, 800.0);
    TH1D * histMetx = new TH1D("histMetx",";#slash{E}_{T}x [GeV]; number of events", 200, -400.0, 400.0);
    TH1D * histMety = new TH1D("histMety",";#slash{E}_{T}y [GeV]; number of events", 200, -400.0, 400.0); 
    
    TH1D * histuperp = new TH1D("histuperp",";u_{#perp}  [GeV]; number of events",100,-400.,400.);
    TH1D * histux = new TH1D("histux",";u_{x} [GeV]; number of events",100,-400.,400.);
    TH1D * histuy = new TH1D("histuy",";u_{y} [GeV]; number of events",100,-400.,400.); 
    TH1D * histupara = new TH1D("histupara",";u_{#parallel}  [GeV]; number of events",100,-400,+400); 
    TH1D * histuparaqT = new TH1D("histuparaqT","; -(u_{#parallel}+q_{T}) [GeV]; number of events",100,-400,+400);
   
    TH2F * histMetx_vs_nvtx = new TH2F("histMetx_vs_nvtx",";number of vertices; #slash{E}_{T}x [GeV]",100,100.5,200.5,200,-100,100);
    TH2F * histMety_vs_nvtx= new TH2F("histMety_vs_nvtx",";number of vertices; #slash{E}_{T}y [GeV]",100,100.5,200.5,200,-100,100);
    TH2F * histuperp_vs_qT= new TH2F("histuperp_vs_qT",";q_{T} [GeV]; #sigma ( u_{#perp} ) ",qTnbins,qTxbins,200,-100,+100);
    TH2F * histuperp_vs_nvtx= new TH2F("histuperp_vs_nvtx","number of vertices; #sigma ( u_{#perp} ) ",100,100.5,200.5, 200,-100,100);
    TH2F * histupara_vs_qT= new TH2F("histupara_vs_qT",";q_{T} [GeV];u_{#parallel}  [GeV]",qTnbins,qTxbins,200,-100,100);
    TH2F * histuparaDivqT_vs_qT= new TH2F("histuparaDivqT_vs_qT",";q_{T} [GeV];-u_{#parallel}/q_{T}",qTnbins,qTxbins,1200,-30,30);
    TH2F * histupara_vs_nvtx= new TH2F("histupara_vs_nvtx",";number of vertices;u_{#parallel}  [GeV]",100,100.5,200.5,200,-100,100);
    TH2F * histuparaDivqT_vs_nvtx= new TH2F("histuparaDivqT_vs_nvtx",";number of vertices;-u_{#parallel}/q_{T}",100,100.5,200.5,1200,-30,30);
    
    
    //Loop over events
    
    Long64_t entry;
    Int_t i, j;
    
    for(Long64_t entry = 0; entry < nentries; ++entry)
    {
        treeReader->ReadEntry(entry);
        
        Electron *elec;
        Electron *elec1, *elec2;
        TLorentzVector vec1, vec2;
        double Zmass,ZpT, Zpx, Zpy, Zpz;
        TVector2 MET_Final, u_Final, q_Final;
        int nvtx;

        std::cout << " events: " << entry << std::endl;
        
        int theNumberOfElectrons = 0;
        
        // Loop over all electrons in events
        for ( i = 0; i < branchElectron->GetEntriesFast(); ++i)
        {
            
            theNumberOfElectrons++;
            std::cout << "how many electrons I have ? =" << theNumberOfElectrons << std::endl;

            Electron *elec = (Electron*) branchElectron->At(i);
            
            
            // electron |eta| < 1.444 or 1.57 < |eta| < 2.5.
            //if(fabs(elec->Eta) > 1.444 && fabs(elec->Eta) < 1.57 ) continue;
            //if(fabs(elec->Eta) > 2.5 ) continue;
            
            if (elec->PT > 20 && fabs(elec->Eta) < 1.4442){
                
                
                    // If event contains at least 2 electron           
                    if( branchMissingET->GetEntriesFast() > 0 && branchElectron->GetEntriesFast() > 1 && branchNPU->GetEntriesFast()>0 ){
            
                        // Take first two electrons 
                        elec1 = (Electron*) branchElectron->At(0);
                        elec2 = (Electron*) branchElectron->At(1);
                        
                        // Print transverse momentum of first two electron
                        std::cout << "first electron pT =" << elec1->PT << std::endl;
                        std::cout << "second electron pT =" << elec2->PT << std::endl;
            
                        // Fill transverse momentum of first two electrons
                        histElectron1Pt->Fill(elec1->PT);
                        histElectron2Pt->Fill(elec2->PT);
                        
                        // Print eta of first two electron
                        std::cout << "first electron Eta =" << elec1->Eta << std::endl;
                        std::cout << "second electron Eta =" << elec2->Eta << std::endl;
                  
                        // Create two 4-vectors for the electrons
                        vec1.SetPtEtaPhiM(elec1->PT, elec1->Eta, elec1->Phi, 0.0);
                        vec2.SetPtEtaPhiM(elec2->PT, elec2->Eta, elec2->Phi, 0.0);
                        
                        // Define their invariant mass ( mass of Z(ee) )
                        Zmass = (vec1 + vec2).M();
                        // Print their invariant mass
                        std::cout << "mass of Z boson =" << (vec1 + vec2).M() << std::endl;
                        
                        if(Zmass < 60 || Zmass > 120) continue;
                        
                        std::cout << "Is mass of Z boson in mass window ? =" << (vec1 + vec2).M() << std::endl;
                        
                        //Fill their invariant mass
                        histZmass->Fill((vec1 + vec2).M());
            
                        //Define transverse momentum of Z boson ( qT )
                        double ZpT = (vec1+vec2).Pt();
                        std::cout << " Transverse momentum of Z boson ? =" << (vec1 + vec2).Pt() << std::endl;
                        //Fill qT
                        histZpT->Fill((vec1 + vec2).Pt());
                        Zpx = vec2.Px()+vec1.Px();
                        Zpy = vec2.Py()+vec1.Py();
                        //Zpz = vec2.Pz()+vec1.Pz();
                        std::cout << "Zpx =" << vec2.Px()+vec1.Px() << std::endl;
                        std::cout << "Zpy =" << vec2.Py()+vec1.Py() << std::endl;
                        //std::cout << "Zpz =" << vec2.Pz()+vec1.Pz() << std::endl;
                        TVector2 q_Final(Zpx, Zpy);
                        
                        //+++++++++++++++++++++++++++++++++++++++++++++++++++++++
                        
                        // Loop over MissingET 
                        //for(j = 0; j < branchMissingET->GetEntriesFast(); ++j){
                        
                        MissingET *Met = (MissingET*) branchMissingET->At(j);
                        histMet->Fill(Met->MET);
                        double METx = Met->MET*cos(Met->Phi);
                        double METy = Met->MET*sin(Met->Phi);
                        TVector2 MET_Final(METx, METy);
                        std::cout << " METx: =" << Met->MET*cos(Met->Phi) << std::endl;
                        std::cout << " METy: =" << Met->MET*sin(Met->Phi) << std::endl;
                        //Fill METx, METy
                        histMetx->Fill(METx);
                        histMety->Fill(METy);
                        
                        
                        //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                        
                        // loop over number of vertices
 
                            // the true number of pileup vertices in a "ScalarHT" object!
                            ScalarHT *NPU = (ScalarHT*) branchNPU->At(0);
                            int nvtx = (int)NPU->HT;
                            std::cout << "  Number of pileup vertices: " << nvtx << std::endl;
                            //Fill number of vertices
                            histnvtx->Fill(NPU->HT);
                        
                        //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                        
                            //Fill METx, METy vs nvtx

                            histMetx_vs_nvtx->Sumw2();
                            histMetx_vs_nvtx->Fill(nvtx,METx);
                        
                            histMety_vs_nvtx->Sumw2();
                            histMety_vs_nvtx->Fill(nvtx,METy);
                        
                            // Calculate  u_perp 
                            double ux = -(METx + Zpx);
                            double uy = -(METy + Zpy);
                            std::cout << " ux: =" << -(METx + Zpx) << std::endl;
                            std::cout << " uy: =" << -(METy + Zpy) << std::endl;
                            TVector2 u_Final(ux, uy);
                            double u_perp = u_Final.Norm(q_Final)*(q_Final.Unit()).Rotate(TMath::Pi()/2.0);
                            std::cout << " u_perp=" << u_Final.Norm(q_Final)*(q_Final.Unit()).Rotate(TMath::Pi()/2.0) << std::endl;
                            std::cout << " events: " << entry << " |u_perp|=" << fabs(u_perp) << std::endl;
                        
                            //Fill u_perp
                            histux->Fill(ux);
                            histuy->Fill(uy);
                            histuperp->Fill(u_perp);
                                                
                            //Fill uperp vs qT
                            histuperp_vs_qT->Sumw2();
                            histuperp_vs_qT->Fill(ZpT, u_perp);
                            TProfile *histuperp_vs_qT_pfx = histuperp_vs_qT->ProfileX();
                        
                            //Fill uperp vs nvertices
                            histuperp_vs_nvtx->Sumw2();
                            histuperp_vs_nvtx->Fill(nvtx,u_perp,1);
                            TProfile *histuperp_vs_nvtx_pfx = histuperp_vs_nvtx->ProfileX();

                            //calculate u_para
                            double u_para = u_Final.Proj(q_Final)*q_Final.Unit();
                            std::cout << " Finally u_para:=" << u_Final.Proj(q_Final)*q_Final.Unit() << std::endl;
                            //Fill u_para
                            histupara->Sumw2();
                            histupara->Fill(u_para);
                        
                            //calculate uparaqT
                            double uparaqT = u_para+((vec1 + vec2).Pt());
                            histuparaqT->Fill(uparaqT);
                            
                            //Fill <u_para> Vs qT 
                            histupara_vs_qT->Sumw2();
                            histupara_vs_qT->Fill(ZpT,u_para,1);
                            TProfile *histupara_vs_qT_pfx = histupara_vs_qT->ProfileX();
                        
                            //Fill upara/qT vs qT
                            histuparaDivqT_vs_qT->Sumw2();
                            double uparaDivqT = - (u_para/ZpT);
                            histuparaDivqT_vs_qT->Fill(ZpT,uparaDivqT,1);
                            TProfile *histuparaDivqT_vs_qT_pfx = histuparaDivqT_vs_qT->ProfileX();
                        
                            //Fill upara vs nvertices  
                            histupara_vs_nvtx->Sumw2();
                            histupara_vs_nvtx->Fill(nvtx,u_para,1);
                            TProfile *histupara_vs_nvtx_pfx = histupara_vs_nvtx->ProfileX();

                            //Fill upara/qT vs nvtx
                            histuparaDivqT_vs_nvtx->Sumw2();
                            histuparaDivqT_vs_nvtx->Fill(nvtx,uparaDivqT,1);
                            TProfile *histuparaDivqT_vs_nvtx_pfx = histuparaDivqT_vs_nvtx->ProfileX();
                        
                        //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                        
                    }
                
                }
                
        }
        
        
    }
    
   //Draw Plots
    
    
    TCanvas *c1 = new TCanvas("c1","c1",600,800);
    c1->SetLineStyle(1);
    c1->SetLineWidth(2);
    c1->SetLineColor(1);
    c1->Divide(1,1);
    c1->cd(23);
    histnvtx->SetFillColor(5);
    histnvtx->Draw();
    c1->SaveAs("histnvtx.png");
    
    TCanvas *c2 = new TCanvas("c2","c2",600,800);
    c2->SetFillColor(10);
    c2->Divide(1,1);
    c2->cd(2);
    c2->SetLogy();
    histElectronEta->SetFillColor(5);
    histElectronEta->Draw();
    c2 -> SaveAs("histElectronEta_v4.png");
    
        
    TCanvas *c3 = new TCanvas("c3","c3",600,800);
    c3->SetFillColor(10);
    c3->Divide(1,1);
    c3->cd(3);
    c3->SetLogy();
    histElectron1Pt->SetFillColor(5);
    histElectron1Pt->Draw();
    c3 -> SaveAs("histElectron1Pt_v4.png");
    
    TCanvas *c4 = new TCanvas("c4","c4",600,800);
    c4->SetFillColor(10);
    c4->Divide(1,1);
    c4->cd(4);
    c4->SetLogy();
    histElectron2Pt->SetFillColor(5);
    histElectron2Pt->Draw();
    c4 -> SaveAs("histElectron2Pt_v4.png");
    
    TCanvas *c5 = new TCanvas("c5","c5",600,800);
    c5->SetFillColor(10);
    c5->Divide(1,1);
    c5->cd(5);
    c5->SetLogy();
    histZmass->SetFillColor(5);
    histZmass->Draw();
    c5 -> SaveAs("histZmass_v4.png");
    
    TCanvas *c6 = new TCanvas("c6","c6",600,800);
    c6->SetFillColor(10);
    c6->Divide(1,1);
    c6->cd(6);
    c6->SetLogy();
    histZpT->SetFillColor(5);
    histZpT->Draw();
    c6 -> SaveAs("histZpT_v4.png");
  
    TCanvas *c7 = new TCanvas("c7","c7",600,800);
    c7->SetFillColor(10);
    c7->Divide(1,1);
    c7->cd(7);
    c7->SetLogy();
    histMet->SetFillColor(5);
    histMet->Draw();
    c7 -> SaveAs("histMet_v5.png");
    
    TCanvas *c8 = new TCanvas("c8","c8",600,800);
    c8->SetFillColor(10);
    c8->Divide(1,1);
    c8->cd(8);
    c8->SetLogy();
    histMetx->SetFillColor(5);
    histMetx->Draw();
    c8 -> SaveAs("histMetx_v5.png");
        
    TCanvas *c9 = new TCanvas("c9","c9",600,800);
    c9->SetFillColor(10);
    c9->Divide(1,1);
    c9->cd(9);
    c9->SetLogy();
    histMety->SetFillColor(5);
    histMety->Draw();
    c9 -> SaveAs("histMety_v5.png");
    
    TCanvas *c10 = new TCanvas("c10","c10",600,800);
    c10->SetFillColor(10);
    c10->SetLineStyle(1);
    c10->SetLineWidth(2);
    c10->SetLineColor(1);
    c10->Divide(1,1);
    c10->cd(10);
    histMetx_vs_nvtx->GetYaxis()->SetTitle(" #slash{E}_{T}x [GeV]");
    histMetx_vs_nvtx->GetYaxis()->SetTitleSize(0.0425);
    histMetx_vs_nvtx->GetYaxis()->SetTitleOffset(1.10);
    histMetx_vs_nvtx->GetYaxis()->SetLabelSize(0.04);
    histMetx_vs_nvtx->GetYaxis()->SetLabelOffset(0.007);
    histMetx_vs_nvtx->GetXaxis()->SetTitle("number of vertices");
    histMetx_vs_nvtx->GetXaxis()->SetTitleSize(0.04);
    histMetx_vs_nvtx->GetXaxis()->SetTitleOffset(1.10);
    histMetx_vs_nvtx->GetXaxis()->SetLabelSize(0.04);
    histMetx_vs_nvtx->GetXaxis()->SetLabelOffset(0.007);
    histMetx_vs_nvtx->SetLineColor(1);
    histMetx_vs_nvtx->SetMarkerSize(1);
    histMetx_vs_nvtx->SetLineWidth(1);
    histMetx_vs_nvtx->SetMarkerStyle(9);
    histMetx_vs_nvtx->SetMarkerColor(1);
    histMetx_vs_nvtx->Draw("P");
    c10->SaveAs("histMetx_vs_nvtx.png");
    
    
    TCanvas *c11 = new TCanvas("c11","c11",600,800);
    c11->SetFillColor(10);
    c11->SetLineStyle(1);
    c11->SetLineWidth(2);
    c11->SetLineColor(1);
    c11->Divide(1,1);
    c11->cd(11);
    histMety_vs_nvtx->GetYaxis()->SetTitle(" #slash{E}_{T}y [GeV]");
    histMety_vs_nvtx->GetYaxis()->SetTitleSize(0.0425);
    histMety_vs_nvtx->GetYaxis()->SetTitleOffset(1.10);
    histMety_vs_nvtx->GetYaxis()->SetLabelSize(0.04);
    histMety_vs_nvtx->GetYaxis()->SetLabelOffset(0.007);
    histMety_vs_nvtx->GetXaxis()->SetTitle("number of vertices");
    histMety_vs_nvtx->GetXaxis()->SetTitleSize(0.04);
    histMety_vs_nvtx->GetXaxis()->SetTitleOffset(1.10);
    histMety_vs_nvtx->GetXaxis()->SetLabelSize(0.04);
    histMety_vs_nvtx->GetXaxis()->SetLabelOffset(0.007);
    histMety_vs_nvtx->SetLineColor(1);
    histMety_vs_nvtx->SetMarkerSize(1);
    histMety_vs_nvtx->SetLineWidth(1);
    histMety_vs_nvtx->SetMarkerStyle(9);
    histMety_vs_nvtx->SetMarkerColor(1);
    histMety_vs_nvtx->Draw("P");
    c11->SaveAs("histMety_vs_nvtx.png");

    
    TCanvas *c12 = new TCanvas("c12","c12",600,800);
    c12->SetLineStyle(1);
    c12->SetLineWidth(2);
    c12->SetLineColor(1);
    c12->Divide(1,1);
    c12->cd(12);
    c12->SetLogy();
    histux->SetFillColor(5);
    histux->Draw();
    c12->SaveAs("histux_v5.png");
    
    
    TCanvas *c13 = new TCanvas("c13","c13",600,800);
    c13->SetLineStyle(1);
    c13->SetLineWidth(2);
    c13->SetLineColor(1);
    c13->Divide(1,1);
    c13->cd(13);
    c13->SetLogy();
    histuy->SetFillColor(5);
    histuy->Draw();
    c13 -> SaveAs("histuy_v5.png");
    
    TCanvas *c14 = new TCanvas("c14","c14",600,800);
    c14->SetLineStyle(1);
    c14->SetLineWidth(2);
    c14->SetLineColor(1);
    c14->Divide(1,1);
    c14->cd(14);
    c14->SetLogy();
    histuperp->SetFillColor(5);
    histuperp->Draw();
    c14->SaveAs("histuperp_v5.png");
    
    
    TCanvas *c15 = new TCanvas("c15","c15",600,800);
    c15->SetLineStyle(1);
    c15->SetLineWidth(2);
    c15->SetLineColor(1);
    c15->Divide(1,2);
    c15->cd(1);
    histuperp_vs_qT->Draw( );
    c15->cd(2);
    histuperp_vs_qT_pfx->GetYaxis()->SetTitle(" #sigma( u_{#perp} )");
    histuperp_vs_qT_pfx->GetYaxis()->SetTitleSize(0.0425);
    histuperp_vs_qT_pfx->GetYaxis()->SetTitleOffset(1.10);
    histuperp_vs_qT_pfx->GetYaxis()->SetLabelSize(0.04);
    histuperp_vs_qT_pfx->GetYaxis()->SetLabelOffset(0.007);
    histuperp_vs_qT_pfx->GetXaxis()->SetTitle("q_{T} [GeV]");
    histuperp_vs_qT_pfx->GetXaxis()->SetTitleSize(0.04);
    histuperp_vs_qT_pfx->GetXaxis()->SetTitleOffset(1.10);
    histuperp_vs_qT_pfx->GetXaxis()->SetLabelSize(0.04);
    histuperp_vs_qT_pfx->GetXaxis()->SetLabelOffset(0.007);
    histuperp_vs_qT_pfx->SetLineColor(1);
    histuperp_vs_qT_pfx->SetMarkerSize(0.7);
    histuperp_vs_qT_pfx->SetLineWidth(1);
    histuperp_vs_qT_pfx->SetMarkerStyle(21);
    histuperp_vs_qT_pfx->SetMarkerColor(1);
    histuperp_vs_qT_pfx->Draw("P");
    c15->SaveAs("histuperp_vs_qT_pfx.png");
    c15->Close();
    
    TCanvas *c18 = new TCanvas("c18","c18",600,800);
    c18->SetLineStyle(1);
    c18->SetLineWidth(2);
    c18->SetLineColor(1);
    c18->Divide(1,1);
    c18->cd(18);
    c18->SetLogy();
    histuparaqT->SetFillColor(5);
    histuparaqT->Draw();
    c18->SaveAs("histuparaqT.png");

    
    TCanvas *c17 = new TCanvas("c17","c17",600,800);
    c17->SetLineStyle(1);
    c17->SetLineWidth(2);
    c17->SetLineColor(1);
    c17->Divide(1,1);
    c17->cd(17);
    c17->SetLogy();
    histupara->SetFillColor(5);
    histupara->Draw();
    c17->SaveAs("histupara_v5.png");
    
    
    TCanvas *c18 = new TCanvas("c18","c18",600,800);
    c18->SetLineStyle(1);
    c18->SetLineWidth(2);
    c18->SetLineColor(1);
    c18->Divide(1,1);
    c18->cd(18);
    c18->SetLogy();
    histuparaqT->SetFillColor(5);
    histuparaqT->Draw();
    c18->SaveAs("histuparaqT_v5.png");
    
    TCanvas *c19 = new TCanvas("c19","c19",600,800);
    c19->SetLineStyle(1);
    c19->SetLineWidth(2);
    c19->SetLineColor(1);
    c19->Divide(1,2);
    c19->cd(1);
    histupara_vs_qT->Draw();
    c19->cd(2);
    histupara_vs_qT_pfx->GetYaxis()->SetTitle(" #sigma( u_{#parallel} )");
    histupara_vs_qT_pfx->GetYaxis()->SetTitleSize(0.0425);
    histupara_vs_qT_pfx->GetYaxis()->SetTitleOffset(1.10);
    histupara_vs_qT_pfx->GetYaxis()->SetLabelSize(0.04);
    histupara_vs_qT_pfx->GetYaxis()->SetLabelOffset(0.007);
    histupara_vs_qT_pfx->GetXaxis()->SetTitle("q_{T} [GeV]");
    histupara_vs_qT_pfx->GetXaxis()->SetTitleSize(0.04);
    histupara_vs_qT_pfx->GetXaxis()->SetTitleOffset(1.10);
    histupara_vs_qT_pfx->GetXaxis()->SetLabelSize(0.04);
    histupara_vs_qT_pfx->GetXaxis()->SetLabelOffset(0.007);
    histupara_vs_qT_pfx->SetLineColor(1);
    histupara_vs_qT_pfx->SetMarkerSize(0.7);
    histupara_vs_qT_pfx->SetLineWidth(1);
    histupara_vs_qT_pfx->SetMarkerStyle(21);
    histupara_vs_qT_pfx->SetMarkerColor(1);
    histupara_vs_qT_pfx->Draw("P");
    c19->SaveAs("histupara_vs_qT_pfx.png");
    c19->Close();
    

    
    TCanvas *c20 = new TCanvas("c20","c20",600,800);
    c20->SetLineStyle(1);
    c20->SetLineWidth(2);
    c20->SetLineColor(1);
    c20->Divide(1,2);
    c20->cd(1);
    histuparaDivqT_vs_qT->Draw();
    c20->cd(2);
    histuparaDivqT_vs_qT_pfx->GetYaxis()->SetTitle(" -u_{#parallel}/q_{T}");
    histuparaDivqT_vs_qT_pfx->GetYaxis()->SetTitleSize(0.0425);
    histuparaDivqT_vs_qT_pfx->GetYaxis()->SetTitleOffset(1.10);
    histuparaDivqT_vs_qT_pfx->GetYaxis()->SetLabelSize(0.04);
    histuparaDivqT_vs_qT_pfx->GetYaxis()->SetLabelOffset(0.007);
    histuparaDivqT_vs_qT_pfx->GetXaxis()->SetTitle("q_{T} [GeV/c]");
    histuparaDivqT_vs_qT_pfx->GetXaxis()->SetTitleSize(0.04);
    histuparaDivqT_vs_qT_pfx->GetXaxis()->SetTitleOffset(1.10);
    histuparaDivqT_vs_qT_pfx->GetXaxis()->SetLabelSize(0.04);
    histuparaDivqT_vs_qT_pfx->GetXaxis()->SetLabelOffset(0.007);
    histuparaDivqT_vs_qT_pfx->SetLineColor(1);
    histuparaDivqT_vs_qT_pfx->SetMarkerSize(1);
    histuparaDivqT_vs_qT_pfx->SetLineWidth(1);
    histuparaDivqT_vs_qT_pfx->SetMarkerStyle(21);
    histuparaDivqT_vs_qT_pfx->SetMarkerSize(.7);
    histuparaDivqT_vs_qT_pfx->SetMarkerColor(1);
    histuparaDivqT_vs_qT_pfx->Draw("P");
    c20->SaveAs("histuparaDivqT_vs_qT_pfx.png");
    c20->Close();
    
    TCanvas *c21 = new TCanvas("c21","c21",600,800);
    c21->SetLineStyle(1);
    c21->SetLineWidth(2);
    c21->SetLineColor(1);
    c21->Divide(1,2);
    c21->cd(1);
    histupara_vs_nvtx->Draw();
    c21->cd(2);
    histupara_vs_nvtx_pfx->GetYaxis()->SetTitle(" -u_{#parallel}/q_{T}");
    histupara_vs_nvtx_pfx->GetYaxis()->SetTitleSize(0.0425);
    histupara_vs_nvtx_pfx->GetYaxis()->SetTitleOffset(1.10);
    histupara_vs_nvtx_pfx->GetYaxis()->SetLabelSize(0.04);
    histupara_vs_nvtx_pfx->GetYaxis()->SetLabelOffset(0.007);
    histupara_vs_nvtx_pfx->GetXaxis()->SetTitle(" number of vertices ");
    histupara_vs_nvtx_pfx->GetXaxis()->SetTitleSize(0.04);
    histupara_vs_nvtx_pfx->GetXaxis()->SetTitleOffset(1.10);
    histupara_vs_nvtx_pfx->GetXaxis()->SetLabelSize(0.04);
    histupara_vs_nvtx_pfx->GetXaxis()->SetLabelOffset(0.007);
    histupara_vs_nvtx_pfx->SetLineColor(1);
    histupara_vs_nvtx_pfx->SetMarkerSize(1);
    histupara_vs_nvtx_pfx->SetLineWidth(1);
    histupara_vs_nvtx_pfx->SetMarkerStyle(21);
    histupara_vs_nvtx_pfx->SetMarkerSize(.7);
    histupara_vs_nvtx_pfx->SetMarkerColor(1);
    histupara_vs_nvtx_pfx->Draw("P");
    c21->SaveAs("histupara_vs_nvtx_pfx.png");
    c21->Close();
    
    
    TCanvas *c22 = new TCanvas("c22","c22",600,800);
    c22->SetLineStyle(1);
    c22->SetLineWidth(2);
    c22->SetLineColor(1);
    c22->Divide(1,2);
    c22->cd(1);
    histuparaDivqT_vs_nvtx->Draw(" ");
    c22->cd(2);
    histuparaDivqT_vs_nvtx_pfx->GetYaxis()->SetTitle(" -u_{#parallel}/q_{T}");
    histuparaDivqT_vs_nvtx_pfx->GetYaxis()->SetTitleSize(0.0425);
    histuparaDivqT_vs_nvtx_pfx->GetYaxis()->SetTitleOffset(1.10);
    histuparaDivqT_vs_nvtx_pfx->GetYaxis()->SetLabelSize(0.04);
    histuparaDivqT_vs_nvtx_pfx->GetYaxis()->SetLabelOffset(0.007);
    histuparaDivqT_vs_nvtx_pfx->GetXaxis()->SetTitle(" number of vertices ");
    histuparaDivqT_vs_nvtx_pfx->GetXaxis()->SetTitleSize(0.04);
    histuparaDivqT_vs_nvtx_pfx->GetXaxis()->SetTitleOffset(1.10);
    histuparaDivqT_vs_nvtx_pfx->GetXaxis()->SetLabelSize(0.04);
    histuparaDivqT_vs_nvtx_pfx->GetXaxis()->SetLabelOffset(0.007);
    histuparaDivqT_vs_nvtx_pfx->SetLineColor(1);
    histuparaDivqT_vs_nvtx_pfx->SetMarkerSize(1);
    histuparaDivqT_vs_nvtx_pfx->SetLineWidth(1);
    histuparaDivqT_vs_nvtx_pfx->SetMarkerStyle(21);
    histuparaDivqT_vs_nvtx_pfx->SetMarkerSize(.7);
    histuparaDivqT_vs_nvtx_pfx->SetMarkerColor(1);
    histuparaDivqT_vs_nvtx_pfx->Draw("P");
    c22->SaveAs("histuparaDivqT_vs_nvtx_pfx.png");
    c22->Close();
    
    std::cout << " Plots are done " << std::endl;
    
    
}






