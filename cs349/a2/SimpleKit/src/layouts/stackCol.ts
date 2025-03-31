import { SKElement, LayoutMethod, Size } from "simplekit/imperative-mode";

export class StackColLayout implements LayoutMethod {
  measure(elements: SKElement[]) {
    // measure all children first
    elements.forEach((el: SKElement) => {
      if (el.measure && typeof el.measure === "function") {
        el.measure();
      }
    });

    // width is width of widest element
    const totalWidth = elements.reduce(
      (acc, el) => Math.max(acc, el.intrinsicWidth),
      0
    );

    // height is sum of non-filling elements plus minimum for filling elements
    const totalHeight = elements.reduce(
      (acc, el) =>
        acc + (el.fillHeight ? el.intrinsicHeight : el.intrinsicHeight),
      0
    );

    return {
      width: totalWidth,
      height: totalHeight,
    };
  }

  layout(width: number, height: number, elements: SKElement[]) {
    const newBounds: Size = { width: 0, height: 0 };
    let y = 0;

    // Calculate total height of non-filling elements
    const fixedHeight = elements
      .filter((el) => !el.fillHeight)
      .reduce((acc, el) => acc + el.intrinsicHeight, 0);

    // Calculate remaining height for filling elements
    const remainingHeight = height - fixedHeight;

    // Count elements with fillHeight
    const fillElements = elements.filter((el) => el.fillHeight).length;

    // Height per filling element
    const heightPerFill = fillElements > 0 ? remainingHeight / fillElements : 0;

    elements.forEach((el: SKElement) => {
      // set the element position
      el.x = 0;
      el.y = y;

      // If element fills height, give it equal portion of remaining space
      const h = el.fillHeight ? heightPerFill : el.intrinsicHeight;
      const w = el.fillWidth ? width : el.intrinsicWidth;

      el.layout(w, h);

      // next row
      y += h;

      // update bounds that were actually used
      newBounds.width = Math.max(newBounds.width, el.layoutWidth);
      newBounds.height = Math.max(newBounds.height, y);
    });

    return newBounds;
  }
}
