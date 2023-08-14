#pragma once

// 必要なヘッダーファイルをインクルード
#include<DxLib.h>
#include"Scene.h"

/// <summary>
/// シーンマネージャー
/// </summary>
class SceneManager
{
public:
	SceneManager();
	~SceneManager();

	/// <summary>
	/// ゲームループ
	/// </summary>
	void GameLoop();

	/// <summary>
	/// シーンの呼び出し
	/// </summary>
	/// <param name="tag">シーンのタグ</param>
	void SetNowScene(const SCENE_TAG& tag);

private:
	/// <summary>
	/// シーンの削除
	/// </summary>
	void DeleteScene();

	/// <summary>
	/// デルタタイムの保存
	/// </summary>
	void SaveDeltaTime();

	Scene* currentScene;	// 現在のシーン

	// フレームレート関連
	float deltaTime;
	int fps;
	int fpsCounter;
	LONGLONG currentTime;
	LONGLONG time;
	LONGLONG fpsCheckTime;

	// カメラ関連
	const float cameraNear		 =	   1.0f;	// 手前クリップ距離
	const float cameraFar		 =  5000.0f;	// 奥クリップ距離
	const float cameraPosX		 =	   0.0f;	// カメラのX座標
	const float cameraPosY		 =	   0.0f;	// カメラのY座標
	const float cameraPosZ		 =	-750.0f;	// カメラのZ座標
	const float cameraGazingPosX =	   0.0f;	// カメラのX座標注視点
	const float cameraGazingPosY =	   0.0f;	// カメラのY座標注視点
	const float cameraGazingPosZ =	2000.0f;	// カメラのZ座標注視点
};