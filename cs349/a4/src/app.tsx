import TopBar from "./components/TopBar";
import QuestionList from "./components/QuestionList";
import BottomBar from "./components/BottomBar";
import Quiz from "./components/Quiz";
import { getMode, toggleCheating } from "./state";
import { useEffect } from "preact/hooks";

export function App() {
  const mode = getMode();

  // event listener for toggle cheating
  useEffect(() => {
    const handleKeyPress = (event: KeyboardEvent) => {
      if (event.key === "?") {
        toggleCheating();
      }
    };

    window.addEventListener("keydown", handleKeyPress);

    return () => {
      window.removeEventListener("keydown", handleKeyPress);
    };
  }, []);

  return (
    <>
      <div className="flex flex-col h-screen">
        <TopBar />
        {mode === "quiz" ? <Quiz /> : <QuestionList />}
        <BottomBar />
      </div>
    </>
  );
}
