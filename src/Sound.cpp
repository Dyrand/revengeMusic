#include "Sound.h"

//constructor for sound class initialises FMOD
Sound::Sound(){

  // Create FMOD interface object and error check
  if( FMOD::System_Create( &m_pSystem) != FMOD_OK){

    std::cout<< "Could not create sound system." <<std::endl;
    return;
  }

  //gets all drivers for error checking
  int driverCount = 0;
  m_pSystem->getNumDrivers( &driverCount);

  if( driverCount == 0){

    std::cout<< "no sound driver was found" <<std::endl;
    return;
  }

  //system is initiallised with 10 channels for now
  m_pSystem->init( 10, FMOD_INIT_NORMAL, NULL);
}

//loads sound in path to memory
void Sound::createSound( const char *pFile) {

  m_pSystem->createStream( pFile, FMOD_DEFAULT, 0, &audio);
}

void Sound::playSound( bool bLoop = false){

      if ( !bLoop)
         audio->setMode(FMOD_LOOP_OFF);
      else{

         audio->setMode(FMOD_LOOP_NORMAL);
         audio->setLoopCount(-1);
      }

      m_pSystem->playSound( audio, 0, false, 0);
   }

   void Sound::releaseSound(){

      audio->release();
   }