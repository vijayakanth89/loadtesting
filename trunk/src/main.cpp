//============================================================================
// Name        : HttpLoadTesting.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <pthread.h>
#include <ubac/HTTPRequest.h>

#include <ubac/UBACJson.h>
#include <ubac/IFHelper.h>
#include <ubac/YamlConfig.h>
using namespace std;
#include "RequestQueue.h"
#include "Requester.h"
#include "Constants.h"

//char FIELDS[][2]= {
//		{"0",""}
//};

vector<string> SymbolsList;

using namespace LOADTEST;

void genItem(string item_template, int limit, vector<string> &samplesList)
{
	char symbol[1000];
	while(limit--){
		sprintf(symbol, item_template.c_str(), limit+1);
		samplesList.push_back(symbol);
	}
}

void symbolGen(vector<string> & symbolsList)
{
	genItem("SYMBOL%02d", 20, symbolsList);
}

void watchlistGen(vector<string> &watchList){
	genItem("WATCH%d", 10, watchList);
}

string getRandomData(int field_id){
	int field_select = rand();
	char data[400];
	sprintf(data,FieldTemplates[field_id].c_str(), field_select%(randomLimits[field_id]));
	return data;
}


RequestQueue URLS_QUEUE;
string url;

static int total_requests;

YamlConfig *config;
int REQUEST_PERIOD = 2;




void* randomRequestGen(void *d)
{

	while(total_requests){
		cout << "random request gen.. " << endl;
		int service_select = rand()%6;
		string service = ServiceUrls[service_select];
		int enc_fields = ServiceFieldMap[service_select];


		stringstream sRequestStream;
		sRequestStream << (*config)["host"]  << service;

		while(enc_fields){
			cout << "service: " << service << endl;
			int field_id = enc_fields%10 - 1;
			cout << "field: " << Fields[field_id] << endl;
			string data = getRandomData(field_id);
			sRequestStream << Fields[field_id] << "=" << data << "&";
			enc_fields = enc_fields/10;
		}

		if(total_requests){
				URLS_QUEUE.addToQueue(sRequestStream.str());
				cout << "request: " << sRequestStream.str() << endl;
				total_requests--;
		}
		usleep(100);
	}
}


int main(int argc, char *argv[])
{
	char request[1000];
	config = new YamlConfig(argv[1]);
	url = (*config)["url"];
	total_requests = atoi((*config)["total_requests"].c_str());
	int thread_pool = atoi((*config)["thread_pool"].c_str());
	REQUEST_PERIOD = atoi((*config)["period"].c_str());

	pthread_t tid;
	pthread_create(&tid, NULL, randomRequestGen, NULL);

	LOADTEST::Requester *requester = new LOADTEST::Requester;

	vector<pthread_t> thread_ids;
	while(thread_pool){
		requester->start(NULL);// create a thread and requests
		thread_ids.push_back(requester->getThreadID());
		thread_pool--;
	}

	vector<pthread_t>::iterator iter_thread = thread_ids.begin();
	while(iter_thread!=thread_ids.end()){
		pthread_join(*iter_thread, NULL);
		iter_thread++;
	}

	pthread_join(tid, NULL);

	cout << "request delay..." << endl;
	vector<time_t>::iterator iter_time = requester->time_to_respond.begin();
	int k = 0;
	while(iter_time!=requester->time_to_respond.end())
	{
		cout << "i: " << k << ", time:" << *iter_time << endl;
		k++;
		iter_time++;
	}
	delete requester;
	delete config;
	return 0;
}
