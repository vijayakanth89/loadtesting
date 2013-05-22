/*
 * UBACRequest.h
 *
 *  Created on: 26-Apr-2013
 *      Author: vijayakanth
 */

#ifndef UBACREQUEST_H_
#define UBACREQUEST_H_


#include <iostream>
#include <sstream>

using namespace std;

namespace LOADTEST {

class UBACRequest {
public:
	UBACRequest(int protocol, string params, string s_extmod);
	virtual ~UBACRequest();

	string extMod;
	int protocol_id;
	string params;

	void toString(string &request);

};

} /* namespace LOADTEST */
#endif /* UBACREQUEST_H_ */
