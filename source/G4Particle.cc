//This file is based off of  G4Alpha.cc for creating any particle for implantation
#include "G4Particle.hh"
#include "G4SystemOfUnits.hh"
#include "G4ParticleTable.hh"

// ######################################################################
// ###                           PARTICLE                             ###
// ######################################################################

G4Particle* G4Particle::theInstance = 0;

G4Particle* G4Particle::Definition(){
   if (theInstance !=0) return theInstance;
   const G4String name = "particle";
   // search in particle table]
  G4ParticleTable* pTable = G4ParticleTable::GetParticleTable();
   G4Ions* anInstance = reinterpret_cast<G4Ions*>(pTable->FindParticle(name));
   if (anInstance ==0)
   {
 	// create particle
 	//
 	//    Arguments for constructor are as follows
 	//               name             mass          width         charge
 	//             2*spin           parity  C-conjugation
 	//          2*Isospin       2*Isospin3       G-parity
 	//               type    lepton number  baryon number   PDG encoding
 	//             stable         lifetime    decay table
 	//             shortlived      subType    anti_encoding
 	//             excitation
 	 anInstance = new G4Ions(
 		                    name,    3.727379*GeV,       0.0*MeV,  +2.0*eplus,
 		                       0,              +1,             0,
 		                       0,               0,             0,
 		               "nucleus",               0,            +4,  1000020040,
 		                    true,            -1.0,          NULL,
 		                    false,       "static",   -1000020040, 
 		                    0.0
 		                  );
 	
 	}
 	
	theInstance = reinterpret_cast<G4Particle*>(anInstance);
   	return theInstance;
 }
 
 G4Particle*  G4Particle::AlphaDefinition()
{
   return Definition();
 }
 
 G4Particle*  G4Particle::Alpha()
{
   if (theInstance !=0) return theInstance
	   
	   return Definition();
}
		
		
