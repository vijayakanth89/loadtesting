/*
 * RequestQueue.h
 *
 *  Created on: 06-May-2013
 *      Author: vijayakanth
 */

#ifndef REQUESTQUEUE_H_
#define REQUESTQUEUE_H_

#include <ubac/Mutex.h>
#include <iostream>
#include <queue>

using namespace std;

namespace LOADTEST {

class RequestQueue {
public:
	RequestQueue();
	virtual ~RequestQueue();
	Mutex qLocker;

	void addToQueue(string url){// add url to queue
		qLocker.lock();
		Requests.push(url);
		qLocker.unlock();
	}

	void Pop(string &url){
		this->qLocker.lock();
		if (Requests.empty()){
			cout << "queue is empty" << endl;
		} else {
			url = Requests.front();
			Requests.pop();
		}
		this->qLocker.unlock();
	}

	size_t getQueueSize(){
		this->qLocker.lock();
		size_t res = this->Requests.size();
		this->qLocker.unlock();
		return res;
	}
	queue<string> Requests;

};

} /* namespace LOADTEST */
#endif /* REQUESTQUEUE_H_ */
