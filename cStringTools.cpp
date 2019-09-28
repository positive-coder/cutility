#include "cStringTools.h"

bool strStrip(const char* inStr,int inStrLen,char* outStr,char stripChar)
{
	if(inStr == NULL || inStrLen <= 0 || outStr == NULL)
		return false;

	int outIndex = 0;
	for(int i = 0;i < inStrLen;i++)
	{
		if(inStr[i] != stripChar)
		{
			outStr[outIndex++] = inStr[i];
		}
	}
	outStr[outIndex++] = '\0';
	return true;
}