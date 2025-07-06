//*******************************************************************
/*!
\file   config.h
\author Thomas Breuer
\date   23.03.2023
\brief  Board specific configuration
*/

//*******************************************************************
/*
Board:    STM32L100-Discovery
*/

//*******************************************************************
#ifndef CONFIG_H
#define CONFIG_H

#include "Hardware/Peripheral/Display/DisplayChar_DIP204spi.cpp"

//*******************************************************************
using namespace EmbSysLib::Hw;
using namespace EmbSysLib::Dev;
using namespace EmbSysLib::Ctrl;
using namespace EmbSysLib::Mod;

//*******************************************************************
PinConfig::MAP PinConfig::table[] =
{
  // ADC
  ADC12_IN2_PA2,
  ADC12_IN3_PA3,

  // SPI
  SPI2_MOSI_PB15,
  SPI2_MISO_PB14,
  SPI2_SCK_PB13,
  SPI2_NSS_PB12,

  // UART
  USART1_TX_PA9,
  USART1_RX_PA10,

  END_OF_TABLE
};

//-------------------------------------------------------------------
// Timer
//-------------------------------------------------------------------
Timer_Mcu   timer( Timer_Mcu::TIM_10, 10000L/*us*/ );
TaskManager taskManager( timer );

//-------------------------------------------------------------------
// Port + Digital
//-------------------------------------------------------------------
Port_Mcu   portA( Port_Mcu::PA );
Port_Mcu   portB( Port_Mcu::PB );
Port_Mcu   portC( Port_Mcu::PC );
Port_Mcu   portD( Port_Mcu::PD );

Digital    led0    ( portC, 8, Digital::Out,  0 ); // LD4 (blue)
Digital    btnA    ( portA, 0, Digital::In,   0 ); // B1 (user button)
Digital    rotA    ( portA, 8, Digital::InPU, 1 );
Digital    rotB    ( portA, 1, Digital::InPU, 1 );
Digital    rotCtrl ( portA,15, Digital::InPU, 1 );

DigitalEncoderRotaryknob  enc( &rotA, &rotB, &rotCtrl, taskManager );

//-------------------------------------------------------------------
// UART
//-------------------------------------------------------------------
Uart_Mcu  uart    ( Uart_Mcu::USART_1, 9600, 100, 100 );
Terminal  terminal( uart, 255,255,"#", "!\r\n" );

//-------------------------------------------------------------------
// Display
//-------------------------------------------------------------------
SPImaster_Mcu         spi          ( SPImaster_Mcu::SPI_2, SPImaster_Mcu::CR_1000kHz, SPImaster_Mcu::CPOL_H_CPHA_H );
SPImaster::Device     spiDevDisplay( spi, portB, 12 );
DisplayChar_DIP204spi dispHw       ( spiDevDisplay );
ScreenChar            disp         ( dispHw );

//-------------------------------------------------------------------
// Sortiermaschine
//-------------------------------------------------------------------
Digital enable( portD, 2, Digital::Out, 1 );

// Tasten
Digital tasterUSER(portA,0, Digital::In, 0);
Digital tasterS1PC0(portC, 0, Digital::InPU, 1);
Digital tasterS2PC1(portC, 1, Digital::InPU, 1);
Digital tasterS2PC6(portC, 6, Digital::InPU, 1);
Digital tasterS2PC7(portC, 7, Digital::InPU, 1);

// Band
Digital  motor_Band_P( portB, 4, Digital::Out,  0 );
Digital  motor_Band_M( portB, 5, Digital::Out,  0 );
Digital inkremental_Band_P(portC, 2, Digital::InPU, 0);

// Kompressor
Digital ventil_Stapel_P(portB, 0, Digital::Out, 0);
Digital ventil_Auswurf(portB, 1, Digital::Out, 0);
Digital ventil_Verarbeitung_P(portB, 6, Digital::Out, 0);
Digital motor_Kompressor_P(portB, 8, Digital::Out, 0);
Digital signal_Druck(portA, 2, Digital::In, 0);

// Sensor
Digital signal_Farbe(portA, 2, Digital::In, 0);
Digital lichtschranke_Stapel_P(portA, 6, Digital::InPU, 0);
Digital lichtschranke_Verarb_P(portA, 7, Digital::InPU, 0);

Digital  endschalter_1( portA, 2, Digital::InPU, 0 );
Digital  increment_1  ( portA, 3, Digital::InPU, 0 );

#endif
