import {
  addQuestion,
  getQuestions,
  getSelectedQuestions,
  selectAllQuestions,
  deselectAllQuestions,
  deleteSelectedQuestions,
} from "../state";
import Question from "./Question";

export default function QuestionList() {
  const questions = getQuestions();
  const selectedQuestions = getSelectedQuestions();
  const totalQuestions = questions.length;
  const selectedCount = selectedQuestions.length;
  const buttons = [
    {
      text: "All",
      onClick: () => selectAllQuestions(),
      disabled: selectedCount >= totalQuestions,
    },
    {
      text: "None",
      onClick: () => deselectAllQuestions(),
      disabled: selectedCount <= 0,
    },
    {
      text: "Delete",
      onClick: () => deleteSelectedQuestions(),
      disabled: selectedCount <= 0,
    },
    {
      text: "Add",
      onClick: () => addQuestion(),
      disabled: totalQuestions >= 10,
    },
  ];
  return (
    <div className="flex flex-col m-[10px] flex-grow">
      <div className="border-black border-2 border-b-0 p-[10px] gap-[10px] flex">
        {buttons.map((b) => (
          <button
            className="w-[80px]"
            onClick={b.onClick}
            disabled={b.disabled}
          >
            {b.text}
          </button>
        ))}
      </div>
      <div className="p-[10px] border-2 border-black flex-grow">
        <div className="flex flex-wrap gap-[10px]">
          {questions.map((q) => (
            <Question q={q} key={q.question} />
          ))}
        </div>
      </div>
    </div>
  );
}
