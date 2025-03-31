import { signal } from "@preact/signals";
import { SAMPLE_QUESTIONS } from "./sampleData";
import { Question, QuizState } from "./types";

let uniqueId = 1;

const getRandomQuestions = (count: number) => {
  const shuffled = [...SAMPLE_QUESTIONS].sort(() => 0.5 - Math.random());
  return shuffled.slice(0, count).map((q) => ({
    id: uniqueId++,
    ...q,
    selecetd: false,
  }));
};

const questionSignal = signal<Question[]>(getRandomQuestions(4));
const modeSignal = signal<"list" | "quiz">("list");
const quizStateSignal = signal<QuizState>({
  currentQuestionIndex: -1,
  answers: [],
});
const cheatingEnabledSignal = signal<boolean>(false);
const editingQuestionIdSignal = signal<number>(-1);
const undoListSignal = signal<Array<Array<Question>>>([]);
const redoListSignal = signal<Array<Array<Question>>>([]);

const redoAction = () => {
  if (redoListSignal.value.length > 0) {
    const newState = redoListSignal.value[redoListSignal.value.length - 1];
    if (newState) {
      undoListSignal.value = [...undoListSignal.value, questionSignal.value];
      questionSignal.value = newState;
      redoListSignal.value = redoListSignal.value.slice(0, -1);
    }
  }
};

const undoAction = () => {
  if (undoListSignal.value.length > 0) {
    const newState = undoListSignal.value[undoListSignal.value.length - 1];
    if (newState) {
      redoListSignal.value = [...redoListSignal.value, questionSignal.value];
      questionSignal.value = newState;
      undoListSignal.value = undoListSignal.value.slice(0, -1);
    }
  }
};

const canUndo = () => {
  return undoListSignal.value.length > 0;
};

const canRedo = () => {
  return redoListSignal.value.length > 0;
};

const appendToUndoList = () => {
  undoListSignal.value = [...undoListSignal.value, questionSignal.value];
  redoListSignal.value = [];
};

const addQuestion = () => {
  const questions = questionSignal.value;
  if (questions.length < 10) {
    const unusedQuestions = SAMPLE_QUESTIONS.filter(
      (sq) => !questions.some((q) => q.question === sq.question)
    );

    if (unusedQuestions.length > 0) {
      const randomQ =
        unusedQuestions[Math.floor(Math.random() * unusedQuestions.length)];
      appendToUndoList();
      questionSignal.value = [
        ...questions,
        {
          id: uniqueId++,
          ...randomQ,
          selected: false,
        },
      ];
    }
  }
};

const toggleQuestionSelection = (id: number) => {
  const questions = questionSignal.value.map((q) =>
    q.id === id
      ? {
          ...q,
          selected: !q.selected,
        }
      : q
  );
  questionSignal.value = questions;
};

const selectAllQuestions = () => {
  const questions = questionSignal.value.map((q) => ({ ...q, selected: true }));
  questionSignal.value = questions;
};

const deselectAllQuestions = () => {
  const questions = questionSignal.value.map((q) => ({
    ...q,
    selected: false,
  }));
  questionSignal.value = questions;
};

const deleteSelectedQuestions = () => {
  const questions = questionSignal.value.filter((q) => !q.selected);
  appendToUndoList();
  questionSignal.value = questions;
};

const updateQuestion = (id: number, updates: Partial<Question>) => {
  const questions = questionSignal.value.map((q) =>
    q.id === id ? { ...q, ...updates } : q
  );
  appendToUndoList();
  questionSignal.value = questions;
};

const startQuiz = () => {
  const selectedQuestions = questionSignal.value.filter((q) => q.selected);
  if (selectedQuestions.length > 0) {
    modeSignal.value = "quiz";
    quizStateSignal.value = {
      currentQuestionIndex: 0,
      answers: [],
    };
  }
};

const submitAnswer = (isCorrect: boolean) => {
  const selectedQuestions = questionSignal.value.filter((q) => q.selected);
  if (quizStateSignal.value.currentQuestionIndex < 0) return;
  quizStateSignal.value = {
    ...quizStateSignal.value,
    answers: [...quizStateSignal.value.answers, isCorrect],
    currentQuestionIndex:
      quizStateSignal.value.currentQuestionIndex < selectedQuestions.length - 1
        ? quizStateSignal.value.currentQuestionIndex + 1
        : quizStateSignal.value.currentQuestionIndex,
  };
};

const toggleCheating = () => {
  cheatingEnabledSignal.value = !cheatingEnabledSignal.value;
};

const exitQuiz = () => {
  modeSignal.value = "list";
  quizStateSignal.value = {
    currentQuestionIndex: -1,
    answers: [],
  };
};

const startEditing = (id: number) => {
  editingQuestionIdSignal.value = id;
};

const stopEditing = () => {
  editingQuestionIdSignal.value = -1;
};

const getMode = () => {
  return modeSignal.value;
};

const getQuestions = () => {
  return [...questionSignal.value];
};

const getSelectedQuestions = () => {
  return questionSignal.value.filter((q) => q.selected);
};

const getQuestion = (id: number) => {
  return questionSignal.value.find((q) => q.id === id);
};

const getCurrentQuizQuestion = () => {
  if (quizStateSignal.value.currentQuestionIndex < 0) return null;
  const selectedQuestions = getSelectedQuestions();
  return selectedQuestions[quizStateSignal.value.currentQuestionIndex];
};

const getQuizState = () => {
  return quizStateSignal.value;
};

const getEditingQuestionId = () => {
  return editingQuestionIdSignal.value;
};

const getIsQuizComplete = () => {
  return (
    quizStateSignal.value.currentQuestionIndex ===
      getSelectedQuestions().length - 1 &&
    quizStateSignal.value.answers.length === getSelectedQuestions().length
  );
};

const getRandomizedAnswers = () => {
  const currentQuestion = getCurrentQuizQuestion();
  if (!currentQuestion) return null;
  const answers = [
    currentQuestion.answer,
    currentQuestion.other1,
    currentQuestion.other2,
  ];

  return answers.sort(() => Math.random() - 0.5);
};

const checkAnswer = (answer: string) => {
  const currentQuestion = getCurrentQuizQuestion();
  if (!currentQuestion) return false;
  return currentQuestion.answer === answer;
};

const getCheatingEnabled = () => {
  return cheatingEnabledSignal.value;
};

export {
  questionSignal,
  modeSignal,
  quizStateSignal,
  editingQuestionIdSignal,
  undoListSignal,
  getCheatingEnabled,
  addQuestion,
  toggleQuestionSelection,
  selectAllQuestions,
  deselectAllQuestions,
  deleteSelectedQuestions,
  updateQuestion,
  startQuiz,
  submitAnswer,
  toggleCheating,
  exitQuiz,
  startEditing,
  stopEditing,
  getMode,
  getQuestions,
  getSelectedQuestions,
  getQuestion,
  getCurrentQuizQuestion,
  getQuizState,
  getEditingQuestionId,
  getIsQuizComplete,
  getRandomizedAnswers,
  checkAnswer,
  canUndo,
  canRedo,
  redoAction,
  undoAction,
};
