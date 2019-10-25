#pragma once

/* CurrentMonitor library by Bachta
 */

// This will load the definition for common Particle variable types
#include "Particle.h"
#include "ADC128S102.h"

// This is your main class that users will import into their application
class CurrentMonitor
{
public:
  /**
   * Constructor
   */
  CurrentMonitor();

  /**
   * Example method
   */
  void begin();

  /**
   * Example method
   */
  double processAdc(uint8_t adcChannel);

private:

  ADC128S102 adc;

  int sampleI;
  double offsetI = 2050.0;
  double filteredI, sqI, sumI, Irms;
  double ICAL = 44.05;

  unsigned int numberOfSamples = 1480;
  
  double calculateIrms(uint8_t channel);
  long readVcc();
};
