import View from "../view";
import { QuizModel } from "../model";
import { QuestionView } from "./questionView";
import "./questionListView.css";

export class QuestionListView implements View {
    update() {
        const totalQuestions = this.model.getTotalQuestions();
        const selectedCount = this.model.getSelectedCount();

        this.allButton.disabled = selectedCount >= totalQuestions;
        this.noneButton.disabled = selectedCount <= 0;
        this.deleteButton.disabled = selectedCount <= 0;
        this.addButton.disabled = totalQuestions >= 10;

        this.questionContainer.replaceChildren();
        this.model.getQuestions().forEach((question) => {
            this.questionContainer.appendChild(
                new QuestionView(this.model, question.id).root
            );
        });
    }

    toolbar = document.createElement("div");
    questionContainer = document.createElement("div");
    allButton = document.createElement("button");
    noneButton = document.createElement("button");
    deleteButton = document.createElement("button");
    addButton = document.createElement("button");

    private container: HTMLElement;
    get root(): HTMLElement {
        return this.container;
    }

    constructor(private model: QuizModel) {
        this.container = document.createElement("div");
        this.container.id = "root-container";
        this.questionContainer.id = "question-list-container";
        this.model.addObserver(this);
        this.toolbar = document.createElement("div");
        this.toolbar.id = "toolbar";
        this.allButton.innerText = "All";
        this.noneButton.innerText = "None";
        this.deleteButton.innerText = "Delete";
        this.addButton.innerText = "Add";

        this.container.appendChild(this.toolbar);
        this.container.appendChild(this.questionContainer);

        this.toolbar.appendChild(this.allButton);
        this.toolbar.appendChild(this.noneButton);
        this.toolbar.appendChild(this.deleteButton);
        this.toolbar.appendChild(this.addButton);

        this.allButton.addEventListener("click", () =>
            this.model.selectAllQuestions()
        );
        this.noneButton.addEventListener("click", () =>
            this.model.deselectAllQuestions()
        );
        this.deleteButton.addEventListener("click", () =>
            this.model.deleteSelectedQuestions()
        );
        this.addButton.addEventListener("click", () =>
            this.model.addQuestion()
        );

        this.model.addObserver(this);
    }
}
