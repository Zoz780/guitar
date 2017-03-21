#pragma once
class MenuController
{
private:
	bool m_isQuit;
	bool m_mainMenuVisible = true;
	bool m_helpVisible;
	bool m_quitVisible;
	bool m_isOpenable;
	bool m_isWaiting;
	bool m_menuLight = true;
	int m_lightSliderPos = 0;
	int m_activeQuality = 1;
	bool m_stateOfDoors;
	bool m_guitarRot;

public:
	MenuController();

	void wantToQuit();
	void notWantToQuit();
	bool needToQuit();

	void openMenu();
	void closeMenu();
	bool needInMenu();

	void openHelp();
	void closeHelp();
	void changeHelp();
	bool needInHelp();

	void openQuitMenu();
	void closeQuitMenu();
	bool needInQuitM();

	void allowedToOpenDoor();
	void notAllowedToOpenDoor();
	bool needToAllowedOpenDoor();

	void openWaitingWindow();
	void closeWaitingWindow();
	bool needToOpenWaitingWindow();

	void turnOnMenuLight();
	void turnOffMenuLight();
	void changeMenuLight();
	bool needToTurnOnMenuLi();

	void lightSliderMoveUp();
	void lightSliderMoveDown();
	int lightSliderActualPos();

	void setActiveQualityLow();
	void setActiveQualityMedium();
	void setActiveQualityHigh();
	int getActiveQuality();

	void changeStateOfDoors();
	bool getStateOfDoors();

	void changeGuitarRot();
	bool getGuitarRot();

};

