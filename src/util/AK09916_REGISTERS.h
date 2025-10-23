#ifndef _AK09916_REGISTERS_H_
#define _AK09916_REGISTERS_H_

#include <stdint.h>

typedef enum
{
  // Addresses 00h to 18h, 30h to 32h are compliant with automatic increment
  // function of serial interface respectively. In other modes, read data is not
  // correct. When the address is in 00h to 18h, the address is incremented
  // 00h -> 01h -> 02h -> 03h -> 10h -> 11h -> ... -> 18h, and the address goes
  // back to 00h after 18h. When the address is in 30h to 32h, the address goes
  // back to 30h after 32h.

  // NOTE: the DMP expects to receive 2 bytes of header (contents don't matter
  // as far as I can see) and 3 words of data (6 bytes) in big endian format.
  // Further to this the DMP expects this data to be stored entirely by the
  // I2C Slave 0 peripheral. i.e. we cannot split the data up over multiple
  // I2C slave reads. Also, the Magnetometer expects for the ST2 register to
  // be read to confirm the data cycle as complete and to proceed with the
  // next reading. This is why we need to read 10 bytes of data starting 2
  // bytes before the HXL data register (RSV2).

  // Data Register Group
  AK09916_REG_WIA1 = 0x00,
  AK09916_REG_WIA2,
  AK09916_REG_RSV1,
  AK09916_REG_RSV2,
  // auto-inremented discontinuity
  AK09916_REG_ST1 = 0x10,
  AK09916_REG_HXL,
  AK09916_REG_HXH,
  AK09916_REG_HYL,
  AK09916_REG_HYH,
  AK09916_REG_HZL,
  AK09916_REG_HZH,
  AK09916_REG_TMPS, // Dummy
  AK09916_REG_ST2,

  // Control Register Group
  AK09916_REG_CNTL1 = 0x30, // Dummy
  AK09916_REG_CNTL2,
  AK09916_REG_CNTL3,
} AK09916_Reg_Addr_e;

typedef struct
{
  uint8_t WIA1;
} AK09916_WIA1_Reg_t;

typedef struct
{
  uint8_t WIA2;
} AK09916_WIA2_Reg_t;

typedef struct
{
  uint8_t DRDY : 1;
  uint8_t DOR : 1;
  uint8_t reserved_0 : 6;
} AK09916_ST1_Reg_t;

// typedef struct{

// }AK09916_HXL_Reg_t;

// typedef struct{

// }AK09916_HXH_Reg_t;
// typedef struct{

// }AK09916_HYL_Reg_t;
// typedef struct{

// }AK09916_HYH_Reg_t;
// typedef struct{

// }AK09916_HZL_Reg_t;
// typedef struct{

// }AK09916_HZH_Reg_t;

typedef struct
{
  uint8_t reserved_0 : 3;
  uint8_t HOFL : 1;
  uint8_t reserved_1 : 4;
} AK09916_ST2_Reg_t;

typedef struct
{
  uint8_t MODE : 5;
  uint8_t reserved_0 : 3;
} AK09916_CNTL2_Reg_t;

typedef struct
{
  uint8_t SRST : 1;
  uint8_t reserved_0 : 7;
} AK09916_CNTL3_Reg_t;

#endif // _AK09916_REGISTERS_H_
