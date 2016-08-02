// ALA library from https://github.com/bportaluri/ALA/tree/master/src
#include "ALA-master\src\AlaLed.h"
// Button library from https://github.com/tigoe/Button
#include "Button-master\Button.h"

AlaLed frontLights;
AlaLed backLights;
AlaLed ambientLights;

byte mainLightPins[] = { 5 };
byte backLightPins[] = { 6, 9 };
byte ambiLightPins[] = { 10 };


Button mainLightsButton = Button( 2, BUTTON_PULLUP );
Button ambiLightsButton = Button( 3, BUTTON_PULLUP );

bool mainLightsState = false;
bool ambiLightsState = false;

void setup() {
  frontLights.initPWM( 1, mainLightPins );
  backLights.initPWM( 2, backLightPins );
  ambientLights.initPWM( 1, ambiLightPins );

  frontLights.setAnimation( ALA_ON, 300 );
  backLights.setAnimation( ALA_BLINKALT, 300 );
  ambientLights.setAnimation( ALA_GLOW, 5000 );
}

void loop() {
  if( mainLightsButton.uniquePress( ) ) {
    if( mainLightsState ) {
      frontLights.setAnimation( ALA_FADEOUT, 1000 );
      backLights.setAnimation( ALA_FADEOUT, 1000 );
      mainLightsState = false;
    }
    else {
      frontLights.setAnimation( ALA_FADEIN, 300 );
      backLights.setAnimation( ALA_BLINKALT, 300 );
      mainLightsState = true;
    }
  }
  if( ambiLightsButton.uniquePress( ) ) {
    if( ambiLightsState ) ambientLights.setAnimation( ALA_FADEOUT, 1000 );
    else ambientLights.setAnimation( ALA_FADEIN, 300 );
    ambiLightsState = !ambiLightsState;
  }
  
  frontLights.runAnimation( );
  backLights.runAnimation( );
  ambientLights.runAnimation( );
}
