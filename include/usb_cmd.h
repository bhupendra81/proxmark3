//-----------------------------------------------------------------------------
// Jonathan Westhues, Mar 2006
// Edits by Gerhard de Koning Gans, Sep 2007
//
// This code is licensed to you under the terms of the GNU GPL, version 2 or,
// at your option, any later version. See the LICENSE.txt file for the text of
// the license.
//-----------------------------------------------------------------------------
// Definitions for all the types of commands that may be sent over USB; our
// own protocol.
//-----------------------------------------------------------------------------

#ifndef __USB_CMD_H
#define __USB_CMD_H
#ifdef _MSC_VER
typedef DWORD uint32_t;
typedef BYTE uint8_t;
#define PACKED
// stuff
#else
#include <stdint.h>
#include <stdbool.h>
#define PACKED __attribute__((packed))
#endif

#define USB_CMD_DATA_SIZE 512

typedef struct {
  uint64_t cmd;
  uint64_t arg[3];
  union {
    uint8_t  asBytes[USB_CMD_DATA_SIZE];
    uint32_t asDwords[USB_CMD_DATA_SIZE/4];
  } d;
} PACKED UsbCommand;
// A struct used to send sample-configs over USB
typedef struct{
	uint8_t decimation;
	uint8_t bits_per_sample;
	bool averaging;
	int divisor;
	int trigger_threshold;
} sample_config;

// For the bootloader
#define CMD_DEVICE_INFO                                                   0x0000
#define CMD_SETUP_WRITE                                                   0x0001
#define CMD_FINISH_WRITE                                                  0x0003
#define CMD_HARDWARE_RESET                                                0x0004
#define CMD_START_FLASH                                                   0x0005
#define CMD_NACK                                                          0x00fe
#define CMD_ACK                                                           0x00ff

// For general mucking around
#define CMD_DEBUG_PRINT_STRING                                            0x0100
#define CMD_DEBUG_PRINT_INTEGERS                                          0x0101
#define CMD_DEBUG_PRINT_BYTES                                             0x0102
#define CMD_LCD_RESET                                                     0x0103
#define CMD_LCD                                                           0x0104
#define CMD_BUFF_CLEAR                                                    0x0105
#define CMD_READ_MEM                                                      0x0106
#define CMD_VERSION                                                       0x0107

// For low-frequency tags
#define CMD_READ_TI_TYPE                                                  0x0202
#define CMD_WRITE_TI_TYPE                                                 0x0203
#define CMD_DOWNLOADED_RAW_BITS_TI_TYPE                                   0x0204
#define CMD_ACQUIRE_RAW_ADC_SAMPLES_125K                                  0x0205
#define CMD_MOD_THEN_ACQUIRE_RAW_ADC_SAMPLES_125K                         0x0206
#define CMD_DOWNLOAD_RAW_ADC_SAMPLES_125K                                 0x0207
#define CMD_DOWNLOADED_RAW_ADC_SAMPLES_125K                               0x0208
#define CMD_DOWNLOADED_SIM_SAMPLES_125K                                   0x0209
#define CMD_SIMULATE_TAG_125K                                             0x020A
#define CMD_HID_DEMOD_FSK                                                 0x020B
#define CMD_HID_SIM_TAG                                                   0x020C
#define CMD_SET_LF_DIVISOR                                                0x020D
#define CMD_LF_SIMULATE_BIDIR                                             0x020E
#define CMD_SET_ADC_MUX                                                   0x020F
#define CMD_HID_CLONE_TAG                                                 0x0210
#define CMD_EM410X_WRITE_TAG                                              0x0211
#define CMD_INDALA_CLONE_TAG                                              0x0212
// for 224 bits UID
#define CMD_INDALA_CLONE_TAG_L                                            0x0213
#define CMD_T55XX_READ_BLOCK                                              0x0214
#define CMD_T55XX_WRITE_BLOCK                                             0x0215
#define CMD_T55XX_READ_TRACE                                              0x0216
#define CMD_PCF7931_READ                                                  0x0217
#define CMD_EM4X_READ_WORD                                                0x0218
#define CMD_EM4X_WRITE_WORD                                               0x0219
#define CMD_IO_DEMOD_FSK                                                  0x021A
#define CMD_IO_CLONE_TAG                                                  0x021B
#define CMD_EM410X_DEMOD  												  0x021c
// Sampling configuration for LF reader/snooper
#define CMD_SET_LF_SAMPLING_CONFIG                                        0x021d

/* CMD_SET_ADC_MUX: ext1 is 0 for lopkd, 1 for loraw, 2 for hipkd, 3 for hiraw */

// For the 13.56 MHz tags
#define CMD_ACQUIRE_RAW_ADC_SAMPLES_ISO_15693                             0x0300
#define CMD_ACQUIRE_RAW_ADC_SAMPLES_ISO_14443                             0x0301
#define CMD_READ_SRI512_TAG                                               0x0303
#define CMD_READ_SRIX4K_TAG                                               0x0304
#define CMD_ISO_14443B_COMMAND                                            0x0305
#define CMD_READER_ISO_15693                                              0x0310
#define CMD_SIMTAG_ISO_15693                                              0x0311
#define CMD_RECORD_RAW_ADC_SAMPLES_ISO_15693                              0x0312
#define CMD_ISO_15693_COMMAND                                             0x0313
#define CMD_ISO_15693_COMMAND_DONE                                        0x0314
#define CMD_ISO_15693_FIND_AFI                                            0x0315
#define CMD_ISO_15693_DEBUG                                               0x0316
#define CMD_LF_SNOOP_RAW_ADC_SAMPLES                                      0x0317

// For Hitag2 transponders
#define CMD_SNOOP_HITAG                                                   0x0370
#define CMD_SIMULATE_HITAG                                                0x0371
#define CMD_READER_HITAG                                                  0x0372

#define CMD_SIMULATE_TAG_HF_LISTEN                                        0x0380
#define CMD_SIMULATE_TAG_ISO_14443                                        0x0381
#define CMD_SNOOP_ISO_14443                                               0x0382
#define CMD_SNOOP_ISO_14443a                                              0x0383
#define CMD_SIMULATE_TAG_ISO_14443a                                       0x0384
#define CMD_READER_ISO_14443a                                             0x0385
#define CMD_SIMULATE_TAG_LEGIC_RF                                         0x0387
#define CMD_READER_LEGIC_RF                                               0x0388
#define CMD_WRITER_LEGIC_RF                                               0x0389
#define CMD_EPA_PACE_COLLECT_NONCE                                        0x038A

#define CMD_SNOOP_ICLASS                                                  0x0392
#define CMD_SIMULATE_TAG_ICLASS                                           0x0393
#define CMD_READER_ICLASS                                                 0x0394
#define CMD_READER_ICLASS_REPLAY					  					  0x0395
#define CMD_ICLASS_ISO14443A_WRITE										  0x0397
#define CMD_ICLASS_EML_MEMSET                                             0x0398

// For measurements of the antenna tuning
#define CMD_MEASURE_ANTENNA_TUNING                                        0x0400
#define CMD_MEASURE_ANTENNA_TUNING_HF                                     0x0401
#define CMD_MEASURED_ANTENNA_TUNING                                       0x0410
#define CMD_LISTEN_READER_FIELD                                           0x0420

// For direct FPGA control
#define CMD_FPGA_MAJOR_MODE_OFF                                           0x0500

// For mifare commands
#define CMD_MIFARE_SET_DBGMODE                                            0x0600
#define CMD_MIFARE_EML_MEMCLR                                             0x0601
#define CMD_MIFARE_EML_MEMSET                                             0x0602
#define CMD_MIFARE_EML_MEMGET                                             0x0603
#define CMD_MIFARE_EML_CARDLOAD                                           0x0604

// magic chinese card commands
#define CMD_MIFARE_CSETBLOCK                                              0x0605
#define CMD_MIFARE_CGETBLOCK                                              0x0606
#define CMD_MIFARE_CIDENT                                                 0x0607

#define CMD_SIMULATE_MIFARE_CARD                                          0x0610

#define CMD_READER_MIFARE                                                 0x0611
#define CMD_MIFARE_NESTED                                                 0x0612

#define CMD_MIFARE_READBL                                                 0x0620
#define CMD_MIFAREU_READBL						  0x0720
#define CMD_MIFARE_READSC                                                 0x0621
#define CMD_MIFAREU_READCARD						  0x0721
#define CMD_MIFARE_WRITEBL                                                0x0622
#define CMD_MIFAREU_WRITEBL						                          0x0722
#define CMD_MIFAREU_WRITEBL_COMPAT					                      0x0723

#define CMD_MIFARE_CHKKEYS                                                0x0623

#define CMD_MIFARE_SNIFFER                                                0x0630
//ultralightC
#define CMD_MIFAREUC_AUTH1						                          0x0724
#define CMD_MIFAREUC_AUTH2						                          0x0725
#define CMD_MIFAREUC_READCARD						                      0x0726

// mifare desfire
#define CMD_MIFARE_DESFIRE_READBL                                         0x0728
#define CMD_MIFARE_DESFIRE_WRITEBL                                        0x0729
#define CMD_MIFARE_DESFIRE_AUTH1                                          0x072a
#define CMD_MIFARE_DESFIRE_AUTH2                                          0x072b
#define CMD_MIFARE_DES_READER                                             0x072c
#define CMD_MIFARE_DESFIRE_INFO                                           0x072d
#define CMD_MIFARE_DESFIRE                                                0x072e

#define CMD_UNKNOWN                                                       0xFFFF


//Mifare simulation flags
#define FLAG_INTERACTIVE 0x01
#define FLAG_4B_UID_IN_DATA 0x02
#define FLAG_7B_UID_IN_DATA 0x04
#define FLAG_NR_AR_ATTACK 0x08


//Iclass reader flags
#define FLAG_ICLASS_READER_ONLY_ONCE    0x01
#define FLAG_ICLASS_READER_GET_CC       0x02


// CMD_DEVICE_INFO response packet has flags in arg[0], flag definitions:
/* Whether a bootloader that understands the common_area is present */
#define DEVICE_INFO_FLAG_BOOTROM_PRESENT         	(1<<0)

/* Whether a osimage that understands the common_area is present */
#define DEVICE_INFO_FLAG_OSIMAGE_PRESENT         	(1<<1)

/* Set if the bootloader is currently executing */
#define DEVICE_INFO_FLAG_CURRENT_MODE_BOOTROM    	(1<<2)

/* Set if the OS is currently executing */
#define DEVICE_INFO_FLAG_CURRENT_MODE_OS         	(1<<3)

/* Set if this device understands the extend start flash command */
#define DEVICE_INFO_FLAG_UNDERSTANDS_START_FLASH 	(1<<4)

/* CMD_START_FLASH may have three arguments: start of area to flash,
   end of area to flash, optional magic.
   The bootrom will not allow to overwrite itself unless this magic
   is given as third parameter */

#define START_FLASH_MAGIC 0x54494f44 // 'DOIT'

#endif
