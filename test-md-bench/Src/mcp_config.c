
/**
  ******************************************************************************
  * @file    mcp_config.c
  * @author  Motor Control SDK Team, ST Microelectronics
  * @brief   This file provides configuration information of the MCP protocol
  *
  *
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */

#include "parameters_conversion.h"
#include "usart_aspep_driver.h"
#include "aspep.h"
#include "mcp.h"
#include "mcp_config.h"

static uint8_t MCPSyncTxBuff[MCP_TX_SYNCBUFFER_SIZE] __attribute__((aligned(4))); //cstat !MISRAC2012-Rule-1.4_a
static uint8_t MCPSyncRXBuff[MCP_RX_SYNCBUFFER_SIZE] __attribute__((aligned(4))); //cstat !MISRAC2012-Rule-1.4_a

MCP_user_cb_t MCP_UserCallBack[MCP_USER_CALLBACK_MAX];

/** @addtogroup MCSDK
  * @{
  */

/** @addtogroup MCP
  * @{
  */

static UASPEP_Handle_t UASPEP_A =
{
 .USARTx = USARTA,
 .rxDMA = DMA_RX_A,
 .txDMA = DMA_TX_A,
 .rxChannel = DMACH_RX_A,
 .txChannel = DMACH_TX_A,
};

ASPEP_Handle_t aspepOverUartA =
{
  ._Super =
   {
    .fGetBuffer = &ASPEP_getBuffer,
    .fSendPacket = &ASPEP_sendPacket,
    .fRXPacketProcess = &ASPEP_RXframeProcess,
    },
  .ASPEPIp = &UASPEP_A,
  .Capabilities =
  {
    .DATA_CRC = 0U,
    .RX_maxSize =  (MCP_RX_SYNC_PAYLOAD_MAX >> 5U) - 1U,
    .TXS_maxSize = (MCP_TX_SYNC_PAYLOAD_MAX >> 5U) - 1U,
    .TXA_maxSize =  0U,
    .version = 0x0U,
  },
  .syncBuffer =
  {
   .buffer = MCPSyncTxBuff,
  },
  .rxBuffer = MCPSyncRXBuff,
  .fASPEP_HWInit = &UASPEP_INIT,
  .fASPEP_HWSync = &UASPEP_IDLE_ENABLE,
  .fASPEP_cfg_recept = &UASPEP_CFG_RECEPTION,
  .fASPEP_cfg_trans = &UASPEP_CFG_TRANSMISSION,
  .liid = 0,
};

MCP_Handle_t MCP_Over_UartA =
{
  .pTransportLayer = (MCTL_Handle_t *)&aspepOverUartA, //cstat !MISRAC2012-Rule-11.3
};

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT 2024 STMicroelectronics *****END OF FILE****/