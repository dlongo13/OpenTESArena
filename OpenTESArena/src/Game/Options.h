#ifndef OPTIONS_H
#define OPTIONS_H

#include <string>

// Settings found in the options menu are saved in this object, which should live in
// the game state object since it persists for the lifetime of the program.

enum class PlayerInterface;

class Options
{
private:
	// Graphics.
	int screenWidth, screenHeight;
	bool fullscreen;
	int targetFPS;
	double resolutionScale; // Percent.
	double verticalFOV; // In degrees.
	double letterboxAspect;
	double cursorScale;
	PlayerInterface playerInterface;

	// Input.
	double hSensitivity, vSensitivity;

    // Sound.
    std::string soundfont; // .cfg file.
    double musicVolume, soundVolume;
    int soundChannels;

	// Miscellaneous.
	std::string arenaPath; // "ARENA" data path.
	bool skipIntro;
public:
	Options(std::string &&arenaPath, int screenWidth, int screenHeight, bool fullscreen,
		int targetFPS, double resolutionScale, double verticalFOV, double letterboxAspect,
		double cursorScale, double hSensitivity, double vSensitivity, std::string &&soundfont,
		double musicVolume, double soundVolume, int soundChannels, bool skipIntro,
		PlayerInterface playerInterface);
	~Options();

	static const int MIN_FPS;
	static const double MIN_RESOLUTION_SCALE;
	static const double MAX_RESOLUTION_SCALE;
	static const double MIN_VERTICAL_FOV;
	static const double MAX_VERTICAL_FOV;

	int getScreenWidth() const;
	int getScreenHeight() const;
	bool isFullscreen() const;
	int getTargetFPS() const;
	double getResolutionScale() const;
	double getVerticalFOV() const;
	double getLetterboxAspect() const;
	double getCursorScale() const;
	double getHorizontalSensitivity() const;
	double getVerticalSensitivity() const;
	const std::string &getSoundfont() const;
	double getMusicVolume() const;
	double getSoundVolume() const;
	int getSoundChannelCount() const;
	const std::string &getArenaPath() const;
	bool introIsSkipped() const;
	PlayerInterface getPlayerInterface() const;

	void setScreenWidth(int width);
	void setScreenHeight(int height);
	void setFullscreen(bool fullscreen);
	void setTargetFPS(int targetFPS);
	void setResolutionScale(double percent);
	void setVerticalFOV(double fov);
	void setLetterboxAspect(double aspect);
	void setCursorScale(double cursorScale);
	void setHorizontalSensitivity(double hSensitivity);
	void setVerticalSensitivity(double vSensitivity);
    void setSoundfont(std::string sfont);
	void setMusicVolume(double percent);
	void setSoundVolume(double percent);
	void setSoundChannelCount(int count);
	void setArenaPath(std::string path);
	void setSkipIntro(bool skip);
	void setPlayerInterface(PlayerInterface playerInterface);
};

#endif
