import { QuizModel } from "./model";
import { ModeBarView } from "./views/modeBarView";
import { QuestionListView } from "./views/questionListView";
import { StatusBarView } from "./views/statusBarView";
import { QuizView } from "./views/quizView";
import View from "./view";

import "./main.css";

const model = new QuizModel();

const root = document.querySelector("div#app") as HTMLElement;
const app = document.createElement("div");
app.id = "base";

class OverlayObserver implements View {
    update(): void {
        const quizMode = model.getMode() === "quiz";
        app.replaceChildren();
        app.appendChild(new ModeBarView(model).root);
        if (quizMode) {
            app.appendChild(new QuizView(model).root);
        } else {
            app.appendChild(new QuestionListView(model).root);
        }
        app.appendChild(new StatusBarView(model).root);
    }
    get root(): HTMLElement {
        return app;
    }
}

// toggle cheating when '?' is pressed
document.addEventListener("keyup", (e) => {
    if (e.key === "?") {
        model.toggleCheating();
        return true;
    }
    return false;
});

model.addObserver(new OverlayObserver());
root.appendChild(app);
