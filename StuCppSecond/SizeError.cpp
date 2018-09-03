#define _CRT_SECURE_NO_WARNINGS
#include "SizeError.h"
#include <iostream>
#include <string.h>



SizeError::SizeError(char *p)//:exception(p)
{
	if (p == NULL)
	{
		return;
	}
	int len = strlen(p) + 1;
	this->p = new char[len];
	strcpy(this->p, p);
}


SizeError::~SizeError()
{
}
