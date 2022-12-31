 #ifndef AVR_ADC_H_
 #define AVR_ADC_H_
 
 #include <avr/io.h>
 #include "Datatypes.h"

 
 #define ADC0 0x00
 #define ADC1 0x01
 #define ADC2 0x02
 #define ADC3 0x03
 #define ADC4 0x04
 #define ADC5 0x05
 #define ADC6 0x06
 #define ADC7 0x07
 #define ADC8 0x08
 #define VBG  0x0E
 #define GND  0x0F
 #define ADC_PIN_MASK 0x0F
 #define ADC_VOLTAGE_REFERENCE_AREF (0<<REFS0)
 #define ADC_VOLTAGE_REFERENCE_AVCC (1<<REFS0)
 #define ADC_VOLTAGE_REFERENCE_IREF (1<<REFS1) | (1<<REFS0)
 #define ADC_VOLTAGE_REFERENCE_MASK (1<<REFS1) | (1<<REFS0)
 #define ADC_PRESCALER_2    (1<<ADPS0)
 #define ADC_PRESCALER_4    (1<<ADPS1)
 #define ADC_PRESCALER_8    (1<<ADPS1) | (1<<ADPS0)
 #define ADC_PRESCALER_16   (1<<ADPS2)
 #define ADC_PRESCALER_32   (1<<ADPS2) | (1<<ADPS0)
 #define ADC_PRESCALER_64   (1<<ADPS2) | (1<<ADPS1)
 #define ADC_PRESCALER_128  (1<<ADPS2) | (1<<ADPS1) | (1<<ADPS0)
 #define ADC_PRESCALER_MASK (1<<ADPS2) | (1<<ADPS1) | (1<<ADPS0)
 #define ADC_TEMP_TOS 0x01
 #define ADC_TEMP_K   0x01
 
 typedef struct ADC_ConfigData
 {
	 uint8_t VoltageReference;
	 uint8_t Prescaler;
 } ADC_ConfigData;
  void ADC_DisableInterrupt();
  void ADC_EnableInterrupt();
  void ADC_Init(ADC_ConfigData Data);
  void ADC_DeInit();
 uint16_t ADC_ReadPin(uint8_t Pin);
 uint16_t ADC_ReadTemperature();

 
 #endif /* AVR_ADC_H_ */