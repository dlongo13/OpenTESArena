#ifndef PAUSE_MENU_PANEL_H
#define PAUSE_MENU_PANEL_H

#include <string>

#include "Button.h"
#include "Panel.h"

class AudioManager;
class Options;
class Renderer;
class TextBox;

class PauseMenuPanel : public Panel
{
private:
	std::unique_ptr<TextBox> playerNameTextBox, musicTextBox, soundTextBox,
		optionsTextBox, optionsShadowTextBox;
	std::unique_ptr<Button<Game*>> loadButton;
	std::unique_ptr<Button<>> exitButton;
	std::unique_ptr<Button<Game*>> newButton, saveButton, resumeButton, optionsButton;
	std::unique_ptr<Button<Options&, AudioManager&, PauseMenuPanel*>> musicUpButton, 
		musicDownButton, soundUpButton, soundDownButton;

	void updateMusicText(double volume);
	void updateSoundText(double volume);
public:
	PauseMenuPanel(Game *game);
	virtual ~PauseMenuPanel();

	virtual void handleEvent(const SDL_Event &e) override;
	virtual void render(Renderer &renderer) override;
};

#endif
