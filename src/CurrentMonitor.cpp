/* CurrentMonitor library by Bachta
 */

#include "CurrentMonitor.h"

/**
 * Constructor.
 */
CurrentMonitor::CurrentMonitor()
{
  // be sure not to call anything that requires hardware be initialized here, put those in begin()
}

/**
 * Example method.
 */
void CurrentMonitor::begin()
{
    // initialize hardware
    adc.begin();
}

/**
 * Processes the given channel and returns the calculated Irms value.
 */
double CurrentMonitor::processAdc(uint8_t adcChannel)
{

    if(adcChannel < 0 || adcChannel > 7){
        return -1;
    }
    return calculateIrms(adcChannel);
}

/**
 * Private: Receives analog reading from given channel and calculates Irms.
 * The Irms is calculated from a numberOfSamples to receive a more accurate number
 */
double CurrentMonitor::calculateIrms(uint8_t channel)
{
    int SupplyVoltage = readVcc();


  for (unsigned int n = 0; n < numberOfSamples; n++)
  {
    sampleI = adc.readADC(channel);

    // Digital low pass filter extracts the 2.5 V or 1.65 V dc offset,
    //  then subtract this - signal is now centered on 0 counts.
    offsetI = (offsetI + (double)((double)(sampleI-offsetI))/1024);
    filteredI = sampleI - offsetI;

    // Root-mean-square method current
    // 1) square current values
    sqI = filteredI * filteredI;
    // 2) sum
    sumI += sqI;
  }

  double I_RATIO = ICAL *((SupplyVoltage/1000.0) / (ADC_COUNTS));
  Irms = I_RATIO * sqrt(sumI / numberOfSamples);

  //Reset accumulators
  sumI = 0;
  //--------------------------------------------------------------------------------------
  return Irms;
}

long CurrentMonitor::readVcc() {
  return (3300);
}