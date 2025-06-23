#pragma once
class Scene 
{

public:
	virtual void Init() = 0;
	virtual void Progress() = 0;
	virtual void Render() = 0;
};

