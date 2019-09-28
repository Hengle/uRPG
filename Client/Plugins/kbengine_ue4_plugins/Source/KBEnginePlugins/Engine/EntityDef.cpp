#include "EntityDef.h"
#include "DataTypes.h"
#include "CustomDataTypes.h"
#include "ScriptModule.h"
#include "Property.h"
#include "Method.h"
#include "KBVar.h"
#include "Entity.h"

#include "Scripts/Account.h"
#include "Scripts/FirstEntity.h"

namespace KBEngine
{

TMap<FString, uint16> EntityDef::datatype2id;
TMap<FString, DATATYPE_BASE*> EntityDef::datatypes;
TMap<uint16, DATATYPE_BASE*> EntityDef::id2datatypes;
TMap<FString, int32> EntityDef::entityclass;
TMap<FString, ScriptModule*> EntityDef::moduledefs;
TMap<uint16, ScriptModule*> EntityDef::idmoduledefs;

bool EntityDef::initialize()
{
	initDataTypes();
	initDefTypes();
	initScriptModules();
	return true;
}

bool EntityDef::reset()
{
	clear();
	return initialize();
}

void EntityDef::clear()
{
	TArray<DATATYPE_BASE*> deleted_datatypes;
	for (auto& item : EntityDef::datatypes)
	{
		int32 idx = deleted_datatypes.Find(item.Value);
		if (idx != INDEX_NONE)
			continue;

		deleted_datatypes.Add(item.Value);
		delete item.Value;
	}

	for (auto& item : EntityDef::moduledefs)
		delete item.Value;

	datatype2id.Empty();
	datatypes.Empty();
	id2datatypes.Empty();
	entityclass.Empty();
	moduledefs.Empty();
	idmoduledefs.Empty();
}

void EntityDef::initDataTypes()
{
	datatypes.Add(TEXT("UINT8"), new DATATYPE_UINT8());
	datatypes.Add(TEXT("UINT16"), new DATATYPE_UINT16());
	datatypes.Add(TEXT("UINT32"), new DATATYPE_UINT32());
	datatypes.Add(TEXT("UINT64"), new DATATYPE_UINT64());

	datatypes.Add(TEXT("INT8"), new DATATYPE_INT8());
	datatypes.Add(TEXT("INT16"), new DATATYPE_INT16());
	datatypes.Add(TEXT("INT32"), new DATATYPE_INT32());
	datatypes.Add(TEXT("INT64"), new DATATYPE_INT64());

	datatypes.Add(TEXT("FLOAT"), new DATATYPE_FLOAT());
	datatypes.Add(TEXT("DOUBLE"), new DATATYPE_DOUBLE());

	datatypes.Add(TEXT("STRING"), new DATATYPE_STRING());
	datatypes.Add(TEXT("VECTOR2"), new DATATYPE_VECTOR2());

	datatypes.Add(TEXT("VECTOR3"), new DATATYPE_VECTOR3());

	datatypes.Add(TEXT("VECTOR4"), new DATATYPE_VECTOR4());
	datatypes.Add(TEXT("PYTHON"), new DATATYPE_PYTHON());

	datatypes.Add(TEXT("UNICODE"), new DATATYPE_UNICODE());
	datatypes.Add(TEXT("ENTITYCALL"), new DATATYPE_ENTITYCALL());

	datatypes.Add(TEXT("BLOB"), new DATATYPE_BLOB());
}

Entity* EntityDef::createEntity(int utype)
{
	Entity* pEntity = NULL;

	switch(utype)
	{
		case 1:
			pEntity = new Account();
			break;
		case 2:
			pEntity = new FirstEntity();
			break;
		default:
			SCREEN_ERROR_MSG("EntityDef::createEntity() : entity(%d) not found!", utype);
			break;
	};

	return pEntity;
}

void EntityDef::initScriptModules()
{
	ScriptModule* pAccountModule = new ScriptModule("Account", 1);
	EntityDef::moduledefs.Add(TEXT("Account"), pAccountModule);
	EntityDef::idmoduledefs.Add(1, pAccountModule);

	Property* pAccount_position = new Property();
	pAccount_position->name = TEXT("position");
	pAccount_position->properUtype = 40000;
	pAccount_position->properFlags = 4;
	pAccount_position->aliasID = 1;
	KBVar* pAccount_position_defval = new KBVar(FVector());
	pAccount_position->pDefaultVal = pAccount_position_defval;
	pAccountModule->propertys.Add(TEXT("position"), pAccount_position); 

	pAccountModule->usePropertyDescrAlias = true;
	pAccountModule->idpropertys.Add((uint16)pAccount_position->aliasID, pAccount_position);

	//DEBUG_MSG("EntityDef::initScriptModules: add(Account), property(position / 40000).");

	Property* pAccount_direction = new Property();
	pAccount_direction->name = TEXT("direction");
	pAccount_direction->properUtype = 40001;
	pAccount_direction->properFlags = 4;
	pAccount_direction->aliasID = 2;
	KBVar* pAccount_direction_defval = new KBVar(FVector());
	pAccount_direction->pDefaultVal = pAccount_direction_defval;
	pAccountModule->propertys.Add(TEXT("direction"), pAccount_direction); 

	pAccountModule->usePropertyDescrAlias = true;
	pAccountModule->idpropertys.Add((uint16)pAccount_direction->aliasID, pAccount_direction);

	//DEBUG_MSG("EntityDef::initScriptModules: add(Account), property(direction / 40001).");

	Property* pAccount_spaceID = new Property();
	pAccount_spaceID->name = TEXT("spaceID");
	pAccount_spaceID->properUtype = 40002;
	pAccount_spaceID->properFlags = 16;
	pAccount_spaceID->aliasID = 3;
	KBVar* pAccount_spaceID_defval = new KBVar((uint32)FCString::Atoi64(TEXT("")));
	pAccount_spaceID->pDefaultVal = pAccount_spaceID_defval;
	pAccountModule->propertys.Add(TEXT("spaceID"), pAccount_spaceID); 

	pAccountModule->usePropertyDescrAlias = true;
	pAccountModule->idpropertys.Add((uint16)pAccount_spaceID->aliasID, pAccount_spaceID);

	//DEBUG_MSG("EntityDef::initScriptModules: add(Account), property(spaceID / 40002).");

	pAccountModule->useMethodDescrAlias = true;
	ScriptModule* pFirstEntityModule = new ScriptModule("FirstEntity", 2);
	EntityDef::moduledefs.Add(TEXT("FirstEntity"), pFirstEntityModule);
	EntityDef::idmoduledefs.Add(2, pFirstEntityModule);

	Property* pFirstEntity_position = new Property();
	pFirstEntity_position->name = TEXT("position");
	pFirstEntity_position->properUtype = 40000;
	pFirstEntity_position->properFlags = 4;
	pFirstEntity_position->aliasID = 1;
	KBVar* pFirstEntity_position_defval = new KBVar(FVector());
	pFirstEntity_position->pDefaultVal = pFirstEntity_position_defval;
	pFirstEntityModule->propertys.Add(TEXT("position"), pFirstEntity_position); 

	pFirstEntityModule->usePropertyDescrAlias = true;
	pFirstEntityModule->idpropertys.Add((uint16)pFirstEntity_position->aliasID, pFirstEntity_position);

	//DEBUG_MSG("EntityDef::initScriptModules: add(FirstEntity), property(position / 40000).");

	Property* pFirstEntity_direction = new Property();
	pFirstEntity_direction->name = TEXT("direction");
	pFirstEntity_direction->properUtype = 40001;
	pFirstEntity_direction->properFlags = 4;
	pFirstEntity_direction->aliasID = 2;
	KBVar* pFirstEntity_direction_defval = new KBVar(FVector());
	pFirstEntity_direction->pDefaultVal = pFirstEntity_direction_defval;
	pFirstEntityModule->propertys.Add(TEXT("direction"), pFirstEntity_direction); 

	pFirstEntityModule->usePropertyDescrAlias = true;
	pFirstEntityModule->idpropertys.Add((uint16)pFirstEntity_direction->aliasID, pFirstEntity_direction);

	//DEBUG_MSG("EntityDef::initScriptModules: add(FirstEntity), property(direction / 40001).");

	Property* pFirstEntity_spaceID = new Property();
	pFirstEntity_spaceID->name = TEXT("spaceID");
	pFirstEntity_spaceID->properUtype = 40002;
	pFirstEntity_spaceID->properFlags = 16;
	pFirstEntity_spaceID->aliasID = 3;
	KBVar* pFirstEntity_spaceID_defval = new KBVar((uint32)FCString::Atoi64(TEXT("")));
	pFirstEntity_spaceID->pDefaultVal = pFirstEntity_spaceID_defval;
	pFirstEntityModule->propertys.Add(TEXT("spaceID"), pFirstEntity_spaceID); 

	pFirstEntityModule->usePropertyDescrAlias = true;
	pFirstEntityModule->idpropertys.Add((uint16)pFirstEntity_spaceID->aliasID, pFirstEntity_spaceID);

	//DEBUG_MSG("EntityDef::initScriptModules: add(FirstEntity), property(spaceID / 40002).");

	TArray<DATATYPE_BASE*> FirstEntity_OnEnter_args;

	Method* pFirstEntity_OnEnter = new Method();
	pFirstEntity_OnEnter->name = TEXT("OnEnter");
	pFirstEntity_OnEnter->methodUtype = 2;
	pFirstEntity_OnEnter->aliasID = 1;
	pFirstEntity_OnEnter->args = FirstEntity_OnEnter_args;

	pFirstEntityModule->methods.Add(TEXT("OnEnter"), pFirstEntity_OnEnter); 
	pFirstEntityModule->useMethodDescrAlias = true;
	pFirstEntityModule->idmethods.Add((uint16)pFirstEntity_OnEnter->aliasID, pFirstEntity_OnEnter);

	//DEBUG_MSG("EntityDef::initScriptModules: add(FirstEntity), method(OnEnter / 2).");

	TArray<DATATYPE_BASE*> FirstEntity_OnSay_args;
	FirstEntity_OnSay_args.Add(EntityDef::id2datatypes[12]);

	Method* pFirstEntity_OnSay = new Method();
	pFirstEntity_OnSay->name = TEXT("OnSay");
	pFirstEntity_OnSay->methodUtype = 3;
	pFirstEntity_OnSay->aliasID = 2;
	pFirstEntity_OnSay->args = FirstEntity_OnSay_args;

	pFirstEntityModule->methods.Add(TEXT("OnSay"), pFirstEntity_OnSay); 
	pFirstEntityModule->useMethodDescrAlias = true;
	pFirstEntityModule->idmethods.Add((uint16)pFirstEntity_OnSay->aliasID, pFirstEntity_OnSay);

	//DEBUG_MSG("EntityDef::initScriptModules: add(FirstEntity), method(OnSay / 3).");

	TArray<DATATYPE_BASE*> FirstEntity_say_args;
	FirstEntity_say_args.Add(EntityDef::id2datatypes[12]);

	Method* pFirstEntity_say = new Method();
	pFirstEntity_say->name = TEXT("say");
	pFirstEntity_say->methodUtype = 1;
	pFirstEntity_say->aliasID = -1;
	pFirstEntity_say->args = FirstEntity_say_args;

	pFirstEntityModule->methods.Add(TEXT("say"), pFirstEntity_say); 
	pFirstEntityModule->cell_methods.Add(TEXT("say"), pFirstEntity_say);

	pFirstEntityModule->idcell_methods.Add(pFirstEntity_say->methodUtype, pFirstEntity_say);

	//DEBUG_MSG("EntityDef::initScriptModules: add(FirstEntity), method(say / 1).");

}

void EntityDef::initDefTypes()
{
	{
		uint16 utype = 2;
		FString typeName = TEXT("UINT8");
		FString name = TEXT("UINT8");
		DATATYPE_BASE** fPtr = EntityDef::datatypes.Find(name);
		DATATYPE_BASE* pVal = fPtr != NULL ? *fPtr : NULL;
		EntityDef::datatypes.Add(typeName, pVal);
		EntityDef::id2datatypes.Add(utype, EntityDef::datatypes[typeName]);
		EntityDef::datatype2id.Add(typeName, utype);
	}

	{
		uint16 utype = 3;
		FString typeName = TEXT("UINT16");
		FString name = TEXT("UINT16");
		DATATYPE_BASE** fPtr = EntityDef::datatypes.Find(name);
		DATATYPE_BASE* pVal = fPtr != NULL ? *fPtr : NULL;
		EntityDef::datatypes.Add(typeName, pVal);
		EntityDef::id2datatypes.Add(utype, EntityDef::datatypes[typeName]);
		EntityDef::datatype2id.Add(typeName, utype);
	}

	{
		uint16 utype = 5;
		FString typeName = TEXT("UINT64");
		FString name = TEXT("UINT64");
		DATATYPE_BASE** fPtr = EntityDef::datatypes.Find(name);
		DATATYPE_BASE* pVal = fPtr != NULL ? *fPtr : NULL;
		EntityDef::datatypes.Add(typeName, pVal);
		EntityDef::id2datatypes.Add(utype, EntityDef::datatypes[typeName]);
		EntityDef::datatype2id.Add(typeName, utype);
	}

	{
		uint16 utype = 4;
		FString typeName = TEXT("UINT32");
		FString name = TEXT("UINT32");
		DATATYPE_BASE** fPtr = EntityDef::datatypes.Find(name);
		DATATYPE_BASE* pVal = fPtr != NULL ? *fPtr : NULL;
		EntityDef::datatypes.Add(typeName, pVal);
		EntityDef::id2datatypes.Add(utype, EntityDef::datatypes[typeName]);
		EntityDef::datatype2id.Add(typeName, utype);
	}

	{
		uint16 utype = 6;
		FString typeName = TEXT("INT8");
		FString name = TEXT("INT8");
		DATATYPE_BASE** fPtr = EntityDef::datatypes.Find(name);
		DATATYPE_BASE* pVal = fPtr != NULL ? *fPtr : NULL;
		EntityDef::datatypes.Add(typeName, pVal);
		EntityDef::id2datatypes.Add(utype, EntityDef::datatypes[typeName]);
		EntityDef::datatype2id.Add(typeName, utype);
	}

	{
		uint16 utype = 7;
		FString typeName = TEXT("INT16");
		FString name = TEXT("INT16");
		DATATYPE_BASE** fPtr = EntityDef::datatypes.Find(name);
		DATATYPE_BASE* pVal = fPtr != NULL ? *fPtr : NULL;
		EntityDef::datatypes.Add(typeName, pVal);
		EntityDef::id2datatypes.Add(utype, EntityDef::datatypes[typeName]);
		EntityDef::datatype2id.Add(typeName, utype);
	}

	{
		uint16 utype = 8;
		FString typeName = TEXT("INT32");
		FString name = TEXT("INT32");
		DATATYPE_BASE** fPtr = EntityDef::datatypes.Find(name);
		DATATYPE_BASE* pVal = fPtr != NULL ? *fPtr : NULL;
		EntityDef::datatypes.Add(typeName, pVal);
		EntityDef::id2datatypes.Add(utype, EntityDef::datatypes[typeName]);
		EntityDef::datatype2id.Add(typeName, utype);
	}

	{
		uint16 utype = 9;
		FString typeName = TEXT("INT64");
		FString name = TEXT("INT64");
		DATATYPE_BASE** fPtr = EntityDef::datatypes.Find(name);
		DATATYPE_BASE* pVal = fPtr != NULL ? *fPtr : NULL;
		EntityDef::datatypes.Add(typeName, pVal);
		EntityDef::id2datatypes.Add(utype, EntityDef::datatypes[typeName]);
		EntityDef::datatype2id.Add(typeName, utype);
	}

	{
		uint16 utype = 1;
		FString typeName = TEXT("STRING");
		FString name = TEXT("STRING");
		DATATYPE_BASE** fPtr = EntityDef::datatypes.Find(name);
		DATATYPE_BASE* pVal = fPtr != NULL ? *fPtr : NULL;
		EntityDef::datatypes.Add(typeName, pVal);
		EntityDef::id2datatypes.Add(utype, EntityDef::datatypes[typeName]);
		EntityDef::datatype2id.Add(typeName, utype);
	}

	{
		uint16 utype = 12;
		FString typeName = TEXT("UNICODE");
		FString name = TEXT("UNICODE");
		DATATYPE_BASE** fPtr = EntityDef::datatypes.Find(name);
		DATATYPE_BASE* pVal = fPtr != NULL ? *fPtr : NULL;
		EntityDef::datatypes.Add(typeName, pVal);
		EntityDef::id2datatypes.Add(utype, EntityDef::datatypes[typeName]);
		EntityDef::datatype2id.Add(typeName, utype);
	}

	{
		uint16 utype = 13;
		FString typeName = TEXT("FLOAT");
		FString name = TEXT("FLOAT");
		DATATYPE_BASE** fPtr = EntityDef::datatypes.Find(name);
		DATATYPE_BASE* pVal = fPtr != NULL ? *fPtr : NULL;
		EntityDef::datatypes.Add(typeName, pVal);
		EntityDef::id2datatypes.Add(utype, EntityDef::datatypes[typeName]);
		EntityDef::datatype2id.Add(typeName, utype);
	}

	{
		uint16 utype = 14;
		FString typeName = TEXT("DOUBLE");
		FString name = TEXT("DOUBLE");
		DATATYPE_BASE** fPtr = EntityDef::datatypes.Find(name);
		DATATYPE_BASE* pVal = fPtr != NULL ? *fPtr : NULL;
		EntityDef::datatypes.Add(typeName, pVal);
		EntityDef::id2datatypes.Add(utype, EntityDef::datatypes[typeName]);
		EntityDef::datatype2id.Add(typeName, utype);
	}

	{
		uint16 utype = 10;
		FString typeName = TEXT("PYTHON");
		FString name = TEXT("PYTHON");
		DATATYPE_BASE** fPtr = EntityDef::datatypes.Find(name);
		DATATYPE_BASE* pVal = fPtr != NULL ? *fPtr : NULL;
		EntityDef::datatypes.Add(typeName, pVal);
		EntityDef::id2datatypes.Add(utype, EntityDef::datatypes[typeName]);
		EntityDef::datatype2id.Add(typeName, utype);
	}

	{
		uint16 utype = 10;
		FString typeName = TEXT("PY_DICT");
		FString name = TEXT("PY_DICT");
		DATATYPE_BASE** fPtr = EntityDef::datatypes.Find(name);
		DATATYPE_BASE* pVal = fPtr != NULL ? *fPtr : NULL;
		EntityDef::datatypes.Add(typeName, pVal);
		EntityDef::id2datatypes.Add(utype, EntityDef::datatypes[typeName]);
		EntityDef::datatype2id.Add(typeName, utype);
	}

	{
		uint16 utype = 10;
		FString typeName = TEXT("PY_TUPLE");
		FString name = TEXT("PY_TUPLE");
		DATATYPE_BASE** fPtr = EntityDef::datatypes.Find(name);
		DATATYPE_BASE* pVal = fPtr != NULL ? *fPtr : NULL;
		EntityDef::datatypes.Add(typeName, pVal);
		EntityDef::id2datatypes.Add(utype, EntityDef::datatypes[typeName]);
		EntityDef::datatype2id.Add(typeName, utype);
	}

	{
		uint16 utype = 10;
		FString typeName = TEXT("PY_LIST");
		FString name = TEXT("PY_LIST");
		DATATYPE_BASE** fPtr = EntityDef::datatypes.Find(name);
		DATATYPE_BASE* pVal = fPtr != NULL ? *fPtr : NULL;
		EntityDef::datatypes.Add(typeName, pVal);
		EntityDef::id2datatypes.Add(utype, EntityDef::datatypes[typeName]);
		EntityDef::datatype2id.Add(typeName, utype);
	}

	{
		uint16 utype = 20;
		FString typeName = TEXT("ENTITYCALL");
		FString name = TEXT("ENTITYCALL");
		DATATYPE_BASE** fPtr = EntityDef::datatypes.Find(name);
		DATATYPE_BASE* pVal = fPtr != NULL ? *fPtr : NULL;
		EntityDef::datatypes.Add(typeName, pVal);
		EntityDef::id2datatypes.Add(utype, EntityDef::datatypes[typeName]);
		EntityDef::datatype2id.Add(typeName, utype);
	}

	{
		uint16 utype = 11;
		FString typeName = TEXT("BLOB");
		FString name = TEXT("BLOB");
		DATATYPE_BASE** fPtr = EntityDef::datatypes.Find(name);
		DATATYPE_BASE* pVal = fPtr != NULL ? *fPtr : NULL;
		EntityDef::datatypes.Add(typeName, pVal);
		EntityDef::id2datatypes.Add(utype, EntityDef::datatypes[typeName]);
		EntityDef::datatype2id.Add(typeName, utype);
	}

	{
		uint16 utype = 15;
		FString typeName = TEXT("VECTOR2");
		FString name = TEXT("VECTOR2");
		DATATYPE_BASE** fPtr = EntityDef::datatypes.Find(name);
		DATATYPE_BASE* pVal = fPtr != NULL ? *fPtr : NULL;
		EntityDef::datatypes.Add(typeName, pVal);
		EntityDef::id2datatypes.Add(utype, EntityDef::datatypes[typeName]);
		EntityDef::datatype2id.Add(typeName, utype);
	}

	{
		uint16 utype = 16;
		FString typeName = TEXT("VECTOR3");
		FString name = TEXT("VECTOR3");
		DATATYPE_BASE** fPtr = EntityDef::datatypes.Find(name);
		DATATYPE_BASE* pVal = fPtr != NULL ? *fPtr : NULL;
		EntityDef::datatypes.Add(typeName, pVal);
		EntityDef::id2datatypes.Add(utype, EntityDef::datatypes[typeName]);
		EntityDef::datatype2id.Add(typeName, utype);
	}

	{
		uint16 utype = 17;
		FString typeName = TEXT("VECTOR4");
		FString name = TEXT("VECTOR4");
		DATATYPE_BASE** fPtr = EntityDef::datatypes.Find(name);
		DATATYPE_BASE* pVal = fPtr != NULL ? *fPtr : NULL;
		EntityDef::datatypes.Add(typeName, pVal);
		EntityDef::id2datatypes.Add(utype, EntityDef::datatypes[typeName]);
		EntityDef::datatype2id.Add(typeName, utype);
	}

	for(auto& Elem : EntityDef::datatypes)
	{
		if(Elem.Value)
		{
			Elem.Value->bind();
		}
	}
}


}