/*
 * EGG OpenSource EBike firmware
 *
 * Copyright (C) Casainho, 2015, 2106, 2017.
 *
 * Released under the GPL License, Version 3
 */

#include <stdint.h>
#include <stdio.h>
#include "stm8s_gpio.h"
#include "stm8s_tim1.h"
#include "motor.h"
#include "gpio.h"
#include "motor.h"
#include "pwm.h"

#if (SVM_TABLE == SVM)
uint8_t ui8_svm_table [SVM_TABLE_LEN] =
{
    131	,
    137	,
    142	,
    147	,
    153	,
    158	,
    163	,
    169	,
    174	,
    179	,
    185	,
    190	,
    195	,
    200	,
    205	,
    210	,
    215	,
    220	,
    225	,
    230	,
    235	,
    238	,
    240	,
    241	,
    243	,
    244	,
    245	,
    246	,
    247	,
    248	,
    249	,
    250	,
    251	,
    252	,
    252	,
    253	,
    253	,
    254	,
    254	,
    254	,
    255	,
    255	,
    255	,
    255	,
    255	,
    254	,
    254	,
    254	,
    253	,
    253	,
    252	,
    252	,
    251	,
    250	,
    249	,
    248	,
    247	,
    246	,
    245	,
    244	,
    242	,
    241	,
    240	,
    238	,
    239	,
    240	,
    242	,
    243	,
    244	,
    246	,
    247	,
    248	,
    249	,
    250	,
    250	,
    251	,
    252	,
    253	,
    253	,
    254	,
    254	,
    254	,
    255	,
    255	,
    255	,
    255	,
    255	,
    255	,
    254	,
    254	,
    254	,
    253	,
    253	,
    252	,
    251	,
    251	,
    250	,
    249	,
    248	,
    247	,
    246	,
    245	,
    243	,
    242	,
    241	,
    239	,
    238	,
    233	,
    228	,
    223	,
    218	,
    213	,
    208	,
    203	,
    198	,
    193	,
    188	,
    182	,
    177	,
    172	,
    167	,
    161	,
    156	,
    150	,
    145	,
    140	,
    134	,
    129	,
    123	,
    118	,
    113	,
    107	,
    102	,
    96	,
    91	,
    86	,
    80	,
    75	,
    70	,
    65	,
    59	,
    54	,
    49	,
    44	,
    39	,
    34	,
    29	,
    25	,
    20	,
    16	,
    15	,
    13	,
    12	,
    11	,
    9	,
    8	,
    7	,
    6	,
    5	,
    4	,
    4	,
    3	,
    2	,
    2	,
    1	,
    1	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    1	,
    1	,
    2	,
    2	,
    3	,
    4	,
    4	,
    5	,
    6	,
    7	,
    8	,
    9	,
    11	,
    12	,
    13	,
    15	,
    16	,
    16	,
    14	,
    13	,
    11	,
    10	,
    9	,
    8	,
    7	,
    6	,
    5	,
    4	,
    3	,
    3	,
    2	,
    1	,
    1	,
    1	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    1	,
    1	,
    2	,
    2	,
    3	,
    4	,
    5	,
    6	,
    7	,
    8	,
    9	,
    10	,
    11	,
    12	,
    14	,
    15	,
    17	,
    22	,
    27	,
    31	,
    36	,
    41	,
    46	,
    51	,
    56	,
    62	,
    67	,
    72	,
    77	,
    83	,
    88	,
    93	,
    99	,
    104	,
    109	,
    115	,
    120	,
    126
};
#elif (SVM_TABLE == SINE_SVM)
uint8_t ui8_svm_table [SVM_TABLE_LEN] =
{
    8	,
    19	,
    30	,
    41	,
    51	,
    62	,
    73	,
    84	,
    94	,
    105	,
    115	,
    126	,
    136	,
    146	,
    157	,
    167	,
    177	,
    187	,
    196	,
    206	,
    216	,
    223	,
    226	,
    228	,
    231	,
    234	,
    236	,
    239	,
    241	,
    243	,
    245	,
    246	,
    248	,
    249	,
    251	,
    252	,
    253	,
    254	,
    254	,
    255	,
    255	,
    256	,
    256	,
    256	,
    255	,
    255	,
    254	,
    254	,
    253	,
    252	,
    251	,
    249	,
    248	,
    246	,
    245	,
    243	,
    241	,
    238	,
    236	,
    234	,
    231	,
    228	,
    225	,
    222	,
    224	,
    227	,
    229	,
    232	,
    235	,
    237	,
    239	,
    241	,
    243	,
    245	,
    247	,
    249	,
    250	,
    251	,
    252	,
    253	,
    254	,
    255	,
    255	,
    255	,
    256	,
    256	,
    255	,
    255	,
    255	,
    254	,
    253	,
    252	,
    251	,
    250	,
    249	,
    247	,
    246	,
    244	,
    242	,
    240	,
    238	,
    235	,
    233	,
    230	,
    227	,
    224	,
    221	,
    212	,
    202	,
    192	,
    182	,
    172	,
    162	,
    152	,
    142	,
    132	,
    121	,
    111	,
    100	,
    90	,
    79	,
    68	,
    58	,
    47	,
    36	,
    25	,
    14	,
    4	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0
};
#elif (SVM_TABLE == SINE)
uint8_t ui8_svm_table [SVM_TABLE_LEN] =
{
    5	,
    12	,
    18	,
    24	,
    30	,
    37	,
    43	,
    49	,
    55	,
    61	,
    67	,
    73	,
    79	,
    85	,
    91	,
    97	,
    103	,
    108	,
    114	,
    120	,
    125	,
    131	,
    136	,
    141	,
    146	,
    151	,
    156	,
    161	,
    166	,
    171	,
    176	,
    180	,
    184	,
    189	,
    193	,
    197	,
    201	,
    205	,
    208	,
    212	,
    215	,
    219	,
    222	,
    225	,
    228	,
    231	,
    233	,
    236	,
    238	,
    240	,
    243	,
    244	,
    246	,
    248	,
    249	,
    251	,
    252	,
    253	,
    254	,
    255	,
    255	,
    256	,
    256	,
    256	,
    256	,
    256	,
    255	,
    255	,
    254	,
    253	,
    253	,
    251	,
    250	,
    249	,
    247	,
    246	,
    244	,
    242	,
    240	,
    237	,
    235	,
    232	,
    230	,
    227	,
    224	,
    221	,
    217	,
    214	,
    211	,
    207	,
    203	,
    199	,
    195	,
    191	,
    187	,
    183	,
    178	,
    174	,
    169	,
    164	,
    159	,
    154	,
    149	,
    144	,
    139	,
    134	,
    128	,
    123	,
    117	,
    112	,
    106	,
    100	,
    94	,
    89	,
    83	,
    77	,
    71	,
    65	,
    59	,
    53	,
    46	,
    40	,
    34	,
    28	,
    22	,
    15	,
    9	,
    3	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0	,
    0
};
#endif

uint8_t ui8_duty_cycle = 0;
uint8_t ui8_duty_cycle_target = 0;
uint8_t ui8_value_a;
uint8_t ui8_value_b;
uint8_t ui8_value_c;
uint16_t ui16_value;

void pwm_phase_a_enable (void)
{
  TIM1_OC3Init(TIM1_OCMODE_PWM1,
	       TIM1_OUTPUTNSTATE_ENABLE,
  	       TIM1_OUTPUTNSTATE_ENABLE,
	       0,
  	       TIM1_OCPOLARITY_HIGH,
  	       TIM1_OCNPOLARITY_LOW,
  	       TIM1_OCIDLESTATE_RESET,
  	       TIM1_OCNIDLESTATE_SET);
}

void pwm_phase_a_disable (void)
{
  TIM1_OC3Init(TIM1_OCMODE_PWM1,
	       TIM1_OUTPUTNSTATE_DISABLE,
  	       TIM1_OUTPUTNSTATE_DISABLE,
	       0,
  	       TIM1_OCPOLARITY_HIGH,
  	       TIM1_OCNPOLARITY_LOW,
  	       TIM1_OCIDLESTATE_RESET,
  	       TIM1_OCNIDLESTATE_SET);

  // disable pin
  GPIO_Init(PMW_PHASE_A_HIGH__PORT,
	    PMW_PHASE_A_HIGH__PIN,
	    GPIO_MODE_OUT_PP_LOW_FAST);

  // disable pin
  GPIO_Init(PMW_PHASE_A_LOW__PORT,
	    PMW_PHASE_A_LOW__PIN,
	    GPIO_MODE_OUT_PP_HIGH_FAST);
}

void pwm_phase_a_enable_pwm (void)
{
  TIM1_OC3Init(TIM1_OCMODE_PWM1,
	       TIM1_OUTPUTSTATE_ENABLE,
	       TIM1_OUTPUTNSTATE_DISABLE,
	       0,
	       TIM1_OCPOLARITY_HIGH,
	       TIM1_OCNPOLARITY_LOW,
	       TIM1_OCIDLESTATE_RESET,
	       TIM1_OCNIDLESTATE_SET);

  // disable pin
  GPIO_Init(PMW_PHASE_A_LOW__PORT,
	    PMW_PHASE_A_LOW__PIN,
	    GPIO_MODE_OUT_PP_HIGH_FAST);
}

void pwm_phase_a_enable_low (void)
{
  TIM1_OC3Init(TIM1_OCMODE_PWM1,
	       TIM1_OUTPUTNSTATE_DISABLE,
  	       TIM1_OUTPUTNSTATE_DISABLE,
	       0,
	       TIM1_OCPOLARITY_HIGH,
	       TIM1_OCNPOLARITY_LOW,
	       TIM1_OCIDLESTATE_RESET,
	       TIM1_OCNIDLESTATE_SET);

  // disable pin
  GPIO_Init(PMW_PHASE_A_HIGH__PORT,
	    PMW_PHASE_A_HIGH__PIN,
	    GPIO_MODE_OUT_PP_LOW_FAST);

  // enable pin
  GPIO_Init(PMW_PHASE_A_LOW__PORT,
	    PMW_PHASE_A_LOW__PIN,
	    GPIO_MODE_OUT_PP_LOW_FAST);
}

void pwm_phase_b_enable (void)
{
  TIM1_OC2Init(TIM1_OCMODE_PWM1,
	       TIM1_OUTPUTNSTATE_ENABLE,
  	       TIM1_OUTPUTNSTATE_ENABLE,
	       0,
  	       TIM1_OCPOLARITY_HIGH,
  	       TIM1_OCNPOLARITY_LOW,
  	       TIM1_OCIDLESTATE_RESET,
  	       TIM1_OCNIDLESTATE_SET);
}

void pwm_phase_b_disable (void)
{
  TIM1_OC2Init(TIM1_OCMODE_PWM1,
	       TIM1_OUTPUTNSTATE_DISABLE,
  	       TIM1_OUTPUTNSTATE_DISABLE,
	       0,
  	       TIM1_OCPOLARITY_HIGH,
  	       TIM1_OCNPOLARITY_LOW,
  	       TIM1_OCIDLESTATE_RESET,
  	       TIM1_OCNIDLESTATE_SET);

  // disable pin
  GPIO_Init(PMW_PHASE_B_HIGH__PORT,
	    PMW_PHASE_B_HIGH__PIN,
	    GPIO_MODE_OUT_PP_LOW_FAST);

  // disable pin
  GPIO_Init(PMW_PHASE_B_LOW__PORT,
	    PMW_PHASE_B_LOW__PIN,
	    GPIO_MODE_OUT_PP_HIGH_FAST);
}

void pwm_phase_b_enable_pwm (void)
{
  TIM1_OC2Init(TIM1_OCMODE_PWM1,
	       TIM1_OUTPUTSTATE_ENABLE,
	       TIM1_OUTPUTNSTATE_DISABLE,
	       0,
	       TIM1_OCPOLARITY_HIGH,
	       TIM1_OCNPOLARITY_LOW,
	       TIM1_OCIDLESTATE_RESET,
	       TIM1_OCNIDLESTATE_SET);

  // disable pin
  GPIO_Init(PMW_PHASE_B_LOW__PORT,
	    PMW_PHASE_B_LOW__PIN,
	    GPIO_MODE_OUT_PP_HIGH_FAST);
}

void pwm_phase_b_enable_low (void)
{
  TIM1_OC2Init(TIM1_OCMODE_PWM1,
	       TIM1_OUTPUTNSTATE_DISABLE,
  	       TIM1_OUTPUTNSTATE_DISABLE,
	       0,
	       TIM1_OCPOLARITY_HIGH,
	       TIM1_OCNPOLARITY_LOW,
	       TIM1_OCIDLESTATE_RESET,
	       TIM1_OCNIDLESTATE_SET);

  // disable pin
  GPIO_Init(PMW_PHASE_B_HIGH__PORT,
	    PMW_PHASE_B_HIGH__PIN,
	    GPIO_MODE_OUT_PP_LOW_FAST);

  // enable pin
  GPIO_Init(PMW_PHASE_B_LOW__PORT,
	    PMW_PHASE_B_LOW__PIN,
	    GPIO_MODE_OUT_PP_LOW_FAST);
}

void pwm_phase_c_enable (void)
{
  TIM1_OC1Init(TIM1_OCMODE_PWM1,
	       TIM1_OUTPUTNSTATE_ENABLE,
  	       TIM1_OUTPUTNSTATE_ENABLE,
	       0,
  	       TIM1_OCPOLARITY_HIGH,
  	       TIM1_OCNPOLARITY_LOW,
  	       TIM1_OCIDLESTATE_RESET,
  	       TIM1_OCNIDLESTATE_SET);
}

void pwm_phase_c_disable (void)
{
  TIM1_OC1Init(TIM1_OCMODE_PWM1,
	       TIM1_OUTPUTNSTATE_DISABLE,
  	       TIM1_OUTPUTNSTATE_DISABLE,
	       0,
  	       TIM1_OCPOLARITY_HIGH,
  	       TIM1_OCNPOLARITY_LOW,
  	       TIM1_OCIDLESTATE_RESET,
  	       TIM1_OCNIDLESTATE_SET);

  // disable pin
  GPIO_Init(PMW_PHASE_C_HIGH__PORT,
	    PMW_PHASE_C_HIGH__PIN,
	    GPIO_MODE_OUT_PP_LOW_FAST);

  // disable pin
  GPIO_Init(PMW_PHASE_C_LOW__PORT,
	    PMW_PHASE_C_LOW__PIN,
	    GPIO_MODE_OUT_PP_HIGH_FAST);
}

void pwm_phase_c_enable_pwm (void)
{
  TIM1_OC1Init(TIM1_OCMODE_PWM1,
	       TIM1_OUTPUTSTATE_ENABLE,
	       TIM1_OUTPUTNSTATE_DISABLE,
	       0,
	       TIM1_OCPOLARITY_HIGH,
	       TIM1_OCNPOLARITY_LOW,
	       TIM1_OCIDLESTATE_RESET,
	       TIM1_OCNIDLESTATE_SET);

  // disable pin
  GPIO_Init(PMW_PHASE_C_LOW__PORT,
	    PMW_PHASE_C_LOW__PIN,
	    GPIO_MODE_OUT_PP_HIGH_FAST);
}

void pwm_phase_c_enable_low (void)
{
  TIM1_OC1Init(TIM1_OCMODE_PWM1,
	       TIM1_OUTPUTNSTATE_DISABLE,
  	       TIM1_OUTPUTNSTATE_DISABLE,
	       0,
	       TIM1_OCPOLARITY_HIGH,
	       TIM1_OCNPOLARITY_LOW,
	       TIM1_OCIDLESTATE_RESET,
	       TIM1_OCNIDLESTATE_SET);

  // disable pin
  GPIO_Init(PMW_PHASE_C_HIGH__PORT,
	    PMW_PHASE_C_HIGH__PIN,
	    GPIO_MODE_OUT_PP_LOW_FAST);

  // enable pin
  GPIO_Init(PMW_PHASE_C_LOW__PORT,
	    PMW_PHASE_C_LOW__PIN,
	    GPIO_MODE_OUT_PP_LOW_FAST);
}


void pwm_set_duty_cycle (uint8_t value)
{
  ui8_duty_cycle_target = value;
}

void pwm_init (void)
{
// TIM1 Peripheral Configuration
  TIM1_DeInit();

#if (SVM_TABLE == SVM)
  TIM1_TimeBaseInit(0, // TIM1_Prescaler = 0
		    TIM1_COUNTERMODE_CENTERALIGNED1,
		    (512 - 1), // clock = 16MHz; counter period = 1024; PWM freq = 16MHz / 1024 = 15.625kHz;
		    //(BUT PWM center aligned mode needs twice the frequency)
		    1); // will fire the TIM1_IT_UPDATE at every PWM period cycle
#elif (SVM_TABLE == SINE) || (SVM_TABLE == SINE_SVM)
  TIM1_TimeBaseInit(0, // TIM1_Prescaler = 0
		    TIM1_COUNTERMODE_UP,
		    (1024 - 1), // clock = 16MHz; counter period = 1024; PWM freq = 16MHz / 1024 = 15.625kHz;
		    0); // will fire the TIM1_IT_UPDATE at every PWM period
#endif


//#define DISABLE_PWM_CHANNELS_1_3

  TIM1_OC1Init(TIM1_OCMODE_PWM1,
#ifdef DISABLE_PWM_CHANNELS_1_3
	       TIM1_OUTPUTSTATE_DISABLE,
	       TIM1_OUTPUTNSTATE_DISABLE,
#else
	       TIM1_OUTPUTSTATE_ENABLE,
	       TIM1_OUTPUTNSTATE_ENABLE,
#endif
	       0, // initial duty_cycle value
	       TIM1_OCPOLARITY_HIGH,
	       TIM1_OCNPOLARITY_LOW,
	       TIM1_OCIDLESTATE_RESET,
	       TIM1_OCNIDLESTATE_SET);

  TIM1_OC2Init(TIM1_OCMODE_PWM1,
	       TIM1_OUTPUTSTATE_ENABLE,
	       TIM1_OUTPUTNSTATE_ENABLE,
	       0, // initial duty_cycle value
	       TIM1_OCPOLARITY_HIGH,
	       TIM1_OCNPOLARITY_LOW,
	       TIM1_OCIDLESTATE_RESET,
	       TIM1_OCNIDLESTATE_SET);

  TIM1_OC3Init(TIM1_OCMODE_PWM1,
#ifdef DISABLE_PWM_CHANNELS_1_3
	       TIM1_OUTPUTSTATE_DISABLE,
	       TIM1_OUTPUTNSTATE_DISABLE,
#else
	       TIM1_OUTPUTSTATE_ENABLE,
	       TIM1_OUTPUTNSTATE_ENABLE,
#endif
	       0, // initial duty_cycle value
	       TIM1_OCPOLARITY_HIGH,
	       TIM1_OCNPOLARITY_LOW,
	       TIM1_OCIDLESTATE_RESET,
	       TIM1_OCNIDLESTATE_SET);

  // break, dead time and lock configuration
  TIM1_BDTRConfig(TIM1_OSSISTATE_ENABLE,
		  TIM1_LOCKLEVEL_OFF,
		  // hardware nees a dead time of 1us
		  16, // DTG = 0; dead time in 62.5 ns steps; 1us/62.5ns = 16
		  TIM1_BREAK_DISABLE,
		  TIM1_BREAKPOLARITY_LOW,
		  TIM1_AUTOMATICOUTPUT_DISABLE);

  TIM1_ITConfig(TIM1_IT_UPDATE, ENABLE);

  TIM1_Cmd(ENABLE); // TIM1 counter enable
  TIM1_CtrlPWMOutputs(ENABLE); // main Output Enable
}

void pwm_duty_cycle_controller (void)
{
  // limit PWM increase/decrease rate
  static uint8_t ui8_counter;
  if (ui8_counter++ > PWM_DUTY_CYCLE_CONTROLLER_COUNTER)
  {
    ui8_counter = 0;

    // increment or decrement duty_cycle
    if (ui8_duty_cycle_target > ui8_duty_cycle) { ui8_duty_cycle++; }
    else if (ui8_duty_cycle_target < ui8_duty_cycle) { ui8_duty_cycle--; }
  }

//#define DO_DUTY_CYCLE_RAMP 1
#if DO_DUTY_CYCLE_RAMP == 1
  pwm_apply_duty_cycle (ui8_duty_cycle);
#else
  pwm_apply_duty_cycle (ui8_duty_cycle_target);
#endif
}

void pwm_apply_duty_cycle (uint8_t ui8_duty_cycle_value)
{
#if (SVM_TABLE == SVM)
  static uint8_t ui8__duty_cycle;
  static uint8_t ui8_temp;

  ui8__duty_cycle = ui8_duty_cycle_value;

  // scale and apply _duty_cycle
  ui8_temp = ui8_svm_table[ui8_motor_rotor_position];
  if (ui8_temp > MIDDLE_PWM_VALUE_DUTY_CYCLE_MAX)
  {
    ui16_value = ((uint16_t) (ui8_temp - MIDDLE_PWM_VALUE_DUTY_CYCLE_MAX)) * ui8__duty_cycle;
    ui8_temp = (uint8_t) (ui16_value >> 8);
    ui8_value_a = MIDDLE_PWM_VALUE_DUTY_CYCLE_MAX + ui8_temp;
  }
  else
  {
    ui16_value = ((uint16_t) (MIDDLE_PWM_VALUE_DUTY_CYCLE_MAX - ui8_temp)) * ui8__duty_cycle;
    ui8_temp = (uint8_t) (ui16_value >> 8);
    ui8_value_a = MIDDLE_PWM_VALUE_DUTY_CYCLE_MAX - ui8_temp;
  }

  // add 120 degrees and limit
  ui8_temp = ui8_svm_table[(uint8_t) (ui8_motor_rotor_position + 85 /* 120º */)];
  if (ui8_temp > MIDDLE_PWM_VALUE_DUTY_CYCLE_MAX)
  {
    ui16_value = ((uint16_t) (ui8_temp - MIDDLE_PWM_VALUE_DUTY_CYCLE_MAX)) * ui8__duty_cycle;
    ui8_temp = (uint8_t) (ui16_value >> 8);
    ui8_value_b = MIDDLE_PWM_VALUE_DUTY_CYCLE_MAX + ui8_temp;
  }
  else
  {
    ui16_value = ((uint16_t) (MIDDLE_PWM_VALUE_DUTY_CYCLE_MAX - ui8_temp)) * ui8__duty_cycle;
    ui8_temp = (uint8_t) (ui16_value >> 8);
    ui8_value_b = MIDDLE_PWM_VALUE_DUTY_CYCLE_MAX - ui8_temp;
  }

  // subtract 120 degrees and limit
  ui8_temp = ui8_svm_table[(uint8_t) (ui8_motor_rotor_position + 171 /* 240º */)];
  if (ui8_temp > MIDDLE_PWM_VALUE_DUTY_CYCLE_MAX)
  {
    ui16_value = ((uint16_t) (ui8_temp - MIDDLE_PWM_VALUE_DUTY_CYCLE_MAX)) * ui8__duty_cycle;
    ui8_temp = (uint8_t) (ui16_value >> 8);
    ui8_value_c = MIDDLE_PWM_VALUE_DUTY_CYCLE_MAX + ui8_temp;
  }
  else
  {
    ui16_value = ((uint16_t) (MIDDLE_PWM_VALUE_DUTY_CYCLE_MAX - ui8_temp)) * ui8__duty_cycle;
    ui8_temp = (uint8_t) (ui16_value >> 8);
    ui8_value_c = MIDDLE_PWM_VALUE_DUTY_CYCLE_MAX - ui8_temp;
  }

  // set final duty_cycle value
  TIM1_SetCompare1((uint16_t) (ui8_value_a << 1));
  TIM1_SetCompare2((uint16_t) (ui8_value_c << 1));
  TIM1_SetCompare3((uint16_t) (ui8_value_b << 1));
#elif (SVM_TABLE == SINE) || (SVM_TABLE == SINE_SVM)
  // scale and apply _duty_cycle
  ui8_value_a = ui8_svm_table[ui8_motor_rotor_position];
  ui16_value = (uint16_t) (ui8_value_a * ui8_duty_cycle_value);
  ui8_value_a = (uint8_t) (ui16_value >> 8);

  // add 120 degrees and limit
  ui8_value_b = ui8_svm_table[(uint8_t) (ui8_motor_rotor_position + 85 /* 120º */)];
  ui16_value = (uint16_t) (ui8_value_b * ui8_duty_cycle_value);
  ui8_value_b = (uint8_t) (ui16_value >> 8);

  // subtract 120 degrees and limit
  ui8_value_c = ui8_svm_table[(uint8_t) (ui8_motor_rotor_position + 171 /* 240º */)];
  ui16_value = (uint16_t) (ui8_value_c * ui8_duty_cycle_value);
  ui8_value_c = (uint8_t) (ui16_value >> 8);

  // set final duty_cycle value
  TIM1_SetCompare1((uint16_t) (ui8_value_a << 2));
  TIM1_SetCompare2((uint16_t) (ui8_value_c << 2));
  TIM1_SetCompare3((uint16_t) (ui8_value_b << 2));
#endif
}

