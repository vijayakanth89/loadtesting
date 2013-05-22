/*
 * UBACRequest.cpp
 *
 *  Created on: 26-Apr-2013
 *      Author: vijayakanth
 */

#include "UBACRequest.h"

namespace LOADTEST {

UBACRequest::UBACRequest(int protocol, string params, string s_extmod) {

	this->extMod = s_extmod;
	this->params = params;
	this->protocol_id = protocol;

}

UBACRequest::~UBACRequest() {
	// TODO Auto-generated destructor stub
}


void UBACRequest::toString(string &response)
{
	stringstream res;
	res << this->protocol_id << " <" << this->params << this->extMod;
	response.clear();
	response.append(res.str());
}

} /* namespace LOADTEST */
