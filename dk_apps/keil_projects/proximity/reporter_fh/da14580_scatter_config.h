/**
 ****************************************************************************************
 *
 * @file da14580_scatter_config.h
 *
 * @brief Common scatter file definition file.
 *
 * Copyright (C) 2014. Dialog Semiconductor Ltd, unpublished work. This computer 
 * program includes Confidential, Proprietary Information and is a Trade Secret of 
 * Dialog Semiconductor Ltd.  All use, disclosure, and/or reproduction is prohibited 
 * unless authorized in writing. All Rights Reserved.
 *
 * <bluetooth.support@diasemi.com> and contributors.
 *
 ****************************************************************************************
 */

#ifndef DA14580_SCATTER_CONFIG_H_
#define DA14580_SCATTER_CONFIG_H_

/******************************************
 * DO NOT ALTER
 ******************************************/

#define DB_HEAP_SIZE            (1024 + 12)

#if (BLE_CONNECTION_MAX_USER == 1)
#define NON_RET_HEAP_SIZE       (1024 + 12)
#define ENV_HEAP_SIZE           (328 + 12)
#define MSG_HEAP_SIZE           (1312 + 12)

#elif (BLE_CONNECTION_MAX_USER == 2)
#define NON_RET_HEAP_SIZE       (2048 + 12)
#define ENV_HEAP_SIZE           (656 + 12)
#define MSG_HEAP_SIZE           (2016 + 12)

#elif (BLE_CONNECTION_MAX_USER == 3)
#define NON_RET_HEAP_SIZE       (2048 + 12)
#define ENV_HEAP_SIZE           (984 + 12)
#define MSG_HEAP_SIZE           (2720 + 12)

#elif (BLE_CONNECTION_MAX_USER == 4)
#define NON_RET_HEAP_SIZE       (2048 + 12)
#define ENV_HEAP_SIZE           (1312 + 12)
#define MSG_HEAP_SIZE           (3424 + 12)

#elif (BLE_CONNECTION_MAX_USER == 5)
#define NON_RET_HEAP_SIZE       (2048 + 12)
#define ENV_HEAP_SIZE           (1640 + 12)
#define MSG_HEAP_SIZE           (4128 + 12)

#elif (BLE_CONNECTION_MAX_USER == 6)
#define NON_RET_HEAP_SIZE       (2048 + 12)
#define ENV_HEAP_SIZE           (1968 + 12)
#define MSG_HEAP_SIZE           (4832 + 12)

#endif // BLE_CONNECTION_MAX_USER

// If the user defines the sizes then automatic calculation is overriden
#if ( (BLE_CONNECTION_MAX_USER > 1) && !defined(MSG_HEAP_SZ) && (USE_MEMORY_MAP != EXT_SLEEP_SETUP) )
#error "Memory map error! When BLE_CONNECTION_MAX_USER is bigger than 1, the constants from the excel tool must be used in da14580_config.h"
#endif

#ifdef DB_HEAP_SZ
#undef DB_HEAP_SIZE
#define DB_HEAP_SIZE            (DB_HEAP_SZ + 12)
#endif

#ifdef NON_RET_HEAP_SZ
#undef NON_RET_HEAP_SIZE
#define NON_RET_HEAP_SIZE       (NON_RET_HEAP_SZ + 12)
#endif

#ifdef ENV_HEAP_SZ
#undef ENV_HEAP_SIZE
#define ENV_HEAP_SIZE           (ENV_HEAP_SZ + 12)
#endif

#ifdef MSG_HEAP_SZ
#undef MSG_HEAP_SIZE
#define MSG_HEAP_SIZE           (MSG_HEAP_SZ + 12)
#endif


#define DESCRIPT_BUF_SIZE       (1502 + 2)

/*
 * Scaterfile: Memory maps
 */
#ifdef CFG_DEEP_SLEEP
#if (USE_MEMORY_MAP == EXT_SLEEP_SETUP)
#error "Memory map error! Device configured for Deep Sleep but the chosen Memory Map is not correct."
#endif
#endif // CFG_DEEP_SLEEP

#ifdef CFG_EXT_SLEEP
#if (USE_MEMORY_MAP != EXT_SLEEP_SETUP)
#warning "Memory map: Device configured for Extended Sleep but the chosen Memory Map applies for Deep Sleep. Please check if Deep Sleep can be used!"
#endif
#endif // CFG_EXT_SLEEP

#if ( (USE_MEMORY_MAP == EXT_SLEEP_SETUP) && (REINIT_DESCRIPT_BUF == 1) )
#warning "Memory map: re-init of descript is not necessary in Extended Sleep mode."
#undef REINIT_DESCRIPT_BUF
#define REINIT_DESCRIPT_BUF     (0)
#endif

#if ( (BLE_CONNECTION_MAX_USER < 1) || (BLE_CONNECTION_MAX_USER > 6) )
#error "Config error: the number of supported connections ranges from 1 to 6."
#endif


#if (REINIT_DESCRIPT_BUF == 0)
#define RETRAM_LEN              (0x1898 - DESCRIPT_BUF_SIZE)
#define ExtRETRAM_LEN           (0x1000)
#else
#define RETRAM_LEN              (0x1898)
#define ExtRETRAM_LEN           (0x1000 - DESCRIPT_BUF_SIZE)
#endif

#if (0x20009000 - NON_RET_HEAP_SIZE > 0x20008000)
#define ZI_AT_8000              ( (0x20009000 - NON_RET_HEAP_SIZE) - 0x20008000 )
#else
#define ZI_AT_8000              (0)
#endif

#endif // DA14580_SCATTER_CONFIG_H_
