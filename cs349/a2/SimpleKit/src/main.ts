import {
  startSimpleKit,
  setSKRoot,
  SKContainer,
  SKKeyboardEvent,
  setSKEventListener,
} from "simplekit/imperative-mode";

import { QuizModel } from "./model";
import { ModeBarView } from "./views/modeBarView";
import { QuestionListView } from "./views/questionListView";
import { StatusBarView } from "./views/statusBarView";
import { StackColLayout } from "./layouts/stackCol";
import { Observer } from "./observer";
import { EditView } from "./views/editView.ts";
import { OverlayContainer } from "./layouts/overlayContainer";
import { Layout } from "simplekit/imperative-mode";
import { QuizView } from "./views/quizView";

const model = new QuizModel();

const root = new SKContainer({
  id: "root",
  fillWidth: 1,
  fillHeight: 1,
  layoutMethod: new Layout.CentredLayout(),
});

const app = new SKContainer({
  id: "app",
  fillWidth: 1,
  fillHeight: 1,
  layoutMethod: new StackColLayout(),
});

class OverlayObserver extends SKContainer implements Observer {
  update(): void {
    const editingId = model.getEditingQuestionId();
    const quizMode = model.getMode() === "quiz";

    const existingOverlay = root.children.find(
      (child) => child instanceof OverlayContainer
    );
    if (existingOverlay) {
      root.removeChild(existingOverlay);
    }

    if (editingId !== null) {
      const overlay = new OverlayContainer();
      overlay.addChild(new EditView(model));
      root.addChild(overlay);
    }

    app.clearChildren();
    app.addChild(new ModeBarView(model));
    if (quizMode) {
      app.addChild(new QuizView(model));
    } else {
      app.addChild(new QuestionListView(model));
    }
    app.addChild(new StatusBarView(model));
  }
}

model.addObserver(new OverlayObserver());
root.addChild(app);

setSKEventListener((e) => {
  if (e.type === "keyup" && (e as SKKeyboardEvent).key === "?") {
    model.toggleCheating();
    return true;
  }
  return false;
});

setSKRoot(root);
startSimpleKit();
