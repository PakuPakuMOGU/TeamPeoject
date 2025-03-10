#include "Task.h"
#include <malloc.h>
#include <string.h>

/* --- タスクの追加・削除の反映 --- */
static void Task_UpData(TaskSystem* TSystem)
{
	TaskInfo* TInfo;
	TaskInfo* NextInfo;
	TaskInfo* TempInfo;

	if (TSystem->AddTask != NULL)
	{
		for (TInfo = TSystem->AddTask; TInfo != NULL; TInfo = NextInfo)
		{
			// 追加するタスクの次のタスクのアドレスを保持.
			NextInfo = TInfo->AddDelNext;		

			// 優先順位に応じた状態推移のタスクを追加.
			TInfo->StepNext = TSystem->StepTask[TInfo->Base->StepNumber];
			TSystem->StepTask[TInfo->Base->StepNumber] = TInfo;

			// 優先順位に応じた描画のタスクを追加.
			TInfo->RenderNext = TSystem->RenderTask[TInfo->Base->RenderNumber];
			TSystem->RenderTask[TInfo->Base->RenderNumber] = TInfo;

			// 追加するタスクの次のアドレスを初期化.
			TInfo->AddDelNext = NULL;
		}
		TSystem->AddTask = NULL;
	}
	if (TSystem->DelTask != NULL)
	{
		for (TInfo = TSystem->DelTask; TInfo != NULL; TInfo = NextInfo)
		{
			// 追加するタスクの次のタスクのアドレスを保持.
			NextInfo = TInfo->AddDelNext;

			// 外すタスクが状態推移処理のタスクの先頭かをチェック.
			if (TSystem->StepTask[TInfo->Base->StepNumber] == TInfo)
			{
				// 先頭だった場合は次のタスクにする.
				TSystem->StepTask[TInfo->Base->StepNumber] = TInfo->StepNext;
			}
			else
			{
				// 状態推移処理のタスクのリストから外すタスクを検索.
				TempInfo = TSystem->StepTask[TInfo->Base->StepNumber];
				while (true)
				{
					// タスクがない場合ループを抜ける.
					if (TempInfo->StepNext == NULL)		break;				

					// 削除対象のタスクが見つかればリストから外す.
					if (TempInfo->StepNext == TInfo)
					{
						TempInfo->StepNext = TInfo->StepNext;
						break;
					}
					TempInfo = TempInfo->StepNext;
				}
			}
			// 外すタスクが描画タスクの先頭かをチェック
			if (TSystem->RenderTask[TInfo->Base->RenderNumber] == TInfo)
			{
				// 先頭だった場合は次のタスクにする.
				TSystem->RenderTask[TInfo->Base->StepNumber] = TInfo->RenderNext;
			}
			else
			{
				TempInfo = TSystem->RenderTask[TInfo->Base->StepNumber];
				while (true)
				{
					// タスクがない場合ループを抜ける.
					if (TempInfo->RenderNext == NULL)	break;

					// 削除対象のタスクが見つかればリストから外す.
					if (TempInfo->RenderNext == TInfo)
					{
						TempInfo->RenderNext = TInfo->RenderNext;
						break;
					}

					TempInfo = TempInfo->RenderNext;
				}
			}

			// 終了する関数があれば実行.
			if (TInfo->Base->Finish != NULL)
				TInfo->Base->Finish(TInfo);

			// ポインタ初期化.
			TInfo->AddDelNext = NULL;
			TInfo->StepNext   = NULL;
			TInfo->RenderNext = NULL;
			
			// メモリ解放.
			if (TInfo->Data != NULL)
				free(TInfo->Data);
		}
		// 削除するタスクのポインタを初期化.
		TSystem->DelTask = NULL;
	}
}

/* --- タスクの状態推移、timeは推移時間 --- */
bool Task_Step(TaskSystem* TSystem, float time)
{
	TaskInfo* TInfo;
	int		  i;

	TSystem->Run = true;	// 実行中フラグON.

	for (int i = 0; i < TASK_NUMBER_MAX; i++)
	{
		// 優先順位iのタスクの状態推移処理を実行.
		for (TInfo = TSystem->StepTask[i]; TInfo != NULL; TInfo = TInfo->StepNext)
		{
			if (!TInfo->Base->Step(TInfo, time))
			{
				return false;
			}
		}
	}

	TSystem->Run = false;	// 実行中フラグOFF.

	Task_UpData(TSystem);	// タスク登録・削除の反映.

	return true;
}

/* --- タスクの描画 --- */
bool Task_Step(TaskSystem* TSystem)
{
	TaskInfo* TInfo;
	int		  i;

	TSystem->Run = true;	// 実行中フラグON.

	for (int i = 0; i < TASK_NUMBER_MAX; i++)
	{
		// 優先順位iのタスクの描画処理を実行.
		for (TInfo = TSystem->StepTask[i]; TInfo != NULL; TInfo = TInfo->StepNext)
		{
			// 削除タスクに登録されている場合、描画しない.
			if (!TInfo->AddDelNext != NULL)
			{
				continue;
			}

			TInfo->Base->Render(TInfo);
		}
	}

	TSystem->Run = false;	// 実行中フラグOFF.

	Task_UpData(TSystem);	// タスク登録・削除の反映.

	return true;
}

void Task_Add(TaskSystem* TSystem, TaskInfo* TInfo)
{
	// タスクシステムの追加するタスクに追加
	TInfo->AddDelNext = TSystem->AddTask;
	TSystem->AddTask = TInfo;

	// タスクが実行中でなければすぐにタスクを反映
	if (!TSystem->Run)
	{
		Task_UpData(TSystem);
	}
}

// 登録したタスクの削除.
void Task_Del(TaskSystem* TSystem, TaskInfo* TInfo)
{
	TaskInfo* TempInfo;

	// 追加するタスクのリストからタスクを外す.
	if (TInfo->AddDelNext != NULL)
	{
		// 外すタスクが追加タスクの先頭かをチェック
		if (TSystem->AddTask == TInfo)
		{
			// 先頭だった場合は外して次のタスクにする.
			TSystem->AddTask = TInfo->AddDelNext;
		}
		else
		{
			TempInfo = TSystem->AddTask;
			while (true)
			{
				// タスクがない場合ループを抜ける.
				if (TempInfo->AddDelNext == NULL)	break;

				// 削除対象のタスクが見つかればリストから外す.
				if (TempInfo->AddDelNext == TInfo)
				{
					TempInfo->AddDelNext = TInfo->AddDelNext;
					break;
				}
				TempInfo = TempInfo->AddDelNext;
			}
		}

		// 終了する関数があれば実行.
		if (TInfo->Base->Finish != NULL)
			TInfo->Base->Finish(TInfo);

		// ポインタ初期化.
		TInfo->AddDelNext = NULL;

		// メモリ解放.
		if (TInfo->Data != NULL)
			free(TInfo->Data);
	}
	else
	{
		// タスクシステムの削除するタスクに追加
		TInfo->AddDelNext = TSystem->DelTask;
		TSystem->DelTask = TInfo;

		// タスクが実行中でなければすぐにタスクを反映
		if (!TSystem->Run)
		{
			Task_UpData(TSystem);
		}
	}
}

// タスクシステムの初期化
void Task_Init(TaskSystem* TSystem)
{
	// 構造体全体をゼロで初期化.
	memset(TSystem, 0, sizeof(TaskSystem));
}

// タスクシステムの終了.
void Task_Finish(TaskSystem* TSystem)
{
	TaskInfo* TInfo;
	int        i;

	// タスクの処理を実行しているかどうかのフラグを『実行中』にしておく
	TSystem->Run = true;

	// 実行優先順位の数だけ繰り返し
	for (i = 0; i < TASK_NUMBER_MAX; i++)
	{
		// 実行優先順位 i に登録されているタスクを全て削除する
		for (TInfo = TSystem->StepTask[i]; TInfo != NULL; TInfo = TInfo->StepNext)
		{
			Task_Del(TSystem, TInfo);
		}
	}

	// タスクの処理を実行しているかどうかのフラグを『実行中ではない』にしておく
	TSystem->Run = false;

	// 削除を反映する
	Task_UpData(TSystem);
}