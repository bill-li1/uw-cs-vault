import { SKContainer, Layout, SKLabel } from "simplekit/imperative-mode";
import { Observer } from "../observer";
import { QuizModel } from "../model";
import { EnhancedButton } from "../widgets/enhancedButton";

export class ModeBarView extends SKContainer implements Observer {
  private quizButton: EnhancedButton;
  private progressLabel = new SKLabel({
    text: "",
    align: "left",
    fillWidth: 1,
  });

  constructor(private model: QuizModel) {
    super();

    this.fillWidth = 1;
    this.fill = "lightgrey";
    this.padding = 10;

    this.quizButton = new EnhancedButton({
      text: "Quiz",
      width: 100,
    });

    this.layoutMethod = new Layout.FillRowLayout();

    this.addChild(this.progressLabel);
    this.addChild(this.quizButton);

    this.quizButton.addEventListener("action", () => {
      if (this.model.getMode() === "list") {
        this.model.startQuiz();
      } else {
        this.model.exitQuiz();
      }
    });

    this.model.addObserver(this);
  }

  update(): void {
    const mode = this.model.getMode();
    const quizState = this.model.getQuizState();

    this.quizButton.text = mode === "list" ? "Quiz" : "Exit";
    this.quizButton.enabled =
      mode === "quiz" || this.model.getSelectedCount() > 0;

    this.fill = mode === "list" ? "lightgrey" : "lightblue";

    if (mode === "quiz" && quizState) {
      const total = this.model.getSelectedQuestions().length;
      const current = quizState.currentQuestionIndex + 1;

      if (this.model.isQuizComplete()) {
        this.progressLabel.text = "Quiz Completed";
      } else {
        this.progressLabel.text = `Question ${current} of ${total}`;
      }
    } else {
      this.progressLabel.text = "";
    }
  }
}
