import {
  SKContainer,
  SKLabel,
  SKTextfield,
  Layout,
} from "simplekit/imperative-mode";
import { Observer } from "../observer";
import { QuizModel } from "../model";
import { EnhancedButton } from "../widgets/enhancedButton";
import { StackColLayout } from "../layouts/stackCol";
import { Spacer } from "../widgets/spacer";

export class EditView extends SKContainer implements Observer {
  update(): void {
    const question = this.model.getQuestion(this.model.getEditingQuestionId()!);
    if (question) {
      this.questionField.text = question.question;
      this.answerField.text = question.answer;
      this.other1Field.text = question.other1;
      this.other2Field.text = question.other2;
    }
  }

  questionLabel = new SKLabel({ text: "Question", align: "right", margin: 5 });
  answerLabel = new SKLabel({ text: "Answer", align: "right", margin: 5 });
  other1Label = new SKLabel({ text: "Other 1", align: "right", margin: 5 });
  other2Label = new SKLabel({ text: "Other 2", align: "right", margin: 5 });

  questionField = new SKTextfield({ fillWidth: 1, margin: 5 });
  answerField = new SKTextfield({ fillWidth: 1, margin: 5 });
  other1Field = new SKTextfield({ fillWidth: 1, margin: 5 });
  other2Field = new SKTextfield({ fillWidth: 1, margin: 5 });

  saveButton = new EnhancedButton({ text: "Save", width: 80 });
  cancelButton = new EnhancedButton({ text: "Cancel", width: 80 });

  constructor(private model: QuizModel) {
    super();

    this.padding = 30;
    this.margin = 60;
    this.fillHeight = 1;
    this.fillWidth = 1;
    this.fill = "whitesmoke";

    const formContainer = new SKContainer({
      fillWidth: 1,
      fillHeight: 1,
      layoutMethod: new Layout.FillRowLayout({ gap: 10 }),
    });

    const labelContainer = new SKContainer({
      layoutMethod: new StackColLayout(),
    });
    labelContainer.addChild(this.questionLabel);
    labelContainer.addChild(this.answerLabel);
    labelContainer.addChild(this.other1Label);
    labelContainer.addChild(this.other2Label);

    const fieldContainer = new SKContainer({
      fillWidth: 1,
      layoutMethod: new StackColLayout(),
    });
    fieldContainer.addChild(this.questionField);
    fieldContainer.addChild(this.answerField);
    fieldContainer.addChild(this.other1Field);
    fieldContainer.addChild(this.other2Field);

    formContainer.addChild(labelContainer);
    formContainer.addChild(fieldContainer);

    const buttonContainer = new SKContainer({
      fillWidth: 1,
      layoutMethod: new Layout.FillRowLayout({ gap: 10 }),
    });

    buttonContainer.addChild(new Spacer());
    buttonContainer.addChild(this.saveButton);
    buttonContainer.addChild(this.cancelButton);

    this.layoutMethod = new StackColLayout();
    this.addChild(formContainer);
    this.addChild(buttonContainer);

    this.saveButton.addEventListener("action", () => {
      this.handleSave();
    });

    this.cancelButton.addEventListener("action", () => {
      this.model.stopEditing();
    });

    this.model.addObserver(this);
  }

  private handleSave() {
    const id = this.model.getEditingQuestionId();
    if (id !== null) {
      this.model.updateQuestion(id, {
        question: this.questionField.text,
        answer: this.answerField.text,
        other1: this.other1Field.text,
        other2: this.other2Field.text,
      });
      this.model.stopEditing();
    }
  }
}
