#include "FirstEntity.h"

namespace KBEngine 
{
	FirstEntity::FirstEntity() :FirstEntityBase()
	{

	}
	FirstEntity::~FirstEntity() 
	{

	}

	void FirstEntity::OnEnter()
	{
		//日志
		DEBUG_MSG("FirstEntity::onEnter");
	}

	void FirstEntity::OnSay(const FString& arg1)
	{
		//DEBUG_MSG(content);
		//找到UI Text对象
		//Text text = GameObject.Find("Canvas/Text").GetComponent<Text>();
		//增加一行say的内容
		//text.text = text.text + "\n" + content;
	}

}