/* File: ui.cpp
 * Author: CRE
 * Last Edited: Thu Dec 22 16:12:25 2016
 */

#include "ui.h"
#include <stdarg.h>
using namespace std;
using namespace cre;

ui::ui()
	:TheHelp(),WrongInput(false), Exit(false), NeedHelp(false)
{
}

ui::~ui()
{
}

void ui::set(int Count, char ** Args)
{
	int i=1;
	if (Count<=1)
	{
		defaults();
	}
	while(i<Count)
	{
		i+=analyze(Count-i, Args+i);
		if (WrongInput)
		{
			NeedHelp=true;
			Exit=true;
			WrongInput=false;
			break;
		}
		if (i>Count||i<0)
		{
			NeedHelp=true;
			Exit=true;
		}
	}
}

void ui::defaults()
{
	needHelp();
	exit();
}

void ui::wrongInput()
{
	WrongInput=true;
}

void ui::needHelp()
{
	NeedHelp=true;
}

void ui::exit()
{
	Exit=true;
}

void ui::between()
{
}

int ui::analyze(int Count, char ** Args)
{
	NeedHelp=true;
	return Count;
}

int ui::run(int Count, char ** Args)
{
	set(Count, Args);
	between();
	return execute();
}

void ui::setHelp(const char * Format, ...)
{
	va_start(TheHelp.Args, Format);
	TheHelp.Format=Format;
}

void ui::printHelp()
{
	fprintf(stderr, TheHelp.Format.c_str(), TheHelp.Args);
}

int ui::execute()
{
	if (NeedHelp) printHelp();
	if (Exit) return 1;
	for (auto f:ToBeExecuted)
	{
		f();
	}
	return 0;
}
