/* 
 * File:   main.cpp
 * Author: m1cha
 *
 * Created on April 25, 2012, 8:08 PM
 */

#include <cstdlib>
#include <stdio.h>

#include "UiMain.h"
#include "Activity.h"
#include "View.h"

using namespace TouchUi;

/*
 * 
 */
int main(int argc, char** argv) {
	UiMain gui;
	Activity activity;
	View view;

	activity.addView(&view);
	gui.addActivity(&activity);
	printf("Exit-Code: %d\n", gui.start());fflush(stdout);

	return EXIT_SUCCESS;
}



