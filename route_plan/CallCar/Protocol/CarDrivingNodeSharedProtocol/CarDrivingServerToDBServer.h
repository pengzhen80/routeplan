#pragma once

#include "SharedProtocolCommonDefine.h"

//CarDriving server is client mongo DB server is server
enum eCarDrivingServerToDBServerMessage
{
	eCDSTDBSM_C2S_CREATE_NEW_CAR_REQUEST = 0,
	eCDSTDBSM_C2S_CREATE_NEW_CAR_RESULT,
	eCDSTDBSM_C2S_ADD_CAR_ROUTE_DATA_REQUEST,
	eCDSTDBSM_C2S_ADD_CAR_ROUTE_DATA_RESULT,

	eCDSTDBSM_MAX
};

