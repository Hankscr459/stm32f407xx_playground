/*
 * stm32f407xx_gpio_driver.h
 *
 *  Created on: 2026年4月2日
 *      Author: Hank
 */

#ifndef INC_STM32F407XX_GPIO_DRIVER_H_
#define INC_STM32F407XX_GPIO_DRIVER_H_

#include "stm32f407xx.h"

/*
 * This is Configuration structure for a GPIO pin
 */
typedef struct
{
	uint8_t GPIO_PinNumber;           /*!< possible values from @GPIO_PIN_Number                       >*/
	uint8_t GPIO_PinMode;             /*!< possible values from @GPIO_PIN_MODES                        >*/
	uint8_t GPIO_PinSpeed;            /*!< possible values from @GPIO_PIN_SPEED                        >*/
	uint8_t GPIO_PinPuPdControl;      /*!< possible values from @GPIO_PIN_PULL_UP_PULL_DOWN_CONTROL    >*/
	uint8_t GPIO_PinOPType;           /*!< possible values from @GPIO_PIN_OUT_PUT_TYPE                 >*/
	uint8_t GPIO_PinAltFunMode;       /*!< possible values from @GPIO_PIN_ALT_FUNCTION_MODE            >*/
} GPIO_PinConfig_t;

/*
 * @GPIO_PIN_Number
 * GPIO pin numbers
 */
#define GPIO_PIN_NO_0    0
#define GPIO_PIN_NO_1    1
#define GPIO_PIN_NO_2    2
#define GPIO_PIN_NO_3    3
#define GPIO_PIN_NO_4    4
#define GPIO_PIN_NO_5    5
#define GPIO_PIN_NO_6    6
#define GPIO_PIN_NO_7    7
#define GPIO_PIN_NO_8    8
#define GPIO_PIN_NO_9    9
#define GPIO_PIN_NO_10   10
#define GPIO_PIN_NO_11   11
#define GPIO_PIN_NO_12   12
#define GPIO_PIN_NO_13   13
#define GPIO_PIN_NO_14   14
#define GPIO_PIN_NO_15   15


/*
 * @GPIO_PIN_MODES
 * GPIO pin possible modes
 */
#define GPIO_MODE_IN         0
#define GPIO_MODE_OUT        1
#define GPIO_MODE_ALTFN      2
#define GPIO_MODE_ANALOG     3
#define GPIO_MODE_IT_FT      4       /*!< IT stands for input falling edge          >*/
#define GPIO_MODE_IT_RT      5       /*!< IT stands for input raising edge          >*/
#define GPIO_MODE_IT_RFT     6       /*!< IT stands for input raising, falling edge >*/


/*
 * @GPIO_PIN_OUT_PUT_TYPE
 * GPIO pin possible output types
 */
#define GPIO_OP_TYPE_PP     0 /*!< push-pull(reset state)    >*/
#define GPIO_OP_TYPE_OD     1 /*!< open-drain   >*/


/*
 * @GPIO_PIN_SPEED
 * GPIO pin possible output speeds
 */
#define GPIO_SPEED_LOW        0
#define GPIO_SPEED_MEDIUM     1
#define GPIO_SPEED_FAST       2
#define GPIO_SPEED_HIGH       3


/*
 * @GPIO_PIN_PULL_UP_PULL_DOWN_CONTROL
 * GPIO pin pull up And pull down configuration macros
 */
#define GPIO_NO_PUPD      0   /*!< no pull-up, no pull-down >*/
#define GPIO_PIN_PU       1   /*!< pull-up                  >*/
#define GPIO_PIN_PD       2   /*!< pull-down                >*/

/*
 * This is a Handle structure for a GPIO pin
 */
typedef struct
{
	GPIO_RegDef_t      *pGPIOx;              /*!< This holds the base address of the GPIO port to which the pin belongs >*/
	GPIO_PinConfig_t   GPIO_PinConfig;       /*!< This holds GPIO pin configuration settings >*/
} GPIO_Handle_t;



/********************************************************************************************
 *                       APIs supported by this driver
 *        For more information about the APIs check the function definitions
 ********************************************************************************************/

/*
 * Peripheral Clock setup
 */
void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnOrDi);

/*
 * Init and De-init
 */
void GPIO_Init(GPIO_Handle_t *pGPIOHandle);
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx);

/*
 * Data read and write
 */
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *GPIOx, uint8_t PinNumber);
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *GPIOx);
void GPIO_WriteToOutputPin(GPIO_RegDef_t *GPIOx, uint8_t PinNumber, uint8_t Value);
void GPIO_WriteToOutputPort(GPIO_RegDef_t *GPIOx, uint16_t Value);
void GPIO_ToggleOutputPin(GPIO_RegDef_t *GPIOx, uint8_t PinNumber);

/*
 * IRQ Configuration and ISR handling
 */
void GPIO_IRQInterruptConfig(uint8_t IQRNumber, uint8_t EnOrDi);
void GPIO_IRQPriorityConfig(uint8_t IRQNumber, uint32_t IRQPriority);
void GPIO_IRQHandling(uint8_t PinNumber);

#endif /* INC_STM32F407XX_GPIO_DRIVER_H_ */
