#pragma once
#include "SharedProtocolCommonDefine.h"

enum eCarDrivingTestAppProtocol
{
	eCDTAP_C2S_CREATE_NEW_DATA_REQUEST = 30000,//send to DB and Car Server
	eCDTAP_S2C_CREATE_NEW_DATA_RESULT,
	eCDTAP_MAX
};