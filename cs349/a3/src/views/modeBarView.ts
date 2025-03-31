import View from "../view";
import { QuizModel } from "../model";

import "./modeBarView.css";

export class ModeBarView implements View {
    quizButton = document.createElement("button");
    progressLabel = document.createElement("span");

    constructor(private model: QuizModel) {
        this.container = document.createElement("div");
        this.quizButton.innerText = "Quiz";
        this.container.id = "container";
        this.quizButton.id = "quizButton";
        this.progressLabel.id = "progressLabel";

        this.container.appendChild(this.progressLabel);
        this.container.appendChild(this.quizButton);

        this.quizButton.addEventListener("click", () => {
            if (this.model.getMode() === "list") {
                this.model.startQuiz();
            } else {
                this.model.exitQuiz();
            }
        });

        this.model.addObserver(this);
    }
    private container: HTMLElement;
    get root(): HTMLElement {
        return this.container;
    }

    update(): void {
        const mode = this.model.getMode();
        const quizState = this.model.getQuizState();

        this.quizButton.innerText = mode === "list" ? "Quiz" : "Exit";
        this.quizButton.disabled = !(
            mode === "quiz" || this.model.getSelectedCount() > 0
        );

        // this.fill = mode === "list" ? "lightgrey" : "lightblue";
        if (mode === "list") {
            this.container.style.backgroundColor = "lightgrey";
        } else {
            this.container.style.backgroundColor = "lightblue";
        }

        if (mode === "quiz" && quizState) {
            const total = this.model.getSelectedQuestions().length;
            const current = quizState.currentQuestionIndex + 1;

            if (this.model.isQuizComplete()) {
                this.progressLabel.innerText = "Quiz Completed";
            } else {
                this.progressLabel.innerText = `Question ${current} of ${total}`;
            }
        } else {
            this.progressLabel.innerText = "";
        }
    }
}
