/*
    ChibiOS/RT - Copyright (C) 2006,2007,2008,2009,2010,
                 2011,2012 Giovanni Di Sirio.

    This file is part of ChibiOS/RT.

    ChibiOS/RT is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 3 of the License, or
    (at your option) any later version.

    ChibiOS/RT is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "ch.h"
#include "hal.h"
#include "test.h"
#include "chprintf.h"

/*
 * PIN Definition for each PWM motors direction.
 * PWM4, UP direction: PORTD.
 * PWM4, DOWN direction: PORTB.
 * PWM3, UP direction: PORTB.
 * PWM3, DOWN direction: PORTC.
 */

/* */
#define PWM4_0_UP     12
#define PWM4_0_DOWN   6
#define PWM4_1_UP     13
#define PWM4_1_DOWN   7
#define PWM4_2_UP     14
#define PWM4_2_DOWN   8
#define PWM4_3_UP     15
#define PWM4_3_DOWN   9
#define PWM3_2_UP     0
#define PWM3_2_DOWN   8
#define PWM3_3_UP     1
#define PWM3_3_DOWN   9

static uint8_t flag = 0;
static uint8_t uartin[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

void uartfun(UARTDriver *uartp, uint16_t c) {
  (void) uartp;
  if(flag < 7) {
      
    uartin[flag] = c;
    flag ++;
    
  }
}

static const UARTConfig UARTpcfg = {
  NULL,
  NULL,
  NULL,
  uartfun,
  NULL,
  /* HW dependent part.*/
  115200,
  0,
  0,
  0
};

static const SerialConfig Serialcfg = {
	38400,
	0,
	0,
	0,
};

/*
 * PWM configuration structure.
 * Cyclic callback disabled, channels 1 to 4 enabled without callbacks,
 * the active state is a logic one.
 */
static PWMConfig pwmcfga = {
  100000,                              /* 10kHz PWM clock frequency.   */
  100,                                 /* PWM period (in ticks).    */
  NULL,
  {
    {PWM_OUTPUT_ACTIVE_HIGH, NULL},
    {PWM_OUTPUT_ACTIVE_HIGH, NULL},
    {PWM_OUTPUT_ACTIVE_HIGH, NULL},
    {PWM_OUTPUT_ACTIVE_HIGH, NULL}
  },
  /* HW dependent part.*/
  0
};

/*
 * PWM configuration structure.
 * Cyclic callback disabled, channels 1 to 4 enabled without callbacks,
 * the active state is a logic one.
 */
static PWMConfig pwmcfgb = {
  100000,                              /* 10kHz PWM clock frequency.   */
  100,                                 /* PWM period (in ticks).    */
  NULL,
  {
    {PWM_OUTPUT_ACTIVE_HIGH, NULL},
    {PWM_OUTPUT_ACTIVE_HIGH, NULL},
    {PWM_OUTPUT_ACTIVE_HIGH, NULL},
    {PWM_OUTPUT_ACTIVE_HIGH, NULL}
  },
  /* HW dependent part.*/
  0
};

/*
 * GPT callback for safe shutdown.
 */
static void gpt2cb(GPTDriver *gptp) {

  (void)gptp;
  pwmEnableChannel(&PWMD4, 0, 0);
  pwmEnableChannel(&PWMD4, 1, 0);
  pwmEnableChannel(&PWMD4, 2, 0);
  pwmEnableChannel(&PWMD4, 3, 0);
  pwmEnableChannel(&PWMD3, 2, 0);
  pwmEnableChannel(&PWMD3, 3, 0);
  //chprintf((BaseSequentialStream *)&SD5, "%s", "EMERGENCY SHUTDOWN");      
}

/*
 * GPT2 configuration.
 */
static const GPTConfig gpt2cfg = {
  10000,    /* 10kHz timer clock.*/
  gpt2cb    /* Timer callback.*/
};

/*
 * Application entry point.
 */
int main(void) {
  
  uint32_t pwmv[6] = {0,0,0,0,0,0};
  uint8_t pwmd[6] = {0,0,0,0,0,0};

  /*
   * System initializations.
   * - HAL initialization, this also initializes the configured device drivers
   *   and performs the board-specific initializations.
   * - Kernel initialization, the main() function becomes a thread and the
   *   RTOS is active.
   */
  halInit();
  chSysInit();

  /*
   * Activates the serial driver 2 using the driver default configuration.
   * PA2(TX) and PA3(RX) are routed to USART2.
   */
  uartStart(&UARTD2,&UARTpcfg);
  palSetPadMode(GPIOA, 2, PAL_MODE_ALTERNATE(7));
  palSetPadMode(GPIOA, 3, PAL_MODE_ALTERNATE(7));

  sdStart(&SD5,&Serialcfg);
  palSetPadMode(GPIOC, 12, PAL_MODE_ALTERNATE(8));
  palSetPadMode(GPIOD, 2, PAL_MODE_ALTERNATE(8));
  
  /*
   * Initializes the PWM driver 4.
   */
  pwmStart(&PWMD4, &pwmcfga);
  pwmStart(&PWMD3, &pwmcfgb);
  
  /*
  * Initializes the GPT drivers 2.
  */
  gptStart(&GPTD2, &gpt2cfg);
  
  /*
   * Normal main() thread activity, in this demo it does nothing except
   * sleeping in a loop and check the button state, when the button is
   * pressed the test procedure is launched with output on the serial
   * driver 2.
   */
    
  flag = 0;

  chprintf((BaseSequentialStream *)&SD5, "%s", "Start up");
  
  
  while (TRUE) { 
	/*
    * UART input value review to change PW value.
    */
    if(flag == 7) {

      /* Stop failsafe mechanism. */
      gptStopTimer(&GPTD2);
      
      /* Data Verification. */
      if(uartin[0] == 's') {
      
	/*
	* PWM4, channel 0 data processing, Motor 1.
	*/
	//----------Out of bounds condition
	if((uartin[1] < 50) | (uartin[1] > 251)) {
	  
	  pwmv[0] = 0;
	  pwmd[0] = 0;
	  
	}
	else if(uartin[1] >= 151) {
	//---------Positive Direction
	  
	  pwmv[0] = (double)((uartin[1]-151)*100);
	  pwmd[0] = 1;
	    
	}
	else if (uartin[1] <= 150) {
	//---------Negative Direction
	  
	  pwmv[0] = (double)((uartin[1]-50)*100);
	  pwmd[0] = 0;
	}

	/*
	* PWM4, channel 1 data processing, Motor 2.
	*/
	if((uartin[2] < 50) | (uartin[2] > 251)) {
	  
	  pwmv[1] = 0;
	  pwmd[1] = 0;
	  
	}
	else if(uartin[2] >= 151) {
	  
	  pwmv[1] = (double)((uartin[2]-151)*100);
	  pwmd[1] = 1;
	    
	}
	else if (uartin[2] <= 150) {
	  
	  pwmv[1] = (double)((uartin[2]-50)*100);
	  pwmd[1] = 0;
	}
	
	/*
	* PWM4, channel 2 data processing, Motor 3.
	*/
	if((uartin[3] < 50) | (uartin[3] > 251)) {
	  
	  pwmv[2] = 0;
	  pwmd[2] = 0;
	  
	}
	else if(uartin[3] >= 151) {
	  
	  pwmv[2] = (double)((uartin[3]-151)*100);
	  pwmd[2] = 1;
	  
	}
	else if (uartin[3] <= 150) {
	  
	  pwmv[2] = (double)((uartin[3]-50)*100);
	  pwmd[2] = 0;
	}
	
	/*
	* PWM4, channel 3 data processing, Motor 4.
	*/
	if((uartin[4] < 50) | (uartin[4] > 251)) {
	  
	  pwmv[3] = 0;
	  pwmd[3] = 0;
	  
	}
	else if(uartin[4] >= 151) {
	  
	  pwmv[3] = (double)((uartin[4]-151)*100);
	  pwmd[3] = 1;
	    
	}
	else if (uartin[4] <= 150) {
	  
	  pwmv[3] = (double)((uartin[4]-50)*100);
	  pwmd[3] = 0;
	}
	
	/*
	* PWM3, channel 2 data processing, Motor 5.
	*/
	if((uartin[5] < 50) | (uartin[5] > 251)) {
	  
	  pwmv[4] = 0;
	  pwmd[4] = 0;
	  
	}
	else if(uartin[5] >= 151) {
	  
	  pwmv[4] = (double)((uartin[5]-151)*100);
	  pwmd[4] = 1;
	    
	}
	else if (uartin[5] <= 150) {
	  
	  pwmv[4] = (double)((uartin[5]-50)*100);
	  pwmd[4] = 0;
	}
	
	/*
	* PWM3, channel 3 data processing, Motor 6.
	*/
	if((uartin[6] < 50) | (uartin[6] > 251)) {
	  
	  pwmv[5] = 0;
	  pwmd[5] = 0;
	  
	}
	else if(uartin[6] >= 151) {
	  
	  pwmv[5] = (double)((uartin[6]-151)*100);
	  pwmd[5] = 1;
	    
	}
	else if (uartin[6] <= 150) {
	  
	  pwmv[5] = (double)((uartin[6]-50)*100);
	  pwmd[5] = 0;
	}
	
      }      

      /*
      * PWM4, channel 0 pulse width and orientation change, Motor 1.
      */
      if (pwmd[0] == 0) {
	pwmDisableChannel(&PWMD4,0);
	palSetPadMode(GPIOB, PWM4_0_DOWN, PAL_MODE_OUTPUT_PUSHPULL);
	palClearPad(GPIOB, PWM4_0_DOWN);
	palSetPadMode(GPIOD, PWM4_0_UP, PAL_MODE_ALTERNATE(2));
	pwmEnableChannel(&PWMD4, 0, PWM_PERCENTAGE_TO_WIDTH(&PWMD4, pwmv[0]));
      }
      else if(pwmd[0] == 1){
	pwmDisableChannel(&PWMD4,0);
	palSetPadMode(GPIOD, PWM4_0_UP, PAL_MODE_OUTPUT_PUSHPULL);
	palClearPad(GPIOD, PWM4_0_UP);
	palSetPadMode(GPIOB, PWM4_0_DOWN, PAL_MODE_ALTERNATE(2));
	pwmEnableChannel(&PWMD4, 0, PWM_PERCENTAGE_TO_WIDTH(&PWMD4, pwmv[0]));
      }
      
      /*
      * PWM4, channel 1 pulse width and orientation change, Motor 2.
      */
      if (pwmd[1] == 0) {
	pwmDisableChannel(&PWMD4,1);
	palSetPadMode(GPIOB, PWM4_1_DOWN, PAL_MODE_OUTPUT_PUSHPULL);
	palClearPad(GPIOB, PWM4_1_DOWN);
	palSetPadMode(GPIOD, PWM4_1_UP, PAL_MODE_ALTERNATE(2));
	pwmEnableChannel(&PWMD4, 1, PWM_PERCENTAGE_TO_WIDTH(&PWMD4, pwmv[1]));
      }
      else if(pwmd[1] == 1){
	pwmDisableChannel(&PWMD4,1);
	palSetPadMode(GPIOD, PWM4_1_UP, PAL_MODE_OUTPUT_PUSHPULL);
	palClearPad(GPIOD, PWM4_1_UP);
	palSetPadMode(GPIOB, PWM4_1_DOWN, PAL_MODE_ALTERNATE(2));
	pwmEnableChannel(&PWMD4, 1, PWM_PERCENTAGE_TO_WIDTH(&PWMD4, pwmv[1]));
      }
      
      /*
      * PWM4, channel 2 pulse width and orientation change, Motor 3.
      */
      if (pwmd[2] == 0) {
	pwmDisableChannel(&PWMD4,2);
	palSetPadMode(GPIOB, PWM4_2_DOWN, PAL_MODE_OUTPUT_PUSHPULL);
	palClearPad(GPIOB, PWM4_2_DOWN);
	palSetPadMode(GPIOD, PWM4_2_UP, PAL_MODE_ALTERNATE(2));
	pwmEnableChannel(&PWMD4, 2, PWM_PERCENTAGE_TO_WIDTH(&PWMD4, pwmv[2]));
      }
      else if(pwmd[2] == 1){
	pwmDisableChannel(&PWMD4,2);
	palSetPadMode(GPIOD, PWM4_2_UP, PAL_MODE_OUTPUT_PUSHPULL);
	palClearPad(GPIOD, PWM4_2_UP);
	palSetPadMode(GPIOB, PWM4_2_DOWN, PAL_MODE_ALTERNATE(2));
	pwmEnableChannel(&PWMD4, 2, PWM_PERCENTAGE_TO_WIDTH(&PWMD4, pwmv[2]));
      }
      
      /*
      * PWM4, channel 3 pulse width and orientation change, Motor 4.
      */
      if (pwmd[3] == 0) {
	pwmDisableChannel(&PWMD4,3);
	palSetPadMode(GPIOB, PWM4_3_DOWN, PAL_MODE_OUTPUT_PUSHPULL);
	palClearPad(GPIOB, PWM4_3_DOWN);
	palSetPadMode(GPIOD, PWM4_3_UP, PAL_MODE_ALTERNATE(2));
	pwmEnableChannel(&PWMD4, 3, PWM_PERCENTAGE_TO_WIDTH(&PWMD4, pwmv[3]));
      }
      else if(pwmd[3] == 1){
	pwmDisableChannel(&PWMD4,3);
	palSetPadMode(GPIOD, PWM4_3_UP, PAL_MODE_OUTPUT_PUSHPULL);
	palClearPad(GPIOD, PWM4_3_UP);
	palSetPadMode(GPIOB, PWM4_3_DOWN, PAL_MODE_ALTERNATE(2));
	pwmEnableChannel(&PWMD4, 3, PWM_PERCENTAGE_TO_WIDTH(&PWMD4, pwmv[3]));
      }
      
      /*
      * PWM3, channel 2 pulse width and orientation change, Motor 5.
      */
      if (pwmd[4] == 0) {
	pwmDisableChannel(&PWMD3,2);
	palSetPadMode(GPIOC, PWM3_2_DOWN, PAL_MODE_OUTPUT_PUSHPULL);
	palClearPad(GPIOC, PWM3_2_DOWN);
	palSetPadMode(GPIOB, PWM3_2_UP, PAL_MODE_ALTERNATE(2));
	pwmEnableChannel(&PWMD3, 2, PWM_PERCENTAGE_TO_WIDTH(&PWMD3, pwmv[4]));
      }
      else if(pwmd[4] == 1){
	pwmDisableChannel(&PWMD3,2);
	palSetPadMode(GPIOB, PWM3_2_UP, PAL_MODE_OUTPUT_PUSHPULL);
	palClearPad(GPIOB, PWM3_2_UP);
	palSetPadMode(GPIOC, PWM3_2_DOWN, PAL_MODE_ALTERNATE(2));
	pwmEnableChannel(&PWMD3, 2, PWM_PERCENTAGE_TO_WIDTH(&PWMD3, pwmv[4]));
      }
      
      /*
      * PWM3, channel 3 pulse width and orientation change, Motor 6.
      */
      if (pwmd[5] == 0) {
	pwmDisableChannel(&PWMD3,3);
	palSetPadMode(GPIOC, PWM3_3_DOWN, PAL_MODE_OUTPUT_PUSHPULL);
	palClearPad(GPIOC, PWM3_3_DOWN);
	palSetPadMode(GPIOB, PWM3_3_UP, PAL_MODE_ALTERNATE(2));
	pwmEnableChannel(&PWMD3, 3, PWM_PERCENTAGE_TO_WIDTH(&PWMD3, pwmv[5]));
      }
      else if(pwmd[5] == 1){
	pwmDisableChannel(&PWMD3,3);
	palSetPadMode(GPIOB, PWM3_3_UP, PAL_MODE_OUTPUT_PUSHPULL);
	palClearPad(GPIOB, PWM3_3_UP);
	palSetPadMode(GPIOC, PWM3_3_DOWN, PAL_MODE_ALTERNATE(2));
	pwmEnableChannel(&PWMD3, 3, PWM_PERCENTAGE_TO_WIDTH(&PWMD3, pwmv[5]));
      }
      /* Output the programmed velocities. */
      chprintf((BaseSequentialStream *)&SD5, "%U - %U - %U - %U - %U - %U", pwmv[0], pwmv[1], pwmv[2], pwmv[3], pwmv[4], pwmv[5]);
      /* Restart velocity commands reading from UART. */
      flag = 0;
      /* Start failsafe mechanism. */
      gptStart(&GPTD2, &gpt2cfg);
      gptStartOneShot(&GPTD2, 200);
    }
    
    chprintf((BaseSequentialStream *)&SD5, "%s", "Fuera");
    
  }
}
