#pragma once
#include "Engine/FirstEntityBase.h"

namespace KBEngine {
	class FirstEntity :
		public FirstEntityBase {
	public:
		FirstEntity();
		virtual ~FirstEntity();

		void OnEnter();
		void OnSay(const FString& arg1);
	};
}
