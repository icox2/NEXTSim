#ifndef PARTICLE_SOURCE_MESSENGER_HH
#define PARTICLE_SOURCE_MESSENGER_HH

#include "ParticleSource.hh"
#include "messengerHandler.hh"

class ParticleSourceMessenger: public messengerHandler {
  public:
	ParticleSourceMessenger() : messengerHandler("particleSourceMessenger"), fAction(NULL) { addAllCommands(); }

	ParticleSourceMessenger(ParticleSource* Gun) : messengerHandler("particleSourceMessenger"), fAction(Gun) { addAllCommands(); }
	
	virtual void SetNewChildValue(G4UIcommand* command, G4String newValue);

  private:
	ParticleSource* fAction; ///< Pointer to the particle source object for which this messenger is defined
	
	void addAllCommands();
};

#endif
