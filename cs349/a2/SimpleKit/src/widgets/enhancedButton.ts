import { SKButton, SKMouseEvent } from "simplekit/imperative-mode";

export class EnhancedButton extends SKButton {
  private _enabled: boolean = true;

  constructor(props: any) {
    super(props);
  }

  get enabled(): boolean {
    return this._enabled;
  }

  set enabled(value: boolean) {
    this._enabled = value;
    if (!value) {
      this.state = "idle"; // Reset state to idle when disabled
    }
  }

  handleMouseEvent(me: SKMouseEvent): boolean {
    if (!this._enabled) {
      return false;
    }
    return super.handleMouseEvent(me);
  }

  draw(gc: CanvasRenderingContext2D) {
    gc.save();
    if (!this._enabled) {
      gc.globalAlpha = 0.5;
      this.state = "idle";
    }
    super.draw(gc);
    gc.restore();
  }
}
