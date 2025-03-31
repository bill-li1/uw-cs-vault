import { SKContainer, SKLabel, Layout } from "simplekit/imperative-mode";
import { Observer } from "../observer";
import { QuizModel } from "../model";
import { EnhancedButton } from "../widgets/enhancedButton";
import { StackColLayout } from "../layouts/stackCol";

export class QuizView extends SKContainer implements Observer {
  update(): void {
    const question = this.model.getCurrentQuizQuestion();
    const quizState = this.model.getQuizState();
    const isFinished = this.model.isQuizComplete();
    console.log("isFinished", isFinished);

    if (isFinished) {
      let correct = 0;
      for (let i = 0; i < (quizState?.answers?.length ?? 0); i++) {
        if (quizState?.answers?.[i] === true) {
          correct++;
        }
      }
      this.questionLabel.text = `${correct} correct, ${
        (quizState?.answers?.length ?? 0) - correct
      } incorrect`;
      this.bottomContainer.clearChildren();
    } else if (question && quizState) {
      this.questionLabel.text = question.question;

      const answers = this.model.getRandomizedAnswers();
      if (answers) {
        this.answerButtons.forEach((button, index) => {
          button.text = answers[index];
          if (quizState.isCheatingEnabled) {
            button.fill =
              answers[index] === question.answer ? "lightyellow" : "white";
          }
        });
      }
    }
  }

  questionLabel = new SKLabel();
  bottomContainer = new SKContainer({
    fillWidth: 1,
    layoutMethod: new Layout.FillRowLayout({ gap: 10 }),
  });

  answerButtons = [
    new EnhancedButton({ fillWidth: 1 }),
    new EnhancedButton({ fillWidth: 1 }),
    new EnhancedButton({ fillWidth: 1 }),
  ];

  constructor(private model: QuizModel) {
    super();

    this.fillWidth = 1;
    this.fillHeight = 1;
    this.padding = 30;
    this.layoutMethod = new Layout.CentredLayout();

    const questionPanel = new SKContainer({
      fillWidth: 1,
      fillHeight: 1,
      fill: "white",
      border: "black",
      padding: 30,
      layoutMethod: new StackColLayout(),
    });

    const questionContainer = new SKContainer({
      fillWidth: 1,
      fillHeight: 1,
      layoutMethod: new Layout.CentredLayout(),
    });
    questionContainer.addChild(this.questionLabel);
    questionPanel.addChild(questionContainer);

    const buttonContainer = new SKContainer({
      fillWidth: 1,
      layoutMethod: new Layout.FillRowLayout({ gap: 20 }),
    });

    this.answerButtons.forEach((button) => {
      buttonContainer.addChild(button);
      button.addEventListener("action", () => {
        const isCorrect =
          button.text === this.model.getCurrentQuizQuestion()?.answer;
        this.model.submitAnswer(isCorrect);
      });
    });

    this.bottomContainer.addChild(buttonContainer);
    questionPanel.addChild(this.bottomContainer);

    this.addChild(questionPanel);

    this.model.addObserver(this);
  }
}
