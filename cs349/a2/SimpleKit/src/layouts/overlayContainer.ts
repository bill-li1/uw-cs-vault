import { Layout, SKContainer, SKEvent } from "simplekit/imperative-mode";

export class OverlayContainer extends SKContainer {
  constructor() {
    super();
    this.fillWidth = 1;
    this.fillHeight = 1;
    this.layoutMethod = new Layout.CentredLayout();
    this.fill = "rgba(0, 0, 0, 0.5)"; // Semi-transparent dark gray
  }

  handleMouseEvent(_me: SKEvent): boolean {
    return true;
  }
}
