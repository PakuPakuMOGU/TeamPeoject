#ifndef TASK_H
#define TASK_H

// タスクの優先順位数-1.今は仮.
#define TASK_NUMBER_MAX 11

/* --- タスクの基本情報 --- */
typedef struct _TaskBaseInfo
{
	int StepNumber;		// 実行優先順位.

	int RenderNumber;	// 描画優先順位.

	bool(*Step)(struct _TaskInfo* TInfo, float steptime);	// 状態推移をする関数へのポインタ.

	void(*Render)(struct _TaskInfo* TInfo);					// 描画をする関数へのポインタ.

	void(*Finish)(struct _TaskInfo* TInfo);					// 終了する関数へのポインタ.

}TaskBaseInfo;

/* --- タスクの情報 --- */
typedef struct _TaskInfo
{
	TaskBaseInfo* Base;

	void* Data;							// タスクデータのポインタ.

	struct _TaskInfo* StepNext;			// 実行優先順位が同じ次のタスクへのポインタ.

	struct _TaskInfo* RenderNext;		// 描画優先順位が同じ次のタスクへのポインタ.

	struct _TaskInfo* AddDelNext;		// 追加・削除する次のタスクへのポインタ.

}TaskInfo;

/* --- タスクのシステム情報 --- */
typedef struct _TaskSystem
{
	bool Run;		// 実行中かどうか.

	TaskInfo* StepTask[TASK_NUMBER_MAX];	// 状態推移優先順位の先頭タスクへのポインタ.

	TaskInfo* RenderTask[TASK_NUMBER_MAX];	// 描画優先順位の先頭タスクへのポインタ.

	TaskInfo* AddTask;		// 追加するタスクへのポインタ.
	TaskInfo* DelTask;		// 削除するタスクへのポインタ.

}TaskSystem;

// タスクシステム初期化.
extern void Task_Init(TaskSystem* TSystem);

// タスクシステム終了.
extern void Task_Finish(TaskSystem* TSystem);

#endif