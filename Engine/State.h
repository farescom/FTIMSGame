#pragma once
class IState
{
public:
	virtual bool initialize() = 0;
	virtual void shutdown() = 0;
	virtual bool update() = 0;
	virtual void render() = 0;
};

