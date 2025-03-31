import {
  getCurrentQuizQuestion,
  getIsQuizComplete,
  getQuizState,
  getRandomizedAnswers,
  submitAnswer,
  getCheatingEnabled,
} from "../state";
import { useMemo } from "preact/hooks";

export default function Quiz() {
  const currentQuestion = getCurrentQuizQuestion();
  const isCheatingEnabled = getCheatingEnabled();
  const quizState = getQuizState();
  const isFinished = getIsQuizComplete();
  const answers = useMemo(
    () => getRandomizedAnswers(),
    [currentQuestion, quizState]
  );
  console.log({ isCheatingEnabled });

  let correct = 0;
  for (let i = 0; i < (quizState?.answers?.length ?? 0); i++) {
    if (quizState?.answers?.[i] === true) {
      correct++;
    }
  }

  return (
    <div className="flex flex-grow p-[50px] bg-gray-100">
      <div className="flex flex-col bg-white border-2 border-black w-full">
        <div className="flex flex-grow justify-center items-center font-bold text-xl">
          {isFinished
            ? `${correct} Correct, ${
                quizState.answers.length - correct
              } Incorrect`
            : currentQuestion?.question}
        </div>
        {isFinished ? (
          <></>
        ) : (
          <div className="flex gap-[10px] p-[10px]">
            {answers?.map((a, i) => (
              <button
                key={i}
                onClick={() => submitAnswer(a === currentQuestion?.answer)}
                className={`flex w-full justify-center items-center ${
                  isCheatingEnabled && a === currentQuestion?.answer
                    ? "bg-yellow-100"
                    : "bg-white"
                }`}
              >
                {a}
              </button>
            ))}
          </div>
        )}
      </div>
    </div>
  );
}
