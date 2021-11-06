#pragma once
/*
************************************************************************************																					*
*  This helper file has several functions that are being repeated throughout		*
*  multiple programs. These include Int validation, Clearing console and buffers,	*
*  prompting for text from user, Random number generation and Formatting headers.	*
*																					*
*************************************************************************************
*/
namespace Helper
{
	 int GetValidatedInt(const char* strMessage, int nMinimumRange = 0, int nMaximumRange = 0);
	 void ClearBuffer();
	 void ClearConsole();
	 void ProgramHeaders(const char* programTitle);
	 void PromptForText(const char* prompt, char*& text);
	 int RandomNumberGen(int min, int max);
}