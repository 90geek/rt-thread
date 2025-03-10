/*
 * Copyright (c) 2006-2022, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2022-09-21     yuqi        created
 */

#ifndef DRIVERS_CONFIG_PWM_CONFIG_H_
#define DRIVERS_CONFIG_PWM_CONFIG_H_
#include "F28x_Project.h"     // Device Headerfile and Examples Include File
#include "F2837xD_epwm.h"
#include "rtthread.h"
#include "drv_config.h"

#define BSP_USING_PWM1
#define BSP_USING_PWM2
#define BSP_USING_PWM3
#define BSP_USING_PWM4
#ifdef __cplusplus
extern "C" {
#endif
#ifdef BSP_USING_PWM1
    #ifndef PWM1_CONFIG
    #define PWM1_CONFIG                             \
    {                                           \
        .name = "pwm1",                         \
        .pwm_regs   = &EPwm1Regs,                \
    }
    #endif
#endif
#ifdef BSP_USING_PWM2
    #ifndef PWM2_CONFIG
    #define PWM2_CONFIG                             \
    {                                           \
        .name = "pwm2",                         \
        .pwm_regs   = &EPwm2Regs,                \
    }
    #endif
#endif
#ifdef BSP_USING_PWM3
    #ifndef PWM3_CONFIG
    #define PWM3_CONFIG                             \
    {                                           \
        .name = "pwm3",                         \
        .pwm_regs   = &EPwm3Regs,                \
    }
    #endif
#endif
#ifdef BSP_USING_PWM4
    #ifndef PWM4_CONFIG
    #define PWM4_CONFIG                             \
    {                                           \
        .name = "pwm4",                         \
        .pwm_regs   = &EPwm4Regs,                \
    }
    #endif
#endif
#define EPWM1_MAX_DB   0x03FF
#define EPWM2_MAX_DB   0x03FF
#define EPWM3_MAX_DB   0x03FF
#define EPWM1_MIN_DB   0
#define EPWM2_MIN_DB   0
#define EPWM3_MIN_DB   0
#define DB_UP          1
#define DB_DOWN        0

#define RT_HSPCLKDIV TB_DIV4
#define RT_CLKDIV TB_DIV4
#define RT_CTRMODE TB_COUNT_UPDOWN

#define TZ_OFF  2
#define TZ_ON   1
#ifdef __cplusplus
}
#endif


#define RT_SHADOW_MODE CC_SHADOW
#define RT_LOAD_TIME CC_CTR_ZERO
#define RT_CTRMODE TB_COUNT_UPDOWN
#endif /* DRIVERS_CONFIG_PWM_CONFIG_H_ */

