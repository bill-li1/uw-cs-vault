// widgets/spacer.ts
import { SKElement, SKElementProps } from "simplekit/imperative-mode";

export class Spacer extends SKElement {
  constructor(props: SKElementProps = {}) {
    super({ fillWidth: 1, ...props });
  }
}
