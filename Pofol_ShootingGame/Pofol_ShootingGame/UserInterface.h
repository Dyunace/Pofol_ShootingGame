#pragma once

class UserInterface
{
private:
	static UserInterface* Instance;
public:
	static UserInterface* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new UserInterface;

		return Instance;
	}
private:
	UserInterface() {};
public:
	~UserInterface() {};
public:
	void Update();
	void Render();
	void StageInterface();
	void MakeUI(float _x, float _y, float _Width, float _Height);
};