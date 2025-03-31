import {
  getMode,
  startQuiz,
  exitQuiz,
  getSelectedQuestions,
  getQuizState,
  undoAction,
  redoAction,
  canUndo,
  canRedo,
  getIsQuizComplete,
} from "../state";

export default function TopBar() {
  const mode = getMode();
  const quizState = getQuizState();
  const isQuizComplete = getIsQuizComplete();
  const total = getSelectedQuestions().length;
  const current = quizState.currentQuestionIndex + 1;
  const action = mode === "list" ? startQuiz : exitQuiz;
  const disabled = mode === "list" && total === 0;
  return (
    <div
      className={`${
        mode === "list" ? "bg-gray-300" : "bg-blue-200"
      } justify-between
      flex p-[10px] h-[50px]`}
    >
      {mode === "quiz" ? (
        <span>
          {isQuizComplete
            ? "Quiz Completed"
            : `Question ${current} of ${total}`}
        </span>
      ) : (
        <div className="flex gap-[10px]">
          <button
            className="w-[80px]"
            onClick={() => undoAction()}
            disabled={!canUndo()}
          >
            Undo
          </button>
          <button
            className="w-[80px]"
            onClick={() => redoAction()}
            disabled={!canRedo()}
          >
            Redo
          </button>
        </div>
      )}
      <button
        className="w-[100px]"
        onClick={() => action()}
        disabled={disabled}
      >
        {mode === "list" ? "Quiz" : "Exit"}
      </button>
    </div>
  );
}
