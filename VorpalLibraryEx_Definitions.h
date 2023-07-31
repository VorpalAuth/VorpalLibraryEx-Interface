/**
* Copyright (C) 2023 Vorpal. All rights reserved.
*
* Licensed under the MIT License. You may obtain a copy
* in the file "LICENSE" found at the root of this repository.
*/

#ifndef VORPALLIBRARYEX_DEFINITIONS_H_
#define VORPALLIBRARYEX_DEFINITIONS_H_

//Configuration
#define VORPAL_DEFAULT_STR_CHAR_COUNT 64

//DO NOT TOUCH
#define VORPAL_API_VERSION 4

#define VORPAL_MAX_PROCS 16
#define VORPAL_PROC_MAX_ARGS 10
#define VORPAL_PROC_STR_MAX_CHAR_COUNT 25

#define VORPAL_MAX_LICENSEKEYS 256

#define VORPAL_HWID_MAX_CHAR_COUNT 256
#define VORPAL_APPID_MAX_CHAR_COUNT 64
#define VORPAL_APPLICATION_NAME_MAX_CHAR_COUNT 64
#define VORPAL_LICENSE_STR_MAX_CHAR_COUNT 64


//Status/Error enum definitions
enum VORPAL_STATUS {
	NONE = 0x00u,

	//Good statuses, proceed no problems
	MIN_GOOD = 0xA00u,
	OK = 0xA01u,
	DONE = 0xA02u,
	MAX_GOOD = 0xAFFu,

	//Neutral
	MIN_NEUTRAL = 0xB00u,
	WAITING = 0xB01u,
	BUSY = 0xB02u,

	MAX_NEUTRAL = 0xBFFu,

	//Errors
	MIN_ERROR = 0xF00u,
	NOT_ENOUGH_MEMORY = 0xF01u, //Allocate more memory for us please
	NOT_INITIALIZED = 0xF02u, //You probably forgot to initialize/allocate something
	FULL = 0xF03u,
	TIMED_OUT = 0xF04u,
	BAD_DATA = 0xF05u,
	API_MISMATCH = 0xF06u,
	MAX_ERROR = 0xFFFu,
};


#endif //VORPALLIBRARYEX_DEFINITIONS_H_