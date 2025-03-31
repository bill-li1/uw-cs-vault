import { QuizModel } from "../model";
import View from "../view";
import "./quizView.css";

export class QuizView implements View {
    answerButtons = [
        document.createElement("button"),
        document.createElement("button"),
        document.createElement("button"),
    ];
    update(): void {
        const question = this.model.getCurrentQuizQuestion();
        const quizState = this.model.getQuizState();
        const isFinished = this.model.isQuizComplete();

        if (isFinished) {
            let correct = 0;
            for (let i = 0; i < (quizState?.answers?.length ?? 0); i++) {
                if (quizState?.answers?.[i] === true) {
                    correct++;
                }
            }
            this.questionLabel.innerText = `${correct} correct, ${
                (quizState?.answers?.length ?? 0) - correct
            } incorrect`;
            this.buttonContainer.replaceChildren();
        } else if (question && quizState) {
            this.questionLabel.innerText = question.question;

            const answers = this.model.getRandomizedAnswers();
            if (answers) {
                this.answerButtons.forEach((button, index) => {
                    button.innerText = answers[index];
                    if (quizState.isCheatingEnabled) {
                        button.classList.toggle(
                            "cheating",
                            answers[index] === question.answer
                        );
                    }
                });
            }
        }
    }

    questionLabel = document.createElement("span");
    buttonContainer = document.createElement("div");
    private container: HTMLElement;
    get root(): HTMLElement {
        return this.container;
    }

    constructor(private model: QuizModel) {
        this.container = document.createElement("div");
        this.container.id = "root-quiz-container";
        this.buttonContainer.id = "quiz-button-container";
        this.questionLabel.id = "question-label";
        this.model.addObserver(this);

        this.answerButtons.forEach((button) => {
            button.id = "answer-button";
            this.buttonContainer.appendChild(button);
            button.addEventListener("click", () => {
                const isCorrect =
                    button.innerText ===
                    this.model.getCurrentQuizQuestion()?.answer;
                this.model.submitAnswer(isCorrect);
            });
        });

        const questionContainer = document.createElement("div");
        questionContainer.id = "quiz-question-container";
        questionContainer.appendChild(this.questionLabel);

        this.container.appendChild(questionContainer);
        this.container.appendChild(this.buttonContainer);
    }
}
