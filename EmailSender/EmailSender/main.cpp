#define _CRT_SECURE_NO_WARNINGS

#include "CSmtp.h"
#include <iostream>

extern "C" __declspec(dllexport) void __cdecl SendEmail(char **server, char** login, char** password, int* port, char** recipient,char** subject, char** body, char** attachPath, char** result);

void SendEmail(char **server, char** login, char** password, int* port, char** recipient,char** subject, char** body, char** attachPath, char** result)
{
	try
	{
		CSmtp mail;
		if ((*server != NULL) && (*server[0] != '\0')) mail.SetSMTPServer(*server, *port);
		else throw "SMTP server isn't set";
		if ((*login != NULL) && (*login[0] != '\0')) mail.SetLogin(*login);
		else throw "SMTP login isn't set";
		if ((*password != NULL) && (*password[0] != '\0')) mail.SetPassword(*password);
		else throw "SMTP login isn't set";
		mail.SetSenderName("REmailSender");
		if ((*login != NULL) && (*login[0] != '\0')) mail.SetSenderMail(*login);
		else throw "SMTP login isn't set";
		if ((*subject != NULL) && (*subject[0] != '\0')) mail.SetSubject(*subject);
		else throw "Subject isn't set";
		if ((*recipient != NULL) && (*recipient[0] != '\0')) mail.AddRecipient(*recipient);
		else throw "Recipient isn't set";
		mail.SetXPriority(XPRIORITY_NORMAL);
		if ((*body != NULL) && (*body[0] != '\0')) mail.AddMsgLine(*body);
		else throw "Body isn't set";
		char* token = strtok(*attachPath, ",");
		while(token != NULL)
		{
			if ((token[0] != '\0')) mail.AddAttachment(token);
			token = strtok(NULL, ",");
		}
		/*if ((*attachPath != NULL) && (*attachPath[0] != '\0')) mail.AddAttachment(*attachPath);*/
		mail.Send();
		*result = "Sending was successfull";
	}
	catch (ECSmtp e)
	{	
		*result = e.GetErrorText();
	}
	catch(char* str)
	{
		*result = str;
	}
}