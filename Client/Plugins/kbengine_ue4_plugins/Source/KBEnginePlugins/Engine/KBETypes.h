/*
	Generated by KBEngine!
	Please do not modify this file!
	tools = kbcmd
*/

#pragma once

#include "KBECommon.h"

namespace KBEngine
{


// defined in */scripts/entity_defs/types.xml

typedef uint8 UINT8;

typedef uint16 UINT16;

typedef uint64 UINT64;

typedef uint32 UINT32;

typedef int8 INT8;

typedef int16 INT16;

typedef int32 INT32;

typedef int64 INT64;

typedef FString STRING;

typedef FString KBE_UNICODE;

typedef float FLOAT;

typedef double DOUBLE;

typedef TArray<uint8> PYTHON;

typedef TArray<uint8> PY_DICT;

typedef TArray<uint8> PY_TUPLE;

typedef TArray<uint8> PY_LIST;

typedef TArray<uint8> ENTITYCALL;

typedef TArray<uint8> BLOB;

typedef FVector2D VECTOR2;

typedef FVector VECTOR3;

typedef FVector4 VECTOR4;

typedef int32 OBJECT_ID;

typedef uint8 BOOL;

typedef int32 CONTROLLER_ID;

typedef int32 EXPERIENCE;

typedef int32 ITEM_ID;

typedef int32 SKILLID;

typedef int32 QUESTID;

typedef uint64 DBID;

typedef uint64 UID;

typedef TArray<uint8> UID1;

typedef int32 ENTITY_ID;

typedef uint32 ENTITY_NO;

typedef uint32 SPACE_ID;

typedef FVector POSITION3D;

typedef FVector DIRECTION3D;

typedef uint32 ENTITY_UTYPE;

typedef int32 DAMAGE_TYPE;

typedef int32 ENMITY;

typedef int32 HP;

typedef int32 MP;

typedef int8 ENTITY_STATE;

typedef uint8 ENTITY_SUBSTATE;

typedef int32 ENTITY_FORBIDS;

class KBENGINEPLUGINS_API ENTITY_FORBID_COUNTER : public TArray<int8>
{
public:

	ENTITY_FORBID_COUNTER()
	{
	}

};

class KBENGINEPLUGINS_API ENTITYID_LIST : public TArray<int32>
{
public:

	ENTITYID_LIST()
	{
	}

};

class KBENGINEPLUGINS_API AVATAR_DATA
{
public:
	int8 param1;
	TArray<uint8> param2;

	AVATAR_DATA():
	param1(0),
	param2()
	{
	}

};

class KBENGINEPLUGINS_API AVATAR_INFOS
{
public:
	uint64 dbid;
	FString name;
	uint8 roleType;
	uint16 level;
	AVATAR_DATA data;

	AVATAR_INFOS():
	dbid(0),
	name(),
	roleType(0),
	level(0),
	data()
	{
	}

};

class KBENGINEPLUGINS_API AVATAR_INFOS_LIST
{
public:
	TArray<AVATAR_INFOS> values;

	AVATAR_INFOS_LIST():
	values()
	{
	}

};

class KBENGINEPLUGINS_API BAG
{
public:
	TArray<TArray<int64>> values22;

	BAG():
	values22()
	{
	}

};

class KBENGINEPLUGINS_API EXAMPLES
{
public:
	int64 k1;
	int64 k2;

	EXAMPLES():
	k1(0),
	k2(0)
	{
	}

};


}