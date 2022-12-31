

/*
 * Relay.c
 *
 * Created: 12/22/2022 9:26:08 AM
 *  Author: oem
 */ 

#include "DIO.h"
#include "Relay.h"
void Relay_Init(){
		DIO_vsetPINDir('C',RelayPin,1);
}
void Relay_On(){
	DIO_write('C',RelayPin,1);
}
void Relay_Off(){
	DIO_write('C',RelayPin,0);
}