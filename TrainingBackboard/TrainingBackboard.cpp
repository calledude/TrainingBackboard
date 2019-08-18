#include "TrainingBackboard.h"

BAKKESMOD_PLUGIN(TrainingBackboard, "Bring back ez backboard shots", "0.2", PLUGINTYPE_FREEPLAY)

void TrainingBackboard::OnFreeplayLoad(std::string eventName) 
{
	auto sw = gameWrapper->GetGameEventAsServer();

	if (!sw.IsPlayingTraining())
	{
		return;
	}

	auto ball = sw.GetBall();

	ball.SetLocation({0,0,100});
	ball.Stop();

}

void TrainingBackboard::onLoad()
{
	gameWrapper->HookEvent("Function GameEvent_TA.Countdown.EndState", bind(&TrainingBackboard::OnFreeplayLoad, this, std::placeholders::_1));
}

void TrainingBackboard::onUnload()
{
}