1. Write firmware hex first, using a STK500 programmer via AVR Studio
2. Write fuses lfuse:w:0xdf:m -U hfuse:w:0x5f:m

After writing the fuses, the SPI programming is disabled, ic can no longer be programmed via a standard programmer