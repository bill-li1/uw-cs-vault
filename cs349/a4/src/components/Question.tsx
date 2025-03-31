import type { Question } from "../types";
import EditQuestion from "./EditQuestion";
import {
  getSelectedQuestions,
  toggleQuestionSelection,
  getEditingQuestionId,
  startEditing,
} from "../state";

export default function Question({ q }: { q: Question }) {
  const open = getEditingQuestionId() === q.id;
  const selectedQuestions = getSelectedQuestions();
  return (
    <div key={q.question} className="flex w-fit bg-blue-200 px-2 py-1 gap-2">
      <input
        type="checkbox"
        checked={selectedQuestions.includes(q)}
        onChange={() => toggleQuestionSelection(q.id)}
      />
      <div onDblClick={() => startEditing(q.id)}>
        <span className="">{q.question}</span>
      </div>
      {open && <EditQuestion />}
    </div>
  );
}
