import {
  getQuestions,
  getSelectedQuestions,
  getCheatingEnabled,
} from "../state";

export default function BottomBar() {
  const isCheatingEnabled = getCheatingEnabled();
  const totalQuestions = getQuestions().length;
  const selectedCount = getSelectedQuestions().length;

  let message = "";
  if (totalQuestions === 0) {
    message = "";
  } else if (totalQuestions === 1) {
    message = "1 question";
  } else {
    message = `${totalQuestions} questions`;
  }

  if (selectedCount > 0) {
    message += ` (${selectedCount} selected)`;
  }

  return (
    <div className="flex justify-between bg-gray-300 h-[50px] items-center p-[10px]">
      <span>{message}</span>
      <span>{isCheatingEnabled ? "CHEATING" : ""}</span>
    </div>
  );
}
