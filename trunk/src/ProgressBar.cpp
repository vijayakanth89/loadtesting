/*
 * ProgressBar.cpp
 *
 *  Created on: 08-Apr-2013
 *      Author: vijayakanth
 */

#include "ProgressBar.h"

void ProgressBar::print(){
	printf("Completed %f\%\r", this->progress_percent);
	fflush(stdout);
}

void ProgressBar::setProgress( float progress){
	this->progress_percent = progress;
}

ProgressBar::ProgressBar() {
	progress_percent = 0.0;
	// TODO Auto-generated constructor stub

}

ProgressBar::~ProgressBar() {
	// TODO Auto-generated destructor stub
}

