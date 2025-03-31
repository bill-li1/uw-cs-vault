import { SAMPLE_QUESTIONS } from "./sampleData";
import { Subject } from "./observer";

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
  isCheatingEnabled: boolean;
};

let uniqueId = 1;

export class QuizModel extends Subject {
  private questions: Question[] = [];
  private mode: "list" | "quiz" = "list";
  private quizState: QuizState | null = null;
  private editingQuestionId: number | null = null;

  constructor() {
    super();
    this.initializeRandomQuestions(4);
  }

  private initializeRandomQuestions(count: number) {
    const shuffled = [...SAMPLE_QUESTIONS].sort(() => 0.5 - Math.random());
    shuffled.slice(0, count).forEach((q) => {
      this.questions.push({
        id: uniqueId++,
        ...q,
        selected: false,
      });
    });
  }

  addQuestion() {
    if (this.questions.length < 10) {
      const unusedQuestions = SAMPLE_QUESTIONS.filter(
        (sq) => !this.questions.some((q) => q.question === sq.question)
      );

      if (unusedQuestions.length > 0) {
        const randomQ =
          unusedQuestions[Math.floor(Math.random() * unusedQuestions.length)];
        this.questions.push({
          id: uniqueId++,
          ...randomQ,
          selected: false,
        });
        this.notifyObservers();
      }
    }
  }

  toggleQuestionSelection(id: number) {
    this.questions = this.questions.map((q) =>
      q.id === id ? { ...q, selected: !q.selected } : q
    );
    this.notifyObservers();
  }

  selectAllQuestions() {
    this.questions = this.questions.map((q) => ({ ...q, selected: true }));
    this.notifyObservers();
  }

  deselectAllQuestions() {
    this.questions = this.questions.map((q) => ({ ...q, selected: false }));
    this.notifyObservers();
  }

  deleteSelectedQuestions() {
    this.questions = this.questions.filter((q) => !q.selected);
    this.notifyObservers();
  }

  updateQuestion(id: number, updates: Partial<Question>) {
    this.questions = this.questions.map((q) =>
      q.id === id ? { ...q, ...updates } : q
    );
    this.notifyObservers();
  }

  startQuiz() {
    const selectedQuestions = this.questions.filter((q) => q.selected);
    if (selectedQuestions.length > 0) {
      this.mode = "quiz";
      this.quizState = {
        currentQuestionIndex: 0,
        answers: [],
        isCheatingEnabled: false,
      };
      this.notifyObservers();
    }
  }

  submitAnswer(isCorrect: boolean) {
    if (this.quizState) {
      this.quizState.answers.push(isCorrect);
      if (
        this.quizState.currentQuestionIndex <
        this.getSelectedQuestions().length - 1
      ) {
        this.quizState.currentQuestionIndex++;
      }
      this.notifyObservers();
    }
  }

  toggleCheating() {
    if (this.quizState) {
      this.quizState.isCheatingEnabled = !this.quizState.isCheatingEnabled;
      this.notifyObservers();
    }
  }

  exitQuiz() {
    this.mode = "list";
    this.quizState = null;
    this.notifyObservers();
  }

  startEditing(id: number) {
    this.editingQuestionId = id;
    this.notifyObservers();
  }

  stopEditing() {
    this.editingQuestionId = null;
    this.notifyObservers();
  }

  getMode() {
    return this.mode;
  }

  getQuestions() {
    return [...this.questions];
  }

  getSelectedQuestions() {
    return this.questions.filter((q) => q.selected);
  }

  getQuestion(id: number) {
    return this.questions.find((q) => q.id === id);
  }

  getCurrentQuizQuestion() {
    if (this.quizState) {
      const selectedQuestions = this.getSelectedQuestions();
      return selectedQuestions[this.quizState.currentQuestionIndex];
    }
    return null;
  }

  getQuizState() {
    return this.quizState;
  }

  getEditingQuestionId() {
    return this.editingQuestionId;
  }

  getTotalQuestions() {
    return this.questions.length;
  }

  getSelectedCount() {
    return this.questions.filter((q) => q.selected).length;
  }

  isQuizComplete() {
    return (
      this.quizState &&
      this.quizState.currentQuestionIndex ===
        this.getSelectedQuestions().length - 1 &&
      this.quizState.answers.length === this.getSelectedQuestions().length
    );
  }

  getRandomizedAnswers(): string[] | null {
    const currentQuestion = this.getCurrentQuizQuestion();
    if (!currentQuestion) return null;

    const answers = [
      currentQuestion.answer,
      currentQuestion.other1,
      currentQuestion.other2,
    ];

    return answers.sort(() => Math.random() - 0.5);
  }

  checkAnswer(answer: string): boolean {
    const currentQuestion = this.getCurrentQuizQuestion();
    return currentQuestion ? currentQuestion.answer === answer : false;
  }
}
