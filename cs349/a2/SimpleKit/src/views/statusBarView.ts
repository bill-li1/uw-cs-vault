import { SKContainer, SKLabel, Layout } from "simplekit/imperative-mode";
import { Observer } from "../observer";
import { QuizModel } from "../model";

export class StatusBarView extends SKContainer implements Observer {
  private messageLabel: SKLabel;
  private cheatingLabel: SKLabel;

  constructor(private model: QuizModel) {
    super();

    this.padding = 10;
    this.fillWidth = 1;
    this.fill = "lightgrey";

    this.layoutMethod = new Layout.FillRowLayout();
    this.cheatingLabel = new SKLabel({
      text: "",
      align: "right",
    });

    this.messageLabel = new SKLabel({
      text: "",
      align: "left",
      fillWidth: 1,
    });
    this.addChild(this.messageLabel);

    this.model.addObserver(this);
  }

  update() {
    const totalQuestions = this.model.getTotalQuestions();
    const selectedCount = this.model.getSelectedCount();
    const isCheating = this.model.getQuizState()?.isCheatingEnabled;
    const isEditing = this.model.getEditingQuestionId();
    console.log({ isEditing });

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

    this.messageLabel.text = message;

    if (isCheating) {
      this.cheatingLabel.text = "CHEATING";
    }
    this.addChild(this.cheatingLabel);
  }
}
