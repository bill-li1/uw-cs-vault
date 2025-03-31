import { SKContainer, SKLabel, Layout } from "simplekit/imperative-mode";
import { Observer } from "../observer";
import { SKCheckbox } from "../widgets/checkbox";
import { QuizModel } from "../model";

export class QuestionView extends SKContainer implements Observer {
  update() {
    const question = this.model.getQuestion(this.questionId);
    if (!question) return;
    this.checkbox.checked = question.selected || false;
    this.questionText.text = question.question;
  }
  checkbox = new SKCheckbox({ margin: 3 });
  questionText = new SKLabel({
    text: "?",
    fillWidth: 1,
    align: "left",
  });

  constructor(private model: QuizModel, private questionId: number) {
    super();

    this.id = `question #${questionId}`;
    this.padding = 5;
    this.margin = 5;
    this.fillWidth = 1;
    this.fill = "lightblue";

    this.layoutMethod = new Layout.FillRowLayout({ gap: 5 });
    this.questionText.font = "10pt sans-serif";

    this.addChild(this.checkbox);
    this.addChild(this.questionText);

    this.checkbox.addEventListener("action", () => {
      model.toggleQuestionSelection(questionId);
    });

    this.addEventListener("dblclick", () => {
      this.model.startEditing(this.questionId);
      return true; // Consume the event
    });

    this.model.addObserver(this);
  }
}
