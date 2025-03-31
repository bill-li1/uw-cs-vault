import {
  getEditingQuestionId,
  stopEditing,
  getQuestion,
  updateQuestion,
} from "../state";
import { TargetedEvent } from "preact/compat";
import { useState } from "preact/hooks";
import { Question } from "../types";

export default function EditQuestion() {
  const editingQuestionId = getEditingQuestionId();
  const question = getQuestion(editingQuestionId);
  if (!question) return <></>;
  const [newQuestion, setNewQuestion] = useState<Question>(question);
  console.log({ newQuestion });
  return (
    <div className="fixed top-0 left-0 w-screen h-screen flex justify-center items-center bg-black bg-opacity-65">
      <div className="w-[500px] h-[240px] border border-black bg-gray-100 p-[16px]">
        <div className="grid grid-cols-4 gap-[10px]">
          <label className="flex justify-end items-center">Question</label>
          <input
            type="text"
            value={newQuestion.question}
            className="col-span-3"
            onChange={(e: TargetedEvent<HTMLInputElement, Event>) => {
              setNewQuestion({
                ...newQuestion,
                question: e.currentTarget.value,
              });
            }}
          />
          <label className="flex justify-end items-center">Answer</label>
          <input
            type="text"
            value={newQuestion.answer}
            className="col-span-3"
            onChange={(e: TargetedEvent<HTMLInputElement, Event>) => {
              setNewQuestion({ ...newQuestion, answer: e.currentTarget.value });
            }}
          />
          <label className="flex justify-end items-center">Other 1</label>
          <input
            type="text"
            value={newQuestion.other1}
            className="col-span-3"
            onChange={(e: TargetedEvent<HTMLInputElement, Event>) => {
              setNewQuestion({ ...newQuestion, other1: e.currentTarget.value });
            }}
          />
          <label className="flex justify-end items-center">Other 2</label>
          <input
            type="text"
            value={newQuestion.other2}
            className="col-span-3"
            onChange={(e: TargetedEvent<HTMLInputElement, Event>) => {
              setNewQuestion({ ...newQuestion, other2: e.currentTarget.value });
            }}
          />
        </div>
        <div className="flex justify-end gap-[10px] mt-[10px]">
          <button
            onClick={() => {
              updateQuestion(question.id, newQuestion);
              stopEditing();
            }}
          >
            Save
          </button>
          <button onClick={() => stopEditing()}>Cancel</button>
        </div>
      </div>
    </div>
  );
}
