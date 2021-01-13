/* ===========================================================================

                     CONFIDENTIAL VISTEON CORPORATION

  This is an unpublished work of authorship, which contains trade secrets,
  created in 2006.  Visteon Corporation owns all rights to this work and
  intends to maintain it in confidence to preserve its trade secret status.
  Visteon Corporation reserves the right, under the copyright laws of the
  United States or those of any other country that may have jurisdiction, to
  protect this work as an unpublished work, in the event of an inadvertent
  or deliberate unauthorized publication.  Visteon Corporation also reserves
  its rights under all copyright laws to protect this work as a published
  work, when appropriate.  Those having access to this work may not copy it,
  use it, modify it or disclose the information contained in it without the
  written authorization of Visteon Corporation.

 =========================================================================*/

/* ===========================================================================

  Name:           Can_Il_Par_Cfg.c

  Description:    CAN Interaction Layer Tx and Rx Parameters Configurations

                  Application Specific Tx and Rx Message and Signal
                  Data Structure Definitions

  Organization:   Multiplex Subsystems

 =========================================================================*/

/* ===========================================================================
  I N C L U D E   F I L E S
 =========================================================================*/ 

//#ifdef CANIL_IFSUPPORT

#include "Can_GeneralTypes.h"
#include <CclStack_Types.h>

//#endif

#include "CanIl_Util.h"
#include "CanIl.h"
#include "CanIl_Par_Cfg.h" 

CAN_UINT16 Can_Ch0_Il_Tx_Periodic_Count[ Can_Ch0_Il_Tx_Num_Periodic ];

#ifdef CAN_IL_TX_BURST_MODE

 #if ( Can_Ch0_Il_Tx_Num_Burst_Periodic > 0 )

CAN_UINT8 Can_Ch0_Il_Tx_Burst_Count[ Can_Ch0_Il_Tx_Num_Burst_Periodic ];

 #endif

#endif

/* ===========================================================================
  M E M O R Y   A L L O C A T I O N
 =========================================================================*/
/* ===========================================================================
  Interaction Layer Transmit Frame Status and Data Storage
 =========================================================================*/
CAN_UINT8 Can_Ch0_Il_Tx_Frame_Data[ Can_Ch0_Il_Tx_Num_Messages ][ CAN_MAX_DATA_LENGTH ];


CAN_UINT8 Can_Ch0_Il_Tx_Frame_Status[ Can_Ch0_Il_Tx_Num_Messages ];


CAN_UINT16 Can_Ch0_Il_Tx_Delay_Count[ Can_Ch0_Il_Tx_Num_Messages ]; 

/* ===========================================================================
  TRANSMIT DATA STRUCTURES
 =========================================================================*/

/* ===========================================================================
  Interaction Layer Transmit Signal Descriptors

 The Following Table Definition Assumes a Motorola (Big Endian) Byte
 Ordering of Bytes within the CAN Frame. As an example, if a 16bit signal
 is defined in Bytes 0 and 1 of the CAN frame, the MSByte is Byte 0 and the
 LSByte is Byte 1.

 =========================================================================*/
CAN_IL_SIGNAL const
Can_Ch0_Il_Tx_Signals[ Can_Ch0_Il_Tx_Num_Signals ] ={\
/*  CAN Frame,                                Num Bytes,       MS Byte,     MS Bit,          LS Byte,       LS Bit   */
{  Can_Ch0_Il_Tx_Msg_IC_0x386_TMH,                1,             0,             7,             0,             7  },  /*IC_BSDSoundSts*/   /*IC_0x386*/\
{  Can_Ch0_Il_Tx_Msg_IC_0x387_TMH,                1,             0,             7,             0,             1  },  /*IC_Fuel_level*/   /*IC_0x387*/\
{  Can_Ch0_Il_Tx_Msg_IC_0x387_TMH,                1,             1,             7,             1,             1  },  /*IC_DriveTimehour*/   /*IC_0x387*/\
{  Can_Ch0_Il_Tx_Msg_IC_0x387_TMH,                1,             2,             7,             2,             2  },  /*IC_DriveTimeMinute*/   /*IC_0x387*/\
{  Can_Ch0_Il_Tx_Msg_IC_0x387_TMH,                1,             3,             7,             3,             0  },  /*IC_AverageSpeed*/   /*IC_0x387*/\
{  Can_Ch0_Il_Tx_Msg_IC_0x387_TMH,                2,             4,             7,             5,             2  },  /*IC_ChangOilDistance*/   /*IC_0x387*/\
{  Can_Ch0_Il_Tx_Msg_IC_0x387_TMH,                3,             5,             1,             7,             0  },  /*BackUpODO*/   /*IC_0x387*/\
{  Can_Ch0_Il_Tx_Msg_IC_0x38A_TMH,                1,             0,             0,             0,             0  },  /*IC_ABSLamp*/   /*IC_0x38A*/\
{  Can_Ch0_Il_Tx_Msg_IC_0x38A_TMH,                1,             0,             1,             0,             1  },  /*IC_EBDFaultLamp*/   /*IC_0x38A*/\
{  Can_Ch0_Il_Tx_Msg_IC_0x38A_TMH,                1,             0,             2,             0,             2  },  /*IC_BrakefluidLowLamp*/   /*IC_0x38A*/\
{  Can_Ch0_Il_Tx_Msg_IC_0x38A_TMH,                1,             0,             4,             0,             3  },  /*IC_APBFaultLamp*/   /*IC_0x38A*/\
{  Can_Ch0_Il_Tx_Msg_IC_0x38A_TMH,                1,             0,             6,             0,             5  },  /*IC_APBLamp*/   /*IC_0x38A*/\
{  Can_Ch0_Il_Tx_Msg_IC_0x38A_TMH,                1,             0,             7,             0,             7  },  /*IC_AVHLamp*/   /*IC_0x38A*/\
{  Can_Ch0_Il_Tx_Msg_IC_0x38A_TMH,                1,             1,             0,             1,             0  },  /*IC_BatteryLamp*/   /*IC_0x38A*/\
{  Can_Ch0_Il_Tx_Msg_IC_0x38A_TMH,                1,             1,             1,             1,             1  },  /*IC_CoolantHighLamp*/   /*IC_0x38A*/\
{  Can_Ch0_Il_Tx_Msg_IC_0x38A_TMH,                1,             1,             2,             1,             2  },  /*IC_FuelLowLamp*/   /*IC_0x38A*/\
{  Can_Ch0_Il_Tx_Msg_IC_0x38A_TMH,                1,             1,             3,             1,             3  },  /*IC_OilpressureLowLamp*/   /*IC_0x38A*/\
{  Can_Ch0_Il_Tx_Msg_IC_0x38A_TMH,                1,             1,             4,             1,             4  },  /*IC_EngineMaintainLamp*/   /*IC_0x38A*/\
{  Can_Ch0_Il_Tx_Msg_IC_0x38A_TMH,                1,             1,             5,             1,             5  },  /*IC_EngineFaultLamp*/   /*IC_0x38A*/\
{  Can_Ch0_Il_Tx_Msg_IC_0x38A_TMH,                1,             1,             7,             1,             6  },  /*IC_ESPLamp*/   /*IC_0x38A*/\
{  Can_Ch0_Il_Tx_Msg_IC_0x38A_TMH,                1,             2,             1,             2,             0  },  /*IC_AntitheftLamp*/   /*IC_0x38A*/\
{  Can_Ch0_Il_Tx_Msg_IC_0x38A_TMH,                1,             2,             3,             2,             3  },  /*IC_ACCFaultLamp*/   /*IC_0x38A*/\
{  Can_Ch0_Il_Tx_Msg_IC_0x38A_TMH,                1,             2,             5,             2,             4  },  /*IC_ACCLamp*/   /*IC_0x38A*/\
{  Can_Ch0_Il_Tx_Msg_IC_0x38A_TMH,                1,             2,             7,             2,             6  },  /*IC_SRSLamp*/   /*IC_0x38A*/\
{  Can_Ch0_Il_Tx_Msg_IC_0x38A_TMH,                1,             3,             0,             3,             0  },  /*IC_TPMSLamp*/   /*IC_0x38A*/\
{  Can_Ch0_Il_Tx_Msg_IC_0x38A_TMH,                1,             3,             1,             3,             1  },  /*IC_TCUServiceLamp*/   /*IC_0x38A*/\
{  Can_Ch0_Il_Tx_Msg_IC_0x38A_TMH,                1,             3,             2,             3,             2  },  /*IC_EPSFaultLamp*/   /*IC_0x38A*/\
{  Can_Ch0_Il_Tx_Msg_IC_0x38A_TMH,                1,             3,             3,             3,             3  },  /*IC_EPSLamp*/   /*IC_0x38A*/\
{  Can_Ch0_Il_Tx_Msg_IC_0x38A_TMH,                1,             3,             4,             3,             4  },  /*IC_SSSystemFaultLamp*/   /*IC_0x38A*/\
{  Can_Ch0_Il_Tx_Msg_IC_0x38A_TMH,                1,             3,             6,             3,             6  },  /*IC_ESCLLamp*/   /*IC_0x38A*/\
{  Can_Ch0_Il_Tx_Msg_IC_0x38A_TMH,                1,             3,             7,             3,             7  },  /*IC_PEPSLamp*/   /*IC_0x38A*/\
{  Can_Ch0_Il_Tx_Msg_IC_0x38A_TMH,                1,             4,             0,             4,             0  },  /*IC_InsulationLamp*/   /*IC_0x38A*/\
{  Can_Ch0_Il_Tx_Msg_IC_0x38A_TMH,                1,             4,             1,             4,             1  },  /*IC_VehFailGradeWarning*/   /*IC_0x38A*/\
{  Can_Ch0_Il_Tx_Msg_IC_0x38A_TMH,                1,             4,             2,             4,             2  },  /*IC_EVSystemLamp*/   /*IC_0x38A*/\
{  Can_Ch0_Il_Tx_Msg_IC_0x38A_TMH,                1,             4,             3,             4,             3  },  /*IC_ThermalRunaywaWarning*/   /*IC_0x38A*/\
{  Can_Ch0_Il_Tx_Msg_IC_0x38A_TMH,                1,             4,             4,             4,             4  },  /*IC_SOClowWarning*/   /*IC_0x38A*/\
{  Can_Ch0_Il_Tx_Msg_IC_0x38A_TMH,                1,             4,             5,             4,             5  },  /*IC_HandbrakeLamp*/   /*IC_0x38A*/\
{  Can_Ch0_Il_Tx_Msg_IC_0x38A_TMH,                1,             4,             7,             4,             6  },  /*IC_48VSystemFaultLamp*/   /*IC_0x38A*/\
{  Can_Ch0_Il_Tx_Msg_IC_0x38A_TMH,                1,             5,             3,             5,             3  },  /*IC_MotorTemHighLamp*/   /*IC_0x38A*/\
{  Can_Ch0_Il_Tx_Msg_IC_0x38A_TMH,                1,             5,             4,             5,             4  },  /*IC_MotorRestLamp*/   /*IC_0x38A*/\
{  Can_Ch0_Il_Tx_Msg_IC_0x38A_TMH,                1,             5,             5,             5,             5  },  /*IC_DCDCLamp*/   /*IC_0x38A*/\
{  Can_Ch0_Il_Tx_Msg_IC_0x38A_TMH,                1,             5,             6,             5,             6  },  /*IC_MotorLamp*/   /*IC_0x38A*/\
{  Can_Ch0_Il_Tx_Msg_IC_0x38A_TMH,                1,             5,             7,             5,             7  },  /*IC_PackSystemLamp*/   /*IC_0x38A*/\
{  Can_Ch0_Il_Tx_Msg_IC_0x510_TMH,                3,             0,             7,             2,             0  },  /*IC_OdometerMasterValue*/   /*IC_0x510*/\
{  Can_Ch0_Il_Tx_Msg_IC_0x510_TMH,                1,             3,             0,             4,             6  },  /*IC_AirbagTelltaleBehavior*/   /*IC_0x510*/\
{  Can_Ch0_Il_Tx_Msg_IC_0x510_TMH,                1,             3,             4,             3,             4  },  /*IC_VehBrkPump_ERR_IC*/   /*IC_0x510*/\
{  Can_Ch0_Il_Tx_Msg_IC_0x510_TMH,                1,             3,             5,             3,             5  },  /*IC_DISFail*/   /*IC_0x510*/\
{  Can_Ch0_Il_Tx_Msg_IC_0x510_TMH,                1,             3,             7,             3,             6  },  /*IC_QDashACCFail*/   /*IC_0x510*/\
{  Can_Ch0_Il_Tx_Msg_IC_0x510_TMH,                2,             4,             5,             5,             5  },  /*IC_VehSpd_HMI*/   /*IC_0x510*/\
{  Can_Ch0_Il_Tx_Msg_IC_0x510_TMH,                1,             5,             3,             6,             4  },  /*BackupCountODO*/   /*IC_0x510*/\
{  Can_Ch0_Il_Tx_Msg_IC_0x510_TMH,                1,             6,             3,             6,             0  },  /*IC_Rolling_counter_0x510*/   /*IC_0x510*/\
{  Can_Ch0_Il_Tx_Msg_IC_0x510_TMH,                1,             7,             7,             7,             0  },  /*IC_Checksum_0x510*/   /*IC_0x510*/\
{  Can_Ch0_Il_Tx_Msg_IC_0x511_TMH,                1,             0,             0,             1,             6  },  /*IC_TemperatureUnitsSetting*/   /*IC_0x511*/\
{  Can_Ch0_Il_Tx_Msg_IC_0x511_TMH,                1,             0,             3,             0,             1  },  /*IC_MileageUnitsSetting*/   /*IC_0x511*/\
{  Can_Ch0_Il_Tx_Msg_IC_0x511_TMH,                1,             0,             7,             0,             4  },  /*IC_LanguageSetting*/   /*IC_0x511*/\
{  Can_Ch0_Il_Tx_Msg_IC_0x511_TMH,                1,             1,             2,             1,             0  },  /*IC_AFCUnitsSetting*/   /*IC_0x511*/\
{  Can_Ch0_Il_Tx_Msg_IC_0x511_TMH,                1,             1,             5,             1,             3  },  /*IC_PressureUnitsSetting*/   /*IC_0x511*/\
{  Can_Ch0_Il_Tx_Msg_IC_0x525_TMH,                2,             0,             7,             1,             7  },  /*IC_AFC*/   /*IC_0x525*/\
{  Can_Ch0_Il_Tx_Msg_IC_0x525_TMH,                2,             1,             3,             2,             0  },  /*IC_DTE*/   /*IC_0x525*/\
{  Can_Ch0_Il_Tx_Msg_IC_0x525_TMH,                1,             1,             5,             1,             4  },  /*IC_AlarmStatus*/   /*IC_0x525*/\
{  Can_Ch0_Il_Tx_Msg_IC_0x525_TMH,                1,             1,             6,             1,             6  },  /*IC_AlarmOrNot*/   /*IC_0x525*/\
{  Can_Ch0_Il_Tx_Msg_IC_0x525_TMH,                1,             3,             4,             3,             2  },  /*IC_AFC_Type*/   /*IC_0x525*/\
{  Can_Ch0_Il_Tx_Msg_IC_0x525_TMH,                2,             4,             7,             5,             3  },  /*IC_Fuel_Level_Volumn*/   /*IC_0x525*/\
{  Can_Ch0_Il_Tx_Msg_IC_0x525_TMH,                1,             5,             2,             5,             0  },  /*IC_Fuel_Level_VolumnQF*/   /*IC_0x525*/\
{  Can_Ch0_Il_Tx_Msg_IC_0x525_TMH,                1,             6,             3,             6,             0  },  /*IC_Rolling_counter_0x525*/   /*IC_0x525*/\
{  Can_Ch0_Il_Tx_Msg_IC_0x525_TMH,                1,             7,             7,             7,             0  },  /*IC_Checksum_0x525*/   /*IC_0x525*/\
{  Can_Ch0_Il_Tx_Msg_IC_time_0x581_TMH,           1,             0,             7,             0,             0  },  /*IC_Year*/   /*IC_time_0x581*/\
{  Can_Ch0_Il_Tx_Msg_IC_time_0x581_TMH,           1,             1,             7,             1,             0  },  /*IC_Month*/   /*IC_time_0x581*/\
{  Can_Ch0_Il_Tx_Msg_IC_time_0x581_TMH,           1,             2,             7,             2,             0  },  /*IC_Date*/   /*IC_time_0x581*/\
{  Can_Ch0_Il_Tx_Msg_IC_time_0x581_TMH,           1,             3,             7,             3,             0  },  /*IC_Hour*/   /*IC_time_0x581*/\
{  Can_Ch0_Il_Tx_Msg_IC_time_0x581_TMH,           1,             4,             7,             4,             0  },  /*IC_Minute*/   /*IC_time_0x581*/\
{  Can_Ch0_Il_Tx_Msg_IC_time_0x581_TMH,           1,             5,             7,             5,             0  },  /*IC_Second*/   /*IC_time_0x581*/\
};
/* ===========================================================================
  Interaction Layer Transmit Message Initialization Arrays

  The following transmit message initialization arrays define the initial
  values for all of the transmitted messages.

 =========================================================================*/

/*
 Sample Message Has 7 Signals, Each 1 Byte, for Initialization
 The order of the bytes in this array is as follows:
 Byte 0 - Signal 0, bit 1.7 Value = 0     C_SAMPLE*/
/*     IC_0x386   */
static CAN_UINT8 const Can_Ch0_Il_IC_0x386_Message_Init[1 ] = {0x00};
/*     IC_0x387   */
static CAN_UINT8 const Can_Ch0_Il_IC_0x387_Message_Init[9 ] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
/*     IC_0x38A   */
static CAN_UINT8 const Can_Ch0_Il_IC_0x38A_Message_Init[36 ] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
/*     IC_0x510   */
static CAN_UINT8 const Can_Ch0_Il_IC_0x510_Message_Init[12 ] = {0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
/*     IC_0x511   */
static CAN_UINT8 const Can_Ch0_Il_IC_0x511_Message_Init[5 ] = {0x00,0x00,0x00,0x00,0x00};
/*     IC_0x525   */
static CAN_UINT8 const Can_Ch0_Il_IC_0x525_Message_Init[12 ] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
/*     IC_time_0x581   */
static CAN_UINT8 const Can_Ch0_Il_IC_time_0x581_Message_Init[6 ] = {0x00,0x00,0x00,0x00,0x00,0x00};
/* ===========================================================================
  Interaction Layer Transmit Message Definition Table

  This table (array of transmit message data structures) defines each
  transmitted message. The data structure defines the number of signals in
  the message, the total number of bytes in the message, a pointer to the
  list of signal handles, and a pointer to the message initialization data
  bytes.

 =========================================================================*/

CAN_IL_TX_MESSAGE const
Can_Ch0_Il_Tx_Messages[ Can_Ch0_Il_Tx_Num_Messages ] =
 {
	/*IC_0x386_TMH*/
	{
        1,                              /* Number of Signals in the Message             */
        0,                               /* Total Number of Signal Bytes in the Message  */
        Can_Ch0_Il_IC_0x386_Message_Init       /* Pointer to the Initialization Data Bytes     */
	},
	/*IC_0x387_TMH*/
	{
        6,                              /* Number of Signals in the Message             */
        0,                               /* Total Number of Signal Bytes in the Message  */
        Can_Ch0_Il_IC_0x387_Message_Init       /* Pointer to the Initialization Data Bytes     */
	},
	/*IC_0x38A_TMH*/
	{
        36,                              /* Number of Signals in the Message             */
        0,                               /* Total Number of Signal Bytes in the Message  */
        Can_Ch0_Il_IC_0x38A_Message_Init       /* Pointer to the Initialization Data Bytes     */
	},
	/*IC_0x510_TMH*/
	{
        9,                              /* Number of Signals in the Message             */
        0,                               /* Total Number of Signal Bytes in the Message  */
        Can_Ch0_Il_IC_0x510_Message_Init       /* Pointer to the Initialization Data Bytes     */
	},
	/*IC_0x511_TMH*/
	{
        5,                              /* Number of Signals in the Message             */
        0,                               /* Total Number of Signal Bytes in the Message  */
        Can_Ch0_Il_IC_0x511_Message_Init       /* Pointer to the Initialization Data Bytes     */
	},
	/*IC_0x525_TMH*/
	{
        9,                              /* Number of Signals in the Message             */
        0,                               /* Total Number of Signal Bytes in the Message  */
        Can_Ch0_Il_IC_0x525_Message_Init       /* Pointer to the Initialization Data Bytes     */
	},
	/*IC_time_0x581_TMH*/
	{
        6,                              /* Number of Signals in the Message             */
        0,                               /* Total Number of Signal Bytes in the Message  */
        Can_Ch0_Il_IC_time_0x581_Message_Init       /* Pointer to the Initialization Data Bytes     */
	},
};

/* ===========================================================================
  Interaction Layer Transmit Message Data (TMD) Structures (Frame Definition)

  !!! IMPORTANT NOTE !!! The transmit message handles must be specified
  sequentially, starting with 0 (zero). These message handles serve as an
  index to the transmit complete function pointers, so each index must map
  to the correct transmit complete callback function pointer in the lookup
  table (array of function pointers) for servicing transmit complete events.

 =========================================================================*/

/*       IC_0x386     */
 static CAN_IL_TMD const Can_Ch0_Il_Tx_Message_IC_0x386_Tmd =
{
     CAN_GPNUM_8,                            /* CAN message data length  */
     Can_Ch0_Il_Tx_Frame_Data[ 0 ],           /* Pointer to Data          */
     Can_Ch0_Il_Tx_Msg_IC_0x386_TMH           /* Transmit Message Handle  */
};

/*       IC_0x387     */
 static CAN_IL_TMD const Can_Ch0_Il_Tx_Message_IC_0x387_Tmd =
{
     CAN_GPNUM_8,                            /* CAN message data length  */
     Can_Ch0_Il_Tx_Frame_Data[ 1 ],           /* Pointer to Data          */
     Can_Ch0_Il_Tx_Msg_IC_0x387_TMH           /* Transmit Message Handle  */
};

/*       IC_0x38A     */
 static CAN_IL_TMD const Can_Ch0_Il_Tx_Message_IC_0x38A_Tmd =
{
     CAN_GPNUM_8,                            /* CAN message data length  */
     Can_Ch0_Il_Tx_Frame_Data[ 2 ],           /* Pointer to Data          */
     Can_Ch0_Il_Tx_Msg_IC_0x38A_TMH           /* Transmit Message Handle  */
};

/*       IC_0x510     */
 static CAN_IL_TMD const Can_Ch0_Il_Tx_Message_IC_0x510_Tmd =
{
     CAN_GPNUM_8,                            /* CAN message data length  */
     Can_Ch0_Il_Tx_Frame_Data[ 3 ],           /* Pointer to Data          */
     Can_Ch0_Il_Tx_Msg_IC_0x510_TMH           /* Transmit Message Handle  */
};

/*       IC_0x511     */
 static CAN_IL_TMD const Can_Ch0_Il_Tx_Message_IC_0x511_Tmd =
{
     CAN_GPNUM_8,                            /* CAN message data length  */
     Can_Ch0_Il_Tx_Frame_Data[ 4 ],           /* Pointer to Data          */
     Can_Ch0_Il_Tx_Msg_IC_0x511_TMH           /* Transmit Message Handle  */
};

/*       IC_0x525     */
 static CAN_IL_TMD const Can_Ch0_Il_Tx_Message_IC_0x525_Tmd =
{
     CAN_GPNUM_8,                            /* CAN message data length  */
     Can_Ch0_Il_Tx_Frame_Data[ 5 ],           /* Pointer to Data          */
     Can_Ch0_Il_Tx_Msg_IC_0x525_TMH           /* Transmit Message Handle  */
};

/*       IC_time_0x581     */
 static CAN_IL_TMD const Can_Ch0_Il_Tx_Message_IC_time_0x581_Tmd =
{
     CAN_GPNUM_8,                            /* CAN message data length  */
     Can_Ch0_Il_Tx_Frame_Data[ 6 ],           /* Pointer to Data          */
     Can_Ch0_Il_Tx_Msg_IC_time_0x581_TMH           /* Transmit Message Handle  */
};
/* ===========================================================================
  Interaction Layer Periodic Transmit Table

  This table is an array of data structures that define the periodic
  transmit characteristics for messages that are transmitted periodically.
  Care must be taken so that the each periodic message defined in the
  Interaction Layer Transmit Frame table map correctly to this table so
  that the correct periodic message attributes, and the pointer to the
  periodic timer, is correctly retrieved.

 =========================================================================*/
static CAN_IL_TX_PERIODIC const
Can_Ch0_Il_Tx_Periodic[ Can_Ch0_Il_Tx_Num_Periodic ] =
{
 /* IC_0x386  Message */
 {
     IL_TIME_IN_TASK_TICS( 100) ,                                   /* Primary Period in Task Tics  */
     IL_TIME_IN_TASK_TICS( 10),                                     /* Offset Delay in Task Tics    */
     &Can_Ch0_Il_Tx_Periodic_Count[ 0 ]                         /* Pointer to Periodic Count    */
 },
 /* IC_0x387  Message */
 {
     IL_TIME_IN_TASK_TICS( 100) ,                                   /* Primary Period in Task Tics  */
     IL_TIME_IN_TASK_TICS( 20),                                     /* Offset Delay in Task Tics    */
     &Can_Ch0_Il_Tx_Periodic_Count[ 1 ]                         /* Pointer to Periodic Count    */
 },
 /* IC_0x38A  Message */
 {
     IL_TIME_IN_TASK_TICS( 200) ,                                   /* Primary Period in Task Tics  */
     IL_TIME_IN_TASK_TICS( 30),                                     /* Offset Delay in Task Tics    */
     &Can_Ch0_Il_Tx_Periodic_Count[ 2 ]                         /* Pointer to Periodic Count    */
 },
 /* IC_0x510  Message */
 {
     IL_TIME_IN_TASK_TICS( 100) ,                                   /* Primary Period in Task Tics  */
     IL_TIME_IN_TASK_TICS( 40),                                     /* Offset Delay in Task Tics    */
     &Can_Ch0_Il_Tx_Periodic_Count[ 3 ]                         /* Pointer to Periodic Count    */
 },
 /* IC_0x511  Message */
 {
     IL_TIME_IN_TASK_TICS( 100) ,                                   /* Primary Period in Task Tics  */
     IL_TIME_IN_TASK_TICS( 50),                                     /* Offset Delay in Task Tics    */
     &Can_Ch0_Il_Tx_Periodic_Count[ 4 ]                         /* Pointer to Periodic Count    */
 },
 /* IC_0x525  Message */
 {
     IL_TIME_IN_TASK_TICS( 100) ,                                   /* Primary Period in Task Tics  */
     IL_TIME_IN_TASK_TICS( 60),                                     /* Offset Delay in Task Tics    */
     &Can_Ch0_Il_Tx_Periodic_Count[ 5 ]                         /* Pointer to Periodic Count    */
 },
 /* IC_time_0x581  Message */
 {
     IL_TIME_IN_TASK_TICS( 500) ,                                   /* Primary Period in Task Tics  */
     IL_TIME_IN_TASK_TICS( 70),                                     /* Offset Delay in Task Tics    */
     &Can_Ch0_Il_Tx_Periodic_Count[ 6 ]                         /* Pointer to Periodic Count    */
 },
};
/* ===========================================================================
  Interaction Layer Burst Periodic Transmit Table
 =========================================================================*/

/* ===========================================================================
  Interaction Layer Transmit Frame Table

  Each entry in this table defines the attributes for a specific transmit
  frame transmitted by the Interaction Layer.

 =========================================================================*/

CAN_IL_TX_FRAME const Can_Ch0_Il_Tx_Frame_Table[ Can_Ch0_Il_Tx_Num_Messages ] = 
{
 {
 /* IC_0x386 Message (CAN periodic, data change or a request ) */
     (IL_TX_ATTR_PERIODIC | IL_TX_ATTR_TXC_NOTIFY),   /* Frame Transmission Attributes                */
     &Can_Ch0_Il_Tx_Frame_Status[ 0 ],       /* Pointer to the Frame Status Variable         */
     Can_Ch0_Il_Tx_Frame_Data[ 0 ],          /* Pointer to the Transmitted Frame Data        */
     &Can_Ch0_Il_Tx_Delay_Count[ 0 ],        /* Pointer to the Transmit Delay Count          */ 
     IL_TIME_IN_TASK_TICS( 0 ),                   /* Minimum Transmit Delay in Timer Tics         */
     &Can_Ch0_Il_Tx_Periodic[ 0 ],           /* Pointer to the Periodic Attributes (or NULL ) */ 
     NULL,                                        /* Ptr to Burst Periodic Attributes (or NULL)   */
     &Can_Ch0_Il_Tx_Message_IC_0x386_Tmd,  /* Pointer to CAN Driver TMD Data Structure     */
 },
 {
 /* IC_0x387 Message (CAN periodic, data change or a request ) */
     (IL_TX_ATTR_PERIODIC | IL_TX_ATTR_TXC_NOTIFY),   /* Frame Transmission Attributes                */
     &Can_Ch0_Il_Tx_Frame_Status[ 1 ],       /* Pointer to the Frame Status Variable         */
     Can_Ch0_Il_Tx_Frame_Data[ 1 ],          /* Pointer to the Transmitted Frame Data        */
     &Can_Ch0_Il_Tx_Delay_Count[ 1 ],        /* Pointer to the Transmit Delay Count          */ 
     IL_TIME_IN_TASK_TICS( 0 ),                   /* Minimum Transmit Delay in Timer Tics         */
     &Can_Ch0_Il_Tx_Periodic[ 1 ],           /* Pointer to the Periodic Attributes (or NULL ) */ 
     NULL,                                        /* Ptr to Burst Periodic Attributes (or NULL)   */
     &Can_Ch0_Il_Tx_Message_IC_0x387_Tmd,  /* Pointer to CAN Driver TMD Data Structure     */
 },
 {
 /* IC_0x38A Message (CAN periodic, data change or a request ) */
     (IL_TX_ATTR_PERIODIC | IL_TX_ATTR_TXC_NOTIFY),   /* Frame Transmission Attributes                */
     &Can_Ch0_Il_Tx_Frame_Status[ 2 ],       /* Pointer to the Frame Status Variable         */
     Can_Ch0_Il_Tx_Frame_Data[ 2 ],          /* Pointer to the Transmitted Frame Data        */
     &Can_Ch0_Il_Tx_Delay_Count[ 2 ],        /* Pointer to the Transmit Delay Count          */ 
     IL_TIME_IN_TASK_TICS( 0 ),                   /* Minimum Transmit Delay in Timer Tics         */
     &Can_Ch0_Il_Tx_Periodic[ 2 ],           /* Pointer to the Periodic Attributes (or NULL ) */ 
     NULL,                                        /* Ptr to Burst Periodic Attributes (or NULL)   */
     &Can_Ch0_Il_Tx_Message_IC_0x38A_Tmd,  /* Pointer to CAN Driver TMD Data Structure     */
 },
 {
 /* IC_0x510 Message (CAN periodic, data change or a request ) */
     (IL_TX_ATTR_PERIODIC | IL_TX_ATTR_TXC_NOTIFY),   /* Frame Transmission Attributes                */
     &Can_Ch0_Il_Tx_Frame_Status[ 3 ],       /* Pointer to the Frame Status Variable         */
     Can_Ch0_Il_Tx_Frame_Data[ 3 ],          /* Pointer to the Transmitted Frame Data        */
     &Can_Ch0_Il_Tx_Delay_Count[ 3 ],        /* Pointer to the Transmit Delay Count          */ 
     IL_TIME_IN_TASK_TICS( 0 ),                   /* Minimum Transmit Delay in Timer Tics         */
     &Can_Ch0_Il_Tx_Periodic[ 3 ],           /* Pointer to the Periodic Attributes (or NULL ) */ 
     NULL,                                        /* Ptr to Burst Periodic Attributes (or NULL)   */
     &Can_Ch0_Il_Tx_Message_IC_0x510_Tmd,  /* Pointer to CAN Driver TMD Data Structure     */
 },
 {
 /* IC_0x511 Message (CAN periodic, data change or a request ) */
     (IL_TX_ATTR_PERIODIC | IL_TX_ATTR_TXC_NOTIFY),   /* Frame Transmission Attributes                */
     &Can_Ch0_Il_Tx_Frame_Status[ 4 ],       /* Pointer to the Frame Status Variable         */
     Can_Ch0_Il_Tx_Frame_Data[ 4 ],          /* Pointer to the Transmitted Frame Data        */
     &Can_Ch0_Il_Tx_Delay_Count[ 4 ],        /* Pointer to the Transmit Delay Count          */ 
     IL_TIME_IN_TASK_TICS( 0 ),                   /* Minimum Transmit Delay in Timer Tics         */
     &Can_Ch0_Il_Tx_Periodic[ 4 ],           /* Pointer to the Periodic Attributes (or NULL ) */ 
     NULL,                                        /* Ptr to Burst Periodic Attributes (or NULL)   */
     &Can_Ch0_Il_Tx_Message_IC_0x511_Tmd,  /* Pointer to CAN Driver TMD Data Structure     */
 },
 {
 /* IC_0x525 Message (CAN periodic, data change or a request ) */
     (IL_TX_ATTR_PERIODIC | IL_TX_ATTR_TXC_NOTIFY),   /* Frame Transmission Attributes                */
     &Can_Ch0_Il_Tx_Frame_Status[ 5 ],       /* Pointer to the Frame Status Variable         */
     Can_Ch0_Il_Tx_Frame_Data[ 5 ],          /* Pointer to the Transmitted Frame Data        */
     &Can_Ch0_Il_Tx_Delay_Count[ 5 ],        /* Pointer to the Transmit Delay Count          */ 
     IL_TIME_IN_TASK_TICS( 0 ),                   /* Minimum Transmit Delay in Timer Tics         */
     &Can_Ch0_Il_Tx_Periodic[ 5 ],           /* Pointer to the Periodic Attributes (or NULL ) */ 
     NULL,                                        /* Ptr to Burst Periodic Attributes (or NULL)   */
     &Can_Ch0_Il_Tx_Message_IC_0x525_Tmd,  /* Pointer to CAN Driver TMD Data Structure     */
 },
 {
 /* IC_time_0x581 Message (CAN periodic, data change or a request ) */
     (IL_TX_ATTR_PERIODIC | IL_TX_ATTR_TXC_NOTIFY),   /* Frame Transmission Attributes                */
     &Can_Ch0_Il_Tx_Frame_Status[ 6 ],       /* Pointer to the Frame Status Variable         */
     Can_Ch0_Il_Tx_Frame_Data[ 6 ],          /* Pointer to the Transmitted Frame Data        */
     &Can_Ch0_Il_Tx_Delay_Count[ 6 ],        /* Pointer to the Transmit Delay Count          */ 
     IL_TIME_IN_TASK_TICS( 0 ),                   /* Minimum Transmit Delay in Timer Tics         */
     &Can_Ch0_Il_Tx_Periodic[ 6 ],           /* Pointer to the Periodic Attributes (or NULL ) */ 
     NULL,                                        /* Ptr to Burst Periodic Attributes (or NULL)   */
     &Can_Ch0_Il_Tx_Message_IC_time_0x581_Tmd,  /* Pointer to CAN Driver TMD Data Structure     */
 },
};
/* ===========================================================================
  R E C E I V E   D A T A   S T R U C T U R E S
 =========================================================================*/
/* ===========================================================================
  Interaction Layer Receive Signal Descriptors

  This data structure defines each received signal, include the specific
  received CAN frame (sequentially enumerated) in which the signal resides,
  and the specific location of the signal within the CAN frame. The
  signal is assumed to span the bits in the frame from the MSByte.MSBit to
  the LSByte.LSBit. As an example, a 16 bit (2 Byte) wide signal that
  occupies the first two bytes (Byte0, Byte 1) of a CAN frame is specified
  as having endpoints at (Byte 0, Bit 7) and (Byte 1, Bit 0). This table
  definition assumes a Motorola (Big Endian) ordering of bytes within the
  CAN Frame.

 =========================================================================*/
/* Receive messages */
CAN_IL_SIGNAL const
Can_Ch0_Il_Rx_Signals[ Can_Ch0_Il_Rx_Num_Signals ] =
{ 
/*  CAN Frame,                                               Num Bytes,      MS Byte,    MS Bit,     LS Byte,    LS Bit */
{  Can_Ch0_Il_Rx_Msg_SCU_0xC8,                              1,             2,             0,             2,             0  },/*0*/  /*SCU_faultwarning*/   /*SCU_0xC8*/
{  Can_Ch0_Il_Rx_Msg_GW_EMS_Power_0x10B,                    1,             1,             7,             1,             0  },/*1*/  /*EMS_EngCoolanTemp*/   /*GW_EMS_Power_0x10B*/
{  Can_Ch0_Il_Rx_Msg_GW_EMS_Power_0x10B,                    1,             3,             2,             3,             0  },/*2*/  /*EMS_EngOperationStatus*/   /*GW_EMS_Power_0x10B*/
{  Can_Ch0_Il_Rx_Msg_GW_EMS_Power_0x10B,                    1,             3,             7,             3,             7  },/*3*/  /*EMS_BatteryVoltageError*/   /*GW_EMS_Power_0x10B*/
{  Can_Ch0_Il_Rx_Msg_GW_EMS_Power_0x10B,                    2,             4,             7,             5,             1  },/*4*/  /*EMS_EngSpeed*/   /*GW_EMS_Power_0x10B*/
{  Can_Ch0_Il_Rx_Msg_GW_EMS_Power_0x10B,                    1,             7,             7,             7,             4  },/*5*/  /*EMS_StartStopMessage*/   /*GW_EMS_Power_0x10B*/
{  Can_Ch0_Il_Rx_Msg_GW_TCU_GearInfo_Power_0x123,           1,             1,             3,             1,             0  },/*6*/  /*TCU_DisplayGear*/   /*GW_TCU_GearInfo_Power_0x123*/
{  Can_Ch0_Il_Rx_Msg_GW_TCU_GearInfo_Power_0x123,           1,             1,             7,             1,             4  },/*7*/  /*TCU_GearSelectorReq*/   /*GW_TCU_GearInfo_Power_0x123*/
{  Can_Ch0_Il_Rx_Msg_GW_TCU_GearInfo_Power_0x123,           1,             4,             7,             4,             4  },/*8*/  /*TCU_StGearMode*/   /*GW_TCU_GearInfo_Power_0x123*/
{  Can_Ch0_Il_Rx_Msg_GW_TCU_GearInfo_Power_0x123,           1,             6,             3,             6,             0  },/*9*/  /*TCU_Status_AliveCounter0x123*/   /*GW_TCU_GearInfo_Power_0x123*/
{  Can_Ch0_Il_Rx_Msg_GW_TCU_GearInfo_Power_0x123,           1,             7,             7,             7,             0  },/*10*/  /*TCU_Status_Checksum0x123*/   /*GW_TCU_GearInfo_Power_0x123*/
{  Can_Ch0_Il_Rx_Msg_GW_EMS_Sts_Power_0x151,                2,             4,             0,             5,             0  },/*11*/  /*EMS_TargCruiseSpeed*/   /*GW_EMS_Sts_Power_0x151*/
{  Can_Ch0_Il_Rx_Msg_GW_EMS_Sts_Power_0x151,                1,             6,             5,             6,             4  },/*12*/  /*EMS_CruiseControlStatus*/   /*GW_EMS_Sts_Power_0x151*/
{  Can_Ch0_Il_Rx_Msg_GW_TBOX_IVI_0x1A2,                     1,             3,             0,             3,             0  },/*13*/  /*TBOX_ECALLFlt*/   /*GW_TBOX_IVI_0x1A2*/
{  Can_Ch0_Il_Rx_Msg_PEPS_Start_0x1A5,                      1,             0,             7,             0,             6  },/*14*/  /*PEPS_Remotestartstatus*/   /*PEPS_Start_0x1A5*/
{  Can_Ch0_Il_Rx_Msg_GW_ABS_Sts_0x221,                      2,             0,             7,             1,             0  },/*15*/  /*ABS_WhlMilgFrntLe*/   /*GW_ABS_Sts_0x221*/
{  Can_Ch0_Il_Rx_Msg_GW_ABS_Sts_0x221,                      2,             2,             7,             3,             0  },/*16*/  /*ABS_WhlMilgFrntRi*/   /*GW_ABS_Sts_0x221*/
{  Can_Ch0_Il_Rx_Msg_GW_ABS_Sts_0x221,                      2,             4,             3,             5,             0  },/*17*/  /*ABS_VehSpdLgt*/   /*GW_ABS_Sts_0x221*/
{  Can_Ch0_Il_Rx_Msg_GW_ABS_Sts_0x221,                      1,             4,             5,             4,             5  },/*18*/  /*ABS_EbdFlgFlt*/   /*GW_ABS_Sts_0x221*/
{  Can_Ch0_Il_Rx_Msg_GW_ABS_Sts_0x221,                      1,             4,             6,             4,             6  },/*19*/  /*ABS_AbsFlgFlt*/   /*GW_ABS_Sts_0x221*/
{  Can_Ch0_Il_Rx_Msg_GW_ABS_Sts_0x221,                      1,             6,             3,             6,             0  },/*20*/  /*ABS_RollingCounter_0x221*/   /*GW_ABS_Sts_0x221*/
{  Can_Ch0_Il_Rx_Msg_GW_ABS_Sts_0x221,                      1,             6,             4,             6,             4  },/*21*/  /*ABS_WhlMilgFrntLeStatus*/   /*GW_ABS_Sts_0x221*/
{  Can_Ch0_Il_Rx_Msg_GW_ABS_Sts_0x221,                      1,             6,             5,             6,             5  },/*22*/  /*ABS_WhlMilgFrntRiStatus*/   /*GW_ABS_Sts_0x221*/
{  Can_Ch0_Il_Rx_Msg_GW_ABS_Sts_0x221,                      1,             7,             7,             7,             0  },/*23*/  /*ABS_Checksum_0x221*/   /*GW_ABS_Sts_0x221*/
{  Can_Ch0_Il_Rx_Msg_GW_ESP_Status_Chassis_0x243,           1,             0,             0,             0,             0  },/*24*/  /*ESP_HHCAvailable*/   /*GW_ESP_Status_Chassis_0x243*/
{  Can_Ch0_Il_Rx_Msg_GW_ESP_Status_Chassis_0x243,           1,             0,             2,             0,             2  },/*25*/  /*ABS_HAZActive*/   /*GW_ESP_Status_Chassis_0x243*/
{  Can_Ch0_Il_Rx_Msg_GW_ESP_Status_Chassis_0x243,           1,             0,             5,             0,             3  },/*26*/  /*ESP_EPBStatus*/   /*GW_ESP_Status_Chassis_0x243*/
{  Can_Ch0_Il_Rx_Msg_GW_ESP_Status_Chassis_0x243,           1,             0,             7,             0,             6  },/*27*/  /*ESP_EPBErrorStatus*/   /*GW_ESP_Status_Chassis_0x243*/
{  Can_Ch0_Il_Rx_Msg_GW_ESP_Status_Chassis_0x243,           1,             1,             1,             1,             1  },/*28*/  /*ESP_HDCAvailable*/   /*GW_ESP_Status_Chassis_0x243*/
{  Can_Ch0_Il_Rx_Msg_GW_ESP_Status_Chassis_0x243,           1,             1,             4,             1,             3  },/*29*/  /*ESP_HDCActive*/   /*GW_ESP_Status_Chassis_0x243*/
{  Can_Ch0_Il_Rx_Msg_GW_ESP_Status_Chassis_0x243,           1,             1,             6,             1,             6  },/*30*/  /*ESP_CdpAvailable*/   /*GW_ESP_Status_Chassis_0x243*/
{  Can_Ch0_Il_Rx_Msg_GW_ESP_Status_Chassis_0x243,           1,             2,             1,             2,             1  },/*31*/  /*ESP_EPBWarningMessage3*/   /*GW_ESP_Status_Chassis_0x243*/
{  Can_Ch0_Il_Rx_Msg_GW_ESP_Status_Chassis_0x243,           1,             2,             2,             2,             2  },/*32*/  /*ESP_EPBWarningMessage2*/   /*GW_ESP_Status_Chassis_0x243*/
{  Can_Ch0_Il_Rx_Msg_GW_ESP_Status_Chassis_0x243,           1,             2,             3,             2,             3  },/*33*/  /*ESP_EPBWarningMessage1*/   /*GW_ESP_Status_Chassis_0x243*/
{  Can_Ch0_Il_Rx_Msg_GW_ESP_Status_Chassis_0x243,           1,             2,             4,             2,             4  },/*34*/  /*ESP_AVHWarningMessage*/   /*GW_ESP_Status_Chassis_0x243*/
{  Can_Ch0_Il_Rx_Msg_GW_ESP_Status_Chassis_0x243,           1,             2,             5,             2,             5  },/*35*/  /*ESP_AvhActive*/   /*GW_ESP_Status_Chassis_0x243*/
{  Can_Ch0_Il_Rx_Msg_GW_ESP_Status_Chassis_0x243,           1,             2,             6,             2,             6  },/*36*/  /*ESP_AvhStandby*/   /*GW_ESP_Status_Chassis_0x243*/
{  Can_Ch0_Il_Rx_Msg_GW_ESP_Status_Chassis_0x243,           1,             2,             7,             2,             7  },/*37*/  /*ESP_AvhAvabliable*/   /*GW_ESP_Status_Chassis_0x243*/
{  Can_Ch0_Il_Rx_Msg_GW_ESP_Status_Chassis_0x243,           1,             4,             0,             4,             0  },/*38*/  /*ESP_VdcFlgFlt*/   /*GW_ESP_Status_Chassis_0x243*/
{  Can_Ch0_Il_Rx_Msg_GW_ESP_Status_Chassis_0x243,           1,             4,             1,             4,             1  },/*39*/  /*ESP_TcsFlgFlt*/   /*GW_ESP_Status_Chassis_0x243*/
{  Can_Ch0_Il_Rx_Msg_GW_ESP_Status_Chassis_0x243,           1,             5,             4,             5,             4  },/*40*/  /*ESP_ESPInfoLamp*/   /*GW_ESP_Status_Chassis_0x243*/
{  Can_Ch0_Il_Rx_Msg_GW_ESP_Status_Chassis_0x243,           1,             5,             5,             5,             5  },/*41*/  /*ESP_EspEnableSts*/   /*GW_ESP_Status_Chassis_0x243*/
{  Can_Ch0_Il_Rx_Msg_GW_ESP_Status_Chassis_0x243,           1,             6,             3,             6,             0  },/*42*/  /*ESP_RollingCounter_0x243*/   /*GW_ESP_Status_Chassis_0x243*/
{  Can_Ch0_Il_Rx_Msg_GW_ESP_Status_Chassis_0x243,           1,             7,             7,             7,             0  },/*43*/  /*ESP_Checksum_0x243*/   /*GW_ESP_Status_Chassis_0x243*/
{  Can_Ch0_Il_Rx_Msg_GW_IPM_0x245,                          1,             1,             0,             2,             6  },/*44*/  /*IPM_LaneAssitType*/   /*GW_IPM_0x245*/
{  Can_Ch0_Il_Rx_Msg_GW_IPM_0x245,                          1,             1,             1,             1,             1  },/*45*/  /*IPM_LaneAssit_WarningVibration*/   /*GW_IPM_0x245*/
{  Can_Ch0_Il_Rx_Msg_GW_IPM_0x245,                          1,             2,             1,             2,             1  },/*46*/  /*IPM_LaneAssit_WarningAudio*/   /*GW_IPM_0x245*/
{  Can_Ch0_Il_Rx_Msg_GW_IPM_0x245,                          1,             2,             3,             2,             2  },/*47*/  /*IPM_LaneAssit_LeftVisualization*/   /*GW_IPM_0x245*/
{  Can_Ch0_Il_Rx_Msg_GW_IPM_0x245,                          1,             2,             5,             2,             4  },/*48*/  /*IPM_LaneAssit_RightVisualization*/   /*GW_IPM_0x245*/
{  Can_Ch0_Il_Rx_Msg_GW_IPM_0x245,                          1,             3,             1,             3,             0  },/*49*/  /*IPM_SLASpdlimitUnits*/   /*GW_IPM_0x245*/
{  Can_Ch0_Il_Rx_Msg_GW_IPM_0x245,                          1,             3,             4,             3,             2  },/*50*/  /*IPM_SLAState*/   /*GW_IPM_0x245*/
{  Can_Ch0_Il_Rx_Msg_GW_IPM_0x245,                          1,             3,             7,             3,             5  },/*51*/  /*IPM_LaneAssit_Status*/   /*GW_IPM_0x245*/
{  Can_Ch0_Il_Rx_Msg_GW_IPM_0x245,                          1,             4,             7,             4,             0  },/*52*/  /*IPM_SLASpdlimit*/   /*GW_IPM_0x245*/
{  Can_Ch0_Il_Rx_Msg_GW_IPM_0x245,                          1,             5,             2,             5,             0  },/*53*/  /*IPM_HMA_Status*/   /*GW_IPM_0x245*/
{  Can_Ch0_Il_Rx_Msg_GW_IPM_0x245,                          1,             5,             4,             5,             3  },/*54*/  /*IPM_DDD_IndexStatus*/   /*GW_IPM_0x245*/
{  Can_Ch0_Il_Rx_Msg_GW_IPM_0x245,                          1,             5,             7,             5,             5  },/*55*/  /*IPM_DDD_WarningLevel*/   /*GW_IPM_0x245*/
{  Can_Ch0_Il_Rx_Msg_GW_IPM_0x245,                          1,             6,             6,             6,             6  },/*56*/  /*IPM_LaneAssit_HandsonReq*/   /*GW_IPM_0x245*/
{  Can_Ch0_Il_Rx_Msg_GW_MRR_Chassis_0x246,                  2,             0,             7,             1,             7  },/*57*/  /*vSetDis*/   /*GW_MRR_Chassis_0x246*/
{  Can_Ch0_Il_Rx_Msg_GW_MRR_Chassis_0x246,                  1,             1,             0,             1,             0  },/*58*/  /*ObjValid*/   /*GW_MRR_Chassis_0x246*/
{  Can_Ch0_Il_Rx_Msg_GW_MRR_Chassis_0x246,                  1,             1,             3,             1,             1  },/*59*/  /*TauGapSet*/   /*GW_MRR_Chassis_0x246*/
{  Can_Ch0_Il_Rx_Msg_GW_MRR_Chassis_0x246,                  1,             1,             6,             1,             4  },/*60*/  /*dxTarObj*/   /*GW_MRR_Chassis_0x246*/
{  Can_Ch0_Il_Rx_Msg_GW_MRR_Chassis_0x246,                  1,             2,             2,             2,             0  },/*61*/  /*ACCHMI_Mode*/   /*GW_MRR_Chassis_0x246*/
{  Can_Ch0_Il_Rx_Msg_GW_MRR_Chassis_0x246,                  1,             2,             3,             2,             3  },/*62*/  /*ACCFailInfo*/   /*GW_MRR_Chassis_0x246*/
{  Can_Ch0_Il_Rx_Msg_GW_MRR_Chassis_0x246,                  1,             2,             4,             2,             4  },/*63*/  /*TakeOverReq*/   /*GW_MRR_Chassis_0x246*/
{  Can_Ch0_Il_Rx_Msg_GW_MRR_Chassis_0x246,                  1,             3,             3,             3,             1  },/*64*/  /*AEB_STATE*/   /*GW_MRR_Chassis_0x246*/
{  Can_Ch0_Il_Rx_Msg_GW_MRR_Chassis_0x246,                  1,             3,             5,             3,             4  },/*65*/  /*ACC_Startstop_infor*/   /*GW_MRR_Chassis_0x246*/
{  Can_Ch0_Il_Rx_Msg_GW_MRR_Chassis_0x246,                  1,             3,             6,             3,             6  },/*66*/  /*PCW_preWarning*/   /*GW_MRR_Chassis_0x246*/
{  Can_Ch0_Il_Rx_Msg_GW_MRR_Chassis_0x246,                  1,             3,             7,             3,             7  },/*67*/  /*PCW_latentWarning*/   /*GW_MRR_Chassis_0x246*/
{  Can_Ch0_Il_Rx_Msg_GW_MRR_Chassis_0x246,                  1,             4,             7,             4,             5  },/*68*/  /*PCW_STATE*/   /*GW_MRR_Chassis_0x246*/
{  Can_Ch0_Il_Rx_Msg_GW_MRR_Chassis_0x246,                  1,             5,             7,             5,             0  },/*69*/  /*Obj_Speed*/   /*GW_MRR_Chassis_0x246*/
{  Can_Ch0_Il_Rx_Msg_GW_MRR_Chassis_0x246,                  1,             6,             3,             6,             0  },/*70*/  /*Rolling_counter_0x246*/   /*GW_MRR_Chassis_0x246*/
{  Can_Ch0_Il_Rx_Msg_GW_MRR_Chassis_0x246,                  1,             6,             7,             6,             4  },/*71*/  /*Textinfo*/   /*GW_MRR_Chassis_0x246*/
{  Can_Ch0_Il_Rx_Msg_GW_MRR_Chassis_0x246,                  1,             7,             7,             7,             0  },/*72*/  /*Checksum_0x246*/   /*GW_MRR_Chassis_0x246*/
{  Can_Ch0_Il_Rx_Msg_GW_IPM_0x247,                          1,             0,             1,             1,             6  },/*73*/  /*IPM_DCLC_manualfeedback*/   /*GW_IPM_0x247*/
{  Can_Ch0_Il_Rx_Msg_GW_IPM_0x247,                          1,             0,             4,             0,             2  },/*74*/  /*IPM_ELKSts*/   /*GW_IPM_0x247*/
{  Can_Ch0_Il_Rx_Msg_GW_IPM_0x247,                          1,             0,             7,             0,             5  },/*75*/  /*IPM_DCLCSts*/   /*GW_IPM_0x247*/
{  Can_Ch0_Il_Rx_Msg_GW_EPS_Chassis_0x260,                  1,             0,             6,             0,             6  },/*76*/  /*EPS_S_WarningLampYellow*/   /*GW_EPS_Chassis_0x260*/
{  Can_Ch0_Il_Rx_Msg_GW_EPS_Chassis_0x260,                  1,             0,             7,             0,             7  },/*77*/  /*EPS_S_SafeLampRed*/   /*GW_EPS_Chassis_0x260*/
{  Can_Ch0_Il_Rx_Msg_GW_EPS_Chassis_0x260,                  1,             6,             3,             6,             0  },/*78*/  /*Rolling_counter_0x260*/   /*GW_EPS_Chassis_0x260*/
{  Can_Ch0_Il_Rx_Msg_GW_EPS_Chassis_0x260,                  1,             7,             7,             7,             0  },/*79*/  /*Checksum_0x260*/   /*GW_EPS_Chassis_0x260*/
{  Can_Ch0_Il_Rx_Msg_GW_PAM_0x271,                          1,             6,             1,             6,             0  },/*80*/  /*PAM_ChimeCmdSoundStatus*/   /*GW_PAM_0x271*/
{  Can_Ch0_Il_Rx_Msg_GW_PAM_0x271,                          1,             6,             3,             6,             2  },/*81*/  /*PAM_RearSysTemWorkSts*/   /*GW_PAM_0x271*/
{  Can_Ch0_Il_Rx_Msg_GW_PAM_0x271,                          1,             6,             5,             6,             4  },/*82*/  /*PAM_FrontSysTemWorkSts*/   /*GW_PAM_0x271*/
{  Can_Ch0_Il_Rx_Msg_GW_PAM_0x271,                          1,             7,             3,             7,             0  },/*83*/  /*PAM_ChimeCmdSoundCadence*/   /*GW_PAM_0x271*/
{  Can_Ch0_Il_Rx_Msg_GW_PAM_0x274,                          2,             0,             6,             2,             7  },/*84*/  /*LAEB_BrkgReqVal*/   /*GW_PAM_0x274*/
{  Can_Ch0_Il_Rx_Msg_GW_PAM_0x274,                          1,             0,             7,             0,             7  },/*85*/  /*LAEB_BrkgReq*/   /*GW_PAM_0x274*/
{  Can_Ch0_Il_Rx_Msg_GW_PAM_0x274,                          2,             2,             6,             3,             3  },/*86*/  /*LAEB_DistanceToCollision*/   /*GW_PAM_0x274*/
{  Can_Ch0_Il_Rx_Msg_GW_PAM_0x274,                          1,             3,             0,             3,             0  },/*87*/  /*LAEB_SpeakReq*/   /*GW_PAM_0x274*/
{  Can_Ch0_Il_Rx_Msg_GW_PAM_0x274,                          1,             3,             2,             3,             1  },/*88*/  /*LAEB_WorkSts*/   /*GW_PAM_0x274*/
{  Can_Ch0_Il_Rx_Msg_GW_PAM_0x274,                          1,             4,             2,             5,             3  },/*89*/  /*Checksum_0x274*/   /*GW_PAM_0x274*/
{  Can_Ch0_Il_Rx_Msg_GW_PAM_0x274,                          1,             4,             6,             4,             3  },/*90*/  /*Rolling_counter_0x274*/   /*GW_PAM_0x274*/
{  Can_Ch0_Il_Rx_Msg_GW_PAM_0x274,                          1,             4,             7,             4,             7  },/*91*/  /*LAEB_LedReq*/   /*GW_PAM_0x274*/
{  Can_Ch0_Il_Rx_Msg_GW_SOD_0x275,                          1,             0,             1,             0,             0  },/*92*/  /*SOD_LCA_warningReqRight*/   /*GW_SOD_0x275*/
{  Can_Ch0_Il_Rx_Msg_GW_SOD_0x275,                          1,             0,             3,             0,             2  },/*93*/  /*SOD_DOA_warningReqRightRear*/   /*GW_SOD_0x275*/
{  Can_Ch0_Il_Rx_Msg_GW_SOD_0x275,                          1,             0,             5,             0,             4  },/*94*/  /*SOD_DOA_warningReqRightFront*/   /*GW_SOD_0x275*/
{  Can_Ch0_Il_Rx_Msg_GW_SOD_0x275,                          1,             0,             7,             0,             6  },/*95*/  /*SOD_CTA_warningReqRight*/   /*GW_SOD_0x275*/
{  Can_Ch0_Il_Rx_Msg_GW_SOD_0x275,                          1,             1,             7,             1,             4  },/*96*/  /*SOD_BLIS_display*/   /*GW_SOD_0x275*/
{  Can_Ch0_Il_Rx_Msg_GW_SOD_0x275,                          1,             2,             1,             2,             0  },/*97*/  /*SOD_LCA_warningReqLeft*/   /*GW_SOD_0x275*/
{  Can_Ch0_Il_Rx_Msg_GW_SOD_0x275,                          1,             2,             3,             2,             2  },/*98*/  /*SOD_DOA_warningReqLeftRear*/   /*GW_SOD_0x275*/
{  Can_Ch0_Il_Rx_Msg_GW_SOD_0x275,                          1,             2,             5,             2,             4  },/*99*/  /*SOD_DOA_warningReqLeftFront*/   /*GW_SOD_0x275*/
{  Can_Ch0_Il_Rx_Msg_GW_SOD_0x275,                          1,             2,             7,             2,             6  },/*100*/  /*SOD_CTA_warningReqLeft*/   /*GW_SOD_0x275*/
{  Can_Ch0_Il_Rx_Msg_GW_SOD_0x275,                          1,             3,             5,             3,             5  },/*101*/  /*DOA_OFFTelltale*/   /*GW_SOD_0x275*/
{  Can_Ch0_Il_Rx_Msg_GW_SOD_0x275,                          1,             3,             6,             3,             6  },/*102*/  /*CTA_OFFTelltale*/   /*GW_SOD_0x275*/
{  Can_Ch0_Il_Rx_Msg_GW_SOD_0x275,                          1,             3,             7,             3,             7  },/*103*/  /*SODLCA_OFFTelltale*/   /*GW_SOD_0x275*/
{  Can_Ch0_Il_Rx_Msg_GW_IPM_LeftLine_0x278,                 1,             0,             7,             0,             0  },/*104*/  /*IPM_LedtLine_dx_start*/   /*GW_IPM_LeftLine_0x278*/
{  Can_Ch0_Il_Rx_Msg_GW_IPM_LeftLine_0x278,                 2,             1,             7,             2,             4  },/*105*/  /*IPM_LeftLine_dy*/   /*GW_IPM_LeftLine_0x278*/
{  Can_Ch0_Il_Rx_Msg_GW_IPM_LeftLine_0x278,                 2,             2,             3,             3,             3  },/*106*/  /*IPM_LeftLine_dx_lookhead*/   /*GW_IPM_LeftLine_0x278*/
{  Can_Ch0_Il_Rx_Msg_GW_IPM_LeftLine_0x278,                 2,             3,             2,             4,             1  },/*107*/  /*IPM_LeftLine_hor_curve*/   /*GW_IPM_LeftLine_0x278*/
{  Can_Ch0_Il_Rx_Msg_GW_IPM_LeftLine_0x278,                 2,             5,             7,             6,             4  },/*108*/  /*IPM_LeftLine_yawangle*/   /*GW_IPM_LeftLine_0x278*/
{  Can_Ch0_Il_Rx_Msg_GW_MRR_FrObj_0x279,                    2,             0,             7,             1,             4  },/*109*/  /*MRR_F_Object_dx*/   /*GW_MRR_FrObj_0x279*/
{  Can_Ch0_Il_Rx_Msg_GW_MRR_FrObj_0x279,                    2,             1,             3,             2,             3  },/*110*/  /*MRR_F_Object_dy*/   /*GW_MRR_FrObj_0x279*/
{  Can_Ch0_Il_Rx_Msg_GW_MRR_FrObj_0x279,                    1,             2,             2,             2,             0  },/*111*/  /*MRR_F_Obj_0x_class*/   /*GW_MRR_FrObj_0x279*/
{  Can_Ch0_Il_Rx_Msg_GW_MRR_FrObj_0x279,                    2,             3,             7,             4,             4  },/*112*/  /*MRR_FF_Object_dx*/   /*GW_MRR_FrObj_0x279*/
{  Can_Ch0_Il_Rx_Msg_GW_MRR_FrObj_0x279,                    2,             4,             3,             5,             3  },/*113*/  /*MRR_FF_Object_dy*/   /*GW_MRR_FrObj_0x279*/
{  Can_Ch0_Il_Rx_Msg_GW_MRR_FrObj_0x279,                    1,             5,             2,             5,             0  },/*114*/  /*MRR_FF_Obj_0x_class*/   /*GW_MRR_FrObj_0x279*/
{  Can_Ch0_Il_Rx_Msg_GW_MRR_FrObj_0x279,                    1,             6,             6,             6,             6  },/*115*/  /*MRR_FFTargrtDetection*/   /*GW_MRR_FrObj_0x279*/
{  Can_Ch0_Il_Rx_Msg_GW_MRR_FrObj_0x279,                    1,             6,             7,             6,             7  },/*116*/  /*MRR_PedDetection*/   /*GW_MRR_FrObj_0x279*/
{  Can_Ch0_Il_Rx_Msg_GW_IPM_LeftLine_0x280,                 1,             0,             1,             0,             0  },/*117*/  /*IPM_LaneAssit_LeftVisualization*/   /*GW_IPM_LeftLine_0x280*/
{  Can_Ch0_Il_Rx_Msg_GW_IPM_LeftLine_0x280,                 1,             0,             4,             0,             2  },/*118*/  /*IPM_LeftLine_Type*/   /*GW_IPM_LeftLine_0x280*/
{  Can_Ch0_Il_Rx_Msg_GW_IPM_LeftLine_0x280,                 1,             0,             7,             0,             5  },/*119*/  /*IPM_LeftLine_Color*/   /*GW_IPM_LeftLine_0x280*/
{  Can_Ch0_Il_Rx_Msg_GW_IPM_LeftLine_0x280,                 1,             1,             4,             1,             2  },/*120*/  /*IPM_leftLeftLine_Type*/   /*GW_IPM_LeftLine_0x280*/
{  Can_Ch0_Il_Rx_Msg_GW_IPM_LeftLine_0x280,                 1,             1,             7,             1,             5  },/*121*/  /*IPM_leftLeftLine_Color*/   /*GW_IPM_LeftLine_0x280*/
{  Can_Ch0_Il_Rx_Msg_GW_IPM_LeftLine_0x280,                 2,             2,             7,             3,             4  },/*122*/  /*IPM_leftleftLine_dy*/   /*GW_IPM_LeftLine_0x280*/
{  Can_Ch0_Il_Rx_Msg_GW_IPM_LeftLine_0x280,                 2,             3,             2,             4,             1  },/*123*/  /*IPM_leftleftLine_hor_curve*/   /*GW_IPM_LeftLine_0x280*/
{  Can_Ch0_Il_Rx_Msg_GW_IPM_LeftLine_0x280,                 2,             5,             7,             6,             4  },/*124*/  /*IPM_leftleftLine_yawangle*/   /*GW_IPM_LeftLine_0x280*/
{  Can_Ch0_Il_Rx_Msg_GW_IPM_LeftLine_0x280,                 2,             6,             3,             7,             0  },/*125*/  /*IPM_leftleftLine_cur_alteration*/   /*GW_IPM_LeftLine_0x280*/
{  Can_Ch0_Il_Rx_Msg_BCM_Door_0x310,                        1,             0,             1,             0,             0  },/*126*/  /*BCM_DoorStsRearRi*/   /*BCM_Door_0x310*/
{  Can_Ch0_Il_Rx_Msg_BCM_Door_0x310,                        1,             0,             3,             0,             2  },/*127*/  /*BCM_DoorStsRearLe*/   /*BCM_Door_0x310*/
{  Can_Ch0_Il_Rx_Msg_BCM_Door_0x310,                        1,             0,             5,             0,             4  },/*128*/  /*BCM_DoorStsFrntRi*/   /*BCM_Door_0x310*/
{  Can_Ch0_Il_Rx_Msg_BCM_Door_0x310,                        1,             0,             7,             0,             6  },/*129*/  /*BCM_DoorStsFrntLe*/   /*BCM_Door_0x310*/
{  Can_Ch0_Il_Rx_Msg_BCM_Door_0x310,                        1,             1,             1,             1,             0  },/*130*/  /*BCM_DoorLockStsRearRi*/   /*BCM_Door_0x310*/
{  Can_Ch0_Il_Rx_Msg_BCM_Door_0x310,                        1,             1,             3,             1,             2  },/*131*/  /*BCM_DoorLockStsRearLe*/   /*BCM_Door_0x310*/
{  Can_Ch0_Il_Rx_Msg_BCM_Door_0x310,                        1,             1,             5,             1,             4  },/*132*/  /*BCM_DoorLockStsFrntRi*/   /*BCM_Door_0x310*/
{  Can_Ch0_Il_Rx_Msg_BCM_Door_0x310,                        1,             1,             7,             1,             6  },/*133*/  /*BCM_DoorLockStsFrntLe*/   /*BCM_Door_0x310*/
{  Can_Ch0_Il_Rx_Msg_BCM_Door_0x310,                        1,             2,             1,             2,             0  },/*134*/  /*BCM_AntiTheftSts*/   /*BCM_Door_0x310*/
{  Can_Ch0_Il_Rx_Msg_BCM_Door_0x310,                        1,             2,             7,             2,             3  },/*135*/  /*BCM_LockUnlockFeedback*/   /*BCM_Door_0x310*/
{  Can_Ch0_Il_Rx_Msg_BCM_Door_0x310,                        1,             3,             2,             3,             1  },/*136*/  /*BCM_DoorLockStsTrunk*/   /*BCM_Door_0x310*/
{  Can_Ch0_Il_Rx_Msg_BCM_Door_0x310,                        1,             3,             4,             3,             3  },/*137*/  /*BCM_DoorStsTrunk*/   /*BCM_Door_0x310*/
{  Can_Ch0_Il_Rx_Msg_BCM_Door_0x310,                        1,             3,             5,             3,             5  },/*138*/  /*BCM_TrunkDoorPreUnlockSts*/   /*BCM_Door_0x310*/
{  Can_Ch0_Il_Rx_Msg_BCM_Door_0x310,                        1,             4,             7,             4,             6  },/*139*/  /*BCM_EnginehoodSts*/   /*BCM_Door_0x310*/
{  Can_Ch0_Il_Rx_Msg_BCM_Door_0x310,                        1,             6,             3,             6,             0  },/*140*/  /*BCM_Rolling_counter_0x310*/   /*BCM_Door_0x310*/
{  Can_Ch0_Il_Rx_Msg_BCM_Door_0x310,                        1,             6,             7,             6,             6  },/*141*/  /*BCM_TurnIndicatorSts*/   /*BCM_Door_0x310*/
{  Can_Ch0_Il_Rx_Msg_BCM_Door_0x310,                        1,             7,             7,             7,             0  },/*142*/  /*BCM_Checksum_0x310*/   /*BCM_Door_0x310*/
{  Can_Ch0_Il_Rx_Msg_BCM_0x313,                             1,             0,             1,             0,             0  },/*143*/  /*BCM_OutsideTempDig*/   /*BCM_0x313*/
{  Can_Ch0_Il_Rx_Msg_BCM_0x313,                             1,             0,             7,             0,             6  },/*144*/  /*BCM_BrakeFluidSts*/   /*BCM_0x313*/
{  Can_Ch0_Il_Rx_Msg_BCM_0x313,                             1,             1,             7,             1,             0  },/*145*/  /*BCM_OutsideTemp*/   /*BCM_0x313*/
{  Can_Ch0_Il_Rx_Msg_BCM_0x313,                             1,             2,             1,             2,             0  },/*146*/  /*BCM_Reverse_gear*/   /*BCM_0x313*/
{  Can_Ch0_Il_Rx_Msg_BCM_0x313,                             1,             2,             5,             2,             4  },/*147*/  /*BCM_SS_EnableSts*/   /*BCM_0x313*/
{  Can_Ch0_Il_Rx_Msg_BCM_0x313,                             1,             6,             3,             6,             0  },/*148*/  /*BCM_Rollingcounter_0x313*/   /*BCM_0x313*/
{  Can_Ch0_Il_Rx_Msg_BCM_0x313,                             1,             7,             7,             7,             0  },/*149*/  /*BCM_Checksum_0x313*/   /*BCM_0x313*/
{  Can_Ch0_Il_Rx_Msg_BCM_Sts_0x315,                         1,             5,             7,             5,             0  },/*150*/  /*BCM_BGLLumLvlSettingStatus*/   /*BCM_Sts_0x315*/
{  Can_Ch0_Il_Rx_Msg_BCM_Lamp_0x318,                        1,             0,             1,             0,             0  },/*151*/  /*BCM_FrntFogLmpSts*/   /*BCM_Lamp_0x318*/
{  Can_Ch0_Il_Rx_Msg_BCM_Lamp_0x318,                        1,             0,             3,             0,             2  },/*152*/  /*BCM_PosLmpSts*/   /*BCM_Lamp_0x318*/
{  Can_Ch0_Il_Rx_Msg_BCM_Lamp_0x318,                        1,             0,             5,             0,             4  },/*153*/  /*BCM_LowBeamSts*/   /*BCM_Lamp_0x318*/
{  Can_Ch0_Il_Rx_Msg_BCM_Lamp_0x318,                        1,             0,             7,             0,             6  },/*154*/  /*BCM_HighBeamSts*/   /*BCM_Lamp_0x318*/
{  Can_Ch0_Il_Rx_Msg_BCM_Lamp_0x318,                        1,             1,             1,             1,             0  },/*155*/  /*BCM_reversinglightSts*/   /*BCM_Lamp_0x318*/
{  Can_Ch0_Il_Rx_Msg_BCM_Lamp_0x318,                        1,             1,             3,             1,             2  },/*156*/  /*BCM_DayRunningLampSts*/   /*BCM_Lamp_0x318*/
{  Can_Ch0_Il_Rx_Msg_BCM_Lamp_0x318,                        1,             1,             7,             1,             6  },/*157*/  /*BCM_RearFogLmpSts*/   /*BCM_Lamp_0x318*/
{  Can_Ch0_Il_Rx_Msg_BCM_Lamp_0x318,                        1,             2,             1,             2,             0  },/*158*/  /*BCM_laserlightSts*/   /*BCM_Lamp_0x318*/
{  Can_Ch0_Il_Rx_Msg_BCM_Lamp_0x318,                        1,             2,             3,             2,             2  },/*159*/  /*BCM_AmbientLightSts*/   /*BCM_Lamp_0x318*/
{  Can_Ch0_Il_Rx_Msg_BCM_Lamp_0x318,                        1,             2,             5,             2,             4  },/*160*/  /*BCM_Highmountedstoplamp*/   /*BCM_Lamp_0x318*/
{  Can_Ch0_Il_Rx_Msg_BCM_Lamp_0x318,                        1,             2,             7,             2,             6  },/*161*/  /*BCM_BrakelightSts*/   /*BCM_Lamp_0x318*/
{  Can_Ch0_Il_Rx_Msg_BCM_Lamp_0x318,                        1,             3,             3,             3,             2  },/*162*/  /*BCM_BackHomeSts*/   /*BCM_Lamp_0x318*/
{  Can_Ch0_Il_Rx_Msg_BCM_Lamp_0x318,                        1,             3,             5,             3,             4  },/*163*/  /*BCM_AutolampSts*/   /*BCM_Lamp_0x318*/
{  Can_Ch0_Il_Rx_Msg_BCM_Lamp_0x318,                        1,             3,             7,             3,             6  },/*164*/  /*BCM_readinglampSts*/   /*BCM_Lamp_0x318*/
{  Can_Ch0_Il_Rx_Msg_BCM_Lamp_0x318,                        1,             4,             0,             4,             0  },/*165*/  /*BCM_DayRunningLampDig*/   /*BCM_Lamp_0x318*/
{  Can_Ch0_Il_Rx_Msg_BCM_Lamp_0x318,                        1,             4,             1,             4,             1  },/*166*/  /*BCM_BrakelightDig*/   /*BCM_Lamp_0x318*/
{  Can_Ch0_Il_Rx_Msg_BCM_Lamp_0x318,                        1,             4,             2,             4,             2  },/*167*/  /*BCM_reversinglightDig*/   /*BCM_Lamp_0x318*/
{  Can_Ch0_Il_Rx_Msg_BCM_Lamp_0x318,                        1,             4,             3,             4,             3  },/*168*/  /*BCM_TurnIndicatorDig*/   /*BCM_Lamp_0x318*/
{  Can_Ch0_Il_Rx_Msg_BCM_Lamp_0x318,                        1,             4,             4,             4,             4  },/*169*/  /*BCM_RearFogLmpDig*/   /*BCM_Lamp_0x318*/
{  Can_Ch0_Il_Rx_Msg_BCM_Lamp_0x318,                        1,             4,             5,             4,             5  },/*170*/  /*BCM_FrntFogLmpDig*/   /*BCM_Lamp_0x318*/
{  Can_Ch0_Il_Rx_Msg_BCM_Lamp_0x318,                        1,             4,             6,             4,             6  },/*171*/  /*BCM_PosLmpDig*/   /*BCM_Lamp_0x318*/
{  Can_Ch0_Il_Rx_Msg_BCM_Lamp_0x318,                        1,             4,             7,             4,             7  },/*172*/  /*BCM_LowBeamDig*/   /*BCM_Lamp_0x318*/
{  Can_Ch0_Il_Rx_Msg_BCM_Lamp_0x318,                        1,             6,             3,             6,             0  },/*173*/  /*BCM_Rollingcounter_0x318*/   /*BCM_Lamp_0x318*/
{  Can_Ch0_Il_Rx_Msg_BCM_Lamp_0x318,                        1,             7,             7,             7,             0  },/*174*/  /*BCM_Checksum_0x318*/   /*BCM_Lamp_0x318*/
{  Can_Ch0_Il_Rx_Msg_GW_SWM_Body_0x31A,                     1,             5,             1,             5,             0  },/*175*/  /*SWM_Menu_Right*/   /*GW_SWM_Body_0x31A*/
{  Can_Ch0_Il_Rx_Msg_GW_SWM_Body_0x31A,                     1,             5,             3,             5,             2  },/*176*/  /*SWM_Menu_Left*/   /*GW_SWM_Body_0x31A*/
{  Can_Ch0_Il_Rx_Msg_GW_SWM_Body_0x31A,                     1,             5,             5,             5,             4  },/*177*/  /*SWM_Menu_Down*/   /*GW_SWM_Body_0x31A*/
{  Can_Ch0_Il_Rx_Msg_GW_SWM_Body_0x31A,                     1,             5,             7,             5,             6  },/*178*/  /*SWM_Menu_Up*/   /*GW_SWM_Body_0x31A*/
{  Can_Ch0_Il_Rx_Msg_GW_SWM_Body_0x31A,                     1,             6,             3,             6,             0  },/*179*/  /*Rolling_counter_0x31A*/   /*GW_SWM_Body_0x31A*/
{  Can_Ch0_Il_Rx_Msg_GW_SWM_Body_0x31A,                     1,             6,             5,             6,             4  },/*180*/  /*SWM_Menu_Return*/   /*GW_SWM_Body_0x31A*/
{  Can_Ch0_Il_Rx_Msg_GW_SWM_Body_0x31A,                     1,             6,             7,             6,             6  },/*181*/  /*SWM_Menu_Confirm*/   /*GW_SWM_Body_0x31A*/
{  Can_Ch0_Il_Rx_Msg_GW_SWM_Body_0x31A,                     1,             7,             7,             7,             0  },/*182*/  /*Checksum_0x31A*/   /*GW_SWM_Body_0x31A*/
{  Can_Ch0_Il_Rx_Msg_GW_SWM_MRR_0x31B,                      1,             0,             0,             0,             0  },/*183*/  /*SWM_ACCtauGapSetPlus*/   /*GW_SWM_MRR_0x31B*/
{  Can_Ch0_Il_Rx_Msg_GW_SWM_MRR_0x31B,                      1,             0,             1,             0,             1  },/*184*/  /*SWM_ACCvSetMinus*/   /*GW_SWM_MRR_0x31B*/
{  Can_Ch0_Il_Rx_Msg_GW_SWM_MRR_0x31B,                      1,             0,             2,             0,             2  },/*185*/  /*SWM_ACCvSetPlus*/   /*GW_SWM_MRR_0x31B*/
{  Can_Ch0_Il_Rx_Msg_GW_SWM_MRR_0x31B,                      1,             0,             4,             0,             4  },/*186*/  /*SWM_ACCResume*/   /*GW_SWM_MRR_0x31B*/
{  Can_Ch0_Il_Rx_Msg_GW_SWM_MRR_0x31B,                      1,             0,             5,             0,             5  },/*187*/  /*SWM_ACCSet*/   /*GW_SWM_MRR_0x31B*/
{  Can_Ch0_Il_Rx_Msg_GW_SWM_MRR_0x31B,                      1,             0,             6,             0,             6  },/*188*/  /*SWM_ACCEnableSwitch*/   /*GW_SWM_MRR_0x31B*/
{  Can_Ch0_Il_Rx_Msg_GW_SWM_MRR_0x31B,                      1,             1,             6,             1,             6  },/*189*/  /*SWM_LaneAssistSwitch*/   /*GW_SWM_MRR_0x31B*/
{  Can_Ch0_Il_Rx_Msg_GW_SWM_MRR_0x31B,                      1,             1,             7,             1,             7  },/*190*/  /*SWM_ACCtauGapSetMinus*/   /*GW_SWM_MRR_0x31B*/
{  Can_Ch0_Il_Rx_Msg_PEPS_0x325,                            1,             0,             7,             0,             6  },/*191*/  /*PEPS_PowerMode*/   /*PEPS_0x325*/
{  Can_Ch0_Il_Rx_Msg_PEPS_0x325,                            1,             2,             3,             2,             2  },/*192*/  /*PEPS_IMMO_MatchStatus*/   /*PEPS_0x325*/
{  Can_Ch0_Il_Rx_Msg_PEPS_0x325,                            1,             3,             5,             3,             5  },/*193*/  /*PEPS_SystemFailStatus*/   /*PEPS_0x325*/
{  Can_Ch0_Il_Rx_Msg_PEPS_0x325,                            1,             3,             6,             3,             6  },/*194*/  /*PEPS_ESCL_FailStatus*/   /*PEPS_0x325*/
{  Can_Ch0_Il_Rx_Msg_PEPS_0x325,                            1,             3,             7,             3,             7  },/*195*/  /*PEPS_SSB_FailStatus*/   /*PEPS_0x325*/
{  Can_Ch0_Il_Rx_Msg_PEPS_0x325,                            1,             4,             1,             4,             1  },/*196*/  /*PEPS_BrakeIndicationWarning*/   /*PEPS_0x325*/
{  Can_Ch0_Il_Rx_Msg_PEPS_0x325,                            1,             4,             2,             4,             2  },/*197*/  /*PEPS_NotPNWarning*/   /*PEPS_0x325*/
{  Can_Ch0_Il_Rx_Msg_PEPS_0x325,                            1,             5,             2,             5,             2  },/*198*/  /*PEPS_DoorOpenNotOFFWarning*/   /*PEPS_0x325*/
{  Can_Ch0_Il_Rx_Msg_PEPS_0x325,                            1,             5,             3,             5,             3  },/*199*/  /*PEPS_DoorOpenWarning*/   /*PEPS_0x325*/
{  Can_Ch0_Il_Rx_Msg_PEPS_0x325,                            1,             5,             4,             5,             4  },/*200*/  /*PEPS_KeyBatteryWarning*/   /*PEPS_0x325*/
{  Can_Ch0_Il_Rx_Msg_PEPS_0x325,                            1,             5,             5,             5,             5  },/*201*/  /*PEPS_KeyOutWarning1*/   /*PEPS_0x325*/
{  Can_Ch0_Il_Rx_Msg_PEPS_0x325,                            1,             5,             6,             5,             6  },/*202*/  /*PEPS_NoKeyFoundWarning*/   /*PEPS_0x325*/
{  Can_Ch0_Il_Rx_Msg_PEPS_0x325,                            1,             5,             7,             5,             7  },/*203*/  /*PEPS_KeyReminderWarning*/   /*PEPS_0x325*/
{  Can_Ch0_Il_Rx_Msg_PEPS_0x325,                            1,             6,             7,             6,             4  },/*204*/  /*PEPS_RemainingNumSts*/   /*PEPS_0x325*/
{  Can_Ch0_Il_Rx_Msg_GW_SRS_0x350,                          1,             0,             4,             0,             3  },/*205*/  /*SRS_SBR_PAMsenger*/   /*GW_SRS_0x350*/
{  Can_Ch0_Il_Rx_Msg_GW_SRS_0x350,                          1,             0,             6,             0,             5  },/*206*/  /*SRS_SBR_Driver*/   /*GW_SRS_0x350*/
{  Can_Ch0_Il_Rx_Msg_GW_SRS_0x350,                          1,             1,             0,             2,             7  },/*207*/  /*SRS_AirBagFailSts*/   /*GW_SRS_0x350*/
{  Can_Ch0_Il_Rx_Msg_GW_SRS_0x350,                          1,             1,             3,             1,             2  },/*208*/  /*SRS_SBR_SecondRowRight*/   /*GW_SRS_0x350*/
{  Can_Ch0_Il_Rx_Msg_GW_SRS_0x350,                          1,             1,             5,             1,             4  },/*209*/  /*SRS_SBR_SecondRowMid*/   /*GW_SRS_0x350*/
{  Can_Ch0_Il_Rx_Msg_GW_SRS_0x350,                          1,             1,             7,             1,             6  },/*210*/  /*SRS_SBR_SecondRowLeft*/   /*GW_SRS_0x350*/
{  Can_Ch0_Il_Rx_Msg_GW_SRS_0x350,                          1,             6,             3,             6,             0  },/*211*/  /*Rolling_counter_0x350*/   /*GW_SRS_0x350*/
{  Can_Ch0_Il_Rx_Msg_GW_SRS_0x350,                          1,             7,             7,             7,             0  },/*212*/  /*Checksum_0x350*/   /*GW_SRS_0x350*/
{  Can_Ch0_Il_Rx_Msg_TPMS_Tire_0x361,                       1,             0,             7,             0,             0  },/*213*/  /*TPMS_LF_Pressure*/   /*TPMS_Tire_0x361*/
{  Can_Ch0_Il_Rx_Msg_TPMS_Tire_0x361,                       1,             1,             7,             1,             0  },/*214*/  /*TPMS_RF_Pressure*/   /*TPMS_Tire_0x361*/
{  Can_Ch0_Il_Rx_Msg_TPMS_Tire_0x361,                       1,             2,             7,             2,             0  },/*215*/  /*TPMS_RR_Pressure*/   /*TPMS_Tire_0x361*/
{  Can_Ch0_Il_Rx_Msg_TPMS_Tire_0x361,                       1,             3,             7,             3,             0  },/*216*/  /*TPMS_LR_Pressure*/   /*TPMS_Tire_0x361*/
{  Can_Ch0_Il_Rx_Msg_TPMS_Tire_0x361,                       1,             4,             7,             4,             0  },/*217*/  /*TPMS_Tire_Temperature*/   /*TPMS_Tire_0x361*/
{  Can_Ch0_Il_Rx_Msg_TPMS_Tire_0x361,                       1,             5,             2,             5,             0  },/*218*/  /*TPMS_LF_Pressure_Warning*/   /*TPMS_Tire_0x361*/
{  Can_Ch0_Il_Rx_Msg_TPMS_Tire_0x361,                       1,             5,             5,             5,             3  },/*219*/  /*TPMS_RF_Pressure_Warning*/   /*TPMS_Tire_0x361*/
{  Can_Ch0_Il_Rx_Msg_TPMS_Tire_0x361,                       1,             5,             7,             5,             6  },/*220*/  /*TPMS_System_Status*/   /*TPMS_Tire_0x361*/
{  Can_Ch0_Il_Rx_Msg_TPMS_Tire_0x361,                       1,             6,             2,             6,             0  },/*221*/  /*TPMS_RR_Pressure_Warning*/   /*TPMS_Tire_0x361*/
{  Can_Ch0_Il_Rx_Msg_TPMS_Tire_0x361,                       1,             6,             5,             6,             3  },/*222*/  /*TPMS_LR_Pressure_Warning*/   /*TPMS_Tire_0x361*/
{  Can_Ch0_Il_Rx_Msg_TPMS_Tire_0x361,                       1,             6,             6,             6,             6  },/*223*/  /*TPMS_Temperature_Warning*/   /*TPMS_Tire_0x361*/
{  Can_Ch0_Il_Rx_Msg_TPMS_Tire_0x361,                       1,             6,             7,             6,             7  },/*224*/  /*TPMS_resrved*/   /*TPMS_Tire_0x361*/
{  Can_Ch0_Il_Rx_Msg_TPMS_Tire_0x361,                       1,             7,             2,             7,             0  },/*225*/  /*Tire_Position*/   /*TPMS_Tire_0x361*/
{  Can_Ch0_Il_Rx_Msg_TPMS_Tire_0x361,                       1,             7,             4,             7,             3  },/*226*/  /*TPMS_Lamp_Status*/   /*TPMS_Tire_0x361*/
{  Can_Ch0_Il_Rx_Msg_GW_EMS_Power_0x366,                    2,             0,             7,             1,             0  },/*227*/  /*EMS_Fuelcounter*/   /*GW_EMS_Power_0x366*/
{  Can_Ch0_Il_Rx_Msg_GW_EMS_Power_0x366,                    2,             2,             7,             3,             0  },/*228*/  /*EMS_FuelconsumptionInst*/   /*GW_EMS_Power_0x366*/
{  Can_Ch0_Il_Rx_Msg_GW_EMS_Power_0x366,                    1,             5,             2,             5,             2  },/*229*/  /*EMS_MIL*/   /*GW_EMS_Power_0x366*/
{  Can_Ch0_Il_Rx_Msg_GW_EMS_Power_0x366,                    1,             5,             3,             5,             3  },/*230*/  /*EMS_SVS*/   /*GW_EMS_Power_0x366*/
{  Can_Ch0_Il_Rx_Msg_GW_EMS_Power_0x366,                    1,             5,             5,             5,             4  },/*231*/  /*EMS_StartStopStatus*/   /*GW_EMS_Power_0x366*/
{  Can_Ch0_Il_Rx_Msg_GW_EMS_0x368,                          1,             3,             3,             3,             0  },/*232*/  /*EMS_GasPrtcWarn_G_Rq*/   /*GW_EMS_0x368*/
{  Can_Ch0_Il_Rx_Msg_MP5_0x382,                             1,             0,             0,             0,             0  },/*233*/  /*MP5_AudioStatus*/   /*MP5_0x382*/
{  Can_Ch0_Il_Rx_Msg_MP5_0x382,                             1,             0,             4,             0,             1  },/*234*/  /*MP5_EnergyFlow*/   /*MP5_0x382*/
{  Can_Ch0_Il_Rx_Msg_MP5_0x382,                             1,             0,             5,             0,             5  },/*235*/  /*MP5_SetMultiButton*/   /*MP5_0x382*/
{  Can_Ch0_Il_Rx_Msg_MP5_0x382,                             1,             0,             6,             0,             6  },/*236*/  /*MP5_BSDSoundSwitchSts*/   /*MP5_0x382*/
{  Can_Ch0_Il_Rx_Msg_MP5_0x382,                             1,             1,             7,             1,             6  },/*237*/  /*MP5_NavStatus*/   /*MP5_0x382*/
{  Can_Ch0_Il_Rx_Msg_MP5_0x384,                             1,             0,             7,             0,             1  },/*238*/  /*MP5_NavICON*/   /*MP5_0x384*/
{  Can_Ch0_Il_Rx_Msg_MP5_0x384,                             3,             1,             7,             3,             0  },/*239*/  /*MP5_ROUTE_REMAIN_DIS*/   /*MP5_0x384*/
{  Can_Ch0_Il_Rx_Msg_MP5_0x384,                             1,             5,             2,             5,             0  },/*240*/  /*MP5_ALModeSetting*/   /*MP5_0x384*/
{  Can_Ch0_Il_Rx_Msg_MP5_0x384,                             1,             5,             3,             5,             3  },/*241*/  /*MP5_ALStartAroundSetting*/   /*MP5_0x384*/
{  Can_Ch0_Il_Rx_Msg_GW_TCU_Info_0x395,                     1,             1,             2,             1,             1  },/*242*/  /*TCU_EmergencyTowingSts*/   /*GW_TCU_Info_0x395*/
{  Can_Ch0_Il_Rx_Msg_GW_TCU_Info_0x395,                     1,             1,             6,             1,             6  },/*243*/  /*TrnSrvcRqd_B_Rq*/   /*GW_TCU_Info_0x395*/
{  Can_Ch0_Il_Rx_Msg_GW_TCU_Info_0x395,                     1,             3,             0,             3,             0  },/*244*/  /*TCU_GearPFault*/   /*GW_TCU_Info_0x395*/
{  Can_Ch0_Il_Rx_Msg_GW_TCU_Info_0x395,                     1,             4,             5,             4,             3  },/*245*/  /*TCU_WarningMessage*/   /*GW_TCU_Info_0x395*/
{  Can_Ch0_Il_Rx_Msg_GW_TCU_Info_0x395,                     1,             4,             7,             4,             6  },/*246*/  /*TCU_DrvShiftAllwCondRmd*/   /*GW_TCU_Info_0x395*/
{  Can_Ch0_Il_Rx_Msg_GW_MRR_FRObj_0x480,                    2,             0,             7,             1,             4  },/*247*/  /*MRR_L_Object_dx*/   /*GW_MRR_FRObj_0x480*/
{  Can_Ch0_Il_Rx_Msg_GW_MRR_FRObj_0x480,                    2,             1,             3,             2,             3  },/*248*/  /*MRR_L_Object_dy*/   /*GW_MRR_FRObj_0x480*/
{  Can_Ch0_Il_Rx_Msg_GW_MRR_FRObj_0x480,                    1,             2,             2,             2,             0  },/*249*/  /*MRR_L_Obj_0x_class*/   /*GW_MRR_FRObj_0x480*/
{  Can_Ch0_Il_Rx_Msg_GW_MRR_FRObj_0x480,                    2,             3,             7,             4,             4  },/*250*/  /*MRR_R_Object_dx*/   /*GW_MRR_FRObj_0x480*/
{  Can_Ch0_Il_Rx_Msg_GW_MRR_FRObj_0x480,                    2,             4,             3,             5,             3  },/*251*/  /*MRR_R_Object_dy*/   /*GW_MRR_FRObj_0x480*/
{  Can_Ch0_Il_Rx_Msg_GW_MRR_FRObj_0x480,                    1,             5,             2,             5,             0  },/*252*/  /*MRR_R_Obj_0x_class*/   /*GW_MRR_FRObj_0x480*/
{  Can_Ch0_Il_Rx_Msg_GW_MRR_FRObj_0x480,                    1,             6,             6,             6,             6  },/*253*/  /*MRR_LeftTargrtDetection*/   /*GW_MRR_FRObj_0x480*/
{  Can_Ch0_Il_Rx_Msg_GW_MRR_FRObj_0x480,                    1,             6,             7,             6,             7  },/*254*/  /*MRR_RightTargrtDetection*/   /*GW_MRR_FRObj_0x480*/
{  Can_Ch0_Il_Rx_Msg_GW_IPM_RightLine_0x490,                1,             0,             7,             0,             0  },/*255*/  /*IPM_RightLine_dx_start*/   /*GW_IPM_RightLine_0x490*/
{  Can_Ch0_Il_Rx_Msg_GW_IPM_RightLine_0x490,                2,             1,             7,             2,             4  },/*256*/  /*IPM_RightLine_dy*/   /*GW_IPM_RightLine_0x490*/
{  Can_Ch0_Il_Rx_Msg_GW_IPM_RightLine_0x490,                2,             2,             3,             3,             3  },/*257*/  /*IPM_RightLine_dx_lookhead*/   /*GW_IPM_RightLine_0x490*/
{  Can_Ch0_Il_Rx_Msg_GW_IPM_RightLine_0x490,                2,             3,             2,             4,             1  },/*258*/  /*IPM_RightLine_hor_curve*/   /*GW_IPM_RightLine_0x490*/
{  Can_Ch0_Il_Rx_Msg_GW_IPM_RightLine_0x490,                2,             5,             7,             6,             4  },/*259*/  /*IPM_RightLine_yawangle*/   /*GW_IPM_RightLine_0x490*/
{  Can_Ch0_Il_Rx_Msg_IPM_RightLine_0x491,                   1,             0,             1,             0,             0  },/*260*/  /*IPM_LaneAssit_RightVisualization*/   /*IPM_RightLine_0x491*/
{  Can_Ch0_Il_Rx_Msg_IPM_RightLine_0x491,                   1,             0,             4,             0,             2  },/*261*/  /*IPM_rightRighLine_Type*/   /*IPM_RightLine_0x491*/
{  Can_Ch0_Il_Rx_Msg_IPM_RightLine_0x491,                   1,             0,             7,             0,             5  },/*262*/  /*IPM_RighLine_Color*/   /*IPM_RightLine_0x491*/
{  Can_Ch0_Il_Rx_Msg_IPM_RightLine_0x491,                   1,             1,             4,             1,             2  },/*263*/  /*IPM_RighLine_Type*/   /*IPM_RightLine_0x491*/
{  Can_Ch0_Il_Rx_Msg_IPM_RightLine_0x491,                   1,             1,             7,             1,             5  },/*264*/  /*IPM_RighrightLine_Color*/   /*IPM_RightLine_0x491*/
{  Can_Ch0_Il_Rx_Msg_IPM_RightLine_0x491,                   2,             2,             7,             3,             4  },/*265*/  /*IPM_rightRightLine_dy*/   /*IPM_RightLine_0x491*/
{  Can_Ch0_Il_Rx_Msg_IPM_RightLine_0x491,                   2,             3,             2,             4,             1  },/*266*/  /*IPM_rightRightLine_hor_curve*/   /*IPM_RightLine_0x491*/
{  Can_Ch0_Il_Rx_Msg_IPM_RightLine_0x491,                   2,             5,             7,             6,             4  },/*267*/  /*IPM_rightRightLine_yawangle*/   /*IPM_RightLine_0x491*/
{  Can_Ch0_Il_Rx_Msg_IPM_RightLine_0x491,                   2,             6,             3,             7,             0  },/*268*/  /*IPM_RightLine_cur_alteration*/   /*IPM_RightLine_0x491*/
{  Can_Ch0_Il_Rx_Msg_GW_AVM_0x520,                          1,             0,             5,             0,             1  },/*269*/  /*AVM_displaytype*/   /*GW_AVM_0x520*/
{  Can_Ch0_Il_Rx_Msg_GW_AVM_0x520,                          1,             0,             7,             0,             6  },/*270*/  /*AVM_Status*/   /*GW_AVM_0x520*/
{  Can_Ch0_Il_Rx_Msg_GW_AVM_0x520,                          1,             1,             7,             1,             4  },/*271*/  /*AVM_Guide_line_info*/   /*GW_AVM_0x520*/
{  Can_Ch0_Il_Rx_Msg_GW_AVM_0x520,                          1,             2,             7,             2,             6  },/*272*/  /*AVM_Switch*/   /*GW_AVM_0x520*/
{  Can_Ch0_Il_Rx_Msg_MP5_0x530,                             1,             1,             3,             1,             2  },/*273*/  /*MP5_ICMenuShift_Button*/   /*MP5_0x530*/
{  Can_Ch0_Il_Rx_Msg_MP5_0x530,                             1,             2,             4,             2,             3  },/*274*/  /*MP5_ICMenuActive_Button*/   /*MP5_0x530*/
{  Can_Ch0_Il_Rx_Msg_MP5_0x530,                             1,             2,             6,             2,             5  },/*275*/  /*MP5_AlarmStatus*/   /*MP5_0x530*/
{  Can_Ch0_Il_Rx_Msg_MP5_0x530,                             1,             2,             7,             2,             7  },/*276*/  /*MP5_AlarmOrNot*/   /*MP5_0x530*/
{  Can_Ch0_Il_Rx_Msg_MP5_Windows_0x532,                     1,             3,             7,             3,             1  },/*277*/  /*MP5_ICMenu_Cmd*/   /*MP5_Windows_0x532*/
{  Can_Ch0_Il_Rx_Msg_MP5_NAV_0x533,                         1,             3,             7,             3,             7  },/*278*/  /*Nav_Sts*/   /*MP5_NAV_0x533*/
{  Can_Ch0_Il_Rx_Msg_MP5_Setting_0x535,                     1,             7,             7,             7,             0  },/*279*/  /*MP5_BGLLumLvlSetting*/   /*MP5_Setting_0x535*/
{  Can_Ch0_Il_Rx_Msg_WACM_WirelessChg_0x537,                1,             0,             7,             0,             4  },/*280*/  /*WACM_WirelessChargerStatus*/   /*WACM_WirelessChg_0x537*/
{  Can_Ch0_Il_Rx_Msg_GW_TBOX_time_0x582,                    1,             0,             7,             0,             0  },/*281*/  /*TBOX_Year*/   /*GW_TBOX_time_0x582*/
{  Can_Ch0_Il_Rx_Msg_GW_TBOX_time_0x582,                    1,             1,             7,             1,             0  },/*282*/  /*TBOX_Month*/   /*GW_TBOX_time_0x582*/
{  Can_Ch0_Il_Rx_Msg_GW_TBOX_time_0x582,                    1,             2,             7,             2,             0  },/*283*/  /*TBOX_Date*/   /*GW_TBOX_time_0x582*/
{  Can_Ch0_Il_Rx_Msg_GW_TBOX_time_0x582,                    1,             3,             7,             3,             0  },/*284*/  /*TBOX_Hour*/   /*GW_TBOX_time_0x582*/
{  Can_Ch0_Il_Rx_Msg_GW_TBOX_time_0x582,                    1,             4,             7,             4,             0  },/*285*/  /*TBOX_Minute*/   /*GW_TBOX_time_0x582*/
{  Can_Ch0_Il_Rx_Msg_GW_TBOX_time_0x582,                    1,             5,             7,             5,             0  },/*286*/  /*TBOX_Second*/   /*GW_TBOX_time_0x582*/
{  Can_Ch0_Il_Rx_Msg_GW_TBOX_time_0x582,                    1,             6,             7,             6,             7  },/*287*/  /*TBOX_ReTime*/   /*GW_TBOX_time_0x582*/
{  Can_Ch0_Il_Rx_Msg_BCM_0x584,                             1,             0,             1,             0,             0  },/*288*/  /*BCM_LoadManageLevel*/   /*BCM_0x584*/
{  Can_Ch0_Il_Rx_Msg_BCM_0x584,                             1,             0,             4,             0,             2  },/*289*/  /*BCM_CarModeIndicator*/   /*BCM_0x584*/
{  Can_Ch0_Il_Rx_Msg_BCM_0x584,                             1,             0,             7,             0,             5  },/*290*/  /*BCM_CarMode*/   /*BCM_0x584*/
{  Can_Ch0_Il_Rx_Msg_GW_AFS_0x5A0,                          1,             0,             7,             0,             6  },/*291*/  /*AFS_WorkSts*/   /*GW_AFS_0x5A0*/
{  Can_Ch0_Il_Rx_Msg_SCMM_0x5A3,                            1,             0,             4,             0,             0  },/*292*/  /*SCMM_HMIDisplay*/   /*SCMM_0x5A3*/
{  Can_Ch0_Il_Rx_Msg_GW_EMS_0x636,                          4,             0,             7,             3,             0  },/*293*/  /*EMS_BackupOdometer*/   /*GW_EMS_0x636*/
};
/* ===========================================================================
  Interaction Layer Receive Frame Data Storage and Status
 =========================================================================*/
CAN_UINT8 Can_Ch0_Il_Rx_Frame_Data[ Can_Ch0_Il_Rx_Num_Messages ][ CAN_MAX_DATA_LENGTH ];

CAN_UINT8 Can_Ch0_Il_Rx_Frame_Status[ Can_Ch0_Il_Rx_Num_Messages ];

CAN_UINT16 Can_Ch0_Il_Rx_Timeout_Count[ Can_Ch0_Il_Rx_Num_Messages ];

Can_Il_Rx_Data_Pointer Can_Ch0_Il_Receive_Ptr[ Can_Ch0_Il_Rx_Num_Messages ][ CAN_MAX_DATA_LENGTH ];

#if (Can_Ch0_Il_Rx_Num_Req_Frames > 0)

#define CAN_CHANNEL0_IL_DATA_REQ_TX_HANDLE
#define CAN_CHANNEL0_IL_REQ_TX_CANID

static CAN_UINT8  reqCounter[ Can_Ch0_Il_Rx_Num_Req_Frames ];
static CAN_UINT16 reqTimer[ Can_Ch0_Il_Rx_Num_Req_Frames ];
static CAN_UINT8  reqStatus[ Can_Ch0_Il_Rx_Num_Req_Frames ];

static const CAN_UINT8 Can_Ch0_Il_Data_Request[2] = {0x00,0x00};

static const CAN_IL_TMD Can_Ch0_Il_Data_Request_Frame_Tmd[ Can_Ch0_Il_Rx_Num_Req_Frames ] =
{
};

static const Can_Ch0_Il_Rx_Frame_Request Can_Ch0_Il_Rx_Request_Frame_Data[ Can_Ch0_Il_Rx_Num_Req_Frames ] =
{
};

#endif


/* ===========================================================================
  Received Frame Attributes Lookup Table

  This table includes the attributes for all of the received frames.
  If a received frame is periodic, this table also includes pointers to the
  received frame status and to the receive timeout counter for message
  gain and loss indication. If a transmitted frame request can be issued
  for a received frame, this table includes the pointer to the receive
  frame request attributes.

 =========================================================================*/
CAN_IL_RX_FRAME const
Can_Ch0_Il_Rx_Frame_Table[ Can_Ch0_Il_Rx_Num_Messages ] =
{
/* SCU_0xC8 */ /*0*/
 {
     (IL_RX_ATTR_PERIODIC | IL_RX_ATTR_TIMEOUT_MONITOR),
     0,      /* Signal Start Index                   */
     1,      /* Number of Signals in Message         */
     CAN_GPNUM_8,           /* Minimum Data Length Code             */
     &Can_Ch0_Il_Rx_Frame_Status[ 0],      /* Pointer to Receive Status            */
     Can_Ch0_Il_Rx_Frame_Data[ 0],         /* Pointer to Received Frame Data       */
     &Can_Ch0_Il_Rx_Timeout_Count[0],         /* Pointer to the Timeout Counter       */
     IL_TIME_IN_TASK_TICS(1900),     /* Timeout Count Value                  */
     NULL,                                       /* &Can_Ch0_Il_Rx_Frame_Request_Table[ 0 ] */  /* Ptr to Receive Request Attributes    */ 
},
/* GW_EMS_Power_0x10B */ /*1*/
 {
     (IL_RX_ATTR_PERIODIC | IL_RX_ATTR_TIMEOUT_MONITOR),
     1,      /* Signal Start Index                   */
     5,      /* Number of Signals in Message         */
     CAN_GPNUM_8,           /* Minimum Data Length Code             */
     &Can_Ch0_Il_Rx_Frame_Status[ 1],      /* Pointer to Receive Status            */
     Can_Ch0_Il_Rx_Frame_Data[ 1],         /* Pointer to Received Frame Data       */
     &Can_Ch0_Il_Rx_Timeout_Count[1],         /* Pointer to the Timeout Counter       */
     IL_TIME_IN_TASK_TICS(1900),     /* Timeout Count Value                  */
     NULL,                                       /* &Can_Ch0_Il_Rx_Frame_Request_Table[ 0 ] */  /* Ptr to Receive Request Attributes    */ 
},
/* GW_TCU_GearInfo_Power_0x123 */ /*2*/
 {
     (IL_RX_ATTR_PERIODIC | IL_RX_ATTR_TIMEOUT_MONITOR),
     6,      /* Signal Start Index                   */
     5,      /* Number of Signals in Message         */
     CAN_GPNUM_8,           /* Minimum Data Length Code             */
     &Can_Ch0_Il_Rx_Frame_Status[ 2],      /* Pointer to Receive Status            */
     Can_Ch0_Il_Rx_Frame_Data[ 2],         /* Pointer to Received Frame Data       */
     &Can_Ch0_Il_Rx_Timeout_Count[2],         /* Pointer to the Timeout Counter       */
     IL_TIME_IN_TASK_TICS(1900),     /* Timeout Count Value                  */
     NULL,                                       /* &Can_Ch0_Il_Rx_Frame_Request_Table[ 0 ] */  /* Ptr to Receive Request Attributes    */ 
},
/* GW_EMS_Sts_Power_0x151 */ /*3*/
 {
     (IL_RX_ATTR_PERIODIC | IL_RX_ATTR_TIMEOUT_MONITOR),
     11,      /* Signal Start Index                   */
     2,      /* Number of Signals in Message         */
     CAN_GPNUM_8,           /* Minimum Data Length Code             */
     &Can_Ch0_Il_Rx_Frame_Status[ 3],      /* Pointer to Receive Status            */
     Can_Ch0_Il_Rx_Frame_Data[ 3],         /* Pointer to Received Frame Data       */
     &Can_Ch0_Il_Rx_Timeout_Count[3],         /* Pointer to the Timeout Counter       */
     IL_TIME_IN_TASK_TICS(1900),     /* Timeout Count Value                  */
     NULL,                                       /* &Can_Ch0_Il_Rx_Frame_Request_Table[ 0 ] */  /* Ptr to Receive Request Attributes    */ 
},
/* GW_TBOX_IVI_0x1A2 */ /*4*/
 {
     (IL_RX_ATTR_PERIODIC | IL_RX_ATTR_TIMEOUT_MONITOR),
     13,      /* Signal Start Index                   */
     1,      /* Number of Signals in Message         */
     CAN_GPNUM_8,           /* Minimum Data Length Code             */
     &Can_Ch0_Il_Rx_Frame_Status[ 4],      /* Pointer to Receive Status            */
     Can_Ch0_Il_Rx_Frame_Data[ 4],         /* Pointer to Received Frame Data       */
     &Can_Ch0_Il_Rx_Timeout_Count[4],         /* Pointer to the Timeout Counter       */
     IL_TIME_IN_TASK_TICS(1900),     /* Timeout Count Value                  */
     NULL,                                       /* &Can_Ch0_Il_Rx_Frame_Request_Table[ 0 ] */  /* Ptr to Receive Request Attributes    */ 
},
/* PEPS_Start_0x1A5 */ /*5*/
 {
     (IL_RX_ATTR_PERIODIC | IL_RX_ATTR_TIMEOUT_MONITOR),
     14,      /* Signal Start Index                   */
     1,      /* Number of Signals in Message         */
     CAN_GPNUM_8,           /* Minimum Data Length Code             */
     &Can_Ch0_Il_Rx_Frame_Status[ 5],      /* Pointer to Receive Status            */
     Can_Ch0_Il_Rx_Frame_Data[ 5],         /* Pointer to Received Frame Data       */
     &Can_Ch0_Il_Rx_Timeout_Count[5],         /* Pointer to the Timeout Counter       */
     IL_TIME_IN_TASK_TICS(1900),     /* Timeout Count Value                  */
     NULL,                                       /* &Can_Ch0_Il_Rx_Frame_Request_Table[ 0 ] */  /* Ptr to Receive Request Attributes    */ 
},
/* GW_ABS_Sts_0x221 */ /*6*/
 {
     (IL_RX_ATTR_PERIODIC | IL_RX_ATTR_TIMEOUT_MONITOR),
     15,      /* Signal Start Index                   */
     9,      /* Number of Signals in Message         */
     CAN_GPNUM_8,           /* Minimum Data Length Code             */
     &Can_Ch0_Il_Rx_Frame_Status[ 6],      /* Pointer to Receive Status            */
     Can_Ch0_Il_Rx_Frame_Data[ 6],         /* Pointer to Received Frame Data       */
     &Can_Ch0_Il_Rx_Timeout_Count[6],         /* Pointer to the Timeout Counter       */
     IL_TIME_IN_TASK_TICS(1900),     /* Timeout Count Value                  */
     NULL,                                       /* &Can_Ch0_Il_Rx_Frame_Request_Table[ 0 ] */  /* Ptr to Receive Request Attributes    */ 
},
/* GW_ESP_Status_Chassis_0x243 */ /*7*/
 {
     (IL_RX_ATTR_PERIODIC | IL_RX_ATTR_TIMEOUT_MONITOR),
     24,      /* Signal Start Index                   */
     20,      /* Number of Signals in Message         */
     CAN_GPNUM_8,           /* Minimum Data Length Code             */
     &Can_Ch0_Il_Rx_Frame_Status[ 7],      /* Pointer to Receive Status            */
     Can_Ch0_Il_Rx_Frame_Data[ 7],         /* Pointer to Received Frame Data       */
     &Can_Ch0_Il_Rx_Timeout_Count[7],         /* Pointer to the Timeout Counter       */
     IL_TIME_IN_TASK_TICS(1900),     /* Timeout Count Value                  */
     NULL,                                       /* &Can_Ch0_Il_Rx_Frame_Request_Table[ 0 ] */  /* Ptr to Receive Request Attributes    */ 
},
/* GW_IPM_0x245 */ /*8*/
 {
     (IL_RX_ATTR_PERIODIC | IL_RX_ATTR_TIMEOUT_MONITOR),
     44,      /* Signal Start Index                   */
     13,      /* Number of Signals in Message         */
     CAN_GPNUM_8,           /* Minimum Data Length Code             */
     &Can_Ch0_Il_Rx_Frame_Status[ 8],      /* Pointer to Receive Status            */
     Can_Ch0_Il_Rx_Frame_Data[ 8],         /* Pointer to Received Frame Data       */
     &Can_Ch0_Il_Rx_Timeout_Count[8],         /* Pointer to the Timeout Counter       */
     IL_TIME_IN_TASK_TICS(1900),     /* Timeout Count Value                  */
     NULL,                                       /* &Can_Ch0_Il_Rx_Frame_Request_Table[ 0 ] */  /* Ptr to Receive Request Attributes    */ 
},
/* GW_MRR_Chassis_0x246 */ /*9*/
 {
     (IL_RX_ATTR_PERIODIC | IL_RX_ATTR_TIMEOUT_MONITOR),
     57,      /* Signal Start Index                   */
     16,      /* Number of Signals in Message         */
     CAN_GPNUM_8,           /* Minimum Data Length Code             */
     &Can_Ch0_Il_Rx_Frame_Status[ 9],      /* Pointer to Receive Status            */
     Can_Ch0_Il_Rx_Frame_Data[ 9],         /* Pointer to Received Frame Data       */
     &Can_Ch0_Il_Rx_Timeout_Count[9],         /* Pointer to the Timeout Counter       */
     IL_TIME_IN_TASK_TICS(1900),     /* Timeout Count Value                  */
     NULL,                                       /* &Can_Ch0_Il_Rx_Frame_Request_Table[ 0 ] */  /* Ptr to Receive Request Attributes    */ 
},
/* GW_IPM_0x247 */ /*10*/
 {
     (IL_RX_ATTR_PERIODIC | IL_RX_ATTR_TIMEOUT_MONITOR),
     73,      /* Signal Start Index                   */
     3,      /* Number of Signals in Message         */
     CAN_GPNUM_8,           /* Minimum Data Length Code             */
     &Can_Ch0_Il_Rx_Frame_Status[ 10],      /* Pointer to Receive Status            */
     Can_Ch0_Il_Rx_Frame_Data[ 10],         /* Pointer to Received Frame Data       */
     &Can_Ch0_Il_Rx_Timeout_Count[10],         /* Pointer to the Timeout Counter       */
     IL_TIME_IN_TASK_TICS(1900),     /* Timeout Count Value                  */
     NULL,                                       /* &Can_Ch0_Il_Rx_Frame_Request_Table[ 0 ] */  /* Ptr to Receive Request Attributes    */ 
},
/* GW_EPS_Chassis_0x260 */ /*11*/
 {
     (IL_RX_ATTR_PERIODIC | IL_RX_ATTR_TIMEOUT_MONITOR),
     76,      /* Signal Start Index                   */
     4,      /* Number of Signals in Message         */
     CAN_GPNUM_8,           /* Minimum Data Length Code             */
     &Can_Ch0_Il_Rx_Frame_Status[ 11],      /* Pointer to Receive Status            */
     Can_Ch0_Il_Rx_Frame_Data[ 11],         /* Pointer to Received Frame Data       */
     &Can_Ch0_Il_Rx_Timeout_Count[11],         /* Pointer to the Timeout Counter       */
     IL_TIME_IN_TASK_TICS(1900),     /* Timeout Count Value                  */
     NULL,                                       /* &Can_Ch0_Il_Rx_Frame_Request_Table[ 0 ] */  /* Ptr to Receive Request Attributes    */ 
},
/* GW_PAM_0x271 */ /*12*/
 {
     (IL_RX_ATTR_PERIODIC | IL_RX_ATTR_TIMEOUT_MONITOR),
     80,      /* Signal Start Index                   */
     4,      /* Number of Signals in Message         */
     CAN_GPNUM_8,           /* Minimum Data Length Code             */
     &Can_Ch0_Il_Rx_Frame_Status[ 12],      /* Pointer to Receive Status            */
     Can_Ch0_Il_Rx_Frame_Data[ 12],         /* Pointer to Received Frame Data       */
     &Can_Ch0_Il_Rx_Timeout_Count[12],         /* Pointer to the Timeout Counter       */
     IL_TIME_IN_TASK_TICS(1900),     /* Timeout Count Value                  */
     NULL,                                       /* &Can_Ch0_Il_Rx_Frame_Request_Table[ 0 ] */  /* Ptr to Receive Request Attributes    */ 
},
/* GW_PAM_0x274 */ /*13*/
 {
     (IL_RX_ATTR_PERIODIC | IL_RX_ATTR_TIMEOUT_MONITOR),
     84,      /* Signal Start Index                   */
     8,      /* Number of Signals in Message         */
     CAN_GPNUM_8,           /* Minimum Data Length Code             */
     &Can_Ch0_Il_Rx_Frame_Status[ 13],      /* Pointer to Receive Status            */
     Can_Ch0_Il_Rx_Frame_Data[ 13],         /* Pointer to Received Frame Data       */
     &Can_Ch0_Il_Rx_Timeout_Count[13],         /* Pointer to the Timeout Counter       */
     IL_TIME_IN_TASK_TICS(1900),     /* Timeout Count Value                  */
     NULL,                                       /* &Can_Ch0_Il_Rx_Frame_Request_Table[ 0 ] */  /* Ptr to Receive Request Attributes    */ 
},
/* GW_SOD_0x275 */ /*14*/
 {
     (IL_RX_ATTR_PERIODIC | IL_RX_ATTR_TIMEOUT_MONITOR),
     92,      /* Signal Start Index                   */
     12,      /* Number of Signals in Message         */
     CAN_GPNUM_8,           /* Minimum Data Length Code             */
     &Can_Ch0_Il_Rx_Frame_Status[ 14],      /* Pointer to Receive Status            */
     Can_Ch0_Il_Rx_Frame_Data[ 14],         /* Pointer to Received Frame Data       */
     &Can_Ch0_Il_Rx_Timeout_Count[14],         /* Pointer to the Timeout Counter       */
     IL_TIME_IN_TASK_TICS(1900),     /* Timeout Count Value                  */
     NULL,                                       /* &Can_Ch0_Il_Rx_Frame_Request_Table[ 0 ] */  /* Ptr to Receive Request Attributes    */ 
},
/* GW_IPM_LeftLine_0x278 */ /*15*/
 {
     (IL_RX_ATTR_PERIODIC | IL_RX_ATTR_TIMEOUT_MONITOR),
     104,      /* Signal Start Index                   */
     5,      /* Number of Signals in Message         */
     CAN_GPNUM_8,           /* Minimum Data Length Code             */
     &Can_Ch0_Il_Rx_Frame_Status[ 15],      /* Pointer to Receive Status            */
     Can_Ch0_Il_Rx_Frame_Data[ 15],         /* Pointer to Received Frame Data       */
     &Can_Ch0_Il_Rx_Timeout_Count[15],         /* Pointer to the Timeout Counter       */
     IL_TIME_IN_TASK_TICS(1900),     /* Timeout Count Value                  */
     NULL,                                       /* &Can_Ch0_Il_Rx_Frame_Request_Table[ 0 ] */  /* Ptr to Receive Request Attributes    */ 
},
/* GW_MRR_FrObj_0x279 */ /*16*/
 {
     (IL_RX_ATTR_PERIODIC | IL_RX_ATTR_TIMEOUT_MONITOR),
     109,      /* Signal Start Index                   */
     8,      /* Number of Signals in Message         */
     CAN_GPNUM_8,           /* Minimum Data Length Code             */
     &Can_Ch0_Il_Rx_Frame_Status[ 16],      /* Pointer to Receive Status            */
     Can_Ch0_Il_Rx_Frame_Data[ 16],         /* Pointer to Received Frame Data       */
     &Can_Ch0_Il_Rx_Timeout_Count[16],         /* Pointer to the Timeout Counter       */
     IL_TIME_IN_TASK_TICS(1900),     /* Timeout Count Value                  */
     NULL,                                       /* &Can_Ch0_Il_Rx_Frame_Request_Table[ 0 ] */  /* Ptr to Receive Request Attributes    */ 
},
/* GW_IPM_LeftLine_0x280 */ /*17*/
 {
     (IL_RX_ATTR_PERIODIC | IL_RX_ATTR_TIMEOUT_MONITOR),
     117,      /* Signal Start Index                   */
     9,      /* Number of Signals in Message         */
     CAN_GPNUM_8,           /* Minimum Data Length Code             */
     &Can_Ch0_Il_Rx_Frame_Status[ 17],      /* Pointer to Receive Status            */
     Can_Ch0_Il_Rx_Frame_Data[ 17],         /* Pointer to Received Frame Data       */
     &Can_Ch0_Il_Rx_Timeout_Count[17],         /* Pointer to the Timeout Counter       */
     IL_TIME_IN_TASK_TICS(1900),     /* Timeout Count Value                  */
     NULL,                                       /* &Can_Ch0_Il_Rx_Frame_Request_Table[ 0 ] */  /* Ptr to Receive Request Attributes    */ 
},
/* BCM_Door_0x310 */ /*18*/
 {
     (IL_RX_ATTR_PERIODIC | IL_RX_ATTR_TIMEOUT_MONITOR),
     126,      /* Signal Start Index                   */
     17,      /* Number of Signals in Message         */
     CAN_GPNUM_8,           /* Minimum Data Length Code             */
     &Can_Ch0_Il_Rx_Frame_Status[ 18],      /* Pointer to Receive Status            */
     Can_Ch0_Il_Rx_Frame_Data[ 18],         /* Pointer to Received Frame Data       */
     &Can_Ch0_Il_Rx_Timeout_Count[18],         /* Pointer to the Timeout Counter       */
     IL_TIME_IN_TASK_TICS(1900),     /* Timeout Count Value                  */
     NULL,                                       /* &Can_Ch0_Il_Rx_Frame_Request_Table[ 0 ] */  /* Ptr to Receive Request Attributes    */ 
},
/* BCM_0x313 */ /*19*/
 {
     (IL_RX_ATTR_PERIODIC | IL_RX_ATTR_TIMEOUT_MONITOR),
     143,      /* Signal Start Index                   */
     7,      /* Number of Signals in Message         */
     CAN_GPNUM_8,           /* Minimum Data Length Code             */
     &Can_Ch0_Il_Rx_Frame_Status[ 19],      /* Pointer to Receive Status            */
     Can_Ch0_Il_Rx_Frame_Data[ 19],         /* Pointer to Received Frame Data       */
     &Can_Ch0_Il_Rx_Timeout_Count[19],         /* Pointer to the Timeout Counter       */
     IL_TIME_IN_TASK_TICS(1900),     /* Timeout Count Value                  */
     NULL,                                       /* &Can_Ch0_Il_Rx_Frame_Request_Table[ 0 ] */  /* Ptr to Receive Request Attributes    */ 
},
/* BCM_Sts_0x315 */ /*20*/
 {
     (IL_RX_ATTR_PERIODIC | IL_RX_ATTR_TIMEOUT_MONITOR),
     150,      /* Signal Start Index                   */
     1,      /* Number of Signals in Message         */
     CAN_GPNUM_8,           /* Minimum Data Length Code             */
     &Can_Ch0_Il_Rx_Frame_Status[ 20],      /* Pointer to Receive Status            */
     Can_Ch0_Il_Rx_Frame_Data[ 20],         /* Pointer to Received Frame Data       */
     &Can_Ch0_Il_Rx_Timeout_Count[20],         /* Pointer to the Timeout Counter       */
     IL_TIME_IN_TASK_TICS(1900),     /* Timeout Count Value                  */
     NULL,                                       /* &Can_Ch0_Il_Rx_Frame_Request_Table[ 0 ] */  /* Ptr to Receive Request Attributes    */ 
},
/* BCM_Lamp_0x318 */ /*21*/
 {
     (IL_RX_ATTR_PERIODIC | IL_RX_ATTR_TIMEOUT_MONITOR),
     151,      /* Signal Start Index                   */
     24,      /* Number of Signals in Message         */
     CAN_GPNUM_8,           /* Minimum Data Length Code             */
     &Can_Ch0_Il_Rx_Frame_Status[ 21],      /* Pointer to Receive Status            */
     Can_Ch0_Il_Rx_Frame_Data[ 21],         /* Pointer to Received Frame Data       */
     &Can_Ch0_Il_Rx_Timeout_Count[21],         /* Pointer to the Timeout Counter       */
     IL_TIME_IN_TASK_TICS(1900),     /* Timeout Count Value                  */
     NULL,                                       /* &Can_Ch0_Il_Rx_Frame_Request_Table[ 0 ] */  /* Ptr to Receive Request Attributes    */ 
},
/* GW_SWM_Body_0x31A */ /*22*/
 {
     (IL_RX_ATTR_EVENT | IL_RX_ATTR_PERIODIC | IL_RX_ATTR_TIMEOUT_MONITOR),
     175,      /* Signal Start Index                   */
     8,      /* Number of Signals in Message         */
     CAN_GPNUM_8,           /* Minimum Data Length Code             */
     &Can_Ch0_Il_Rx_Frame_Status[ 22],      /* Pointer to Receive Status            */
     Can_Ch0_Il_Rx_Frame_Data[ 22],         /* Pointer to Received Frame Data       */
     &Can_Ch0_Il_Rx_Timeout_Count[22],         /* Pointer to the Timeout Counter       */
     IL_TIME_IN_TASK_TICS(1900),     /* Timeout Count Value                  */
     NULL,                                       /* &Can_Ch0_Il_Rx_Frame_Request_Table[ 0 ] */  /* Ptr to Receive Request Attributes    */ 
},
/* GW_SWM_MRR_0x31B */ /*23*/
 {
     (IL_RX_ATTR_EVENT | IL_RX_ATTR_PERIODIC | IL_RX_ATTR_TIMEOUT_MONITOR),
     183,      /* Signal Start Index                   */
     8,      /* Number of Signals in Message         */
     CAN_GPNUM_8,           /* Minimum Data Length Code             */
     &Can_Ch0_Il_Rx_Frame_Status[ 23],      /* Pointer to Receive Status            */
     Can_Ch0_Il_Rx_Frame_Data[ 23],         /* Pointer to Received Frame Data       */
     &Can_Ch0_Il_Rx_Timeout_Count[23],         /* Pointer to the Timeout Counter       */
     IL_TIME_IN_TASK_TICS(1900),     /* Timeout Count Value                  */
     NULL,                                       /* &Can_Ch0_Il_Rx_Frame_Request_Table[ 0 ] */  /* Ptr to Receive Request Attributes    */ 
},
/* PEPS_0x325 */ /*24*/
 {
     (IL_RX_ATTR_PERIODIC | IL_RX_ATTR_TIMEOUT_MONITOR),
     191,      /* Signal Start Index                   */
     14,      /* Number of Signals in Message         */
     CAN_GPNUM_8,           /* Minimum Data Length Code             */
     &Can_Ch0_Il_Rx_Frame_Status[ 24],      /* Pointer to Receive Status            */
     Can_Ch0_Il_Rx_Frame_Data[ 24],         /* Pointer to Received Frame Data       */
     &Can_Ch0_Il_Rx_Timeout_Count[24],         /* Pointer to the Timeout Counter       */
     IL_TIME_IN_TASK_TICS(1900),     /* Timeout Count Value                  */
     NULL,                                       /* &Can_Ch0_Il_Rx_Frame_Request_Table[ 0 ] */  /* Ptr to Receive Request Attributes    */ 
},
/* GW_SRS_0x350 */ /*25*/
 {
     (IL_RX_ATTR_EVENT | IL_RX_ATTR_PERIODIC | IL_RX_ATTR_TIMEOUT_MONITOR),
     205,      /* Signal Start Index                   */
     8,      /* Number of Signals in Message         */
     CAN_GPNUM_8,           /* Minimum Data Length Code             */
     &Can_Ch0_Il_Rx_Frame_Status[ 25],      /* Pointer to Receive Status            */
     Can_Ch0_Il_Rx_Frame_Data[ 25],         /* Pointer to Received Frame Data       */
     &Can_Ch0_Il_Rx_Timeout_Count[25],         /* Pointer to the Timeout Counter       */
     IL_TIME_IN_TASK_TICS(1900),     /* Timeout Count Value                  */
     NULL,                                       /* &Can_Ch0_Il_Rx_Frame_Request_Table[ 0 ] */  /* Ptr to Receive Request Attributes    */ 
},
/* TPMS_Tire_0x361 */ /*26*/
 {
     (IL_RX_ATTR_PERIODIC | IL_RX_ATTR_TIMEOUT_MONITOR),
     213,      /* Signal Start Index                   */
     14,      /* Number of Signals in Message         */
     CAN_GPNUM_8,           /* Minimum Data Length Code             */
     &Can_Ch0_Il_Rx_Frame_Status[ 26],      /* Pointer to Receive Status            */
     Can_Ch0_Il_Rx_Frame_Data[ 26],         /* Pointer to Received Frame Data       */
     &Can_Ch0_Il_Rx_Timeout_Count[26],         /* Pointer to the Timeout Counter       */
     IL_TIME_IN_TASK_TICS(1900),     /* Timeout Count Value                  */
     NULL,                                       /* &Can_Ch0_Il_Rx_Frame_Request_Table[ 0 ] */  /* Ptr to Receive Request Attributes    */ 
},
/* GW_EMS_Power_0x366 */ /*27*/
 {
     (IL_RX_ATTR_PERIODIC | IL_RX_ATTR_TIMEOUT_MONITOR),
     227,      /* Signal Start Index                   */
     5,      /* Number of Signals in Message         */
     CAN_GPNUM_8,           /* Minimum Data Length Code             */
     &Can_Ch0_Il_Rx_Frame_Status[ 27],      /* Pointer to Receive Status            */
     Can_Ch0_Il_Rx_Frame_Data[ 27],         /* Pointer to Received Frame Data       */
     &Can_Ch0_Il_Rx_Timeout_Count[27],         /* Pointer to the Timeout Counter       */
     IL_TIME_IN_TASK_TICS(1900),     /* Timeout Count Value                  */
     NULL,                                       /* &Can_Ch0_Il_Rx_Frame_Request_Table[ 0 ] */  /* Ptr to Receive Request Attributes    */ 
},
/* GW_EMS_0x368 */ /*28*/
 {
     (IL_RX_ATTR_PERIODIC | IL_RX_ATTR_TIMEOUT_MONITOR),
     232,      /* Signal Start Index                   */
     1,      /* Number of Signals in Message         */
     CAN_GPNUM_8,           /* Minimum Data Length Code             */
     &Can_Ch0_Il_Rx_Frame_Status[ 28],      /* Pointer to Receive Status            */
     Can_Ch0_Il_Rx_Frame_Data[ 28],         /* Pointer to Received Frame Data       */
     &Can_Ch0_Il_Rx_Timeout_Count[28],         /* Pointer to the Timeout Counter       */
     IL_TIME_IN_TASK_TICS(1900),     /* Timeout Count Value                  */
     NULL,                                       /* &Can_Ch0_Il_Rx_Frame_Request_Table[ 0 ] */  /* Ptr to Receive Request Attributes    */ 
},
/* MP5_0x382 */ /*29*/
 {
     (IL_RX_ATTR_EVENT | IL_RX_ATTR_PERIODIC | IL_RX_ATTR_TIMEOUT_MONITOR),
     233,      /* Signal Start Index                   */
     5,      /* Number of Signals in Message         */
     CAN_GPNUM_8,           /* Minimum Data Length Code             */
     &Can_Ch0_Il_Rx_Frame_Status[ 29],      /* Pointer to Receive Status            */
     Can_Ch0_Il_Rx_Frame_Data[ 29],         /* Pointer to Received Frame Data       */
     &Can_Ch0_Il_Rx_Timeout_Count[29],         /* Pointer to the Timeout Counter       */
     IL_TIME_IN_TASK_TICS(1900),     /* Timeout Count Value                  */
     NULL,                                       /* &Can_Ch0_Il_Rx_Frame_Request_Table[ 0 ] */  /* Ptr to Receive Request Attributes    */ 
},
/* MP5_0x384 */ /*30*/
 {
     (IL_RX_ATTR_EVENT | IL_RX_ATTR_PERIODIC | IL_RX_ATTR_TIMEOUT_MONITOR),
     238,      /* Signal Start Index                   */
     4,      /* Number of Signals in Message         */
     CAN_GPNUM_8,           /* Minimum Data Length Code             */
     &Can_Ch0_Il_Rx_Frame_Status[ 30],      /* Pointer to Receive Status            */
     Can_Ch0_Il_Rx_Frame_Data[ 30],         /* Pointer to Received Frame Data       */
     &Can_Ch0_Il_Rx_Timeout_Count[30],         /* Pointer to the Timeout Counter       */
     IL_TIME_IN_TASK_TICS(1900),     /* Timeout Count Value                  */
     NULL,                                       /* &Can_Ch0_Il_Rx_Frame_Request_Table[ 0 ] */  /* Ptr to Receive Request Attributes    */ 
},
/* GW_TCU_Info_0x395 */ /*31*/
 {
     (IL_RX_ATTR_PERIODIC | IL_RX_ATTR_TIMEOUT_MONITOR),
     242,      /* Signal Start Index                   */
     5,      /* Number of Signals in Message         */
     CAN_GPNUM_8,           /* Minimum Data Length Code             */
     &Can_Ch0_Il_Rx_Frame_Status[ 31],      /* Pointer to Receive Status            */
     Can_Ch0_Il_Rx_Frame_Data[ 31],         /* Pointer to Received Frame Data       */
     &Can_Ch0_Il_Rx_Timeout_Count[31],         /* Pointer to the Timeout Counter       */
     IL_TIME_IN_TASK_TICS(1900),     /* Timeout Count Value                  */
     NULL,                                       /* &Can_Ch0_Il_Rx_Frame_Request_Table[ 0 ] */  /* Ptr to Receive Request Attributes    */ 
},
/* GW_MRR_FRObj_0x480 */ /*32*/
 {
     (IL_RX_ATTR_PERIODIC | IL_RX_ATTR_TIMEOUT_MONITOR),
     247,      /* Signal Start Index                   */
     8,      /* Number of Signals in Message         */
     CAN_GPNUM_8,           /* Minimum Data Length Code             */
     &Can_Ch0_Il_Rx_Frame_Status[ 32],      /* Pointer to Receive Status            */
     Can_Ch0_Il_Rx_Frame_Data[ 32],         /* Pointer to Received Frame Data       */
     &Can_Ch0_Il_Rx_Timeout_Count[32],         /* Pointer to the Timeout Counter       */
     IL_TIME_IN_TASK_TICS(1900),     /* Timeout Count Value                  */
     NULL,                                       /* &Can_Ch0_Il_Rx_Frame_Request_Table[ 0 ] */  /* Ptr to Receive Request Attributes    */ 
},
/* GW_IPM_RightLine_0x490 */ /*33*/
 {
     (IL_RX_ATTR_PERIODIC | IL_RX_ATTR_TIMEOUT_MONITOR),
     255,      /* Signal Start Index                   */
     5,      /* Number of Signals in Message         */
     CAN_GPNUM_8,           /* Minimum Data Length Code             */
     &Can_Ch0_Il_Rx_Frame_Status[ 33],      /* Pointer to Receive Status            */
     Can_Ch0_Il_Rx_Frame_Data[ 33],         /* Pointer to Received Frame Data       */
     &Can_Ch0_Il_Rx_Timeout_Count[33],         /* Pointer to the Timeout Counter       */
     IL_TIME_IN_TASK_TICS(1900),     /* Timeout Count Value                  */
     NULL,                                       /* &Can_Ch0_Il_Rx_Frame_Request_Table[ 0 ] */  /* Ptr to Receive Request Attributes    */ 
},
/* IPM_RightLine_0x491 */ /*34*/
 {
     (IL_RX_ATTR_PERIODIC | IL_RX_ATTR_TIMEOUT_MONITOR),
     260,      /* Signal Start Index                   */
     9,      /* Number of Signals in Message         */
     CAN_GPNUM_8,           /* Minimum Data Length Code             */
     &Can_Ch0_Il_Rx_Frame_Status[ 34],      /* Pointer to Receive Status            */
     Can_Ch0_Il_Rx_Frame_Data[ 34],         /* Pointer to Received Frame Data       */
     &Can_Ch0_Il_Rx_Timeout_Count[34],         /* Pointer to the Timeout Counter       */
     IL_TIME_IN_TASK_TICS(1900),     /* Timeout Count Value                  */
     NULL,                                       /* &Can_Ch0_Il_Rx_Frame_Request_Table[ 0 ] */  /* Ptr to Receive Request Attributes    */ 
},
/* GW_AVM_0x520 */ /*35*/
 {
     (IL_RX_ATTR_PERIODIC | IL_RX_ATTR_TIMEOUT_MONITOR),
     269,      /* Signal Start Index                   */
     4,      /* Number of Signals in Message         */
     CAN_GPNUM_8,           /* Minimum Data Length Code             */
     &Can_Ch0_Il_Rx_Frame_Status[ 35],      /* Pointer to Receive Status            */
     Can_Ch0_Il_Rx_Frame_Data[ 35],         /* Pointer to Received Frame Data       */
     &Can_Ch0_Il_Rx_Timeout_Count[35],         /* Pointer to the Timeout Counter       */
     IL_TIME_IN_TASK_TICS(1900),     /* Timeout Count Value                  */
     NULL,                                       /* &Can_Ch0_Il_Rx_Frame_Request_Table[ 0 ] */  /* Ptr to Receive Request Attributes    */ 
},
/* MP5_0x530 */ /*36*/
 {
     (IL_RX_ATTR_EVENT | IL_RX_ATTR_PERIODIC | IL_RX_ATTR_TIMEOUT_MONITOR),
     273,      /* Signal Start Index                   */
     4,      /* Number of Signals in Message         */
     CAN_GPNUM_8,           /* Minimum Data Length Code             */
     &Can_Ch0_Il_Rx_Frame_Status[ 36],      /* Pointer to Receive Status            */
     Can_Ch0_Il_Rx_Frame_Data[ 36],         /* Pointer to Received Frame Data       */
     &Can_Ch0_Il_Rx_Timeout_Count[36],         /* Pointer to the Timeout Counter       */
     IL_TIME_IN_TASK_TICS(1900),     /* Timeout Count Value                  */
     NULL,                                       /* &Can_Ch0_Il_Rx_Frame_Request_Table[ 0 ] */  /* Ptr to Receive Request Attributes    */ 
},
/* MP5_Windows_0x532 */ /*37*/
 {
     (IL_RX_ATTR_EVENT | IL_RX_ATTR_PERIODIC | IL_RX_ATTR_TIMEOUT_MONITOR),
     277,      /* Signal Start Index                   */
     1,      /* Number of Signals in Message         */
     CAN_GPNUM_8,           /* Minimum Data Length Code             */
     &Can_Ch0_Il_Rx_Frame_Status[ 37],      /* Pointer to Receive Status            */
     Can_Ch0_Il_Rx_Frame_Data[ 37],         /* Pointer to Received Frame Data       */
     &Can_Ch0_Il_Rx_Timeout_Count[37],         /* Pointer to the Timeout Counter       */
     IL_TIME_IN_TASK_TICS(1900),     /* Timeout Count Value                  */
     NULL,                                       /* &Can_Ch0_Il_Rx_Frame_Request_Table[ 0 ] */  /* Ptr to Receive Request Attributes    */ 
},
/* MP5_NAV_0x533 */ /*38*/
 {
     (IL_RX_ATTR_EVENT | IL_RX_ATTR_PERIODIC | IL_RX_ATTR_TIMEOUT_MONITOR),
     278,      /* Signal Start Index                   */
     1,      /* Number of Signals in Message         */
     CAN_GPNUM_8,           /* Minimum Data Length Code             */
     &Can_Ch0_Il_Rx_Frame_Status[ 38],      /* Pointer to Receive Status            */
     Can_Ch0_Il_Rx_Frame_Data[ 38],         /* Pointer to Received Frame Data       */
     &Can_Ch0_Il_Rx_Timeout_Count[38],         /* Pointer to the Timeout Counter       */
     IL_TIME_IN_TASK_TICS(1900),     /* Timeout Count Value                  */
     NULL,                                       /* &Can_Ch0_Il_Rx_Frame_Request_Table[ 0 ] */  /* Ptr to Receive Request Attributes    */ 
},
/* MP5_Setting_0x535 */ /*39*/
 {
     (IL_RX_ATTR_EVENT | IL_RX_ATTR_PERIODIC | IL_RX_ATTR_TIMEOUT_MONITOR),
     279,      /* Signal Start Index                   */
     1,      /* Number of Signals in Message         */
     CAN_GPNUM_8,           /* Minimum Data Length Code             */
     &Can_Ch0_Il_Rx_Frame_Status[ 39],      /* Pointer to Receive Status            */
     Can_Ch0_Il_Rx_Frame_Data[ 39],         /* Pointer to Received Frame Data       */
     &Can_Ch0_Il_Rx_Timeout_Count[39],         /* Pointer to the Timeout Counter       */
     IL_TIME_IN_TASK_TICS(1900),     /* Timeout Count Value                  */
     NULL,                                       /* &Can_Ch0_Il_Rx_Frame_Request_Table[ 0 ] */  /* Ptr to Receive Request Attributes    */ 
},
/* WACM_WirelessChg_0x537 */ /*40*/
 {
     (IL_RX_ATTR_PERIODIC | IL_RX_ATTR_TIMEOUT_MONITOR),
     280,      /* Signal Start Index                   */
     1,      /* Number of Signals in Message         */
     CAN_GPNUM_8,           /* Minimum Data Length Code             */
     &Can_Ch0_Il_Rx_Frame_Status[ 40],      /* Pointer to Receive Status            */
     Can_Ch0_Il_Rx_Frame_Data[ 40],         /* Pointer to Received Frame Data       */
     &Can_Ch0_Il_Rx_Timeout_Count[40],         /* Pointer to the Timeout Counter       */
     IL_TIME_IN_TASK_TICS(1900),     /* Timeout Count Value                  */
     NULL,                                       /* &Can_Ch0_Il_Rx_Frame_Request_Table[ 0 ] */  /* Ptr to Receive Request Attributes    */ 
},
/* GW_TBOX_time_0x582 */ /*41*/
 {
     (IL_RX_ATTR_PERIODIC | IL_RX_ATTR_TIMEOUT_MONITOR),
     281,      /* Signal Start Index                   */
     7,      /* Number of Signals in Message         */
     CAN_GPNUM_8,           /* Minimum Data Length Code             */
     &Can_Ch0_Il_Rx_Frame_Status[ 41],      /* Pointer to Receive Status            */
     Can_Ch0_Il_Rx_Frame_Data[ 41],         /* Pointer to Received Frame Data       */
     &Can_Ch0_Il_Rx_Timeout_Count[41],         /* Pointer to the Timeout Counter       */
     IL_TIME_IN_TASK_TICS(4900),     /* Timeout Count Value                  */
     NULL,                                       /* &Can_Ch0_Il_Rx_Frame_Request_Table[ 0 ] */  /* Ptr to Receive Request Attributes    */ 
},
/* BCM_0x584 */ /*42*/
 {
     (IL_RX_ATTR_PERIODIC | IL_RX_ATTR_TIMEOUT_MONITOR),
     288,      /* Signal Start Index                   */
     3,      /* Number of Signals in Message         */
     CAN_GPNUM_8,           /* Minimum Data Length Code             */
     &Can_Ch0_Il_Rx_Frame_Status[ 42],      /* Pointer to Receive Status            */
     Can_Ch0_Il_Rx_Frame_Data[ 42],         /* Pointer to Received Frame Data       */
     &Can_Ch0_Il_Rx_Timeout_Count[42],         /* Pointer to the Timeout Counter       */
     IL_TIME_IN_TASK_TICS(1900),     /* Timeout Count Value                  */
     NULL,                                       /* &Can_Ch0_Il_Rx_Frame_Request_Table[ 0 ] */  /* Ptr to Receive Request Attributes    */ 
},
/* GW_AFS_0x5A0 */ /*43*/
 {
     (IL_RX_ATTR_PERIODIC | IL_RX_ATTR_TIMEOUT_MONITOR),
     291,      /* Signal Start Index                   */
     1,      /* Number of Signals in Message         */
     CAN_GPNUM_8,           /* Minimum Data Length Code             */
     &Can_Ch0_Il_Rx_Frame_Status[ 43],      /* Pointer to Receive Status            */
     Can_Ch0_Il_Rx_Frame_Data[ 43],         /* Pointer to Received Frame Data       */
     &Can_Ch0_Il_Rx_Timeout_Count[43],         /* Pointer to the Timeout Counter       */
     IL_TIME_IN_TASK_TICS(1900),     /* Timeout Count Value                  */
     NULL,                                       /* &Can_Ch0_Il_Rx_Frame_Request_Table[ 0 ] */  /* Ptr to Receive Request Attributes    */ 
},
/* SCMM_0x5A3 */ /*44*/
 {
     (IL_RX_ATTR_PERIODIC | IL_RX_ATTR_TIMEOUT_MONITOR),
     292,      /* Signal Start Index                   */
     1,      /* Number of Signals in Message         */
     CAN_GPNUM_8,           /* Minimum Data Length Code             */
     &Can_Ch0_Il_Rx_Frame_Status[ 44],      /* Pointer to Receive Status            */
     Can_Ch0_Il_Rx_Frame_Data[ 44],         /* Pointer to Received Frame Data       */
     &Can_Ch0_Il_Rx_Timeout_Count[44],         /* Pointer to the Timeout Counter       */
     IL_TIME_IN_TASK_TICS(1900),     /* Timeout Count Value                  */
     NULL,                                       /* &Can_Ch0_Il_Rx_Frame_Request_Table[ 0 ] */  /* Ptr to Receive Request Attributes    */ 
},
/* GW_EMS_0x636 */ /*45*/
 {
     (IL_RX_ATTR_PERIODIC | IL_RX_ATTR_TIMEOUT_MONITOR),
     293,      /* Signal Start Index                   */
     1,      /* Number of Signals in Message         */
     CAN_GPNUM_8,           /* Minimum Data Length Code             */
     &Can_Ch0_Il_Rx_Frame_Status[ 45],      /* Pointer to Receive Status            */
     Can_Ch0_Il_Rx_Frame_Data[ 45],         /* Pointer to Received Frame Data       */
     &Can_Ch0_Il_Rx_Timeout_Count[45],         /* Pointer to the Timeout Counter       */
     IL_TIME_IN_TASK_TICS(1900),     /* Timeout Count Value                  */
     NULL,                                       /* &Can_Ch0_Il_Rx_Frame_Request_Table[ 0 ] */  /* Ptr to Receive Request Attributes    */ 
},
};
pTxPrecopyfn const Can_Ch0_Il_Tx_Precopy_Function_Table[ Can_Ch0_Il_Tx_Num_Messages ] =
  {
     NULL  ,
     NULL  ,
     NULL  ,
     IC_0x510_RollingCounter_Checksum  ,
     NULL  ,
     IC_0x525_RollingCounter_Checksum  ,
     NULL  ,
};
/*****************************************************************************
    R E V I S I O N     N O T E S
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  -
For each change to this file, be sure to record:
1.   Who made the change and when the change was made.
2.   Why the change was made and the intended result.

Date       By         Reason For Change
------------------------------------------------------------------------------

******************************************************************************/
/*****************************************************************************
Date          : 2021-01-06 14:51:25
By              : ChengJia
Traceability    : JMC_SUV_Body_CAN_Matrix_20210104.dbc
Change Description  : Tool Generated code
*****************************************************************************/
