#include "System.h"
#include "DxLib.h"
#include "Player.h"

// タスク処理.
typedef enum Task_GameState
{
	Task_GameState_AddItem,		// アイテムを拾う.
	Task_GameState_DeletItem,   // アイテムを捨てる.
	Task_GameState_EndItem,		// アイテムの処理終了.
};