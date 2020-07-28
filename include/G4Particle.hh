//This file uses the G4Alpha.hh template for any ion to be include and used for implantation
#ifndef G4Particle_h
#define G4Particle_h 1

#include "globals.hh"
#include "G4ios.hh"
#include "G4ParticleDefinition.hh"
#include "G4Ions.hh"

// ######################################################################
// ###                          PARTICLE                              ###
// ######################################################################

class G4Particle : public G4Ions
	{
		private:
			static G4Particle* theInstance;
  		        G4Particle(){}
  		        ~G4Particle(){}
		public:
  		        static G4Particle* Definition();
  		        static G4Particle* ParticleDefinition();
  		        static G4Particle* Particle();
 	};

#endif
