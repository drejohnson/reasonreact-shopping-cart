open Css;

let products =
  style([
    display(grid),
    gridTemplateColumns([
      `repeat((`autoFit, `minmax((px(320), fr(1.0))))),
    ]),
    gridGap(rem(1.0)),
  ]);