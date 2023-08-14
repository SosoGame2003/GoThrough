#pragma once

class Application
{
public:
	Application();
	~Application();

	/// <summary>
	/// ゲームループ
	/// </summary>
	void GameLoop();

private:
	class SceneManager* sceneMgr;

	const int ScreenSizeX	  = 1000;	// ウィンドウの幅
	const int ScreenSizeY	  = 1000;	// ウィンドウの高さ
	const int ColorBitDepth	  =	  32;	// カラービット数
};