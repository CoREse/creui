/* File: test.cpp
 * Author: CRE
 * Last Edited: Wed Dec 21 18:42:39 2016
 */

#include "ui.h"
#include <iostream>
#include <string.h>
using namespace std;
using namespace cre;


void helloWorld(const char * Name)
{
	printf("Hello! %s", Name);
}

class MyUI: public ui
{
	public:
		virtual int analyze (int Count, char ** Args) override
		{
			fprintf(stderr,"I am in!, Count:%d, Args[0]:%s", Count, Args[0]);
			if (Count<1)
			{
				wrongInput();
				return 0;
			}
			if (strcmp(Args[0], "help")==0)
			{
				needHelp();
				return 1;
			}
			else if (strcmp(Args[0],"Hello")==0)
			{
				fprintf(stderr,"I am here!");
				//addExecutable(helloWorld, "ME!");
				ToBeExecuted.push_back(bind(helloWorld, "ME!"));
				return 1;
			}
			needHelp();
			return Count;
		}
};

int main (int argc, char ** args)
{
	MyUI TheUI;
	TheUI.setHelp("Help!");
	return TheUI.run(argc,args);
}
