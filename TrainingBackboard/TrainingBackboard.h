#pragma once
#pragma comment(lib, "bakkesmod.lib")
#include "bakkesmod/plugin/bakkesmodplugin.h"

class TrainingBackboard : public BakkesMod::Plugin::BakkesModPlugin
{
public:
	void OnFreeplayLoad(std::string eventName);
	virtual void onLoad();
	virtual void onUnload();
};