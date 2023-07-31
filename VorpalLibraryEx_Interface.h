/**
* Copyright (C) 2023 Vorpal. All rights reserved.
*
* Licensed under the MIT License. You may obtain a copy
* in the file "LICENSE" found at the root of this repository.
*/

ifndef VORPALLIBRARYEX_INTERFACE_H_
#define VORPALLIBRARYEX_INTERFACE_H_

#define VORPAL_API   __declspec( dllimport )


//Forward declarations
struct VorpalClient;

//Structs used when dealing with VorpalProc(edure)s
union ProcArg {
	int arg_i;
	unsigned long long arg_ull;
	float arg_f;
	char arg_s[VORPAL_PROC_STR_MAX_CHAR_COUNT];
};

struct ProcArgs {
	ProcArg args[VORPAL_PROC_MAX_ARGS] = {};
};

struct Proc {
	unsigned int proc{};
	ProcArgs args{};

	VORPAL_STATUS status = VORPAL_STATUS::NONE;
};

//Structs used when dealing with ReadOnly fields and ProtectedData
struct ReadOnlyData {
	unsigned long long data;
	unsigned long long size;

	VORPAL_STATUS status;
	unsigned long long wantedSize;
};

//Structs used by the Vorpal Client
struct Protected_Application {
	//ReadOnlyData Error;
	ReadOnlyData/*bool*/ Result;
	//unsigned long long Time;

	ReadOnlyData Name;
	ReadOnlyData Domain;
	ReadOnlyData Version;
	ReadOnlyData Login;
	ReadOnlyData Key;

	ReadOnlyData HWID;
	ReadOnlyData Maintenance;
	ReadOnlyData Developer;
	ReadOnlyData AntiDebug;
	ReadOnlyData AntiVM;
};

struct Protected_LoginApplication {
	//ReadOnlyData Error;
	ReadOnlyData Result;
	//unsigned long long Time;

	ReadOnlyData HashedID;
	ReadOnlyData Username;
	ReadOnlyData Email;
	ReadOnlyData Status;
	ReadOnlyData Rank;
	ReadOnlyData Key;
	ReadOnlyData HWID;
	//unsigned long long Expiry;
};

struct LicenseKey {
	char AppId[VORPAL_APPID_MAX_CHAR_COUNT];
	char ApplicationName[VORPAL_APPLICATION_NAME_MAX_CHAR_COUNT];
	char License[VORPAL_LICENSE_STR_MAX_CHAR_COUNT];
	unsigned long long ExpiryDays;
	unsigned long long ExpiryDate;
	int status;
	char HWID[VORPAL_HWID_MAX_CHAR_COUNT];
};

struct Protected_Login {
	ReadOnlyData  HashedID;
	ReadOnlyData  Username;
	ReadOnlyData  Email;
	ReadOnlyData  Status;
	ReadOnlyData Rank;

	//Non Protected
	LicenseKey Keys[VORPAL_MAX_LICENSEKEYS]; unsigned long long KeyAmount;
};


struct VorpalClient { //Vorpalclient represents the data that the client has, this data is linked to their Vorpal (classPtr) instance
	Protected_Application app; unsigned long long app_size;
	Protected_LoginApplication loginApp; unsigned long long loginApp_size;
	Protected_Login login; unsigned long long login_size;

	ReadOnlyData currentVar;
	ReadOnlyData currentFile;

	Proc vorpalProcs[VORPAL_MAX_PROCS] = { {{}} };
	Proc vorpalProcs2[VORPAL_MAX_PROCS] = { {{}} };
};

#endif