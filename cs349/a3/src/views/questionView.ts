import View from "../view";
import "./questionView.css";

export class QuestionView implements View {
    checkbox = document.createElement("input");
    questionText = document.createElement("span");

    constructor(private model: any, private questionId: number) {
        this.container = document.createElement("div");
        this.container.id = "question-container";
        this.questionText.id = "question-text";
        this.checkbox.type = "checkbox";
        this.checkbox.id = "question-checkbox";
        this.questionText.innerText = "?";

        this.container.appendChild(this.checkbox);
        this.container.appendChild(this.questionText);

        this.checkbox.addEventListener("click", () => {
            this.model.toggleQuestionSelection(this.questionId);
        });

        this.model.addObserver(this);
    }
    private container: HTMLElement;
    get root(): HTMLElement {
        return this.container;
    }

    update() {
        const question = this.model.getQuestion(this.questionId);
        if (!question) return;
        this.checkbox.checked = question.selected || false;
        this.questionText.innerText = question.question;
    }
}
