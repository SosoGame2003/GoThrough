#pragma once

/// <summary>
/// シーンのタグ
/// </summary>
enum class SCENE_TAG
{
	MENU,	// メニュー
	PLAY,	// プレイ
	RESULT,	// リザルト
	END,	// ゲーム終了
	NONE,	// 戻り値
};

/// <summary>
/// シーン
/// </summary>
class Scene
{
public:
	Scene(){ /*処理なし*/ }
	virtual ~Scene() { /*処理なし*/ }

	/// <summary>
	/// 更新処理
	/// </summary>
	/// <param name="deltaTime">デルタタイム</param>
	/// <returns>NONE</returns>
	virtual SCENE_TAG Update(float deltaTime) = 0;

	/// <summary>
	/// 描画処理
	/// </summary>
	virtual void Draw() = 0;
};