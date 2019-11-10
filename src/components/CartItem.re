module Styles = {
  open Css;

  let wrapper =
    style([
      display(grid),
      gridTemplateColumns([pct(25.), fr(1.)]),
      gridGap(rem(1.)),
      alignItems(center),
      justifyContent(center),
      height(pct(100.)),
    ]);

  let imgWrapper =
    style([display(flexBox), width(pct(100.)), height(pct(100.))]);

  let img = style([objectFit(contain)]);

  let bookInfo = style([maxWidth(px(600)), padding(rem(1.))]);
};

[@react.component]
let make = (~book: BookData.book, ~removeItem) => {
  <div className=Styles.wrapper>
    <div className=Styles.imgWrapper>
      <img className=Styles.img src={book.book_image} alt={book.title} />
    </div>
    <div className=Styles.bookInfo>
      <h1> book.title->React.string </h1>
      <p> {React.string("$" ++ Js.Float.toString(book.price))} </p>
    </div>
    <button onClick={_ => removeItem(book.rank)}>
      "Remove from cart"->React.string
    </button>
  </div>;
};