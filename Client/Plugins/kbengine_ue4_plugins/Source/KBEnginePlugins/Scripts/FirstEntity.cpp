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
		//��־
		DEBUG_MSG("FirstEntity::onEnter");
	}

	void FirstEntity::OnSay(const FString& arg1)
	{
		//DEBUG_MSG(content);
		//�ҵ�UI Text����
		//Text text = GameObject.Find("Canvas/Text").GetComponent<Text>();
		//����һ��say������
		//text.text = text.text + "\n" + content;
	}

}