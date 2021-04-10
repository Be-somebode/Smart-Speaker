#include <wiringPi.h>
#include <wiringPiI2C.h>
#include "ads1115.h"

/* ADS1115 analogRead function
*===================================*/

static int myAnalogRead(struct wiringPiNodeStruct *node, int pin) {
  int chan = pin - node->pinBase;
  int data[2];
  int value;

  // Start with default values
  int config = ADS1015_REG_CONFIG_CQUE_NONE    | // Disable the comparator (default val)
                    ADS1015_REG_CONFIG_CLAT_NONLAT  | // Non-latching (default val)
                    ADS1015_REG_CONFIG_CPOL_ACTVLOW | // Alert/Rdy active low   (default val)
                    ADS1015_REG_CONFIG_CMODE_TRAD   | // Traditional comparator (default val)
                    ADS1115_REG_CONFIG_DR_860SPS   | // 860 samples per second (max)
                    ADS1015_REG_CONFIG_MODE_SINGLE;   // Single-shot mode (default)
                    //ADS1015_REG_CONFIG_MODE_CONTIN;   // Continuous mode (doesn't work with more than one channel)
  // Set PGA/voltage range
  config |= ADS1015_REG_CONFIG_PGA_4_096V;

  // Set single-ended input chan
  switch (chan)
  {
    case (0):
      config |= ADS1015_REG_CONFIG_MUX_SINGLE_0;
      break;
    case (1):
      config |= ADS1015_REG_CONFIG_MUX_SINGLE_1;
      break;
    case (2):
      config |= ADS1015_REG_CONFIG_MUX_SINGLE_2;
      break;
    case (3):
      config |= ADS1015_REG_CONFIG_MUX_SINGLE_3;
      break;
  }

  // Set 'start single-conversion' bit
  config |= ADS1015_REG_CONFIG_OS_SINGLE;
  
  // Sent the config data in the right order
  config = ((config >> 8) & 0x00FF) | ((config << 8) & 0xFF00);
  wiringPiI2CWriteReg16(node->fd, ADS1015_REG_POINTER_CONFIG, config);
 
  // Wait for conversion to complete
  delay(2); // (1/SPS rounded up)

  wiringPiI2CWrite(node->fd, ADS1015_REG_POINTER_CONVERT);
  data[0] = wiringPiI2CRead(node->fd);
  data[1] = wiringPiI2CRead(node->fd);
  value = ((data[0] << 8) & 0xFF00) | data[1];

  // wiringPi doesn't include stdint so everything is an int (int32), this should account for this
  if (value > 0x7FFF) {
    return (value - 0xFFFF);
  } else {
    return value;
  }
}

/* ADS1115 ADC setup:
 *    create ADS1115 device.
 *    id is the address of the chip (0x48 default)
*===============================================*/

int ads1115Setup(const int pinBase, int id) {
  struct wiringPiNodeStruct *node;

  node = wiringPiNewNode(pinBase,4);

  node->fd = wiringPiI2CSetup(id);
  node->analogRead = myAnalogRead;

  if (node->fd < 0) {
    return -1;
  } else {
    return 0;
  }
}
