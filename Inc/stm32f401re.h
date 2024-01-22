/*
 * File: stm32f401re.h
 * Author: phamtien758
 * 
 */

#ifndef STM32F401RE_H
#define STM32F401RE_H

#include "type.h"

/*************************************************************
 *            Cortex-M4 Processor Peripheral
 *************************************************************/
/*
 * Definition of IRQ number
 */
typedef enum
{
    IRQ_NUM_WWDG               = 0,
    IRQ_NUM_EXTI16             = 1,
    IRQ_NUM_EXTI21             = 2,
    IRQ_NUM_EXTI22             = 3,
    IRQ_NUM_FLASH              = 4,
    IRQ_NUM_RCC                = 5,
    IRQ_NUM_EXTI0              = 6,
    IRQ_NUM_EXTI1              = 7,
    IRQ_NUM_EXTI2              = 8,
    IRQ_NUM_EXTI3              = 9,
    IRQ_NUM_EXTI4              = 10,
    IRQ_NUM_DMA1_0             = 11,
    IRQ_NUM_DMA1_1             = 12,
    IRQ_NUM_DMA1_2             = 13,
    IRQ_NUM_DMA1_3             = 14,
    IRQ_NUM_DMA1_4             = 15,
    IRQ_NUM_DMA1_5             = 16,
    IRQ_NUM_DMA1_6             = 17,
    IRQ_NUM_ADC                = 18,
    IRQ_NUM_EXTI9_5            = 23,
    IRQ_NUM_TIM1_BRK_TIM9      = 24,
    IRQ_NUM_TIM1_UP_TIM10      = 25,
    IRQ_NUM_TIM1_TRG_COM_TIM11 = 26,
    IRQ_NUM_TIM1_CC            = 27,
    IRQ_NUM_TIM2               = 28,
    IRQ_NUM_TIM3               = 29,
    IRQ_NUM_TIM4               = 30,
    IRQ_NUM_I2C1_EV            = 31,
    IRQ_NUM_I2C1_ER            = 32,
    IRQ_NUM_I2C2_EV            = 33,
    IRQ_NUM_I2C2_ER            = 34,
    IRQ_NUM_SPI1               = 35,
    IRQ_NUM_SPI2               = 36,
    IRQ_NUM_USART1             = 37,
    IRQ_NUM_USART2             = 38,
    IRQ_NUM_EXTI15_10          = 40,
    IRQ_NUM_EXTI17             = 41,
    IRQ_NUM_EXTI18             = 42,
    IRQ_NUM_DMA1_7             = 47,
    IRQ_NUM_SDIO               = 49,
    IRQ_NUM_TIM5               = 50,
    IRQ_NUM_SPI3               = 51,
    IRQ_NUM_DMA2_0             = 56,
    IRQ_NUM_DMA2_1             = 57,
    IRQ_NUM_DMA2_2             = 58,
    IRQ_NUM_DMA2_3             = 59,
    IRQ_NUM_DMA2_4             = 60,
    IRQ_NUM_OTG_FS             = 67,
    IRQ_NUM_DMA2_5             = 68,
    IRQ_NUM_DMA2_6             = 69,
    IRQ_NUM_DMA2_7             = 70,
    IRQ_NUM_USART6             = 71,
    IRQ_NUM_I2C3_EV            = 72,
    IRQ_NUM_I2C3_ER            = 73,
    IRQ_NUM_FPU                = 81,
    IRQ_NUM_SPI4               = 84
}Irq_Number;

/*
 * @Irq_Pri
 */
typedef enum
{
    IRQ_PRI_0  = 0,
    IRQ_PRI_1  = 1,
    IRQ_PRI_2  = 2,
    IRQ_PRI_3  = 3,
    IRQ_PRI_4  = 4,
    IRQ_PRI_5  = 5,
    IRQ_PRI_6  = 6,
    IRQ_PRI_7  = 7,
    IRQ_PRI_8  = 8,
    IRQ_PRI_9  = 9,
    IRQ_PRI_10 = 10,
    IRQ_PRI_11 = 11,
    IRQ_PRI_12 = 12,
    IRQ_PRI_13 = 13,
    IRQ_PRI_14 = 14,
    IRQ_PRI_15 = 15
}Irq_Pri;

/*
 * Definition of NVIC peripheral base address
 */
typedef struct
{
    _RW uint32_t ISER[8U];
        uint32_t RESERVED0[24U];
    _RW uint32_t ICER[8U];
        uint32_t RESERVED0[24U];
    _RW uint32_t ISPR[8U];
        uint32_t RESERVED0[24U];
    _RW uint32_t ICPR[8U];
        uint32_t RESERVED0[24U];
    _RW uint32_t IABR[8U];
        uint32_t RESERVED0[56U];
    _RW uint32_t IPR[60U];
        uint32_t RESERVED0[643U];
    _W  uint32_t STIR;
}Nvic_RegDef;

#define NVIC_BASE    ((uint32_t*)0xE000E100)
#define NVIC         ((Nvic_RegDef*)NVIC_BASE)
#define NVIC_IPR_LOW_BIT_UNUSED      4U

#define NVIC_ISER_REG_WIDTH          32U
#define NVIC_ISER_BIT_PER_IRQ        1U
#define NVIC_ISER_FIRST_IRQ_MASK     ((uint32_t)0x1)
#define NVIC_ISER_IRQ_MASK(Index)    (NVIC_ISER_FIRST_IRQ_MASK<< \
                                      ((Index) * NVIC_ISER_BIT_PER_IRQ))

#define NVIC_ICER_REG_WIDTH          32U
#define NVIC_ICER_BIT_PER_IRQ        1U
#define NVIC_ICER_FIRST_IRQ_MASK     ((uint32_t)0x1)
#define NVIC_ICER_IRQ_MASK(Index)    (NVIC_ICER_FIRST_IRQ_MASK<< \
                                      ((Index) * NVIC_ICER_BIT_PER_IRQ))

#define NVIC_ISPR_REG_WIDTH          32U
#define NVIC_ISPR_BIT_PER_IRQ        1U
#define NVIC_ISPR_FIRST_IRQ_MASK     ((uint32_t)0x1)
#define NVIC_ISPR_IRQ_MASK(Index)    (NVIC_ISPR_FIRST_IRQ_MASK<< \
                                      ((Index) * NVIC_ISPR_BIT_PER_IRQ))

#define NVIC_ICPR_REG_WIDTH          32U
#define NVIC_ICPR_BIT_PER_IRQ        1U
#define NVIC_ICPR_FIRST_IRQ_MASK     ((uint32_t)0x1)
#define NVIC_ICPR_IRQ_MASK(Index)    (NVIC_ICPR_FIRST_IRQ_MASK<< \
                                      ((Index) * NVIC_ICPR_BIT_PER_IRQ))

#define NVIC_IABR_REG_WIDTH          32U
#define NVIC_IABR_BIT_PER_IRQ        1U
#define NVIC_IABR_FIRST_IRQ_MASK     ((uint32_t)0x1)
#define NVIC_IABR_IRQ_MASK(Index)    (NVIC_IABR_FIRST_IRQ_MASK<< \
                                      ((Index) * NVIC_IABR_BIT_PER_IRQ))

#define NVIC_IPR_REG_WIDTH           32U
#define NVIC_IPR_BIT_PER_IRQ         8U
#define NVIC_IPR_FIRST_IRQ_MASK      ((uint32_t)0xFF)
#define NVIC_IPR_IRQ_POS(Index)      (NVIC_IPR_LOW_BIT_UNUSED + \
                                      (Index) * NVIC_IPR_BIT_PER_IRQ)
#define NVIC_IPR_IRQ_MASK(Index)     (NVIC_IPR_FIRST_IRQ_MASK << \
                                      NVIC_IPR_IRQ_POS(Index))

/*
 * Definition of GPIO peripheral base address
 */
#define GPIOA_BASE      0x40020000U
#define GPIOB_BASE      0x40020400U
#define GPIOC_BASE      0x40020800U
#define GPIOD_BASE      0x40020C00U
#define GPIOE_BASE      0x40021000U
#define GPIOH_BASE      0x40021C00U

/*
 * Definition of I2c peripheral base address
 */
#define I2C1_BASE       0x40005400U
#define I2C2_BASE       0x40005800U
#define I2C3_BASE       0x40005C00U

/*
 * Definition of Usart peripheral base address
 */
#define USART1_BASE     0x40011000U
#define USART2_BASE     0x40004400U
#define USART6_BASE     0x40011400U

/*
 * Definition of Spi peripheral base address
 */
#define SPI1_BASE       0x40013000U
#define SPI2_BASE       0x40003800U
#define SPI3_BASE       0x40003C00U
#define SPI4_BASE       0x40013400U

/*
 * Definition of EXTI peripheral base address
 */
#define EXTI_BASE       0x40013C00U

/*
 * Definition of RCC peripheral base address
 */
#define RCC_BASE        0x40023800U

/*
 * Definition of RCC peripheral base address
 */
#define SYSCFG_BASE     0x40013800U

/*********************************************************
 *              Peripheral register structures
 *********************************************************/
/*
 * GPIO peripheral register definition
 */
typedef struct
{
    _RW uint32_t MODER;
    _RW uint32_t OTYPER;
    _RW uint32_t OSPEEDR;
    _RW uint32_t PUPDR;
    _R  uint32_t IDR;
    _RW uint32_t ODR;
    _W  uint32_t BSRR;
    _RW uint32_t LCKR;
    _RW uint32_t AFRL;
    _RW uint32_t AFRH;
} Gpio_RegDef;

#define GPIOA    ((Gpio_RegDef*)GPIOA_BASE)
#define GPIOB    ((Gpio_RegDef*)GPIOB_BASE)
#define GPIOC    ((Gpio_RegDef*)GPIOC_BASE)
#define GPIOD    ((Gpio_RegDef*)GPIOD_BASE)
#define GPIOE    ((Gpio_RegDef*)GPIOE_BASE)
#define GPIOH    ((Gpio_RegDef*)GPIOH_BASE)

/* Position macro of bit fields in GPIO_MODER register */
#define NUM_BIT_PER_PIN_IN_GPIO_MODER    2U
#define GPIO_MODER_BIT_POS(pinNum)       (NUM_BIT_PER_PIN_IN_GPIO_MODER * \
                                          (pinNum))

/* Mask macro of bit fields in GPIO_MODER register */
#define MASK_OF_PIN_IN_GPIO_MODER        ((uint32_t)0x3)
#define GPIO_MODER_BIT_MASK(pinNum)      (MASK_OF_PIN_IN_GPIO_MODER << \
                                          GPIO_MODER_BIT_POS(pinNum))

/* Position macro of bit fields in GPIO_OTYPER register */
#define NUM_BIT_PER_PIN_IN_GPIO_OTYPER   1U
#define GPIO_OTYPER_BIT_POS(pinNum)      (NUM_BIT_PER_PIN_IN_GPIO_OTYPER * \
                                          (pinNum))

/* Mask macro of bit fields in GPIO_OTYPER register */
#define MASK_OF_PIN_IN_GPIO_OTYPER       ((uint32_t)0x1)
#define GPIO_OTYPER_BIT_MASK(pinNum)     (MASK_OF_PIN_IN_GPIO_OTYPER << \
                                          GPIO_OTYPER_BIT_POS(pinNum))

/* Position macro of bit fields in GPIO_OSPEEDR register */
#define NUM_BIT_PER_PIN_IN_GPIO_OSPEEDR  2U
#define GPIO_OSPEEDR_BIT_POS(pinNum)     (NUM_BIT_PER_PIN_IN_GPIO_OSPEEDR * \
                                          (pinNum))

/* Mask macro of bit fields in GPIO_OSPEEDR register */
#define MASK_OF_PIN_IN_GPIO_OSPEEDR      ((uint32_t)0x3)
#define GPIO_OSPEEDR_BIT_MASK(pinNum)    (MASK_OF_PIN_IN_GPIO_OSPEEDR << \
                                          GPIO_OSPEEDR_BIT_POS(pinNum))

/* Position macro of bit fields in GPIO_PUPDR register */
#define NUM_BIT_PER_PIN_IN_GPIO_PUPDR    2U
#define GPIO_PUPDR_BIT_POS(pinNum)       (NUM_BIT_PER_PIN_IN_GPIO_PUPDR * \
                                          (pinNum))

/* Mask macro of bit fields in GPIO_PUPDR register */
#define MASK_OF_PIN_IN_GPIO_PUPDR        ((uint32_t)0x3)
#define GPIO_PUPDR_BIT_MASK(pinNum)      (MASK_OF_PIN_IN_GPIO_PUPDR << \
                                          GPIO_PUPDR_BIT_POS(pinNum))

/* Position macro of bit fields in GPIO_IDR register */
#define NUM_BIT_PER_PIN_IN_GPIO_IDR      1U
#define GPIO_IDR_BIT_POS(pinNum)         (NUM_BIT_PER_PIN_IN_GPIO_IDR * \
                                          (pinNum))

/* Mask macro of bit fields in GPIO_IDR register */
#define MASK_OF_PIN_IN_GPIO_IDR          ((uint32_t)0x1)
#define GPIO_IDR_BIT_MASK(pinNum)        (MASK_OF_PIN_IN_GPIO_IDR << \
                                          GPIO_IDR_BIT_POS(pinNum))

/* Position macro of bit fields in GPIO_ODR register */
#define NUM_BIT_PER_PIN_IN_GPIO_ODR      1U
#define GPIO_ODR_BIT_POS(pinNum)         (NUM_BIT_PER_PIN_IN_GPIO_ODR * \
                                          (pinNum))

/* Mask macro of bit fields in GPIO_ODR register */
#define MASK_OF_PIN_IN_GPIO_ODR          ((uint32_t)0x1)
#define GPIO_ODR_BIT_MASK(pinNum)        (MASK_OF_PIN_IN_GPIO_ODR << \
                                          GPIO_ODR_BIT_POS(pinNum))

/* Position macro of bit fields in GPIO_BSRR_BS register */
#define NUM_BIT_PER_PIN_IN_GPIO_BSRR_BS  1U
#define GPIO_BSRR_BS_BIT_POS(pinNum)     (NUM_BIT_PER_PIN_IN_GPIO_BSRR_BS * \
                                          (pinNum))

/* Mask macro of bit fields in GPIO_BSRR_BS register */
#define MASK_OF_PIN_IN_GPIO_BSRR_BS      ((uint32_t)0x1)
#define GPIO_BSRR_BS_BIT_MASK(pinNum)    (MASK_OF_PIN_IN_GPIO_BSRR_BS << \
                                          GPIO_BSRR_BS_BIT_POS(pinNum))

/* Position macro of bit fields in GPIO_BSRR_BR register */
#define START_POS_OF_BSRR_BR             16U
#define NUM_BIT_PER_PIN_IN_GPIO_BSRR_BR  1U
#define GPIO_BSRR_BR_BIT_POS(pinNum)     (START_POS_OF_BSRR_BR + \
                                          NUM_BIT_PER_PIN_IN_GPIO_BSRR_BR * \
                                          (pinNum))

/* Mask macro of bit fields in GPIO_BSRR_BR register */
#define MASK_OF_PIN_IN_GPIO_BSRR_BR      ((uint32_t)0x1)
#define GPIO_BSRR_BR_BIT_MASK(pinNum)    (MASK_OF_PIN_IN_GPIO_BSRR_BR << \
                                          GPIO_BSRR_BR_BIT_POS(pinNum))

/* Position macro of bit fields in GPIO_LCKR_LCK register */
#define NUM_BIT_PER_PIN_IN_GPIO_LCKR_LCK   1U
#define GPIO_LCKR_LCK_BIT_POS(pinNum)      (NUM_BIT_PER_PIN_IN_GPIO_LCKR_LCK * \
                                            (pinNum))

/* Mask macro of bit fields in GPIO_LCKR_LCK register */
#define MASK_OF_PIN_IN_GPIO_LCKR_LCK     ((uint32_t)0x1)
#define GPIO_LCKR_LCK_BIT_MASK(pinNum)   (MASK_OF_PIN_IN_GPIO_LCKR_LCK << \
                                          GPIO_LCKR_LCK_BIT_POS(pinNum))

/* Position macro of bit fields GPIO_LCKR_LCKK */
#define GPIO_LCKR_LCKK_POS               16U

/* Mask macro of bit fields GPIO_LCKR_LCKK */
#define GPIO_LCKR_LCKK_MASK              ((uint32_t)0x10000)

/* Position macro of bit fields in GPIO_AFRL register */
#define NUM_BIT_PER_PIN_IN_GPIO_AFRL     4U
#define GPIO_AFRL_BIT_POS(pinNum)        (NUM_BIT_PER_PIN_IN_GPIO_AFRL * \
                                          (pinNum))

/* Mask macro of bit fields in GPIO_AFRL register */
#define MASK_OF_PIN_IN_GPIO_AFRL         ((uint32_t)0xF)
#define GPIO_AFRL_BIT_MASK(pinNum)       (MASK_OF_PIN_IN_GPIO_AFRL << \
                                          GPIO_AFRL_BIT_POS(pinNum))

/* Position macro of bit fields in GPIO_AFRH register */
#define PIN_NUM_START_IN_AFRH            8U
#define NUM_BIT_PER_PIN_IN_GPIO_AFRH     4U
#define GPIO_AFRH_BIT_POS(pinNum)        (NUM_BIT_PER_PIN_IN_GPIO_AFRL * \
                                          ((pinNum) - PIN_NUM_START_IN_AFRH))

/* Mask macro of bit fields in GPIO_AFRH register */
#define MASK_OF_PIN_IN_GPIO_AFRH         ((uint32_t)0xF)
#define GPIO_AFRH_BIT_MASK(pinNum)       (MASK_OF_PIN_IN_GPIO_AFRH << \
                                          GPIO_AFRH_BIT_POS(pinNum))

/*
 * RCC peripheral register structure
 */
typedef struct
{
    _RW uint32_t CR;
    _RW uint32_t PLLCFGR;
    _RW uint32_t CFGR;
    _RW uint32_t CIR;
    _RW uint32_t AHB1RSTR;
    _RW uint32_t AHB2RSTR;
        uint32_t Reserved1[2U];
    _RW uint32_t APB1RSTR;
    _RW uint32_t APB2RSTR;
        uint32_t Reserved2[2U];
    _RW uint32_t AHB1ENR;
    _RW uint32_t AHB2ENR;
        uint32_t Reserved3[2U];
    _RW uint32_t APB1ENR;
    _RW uint32_t APB2ENR;
        uint32_t Reserved4[2U];
    _RW uint32_t AHB1LPENR;
    _RW uint32_t AHB2LPENR;
        uint32_t Reserved5[2U];
    _RW uint32_t APB1LPENR;
    _RW uint32_t APB2LPENR;
        uint32_t Reserved6[2U];
    _RW uint32_t BDCR;
    _RW uint32_t CSR;
        uint32_t Reserved7[2U];
    _RW uint32_t SSCGR;
    _RW uint32_t PLLI2SCFGR;
        uint32_t Reserved8;
    _RW uint32_t DCKCFGR;
} Rcc_RegDef;

#define RCC    ((Rcc_RegDef*)RCC_BASE)

#define RCC_AHB1ENR_GPIOAEN_POS     (0U)
#define RCC_AHB1ENR_GPIOBEN_POS     (1U)
#define RCC_AHB1ENR_GPIOCEN_POS     (2U)
#define RCC_AHB1ENR_GPIODEN_POS     (3U)
#define RCC_AHB1ENR_GPIOEEN_POS     (4U)
#define RCC_AHB1ENR_GPIOHEN_POS     (7U)

#define RCC_AHB1ENR_GPIOAEN_MASK    (0x1U)
#define RCC_AHB1ENR_GPIOBEN_MASK    (0x2U)
#define RCC_AHB1ENR_GPIOCEN_MASK    (0x4U)
#define RCC_AHB1ENR_GPIODEN_MASK    (0x8U)
#define RCC_AHB1ENR_GPIOEEN_MASK    (0x10U)
#define RCC_AHB1ENR_GPIOHEN_MASK    (0x80U)

#define RCC_APB1ENR_I2C1EN_MASK     (0x200000U)
#define RCC_APB1ENR_I2C2EN_MASK     (0x400000U)
#define RCC_APB1ENR_I2C3EN_MASK     (0x800000U)
#define RCC_APB1ENR_USART2EN_MASK   (0x20000U)
#define RCC_APB1ENR_SPI2EN_MASK     (0x4000U)
#define RCC_APB1ENR_SPI3EN_MASK     (0x8000U)

#define RCC_APB2ENR_USART1EN_MASK   (0x10U)
#define RCC_APB2ENR_USART6EN_MASK   (0x20U)
#define RCC_APB2ENR_SPI1EN_MASK     (0x1000U)
#define RCC_APB2ENR_SPI4EN_MASK     (0x2000U)
#define RCC_APB2ENR_SYSCFGEN_MASK   (0x4000U)

#define RCC_AHB1RSTR_GPIOARST_MASK  (0x1U)
#define RCC_AHB1RSTR_GPIOBRST_MASK  (0x2U)
#define RCC_AHB1RSTR_GPIOCRST_MASK  (0x4U)
#define RCC_AHB1RSTR_GPIODRST_MASK  (0x8U)
#define RCC_AHB1RSTR_GPIOERST_MASK  (0x10U)
#define RCC_AHB1RSTR_GPIOHRST_MASK  (0x80U)

/*
 * EXTI peripheral register structure
 */
typedef struct
{
    _RW uint32_t EXTI_IMR;
    _RW uint32_t EXTI_EMR;
    _RW uint32_t EXTI_RTSR;
    _RW uint32_t EXTI_FTSR;
    _RW uint32_t EXTI_SWIER;
    _RW uint32_t EXTI_PR;
}Exti_RegDef;

#define EXTI    ((Exti_RegDef*)EXTI_BASE)

/* Position macro of bit fields in EXTI_IMR register */
#define NUM_BIT_PER_LINE_IN_EXTI_IMR   1U
#define EXTI_IMR_BIT_POS(line)         (NUM_BIT_PER_LINE_IN_EXTI_IMR * (line))

/* Mask macro of bit fields in EXTI_IMR register */
#define MASK_OF_LINE_IN_EXTI_IMR       ((uint32_t)0x1)
#define EXTI_IMR_BIT_MASK(line)        (MASK_OF_LINE_IN_EXTI_IMR << \
                                        EXTI_IMR_BIT_POS(line))

/* Position macro of bit fields in EXTI_EMR register */
#define NUM_BIT_PER_LINE_IN_EXTI_EMR   1U
#define EXTI_EMR_BIT_POS(line)         (NUM_BIT_PER_LINE_IN_EXTI_EMR * (line))

/* Mask macro of bit fields in EXTI_EMR register */
#define MASK_OF_LINE_IN_EXTI_EMR       ((uint32_t)0x1)
#define EXTI_EMR_BIT_MASK(line)        (MASK_OF_LINE_IN_EXTI_EMR << \
                                        EXTI_EMR_BIT_POS(line))

/* Position macro of bit fields in EXTI_RTSR register */
#define NUM_BIT_PER_LINE_IN_EXTI_RTSR  1U
#define EXTI_RTSR_BIT_POS(line)        (NUM_BIT_PER_LINE_IN_EXTI_RTSR * (line))

/* Mask macro of bit fields in EXTI_RTSR register */
#define MASK_OF_LINE_IN_EXTI_RTSR      ((uint32_t)0x1)
#define EXTI_RTSR_BIT_MASK(line)       (MASK_OF_LINE_IN_EXTI_RTSR << \
                                        EXTI_RTSR_BIT_POS(line))

/* Position macro of bit fields in EXTI_FTSR register */
#define NUM_BIT_PER_LINE_IN_EXTI_FTSR  1U
#define EXTI_FTSR_BIT_POS(line)        (NUM_BIT_PER_LINE_IN_EXTI_FTSR *(line))

/* Mask macro of bit fields in EXTI_FTSR register */
#define MASK_OF_LINE_IN_EXTI_FTSR      ((uint32_t)0x1)
#define EXTI_FTSR_BIT_MASK(line)       (MASK_OF_LINE_IN_EXTI_FTSR << \
                                        EXTI_FTSR_BIT_POS(line))

/* Position macro of bit fields in EXTI_SWIER register */
#define NUM_BIT_PER_LINE_IN_EXTI_SWIER 1U
#define EXTI_SWIER_BIT_POS(line)       (NUM_BIT_PER_LINE_IN_EXTI_SWIER * (line))

/* Mask macro of bit fields in EXTI_SWIER register */
#define MASK_OF_LINE_IN_EXTI_SWIER     ((uint32_t)0x1)
#define EXTI_SWIER_BIT_MASK(line)      (MASK_OF_LINE_IN_EXTI_SWIER << \
                                        EXTI_SWIER_BIT_POS(line))

/* Position macro of bit fields in EXTI_PR register */
#define NUM_BIT_PER_LINE_IN_EXTI_PR    1U
#define EXTI_PR_BIT_POS(line)          (NUM_BIT_PER_LINE_IN_EXTI_PR * (line))

/* Mask macro of bit fields in EXTI_PR register */
#define MASK_OF_LINE_IN_EXTI_PR        ((uint32_t)0x1)
#define EXTI_PR_BIT_MASK(line)         (MASK_OF_LINE_IN_EXTI_PR << \
                                        EXTI_PR_BIT_POS(line))

/*
 * SYSCFG register structure
 */
typedef struct
{
    _RW uint32_t MEMRMP;
    _RW uint32_t PMC;
    _RW uint32_t EXTICR[4U];
    _RW uint32_t Reserved[2U];
    _RW uint32_t CMPCR;
}Syscfg_RegDef;

#define SYSCFG    ((Syscfg_RegDef*)SYSCFG_BASE)

#endif /* STM32F401RE_H */