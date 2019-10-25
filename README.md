# CurrentMonitor Project

Driver class for calculating Irms from the ADC128S102 analog to digital chip

## Usage

Connect ADC128S102 hardware as per the datasheet (See Documentation section for link), add the CurrentMonitor project to your library,
include CurrentMonitor.h to your project.

```
#include "CurrentMonitor.h"
CurrentMonitor monitor;

void setup() {
  monitor.begin();
}

void loop() {
  double Irms = monitor.processAdc(0); // change to any channel from 0-7
  Serial.println(Irms);
}
```

## Documentation

`ADC128S102` Datasheet

http://www.ti.com/lit/ds/symlink/adc128s102.pdf

## LICENSE
Copyright 2019 Bachta

This project is licensed under the MIT license - see the [LICENSE.md](LICENSE.md) file for details