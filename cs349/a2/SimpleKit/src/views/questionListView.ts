import { SKContainer } from "simplekit/imperative-mode";
import { Observer } from "../observer";
import { QuizModel } from "../model";
import { Layout } from "simplekit/imperative-mode";
import { EnhancedButton } from "../widgets/enhancedButton";
import { StackColLayout } from "../layouts/stackCol";
import { QuestionView } from "./questionView.ts";

export class QuestionListView extends SKContainer implements Observer {
  private toolbar: SKContainer;
  private questionContainer: SKContainer;
  private allButton: EnhancedButton;
  private noneButton: EnhancedButton;
  private deleteButton: EnhancedButton;
  private addButton: EnhancedButton;

  constructor(private model: QuizModel) {
    super();

    this.fillWidth = 1;
    this.fillHeight = 1;
    this.padding = 10;

    this.toolbar = new SKContainer({
      fillWidth: 1,
      padding: 10,
      border: "black",
      layoutMethod: new Layout.FillRowLayout({ gap: 10 }),
    });

    this.allButton = new EnhancedButton({ text: "All", width: 80 });
    this.noneButton = new EnhancedButton({ text: "None", width: 80 });
    this.deleteButton = new EnhancedButton({ text: "Delete", width: 80 });
    this.addButton = new EnhancedButton({ text: "Add", width: 80 });

    this.toolbar.addChild(this.allButton);
    this.toolbar.addChild(this.noneButton);
    this.toolbar.addChild(this.deleteButton);
    this.toolbar.addChild(this.addButton);

    this.questionContainer = new SKContainer({
      fillWidth: 1,
      fillHeight: 1,
      border: "black",
      padding: 10,
      layoutMethod: new Layout.WrapRowLayout(),
    });

    this.layoutMethod = new StackColLayout();
    this.addChild(this.toolbar);
    this.addChild(this.questionContainer);

    this.allButton.addEventListener("action", () =>
      this.model.selectAllQuestions()
    );
    this.noneButton.addEventListener("action", () =>
      this.model.deselectAllQuestions()
    );
    this.deleteButton.addEventListener("action", () =>
      this.model.deleteSelectedQuestions()
    );
    this.addButton.addEventListener("action", () => this.model.addQuestion());

    this.model.addObserver(this);
  }

  update() {
    const totalQuestions = this.model.getTotalQuestions();
    const selectedCount = this.model.getSelectedCount();

    this.allButton.enabled = selectedCount < totalQuestions;
    this.noneButton.enabled = selectedCount > 0;
    this.deleteButton.enabled = selectedCount > 0;
    this.addButton.enabled = totalQuestions < 10;

    this.questionContainer.clearChildren();
    this.model.getQuestions().forEach((question) => {
      this.questionContainer.addChild(
        new QuestionView(this.model, question.id)
      );
    });
  }
}
