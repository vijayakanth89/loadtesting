/*
 * Constants.h
 *
 *  Created on: 22-May-2013
 *      Author: vijayakanth
 */

#ifndef CONSTANTS_H_
#define CONSTANTS_H_

string ServiceUrls[] = {
		"/getwatchlists?",// 0
		"/addwatchlist?",//1
		"/deletewatchlist?",//2
		"/getsymbols?",//3
		"/addsymbol?",//4
		"/deletesymbol?"//5
};

const int ServiceFieldMap[] = {
		1,
		13,
		12,
		12,
		124,
		124
};

string Fields[] = {
		"account_id",
		"watchlist_id",
		"name",
		"symbol"
};

const int randomLimits[] = {
		50000,
		20,
		20,
		20
};

string FieldTemplates[] = {
		"AC_%05d",
		"%d",
		"WAT_%03d",
		"SYM_%03d"
};

const int SERVICE_GETWATCH = 0;// can be used to randomize the service..
const int SERVICE_ADDWATCH = 1;
const int SERVICE_DELETEWATCH = 2;
const int SERVICE_GETSYMBOL = 3;
const int SERVICE_ADDSYMBOL = 4;
const int SERVICE_DELETESYMBOL = 5;

const int FIELD_ACCOUNTID = 0;// can be used to map the random data with field..
const int FIELD_WATCHLISTID = 1;
const int FIELD_NAME = 2;
const int FIELD_SYMBOL = 3;

#endif /* CONSTANTS_H_ */
