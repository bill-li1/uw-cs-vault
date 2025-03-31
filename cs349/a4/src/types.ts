export type Question = {
  id: number;
  question: string;
  answer: string;
  other1: string;
  other2: string;
  selected?: boolean;
};

export type QuizState = {
  currentQuestionIndex: number;
  answers: boolean[]; // true for correct, false for incorrect
};
