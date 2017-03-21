#include "Menu_controller.h"


MenuController::MenuController()
{
}

//want to quit
void MenuController::wantToQuit()
{
	m_isQuit = true;
}

void MenuController::notWantToQuit()
{
	m_isQuit = false;
}

bool MenuController::needToQuit()
{
	return m_isQuit;
}

//main menu
void MenuController::openMenu()
{
	m_mainMenuVisible = true;
}

void MenuController::closeMenu()
{
	m_mainMenuVisible = false;
}

bool MenuController::needInMenu()
{
	return m_mainMenuVisible;
}

//help menu
void MenuController::openHelp()
{
	m_helpVisible = true;
}

void MenuController::closeHelp()
{
	m_helpVisible = false;
}

void MenuController::changeHelp()
{
	m_helpVisible = !m_helpVisible;
}

bool MenuController::needInHelp()
{
	return m_helpVisible;
}

//quit menu
void MenuController::openQuitMenu()
{
	m_quitVisible = true;
}

void MenuController::closeQuitMenu()
{
	m_quitVisible = false;
}

bool MenuController::needInQuitM()
{
	return m_quitVisible;
}

//doors openable::
void MenuController::allowedToOpenDoor()
{
	m_isOpenable = true;
}

void MenuController::notAllowedToOpenDoor()
{
	m_isOpenable = false;
}

bool MenuController::needToAllowedOpenDoor()
{
	return m_isOpenable;
}

//waiting window // sand glass picture
void MenuController::openWaitingWindow()
{
	m_isWaiting = true;
}

void MenuController::closeWaitingWindow()
{
	m_isWaiting = false;
}

bool MenuController::needToOpenWaitingWindow()
{
	return m_isWaiting;
}

//menu light on or off
void MenuController::turnOnMenuLight()
{
	m_menuLight = true;
}

void MenuController::turnOffMenuLight()
{
	m_menuLight = false;
}

void MenuController::changeMenuLight()
{
	m_menuLight = !m_menuLight;
}

bool MenuController::needToTurnOnMenuLi()
{
	return m_menuLight;
}

//light slider moving
void MenuController::lightSliderMoveUp()
{
	if (m_lightSliderPos < 9)
	{
		m_lightSliderPos++;
	}
}

void MenuController::lightSliderMoveDown()
{
	if (m_lightSliderPos > 0)
	{
		m_lightSliderPos--;
	}
}

int MenuController::lightSliderActualPos()
{
	return m_lightSliderPos;
}

//set active quality
void MenuController::setActiveQualityLow()
{
	m_activeQuality = 1;
}

void MenuController::setActiveQualityMedium()
{
	m_activeQuality = 2;
}

void MenuController::setActiveQualityHigh()
{
	m_activeQuality = 3;
}

int MenuController::getActiveQuality()
{
	return m_activeQuality;
}

//set state of doors
void MenuController::changeStateOfDoors()
{
	m_stateOfDoors = !m_stateOfDoors;
}


bool MenuController::getStateOfDoors()
{
	return m_stateOfDoors;
}

//set guitar rot
void MenuController::changeGuitarRot()
{
	m_guitarRot = !m_guitarRot;
}


bool MenuController::getGuitarRot()
{
	return m_guitarRot;
}