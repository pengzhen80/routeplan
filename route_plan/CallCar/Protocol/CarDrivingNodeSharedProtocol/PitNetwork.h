#pragma once

#include "SharedProtocolCommonDefine.h"
#include "StreamingDataReceiver.h"

#define	PIT_NETWORK_VERSION	20200519

enum ePitNetworkMessage
{
	ePNM_S2C_VERSION_CHECK_REQUEST = 200000,
	ePNM_C2S_VERSION_CHECK_RESULT,
	ePNM_S2C_PIT_CHARGE_REQUEST,
	ePNM_C2S_PIT_CHARGE_RESULT,
	ePNM_S2C_ASSIGN_PIT_ID_REQUEST,
	ePNM_C2S_ASSIGN_PIT_ID_RESULT,
	//
	ePNM_MAX
};

enum ePitNetworkResponseMessage
{
	ePNRM_OKAY = 0,
	ePNRM_VERSION_NOT_MATCH,
	ePNRM_MAX
};


LAZY_MESSAGE_HEADER_STAR(ePNM_S2C_VERSION_CHECK_REQUEST)
	int32 iVersion;//PIT_NETWORK_VERSION
LAZY_MESSAGE_HEADER_END(ePNM_S2C_VERSION_CHECK_REQUEST)

LAZY_RESULT_MESSAGE_HEADER_STAR(ePNM_C2S_VERSION_CHECK_RESULT)
	int32	iVersion;//PIT_NETWORK_VERSION
	int8	iPitID;
LAZY_RESULT_MESSAGE_HEADER_END(ePNM_C2S_VERSION_CHECK_RESULT)

LAZY_MESSAGE_HEADER_STAR(ePNM_S2C_PIT_CHARGE_REQUEST)
	int32 fChargeTime;
LAZY_MESSAGE_HEADER_END(ePNM_S2C_PIT_CHARGE_REQUEST)

LAZY_RESULT_MESSAGE_HEADER_STAR(ePNM_C2S_PIT_CHARGE_RESULT)
	//float fRestChargeTime;
LAZY_RESULT_MESSAGE_HEADER_END(ePNM_C2S_PIT_CHARGE_RESULT)



LAZY_MESSAGE_HEADER_STAR(ePNM_S2C_ASSIGN_PIT_ID_REQUEST)
	int iPitID;
LAZY_MESSAGE_HEADER_END(ePNM_S2C_ASSIGN_PIT_ID_REQUEST)

LAZY_RESULT_MESSAGE_HEADER_STAR(ePNM_C2S_ASSIGN_PIT_ID_RESULT)
	int iPitID;
LAZY_RESULT_MESSAGE_HEADER_END(ePNM_C2S_ASSIGN_PIT_ID_RESULT)