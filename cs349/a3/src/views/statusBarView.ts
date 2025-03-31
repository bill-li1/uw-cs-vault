import { QuizModel } from "../model";
import View from "../view";
import "./statusBarView.css";

export class StatusBarView implements View {
    cheatingLabel = document.createElement("span");
    messageLabel = document.createElement("span");
    update(): void {
        const totalQuestions = this.model.getTotalQuestions();
        const selectedCount = this.model.getSelectedCount();
        const isCheating = this.model.getQuizState()?.isCheatingEnabled;

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

        this.messageLabel.innerText = message;

        console.log({ isCheating });

        if (isCheating) {
            this.cheatingLabel.innerText = "CHEATING";
        }
    }

    private container: HTMLElement;
    get root(): HTMLElement {
        return this.container;
    }

    constructor(private model: QuizModel) {
        this.container = document.createElement("div");
        this.container.id = "status-bar-container";
        this.container.appendChild(this.messageLabel);
        this.container.appendChild(this.cheatingLabel);
        this.model.addObserver(this);
    }
}
