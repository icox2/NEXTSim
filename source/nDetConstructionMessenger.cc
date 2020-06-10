
#include <iostream>

#include "nDetConstructionMessenger.hh"
#include "nDetConstruction.hh"

#include "G4Material.hh"
#include "G4UIcommand.hh"
#include "G4UIcmdWithAString.hh"
#include "G4UIdirectory.hh"
#include "G4UIcmdWith3Vector.hh"
#include "G4UIcmdWith3VectorAndUnit.hh"
#include "G4UIcmdWithADouble.hh"
#include "G4UIcmdWithAnInteger.hh"
#include "G4UIcmdWithoutParameter.hh"
#include "G4SystemOfUnits.hh"

void nDetConstructionMessenger::addAllCommands(){
	///////////////////////////////////////////////////////////////////////////////
	// Detector commands
	///////////////////////////////////////////////////////////////////////////////

	addDirectory("/nDet/detector/", "Detector geometry control");

	addCommand(new G4UIcmdWithAString("/nDet/detector/addGeometry", this));
	addGuidance("Defines the Geometry of the detector");

	addCommand(new G4UIcommand("/nDet/detector/update", this));
	addGuidance("Updates the detector Geometry");

	addCommand(new G4UIcmdWithAString("/nDet/detector/setSpectralResponse", this));
	addGuidance("Load PMT spectral response from a root file");
	addGuidance("Input file MUST contain a TGraph named \"spec\"");

	addCommand(new G4UIcmdWithAString("/nDet/detector/setGainMatrix", this));
	addGuidance("Load segmented PMT anode gain matrix file");
	
	addCommand(new G4UIcmdWithAString("/nDet/detector/addGreaseLayer", this));
	addGuidance("Add a layer of optical grease (all units in mm). SYNTAX: addGreaseLayer <width> <height> [thickness]");	

	addCommand(new G4UIcmdWithAString("/nDet/detector/addDiffuserLayer", this));
	addGuidance("Add a straight diffuser to the assembly (all units in mm). SYNTAX: addDiffuserLayer <width> <height> <thickness> [material=G4_SILICON_DIOXIDE]");	

	addCommand(new G4UIcmdWithAString("/nDet/detector/addLightGuide", this));
	addGuidance("Add a trapezoidal light-guide to the assembly (all units in mm). SYNTAX: addLightGuide <width1> <width2> <height1> <height2> <thickness> [material=G4_SILICON_DIOXIDE]");	

	addCommand(new G4UIcmdWithAString("/nDet/detector/loadLightGuide", this));
	addGuidance("Load a light-guide from a GDML geometry file. SYNTAX: loadLightGuide <filename> <rotX> <rotY> <rotZ> <matString>");

	addCommand(new G4UIcmdWithoutParameter("/nDet/detector/clear", this));
	addGuidance("Clear all detector Geometry");
	
	addCommand(new G4UIcmdWithAString("/nDet/detector/addArray", this));
	addGuidance("Add an array of multiple detectors. SYNTAX: addArray <geom> <r0> <startTheta> <stopTheta> <Ndet>");

	addCommand(new G4UIcmdWithoutParameter("/nDet/detector/printAll", this));
	addGuidance("Print construction parameters for all defined detectors");

	///////////////////////////////////////////////////////////////////////////////
	// PMT & digitizer commands
	///////////////////////////////////////////////////////////////////////////////

	addDirectory("/nDet/output/trace/", "Output light pulse parameters");

	addCommand(new G4UIcmdWithADouble("/nDet/output/trace/setRisetime", this));
	addGuidance("Set the PMT light response risetime (ns)");

	addCommand(new G4UIcmdWithADouble("/nDet/output/trace/setFalltime", this));
	addGuidance("Set the PMT light response falltime (ns)");

	addCommand(new G4UIcmdWithADouble("/nDet/output/trace/setGain", this));
	addGuidance("Set the gain of the PMT light response pulse");

	addCommand(new G4UIcmdWithADouble("/nDet/output/trace/setBaseline", this));
	addGuidance("Set the baseline of the PMT light response pulse as a percentage of the full ADC range");

	addCommand(new G4UIcmdWithADouble("/nDet/output/trace/setJitter", this));
	addGuidance("Set the baseline jitter of the PMT light response pulse as a percentage of the full ADC range");

	addCommand(new G4UIcmdWithADouble("/nDet/output/trace/setCfdFraction", this));
	addGuidance("Set the Cfd F parameter as a fraction of the maximum pulse height");

	addCommand(new G4UIcmdWithADouble("/nDet/output/trace/setTraceDelay", this));
	addGuidance("Set the delay of the PMT light response pulse (ns)");

	addCommand(new G4UIcmdWithADouble("/nDet/output/trace/setTraceLength", this));
	addGuidance("Set the length of the PMT light response pulse (ns)");

	addCommand(new G4UIcmdWithADouble("/nDet/output/trace/setTimeSpread", this));
	addGuidance("Set the FWHM spread in the photo-electron transit time of the PMT (ns)");

	addCommand(new G4UIcmdWithAnInteger("/nDet/output/trace/setIntegralLow", this));
	addGuidance("Set the low pulse integration limit in ADC bins");

	addCommand(new G4UIcmdWithAnInteger("/nDet/output/trace/setIntegralHigh", this));
	addGuidance("Set the high pulse integration limit in ADC bins");

	addCommand(new G4UIcmdWithAnInteger("/nDet/output/trace/setBitRange", this));
	addGuidance("Set the ADC dynamic bit range");

	addCommand(new G4UIcmdWithAString("/nDet/output/trace/setFunction", this));
	addGuidance("Set the single photon response function (default=0)");
	addCandidates("expo 0 vandle 1 gauss 2");

	addCommand(new G4UIcmdWithADouble("/nDet/output/trace/setAdcClock", this));
	addGuidance("Set the period of the ADC clock (ns)");
	
	addCommand(new G4UIcmdWithADouble("/nDet/output/trace/setAdcClockFrequency", this));
	addGuidance("Set the frequency of the ADC clock (MHz)");	

	addCommand(new G4UIcmdWithAString("/nDet/output/trace/print", this));
	addGuidance("Print the digitized light pulse");
	addCandidates("true false");

	addCommand(new G4UIcmdWithoutParameter("/nDet/output/trace/params", this));
	addGuidance("Print pulse and digitizer settings");

	///////////////////////////////////////////////////////////////////////////////
	// Implant commands
	///////////////////////////////////////////////////////////////////////////////

	addDirectory("/nDet/implant/", "Implant geometry control");

	addCommand(new G4UIcmdWithAString("/nDet/implant/addGeometry", this));
	addGuidance("Defines the Geometry of the implant");

	addCommand(new G4UIcommand("/nDet/implant/update", this));
	addGuidance("Updates the implant Geometry");

	addCommand(new G4UIcmdWithAString("/nDet/implant/setSpectralResponse", this));
	addGuidance("Load PMT spectral response from a root file");
	addGuidance("Input file MUST contain a TGraph named \"spec\"");

	addCommand(new G4UIcmdWithAString("/nDet/implant/setGainMatrix", this));
	addGuidance("Load segmented PMT anode gain matrix file");
	
	addCommand(new G4UIcmdWithAString("/nDet/implant/addGreaseLayer", this));
	addGuidance("Add a layer of optical grease (all units in mm). SYNTAX: addGreaseLayer <width> <height> [thickness]");	

	addCommand(new G4UIcmdWithAString("/nDet/implant/addDiffuserLayer", this));
	addGuidance("Add a straight diffuser to the assembly (all units in mm). SYNTAX: addDiffuserLayer <width> <height> <thickness> [material=G4_SILICON_DIOXIDE]");	

	addCommand(new G4UIcmdWithAString("/nDet/implant/addLightGuide", this));
	addGuidance("Add a trapezoidal light-guide to the assembly (all units in mm). SYNTAX: addLightGuide <width1> <width2> <height1> <height2> <thickness> [material=G4_SILICON_DIOXIDE]");	

	addCommand(new G4UIcmdWithAString("/nDet/implant/loadLightGuide", this));
	addGuidance("Load a light-guide from a GDML geometry file. SYNTAX: loadLightGuide <filename> <rotX> <rotY> <rotZ> <matString>");

	addCommand(new G4UIcmdWithoutParameter("/nDet/implant/clear", this));
	addGuidance("Clear all implant Geometry");
	
	addCommand(new G4UIcmdWithAString("/nDet/implant/addArray", this));
	addGuidance("Add an array of multiple implants. SYNTAX: addArray <geom> <r0> <startTheta> <stopTheta> <Ndet>");

	addCommand(new G4UIcmdWithoutParameter("/nDet/implant/printAll", this));
	addGuidance("Print construction parameters for all defined implants");

}

void nDetConstructionMessenger::SetNewChildValue(G4UIcommand* command, G4String newValue){
	size_t index;
	if(!findCommand(command, newValue, index)) return;

	if(index == 0){
		fDetector->AddGeometry(newValue);
	}
	else if(index == 1){
		fDetector->UpdateGeometry();
	}	
	else if(index == 2){
		fDetector->setPmtSpectralResponse(newValue.c_str());
	}
	else if(index == 3){
		fDetector->setPmtGainMatrix(newValue.c_str());
	}
	else if(index == 4){
		fDetector->AddGrease(newValue);
	}
	else if(index == 5){
		fDetector->AddDiffuser(newValue);
	}
	else if(index == 6){
		fDetector->AddLightGuide(newValue);
	}
	else if(index == 7){
		fDetector->AddLightGuideGDML(newValue);
	}
	else if(index == 8){
		fDetector->ClearGeometry();
	}
	else if(index == 9){
		fDetector->AddDetectorArray(newValue);
	}
	else if(index == 10){
		fDetector->PrintAllDetectors();
	}
	else{ // Digitizer command
		pmtResponse *prL = fDetector->GetPmtResponseL();
		pmtResponse *prR = fDetector->GetPmtResponseR();
		index = index - 11;
		if(index == 0){
			G4double val = command->ConvertToDouble(newValue);
			prL->setRisetime(val);
			prR->setRisetime(val);
		}
		else if(index == 1){
			G4double val = command->ConvertToDouble(newValue);
			prL->setFalltime(val);
			prR->setFalltime(val);
		}
		else if(index == 2){
			G4double val = command->ConvertToDouble(newValue);
			prL->setGain(val);
			prR->setGain(val);
		}
		else if(index == 3){
			G4double val = command->ConvertToDouble(newValue);
			prL->setBaselinePercentage(val);
			prR->setBaselinePercentage(val);
		}
		else if(index == 4){
			G4double val = command->ConvertToDouble(newValue);
			prL->setBaselineJitterPercentage(val);
			prR->setBaselineJitterPercentage(val);
		}
		else if(index == 5){
			G4double val = command->ConvertToDouble(newValue);
			prL->setPolyCfdFraction(val);
			prR->setPolyCfdFraction(val);
		}
		else if(index == 6){
			G4double val = command->ConvertToDouble(newValue);
			prL->setTraceDelay(val);
			prR->setTraceDelay(val);
		}
		else if(index == 7){
			G4double val = command->ConvertToDouble(newValue);
			prL->setPulseLengthInNanoSeconds(val);
			prR->setPulseLengthInNanoSeconds(val);
		}
		else if(index == 8){
			G4double val = command->ConvertToDouble(newValue);
			prL->setTransitTimeSpread(val);
			prR->setTransitTimeSpread(val);
		}
		else if(index == 9){
			G4int val = command->ConvertToInt(newValue);
			prL->setPulseIntegralLow(val);
		}
		else if(index == 10){
			G4int val = command->ConvertToInt(newValue);
			prL->setPulseIntegralHigh(val);
			prR->setPulseIntegralHigh(val);
		}
		else if(index == 11){
			G4int val = command->ConvertToInt(newValue);
			prL->setBitRange(val);
			prR->setBitRange(val);
		}
		else if(index == 12){
			if(newValue == "expo" || newValue == "0"){
				prL->setFunctionType(pmtResponse::EXPO);
				prR->setFunctionType(pmtResponse::EXPO);
			}
			else if(newValue == "vandle" || newValue == "1"){
				prL->setFunctionType(pmtResponse::VANDLE);
				prR->setFunctionType(pmtResponse::VANDLE);
			}
			else if(newValue == "gauss" || newValue == "0"){
				prL->setFunctionType(pmtResponse::GAUSS);
				prR->setFunctionType(pmtResponse::GAUSS);
			}
		}
		else if(index == 13){
			G4double val = command->ConvertToDouble(newValue);
			prL->setAdcClockInNanoseconds(val);
			prR->setAdcClockInNanoseconds(val);
		}
		else if(index == 14){
			G4double val = command->ConvertToDouble(newValue);
			prL->setAdcClockFrequency(val);
			prR->setAdcClockFrequency(val);
		}
		else if(index == 15){
			prL->setPrintTrace((newValue == "true") ? true : false);
			prR->setPrintTrace((newValue == "true") ? true : false);
		}
		else if(index == 16){
			prL->print(); // Only show the left side, because they're both the same
		}
		
		//Implant commands
		else if(index == 17){
			fDetector->AddImplantGeometry(newValue);
		}
		else if(index == 18){
			fDetector->UpdateGeometry();
		}	
		else if(index == 19){
			fDetector->setPmtSpectralResponse(newValue.c_str());
		}
		else if(index == 20){
			fDetector->setPmtGainMatrix(newValue.c_str());
		}
		else if(index == 21){
			fDetector->AddGrease(newValue);
		}
		else if(index == 22){
			fDetector->AddDiffuser(newValue);
		}
		else if(index == 23){
			fDetector->AddLightGuide(newValue);
		}
		else if(index == 24){
			fDetector->AddLightGuideGDML(newValue);
		}
		else if(index == 25){
			fDetector->ClearGeometry();
		}
		else if(index == 26){
			fDetector->AddDetectorArray(newValue);
		}
		else if(index == 27){
			fDetector->PrintAllDetectors();
		}
	}
}
