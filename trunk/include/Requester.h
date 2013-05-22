/*
 * Requester.h
 *
 *  Created on: 26-Apr-2013
 *      Author: vijayakanth
 */

#ifndef REQUESTER_H_
#define REQUESTER_H_

#include <iostream>
#include <ubac/Thread.h>
#include <ubac/HTTPRequest.h>
#include "RequestQueue.h"
#include "ubac/UBACJson.h"
#include "ProgressBar.h"
namespace LOADTEST {

class Requester :
	public Thread {
public:
	Requester();
	virtual ~Requester();

	void run();
	void monitor_queue();
	int id;

	vector<time_t> time_to_respond;
	Mutex timeArrayLock;
};

} /* namespace LOADTEST */
extern LOADTEST::RequestQueue URLS_QUEUE;
extern int REQUEST_PERIOD;
#endif /* REQUESTER_H_ */
