/*
*
* Copyright (C) Patryk Jaworski <regalis@regalis.com.pl>
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program. If not, see <http://www.gnu.org/licenses/>.
*
*/
#include <stm32f4xx.h>
 
#define LED_PIN 5
#define LED_ON() GPIOA->BSRR |= (1 << 5)
#define LED_OFF() GPIOA->BSRR |= (1 << 5)
 
int main() {
	/* Enbale GPIOA clock */
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
	/* Configure GPIOA pin 5 as output */
	GPIOA->MODER |= (1 << (LED_PIN << 1));
	/* Configure GPIOA pin 5 in max speed */
	GPIOA->OSPEEDR |= (3 << (LED_PIN << 1));
    
	/* Turn on the LED */
	LED_ON();

    return 0;
}

/*
  Compile Commnad 
  /home/ery/dev/STM32F4/STM32Cube_FW_F4_V1.7.0/Drivers/CMSIS/Device/ST/STM32F4xx/Include
  /home/ery/dev/STM32F4/STM32Cube_FW_F4_V1.7.0/Drivers/CMSIS/Include

For STM32F411xE  
  arm-none-eabi-gcc -Wall -mcpu=cortex-m4 -mlittle-endian -mthumb -I/home/ery/dev/STM32F4/STM32Cube_FW_F4_V1.7.0/Drivers/CMSIS/Device/ST/STM32F4xx/Include -I/home/ery/dev/STM32F4/STM32Cube_FW_F4_V1.7.0/Drivers/CMSIS/Include -DSTM32F411xE -O1 -c system.c -o system.o

For STM32F401xE
  arm-none-eabi-gcc -Wall -mcpu=cortex-m4 -mlittle-endian -mthumb -I/home/ery/dev/STM32F4/STM32Cube_FW_F4_V1.7.0/Drivers/CMSIS/Device/ST/STM32F4xx/Include -I/home/ery/dev/STM32F4/STM32Cube_FW_F4_V1.7.0/Drivers/CMSIS/Include -DSTM32F401xE -Os -c system.c -o system.o


  
  スタートアップファイルはGCCバージョンのものを使わないとGCCでコンパイルできない。シンボルエラー？になる

  Link Command for STM32F411xE
  arm-none-eabi-gcc -mcpu=cortex-m4 -mlittle-endian -mthumb -DSTM32F411xE -TSTM32F411RE_FLASH.ld -Wl,--gc-sections system.o main.o startup_stm32f411xe.o -o main.elf

For STM32F401xE
arm-none-eabi-gcc -mcpu=cortex-m4 -mlittle-endian -mthumb -DSTM32F401xE -TSTM32F401CE_FLASH.ld -Wl,--gc-sections system.o main.o startup_stm32f401xe.o -o main.elf

arm-none-eabi-objcopy -Oihex main.elf main.hex
  

重要！！！！
Toolchainに
arm-linux-gnueabi-
を使うと、__libc_init_arrayでレファレンスエラーが出る
しかし、
arm-none-eabi-
のツールチェインならば、出ない
arm-none-eabi-
を使用すべし！！！



 */
